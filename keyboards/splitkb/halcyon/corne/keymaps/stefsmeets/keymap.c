#include QMK_KEYBOARD_H

#include "overrides.h"
#include "emoji.h"
#include "stefsmeets.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

// Thumbs for corne
#define CLTHMB1  LGUI_T(KC_ENTER)
#define CLTHMB2  LT(_SYMBOL, KC_HOME)
#define CLTHMB3  KC_SPC

#define CRTHMB3  LSFT_T(KC_ENTER)
#define CRTHMB2  LT(_NAV, KC_END)
#define CRTHMB1  MEH_T(KC_F1)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wrapper(
       BASE_LEFT_ROW1,                            BASE_RIGHT_ROW1,
       BASE_LEFT_ROW2,                            BASE_RIGHT_ROW2,
       BASE_LEFT_ROW3,                            BASE_RIGHT_ROW3,
          CLTHMB1, CLTHMB2, CLTHMB3, CRTHMB3, CRTHMB2, CRTHMB1
    ),


// Layer: Symbol/number
    [_SYMBOL] = LAYOUT_wrapper(
       SYMBOL_LEFT_ROW1,                        SYMBOL_RIGHT_ROW1,
       SYMBOL_LEFT_ROW2,                        SYMBOL_RIGHT_ROW2,
       SYMBOL_LEFT_ROW3,                        SYMBOL_RIGHT_ROW3,
          _______, _______, _______,  KC_SPC, KC_COMM,  KC_DOT
    ),

//  Layer: Navigation
    [_NAV] = LAYOUT_wrapper(
       NAV_LEFT_ROW1,                              NAV_RIGHT_ROW1,
       NAV_LEFT_ROW2,                              NAV_RIGHT_ROW2,
       NAV_LEFT_ROW3,                              NAV_RIGHT_ROW3,
          _______, _______, _______, _______, _______, _______
    ),

// Adjust Layer: F-keys, Emoji, layouts
    [_FUNCTION] = LAYOUT_wrapper(
       FUNC_LEFT_ROW1,                            FUNC_RIGHT_ROW1,
       FUNC_LEFT_ROW2,                            FUNC_RIGHT_ROW2,
       FUNC_LEFT_ROW3,                            FUNC_RIGHT_ROW3,
          KC_PSCR, COMPOSE, KC_MUTE, _______, _______, _______
    ),

};
