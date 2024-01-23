/* Copyright 2021 SonOfAres
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
#include "os_detection.h"
enum layer_names {
    _BASE,
    _PC,
    _PC_CTR,
    _PROG,
    _NUM_ROW,
    _MOUSE,
    _NUMPAD,
    _NAV
};
// enum custom_keycodes {
//   ST_MACRO_0 = SAFE_RANGE,
//   ST_MACRO_11,
//   KEYCODES_LAST
// };
enum {
    TD_KC_RSHIFT_CAPS,
    TD_KC_LALT_MOVE_TO_NUM,
    TD_MOVE_TO_BASE_SPACE,
    TD_KC_I_MOVE_TO_NUM,
    TD_KC_K_MOVE_TO_NUM,
    TD_KC_J_MOVE_TO_NUM,
    TD_KC_L_MOVE_TO_NUM,
    TD_MOVE_TO_BASE_LALT,
    TD_KC_BSPC_ENTER,
    TD_F6,
    DANCE_9,

};

enum tap_dance_codes {
  CMD_TD,
  LBRC_TD,
  BSLS_TD,
  QUOTE_TD,
  RBRC_TD,
  SLSH_TD,
  MINS_TD,
};
// Tap Dance declarations
#define CKC_SUPER KC_F20
#define DETECT_OS KC_F19
// enum my_keycodes {
//   CKC_SUPER = KC_HELP
// };


//without mods
#define WM(...) \
  do { \
    uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_mamut_70(
        KC_ESC,        KC_1,         KC_2,          KC_3,         KC_4,              KC_5,     DF(_BASE),                             DETECT_OS,         KC_6,       KC_7,                    KC_8,        KC_9,        KC_0,       KC_DEL,
        KC_TAB,        KC_Q,         KC_W,          KC_E,         KC_R,              KC_T,     TD(SLSH_TD),                          TD(BSLS_TD),      KC_Y,       KC_U,                    KC_I,        KC_O,        KC_P,       KC_EQL,
        KC_GRV,        KC_A,         MT(MOD_LSFT, KC_S),          MT(MOD_RALT, KC_D),         KC_F,              KC_G,     TD(MINS_TD),                          TD(QUOTE_TD),      KC_H,       KC_J,   MT(MOD_RALT, KC_K),   MT(MOD_RSFT, KC_L),        KC_SCLN,    KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,          KC_C,         KC_V,              KC_B,     TD(LBRC_TD),                          TD(RBRC_TD),      KC_N,       KC_M,                    KC_COMMA,    KC_DOT,      KC_SLSH,    KC_NO,
        MO(_NUMPAD),   KC_LCTL,      KC_LALT,       TD(CMD_TD),  LT(_NAV,KC_SPC),  KC_LSFT,   KC_ENT,                              KC_ENT,            KC_BSPC,    KC_BSPC,   KC_SPACE,     MO(_NAV),    KC_RCTL,      MO(_NUMPAD)
    ),
    [_PC] = LAYOUT_mamut_70(
        KC_ESC,        KC_1,         KC_2,          KC_3,         KC_4,              KC_5,      DF(_BASE),                           DF(_BASE),       KC_6,       KC_7,                    KC_8,        KC_9,        KC_0,       KC_DEL,
        KC_TAB,        KC_Q,         KC_W,          KC_E,         KC_R,              KC_T,       TD(SLSH_TD),                        TD(BSLS_TD),   KC_Y,                    KC_U,                     KC_I,         KC_O,       KC_P,       KC_EQL,
        KC_GRV,        KC_A,         MT(MOD_LSFT, KC_S),          MT(MOD_RALT, KC_D),         KC_F,              KC_G,     TD(MINS_TD),                          TD(QUOTE_TD),      KC_H,       KC_J,   MT(MOD_RALT, KC_K),   MT(MOD_RSFT, KC_L),        KC_SCLN,    KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,          KC_C,         KC_V,              KC_B,       TD(LBRC_TD),                        TD(RBRC_TD),   KC_N,                    KC_M,                     KC_COMMA,     KC_DOT,     KC_SLSH,    KC_NO,
        MO(_NUMPAD),   KC_LCTL,  KC_LALT,          MT(MOD_LGUI, KC_SPC),          LT(_NAV,KC_SPC),  KC_LSFT,    LT(_NAV,_PC_CTR),                    KC_ENT,         KC_BSPC,                 KC_BSPC,   KC_SPACE,       MO(_NAV),   KC_RCTL,      MO(_NUMPAD)
    ),
    [_PC_CTR] = LAYOUT_mamut_70(
        KC_ESC,        KC_1,         KC_2,          KC_3,         KC_4,              KC_5,      DF(_BASE),                           DF(_BASE),       KC_6,       KC_7,                    KC_8,        KC_9,        KC_0,       KC_DEL,
        KC_TAB,        KC_Q,         KC_W,          KC_E,         KC_R,              KC_T,       TD(SLSH_TD),                        TD(BSLS_TD),   KC_Y,                    KC_U,                     KC_I,         KC_O,       KC_P,       KC_EQL,
        KC_GRV,        KC_A,         KC_S,          MT(MOD_LALT, KC_D),         MT(MOD_LSFT, KC_F),              KC_G,     TD(MINS_TD),                          TD(QUOTE_TD),      KC_H,      MT(MOD_RSFT, KC_J),   MT(MOD_RALT, KC_K),   KC_L,        KC_SCLN,    KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,          KC_C,         KC_V,              KC_B,       TD(LBRC_TD),                        TD(RBRC_TD),   KC_N,                    KC_M,                     KC_COMMA,     KC_DOT,     KC_SLSH,    KC_NO,
        MO(_NUMPAD),   KC_LCTL,      KC_LALT,       TD(CMD_TD),  LT(_NAV,KC_SPC),  KC_LSFT,   KC_ENT,                              KC_ENT,            KC_BSPC,    KC_BSPC,   KC_SPACE,     MO(_NAV),    KC_RCTL,      MO(_NUMPAD)
    ),
    [_NUMPAD] = LAYOUT_mamut_70(
        TO(_BASE),  KC_1,        KC_2,      KC_3,           KC_4,       KC_5,      _______,       _______,       KC_6,         KC_7,        KC_8,        KC_9,      KC_0,            KC_EQL,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      KC_4,        KC_5,        KC_6,      KC_KP_ASTERISK,  KC_MINS,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      KC_1,        KC_2,        KC_3,      KC_MINS,         _______,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      KC_0,        _______,     _______,   KC_PLUS,         _______,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      _______,     _______,     _______,   _______,         _______
    ),
    [_NAV] = LAYOUT_mamut_70(
        TO(_BASE),     KC_F1,      KC_F2,                  KC_F3,                         KC_F4,     KC_F5,     KC_GRV,        KC_DEL,        KC_F6,       KC_F7,       KC_F8,        KC_F9,      KC_F10,        KC_WH_U,
        _______,    _______,     _______,                  KC_PAGE_UP,                    _______,   _______,   _______,       _______,       _______,     KC_HOME,     KC_UP,        KC_END,     _______,       KC_WH_D,
        _______,    _______,     MT(MOD_LSFT, KC_HOME),    MT(MOD_RALT, KC_PAGE_DOWN),    KC_END,    _______,   _______,       _______,       _______,     KC_LEFT,     KC_DOWN,      KC_RIGHT,   _______,       _______,
        _______,    _______,     _______,                  _______,                       _______,   _______,   _______,       _______,       _______,     _______,     _______,      _______,    _______,       _______,
        _______,    _______,     _______,                  _______,                       _______,   _______,   _______,       _______,       _______,     _______,     _______,      _______,    _______,       _______
    )
};

// enum combo_events {
//   CMD_C,
//   CMD_V,
//   CMD_A,
//   CMD_X,
//   CMD_S,

// };
// //uint16_t COMBO_LEN = CMD_S; // remove the COMBO_COUNT define and use this instead!

// const uint16_t PROGMEM copy_combo[] = {LGUI_T(KC_C), COMBO_END};
// const uint16_t PROGMEM paste_combo[] = {LGUI_T(KC_V), COMBO_END};

// combo_t key_combos[] = {
//    COMBO_ACTION(copy_combo),
//    COMBO_ACTION(paste_combo),
//   //COMBO(paste_combo,KC_V),
// };
// /* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case CMD_C:
//       if (pressed ) {
//         tap_code16(LCTL(KC_C));
//       break;
//     case CMD_V:
//       if (pressed ) {
//         tap_code16(LCTL(KC_V));
//       }
//       break;
//   }
// }
// }

// uint16_t get_combo_term(uint16_t index, combo_t *combo) {
//     if (combo->keys[0] == KC_LGUI) {
//         return 200;
//     }

//     return 1000;
// }
// bool caps_word_press_user(uint16_t keycode) {
//     switch (keycode) {
//         // Keycodes that continue Caps Word, with shift applied.
//         case KC_SPC:
//         case KC_MINS:
//         case KC_SCLN:
//         case KC_ESC:
//         case KC_ENT:
//         case KC_EQL:
//          case KC_C:
//             return false; // Deactivate Caps Word.
//         default:
//             return true;
//     }
// }

typedef struct {
    os_variant_t os;
    uint16_t key_code;
} Action;

typedef struct {
    uint16_t keycode;
    uint8_t mode;
} Mode;

os_variant_t selected_os = OS_UNSURE;

Action *find_action(uint16_t keycode, Action actions[][3]) {
    if (actions[keycode] != NULL) {
        for (int j = 0; j < sizeof(actions[keycode]) / sizeof(actions[keycode][0]); ++j) {
            if (selected_os == actions[keycode][j].os) {
                return &actions[keycode][j];
            }
        }
    }
    return NULL;
}

uint8_t find_mode(uint16_t keycode, Mode super_key_to_mask[][6]) {
    uint8_t def_mod = MOD_LGUI;
    if (super_key_to_mask[selected_os] != NULL) {
        for (int j = 0; j < sizeof(super_key_to_mask[selected_os]) / sizeof(super_key_to_mask[selected_os][0]); ++j) {
            if (CKC_SUPER == super_key_to_mask[selected_os][j].keycode) {
                def_mod = super_key_to_mask[selected_os][j].mode;
            }
            if (keycode == super_key_to_mask[selected_os][j].keycode) {
                return super_key_to_mask[selected_os][j].mode;
            }
        }
    }
    return def_mod;
}

bool process_key_action(uint16_t keycode, bool pressed, Action actions[][3]) {
    uint8_t key_without_modifiers = keycode & 0xFF;

    Action *action = find_action(key_without_modifiers, actions);
    if (action != NULL) {
        if (pressed) {
            register_code16(action->key_code);
        } else {
            unregister_code16(action->key_code);
        }
        return false;
    }
    return true;
}

Action gui_mask_actions[][3] = {
       [KC_SPC] = {{OS_LINUX, KC_LGUI },{OS_WINDOWS, KC_LGUI }},
       [KC_C] =  {{OS_LINUX, KC_INS }},
       [KC_V] =  {{OS_LINUX, KC_INS }}
};

Action default_actions[][3] = {
       [KC_HOME] = {{OS_MACOS, LGUI(KC_LEFT)}},
       [KC_END] = {{OS_MACOS, LGUI(KC_RIGHT)}}
};
const uint8_t MOD_EMPTY = 0;
Mode super_key_to_mask[][6] = {
    [OS_LINUX] = {
        { KC_TAB, MOD_LALT },
        { KC_GRV, MOD_LALT },
        { KC_C, MOD_LCTL },
        { KC_V, MOD_LSFT },
        { KC_SPACE, MOD_EMPTY },
        { CKC_SUPER, MOD_LCTL }
    },
    [OS_WINDOWS] = {
        { KC_TAB, MOD_LALT },
        { KC_GRV, MOD_LALT },
        { CKC_SUPER, MOD_LCTL }
    },
    [OS_MACOS] = {
        { CKC_SUPER, MOD_LGUI }
    }
};

uint16_t previous_key = KC_NO;
bool SUPER_ACTIVE = false;
bool process_super_action(uint16_t keycode, bool pressed) {
    if (keycode == CKC_SUPER) {
        if (!pressed) {
            // deactivate default mode for super key
            uint8_t mod_state = get_mods();
            uint8_t prev_mode = find_mode(CKC_SUPER, super_key_to_mask);
            if (prev_mode != MOD_EMPTY && mod_state & prev_mode) {
                unregister_mods(prev_mode);
            }
            previous_key = KC_NO;
        }
        SUPER_ACTIVE = pressed;
    }

    if (SUPER_ACTIVE) {
        uint8_t mod_state             = get_mods();
        uint8_t key_without_modifiers = keycode & 0xFF;
        uint8_t current_mode          = find_mode(key_without_modifiers, super_key_to_mask);
        uint8_t prev_mode             = find_mode(previous_key, super_key_to_mask);
        if (prev_mode != MOD_EMPTY && prev_mode != current_mode && mod_state & prev_mode) {
            unregister_mods(prev_mode);
        }
        if (current_mode != MOD_EMPTY && pressed && !(mod_state & current_mode)) {
            register_mods(current_mode);
        }
        previous_key = key_without_modifiers;
        return process_key_action(keycode, pressed, gui_mask_actions);
    }
    return true;
}

// uint32_t caps_word_monitor(uint32_t trigger_time, void *cb_arg) {
//     /* do something */
//     bool repeat = my_deferred_functionality();
//     return repeat ? 500 : 0;
// }
    // OS_UNSURE,
    // OS_LINUX,
    // OS_WINDOWS,
    // OS_MACOS,
    // OS_IOS,OS_LINUX
