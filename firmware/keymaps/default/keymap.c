// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum custom_keys {
    PUBLIC = SAFE_RANGE,
    PRIVATE,
    STATIC,
    FINAL,
    DEFAULT,
    _VOID,
    OVERRIDE,
    CLASS,
    INTERFACE,
    RETURN,
    BREAK,
    CONTINUE
    #ifdef ENCODER_ENABLE
    , UP,
    DOWN
    #endif
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 
    /*
        0   3      6   9   10
      2   1   4  5   7   8   11
    */
    [0] = LAYOUT(
        KC_MINUS, KC_2, KC_1, 
        KC_DOT, KC_3, KC_4,
        KC_7, KC_5, KC_6,   
        KC_8, KC_9, KC_0                       
    ),
    [1] = LAYOUT(
        KC_2, KC_W, KC_Q, 
        KC_3, KC_E, KC_R,
        KC_5, KC_T, KC_Y,   
        KC_6, KC_7, KC_U                       
    ),
    [2] = LAYOUT(
        PUBLIC, FINAL, STATIC,
        PRIVATE, DEFAULT, _VOID,
        OVERRIDE, RETURN, BREAK,
        CLASS, INTERFACE, CONTINUE
    )
};

#ifdef ENCODER_ENABLE
const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(UP, DOWN) },
    [1] = { ENCODER_CCW_CW(UP, DOWN) },
    [2] = { ENCODER_CCW_CW(UP, DOWN) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PUBLIC:
        if(record->event.pressed)
            SEND_STRING("public ");
        break;
    case PRIVATE:
        if(record->event.pressed)
            SEND_STRING("private ");
        break;
    case STATIC:
        if(record->event.pressed)
            SEND_STRING("static ");
        break;
    case FINAL:
        if(record->event.pressed)
            SEND_STRING("final ");
        break;
    case DEFAULT:
        if(record->event.pressed)
            SEND_STRING("default ");
        break;
    case _VOID:
        if(record->event.pressed)
            SEND_STRING("void ");
        break;
    case OVERRIDE:
        if(record->event.pressed)
            SEND_STRING("@Override\n");
        break;
    case CLASS:
        if(record->event.pressed)
            SEND_STRING("class ");
        break;
    case INTERFACE:
        if(record->event.pressed)
            SEND_STRING("interface ");
        break;
    case RETURN:
        if(record->event.pressed)
            SEND_STRING("return ");
        break;
    case BREAK:
        if(record->event.pressed)
            SEND_STRING("break;\n");
        break;
    case CONTINUE:
        if(record->event.pressed)
            SEND_STRING("continue;\n");
        break;

    #ifdef ENCODER_ENABLE
    case UP:
        if(record->event.pressed) {
            if(default_layer_state == 0) {
                default_layer_state = 1;
                return false;
            } else if(default_layer_state == 0b1000000000000000) {
                default_layer_state = 0;
                return false;
            } else if(default_layer_state < 0b1000000000000000) {
                default_layer_state <<= 1;
                return false;
            }
        }
        return false;
    case DOWN:
        if(record->event.pressed) {
            if(default_layer_state > 0)
                default_layer_state >>= 1;
            else
                default_layer_state = 0b1000000000000000;
        }
        return false;
    #endif

    }
    return true;
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    oled_clear();
    char s[10];
    snprintf(s, sizeof(s), "%d", default_layer_state);
    oled_write(s,false);
    return false;
}
#endif