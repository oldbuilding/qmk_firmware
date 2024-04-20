#include QMK_KEYBOARD_H
#include "preonic.h"
#include "keycode_abbreviations.c"

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
    EMPTY,
    WIN_OS,
    MAC_OS,
    TOGGLE_OS,
    TOGGLE_KB, // toggles OS input sources between "Dvorak" and "Unicode Hex Input"
    PREV_WORD, // select and remove the previous wor
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
        _DQT, _COM, _DOT, __P_, __Y_, LPRN, RPRN, __F_, __G_, __C_, __R_, __L_,
        __A_, __O_, __E_, __U_, __I_, LBRC, RBRC, __D_, __H_, __T_, __N_, __S_,
        _LST, __Q_, __J_, __K_, __X_, SCLN, SLSH, __B_, __M_, __W_, __V_, __Z_,
        _LCT, _LGU, _LAT, LLOW, LRAI, LADJ, _ENT, _SPC, _LFT, _DN_, _UP_, _RGT
    ),
    [_NUMPAD] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, __7_, __8_, __9_, _BKS,
        ____, ____, ____, ____, ____, ____, ____, ____, __4_, __5_, __6_, _PLS,
        ____, ____, ____, ____, ____, ____, ____, ____, __1_, __2_, __3_, _MIN,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, __0_, ____, _ENT,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_NAVIGATION] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, WBAK, WFWD, DEL,
        ____, ____, ____, ____, ____, ____, ____, ____, C_S_T(TAB), LCTL(UP), LCTL(TAB), PGUP,
        ____, ____, ____, ____, ____, ____, ____, ____, LCTL(LEFT), LCTL(DOWN), LCTL(RGHT), PGDN,
        ____, ____, ____, ____, ____, ____, ____, ____, LSA(TAB), UP, LALT(TAB), HOME,
        ____, ____, ____, ____, ____, ____, ____, ____, LEFT, DOWN, RGHT, END
    ),
    [_FUNCTIONS] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, ____, ____, F1__3_ F1__4_ F1__5_ F1__6_
        ____, ____, ____, ____, ____, ____, ____, ____, _F9_, _F10, _F11,_F12,
        ____, ____, ____, ____, ____, ____, ____, ____, _F5_, _F6_, _F7_, _F8_,
        ____, ____, ____, ____, ____, ____, ____, ____, _F1_, _F2_, _F3_, _F4_,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_SYMBOLS] = LAYOUT_ortho_5x12( \
        ____, ____, ____, ____, ____, ____, SLSH, BSLS, PIPE, DQUO, LCBR, RCBR,
        ____, ____, ____, ____, ____, ____, ASTR, UNDS, PLUS, QUES, LBRC, RBRC,
        ____, ____, ____, ____, ____, ____, DLR, PERC, CIRC, AMPR, LPRN, RPRN,
        ____, ____, ____, ____, ____, ____, TILD, EXLM, AT, HASH, LT, GT,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),
    [_SETTINGS] = LAYOUT_ortho_5x12( \
        QK_BOOT, ____, ____, ____, ____, ____, ____, ____, BL_BRTG, BL_INC, BL_ON, BL_TOGG,
        ____, ____, ____, ____, ____, ____, ____, ____, BL_STEP, BL_DEC, BL_OFF, RGB_TOG,
        ____, ____, ____, ____, ____, ____, ____, RGB_MOD, RGB_SPI, RGB_VAI, RGB_HUI, RGB_SAI,
        ____, ____, ____, ____, ____, ____, ____, RGB_RMOD, RGB_SPD, RGB_VAD, RGB_HUD, RGB_SAD,
        NK_TOGG, ____, ____, RGB_M_G, RGB_M_T, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X
    ),
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