void detect_os(void) {
    if (selected_os == OS_UNSURE) {
        selected_os = detected_host_os();
        if (selected_os == OS_IOS) {
            selected_os = OS_MACOS;
        }
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    detect_os();
    if(process_super_action(keycode, record->event.pressed)){
        return process_key_action(keycode, record->event.pressed, default_actions);
    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        //case KC_MINS: // CHANGE - do not shift -_ (see below)
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            send_keyboard_report();
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_MINS: // CHANGE - default is -_ is shifted.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case TD(MINS_TD):
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

void keyboard_post_init_user(void) {
    // Initialize RGB to static blackG_inactiveG_
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(0,200,0);
}
uint8_t previous_layer = _BASE;

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(state);
    switch (current_layer) {
    case _BASE:
        rgblight_setrgb(0,200,0);
        break;
    case _PROG:
        rgblight_setrgb(0,128,255);
        break;
    case _NAV:
        rgblight_setrgb(0,0,255);
        break;
    case _NUMPAD:
        rgblight_setrgb(0,255,255);
        break;
    case _PC_CTR:
        rgblight_setrgb(77,77,77);
        break;
    case _PC:
        rgblight_setrgb(0,77,0);
        break;
    default:
        rgblight_setrgb(0,200,0);
    }
    previous_layer = current_layer;
  return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
   return layer_state_set_user(state);
}
layer_state_t layer_state_set_kb(layer_state_t state){
   return layer_state_set_user(state);
}

// Tab dance section

enum {
    QUOT_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum
};
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    SINGLE_HOLD_INTERUPTED,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

static tap dance_state[16];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted){
            return SINGLE_HOLD_INTERUPTED;
        }
        if(!state->pressed){
            return SINGLE_TAP;
        }
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);


