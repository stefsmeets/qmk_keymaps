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
#define NUM      MO(_NUM)
#define MOUSE    MO(_MOUSE)
#define FUNC     MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

// aliases
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)

#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define OSM_SFT  OSM(MOD_LSFT)
#define SFT_SPC  MT(MOD_LSFT, KC_SPC)
#define SFT_TAB  MT(MOD_LSFT, KC_TAB)
#define SFT_QUO  MT(MOD_RSFT, KC_QUOT)
#define SFT_CLN  MT(MOD_RSFT, KC_COLN)
#define SFT_ENT  MT(MOD_RSFT, KC_ENT)
#define SFT_GRV  MT(MOD_LSFT, KC_GRV)

#define FUN_ENT  LT(_FUNCTION, KC_ENT)

#define NAV_BSP  LT(_NAV, KC_BSPC)
#define NAV_DEL  LT(_NAV, KC_DEL)
#define NAV_END  LT(_NAV, KC_END)
#define NAV_TAB  LT(_NAV, KC_TAB)

#define NUM_ENT  LT(_NUM, KC_ENT)

#define SYM_BSP  LT(_SYMBOL, KC_BSPC)
#define SYM_DEL  LT(_SYMBOL, KC_DEL)
#define SYM_ESC  LT(_SYMBOL, KC_ESC)
#define SYM_TAB  LT(_SYMBOL, KC_TAB)
#define SYM_MIN  LT(_SYMBOL, KC_MINS)

#define T_MOUSE  TG(_FUNCTION)

#define COMPOSE  KC_CAPS

// Navigation
#define NXT_TAB  C(KC_TAB)
#define PRV_TAB  C(S(KC_TAB))

#define GO_BACK  A(KC_ESC)

// macros
enum custom_keycodes {
  LIST = SAFE_RANGE,
  SELWORD,
  UPDIR,
  RARROW,
  TAB4SP,
  ALT_TAB,
  ALT_ESC,
};

