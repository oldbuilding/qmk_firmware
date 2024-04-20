/* Copyright 2018 Milton Griffin
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

// Keyboard Layers
#define _QW 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* DVORAK
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | '      | ,      | .      | P      | Y      |        |        |        | F      | G      | C      | R      | L      | /      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        | A      | O      | E      | U      | I      |        |        |        | D      | H      | T      | N      | S      | -      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | ;      | Q      | J      | K      | X      |        |        |        | B      | M      | W      | V      | Z      | ENTER  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | MO(1)  |        |        | LSHIFT | ENTER  | SPACE  |        | FN     | RALT   | RGUI   | RCTRL  |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */

    [_DV1] = LAYOUT_ortho_5x15(/* DVORAK */
                               KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRV, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_HOME, KC_DEL, KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END, KC_UP, KC_PGDN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(_FN), KC_RALT, KC_RGUI, KC_RCTL),

    /* DVORAK
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    |        | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | BACKSP |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    |        | '      | ,      | .      | P      | Y      | F      | G      | C      | R      | L      | /      |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        |        | A      | O      | E      | U      | I      | D      | H      | T      | N      | S      | -      |        | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT |        | ;      | Q      | J      | K      | X      | B      | M      | W      | V      | Z      |        | RSHIFT |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  |        | LGUI   | LALT   | MO(1)  |        |        | LSHIFT | ENTER  | SPACE  |        | FN     | RALT   | RGUI   | RCTRL  |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */

    [_DV2] = LAYOUT_ortho_5x15(/* DVORAK */
                               KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRV, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_HOME, KC_DEL, KC_PGUP, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END, KC_UP, KC_PGDN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(_FN), KC_RALT, KC_RGUI, KC_RCTL),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | PR SCR |        | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        | QK_BOOT |       |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */

    [_FN] = LAYOUT_ortho_5x15(/* FUNCTION */
                              KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NUM, KC_SLSH, KC_ASTR, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7, KC_P8, KC_P9, KC_MINS, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4, KC_P5, KC_P6, KC_PLUS, _______, QK_BOOT, _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, KC_APP, RGB_VAD, RGB_VAI, KC_P1, KC_P2, KC_P3, KC_PENT, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, MO(_FN), RGB_RMOD, RGB_MOD, KC_P0, _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______),
};
