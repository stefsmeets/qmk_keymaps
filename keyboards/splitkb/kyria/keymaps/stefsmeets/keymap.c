#include QMK_KEYBOARD_H

#include "overrides.h"
#include "definitions.h"
#include "emoji.h"

bool is_alt_tab_active = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// q l w p b  j f o u :
// n r s t g  y h e i a
// z x c d v  k m , . /
    [_BASE] = LAYOUT(
       LPINK1,    KC_Q,    KC_L,    KC_W,    KC_P,    KC_B,                                        KC_J,    KC_F,    KC_O,    KC_U, KC_COLN,  RPINK1,
       LPINK2,    KC_N,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_Y,    KC_H,    KC_E,    KC_I,    KC_A,  RPINK2,
       LPINK3,   CKC_Z,   CKC_X,    KC_C,    KC_D,    KC_V, KC_MPLY, COMPOSE, KC_PSCR, KC_MNXT,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RPINK3,
                        MS_BTN1, MS_BTN2,  LTHMB1,  LTHMB2,  LTHMB3,  RTHMB3,  RTHMB2,  RTHMB1, KC_LEFT, KC_RGHT
    ),

    [_QWERTY] = LAYOUT(
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Layer: Symbol/number
    [_SYMBOL] = LAYOUT(
       KC_DEL,  KC_GRV,   KC_AT, KC_LBRC, KC_RBRC, KC_AMPR,                                      KC_DLR, KC_LCBR,    KC_0, KC_RCBR, KC_CIRC, _______,
      KC_TILD, KC_PLUS,  KC_EQL, KC_LPRN, KC_RPRN, KC_ASTR,                                     KC_HASH,    KC_1,    KC_2,    KC_3,    KC_4, _______,
      KC_LGUI, KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_PERC,    LIST, _______, _______, _______,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______,
                                 _______, _______, _______, _______, _______, KC_COMM,  KC_DOT,  KC_SPC, _______, _______
    ),

//  Layer: Navigation
    [_NAV] = LAYOUT(
      _______, XXXXXXX, C(KC_X), C(KC_D), C(KC_C), KC_PGUP,                                     XXXXXXX, KC_LCBR, KC_DQUO, KC_RCBR, KC_COLN, _______,
      _______, XXXXXXX, KC_LEFT,   KC_UP, KC_RGHT, C(KC_V),                                     KC_SCLN, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, XXXXXXX, KC_HOME, KC_DOWN, KC_END,  KC_PGDN, _______, _______, _______, _______, XXXXXXX, KC_SCLN, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_DOWN
    ),

// Adjust Layer: F-keys, Emoji, layouts
    [_FUNCTION] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  QWERTY,                                     UM(E11), UM(E12), UM(E13), UM(E14), UM(E15), UM(E16),
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    BASE,                                     UM(E21), UM(E22), UM(E23), UM(E24), UM(E25), UM(E26),
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, _______, _______, _______, _______, UM(E31), UM(E32), UM(E33), UM(E34), UM(E35), UM(E36),
                                 _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU
    ),

};


// Turn off power led
// https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
void keyboard_pre_init_user(void) {
  setPinOutput(24);
  writePinHigh(24);
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_Z:
        case CKC_X:
        case LPINK2:
        case RPINK2:
            return false;
        default:
            return true;
    }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_Z:
        case CKC_X:
        case RPINK1:
        case LPINK1:
            return 200;
        default:
            return TAPPING_TERM;
    }
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LTHMB1:
        case RTHMB1:
        case LPINK3:
            return true;
        default:
            return false;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // case RTHMB3:
    //     if (record->tap.count && record->event.pressed) {
    //         tap_code16(KC_DQUO);
    //         return false;
    //     }

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
