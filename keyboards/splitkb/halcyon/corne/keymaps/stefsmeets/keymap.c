#include QMK_KEYBOARD_H

#include "overrides.h"
#include "emoji.h"
#include "stefsmeets.h"

#define LAYOUT_wrapper(...) LAYOUT_corne_hlc(__VA_ARGS__)

#define HALCYON_EXTRA KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wrapper(
       BASE_LEFT_ROW1,                            BASE_RIGHT_ROW1,
       BASE_LEFT_ROW2,                            BASE_RIGHT_ROW2,
       BASE_LEFT_ROW3,                            BASE_RIGHT_ROW3,
            LOPT2,   LOPT1,  LPRIME,  RPRIME,   ROPT1,   ROPT2,
       HALCYON_EXTRA
    ),

//  Layer: Navigation
    [_NAV] = LAYOUT_wrapper(
       NAV_LEFT_ROW1,                              NAV_RIGHT_ROW1,
       NAV_LEFT_ROW2,                              NAV_RIGHT_ROW2,
       NAV_LEFT_ROW3,                              NAV_RIGHT_ROW3,
          _______, _______,  _______, _______,  TO(BASE), _______,
       HALCYON_EXTRA
),

// Layer: Symbol/number
    [_SYMBOL] = LAYOUT_wrapper(
       SYMBOL_LEFT_ROW1,                        SYMBOL_RIGHT_ROW1,
       SYMBOL_LEFT_ROW2,                        SYMBOL_RIGHT_ROW2,
       SYMBOL_LEFT_ROW3,                        SYMBOL_RIGHT_ROW3,
          _______, _______, _______, KC_COMM, LT(_NAV, KC_DOT), XXXXXXX,
       HALCYON_EXTRA
    ),

 // Adjust Layer: F-keys, Emoji, layouts
    [_FUNCTION] = LAYOUT_wrapper(
       FUNC_LEFT_ROW1,                            FUNC_RIGHT_ROW1,
       FUNC_LEFT_ROW2,                            FUNC_RIGHT_ROW2,
       FUNC_LEFT_ROW3,                            FUNC_RIGHT_ROW3,
          KC_PSCR, COMPOSE, KC_MUTE, _______, _______, _______,
       HALCYON_EXTRA
   ),

};
