
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// .............................................................. CapsLock Layer

  [_TTCAPS] = KEYMAP(
___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , S(KC_Z) , S(KC_Y) , S(KC_O) , S(KC_U) , TD_COLN ,                      S(KC_G) , S(KC_D) , S(KC_N) , S(KC_M) , S(KC_X) , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
#ifdef UPPER_HEX
      ___x___ , S(KC_Q) , S(KC_H) , S(KC_E) , ST_A    , KC_DOT  ,                      S(KC_C) , ST_T    , S(KC_R) , S(KC_S) , S(KC_W) , ___x___ ,
#else
      ___x___ , S(KC_Q) , S(KC_H) , S(KC_E) , S(KC_A) , KC_DOT  ,                      S(KC_C) , ST_T    , S(KC_R) , S(KC_S) , S(KC_W) , ___x___ ,
#endif
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
      ___x___ , S(KC_J) , KC_MINS , KC_QUOT , S(KC_K) , KC_COMM ,                      S(KC_B) , S(KC_P) , S(KC_L) , S(KC_F) , S(KC_V) , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
___x___ , ___x___ , ___x___ , ___x___ ,
                                              TT_ESC  , TT_I    , TT_TAB  ,___x___ , ___x___ , ___x___ ,   KC_ENT  , TT_SPC  , KC_BSPC,___x___ , ___x___ , ___x___
  //                                         ---------+---------+---------  ---------+---------+---------
  ),

// ....................................................... Numberic Keypad Layer

  [_TTNUMBER] = KEYMAP(
___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
#ifdef UPPER_HEX
      ___x___ , _______ , S(KC_F) , ACT_E   , S(KC_D) , _______ ,                      KC_SLSH , KC_7    , KC_8    , KC_9    , KC_ASTR , ___x___ ,
#else
      ___x___ , _______ , KC_F    , ACT_E   , KC_D    , _______ ,                      KC_SLSH , KC_7    , KC_8    , KC_9    , KC_ASTR , ___x___ ,
#endif
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , OS_GUI  , CT_C    , AT_B    , ST_A    , _______ ,                      TD_DOT  , KC_4    , KC_5    , KC_6    , KC_MINS , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , KC_LBRC , AST_G   , KC_RBRC , _______ ,                      TD_COMM , KC_1    , KC_2    , KC_3    , KC_PLUS , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
___x___ , ___x___ , ___x___ , ___x___ ,
                                              TT_ESC  , KC_SPC  , _______ ,___x___ , ___x___ , ___x___ ,   KC_BSLS , KC_0    , KC_EQL,___x___ , ___x___ , ___x___
  //                                         ---------+---------+---------  ---------+---------+---------
  ),

// ............ .................................................. Function Keys

  [_TTFNCKEY] = KEYMAP(
___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , KC_F7   , KC_F8   , KC_F9   , KC_F12  , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , OS_GUI ,  OS_CTL ,  OS_ALT ,  OS_SFT ,  _______ ,                      _______ , KC_F4   , KC_F5   , KC_F6   , KC_F11  , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , KC_F1   , KC_F2   , KC_F3   , KC_F10  , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
___x___ , ___x___ , ___x___ , ___x___ ,
                                              TT_ESC  , _______ , _______ ,___x___ , ___x___ , ___x___ ,   _______ , _______ , _______,___x___ , ___x___ , ___x___
  //                                         ---------+---------+---------  ---------+---------+---------
  ),

// ....................................................................... Regex

  [_TTREGEX] = KEYMAP(
___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , KC_DOT  , KC_ASTR , KC_AMPR , KC_PIPE ,                      KC_ASTR , KC_LBRC , KC_CIRC , KC_RBRC , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , KC_LT   , KC_PERC , KC_GT   , KC_QUES ,                      KC_QUES , KC_LPRN , KC_DLR ,  KC_RPRN , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , KC_PLUS , KC_AT   , KC_SLSH , KC_EXLM ,                      KC_PIPE , KC_LCBR , KC_HASH , KC_RCBR , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
___x___ , ___x___ , ___x___ , ___x___ ,
                                              TT_ESC  , TD_EQL  , KC_BSLS ,___x___ , ___x___ , ___x___ ,   KC_ENT  , KC_BSLS , KC_DEL ,___x___ , ___x___ , ___x___
  //                                         ---------+---------+---------  ---------+---------+---------
  ),

// ............................................................ Navigation Layer

  [_TTCURSOR] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , KC_HOME , KC_UP   , KC_END ,  KC_PGUP , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , OS_GUI  , OS_CTL  , OS_ALT  , OS_SFT  , _______ ,                      _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , _______ , _______ , _______ , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                              TT_ESC  , _______ , _______ ,  _______ , _______ , _______
  //                                         ---------+---------+---------  ---------+---------+---------
  ),

// ............................................................... Mouse Actions

  [_TTMOUSE] = KEYMAP(
___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , KC_WH_L , KC_MS_U , KC_WH_R , KC_WH_U , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , KC_BTN3 , KC_BTN2 , KC_BTN1 , _______ ,                      _______ , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , _______ , _______ , _______ , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
___x___ , ___x___ , ___x___ , ___x___ ,
                                              TT_ESC  , _______ , _______ ,___x___ , ___x___ , ___x___ ,   _______ , _______ , _______,___x___ , ___x___ , ___x___
  //                                         ---------+---------+---------  ---------+---------+---------
  ),
