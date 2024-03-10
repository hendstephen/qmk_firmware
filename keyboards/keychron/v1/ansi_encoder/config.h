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

#pragma once

// Sunaku config
/* QMK */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT /* for rolling on mod-tap keys */

/* Miryoku */
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80   /* ms */
// #define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)

// // Achordion config
// #define ACHORDION_STREAK
// #define TAPPING_TERM 175
// #define PERMISSIVE_HOLD
// #define QUICK_TAP_TERM_PER_KEY

// // default but used in macros
// #undef TAPPING_TERM
// #define TAPPING_TERM 200

// // Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define QUICK_TAP_TERM 0
// #define PERMISSIVE_HOLD

/* RGB Matrix Configuration */
#define DRIVER_1_LED_TOTAL 45
#define DRIVER_2_LED_TOTAL 37
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define SNLED27351_CURRENT_TUNE \
    { 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50 }

/* Encoder Configuration */
#define ENCODER_DEFAULT_POS 0x3

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 45
