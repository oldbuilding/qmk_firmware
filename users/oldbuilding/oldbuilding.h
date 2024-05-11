#ifndef USERSPACE
#define USERSPACE
#pragma once

#include "quantum.h"

enum custom_keycodes {
    DVORAK = SAFE_RANGE,
    WIN_OS,
    MAC_OS,
    TOG_OS,
    TOG_KB,
    M_PRWD, // select the previous word
    SUR_SQ, // surround with square brackets
    SUR_CB, // surround with curly braces
    SUR_PB, // surround with parentheses
    SUR_AB, // surround with angle brackets
    NEW_SAFE_RANGE
};

enum common_layers { _DVORAK, _LOWER, _RAISE, _ADJUST, _LAST };

// Function declarations

bool process_record_user(uint16_t keycode, keyrecord_t *record);

// add external references to keycodes

// extern int os_mode;

bool is_win(void);
bool is_mac(void);

extern int os_mode;

#endif