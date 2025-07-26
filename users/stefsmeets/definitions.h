#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _NAV,
    _SYMBOL,
    _FUNCTION,
};

// layer shortcuts
#define BASE     DF(_BASE)
#define SYM      MO(_SYMBOL)
#define NAV      MO(_NAV)
#define NUM      MO(_NUMBER)
#define FUNC     MO(_FUNCTION)

// Thumbs
#define LPRIME  KC_ENT
#define LOPT1   LT(_SYMBOL, KC_SPC)
#define LOPT2   HYPR_T(KC_GRV)

#define RPRIME  OSM(MOD_LSFT)
#define ROPT1   TT(_NAV)
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

#define T_MOUSE    TG(_FUNCTION)
#define COMPOSE    KC_CAPS

// Home-row mods
#define HRM_N      LGUI_T(KC_N)
#define HRM_R      LALT_T(KC_R)
#define HRM_S      LCTL_T(KC_S)
#define HRM_T      LSFT_T(KC_T)

#define HRM_H      LSFT_T(KC_H)
#define HRM_E      LCTL_T(KC_E)
#define HRM_I      LALT_T(KC_I)
#define HRM_A      LGUI_T(KC_A)

// Navigation
#define NXT_TAB  C(KC_TAB)
#define PRV_TAB  C(S(KC_TAB))
#define GO_BACK  A(KC_ESC)

#define JMPNEXT  C(S(KC_BSPC))
#define JMPPREV  C(S(A(KC_BSPC)))

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
