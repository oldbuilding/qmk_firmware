SRC += keymap.c
# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# link time optimizations
# this reduces the size of the output bin file
# and also disables Action Functions and Action Macros
LTO_ENABLE = yes

# the following four settings can also greatly help reduce
# the size of output bin file
COMMAND_ENABLE = no
CONSOLE_ENABLE = no # read using `hid listen`
EXTRAKEY_ENABLE = yes # media keys, system volume control
MOUSEKEY_ENABLE = no

# additional settings that can reduce the output bin size
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

# QMK magic keycodes control things like NKRO toggling,
# GUI and ALT/CTRL swapping, etc.
# Disabling it will disable those functions
MAGIC_ENABLE = yes

# if using sprintf or snprintf, the following saves  ~400 bytes
# enabling this has its own baggage
AVR_USE_MINIMAL_PRINTF = no

# CUSTOM_MATRIX = no
AUDIO_ENABLE = no
AUTO_SHIFT_ENABLE = yes
BACKLIGHT_ENABLE = yes
BLUETOOTH_ENABLE = no
BOOTMAGIC_ENABLE = no
COMBO_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
KEYLOCK_ENABLE = yes
LEADER_ENABLE = no
MIDI_ENABLE = no
MUSIC_ENABLE = no
NKRO_ENABLE = yes # 248 key rollover
ORYX_ENABLE = yes
RGB_MATRIX_ENABLE = yes
SLEEP_LED_ENABLE = yes
SPLIT_KEYBOARD = no
SPLIT_TRANSPORT = no
UCIS_ENABLE = no
UNICODE_ENABLE = yes
UNICODEMAP_ENABLE = no
VARIABLE_TRACE = no