void on_CMD_TD(tap_dance_state_t *state, void *user_data);
void CMD_TD_finished(tap_dance_state_t *state, void *user_data);
void CMD_TD_reset(tap_dance_state_t *state, void *user_data);

void on_CMD_TD(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
    }
    if(state->count > 3) {
        tap_code16(KC_LGUI);
    }
}

void CMD_TD_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(KC_SPACE);
        break;
        case SINGLE_HOLD_INTERUPTED:
            if (state->interrupting_keycode != KC_TAB && state->interrupting_keycode != KC_GRV &&
                state->interrupting_keycode != KC_LALT && state->interrupting_keycode != KC_RALT &&
                state->interrupting_keycode != KC_LCTL && state->interrupting_keycode != KC_RCTL &&
                state->interrupting_keycode != KC_LSFT && state->interrupting_keycode != KC_RSFT
                ) {
                register_code16(KC_SPACE);
            } else {
                process_super_action(CKC_SUPER, true);
            }
            break;
        case DOUBLE_TAP:
            register_code16(KC_SPACE);
            register_code16(KC_SPACE);
            break;
        case SINGLE_HOLD:
            process_super_action(CKC_SUPER, true);
            break;
        case MORE_TAPS:
            register_code16(KC_SPACE);
            break;
        case DOUBLE_HOLD:
            layer_on(_NAV);
            break;
    }
}

