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
#define BASE_RIGHT_ROW3        KC_K,     KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RPINK3

// Layer: Symbol/number
#define SYMBOL_LEFT_ROW1     KC_DEL,   KC_GRV,   KC_AT, KC_LBRC, KC_RBRC, KC_AMPR
#define SYMBOL_LEFT_ROW2    KC_TILD,  KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN, KC_ASTR
#define SYMBOL_LEFT_ROW3    KC_LGUI,  KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_PERC

#define SYMBOL_RIGHT_ROW1    KC_DLR, KC_LCBR,    KC_0, KC_RCBR, KC_CIRC,  _______
#define SYMBOL_RIGHT_ROW2   KC_HASH,    KC_1,    KC_2,    KC_3,    KC_4,  _______
#define SYMBOL_RIGHT_ROW3      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,  _______

// Layer: Navigation
#define NAV_LEFT_ROW1       _______,LCS(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Z)
#define NAV_LEFT_ROW2       _______,  KC_PGUP, KC_LEFT,   KC_UP, KC_RGHT, C(KC_D)
#define NAV_LEFT_ROW3       _______,  KC_PGDN, KC_HOME, KC_DOWN,  KC_END,  KC_INS

#define NAV_LEFT_ROW1_ALT   _______,  C(KC_Y), C(KC_X), C(KC_C), C(KC_V), C(KC_Z)
#define NAV_LEFT_ROW2_ALT   _______,  KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, C(KC_D)
#define NAV_LEFT_ROW3_ALT   _______,  KC_HOME, KC_PGUP, KC_PGDN,  KC_END,  KC_INS

#define NAV_RIGHT_ROW1      KC_TILD,  KC_LCBR, KC_DQUO, KC_RCBR, KC_COLN, _______
#define NAV_RIGHT_ROW2      KC_SCLN,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______
#define NAV_RIGHT_ROW3         LIST,  KC_SCLN, KC_COMM,  KC_DOT, KC_SLSH, _______

// Layer: F-keys, Emoji, layouts, ...
#define FUNC_LEFT_ROW1       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define FUNC_LEFT_ROW2       _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLU
#define FUNC_LEFT_ROW3       _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_VOLD

#define FUNC_RIGHT_ROW1      UM(E11), UM(E12), UM(E13), UM(E14), UM(E15), UM(E16)
#define FUNC_RIGHT_ROW2      UM(E21), UM(E22), UM(E23), UM(E24), UM(E25), UM(E26)
#define FUNC_RIGHT_ROW3      UM(E31), UM(E32), UM(E33), UM(E34), UM(E35), UM(E36)
