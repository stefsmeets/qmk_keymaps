#include QMK_KEYBOARD_H

#include "stefsmeets.h"

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
    // Prefer hold action
    switch (keycode) {
        case LOPT2:
        case ROPT2:
        // case LOPT1:
        case ROPT1:
        case LPINK3:
            return true;
        default:
            return false;
    }
}


bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case LOPT1:
        case CKC_X:
        case CKC_Z:
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
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
