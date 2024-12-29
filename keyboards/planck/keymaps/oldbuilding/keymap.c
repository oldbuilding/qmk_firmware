/* Copyright 2015-2021 Jack Humbert
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
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

#include QMK_KEYBOARD_H
#include "oldbuilding.c"

// clang-format off

enum planck_layers {
    _DEBUG = _LAST
};


enum planck_keycodes {
    BACKLIT = NEW_SAFE_RANGE,
    EXT_PLV,
};


#define DVAK _DVORAK
#define LLOW MO(_LOWER)
#define LRAI MO(_RAISE)
#define LADJ MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  | Ctrl |   -  | Alt  | LOW  |    Space    | RISE |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_DVORAK] = LAYOUT_planck_grid(
    _TAB, _QOT, _COM, _DOT, __P_, __Y_, __F_, __G_, __C_, __R_, __L_, PREV_WORD,
    _ESC, __A_, __O_, __E_, __U_, __I_, __D_, __H_, __T_, __N_, __S_, _MIN,
    _LST, _SCN, __Q_, __J_, __K_, __X_, __B_, __M_, __W_, __V_, __Z_, _ENT,
    _LGU, _LCT, _MIN, _LAT, LLOW, _SPC, _SPC, LRAI, ____, ____, ____, ____
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   &  |   *  |   (  |      |      |      |      |      |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   $  |   %  |   ^  |      |      |      |      |      |   {  |   }  |  |   |
 * |-----------------------------------------------------------------------------------|
 * |      |   !  |   @  |   #  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   )  |      |      |             |      | ADJT |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT_planck_grid(
    _GRV, __1_, __2_, __3_, __4_, __5_, __6_, __7_, __8_, __9_, __0_, _BKS,
    _DEL, _F1_, _F2_, _F3_, _F4_, _F5_, _F6_, _UND, _PLS, _LCB, _RCB, _PIP,
    ____, _F7_, _F8_, _F9_, _F10, _F11, _F12, ____, ____, _HOM, _END, ____,
    ____, ____, ____, ____, ____, ____, ____, ____, LADJ, ____, ____, ____
  ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  7   |   8  |   9  |   /  |      |      |      |  up  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  4   |   5  |   6  |   *  |      |      | left | down | rght |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  1   |   2  |   3  |   +  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  .   |   0  |   ,  |   -  |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT_planck_grid(
    _GRV, __1_, __2_, __3_, __4_, __5_, __6_, __7_, __8_, __9_, __0_, _BKS,
    _DEL, _F1_, _F2_, _F3_, _F4_, _F5_, _F6_, _MIN, _EQL, _LBC, _RBC, _BSL,
    ____, _F7_, _F8_, _F9_, _F10, _F11, _F12, ____, _MUT, _PGD, _MUT, _MST,
    ____, ____, ____, ____, ____, ____, ____, _MRW, _MFF, _VLD, _VLP, _PLY
  ),

/* Adjust (Lower + Raise)                                         | --- Auto Shift --- |
 * ,-----------------------------------------------------------------------------------. _
 * | DVAK |      |      |      |      |      |      |      |      | DOWN | UP   | PRNT | |
 * |-----------------------------------------------------------------------------------| Auto Shift
 * |      |      |      |      |      |      |      |      |      | ON   | OFF  | TOG  | |
 * |-----------------------------------------------------------------------------------| _
 * |      |      |      |      |      |      |      |      |      |      |      | input|
 * |      |      |      |      |      |      |      |      |      |      |      | src  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | reset|      |      |      |      |             |      |      |      |      |  OS  |
 * `-----------------------------------------------------------------------------------'
 */
  [_DEBUG] = LAYOUT_planck_grid(
    DVAK, ____, ____, ____, ____, ____, ____, ____, ____, _ASD, _ASU, _ASP,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, _ASO, _ASF, _ASG,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, TOGGLE_KB,
    _RET, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, TOGGLE_OS
  )
};

// clang-format on

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

// bool     muse_mode      = false;
// uint8_t  last_muse_note = 0;
// uint16_t muse_counter   = 0;
// uint8_t  muse_offset    = 70;
// uint16_t muse_tempo     = 50;

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0: {
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         }
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
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