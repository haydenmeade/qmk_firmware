#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define SOFT_SERIAL_PIN D0
#define MASTER_LEFT

// prevent holdback of 1-3 key TxBolt chords
#define PREVENT_STUCK_MODIFIERS
// fix dual function timing
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// tap dance key press termination interval
#define TAPPING_TERM 200
#define HASKELL_TERM 200

// smooth mouse motion
// #define MOUSEKEY_INTERVAL    20
// #define MOUSEKEY_DELAY       0
// #define MOUSEKEY_TIME_TO_MAX 60
// #define MOUSEKEY_MAX_SPEED   7
// #define MOUSEKEY_WHEEL_DELAY 0

// compile time macro strings, see functions/hardware qmk script
#define PRIVATE_STRING "mysmellyoldsocks"
#define PUBLIC_STRING ""

// language tap dance operators
#define UNIX

// test all keyswitches
// #define TEST

#endif
