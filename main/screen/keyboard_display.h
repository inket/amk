/**
 * @file keyboard_display.h
 * @author astro
 * @brief 
 * 
 * @copyright Copyright (c) 2022, astro,  All rights reserved.
 * 
 */
#pragma once

#include "render_common.h"
#include "keyboard.h"

typedef struct {
    uint32_t x;
    uint32_t y;
    uint32_t w;
    uint32_t h;
    keypos_t pos;
} keyboard_key_t;

extern const keyboard_key_t keyboard_keys[KEYBOARD_KEY_COUNT];

bool keyboard_display_create(display_t *display, display_param_t *param);