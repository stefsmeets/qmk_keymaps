#include QMK_KEYBOARD_H

#include "overrides.h"
#include "definitions.h"
#include "emoji.h"

bool is_alt_tab_active = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// q l w p b  j f o u =
// n r s t g  y h e i a
// z x c d v  k m , . /
    [_BASE] = LAYOUT(
       KC_ESC,    KC_Q,    KC_L,    KC_W,    KC_P,    KC_B,                                        KC_J,    KC_F,    KC_O,    KC_U, KC_COLN, KC_BSPC,
      SFT_TAB,    KC_N,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_Y,    KC_H,    KC_E,    KC_I,    KC_A, KC_QUOT,
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_MPLY, COMPOSE, KC_PSCR, KC_MNXT,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_DEL,
                                 KC_LGUI, KC_LALT,  LTHMB1,  LTHMB2,  LTHMB3,  RTHMB3,  RTHMB2,  RTHMB1, KC_LEFT, KC_RGHT
    ),

    [_QWERTY] = LAYOUT(
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Layer: Symbol/number
    [_SYMBOL] = LAYOUT(
         GRV3,  KC_GRV,   KC_AT, KC_LBRC, KC_RBRC, KC_PERC,                                      KC_DLR,    KC_7,    KC_8,    KC_9, KC_CIRC, _______,
      _______, KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN, KC_ASTR,                                      KC_DOT,    KC_1,    KC_2,    KC_3, KC_AMPR,   QUOT3,
      _______, KC_LABK, KC_PIPE, KC_MINS, KC_RABK,   RABK3,    LIST, _______, _______, KC_MPRV, KC_HASH,    KC_4,    KC_5,    KC_6, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______
    ),

//  Layer: Navigation
    [_NAV] = LAYOUT(
      _______, XXXXXXX, PRV_TAB, SELWORD, NXT_TAB, KC_PGUP,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX, KC_LEFT,   KC_UP, KC_RGHT, KC_PGDN,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, XXXXXXX, KC_HOME, KC_DOWN, KC_END,  XXXXXXX, _______, _______, _______, _______, XXXXXXX, ALT_TAB, ALT_ESC, XXXXXXX, XXXXXXX, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_DOWN
    ),

//  Layer: Number
    [_NUMBER] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_PERC,                                      KC_DLR,    KC_7,    KC_8,    KC_9, _______, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ASTR,                                      KC_DOT,    KC_1,    KC_2,    KC_3, KC_COMM, _______,
      _______, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_AGIN, _______, _______, _______, _______, KC_HASH,    KC_4,    KC_5,    KC_6, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, _______,    KC_0,  KC_SPC, _______, _______
    ),

// Adjust Layer: F-keys, Emoji, layouts
    [_FUNCTION] = LAYOUT(
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  QWERTY,                                     UM(E11), UM(E12), UM(E13), UM(E14), UM(E15), UM(E16),
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    BASE,                                     UM(E21), UM(E22), UM(E23), UM(E24), UM(E25), UM(E26),
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, _______, _______, _______, _______, UM(E31), UM(E32), UM(E33), UM(E34), UM(E35), UM(E36),   
                                 _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_VOLD
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
