#include QMK_KEYBOARD_H

enum unicode_names {
    UC_GRINNING_FACE, // 😃
    UC_BEAMING_FACE, // 😁
    UC_GRINNING_FACE_WITH_SWEAT, // 😅
    UC_ROLLING_LAUGHING, // 🤣
    UC_FACE_TEARS_JOY, // 😂
    UC_WINKING_FACE, // 😉
    UC_SMILING_FACE_HALO, // 😇
    UC_SMILING_FACE_HEARTS, // 🥰
    UC_SMILING_FACE_HEART_EYES, // 😍
    UC_FACE_BLOWING_KISS, // 😘
    UC_FACE_SAVORING_FOOD, // 😋
    UC_ZANY_FACE, // 🤪
    UC_HUGGING_FACE, // 🤗
    UC_SHUSHING_FACE, // 🤫
    UC_THINKING_FACE, // 🤔
    UC_FACE_RAISED_EYEBROW, // 🤨
    UC_NEUTRAL_FACE, // 😐
    UC_SMIRKING_FACE, // 😏
    UC_FACE_ROLLING_EYES, // 🙄
    UC_PENSIVE_FACE, // 😔
    UC_FACE_VOMITING, // 🤮
    UC_WOOZY_FACE, // 🥴
    UC_PLEADING_FACE, // 🥺
    UC_LOUDLY_CRYING_FACE, // 😭
    UC_DISAPPOINTED_FACE, // 😞
    UC_FACE_SYMBOLS_MOUTH, // 🤬
    UC_SMILING_FACE_HORNS, // 😈
    UC_SKULL, // 💀
    UC_PILE_POO, // 💩
    UC_GHOST, // 👻
    UC_ALIEN_MONSTER, // 👾
    UC_RED_HEART, // ❤
    UC_BOMB, // 💣
    UC_WAVING_HAND, // 👋
    UC_OK_HAND, // 👌
    UC_CLAPPING_HANDS, // 👏
    UC_EYES, // 👀
    UC_MAN_FACEPALMING, // 🤦
    UC_TURTLE, // 🐢
    UC_SNAKE, // 🐍
    UC_SPOUTING_WHALE, // 🐳
    UC_DRAGON, // 🐉
    UC_TREX, // 🦖
    UC_ARGENTINA_A, // 🇦
    UC_ARGENTINA_R, // 🇷
    UC_THUMBSDOWN, // 👍
    UC_THUMBSUP, // 👎
};

const uint32_t unicode_map[] PROGMEM = {
    [UC_GRINNING_FACE] = 0x1F603,
    [UC_BEAMING_FACE] = 0x1F601,
    [UC_GRINNING_FACE_WITH_SWEAT] = 0x1F605,
    [UC_ROLLING_LAUGHING] = 0x1F923,
    [UC_FACE_TEARS_JOY] = 0x1F602,
    [UC_WINKING_FACE] = 0x1F609,
    [UC_SMILING_FACE_HALO] = 0x1F607,
    [UC_SMILING_FACE_HEARTS] = 0x1F970,
    [UC_SMILING_FACE_HEART_EYES] = 0x1F60D,
    [UC_FACE_BLOWING_KISS] = 0x1F618,
    [UC_FACE_SAVORING_FOOD] = 0x1F60B,
    [UC_ZANY_FACE] = 0x1F92A,
    [UC_HUGGING_FACE] = 0x1F917,
    [UC_SHUSHING_FACE] = 0x1F92B,
    [UC_THINKING_FACE] = 0x1F914,
    [UC_FACE_RAISED_EYEBROW] = 0x1F928,
    [UC_NEUTRAL_FACE] = 0x1F610,
    [UC_SMIRKING_FACE] = 0x1F60F,
    [UC_FACE_ROLLING_EYES] = 0x1F644,
    [UC_PENSIVE_FACE] = 0x1F614,
    [UC_FACE_VOMITING] = 0x1F92E,
    [UC_WOOZY_FACE] = 0x1F974,
    [UC_PLEADING_FACE] = 0x1F97A,
    [UC_LOUDLY_CRYING_FACE] = 0x1F62D,
    [UC_DISAPPOINTED_FACE] = 0x1F61E,
    [UC_FACE_SYMBOLS_MOUTH] = 0x1F92C,
    [UC_SMILING_FACE_HORNS] = 0x1F608,
    [UC_SKULL] = 0x1F480,
    [UC_PILE_POO] = 0x1F4A9,
    [UC_GHOST] = 0x1F47B,
    [UC_ALIEN_MONSTER] = 0x1F47E,
    [UC_RED_HEART] = 0x2764,
    [UC_BOMB] = 0x1F4A3,
    [UC_WAVING_HAND] = 0x1F44B,
    [UC_OK_HAND] = 0x1F44C,
    [UC_CLAPPING_HANDS] = 0x1F44F,
    [UC_EYES] = 0x1F440,
    [UC_MAN_FACEPALMING] = 0x1F926,
    [UC_TURTLE] = 0x1F422,
    [UC_SNAKE] = 0x1F40D,
    [UC_SPOUTING_WHALE] = 0x1F433,
    [UC_DRAGON] = 0x1F409,
    [UC_TREX] = 0x1F996,
    [UC_ARGENTINA_A] = 0x1F1E6,
    [UC_ARGENTINA_R] = 0x1F1F7,
    [UC_THUMBSDOWN] = 0x1F44E,
    [UC_THUMBSUP] = 0x1F44D,
};