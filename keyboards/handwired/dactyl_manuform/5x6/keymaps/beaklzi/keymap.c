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

#define KEYMAP LAYOUT_5x6

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
    ,
    CM_EXL  // comma / exclamation
    ,
    DT_ADD  // dot / at
    ,
    QUOT_DSH  // ' /
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

#define VSVIM LALT(LCTL(LSFT(KC_F12)))
#define REMOTE LCTL(LALT(KC_HOME))
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
#define LT_I LT(_NUMBER, KC_I)
#define LT_SPC LT(_SYMBOL, KC_SPC)
#define LT_TAB SFT_T(KC_TAB)
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
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case CM_EXL:  // comma / exclamation
            if (KEY_DOWN) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_modifier(KC_LSFT);
                    unregister_modifier(KC_RSFT);
                    tap_code16(KC_EXLM);
                    register_modifier(KC_LSFT);
                }
                else
                {
                     tap_code16(KC_COMMA);
                }
            }
            break;
        case DT_ADD:  // dot / at
            if (KEY_DOWN) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_modifier(KC_LSFT);
                    unregister_modifier(KC_RSFT);
                    tap_code16(KC_AT);
                    register_modifier(KC_LSFT);
                } else {
                    tap_code16(KC_DOT);
                }
            }
            break;
        case QUOT_DSH:  // quote /KC_GRAVE
            if (KEY_DOWN) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_modifier(KC_LSFT);
                    unregister_modifier(KC_RSFT);
                    tap_code16(KC_GRAVE);
                    register_modifier(KC_LSFT);
                } else {
                    tap_code16(KC_QUOTE);
                }
            }
            break;

        default:
            break;
    }
    return true;
}

// Initialization
// ═════════════════════════════════════════════════════════════════════════════

void matrix_init_user(void) { base_layer(0); }
