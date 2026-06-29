// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            KC_S,   KC_D,           KC_G,   KC_H,
                KC_X,   KC_C,           KC_B,      KC_J,
        KC_Z,                   KC_V,          KC_N,   KC_M
    )
};

#ifdef ENCODER_ENABLE
const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;

}
#endif