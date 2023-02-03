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

typedef union {
  uint32_t raw;
  struct {
    bool enable_mod_tap :1
  };
} user_config_t;

user_config_t user_config;

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

enum my_keycodes {
    KC_USER_ENC = SAFE_RANGE,
    KC_USER_TOG_MT
};

#ifdef TAP_DANCE_ENABLE
#   define KC_X_SHFT TD(NUM_LAYR)
#endif
#ifndef TAP_DANCE_ENABLE
#   define KC_X_SHFT KC_LSFT
#endif

// Define home-row MT keycodes for convenience
#define MT_A LGUI_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_J RSFT_T(KC_J)
#define MT_K RCTL_T(KC_K)
#define MT_L RALT_T(KC_L)
#define MT_SCLN LGUI_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_USER_ENC,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            TG(_NUM),
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_HOME,
        KC_CAPS,  MT_A,     MT_S,     MT_D,     MT_F,     KC_G,     KC_H,     MT_J,     MT_K,     MT_L,     MT_SCLN,  KC_QUOT,    KC_ENT,   KC_END,
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
        _______,  KC_USER_TOG_MT,_______,_______,_______, _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
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
#endif
#ifndef ENCODER_MAP_ENABLE
// If you return true, it will allow the keyboard level code to run as well. 
// Returning false will override the keyboard level code, depending on how the keyboard function is set up.
// Ignore index, only one encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index > 0) return true;

    uint8_t mods = get_mods();
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    switch (current_layer) {
        case _BASE:
            if (mods & MOD_MASK_ALT) {
                tap_code(!clockwise ? KC_VOLD : KC_VOLU);
            } else {
                tap_code(!clockwise ? KC_MPRV : KC_MNXT);
            }
            return false;
        case _FN:
            if (!clockwise) {
                rgb_matrix_decrease_val();
            } else {
                rgb_matrix_increase_val();
            }
            return false;
        case _NUM:
        default:
            return false;
    }

    return false;
}
#endif

bool handle_encoder(uint8_t layer, uint8_t mods) {
    switch (layer) {
        case _BASE:
            if (mods & MOD_MASK_ALT) {
                tap_code(KC_MUTE);
            } else {
                tap_code(KC_MPLY);
            }
            return false;
        default:
            return false;
    }
    return false;
}

// Handle intercept mod-tap keys. If we have MT enabled
// we just pass the keystroke through for MT to handle.
// If not we just (un)register the original keycode.
bool handle_mt_intercept(uint16_t keycode) {
    // Mod-tap enabled, let MT handle this keystroke
    if (user_config.enable_mod_tap) {
        return true;
    } else if (record->event.pressed) {
        register_code16(KC_A);
    } else {
        unregister_code16(KC_A);
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    switch (keycode) {
        
        // Encoder
        case KC_USER_ENC:
            if (record->event.pressed) {
                return handle_encoder(current_layer, mods);
            } else {
                return true;
            }

        // Mod-tap config
        case KC_USER_TOG_MT:
            user_config.enable_mod_tap ^= 1;
            eeconfig_update_user(user_config.raw);
            return false;

        // Mod-tap home row mods
        case MT_A: return handle_mt_intercept(KC_A);
        case MT_S: return handle_mt_intercept(KC_S);
        case MT_D: return handle_mt_intercept(KC_D);
        case MT_F: return handle_mt_intercept(KC_F);
        case MT_J: return handle_mt_intercept(KC_J);
        case MT_K: return handle_mt_intercept(KC_K);
        case MT_L: return handle_mt_intercept(KC_L);
        case MT_SCLN: return handle_mt_intercept(KC_SCLN);

        // Process all other keycodes normally
        default:
            return true;
    }
    return true;
}

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

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

// EEPROM is getting reset
void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.enable_mod_tap = false;
    eeconfig_update_user(user_config.raw);
}