void CMD_TD_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD_INTERUPTED:
        if (state->interrupting_keycode != KC_TAB && state->interrupting_keycode != KC_GRV &&
            state->interrupting_keycode != KC_LALT && state->interrupting_keycode != KC_RALT &&
            state->interrupting_keycode != KC_LCTL && state->interrupting_keycode != KC_RCTL &&
            state->interrupting_keycode != KC_LSFT && state->interrupting_keycode != KC_RSFT
            ){
            unregister_code16(KC_SPACE);
        } else {
            process_super_action(CKC_SUPER, false);
        }
        break;
        case DOUBLE_TAP:
            unregister_code16(KC_SPACE);
            unregister_code16(KC_SPACE);
        break;
        case SINGLE_HOLD:
            process_super_action(CKC_SUPER, false);
        break;
        case MORE_TAPS:
            unregister_code16(KC_SPACE);
        break;
        case DOUBLE_HOLD:
            layer_off(_NAV);
        break;
    }
    dance_state[8].step = 0;
}

void on_SLSH_TD(tap_dance_state_t *state, void *user_data);
void SLSH_TD_finished(tap_dance_state_t *state, void *user_data);
void SLSH_TD_reset(tap_dance_state_t *state, void *user_data);

void on_SLSH_TD(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLSH);
        tap_code16(KC_SLSH);
        tap_code16(KC_SLSH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLSH);
    }
}

