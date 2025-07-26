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
        case CKC_DOT:
        case CKC_SLSH:
        case LPINK2:
        case RPINK2:
        case LOPT1:
        case LOPT2:
        case ROPT1:
        case ROPT2:
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
        case RPINK2:
        case LPINK2:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOPT1:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

#ifdef FLOW_TAP_TERM
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case LOPT1:
        case CKC_X:
        case CKC_Z:
        case CKC_DOT:
        case CKC_SLSH:
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

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
  if (is_flow_tap_key(prev_keycode)) {
      return FLOW_TAP_TERM;
    }

  return 0;  // Disable Flow Tap otherwise.
}
#endif  // FLOW_TAP_TERM


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
   const uint8_t mods = get_mods();
   const uint8_t all_mods = (mods | get_weak_mods());
   const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
   // const bool alt = all_mods & MOD_BIT_LALT;
   // const uint8_t layer = read_source_layers_cache(record->event.key);

   switch (keycode) {

    // Hold: SYM  |  tap: space  |  shift: _
    case LOPT1:
      if (record->tap.count) {
        if (record->event.pressed) {
          if (shift_mods) {
            del_weak_mods(MOD_MASK_SHIFT);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code16_delay(KC_UNDS, TAP_CODE_DELAY);
            set_mods(mods);
          } else {
            tap_code_delay(KC_SPC, TAP_CODE_DELAY);
          }
        }
        return false;
      }
      return true;

    // Hold: ALT  |  tap: .  |  shift: ?
    case CKC_DOT:
      if (record->tap.count) {
        if (record->event.pressed) {
          if (shift_mods) {
            del_weak_mods(MOD_MASK_SHIFT);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code16_delay(KC_QUES, TAP_CODE_DELAY);
            set_mods(mods);
          } else {
            tap_code_delay(KC_DOT, TAP_CODE_DELAY);
          }
        }
        return false;
      }
      return true;

    // Hold: GUI  |  tap:  /  |  shift-tap:  '\'
    case CKC_SLSH:
      if (record->tap.count) {
        if (record->event.pressed) {
          if (shift_mods) {
            del_weak_mods(MOD_MASK_SHIFT);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code16_delay(KC_BSLS, TAP_CODE_DELAY);
            set_mods(mods);
          } else {
            tap_code_delay(KC_SLSH, TAP_CODE_DELAY);
          }
        }
        return false;
      }
      return true;

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
