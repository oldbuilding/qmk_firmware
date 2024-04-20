#include QMK_KEYBOARD_H
#include "preonic.h"

#define ________ KC_TRANSPARENT

enum preonic_layers {
    _DVORAK = 0,
    _NUMPAD,
    _NAVIGATION,
    _FUNCTIONS,
    _SYMBOLS,
    _SETTINGS,
    _MEDIA,
    _EMPTY
};

enum ortho_keycodes {
  DVORAK = SAFE_RANGE,
  NUMPAD,
  NAVIGATION,
  FUNCTIONS,
  SYMBOLS,
  SETTINGS,
  MEDIA,
  EMPTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    // clang-format off
    [_DVORAK] = LAYOUT_ortho_5x12( \
        KC_SLSH, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
        KC_EQL, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_PGUP,
        KC_DEL, LT(_NUMPAD, KC_A), LT(_NAVIGATION, KC_O), LT(_FUNCTIONS, KC_O), LT(_SYMBOLS, KC_U), KC_I, KC_D, LT(_SETTINGS, KC_H), LT(_MEDIA, KC_T), LT(_EMPTY, KC_N), KC_S, KC_PGDN,
        MT(KC_BSPC, KC_PIPE), KC_SCLN, MT(KC_CUT, KC_Q), MT(KC_COPY, KC_J), MT(KC_PSTE, KC_K), KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_HOME,
        MT(KC_DEL, KC_TAB), KC_LCTL, KC_LGUI, KC_LALT, KC_ENT, MT(MOD_LALT, KC_ENT), MT(MOD_LSFT, KC_SPACE), KC_TAB, KC_ESC, KC_LBRC, KC_RBRC, KC_END
    ),
    [_NUMPAD] = LAYOUT_ortho_5x12( \
        ________, ________, ________, ________, ________, ________, ________, KC_PAST, KC_P7, KC_P8, KC_P9, KC_BSPC,
        ________, ________, ________, ________, ________, ________, ________, KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PPLS,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_P1, KC_P2, KC_P3, KC_PMNS,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_PCMM, KC_P0, KC_PDOT, MT(KC_ENTER, KC_PEQL),
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
    ),
    [_NAVIGATION] = LAYOUT_ortho_5x12( \
        ________, ________, ________, ________, ________, ________, ________, ________, ________, KC_WBAK, KC_WFWD, KC_DEL,
        ________, ________, ________, ________, ________, ________, ________, ________, C_S_T(KC_TAB), LCTL(KC_UP), LCTL(KC_TAB), KC_PGUP,
        ________, ________, ________, ________, ________, ________, ________, ________, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT), KC_PGDN,
        ________, ________, ________, ________, ________, ________, ________, ________, LSA(KC_TAB), KC_UP, LALT(KC_TAB), KC_HOME,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
    ),
    [_FUNCTIONS] = LAYOUT_ortho_5x12( \
        ________, ________, ________, ________, ________, ________, ________, ________, KC_F13, KC_F14, KC_F15, KC_F16,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_F9, KC_F10, KC_F11, KC_F12,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_F5, KC_F6, KC_F7, KC_F8,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_F1, KC_F2, KC_F3, KC_F4,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
    ),
    [_SYMBOLS] = LAYOUT_ortho_5x12( \
        ________, ________, ________, ________, ________, ________, KC_SLSH, KC_BSLS, KC_PIPE, KC_DQUO, KC_LCBR, KC_RCBR,
        ________, ________, ________, ________, ________, ________, KC_ASTR, KC_UNDS, KC_PLUS, KC_QUES, KC_LBRC, KC_RBRC,
        ________, ________, ________, ________, ________, ________, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN,
        ________, ________, ________, ________, ________, ________, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_LT, KC_GT,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
    ),
    [_SETTINGS] = LAYOUT_ortho_5x12( \
        QK_BOOT, ________, ________, ________, ________, ________, ________, ________, BL_BRTG, BL_INC, BL_ON, BL_TOGG,
        ________, ________, ________, ________, ________, ________, ________, ________, BL_STEP, BL_DEC, BL_OFF, RGB_TOG,
        ________, ________, ________, ________, ________, ________, ________, RGB_MOD, RGB_SPI, RGB_VAI, RGB_HUI, RGB_SAI,
        ________, ________, ________, ________, ________, ________, ________, RGB_RMOD, RGB_SPD, RGB_VAD, RGB_HUD, RGB_SAD,
        NK_TOGG, ________, ________, RGB_M_G, RGB_M_T, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X
    ),
    [_MEDIA] = LAYOUT_ortho_5x12( \
        ________, ________, ________, ________, ________, ________, ________, ________, KC_MRWD, KC_MPLY, KC_MFFD, KC_MSTP,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_MPRV, KC_STOP, KC_MNXT, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, KC_VOLD, KC_MUTE, KC_VOLU, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, KC_UNDO, KC_AGIN, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, KC_CUT, KC_COPY, KC_PSTE
    ),
    [_EMPTY] = LAYOUT_ortho_5x12( \
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
    )
// clang-format on
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

void matrix_scan_user(void) {
}
