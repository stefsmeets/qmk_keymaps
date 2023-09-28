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


enum layers {
    _QWERTY = 0,
    _SYMBOL,
    _NAV,
    _NUM,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYMBOL)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define FUNC     MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define SFT_SPC  MT(MOD_LSFT, KC_SPC)
#define SFT_TAB  MT(MOD_LSFT, KC_TAB)
#define SFT_QUO  MT(MOD_RSFT, KC_QUOT)

#define FUN_ENT  LT(_FUNCTION, KC_ENT)
#define NUM_ENT  LT(_NUM, KC_ENT)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Base Layer: QWERTY

    [_QWERTY] = LAYOUT(
      KC_ESC ,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P , KC_BSPC,
      SFT_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SFT_QUO,
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_CAPS, KC_PSCR,    FUNC, QK_LEAD,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LCTL,
                                 KC_LGUI, KC_LALT,     SYM,  KC_SPC, NUM_ENT, KC_LSFT,  KC_SPC,     NAV, KC_BSPC, KC_DEL
    ),

// Layer: Neo symbols
// https://github.com/Dakes/qmk_config/blob/main/kyria/keymaps/dakes/keymap.c
// https://www.neo-layout.org/

    [_SYMBOL] = LAYOUT(
      _______,   KC_AT, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                                     KC_EXLM, KC_LABK, KC_RABK,  KC_EQL, KC_AMPR, _______,
      _______, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR,                                     KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, _______,
      _______, KC_HASH,  KC_DLR, KC_PIPE, KC_TILD, KC_GRV , _______, _______, _______, _______, KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Layer: Navigation

    [_NAV] = LAYOUT(
      _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
      _______, _______, KC_BSPC, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Layer: Number

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_ASTR,    KC_4,    KC_5,    KC_6, KC_COMM, KC_PLUS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Layer: Function

    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// Adjust Layer: Music, Locks

    [_ADJUST] = LAYOUT(
      _______, _______, _______, KC_VOLU, _______, _______,                                     KC_CAPS, _______, _______, _______, _______, _______,
      _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,                                     KC_SCRL, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        // static const char PROGMEM qmk_logo[] = {
        //     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        //     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        //     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        // oled_write_P(qmk_logo, false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n\n"), false);
                oled_write_P(PSTR("q w e r t  y u i o p\n"), false);
                oled_write_P(PSTR("a s d f g  h j k l ;\n"), false);
                oled_write_P(PSTR("z x c v b  n m , . /\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Navigation\n\n"), false);
                oled_write_P(PSTR(". h ^ e up . . . . .\n"), false);
                oled_write_P(PSTR(". < v > dn . S C A G\n"), false);
                oled_write_P(PSTR(". b . d .  . . . . .\n"), false);
                break;
            case _SYMBOL:
                oled_write_P(PSTR("Symbol\n\n"), false);
                oled_write_P(PSTR("@ _ [ ] ^  ! < > = &\n"), false);
                oled_write_P(PSTR("\\ / { } *  ? ( ) - :\n"), false);
                oled_write_P(PSTR("# $ | ~ `  + % \" ' ;\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Number\n\n"), false);
                oled_write_P(PSTR(". . . . .  / 7 8 9 -\n"), false);
                oled_write_P(PSTR("G A C S .  * 4 5 6 ,\n"), false);
                oled_write_P(PSTR(". . . . .  0 1 2 3 =\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n\n"), false);
                oled_write_P(PSTR(". . . . .  . 7 8 9 0\n"), false);
                oled_write_P(PSTR("G A C S .  . 4 5 6 1\n"), false);
                oled_write_P(PSTR(". . . . .  . 1 2 3 2\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n\n"), false);
                oled_write_P(PSTR(". . ^ . .  . . . . .\n"), false);
                oled_write_P(PSTR(".<< v >>.  . S C A G\n"), false);
                oled_write_P(PSTR(". . p m .  . . . . .\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("\nNUM ") : PSTR("\n    "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

