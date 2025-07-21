#include QMK_KEYBOARD_H

#include "overrides.h"
#include "emoji.h"
#include "stefsmeets.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wrapper(
       BASE_LEFT_ROW1,                                                          BASE_RIGHT_ROW1,
       BASE_LEFT_ROW2,                                                          BASE_RIGHT_ROW2,
       BASE_LEFT_ROW3,            KC_MPLY, COMPOSE, KC_PSCR, KC_MNXT,           BASE_RIGHT_ROW3,
       MS_BTN1, MS_BTN2,   LOPT1,  LPRIME,   LOPT2,   ROPT2,  RPRIME,   ROPT1, KC_LEFT, KC_RGHT
    ),

// Layer: Symbol/number
    [_SYMBOL] = LAYOUT_wrapper(
       SYMBOL_LEFT_ROW1,                                                      SYMBOL_RIGHT_ROW1,
       SYMBOL_LEFT_ROW2,                                                      SYMBOL_RIGHT_ROW2,
       SYMBOL_LEFT_ROW3,          _______, _______, _______, _______,         SYMBOL_RIGHT_ROW3,
       _______, _______, _______, _______, _______, KC_COMM,  KC_DOT,  KC_SPC, _______, _______
    ),

//  Layer: Navigation
    [_NAV] = LAYOUT_wrapper(
       NAV_LEFT_ROW1,                                                            NAV_RIGHT_ROW1,
       NAV_LEFT_ROW2,                                                            NAV_RIGHT_ROW2,
       NAV_LEFT_ROW3,             _______, _______, _______, _______,            NAV_RIGHT_ROW3,
       _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_DOWN
    ),

// Adjust Layer: F-keys, Emoji, layouts
    [_FUNCTION] = LAYOUT_wrapper(
       FUNC_LEFT_ROW1,                                                          FUNC_RIGHT_ROW1,
       FUNC_LEFT_ROW2,                                                          FUNC_RIGHT_ROW2,
       FUNC_LEFT_ROW3,            _______, _______, _______, _______,           FUNC_RIGHT_ROW3,
       _______, _______, KC_PSCR, COMPOSE, KC_MUTE, _______, _______, _______, KC_VOLD, KC_VOLU
    ),

};
