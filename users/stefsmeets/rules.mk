# Add shared code
SRC += stefsmeets.c

OLED_ENABLE = no
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGB_MATRIX_ENABLE = no    # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

# https://docs.qmk.fm/#/feature_mouse_keys
MOUSEKEY_ENABLE = yes

# https://docs.qmk.fm/#/feature_unicode
UNICODE_COMMON = yes
UNICODEMAP_ENABLE = yes

# https://docs.qmk.fm/#/feature_caps_word
CAPS_WORD_ENABLE = no

# https://docs.qmk.fm/#/feature_tap_dance
TAP_DANCE_ENABLE = no

# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
COMBO_ENABLE = no

# https://docs.qmk.fm/#/feature_repeat_key
REPEAT_KEY_ENABLE = yes

# https://docs.qmk.fm/#/feature_key_overrides
KEY_OVERRIDE_ENABLE = yes

# https://docs.qmk.fm/#/feature_dynamic_macros
DYNAMIC_MACRO_ENABLE = no
