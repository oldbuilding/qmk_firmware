#include QMK_KEYBOARD_H
#include "preonic.h"
#include "keycode_abbreviations.c"

enum preonic_layers {
    _DVORAK = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _DEBUG
    // _NUMPAD,
    // _NAVIGATION,
    // _FUNCTIONS,
    // _SYMBOLS,
    // _SETTINGS,
    // _MEDIA,
    // _EMPTY
};

enum ortho_keycodes {
    DVORAK = SAFE_RANGE,
    NUMPAD,
    NAVIGATION,
    FUNCTIONS,
    SYMBOLS,
    SETTINGS,
    MEDIA,
    EMPTY,
    WIN_OS,
    MAC_OS,
    _TOS,
    _TKB, // toggles OS input sources between "Dvorak" and "Unicode Hex Input"
    M_PW, // select the previous word
    SURS, // surround with square brackets
    SURC, // surround with curly braces
    SURP, // surround with parentheses
    SURA  // surround with angle brackets
};

#define DVAK _DVORAK
#define LLOW MO(_LOWER)
#define LRAI MO(_RAISE)
#define LADJ MO(_ADJUST)

static int os_mode = WIN_OS;

bool is_win(void) {
    return os_mode == WIN_OS;
}

bool is_mac(void) {
    return os_mode == MAC_OS;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   "  |   ,  |   .  |   P  |   Y  |   (  |  )   |   F  |   G  |   C  |   R  |   L  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   O  |   E  |   U  |   I  |  [{  |  }]  |   D  |   H  |   T  |   N  |   S  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Q  |   J  |   K  |   X  |  ;:  |  /?  |   B  |   M  |   W  |   V  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  |  Alt |  L 1 | L 2  | L 3  | ENT  | SPC  |  <-  |   v  |   ^  |  ->  |
     * `-----------------------------------------------------------------------------------'
     */
    // clang-format off
    [_DVORAK] = LAYOUT_ortho_5x12( \
        _ESC, __1_, __2_, __3_, __4_, __5_, __6_, __7_, __8_, __9_, __0_, _BKS,
        _DQT, _COM, _DOT, __P_, __Y_, LPRN, , __F_, __G_, __C_, __R_, __L_,
        __A_, __O_, __E_, __U_, __I_, _LBC, _RBC, __D_, __H_, __T_, __N_, __S_,
        _LST, __Q_, __J_, __K_, __X_, _SCN, M_PW, __B_, __M_, __W_, __V_, __Z_,
        _LCT, _LGU, _LAT, LLOW, LRAI, LADJ, _ENT, _SPC, _LFT, _DN_, _UP_, _RGT
    ),
    [_LOWER] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, __7_, __8_, __9_, _BKS,
        ____, ____, ____, ____, ____, ____, ____, ____, __4_, __5_, __6_, _PLS,
        ____, ____, ____, ____, ____, ____, ____, ____, __1_, __2_, __3_, _MIN,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, __0_, ____, _ENT,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_RAISE] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, SLSH, BSLS, PIPE, DQUO, LCBR, RCBR,
        ____, ____, ____, ____, ____, ____, ASTR, UNDS, PLUS, QUES, LBRC, RBRC,
        ____, ____, ____, ____, ____, ____, DLR, PERC, CIRC, AMPR, LPRN, RPRN,
        ____, ____, ____, ____, ____, ____, TILD, EXLM, AT, HASH, LT, GT,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    // [_NAVIGATION] = LAYOUT_ortho_5x12( \
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    // ),
    [_DEBUG] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, F1__3_ F1__4_ F1__5_ F1__6_
        ____, ____, ____, ____, ____, ____, ____, ____, _F9_, _F10, _F11,_F12,
        ____, ____, ____, ____, ____, ____, ____, ____, _F5_, _F6_, _F7_, _F8_,
        ____, ____, ____, ____, ____, ____, ____, ____, _F1_, _F2_, _F3_, _F4_,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_ADJUST] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
        _REB, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    // [_MEDIA] = LAYOUT_ortho_5x12( \
    //     ____, ____, ____, ____, ____, ____, ____, ____, MRWD, MPLY, MFFD, MSTP,
    //     ____, ____, ____, ____, ____, ____, ____, ____, MPRV, STOP, MNXT, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, VOLD, MUTE, VOLU, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, UNDO, AGIN, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, CUT, COPY, PSTE
    // ),
    // [_EMPTY] = LAYOUT_ortho_5x12( \
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    // )
    // clang-format on
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOGGLE_OS:
            if (record->event.pressed) {
                os_mode = (os_mode == WIN_OS ? MAC_OS : WIN_OS);
            }

        case TOGGLE_KB:
            if (is_win()) {
                // Send Win + Space for Windows
                register_code(KC_LCTL); // Control key on Windows is CTL
                tap_code(KC_SPACE);
                unregister_code(KC_LCTL);
            } else {
                // Send Command + Space for macOS
                register_code(KC_LGUI); // Command key on macOS is GUI
                tap_code(KC_SPACE);
                unregister_code(KC_LGUI);
            }
            return false;

        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;

        case M_PW: // Select the previous word
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(WIN_OS ? KC_LSFT : KC_LALT);
                tap_code(KC_LEFT);
                wait_ms(100); // Wait 100 milliseconds to ensure the selection is registered
                unregister_code(WIN_OS ? KC_LSFT : KC_LALT);
                unregister_code(KC_LCTL);
                // tap_code(KC_BSPC);
            }
            return false;
            break;

        case SURS: // surround with square brackets
            SEND_STRING(SS_TAP(X_LCTRL) "x[" SS_TAP(X_LCTRL) "v]");
            return false;
            break;

        case SURC: // surround with curly braces
            SEND_STRING(SS_TAP(X_LCTRL) "x{" SS_TAP(X_LCTRL) "v}");
            return false;
            break;

        case SURP: // surround with parentheses
            SEND_STRING(SS_TAP(X_LCTRL) "x(" SS_TAP(X_LCTRL) "v)");
            return false;
            break;

        case SURA: // surround with angle brackets
            SEND_STRING(SS_TAP(X_LCTRL) "x<" SS_TAP(X_LCTRL) "v>");
            return false;
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    static uint8_t old_os_mode = 255; // Invalid value to ensure the initial update
    if (os_mode != old_os_mode) {
        old_os_mode            = os_mode;
        uint8_t spacebar_index = 38;
        if (os_mode == WIN_OS) {
            rgb_matrix_set_color(spacebar_index, RGB_PURPLE);
        } else if (os_mode == MAC_OS) {
            rgb_matrix_set_color(spacebar_index, RGB_TEAL);
        }
    }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case DVORAK:
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(_DVORAK);
//             }
//             return false;
//             break;
//         case LOWER:
//             if (record->event.pressed) {
//                 layer_on(_LOWER);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             } else {
//                 layer_off(_LOWER);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             }
//             return false;
//             break;
//         case RAISE:
//             if (record->event.pressed) {
//                 layer_on(_RAISE);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             } else {
//                 layer_off(_RAISE);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             }
//             return false;
//             break;
//     }
//     return true;
// };

// void matrix_scan_user(void) {}
