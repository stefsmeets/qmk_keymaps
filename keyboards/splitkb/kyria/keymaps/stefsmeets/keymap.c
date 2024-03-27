/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "overrides.h"
#include "definitions.h"
#include "emoji.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Base Layer: COLEMAK

// q l w p b  j f u o ;
// n r s t g  y h e a i
// z x c d v  k m , . /
    [_NERPST] = LAYOUT(
       KC_ESC,    KC_Q,    KC_L,    KC_W,    KC_P,    KC_B,                                        KC_J,    KC_F,    KC_U,    KC_O,  KC_GRV, KC_BSPC,
      SFT_TAB,    KC_N,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_Y,    KC_H,    KC_E,    KC_A,    KC_I, KC_COMM,
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, GO_BACK, COMPOSE, KC_PSCR,  KC_MEH,    KC_K,    KC_M, KC_QUOT,  KC_DOT, KC_SLSH, KC_DEL,
                                 KC_LGUI, KC_LALT, SYM_DEL,  KC_SPC, FUN_ENT, MSE_HME, OSM_SFT, NAV_END, KC_LEFT, KC_RGHT
    ),

    [_QWERTY] = LAYOUT(
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, _______, _______,    KC_N,    KC_M, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Based on:
// https://github.com/rdavison/graphite-layout
// https://www.reddit.com/r/KeyboardLayouts/comments/15zu2rn/sturdy_vs_nerps/jxjq139/
// Keeps low pinky usage, zxcv on left hand, 12 key similar to colemak-dh
    [_GRAPHITE] = LAYOUT(
      _______,    KC_Q,    KC_L,    KC_D,    KC_W,    KC_B,                                        KC_J,    KC_F,    KC_U,    KC_O, _______, _______,
      _______,    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                                        KC_Y,    KC_H,    KC_E,    KC_A,    KC_I, _______,
      _______,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V, _______, _______, _______, _______,    KC_K,    KC_P, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_COLEMAK] = LAYOUT(
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,  KC_GRV, KC_BSPC,
      SFT_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O, SFT_QUO,
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, GO_BACK, COMPOSE, KC_PSCR,  KC_MEH,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_DEL,
                                 KC_LGUI, KC_LALT, SYM_DEL,  KC_SPC, FUN_ENT, MSE_HME, OSM_SFT, NAV_END, KC_LEFT, KC_RGHT
    ),

    [_GAME] = LAYOUT(
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y, _______, _______,
      KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O, _______,
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_F6,   KC_F7, XXXXXXX, XXXXXXX,    KC_K,    KC_H, _______, _______, _______, _______,
                                 _______, _______,   GAME2,  KC_SPC,  KC_ENT, _______, _______, _______, _______, _______
    ),

    [_GAME2] = LAYOUT(
       KC_TAB,    KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK,
      KC_LSFT,     KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_LCTL,     KC_6,    KC_7,   KC_8,    KC_9,    KC_0, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______,  KC_SPC,  KC_ENT, _______, _______, _______, _______, _______
    ),

// https://getreuer.info/posts/keyboards/symbol-layer/index.html#a-reasonable-default
// Layer: Symbol
    [_SYMBOL] = LAYOUT(
      _______,   KC_AT, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR,                                      KC_DLR,    KC_7,    KC_8,    KC_9, KC_SCLN, _______,
      _______, KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN, KC_ASTR,                                     KC_COLN,    KC_4,    KC_5,    KC_6,    KC_0, SFT_ENT,
      _______, KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_BSLS, _______, _______, _______, KC_AMPR, KC_HASH,    KC_1,    KC_2,    KC_3, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, KC_COMM,  KC_SPC,  KC_DOT, KC_PERC, KC_CIRC
    ),

//  Layer: Navigation
    [_NAV] = LAYOUT(
      _______, _______, PRV_TAB, _______, NXT_TAB, KC_PGUP,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_LEFT,   KC_UP, KC_RGHT, KC_PGDN,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, _______, KC_HOME, KC_DOWN, KC_END,  _______, _______, _______, _______, _______, KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_DOWN
    ),

    [_MOUSE] = LAYOUT(
      _______, _______, PRV_TAB, _______, NXT_TAB, KC_WH_U,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_MS_L, KC_MS_U, KC_MS_R, KC_WH_D,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, _______, KC_WH_L, KC_MS_D, KC_WH_R, _______, _______, _______, _______, _______, KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
                                 _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______
    ),

//  Layer: Function
    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11, _______,
      _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_AGIN, _______, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Adjust Layer: Music, Emoji, layouts

    [_ADJUST] = LAYOUT(
      _______,    GAME, _______, KC_MPLY, KC_MUTE,  QWERTY,                                     UM(E11), UM(E12), UM(E13), UM(E14), UM(E15), UM(E16),
      _______, _______, KC_MPRV, KC_VOLU, KC_MNXT, COLEMAK,                                     UM(E21), UM(E22), UM(E23), UM(E24), UM(E25), UM(E26),
      _______, _______, _______, KC_VOLD, _______,  NERPST, _______, _______, _______, _______, UM(E31), UM(E32), UM(E33), UM(E34), UM(E35), UM(E36),                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};


// Turn off power led
// https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
void keyboard_pre_init_user(void) {
  setPinOutput(24);
  writePinHigh(24);
}


// https://docs.qmk.fm/#/ref_functions?id=update_tri_layer_statestate-x-y-z
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYMBOL, _ADJUST);
}
