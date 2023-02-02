#include QMK_KEYBOARD_H
#include "keymap_user.h"
#include "rgb_matrix_user.h"

keypos_t led_index_key_position[RGB_MATRIX_LED_COUNT];

// Initialize array of led positions
void rgb_matrix_init_user(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index != NO_LED) {
                led_index_key_position[led_index] = (keypos_t){.row = row, .col = col};
            }
        }
    }
}

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     uint8_t current_layer = get_highest_layer(layer_state);
//     switch (current_layer) {
//         case MAC_BASE:
//         case WIN_BASE:
//             if (host_keyboard_led_state().caps_lock) {
//                 for (uint8_t i = led_min; i < led_max; i++) {
//                     uint16_t keycode = keymap_key_to_keycode(current_layer, led_index_key_position[i]);
//                     if (keycode == KC_CAPS) {
//                         rgb_matrix_set_color(i, RGB_RED);
//                     }
//                 }
//             }
//             break;
//     }
//     return false;
// }

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case _NUM:
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_not_transparent, RGB_GREEN);
            break;
        default:
            break;
    }

    return false;
}

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = led_min; i < led_max; i++) {
        uint16_t keycode = keymap_key_to_keycode(layer, led_index_key_position[i]);
        if ((*is_keycode)(keycode)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

bool is_transparent(uint16_t keycode) { return keycode == KC_TRNS; }
bool is_not_transparent(uint16_t keycode) { return keycode != KC_TRNS; }