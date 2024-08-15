#include QMK_KEYBOARD_H

#include "overrides.h"
#include "definitions.h"
#include "emoji.h"

bool is_alt_tab_active = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// q l w p b  j f o u <
// n r s t g  y h e i a
// z x c d v  k m , . >
    [_BASE] = LAYOUT(
       XXXXXXX,    KC_Q,    KC_L,    KC_W,    KC_P,    KC_B,                                        KC_J,    KC_F,    KC_O,    KC_U, KC_BSPC, XXXXXXX,
       XXXXXXX,    KC_N,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_Y,    KC_H,    KC_E,    KC_I,    KC_A, XXXXXXX,
       XXXXXXX,   Z_GUI,   X_ALT,    KC_C,    KC_D,    KC_V, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_K,    KC_M, KC_COMM,  KC_DOT,  KC_DEL, XXXXXXX,
                                  XXXXXXX, XXXXXXX,  LTHMB1,  LTHMB2,  LTHMB3,  RTHMB3,  RTHMB2,  RTHMB1, XXXXXXX, XXXXXXX
    ),


// Layer: Symbol/number
    [_SYMBOL] = LAYOUT(
      _______, KC_TILD,   KC_AT, KC_LBRC, KC_RBRC, KC_PERC,                                      KC_DLR,    KC_5,    KC_0,  KC_DOT, KC_BSLS, _______,
      _______, KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN, KC_ASTR,                                     KC_SLSH,    KC_1,    KC_2,    KC_3,    KC_4, _______,
      _______, KC_LABK, KC_PIPE, KC_MINS, KC_RABK,  KC_GRV, _______, _______, _______, _______, KC_HASH,    KC_6,    KC_7,    KC_8,    KC_9, _______,
                                 _______, _______, _______, _______, _______, _______, _______,  KC_SPC, _______, _______
    ),

//  Layer: Navigation
    [_NAV] = LAYOUT(
      _______,  KC_ESC, PRV_TAB, SELWORD, NXT_TAB, KC_PGUP,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX, KC_LEFT,   KC_UP, KC_RGHT, KC_PGDN,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, XXXXXXX, KC_HOME, KC_DOWN, KC_END,  XXXXXXX, _______, _______, _______, _______, XXXXXXX, ALT_TAB, ALT_ESC, XXXXXXX, XXXXXXX, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Adjust Layer: F-keys, Emoji, layouts
    [_FUNCTION] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                                     UM(E11), UM(E12), UM(E13), UM(E14), UM(E15), _______,
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, COMPOSE,                                     UM(E21), UM(E22), UM(E23), UM(E24), UM(E25), _______,
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR, _______, _______, _______, _______, UM(E31), UM(E32), UM(E33), UM(E34), UM(E35), _______,
                                 _______, _______, _______, _______, C(KC_P), C(KC_P), _______, _______, _______, _______
    ),

};


// Turn off power led
// https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
void keyboard_pre_init_user(void) {
  setPinOutput(24);
  writePinHigh(24);
}


// https://docs.qmk.fm/#/ref_functions?id=update_tri_layer_statestate-x-y-z
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
    // return update_tri_layer_state(state, _NAV, _SYMBOL, _ADJUST);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case ALT_TAB: // super alt tab macro
        if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        return false;

    case ALT_ESC: // super alt esc macro
        if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            register_code(KC_ESC);
        } else {
            unregister_code(KC_ESC);
        }
        return false;

    case LIST:  // Types '- [ ] '
      if (record->event.pressed) {
        SEND_STRING("- [ ] ");
      }
      return false;

    case TAB4SP:  // Types '    '
      if (record->event.pressed) {
        SEND_STRING("    ");
      }
      return false;

    case RABK3:  // Types '>>> '
      if (record->event.pressed) {
        SEND_STRING(">>> ");
      }
      return false;

    case LABK3:  // Types '<<< '
      if (record->event.pressed) {
        SEND_STRING("<<< ");
      }
      return false;

    case QUOT3:  // Types '"""'
      if (record->event.pressed) {
        SEND_STRING("\"\"\"");
      }
      return false;

    case GRV3:  // Types '```'
      if (record->event.pressed) {
        SEND_STRING("```");
      }
      return false;

    case SELWORD:  // Selects the current word under the cursor.
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT) SS_LSFT(SS_TAP(X_RIGHT))));
      }
      return false;

    case RARROW:  // Types '->'
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;

    }

  return true;
}
