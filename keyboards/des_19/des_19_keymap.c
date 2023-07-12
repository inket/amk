/**
 * @file des_19_keymap.c
 * @author astro
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "des_19.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_default(
        KC_NLCK, KC_PSLS, KC_PAST, KC_PEQL,
          KC_P7,   KC_P8,   KC_P9, KC_PMNS,
          KC_P4,   KC_P5,   KC_P6, KC_PPLS,
          KC_P1,   KC_P2,   KC_P3, KC_PENT,
          MO(1),   KC_P0, KC_PDOT),

    [1] = LAYOUT_default(
        _______, _______, _______, _______,
        _______, _______, _______, _______, 
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______),
};