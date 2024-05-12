#include QMK_KEYBOARD_H
#include "oldbuilding.h"
#include "keycode_abbreviations.c"

enum preonic_layers { _DEBUG = _LAST };

// enum ortho_keycodes {
//     // DVORAK = NEW_SAFE_RANGE,
//     // NUMPAD,
//     // NAVIGATION,
//     // FUNCTIONS,
//     // SYMBOLS,
//     // SETTINGS,
//     // MEDIA,
//     // EMPTY,
//     // WIN_OS,
//     // MAC_OS,
//     // _TOS,
//     // _TKB, // toggles OS input sources between "Dvorak" and "Unicode Hex Input"

// };

#define DVAK _DVORAK
#define LLOW MO(_LOWER)
#define LRAI MO(_RAISE)
#define LADJ MO(_ADJUST)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+--j---+------+------|
     * |   "  |   ,  |   .  |   P  |   Y  |   (  |  )   |   F  |   G  |   C  |   R  |   L  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   O  |   E  |   U  |   I  |  [{  |  }]  |   D  |   H  |   T  |   N  |   S  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   :  |   Q  |   J  |   K  |   X  |  ;:  |  /?  |   B  |   M  |   W  |   V  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  |  Alt |  L 1 | L 2  | SHFT | ENT  | SPC  |  <-  |   v  |   ^  |  ->  |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_ortho_5x12( \
        _ESC, __1_, __2_, __3_, __4_,    __5_,   __6_,     __7_, __8_, __9_, __0_, _BKS,
        _DQT, _COM, _DOT, __P_, __Y_,    _LPN,   _RPN,     __F_, __G_, __C_, __R_, __L_,
        __A_, __O_, __E_, __U_, __I_,    _LBC,   _RBC,     __D_, __H_, __T_, __N_, __S_,
        _SCN, __Q_, __J_, __K_, __X_,    _SCN,   M_PRWD,   __B_, __M_, __W_, __V_, __Z_,
        _LCT, _LGU, _LAT, LLOW, LRAI,    _LST,   _ENT,     _SPC, _LFT, _DN_, _UP_, _RGT
    ),
    [_LOWER] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, __7_, __8_, __9_, _BKS,
        ____, ____, ____, ____, ____, ____, ____, ____, __4_, __5_, __6_, _PLS,
        ____, ____, ____, ____, ____, ____, ____, ____, __1_, __2_, __3_, _MIN,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, __0_, ____, _ENT,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_RAISE] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, _SLS, _BSL, _PIP, _DQT, _LCB, _RCB,
        ____, ____, ____, ____, ____, ____, _AST, _UND, _PLS, _QMK, _LBC, _RBC,
        ____, ____, ____, ____, ____, ____, _DOL, _PRC, _CCT, _AMP, _LPN, _RPN,
        ____, ____, ____, ____, ____, ____, _TLD, _XLM, _AT_, _HSH, _LT_, _GT_,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_DEBUG] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, _F9_, _F10, _F11, _F12,
        ____, ____, ____, ____, ____, ____, ____, ____, _F5_, _F6_, _F7_, _F8_,
        ____, ____, ____, ____, ____, ____, ____, ____, _F1_, _F2_, _F3_, _F4_,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_ADJUST] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        _REB, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    )
    /*
    [_MEDIA] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, MRWD, MPLY, MFFD, MSTP,
        ____, ____, ____, ____, ____, ____, ____, ____, MPRV, STOP, MNXT, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, VOLD, MUTE, VOLU, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, UNDO, AGIN, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, CUT, COPY, PSTE
    ),
    [_EMPTY] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    )
   */
    // clang-format on
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

// void matrix_scan_user(void) {
//     static uint8_t old_os_mode = 255; // Invalid value to ensure the initial update
//     if (os_mode != old_os_mode) {
//         old_os_mode            = os_mode;
//         uint8_t spacebar_index = 38;
//         if (os_mode == WIN_OS) {
//             rgb_matrix_set_color(spacebar_index, RGB_PURPLE);
//         } else if (os_mode == MAC_OS) {
//             rgb_matrix_set_color(spacebar_index, RGB_TEAL);
//         }
//     }
// }

// void matrix_scan_user(void) {}
