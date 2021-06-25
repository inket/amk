/**
 * abelx_ble.h
 * common including files
 */

#pragma once

#include "config.h"
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "action_code.h"
#include "keymap.h"
#include "amk_action.h"


#define LAYOUT_default( \
    K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,          K013, K014, K015, \
  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,          K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,          K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K412,                K413, \
	K500, K501, K502,                         K503,             K510, K504, K505, K506,          K507, K508, K509  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013, K014, K015}, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113, K114, K115}, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213, K214, K116}, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311, KC_NO,  K313, K215, K216}, \
	{ K400, KC_NO,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412, KC_NO, K413,KC_NO}, \
	{ K500,  K501,  K502, KC_NO, KC_NO, KC_NO,  K503,  K510,  K504,  K505,  K506,  K507,  K508, KC_NO, K509,KC_NO}, \
}