void SLSH_TD_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: register_code16(KC_SLSH); break;
        case DOUBLE_TAP: register_code16(KC_QUES); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLSH); register_code16(KC_SLSH);
    }
}

void SLSH_TD_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: unregister_code16(KC_SLSH); break;
        case DOUBLE_TAP: unregister_code16(KC_QUES); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLSH); break;
    }
    dance_state[14].step = 0;
}


void on_LBRC_TD(tap_dance_state_t *state, void *user_data);
void LBRC_TD_finished(tap_dance_state_t *state, void *user_data);
void LBRC_TD_reset(tap_dance_state_t *state, void *user_data);

void on_LBRC_TD(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
    }
    if(state->count > 3) {
        tap_code16(KC_LBRC);
    }
}

void LBRC_TD_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: register_code16(KC_LBRC); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LBRC); register_code16(KC_LBRC);
    }
}

void LBRC_TD_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LBRC); break;
    }
    dance_state[10].step = 0;
}
void on_BSLS_TD(tap_dance_state_t *state, void *user_data);
void BSLS_TD_finished(tap_dance_state_t *state, void *user_data);
void BSLS_TD_reset(tap_dance_state_t *state, void *user_data);

void on_BSLS_TD(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
    }
    if(state->count > 3) {
        tap_code16(KC_BSLS);
    }
}

