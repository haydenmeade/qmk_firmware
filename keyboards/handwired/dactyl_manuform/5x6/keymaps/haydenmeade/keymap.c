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
     _______  , __________________PROG_TD_L________________,                          __________________PROG_TD_R________________, KC_DEL ,
     _______  , _________________DVORAK_L1_________________,                          _________________DVORAK_R1_________________, KC_BSLS,
     KC_UNDS  , _________________DVORAK_L2_________________,                          _________________DVORAK_R2_________________, KC_MINS,
     KC_LSPO  , _________________DVORAK_L3_________________,                          _________________DVORAK_R3_________________, KC_RSPC,
                            KC_HOME,KC_RGHT,                                                       KC_UP, KC_END,
                                             KC_BSPC, KC_SPC,                         KC_TAB    , KC_ENT,
                                             CTL_ESC, MO(NUMPAD),                     MO(NUMPAD), KC_EQL,
                                             KC_LGUI, _______,                        LT(GAMING, KC_DEL)  , KC_RALT
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


