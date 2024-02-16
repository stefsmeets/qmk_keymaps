#include QMK_KEYBOARD_H

enum unicode_names {
    E11, E12, E13, E14, E15, E16,
    E21, E22, E23, E24, E25, E26,
    E31, E32, E33, E34, E35, E36,
};

// 👍🎉🚀💪👊👋
// 🤣😁😅😬🤓😱
// 👎🧐🫣🤯🤔😭

const uint32_t unicode_map[] PROGMEM = {
    [E11] = 0x1F44D, // 👍
    [E12] = 0x1F389, // 🎉
    [E13] = 0x1F680, // 🚀
    [E14] = 0x1F4AA, // 💪
    [E15] = 0x1F44A, // 👊
    [E16] = 0x1F44B, // 👋
    [E21] = 0x1F923, // 🤣
    [E22] = 0x1F601, // 😁
    [E23] = 0x1F605, // 😅
    [E24] = 0x1F62C, // 😬
    [E25] = 0x1F913, // 🤓
    [E26] = 0x1F631, // 😱
    [E31] = 0x1F44E, // 👎
    [E32] = 0x1F9D0, // 🧐
    [E33] = 0x1FAE3, // 🫣
    [E34] = 0x1F92F, // 🤯
    [E35] = 0x1F914, // 🤔
    [E36] = 0x1F62D, // 😭
};

