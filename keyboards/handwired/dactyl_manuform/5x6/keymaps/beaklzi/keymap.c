// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
//
// To flash corne / chimera / planck firmware
// ═════════════════════════
//   Reset keyboard or press hw reset button on base
//
//   cd qmk_firmware/keyboards/<keyboard>
//   sudo make KEYMAP=<keymap> dfu
//
//   sudo make clean           (good practice before flashing)
//   sudo make KEYMAP=<keymap> (to compile check)
//
// Package requirements (for arch linux)
// ═════════════════════════════════════
//   avr-gcc-atmel
//   avr-libc-atmel
//   dfu-programmer
//
// Notes
// ═════
//   ** E R G O   W I D E   S P L I T ** Layout
//
//   Autocompletion tap dance key pairs (),[],{} are available from the
//   number/symbol layer, as well as, numerous (un)shift key values
//
//   #define PRIVATE_STRING includes private_string.h, a user defined code
//   block for the PRIV tap dance e.g. SEND_STRING("secret messape"),
//   see function private()
//
// Code
// ════
//   This source is shamelessly based on the "default" planck layout
//
//   #ifdef/#endif block structures are not indented, as syntax highlighting
//   in vim is sufficient for identification
//
//   c++ commenting style is used throughout
//
// Change history
// ══════════════
//   See http://thedarnedestthing.com/colophon
//
//                === N O T E ===
//
// sudo CPATH=<keymap.c directory>/common make ...

// Hardware
// ═════════════════════════════════════════════════════════════════════════════

#include "5x6.h"

#undef LAYOUT_5x6
#define LAYOUT_5x6(L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, L42, L43, R42, R43, L44, L45, R40, R41, L54, L55, R50, R51, L52, L53, R52, R53) \
    {                                                                                                                                                                                                                                                                                                                                              \
        {L00, L01, L02, L03, L04, L05}, {L10, L11, L12, L13, L14, L15}, {L20, GUI_T(L21), CTL_T(L22), ALT_T(L23), L24, L25}, {L30, L31, L32, L33, L34, L35}, {KC_NO, KC_NO, L42, L43, L44, L45}, {KC_NO, KC_NO, L52, L53, L54, L55},                                                                                                               \
                                                                                                                                                                                                                                                                                                                                                   \
            {R00, R01, R02, R03, R04, R05}, {R10, R11, R12, R13, R14, R15}, {R20, GUI_T(R21), CTL_T(R22), ALT_T(R23), R24, R25}, {R30, R31, R32, R33, R34, R35}, {R40, R41, R42, R43, KC_NO, KC_NO}, {                                                                                                                                             \
            R50, R51, R52, R53, KC_NO, KC_NO                                                                                                                                                                                                                                                                                                       \
        }                                                                                                                                                                                                                                                                                                                                          \
    }
#define KEYMAP(...) LAYOUT_5x6(__VA_ARGS__)

// Keymaps
// ═════════════════════════════════════════════════════════════════════════════

extern keymap_config_t keymap_config;

enum keyboard_layers {
    _BASE = 0,
    _DVORAK,
    _QWERTY,
    _TTCAPS,
    _SYMBOL,
    _MOUSE,
    _NUMBER,
    _FNCKEY,
    _EDIT,
    _TTFNCKEY,
    _TTCURSOR,
    _TTMOUSE,
    _TTNUMBER,
    _TTSYMBOL
#ifdef TEST
    ,
    _TEST
#endif
    ,
    _END_LAYERS
};

enum keyboard_keycodes {
    BASE = SAFE_RANGE,
    AST_G  // pseudo MT   (MOD_LALT | MOD_LSFT, S(KC_G))
    ,
    ST_T  // pseudo SFT_T(S(KC_T))
    ,
    TT_ESC,
    TT_I  // pseudo LT(_REGEX, S(KC_I))
    ,
    TT_SPC  // pseudo LT(_SYMGUI, KC_SPC)
};

#define ACT_E MT(MOD_LALT | MOD_LCTL, KC_E)
#define AT_B ALT_T(KC_B)
#define CT_C CTL_T(KC_C)
#define ST_A SFT_T(KC_A)

#include "common/tapdance.h"

// keycodes
#define ___x___ KC_TRNS
#define ___fn__ KC_TRNS
#ifdef _______
#    undef _______
#endif
#define _______ KC_NO

