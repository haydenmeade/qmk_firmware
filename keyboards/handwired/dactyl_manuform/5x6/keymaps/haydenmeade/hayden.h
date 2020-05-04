#pragma once

#define LAYOUT_5x6_wrapper(...)             LAYOUT_5x6(__VA_ARGS__)
// TODO
// Test out programming symbol row vs programming symbol layer
// Need a print screen key
// Function layer with volume keys / media controls
// Create the colemak layout
// Try a mouse layer

// Ctrl when held, esc when pressed.
#define CTL_ESC CTL_T(KC_ESC)

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  1  |  2  |  3  |  4  |  5  |   |  6  |  7  |  8  |  9  |  0  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________NUMBERS_L__________________  KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_R__________________  KC_6, KC_7, KC_8, KC_9, KC_0

// Programming symbols.
// ,-----+-----+-----+-----+---------------,   ,-----+-----+-----+-----+---------------,
// |  `/~  |  @/$  |  {/<  |  (/[  |  !/?  |   |  &/|  |  (/[  |  {/>  |  #/%  |  */^  |
// ,-----+-----+-----+-----+---------------,   ,-----+-----+-----+-----+---------------,
#define __________________PROG_TD_L________________  TD(GRV_TILD) , TD(AT_DLR), TD(LCBR_LABK), TD(LPRN_LBRC), TD(EXLM_QUES)
#define __________________PROG_TD_R________________  TD(APMR_PIPE), TD(RPRN_RBRC), TD(RCBR_RABK), TD(HASH_PERC), TD(ASTR_CIRC)

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// | F1  | F2  | F3  | F4  | F5  |   | F6  | F7  | F8  | F9  | F10 |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ______________________F_L__________________  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define ______________________F_R__________________  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U  |  I  |  O  |  P  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  S  |  D  |  F  |  G  |   |  H  |  J  |  K  |  L  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________QWERTY_L1_________________  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _________________QWERTY_L2_________________  KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _________________QWERTY_L3_________________  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _________________QWERTY_R1_________________  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define _________________QWERTY_R2_________________  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define _________________QWERTY_R3_________________  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

// Dvorak
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  '  |  ,  |  .  |  P  |  Y  |   |  F  |  G  |  C  |  R  |  L  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  O  |  E  |  U  |  I  |   |  D  |  H  |  T  |  N  |  S  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  ;  |  Q  |  J  |  K  |  X  |   |  B  |  M  |  W  |  V  |  Z  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________DVORAK_L1_________________  KC_QUOT , KC_COMM, KC_DOT , KC_P   , KC_Y
#define _________________DVORAK_L2_________________  KC_A    , KC_O   , KC_E   , KC_U   , KC_I
#define _________________DVORAK_L3_________________  KC_SCLN , KC_Q   , KC_J   , KC_K   , KC_X

#define _________________DVORAK_R1_________________  KC_F   , KC_G   , KC_C   , KC_R   , KC_L
#define _________________DVORAK_R2_________________  KC_D   , KC_H   , KC_T   , KC_N   , KC_S
#define _________________DVORAK_R3_________________  KC_B   , KC_M   , KC_W   , KC_V   , KC_Z

// Colemak DHm
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  F  |  P  |  B  |   |  J  |  L  |  U  |  Y  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  R  |  S  |  T  |  G  |   |  M  |  N  |  E  |  I  |  O  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  D  |  V  |   |  K  |  H  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________COLEMAKDHM_L1_________________  KC_Q    , KC_W   , KC_F   , KC_P   , KC_B
#define _________________COLEMAKDHM_L2_________________  KC_A    , KC_R   , KC_S   , KC_T   , KC_G
#define _________________COLEMAKDHM_L3_________________  KC_Z    , KC_X   , KC_C   , KC_D   , KC_V

#define _________________COLEMAKDHM_R1_________________  KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN
#define _________________COLEMAKDHM_R2_________________  KC_M   , KC_N   , KC_E   , KC_I   , KC_O
#define _________________COLEMAKDHM_R3_________________  KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH


// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  !  |  @  |  {  |  }  |  _  |   |  \  |  7  |  8  |  9  |     |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  #  |  $  |  (  |  )  |  -  |   |  =  |  4  |  5  |  6  |  |  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  %  |  ^  |  [  |  ]  |  +  |   |  *  |  1  |  2  |  3  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________SYMBOL_L1_________________  KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_UNDS
#define _________________SYMBOL_L2_________________  KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_MINS
#define _________________SYMBOL_L3_________________  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_PLUS

#define _________________SYMBOL_R1_________________  KC_BSLS, KC_P7, KC_P8 , KC_P9, KC_PAST
#define _________________SYMBOL_R2_________________  KC_EQL , KC_P4, KC_P5, KC_P6, KC_PPLS
#define _________________SYMBOL_R3_________________  KC_ASTR, KC_P1, KC_P2, KC_P3, KC_PMNS
