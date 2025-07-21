#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYMBOL,
    _NAV,
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
#define LPRIME  KC_SPC
#define LOPT1   LT(_SYMBOL, KC_ENT)
#define LOPT2   LGUI_T

#define RPRIME  OSM(MOD_LSFT)
#define ROPT1   MO(_NAV)
#define ROPT2   MEH_T(KC_F1)

// Pinkies
#define LPINK1  LT(_FUNCTION, KC_ESC)
#define LPINK2  LSFT_T(KC_TAB)
#define LPINK3  KC_LCTL

#define RPINK1  KC_BSPC
#define RPINK2  RSFT_T(KC_QUOT)
#define RPINK3  KC_DEL

// bottom-row mods
#define CKC_Z      LGUI_T(KC_Z)
#define CKC_X      LALT_T(KC_X)
#define CKC_DOT    LALT_T(KC_DOT)
#define CKC_SLSH   LGUI_T(KC_SLSH)

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
