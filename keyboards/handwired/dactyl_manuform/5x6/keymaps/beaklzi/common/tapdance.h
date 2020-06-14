
// tap dance keys
enum tap_dance {
  _ASTR = 0
 ,_COLN
 ,_COMM
 ,_DOT
 ,_EQL
 ,_GT
 ,_PASTE
 ,_PERC
 ,_PRIV
 ,_SEND
 ,_TILD
 ,_XPASTE
};

#define TD_ASTR   TD(_ASTR)
#define TD_COLN   TD(_COLN)
#define TD_COMM   TD(_COMM)
#define TD_DOT    TD(_DOT)
#define TD_EQL    TD(_EQL)
#define TD_GT     TD(_GT)
#define TD_PASTE  TD(_PASTE)
#define TD_PERC   TD(_PERC)
#define TD_PRIV   TD(_PRIV)  // compile time macro string, provided in private_string.h
#define TD_SEND   TD(_SEND)  // config.h defined macro string
#define TD_TILD   TD(_TILD)
#define TD_XPASTE TD(_XPASTE)
