#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _QWERTY,
    _SYMBOL,
    _NAV,
    _NUMBER,
    _FUNCTION,
};

// layer shortcuts
#define BASE     DF(_BASE)
#define QWERTY   DF(_QWERTY)
#define SYM      MO(_SYMBOL)
#define NAV      MO(_NAV)
#define NUM      MO(_NUMBER)
#define FUNC     MO(_FUNCTION)

// Thumbs
#define LTHMB1  SYM
#define LTHMB2  KC_SPC
#define LTHMB3  LT(_FUNCTION, KC_ENT)

#define RTHMB3  MEH_T(KC_F1)
#define RTHMB2  OSM(MOD_LSFT)
#define RTHMB1  NAV

// aliases
#define SFT_TAB  MT(MOD_LSFT, KC_TAB)
#define SFT_QUO  MT(MOD_RSFT, KC_QUOT)
#define HPR_ESC  HYPR_T(KC_ESC)

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
  QUOT3,              // """
  GRV3,               // ```
  ALT_TAB,
  ALT_ESC,
};
