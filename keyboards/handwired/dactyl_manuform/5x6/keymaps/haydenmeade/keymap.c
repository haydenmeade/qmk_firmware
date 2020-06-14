/* My layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "layers/layers_definitions.c"
#include "hayden.h"
#include "tap_dance/tap_dance_setup.c"
#include "tap_dance/tap_dances.c"
#include "tap_dance/mod_tap_layer_dances/dot_comm.c"
#include "tap_dance/mod_tap_layer_dances/quot_dquot.c"
#include "tap_dance/mod_tap_layer_dances/scln_coln.c"
#include "tap_dance/tap_dance_actions.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DVORAK] = LAYOUT_5x6_wrapper(
     KC_CAPS  , __________________PROG_TD_L________________,       __________________PROG_TD_R________________, KC_DEL ,
     KC_TAB   , _________________DVORAK_L1_________________,       _________________DVORAK_R1_________________, KC_SLSH,
     KC_LSPO  , _________________DVORAK_L2_________________,       _________________DVORAK_R2_________________, KC_MINS,
     KC_LGUI  , _________________DVORAK_L3_________________,       _________________DVORAK_R3_________________, KC_GRV ,
                            KC_HOME,KC_RGHT,                                 KC_UP, KC_A,
                                             LT_ESC , LT_SPC,      KC_TAB    , KC_ENT,
                                             CTL_ESC, MO(NUMPAD),  KC_EQL, MO(NUMPAD),
                                             KC_LALT, MO(NAV),     LT(GAMING, KC_DEL)  , KC_RSFT
  ),
  [NUMPAD] = LAYOUT_5x6_wrapper(
       KC_F12 , ______________________F_L__________________,                      ______________________F_R__________________, KC_F11,
       KC_GRV , _________________SYMBOL_L1_________________,                      _________________SYMBOL_R1_________________, KC_NLCK,
       _______, _________________SYMBOL_L2_________________,                      _________________SYMBOL_R2_________________, _______,
       RESET  , _________________SYMBOL_L3_________________,                      _________________SYMBOL_R3_________________, _______,
                       _______, _______,                                                          KC_P0 , KC_PDOT,
                                               _______, _______,            _______, _______,
                                               _______, _______,            _______, _______,
                                               _______, _______,            _______, _______
  ),
  [SYMBOL] = LAYOUT_5x6_wrapper(
       KC_F12 , ______________________F_L__________________,                      ______________________F_R__________________, KC_F11,
       KC_GRV , _________________SYMBOL_L1_________________,                      _________________SYMBOL_R1_________________, KC_NLCK,
       _______, _________________SYMBOL_L2_________________,                      _________________SYMBOL_R2_________________, _______,
       RESET  , _________________SYMBOL_L3_________________,                      _________________SYMBOL_R3_________________, _______,
                       _______, _______,                                                          KC_P0 , KC_PDOT,
                                               _______, _______,            _______, _______,
                                               _______, _______,            _______, _______,
                                               _______, _______,            _______, _______
  ),
  [NAV] = LAYOUT_5x6_wrapper(
       KC_F12 , ______________________F_L__________________,                      ______________________F_R__________________, KC_F11,
       _______, KC_ENT , S(KC_TAB), KC_LSFT, KC_LALT, KC_BSPC,                    S(KC_TAB), KC_PGUP, KC_UP  , KC_PGDN, KC_BSPC, KC_NLCK,
       _______, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, KC_BSPC,                      KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, _______,
       _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_A),                      KC_TAB, KC_HOME, KC_DEL, KC_END, C(KC_Y), _______,
                       _______, _______,                                                          KC_P0 , KC_PDOT,
                                               _______, _______,            _______, _______,
                                               _______, _______,            _______, _______,
                                               _______, _______,            _______, _______
  ),
  [GAMING] = LAYOUT_5x6_wrapper(
     _______  , ________________NUMBERS_L__________________,                          ________________NUMBERS_R__________________, KC_BSPC,
     KC_TAB   , _________________QWERTY_L1_________________,                          _________________QWERTY_R1_________________, _______,
     _______  , _________________QWERTY_L2_________________,                          _________________QWERTY_R2_________________, _______,
     MOD_LSFT , _________________QWERTY_L3_________________,                          _________________QWERTY_R3_________________, _______,
                            KC_LEFT,KC_RGHT,                                                       KC_UP, KC_DOWN,
                                             KC_ENT  , KC_SPC    ,                    KC_TAB    , KC_ENT,
                                             KC_LCTL , MO(NUMPAD),                    MO(NUMPAD), KC_EQL,
                                             MOD_LALT, TG(DVORAK),                    _______   , KC_BSPC
  ),
};
// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
  xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.row, record->event.key.col, record->event.pressed);
#endif //CONSOLE_ENABLE
