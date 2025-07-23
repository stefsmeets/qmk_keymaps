#pragma once

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define QUICK_TAP_TERM 0

#define FLOW_TAP_TERM 200

// Nested tap (abba)
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// Rolling press (abab)
// #define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

// https://docs.qmk.fm/#/one_shot_keys
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2500
