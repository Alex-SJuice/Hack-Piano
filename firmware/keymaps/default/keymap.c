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
bool oled_task_user(void) {

    switch (default_layer_state){
    case 0:
    case 1:
        oled_scroll_off();
        oled_write_P(PSTR("|  Woah, a numpad    |\n"), false);
        oled_write_P(PSTR("|     crazy, right?  |\n"), false);
        break; 
    case 2:
        oled_scroll_off();
        oled_write_P(PSTR("|  Music is like     |\n"), false);
        oled_write_P(PSTR("|      cool I guess  |\n"), false);
        break; 
    case 4:
        oled_write_P(PSTR("IMAGINE  USING  JAVA  \n"), false);
        oled_write_P(PSTR("IMAGINE  USING  JAVA  \n"), false);
        oled_scroll_left();
        break; 
    default:
        oled_scroll_off();
        oled_write_P(PSTR("|                    |\n"), false);
        oled_write_P(PSTR("|                    |\n"), false);
    }
    
    return false;
}
#endif
