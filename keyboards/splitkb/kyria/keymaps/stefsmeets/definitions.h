#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _QWERTY,
    _SYMBOL,
    _NAV,
    _FUNCTION,
    _ADJUST,
};

// layer shortcuts
#define BASE     DF(_BASE)
#define QWERTY   DF(_QWERTY)
#define SYM      MO(_SYMBOL)
#define NAV      MO(_NAV)
#define FUNC     MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

// Thumbs
#define LTHMB1  LT(_SYMBOL,   KC_EQL)
#define LTHMB2  KC_SPC
#define LTHMB3  LT(_FUNCTION, KC_ENT)

#define RTHMB3  LT(_ADJUST,   KC_TAB)
#define RTHMB2  OSM(MOD_LSFT)
#define RTHMB1  LT(_NAV,      KC_MINS)

// aliases
#define SFT_TAB  MT(MOD_LSFT, KC_TAB)
#define SFT_QUO  MT(MOD_RSFT, KC_QUOT)

#define T_MOUSE  TG(_FUNCTION)
#define COMPOSE  KC_CAPS

// Navigation
#define NXT_TAB  C(KC_TAB)
#define PRV_TAB  C(S(KC_TAB))
#define GO_BACK  A(KC_ESC)

// macros
enum custom_keycodes {
  LIST = SAFE_RANGE,  // - [ ]
  SELWORD,
  UPDIR,              // ../
  RARROW,             // ->
  TAB4SP,             // ____    
  RABK3,              // >>>
  LABK3,              // <<<
  ALT_TAB,
  ALT_ESC,
};

