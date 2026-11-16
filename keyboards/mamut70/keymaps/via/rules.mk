VIA_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
OS_DETECTION_ENABLE = yes
SEND_STRING_ENABLE = yes

# Route every process_wlength() call through the keymap's
# __wrap_process_wlength (see keymap.c), so the macOS 15.7 detection fix
# lives in the keymap instead of quantum/os_detection.c and upstream
# merges stay conflict-free.
EXTRALDFLAGS += -Wl,--wrap=process_wlength
