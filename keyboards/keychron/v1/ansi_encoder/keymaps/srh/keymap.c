/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "keymap_user.h"
#ifdef RGB_MATRIX_ENABLE
#   include "rgb_matrix_user.h"
#endif
#ifdef TAP_DANCE_ENABLE
#   include "tapdance_user.h"
#endif
// clang-format off

// typedef union {
//   uint32_t raw;
//   struct {
//   };
// } user_config_t;

// user_config_t user_config;

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#ifdef TAP_DANCE_ENABLE
#   define KC_X_SHFT TD(NUM_LAYR)
#endif
#ifndef TAP_DANCE_ENABLE
#   define KC_X_SHFT KC_LSFT
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MPLY,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            TG(_NUM),
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_HOME,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_END,
        KC_X_SHFT,KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FN),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [_NUM] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  KC_7   ,  KC_8   ,  KC_9   ,  _______,  _______,  KC_HOME,  KC_UP  ,  KC_END ,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  KC_4   ,  KC_5   ,  KC_6   ,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,              _______,            _______,
        _______,  KC_0   ,  KC_1   ,  KC_2   ,  KC_3   ,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_NUM]  = { ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE

// Init custom RGB matrix logic
void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

// Intercept dip switch to force windows from keychron's layer 2/3 to our layers
#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    default_layer_set(_BASE);
    return false;
}
#endif // DIP_SWITCH_ENABLE

// void keyboard_post_init_user(void) {
//     user_config.raw = eeconfig_read_user();
// }

// void eeconfig_init_user(void) {
//     user_config.raw = 0;
//     eeconfig_update_user(user_config.raw);
// }