#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE TD_PASTE
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define XCOPY LCTL(LSFT(KC_C))
#define XPASTE TD_XPASTE

#define HOME_A SFT_T(KC_A)
#define HOME_S SFT_T(KC_S)
#define HOME_U SFT_T(KC_U)
#define HOME_H SFT_T(KC_H)

#define LT_BSPC LT(_MOUSE, KC_BSPC)
#define LT_ESC LT(_EDIT, KC_ESC)
#define LT_ENT LT(_FNCKEY, KC_ENT)
#define LT_I LT(_SYMBOL, KC_I)
#define LT_SPC LT(_SYMBOL, KC_SPC)
#define LT_TAB LT(_NUMBER, KC_TAB)
#define TT_TAB LT(_NUMBER, KC_TAB)

#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_GUI OSM(MOD_LGUI)
#define OS_SFT OSM(MOD_LSFT)

#define TGL_TL TT(_TTFNCKEY)
#define TGL_HL TT(_TTCAPS)
#define TGL_BL TT(_TTMOUSE)
#define TGL_TR TT(_TTSYMBOL)
#define TGL_HR TT(_TTNUMBER)
#define TGL_BR TT(_TTCURSOR)

#ifdef TEST
#    define DEBUG TG(_TEST)
#else
#    define DEBUG KC_NO
#endif

// Layers
// ═════════════════════════════════════════════════════════════════════════════

// ........................................................ Default Alpha Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#include "base_layout.h"

// ...................................................... Number / Function Keys

#include "common/number_fkey_layout.h"

// ......................................................... Symbol / Navigation

#include "common/symbol_layout.h"

// ............................................................... Toggle Layers

#include "common/toggle_layout.h"

// .............................................................. Mouse / Chords

#include "common/mouse_chord_layout.h"

};

// User Keycode Trap
// ═════════════════════════════════════════════════════════════════════════════

#include "common/keycode_functions.c"
#include "common/tapdance.c"

static uint16_t td_timer = 0;  // pseudo tapdance timer
#define UNUSED(x) (void)(x)
#define TAPDANCE                                                              \
    if (KEY_DOWN) {                                                           \
        td_timer = timer_elapsed(td_timer) < TAPPING_TERM ? 0 : timer_read(); \
    }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    UNUSED(td_timer);

    if (reshifted && !mod_down(KC_LSFT)) {
        unregister_code(KC_LSFT);
        reshifted = 0;
    }

    // ........................................................ Home Row Modifiers

    switch (keycode) {
        case HOME_A:
        case HOME_U:
            mod_bits(record, KC_LSFT);
            break;
        case HOME_S:
        case HOME_H:
            mod_bits(record, KC_RSFT);
            break;

            // ............................................................. Toggle Layers

        case TGL_TL:
        case TGL_TR:
        case TGL_HL:
        case TGL_HR:
        case TGL_BL:
        case TGL_BR:
            tt_escape(record, keycode);
            break;

            // ........................................................... Left Thumb Keys

        case TT_ESC:
            base_layer(0);
            return false;  // exit TT layer
        case LT_ESC:
            if (tt_keycode) {
                base_layer(0);
                return false;
            }
            break;

        case LT_I:
            break;
        case TT_I:
            lt(record, _SYMBOL, SHIFT, KC_I);
            break;
        case S(KC_I):
            if (!KEY_DOWN) {
                CLR_1SHOT;
            }  // see leader_cap()
            break;

            // .......................................................... Right Thumb Keys

        case TT_SPC:
            lt(record, _SYMBOL, NOSHIFT, KC_SPC);
            break;
        case KC_SPC:
            if (!KEY_DOWN) {
                CLR_1SHOT;
            }  // see leader_cap()
            break;

        case LT_BSPC:
        case KC_BSPC:
            if (!KEY_DOWN) {
                CLR_1SHOT;
            }  // see leader_cap()
            break;

            // ................................................................ Other Keys

        default:
            if (!KEY_DOWN) {
                CLR_1SHOT;
            }               // see leader_cap()
            key_timer = 0;  // regular keycode, clear timer in keycode_functions.h
    }
    return true;
}

// Initialization
// ═════════════════════════════════════════════════════════════════════════════

void matrix_init_user(void) { base_layer(0); }
