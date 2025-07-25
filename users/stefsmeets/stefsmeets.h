#pragma once

#include "definitions.h"

// Layer: Base layout
// q l w p b  j f o u :
// n r s t g  y h e i a
// z x c d v  k m , . /
#define BASE_LEFT_ROW1       LPINK1,     KC_Q,    KC_L,    KC_W,    KC_P,    KC_B
#define BASE_LEFT_ROW2       LPINK2,     KC_N,    KC_R,    KC_S,    KC_T,    KC_G
#define BASE_LEFT_ROW3       LPINK3,    CKC_Z,   CKC_X,    KC_C,    KC_D,    KC_V

#define BASE_RIGHT_ROW1        KC_J,     KC_F,    KC_O,    KC_U, KC_COLN,  RPINK1
#define BASE_RIGHT_ROW2        KC_Y,     KC_H,    KC_E,    KC_I,    KC_A,  RPINK2
#define BASE_RIGHT_ROW3        KC_K,     KC_M, KC_COMM, CKC_DOT,CKC_SLSH,  RPINK3

// Layer: Symbol/number
#define SYMBOL_LEFT_ROW1    KC_BSPC,  KC_SCLN,   KC_AT, KC_LBRC, KC_RBRC, KC_AMPR
#define SYMBOL_LEFT_ROW2    KC_DQUO,  KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN, KC_ASTR
#define SYMBOL_LEFT_ROW3     KC_DEL,  KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_PERC

#define SYMBOL_RIGHT_ROW1    KC_DLR, KC_LCBR,    KC_0, KC_RCBR, KC_CIRC,  _______
#define SYMBOL_RIGHT_ROW2   KC_HASH,    KC_1,    KC_2,    KC_3,    KC_4,  _______
#define SYMBOL_RIGHT_ROW3      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,  _______

// Layer: Navigation
#define NAV_LEFT_ROW1       _______,LCS(KC_Z), C(KC_X), C(KC_C), C(KC_D), C(KC_V)
#define NAV_LEFT_ROW2       _______,  JMPPREV, KC_LEFT,   KC_UP, KC_RGHT, JMPNEXT
#define NAV_LEFT_ROW3       _______,  C(KC_Z), KC_HOME, KC_DOWN,  KC_END, _______

#define NAV_RIGHT_ROW1      MS_WHLU,  QK_LLCK, _______, _______, KC_COLN, _______
#define NAV_RIGHT_ROW2      MS_WHLD,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______
#define NAV_RIGHT_ROW3         LIST,  KC_SCLN, KC_COMM,  KC_DOT, KC_SLSH, _______

// Layer: F-keys, Emoji, layouts, ...
#define FUNC_LEFT_ROW1       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define FUNC_LEFT_ROW2       QK_BOOT,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLU
#define FUNC_LEFT_ROW3       QK_MAKE,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_VOLD

#define FUNC_RIGHT_ROW1      _______, _______, _______, _______, _______, _______
#define FUNC_RIGHT_ROW2      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______
#define FUNC_RIGHT_ROW3      _______, _______, _______, _______, _______, _______
