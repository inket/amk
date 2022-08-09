/**
 * @file amk_cmd.c
 * @author astro
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string.h>
#include <stdlib.h>

#include "amk_cmd.h"
#include "amk_printf.h"

#ifndef CMD_DEBUG
#define CMD_DEBUG 1
#endif

#if CMD_DEBUG
#define cmd_debug  amk_printf
#else
#define cmd_debug(...)
#endif

#define BUF_SIZE    16
#define NAME_MAX    16
#define VALUE_MAX   96

typedef struct {
    uint32_t type;
    const char* str;
} cmd_str_t;

static cmd_str_t cmd_strs[] = {
    {CMD_KEYBOARD, CMD_KEYBOARD_STR},
    {CMD_MOUSE, CMD_MOUSE_STR},
    {CMD_NKRO, CMD_NKRO_STR},
    {CMD_SYSTEM, CMD_SYSTEM_STR},
    {CMD_CONSUMER, CMD_CONSUMER_STR},
    {CMD_SCREEN, CMD_SCREEN_STR},
    {CMD_LED, CMD_LED_STR},
    {CMD_LAYER, CMD_LAYER_STR},
    {CMD_KEYHIT, CMD_KEYHIT_STR},
    {CMD_STATUS, CMD_STATUS_STR},
    {CMD_TYPE_MAX, NULL},
};

static int32_t cmd_parse_type(const void *data, uint32_t size, uint8_t *type);
static int32_t cmd_parse_param(const void *data, uint32_t size, cmd_t* cmd);

int32_t cmd_parse(const void* data, uint32_t size, cmd_t* cmd)
{
    const uint8_t *cur = (const uint8_t*)data;
    cmd_debug("%s\n", cur);

    cmd->type = CMD_TYPE_MAX;
    int32_t cmd_parsed = cmd_parse_type(cur, size, &cmd->type);

    if (cmd_parsed > 0) {
        int32_t param_parsed = cmd_parse_param(cur+cmd_parsed, size-cmd_parsed, cmd); 
        if (param_parsed > 0) {
            return cmd_parsed+param_parsed;
        }
    }

    return -1;
}

static int32_t cmd_parse_type(const void *data, uint32_t size, uint8_t *type)
{
    const uint8_t *cur = (const uint8_t *)data;
    char buf[BUF_SIZE];
    uint8_t index = 0;
    uint32_t buf_max = size > BUF_SIZE ? BUF_SIZE : size;

    while(index < buf_max) {
        if(cur[index] == CMD_DELI) {
            buf[index] = '\0';
            for (int i = 0; i < CMD_TYPE_MAX; i++) {
                if (!cmd_strs[i].str) break;

                if (strcmp(buf, cmd_strs[i].str) == 0) {
                    *type = cmd_strs[i].type;
                    return index+1;
                }
            }
            return -1;
        } else {
            buf[index] = cur[index];
            index++;
        }
    }

    return -1;
}

static int32_t cmd_parse_param_token(const void* data, uint32_t size, char* name, char* value)
{
    const char *cur = (const char*)data;
    char* endl = memchr(data, CMD_PARAM_ENDL, size);
    if (!endl) return -1;

    char* deli = memchr(data, CMD_PARAM_DELI, endl-cur);
    if (!deli) {
        // no value
        memcpy(name, cur, endl-cur);
        name[endl-cur] = '\0';
    } else {
        // has value
        memcpy(name, cur, deli-cur);
        name[deli-cur] = '\0';
        memcpy(value, deli+1, endl-deli-1);
        value[endl-deli-1] = '\0';
    }

    return (endl-cur+1);
}

static void cmd_process_keyboard_param(const char *name, const char *value, cmd_t *cmd)
{
    if (strcmp(name, KEYBOARD_PARAM_MODS) == 0) {
        int d = strtol(value, NULL, 16);
        cmd->param.keyboard.mods = d;
    } else {
        int d = strtol(name, NULL, 16);
        if (d != 0) {
            for (int i = 0; i < KEYBOARD_KEY_SIZE; i++) {
                if (cmd->param.keyboard.keys[i] == 0) {
                    cmd->param.keyboard.keys[i] = d;
                    break;
                }
            }
        }
    }
}

static int32_t cmd_process_mouse_param(void)
{
    return -1;
}

static int32_t cmd_process_nkro_param(void)
{
    return -1;
}

static int32_t cmd_process_system_param(void)
{
    return -1;
}

static int32_t cmd_process_consumer_param(void)
{
    return -1;
}

static void cmd_process_layer_param(const char *name, const char *value, cmd_t *cmd)
{
    cmd->param.layer = strtol(name, NULL, 10);
}

static void cmd_process_led_param(const char *name, const char *value, cmd_t *cmd)
{
    cmd->param.led = strtol(name, NULL, 10);
}

static void cmd_process_keyhit_param(const char *name, const char *value, cmd_t *cmd)
{
    if (strcmp(name, KEYHIT_PARAM_ROW) == 0) {
        cmd->param.keyhit.row = strtol(value, NULL, 10);
    } else if (strcmp(name, KEYHIT_PARAM_COL) == 0) {
        cmd->param.keyhit.col = strtol(value, NULL, 10);
    } else if (strcmp(name, KEYHIT_PARAM_PRESSED) == 0) {
        cmd->param.keyhit.pressed = strtol(value, NULL, 10);
    }
}

static void cmd_process_screen_param(const char *name, const char *value, cmd_t *cmd)
{
    if (strcmp(name, SCREEN_PARAM_POWER) == 0) {
        cmd->param.screen.action = CMD_SCREEN_POWER;
        if (strcmp(value, CMD_PARAM_ON) == 0) {
            cmd->param.screen.state = 1;
        } else {
            cmd->param.screen.state = 0;
        }
    } else if (strcmp(name, SCREEN_PARAM_MSC) == 0) {
        cmd->param.screen.action = CMD_SCREEN_MSC;
        if (strcmp(value, CMD_PARAM_ON) == 0) {
            cmd->param.screen.state = 1;
        } else {
            cmd->param.screen.state = 0;
        }
    }
}

static void cmd_process_status_param(const char *name, const char *value, cmd_t *cmd)
{
    if (strcmp(name, CMD_PARAM_OK) == 0) {
        cmd->param.status = 1;
    } else {
        cmd->param.status = 0;
    }
}

static int32_t cmd_parse_param(const void *data, uint32_t size, cmd_t* cmd)
{
    char name[NAME_MAX];
    char value[VALUE_MAX];
    uint32_t parsed = 0;
    const char* cur = (const char*)data;
    while( parsed < size) {
        int32_t result = cmd_parse_param_token(cur, size, name, value);
        if (result < 0) {
            break;
        } else {
            parsed += result;
            cur += result;
            switch(cmd->type) {
            case CMD_KEYBOARD:
                cmd_process_keyboard_param(name, value, cmd);
                break;
            case CMD_MOUSE:
                cmd_process_mouse_param();
                break;
            case CMD_NKRO:
                cmd_process_nkro_param();
                break;
            case CMD_SYSTEM:
                cmd_process_system_param();
                break;
            case CMD_CONSUMER:
                cmd_process_consumer_param();
                break;
            case CMD_SCREEN:
                cmd_process_screen_param(name, value, cmd);
                break;
            case CMD_LED:
                cmd_process_led_param(name, value, cmd);
                break;
            case CMD_LAYER:
                cmd_process_layer_param(name, value, cmd);
                break;
            case CMD_KEYHIT:
                cmd_process_keyhit_param(name, value, cmd);
                break;
            case CMD_STATUS:
                cmd_process_status_param(name, value, cmd);
                break;
            default:
                break;
            }
        }
    }
    
    if (parsed) return parsed;

    return -1;
}

static int32_t cmd_compose_keyboard(const cmd_t *cmd, void *buf, uint32_t size)
{
    int32_t valid = 0;
    char *p = (char *)buf;
    // put modifiers always
    int32_t result = snprintf(p, size, "%s:%s=%x;",
                        CMD_KEYBOARD_STR,
                        KEYBOARD_PARAM_MODS,
                        cmd->param.keyboard.mods);

    if (result < 0) return result;
    valid += result;
    p += result;
    size -= result;
    for(int i = 1; i < KEYBOARD_KEY_SIZE; i++) {
        if (cmd->param.keyboard.keys[i]) {
            result = snprintf(p, size, "%x;", cmd->param.keyboard.keys[i]);
            if (result < 0) return result;

            valid += result;
            p += result;
            size -= result;
        }
    }

    result = snprintf(p, size, "\n");
    if (result < 0) return result;

    return result+valid;
}

static int32_t cmd_compose_screen(const cmd_t *cmd, void *buf, uint32_t size)
{
    int32_t result = -1;
    if (cmd->param.screen.action == CMD_SCREEN_POWER) {
        result = snprintf(buf, size, "%s:%s=%s;\n", 
                    CMD_SCREEN_STR, 
                    SCREEN_PARAM_POWER,
                    cmd->param.screen.state ? CMD_PARAM_ON:CMD_PARAM_OFF);
    } else if (cmd->param.screen.action == CMD_SCREEN_MSC) {
        result = snprintf(buf, size, "%s:%s=%s;\n", 
                    CMD_SCREEN_STR, 
                    SCREEN_PARAM_MSC,
                    cmd->param.screen.state ? CMD_PARAM_ON:CMD_PARAM_OFF);
    }

    return result;
}

static int32_t cmd_compose_led(const cmd_t *cmd, void *buf, uint32_t size)
{
    int32_t result = snprintf(buf, size, "%s:%d;\n", 
                    CMD_LED_STR, 
                    cmd->param.led);

    return result;
}

static int32_t cmd_compose_layer(const cmd_t *cmd, void *buf, uint32_t size)
{
    int32_t result = snprintf(buf, size, "%s:%d;\n", 
                    CMD_LAYER_STR, 
                    cmd->param.layer);

    return result;
}
static int32_t cmd_compose_keyhit(const cmd_t *cmd, void *buf, uint32_t size)
{
    int32_t result = snprintf(buf, size, "%s:%s=%d;%s=%d;%s=%d;\n", 
                    CMD_KEYHIT_STR, 
                    KEYHIT_PARAM_ROW,
                    cmd->param.keyhit.row,
                    KEYHIT_PARAM_COL,
                    cmd->param.keyhit.col,
                    KEYHIT_PARAM_PRESSED,
                    cmd->param.keyhit.pressed);

    return result;
}

static int32_t cmd_compose_status(const cmd_t *cmd, void *buf, uint32_t size)
{
    int32_t result = snprintf(buf, size, "%s:%s;\n", 
                    CMD_STATUS_STR, 
                    cmd->param.status ? CMD_PARAM_OK:CMD_PARAM_FAIL);

    return result;
}

int32_t cmd_compose(const cmd_t *cmd, void* buf, uint32_t size)
{
    int32_t result = -1;
    switch(cmd->type) {
    case CMD_KEYBOARD:
        result = cmd_compose_keyboard(cmd, buf, size);
        break;
    case CMD_MOUSE:
        break;
    case CMD_NKRO:
        break;
    case CMD_SYSTEM:
        break;
    case CMD_CONSUMER:
        break;
    case CMD_SCREEN:
        result = cmd_compose_screen(cmd, buf, size);
        break;
    case CMD_LED:
        result = cmd_compose_led(cmd, buf, size);
        break;
    case CMD_LAYER:
        result = cmd_compose_layer(cmd, buf, size);
        break;
    case CMD_KEYHIT:
        result = cmd_compose_keyhit(cmd, buf, size);
        break;
    case CMD_STATUS:
        result = cmd_compose_status(cmd, buf, size);
        break;
    default:
        break;
    }

    return result;
}
