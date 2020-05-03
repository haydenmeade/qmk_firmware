/* My layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "layers/layers_definitions.c"
#include "hayden.h"
#include "tap_dance/tap_dance_setup.c"
#include "tap_dance/tap_dances.c"
#include "tap_dance/mod_tap_layer_dances/dot_comm.c"
#include "tap_dance/mod_tap_layer_dances/quot_dquot.c"
#include "tap_dance/mod_tap_layer_dances/scln_coln.c"
#include "tap_dance/mod_tap_layer_dances/h_mouse_gui.c"
#include "tap_dance/tap_dance_actions.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DVORAK] = LAYOUT_5x6_wrapper(
     KC_LGUI , __________________PROG_L___________________,                          __________________PROG_R___________________, KC_MINS,
     KC_TAB  , _________________DVORAK_L1_________________,                          _________________DVORAK_R1_________________, KC_BSLS,
     KC_ESC  , _________________DVORAK_L2_________________,                          _________________DVORAK_R2_________________, KC_QUOT,
     MOD_LSFT , _________________DVORAK_L3_________________,                          _________________DVORAK_R3_________________, MOD_RSFT,
                      KC_EQL,KC_RGHT,                                                       KC_UP, KC_DOWN,
                                     KC_BSPC, KC_SPC,                         KC_TAB    , KC_ENT,
                                     KC_LGUI, MO(NUMPAD),                     MO(NUMPAD), TT(MOUSE),
                                     KC_DEL, KC_GRV,                           KC_LALT  , _______
  ),
  [NUMPAD] = LAYOUT_5x6_wrapper(
       KC_F12 , ______________________F_L__________________,                      ______________________F_R__________________, KC_F11,
       _______, _________________SYMBOL_L1_________________,                      _________________SYMBOL_R1_________________, KC_NLCK,
       _______, _________________SYMBOL_L2_________________,                      _________________SYMBOL_R2_________________, _______,
       _______, _________________SYMBOL_L3_________________,                      _________________SYMBOL_R3_________________, _______,
                       _______, _______,                                                          KC_P0 , KC_PDOT,
                                               _______, _______,            _______, _______,
                                               RESET  , _______,            _______, _______,
                                               _______, _______,            _______, _______
  ),
  [MOUSE] = LAYOUT_5x6_wrapper(

     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
     _______, _________________DVORAK_L2_________________,                        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                       _______, _______,                                                            _______, _______,
                                             _______, _______,            _______, _______,
                                             KC_LCTL, _______,            _______, _______,
                                             _______, _______,            _______, _______
  ),
};