void BSLS_TD_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: register_code16(KC_BSLS); break;
        case DOUBLE_TAP: register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSLS); register_code16(KC_BSLS);
    }
}

void BSLS_TD_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: unregister_code16(KC_BSLS); break;
        case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLS); break;
    }
    dance_state[11].step = 0;
}
void on_QUOTE_TD(tap_dance_state_t *state, void *user_data);
void QUOTE_TD_finished(tap_dance_state_t *state, void *user_data);
void QUOTE_TD_reset(tap_dance_state_t *state, void *user_data);

void on_QUOTE_TD(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void QUOTE_TD_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void QUOTE_TD_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[12].step = 0;
}
void on_RBRC_TD(tap_dance_state_t *state, void *user_data);
void RBRC_TD_finished(tap_dance_state_t *state, void *user_data);
void RBRC_TD_reset(tap_dance_state_t *state, void *user_data);

void on_RBRC_TD(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RBRC);
        tap_code16(KC_RBRC);
        tap_code16(KC_RBRC);
    }
    if(state->count > 3) {
        tap_code16(KC_RBRC);
    }
}

void RBRC_TD_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: register_code16(KC_RBRC); break;
        case DOUBLE_TAP: register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RBRC); register_code16(KC_RBRC);
    }
}

void RBRC_TD_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: unregister_code16(KC_RBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RBRC);break;
    }
    dance_state[13].step = 0;
}

void on_MINS_TD(tap_dance_state_t *state, void *user_data);
void MINS_TD_finished(tap_dance_state_t *state, void *user_data);
void MINS_TD_reset(tap_dance_state_t *state, void *user_data);

void on_MINS_TD(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        SEND_STRING ("->{}" SS_TAP(X_LEFT));
    }
    if(state->count > 3) {
        tap_code16(KC_MINS);
    }
}

void MINS_TD_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: register_code16(KC_MINS); break;
        case DOUBLE_TAP: register_code16(KC_UNDERSCORE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINS); register_code16(KC_MINS);
    }
}

void MINS_TD_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_HOLD_INTERUPTED:
        case SINGLE_TAP: unregister_code16(KC_MINS); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDERSCORE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINS); break;
    }
    dance_state[15].step = 0;
}


// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_KC_RSHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    [TD_KC_BSPC_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_ENTER),
    [TD_MOVE_TO_BASE_LALT] = ACTION_TAP_DANCE_LAYER_MOVE(KC_LALT, _BASE),
    [TD_KC_LALT_MOVE_TO_NUM] = ACTION_TAP_DANCE_LAYER_MOVE(KC_LALT, _NAV),
    [TD_MOVE_TO_BASE_SPACE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_SPC, _BASE),
    [TD_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),

    [CMD_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_CMD_TD, CMD_TD_finished, CMD_TD_reset),
    [LBRC_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_LBRC_TD, LBRC_TD_finished, LBRC_TD_reset),
    [BSLS_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_BSLS_TD, BSLS_TD_finished, BSLS_TD_reset),
    [QUOTE_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_QUOTE_TD, QUOTE_TD_finished, QUOTE_TD_reset),
    [RBRC_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_RBRC_TD, RBRC_TD_finished, RBRC_TD_reset),
    [SLSH_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_SLSH_TD, SLSH_TD_finished, SLSH_TD_reset),
    [MINS_TD] = ACTION_TAP_DANCE_FN_ADVANCED(on_MINS_TD, MINS_TD_finished, MINS_TD_reset),

};

