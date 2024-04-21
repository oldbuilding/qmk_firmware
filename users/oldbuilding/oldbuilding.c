#include "oldbuilding.h"


static int os_mode = WIN_OS;

bool is_win(void) {
    return os_mode == WIN_OS;
}

bool is_mac(void) {
    return os_mode == MAC_OS;
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
