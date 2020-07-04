#define STENO    !defined(CHIMERA) && !defined(CORNE)
#define NONSTENO defined(CHIMERA) || defined(CORNE)

#include "config.h"  // for ale linter
#include "keycode_functions.h"

// ................................................................ Global Scope

static uint16_t tt_keycode = 0;  // current TT keycode

#define CLR_1SHOT clear_oneshot_layer_state(ONESHOT_PRESSED)
#define KEY_DOWN  record->event.pressed

// ................................................................. Local Scope

static uint8_t  i          = 0;  // inline for loop counter
static uint16_t key_timer  = 0;  // global event timer

#define KEY_TIMER key_timer = timer_read()
#define KEY_TAP   timer_elapsed(key_timer) < TAPPING_TERM

// Keycodes
// ═════════════════════════════════════════════════════════════════════════════

// ................................................................... Mod Masks

// tap dance persistant mods, see process_record_user()
// keyboard_report->mods (?) appears to be cleared by tap dance
static uint8_t mods = 0;

void register_modifier(uint16_t keycode)
{
  register_code(keycode);
  mods |= MOD_BIT(keycode);
}

void unregister_modifier(uint16_t keycode)
{
  unregister_code(keycode);
  mods &= ~(MOD_BIT(keycode));
}

#define MOD_KEY(x) mods & MOD_BIT(x)

// (un)register modifiers
void mod_all(void (*f)(uint8_t), uint8_t mask)
{
  if (!mods)            { return; }
  if (MOD_KEY(KC_LGUI)) { f(KC_LGUI); }
  if (MOD_KEY(KC_LCTL)) { f(KC_LCTL); }
  if (MOD_KEY(KC_LALT)) { f(KC_LALT); }
  if (MOD_KEY(KC_LSFT)) { f(KC_LSFT); }
  if (MOD_KEY(KC_RSFT)) { f(KC_RSFT); }  // note: qmk macros all use left modifiers
  if (MOD_KEY(KC_RALT)) { f(KC_RALT); }
  if (MOD_KEY(KC_RCTL)) { f(KC_RCTL); }
  if (MOD_KEY(KC_RGUI)) { f(KC_RGUI); }
  mods &= (mask ? 0xFF : 0);             // 0 -> discard, otherwise -> retain state
}

// two or more active modifier keys (down) only, see mod_roll()
bool chained_modifier()
{
  uint8_t bits = 0;
  uint8_t i    = mods;
  while(i) { bits += i % 2; i >>= 1; }
  return bits > 1;
}

void mod_bits(RECORD, uint16_t keycode)
{
  if (KEY_DOWN) { mods |=   MOD_BIT(keycode); }
  else          { mods &= ~(MOD_BIT(keycode)); }
}

// base layer modifier
bool mod_down(uint16_t key_code)
{
#ifdef SPLITOGRAPHY
  return mods & MOD_BIT(key_code);   // regardless of other home row modifiers
#else
  return mods == MOD_BIT(key_code);  // on home row modifier only
#endif
}

// .................................................................. Key event

// alternate escape for TT layers, see process_record_user()
void tt_escape(RECORD, uint16_t keycode)
{
  if (tt_keycode && tt_keycode != keycode) { base_layer(0); }  // if different TT layer selected
  if (KEY_DOWN)                            { KEY_TIMER; }
  else                                     { if (KEY_TAP) { tt_keycode = keycode; } key_timer = 0; }
}

// tapped or not?
bool key_press(RECORD)
{
  if (KEY_DOWN)     { KEY_TIMER; }
  else if (KEY_TAP) { key_timer = 0; return true; }
  else              { key_timer = 0; }
  return false;
}

// .......................................................... Keycode Primitives

void register_shift(uint16_t keycode)
{
  register_code(KC_LSFT);
  register_code(keycode);
}

void unregister_shift(uint16_t keycode)
{
  unregister_code(keycode);
  unregister_code(KC_LSFT);
}

void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

void tap_shift(uint16_t keycode)
{
  register_code  (KC_LSFT);
  tap_key        (keycode);
  unregister_code(KC_LSFT);
}

#define SHIFTED_OR(k) shift ? tap_shift(k) : tap_key(k)

void double_tap(uint8_t count, uint8_t shift, uint16_t keycode)
{
  SHIFTED_OR(keycode);
  if (count > 1) { SHIFTED_OR(keycode); }
}

// ............................................................ Keycode Modifier

#define SHIFT   1
#define NOSHIFT 0

void mod_key(uint16_t modifier, uint16_t keycode)
{
  switch (modifier) {
  case NOSHIFT:
    tap_key(keycode);   break;
  case SHIFT:
    tap_shift(keycode); break;
  default:
    register_modifier  (modifier);
    tap_key            (keycode);
    unregister_modifier(modifier);
  }
}

#define SET_EVENT(c) e[c].key_timer = timer_read(); \
                     e[c].keycode   = keycode;      \
                     e[c].shift     = shift;        \
                     e[c].side      = side;         \
                     e[c].leadercap = leadercap;    \
                     prev_key       = next_key;     \
                     next_key       = c

// column 0 1 2 3 4 <- left, right -> 5 6 7 8 9
static struct column_event {
  uint16_t key_timer;            // event priority
  uint16_t keycode;
  uint8_t  shift;
  uint8_t  side;
  uint8_t  leadercap;
} e[12];                         // leader -> 10 11, see process_record_user(), mod_roll()

void clear_events(void)
{
  for (i = 0; i < 12; i++) { e[i].key_timer = 0; e[i].leadercap = 0; }
}

// Layers
// ═════════════════════════════════════════════════════════════════════════════

// ............................................................ Layer Primitives

// void persistant_default_layer_set(uint16_t default_layer)
// {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set            (default_layer);
// }

void clear_layers(void)
{
  for (i = 0; i < _END_LAYERS; i++) { layer_off(i); }
  mods       = 0;
  key_timer  = 0;
  tt_keycode = 0;
  clear_events();
}

void base_layer(uint8_t defer)
{
  if (defer) { return; }  // see process_record_user() reset keys
  clear_layers();
  set_single_persistent_default_layer(_BASE);
}

// LT macro for mapc_shift(), see process_record_user()
void lt(RECORD, uint8_t layer, uint8_t shift, uint16_t keycode)
{
  if (KEY_DOWN) { KEY_TIMER; layer_on(layer); }
  else {
    layer_off(layer);
    if (KEY_TAP) { mod_key(shift, keycode); }
    // clear_mods();
    key_timer = 0;
  }
}

