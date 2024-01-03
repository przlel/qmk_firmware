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
enum custom_keycodes {
  ST_MACRO_0,
  ST_MACRO_11,
};
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

enum OS {
    MAC,PC
};

static uint32_t current_os = MAC;

enum my_keycodes {
  SWITCH_OS
};

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
        KC_ESC,        KC_1,         KC_2,          KC_3,         KC_4,              KC_5,     DF(_BASE),                             DF(_PC),         KC_6,       KC_7,                    KC_8,        KC_9,        KC_0,       KC_DEL,
        KC_TAB,        KC_Q,         KC_W,          KC_E,         KC_R,              KC_T,     TD(SLSH_TD),                          TD(BSLS_TD),      KC_Y,       KC_U,                    KC_I,        KC_O,        KC_P,       KC_EQL,
        KC_GRV,        KC_A,         KC_S,          MT(MOD_LALT, KC_D),  MT(MOD_LSFT, KC_F), KC_G, TD(MINS_TD),                      TD(QUOTE_TD),      KC_H,      MT(MOD_RSFT, KC_J),   MT(MOD_RALT, KC_K),   KC_L,        KC_SCLN,    KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,          KC_C,         KC_V,              KC_B,     TD(LBRC_TD),                          TD(RBRC_TD),      KC_N,       KC_M,                    KC_COMMA,    KC_DOT,      KC_SLSH,    KC_NO,
        MO(_NUMPAD),   KC_LCTL,      KC_LALT,       TD(CMD_TD),  LT(_NAV,KC_SPC),  KC_LSFT,   KC_ENT,                              KC_ENT,            KC_BSPC,    MT(MOD_RSFT, KC_BSPC),   MT(MOD_RALT,KC_SPACE),     MO(_NAV),    KC_RCTL,      MO(_NUMPAD)
    ),
    [_PC] = LAYOUT_mamut_70(
        KC_ESC,        KC_1,         KC_2,          KC_3,         KC_4,              KC_5,      DF(_BASE),                           DF(_BASE),       KC_6,       KC_7,                    KC_8,        KC_9,        KC_0,       KC_DEL,
        KC_TAB,        KC_Q,         KC_W,          KC_E,         KC_R,              KC_T,       TD(SLSH_TD),                        TD(BSLS_TD),   KC_Y,                    KC_U,                     KC_I,         KC_O,       KC_P,       KC_EQL,
        KC_GRV,        KC_A,         KC_S,          MT(MOD_LALT, KC_D),         MT(MOD_LSFT, KC_F),              KC_G,     TD(MINS_TD),                          TD(QUOTE_TD),      KC_H,      MT(MOD_RSFT, KC_J),   MT(MOD_RALT, KC_K),   KC_L,        KC_SCLN,    KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,          KC_C,         KC_V,              KC_B,       TD(LBRC_TD),                        TD(RBRC_TD),   KC_N,                    KC_M,                     KC_COMMA,     KC_DOT,     KC_SLSH,    KC_NO,
        MO(_NUMPAD),   KC_LCTL,  KC_LALT,          LT(_PC_CTR,KC_SPC),     LT(_NAV,KC_SPC),  KC_LSFT,    LT(_NAV,_PC_CTR),                    KC_ENT,         KC_BSPC,                 MT(MOD_RSFT, KC_BSPC),   MT(MOD_RALT,KC_SPACE),       MO(_NAV),   KC_RCTL,      MO(_NUMPAD)
    ),
    [_PC_CTR] = LAYOUT_mamut_70(
         KC_ESC,        KC_1,         KC_2,          KC_3,         KC_4,              KC_5,      DF(_BASE),                              DF(_PC_CTR),      KC_6,       KC_7,                    KC_8,        KC_9,        KC_0,       KC_DEL,
        KC_TAB,     C(KC_Q),      KC_W,          KC_E,         C(KC_R),              C(KC_T),       C(KC_SLASH),                        TD(BSLS_TD),   KC_Y,                    KC_U,                     KC_I,         KC_O,       G(KC_P),       KC_EQL,
        KC_GRV,     C(KC_A),      C(KC_S),       KC_D,         C(KC_F),              KC_G,       TD(MINS_TD),                        TD(QUOTE_TD),   KC_H,                    KC_J,                     KC_K,         KC_L,       KC_SCLN,    KC_ENT,
        KC_LSFT,      C(KC_Z),      C(KC_X),       C(KC_C),      C(KC_V),              KC_B,       TD(LBRC_TD),                        TD(RBRC_TD),   KC_N,                    KC_M,                     KC_COMMA,     KC_DOT,     KC_SLSH,    KC_NO,
        MO(_NUMPAD),   KC_LCTL,  KC_LALT,    KC_LCTL,   LT(_NAV,KC_SPC),   KC_LSFT,    KC_LGUI,                             KC_ENT,         KC_BSPC,                 MT(MOD_RSFT, KC_BSPC),     MT(KC_RALT,KC_SPACE),      MO(_NAV),   KC_RCTL,      MO(_NUMPAD)
    ),
    [_NUMPAD] = LAYOUT_mamut_70(
        TO(_BASE),  KC_1,        KC_2,      KC_3,           KC_4,       KC_5,      _______,       _______,       KC_6,         KC_7,        KC_8,        KC_9,      KC_0,            KC_EQL,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      KC_4,        KC_5,        KC_6,      KC_KP_ASTERISK,  KC_MINS,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      KC_1,        KC_2,        KC_3,      KC_MINS,         _______,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      KC_0,        _______,     _______,   KC_PLUS,         _______,
        _______,    _______,     _______,    _______,        _______,    _______,   _______,       _______,       _______,      _______,     _______,     _______,   _______,         _______
    ),
    [_NAV] = LAYOUT_mamut_70(
        TO(_BASE),     KC_F1,      KC_F2,    KC_F3,          KC_F4,                       KC_F5,     KC_GRV,        KC_DEL,        KC_F6,       KC_F7,       KC_F8,        KC_F9,      KC_F10,        KC_WH_U,
        _______,    _______,     _______,    KC_PAGE_UP,     _______,                     _______,   _______,       _______,       _______,     KC_HOME,     KC_UP,        KC_END,     _______,       KC_WH_D,
        _______,    _______,     KC_HOME,    KC_PAGE_DOWN,   KC_END,                      _______,   _______,       _______,       _______,     KC_LEFT,     KC_DOWN,      KC_RIGHT,   _______,       _______,
        _______,    _______,     _______,    _______,        _______,                     _______,   _______,       _______,       _______,     _______,     _______,      _______,    _______,       _______,
        _______,    _______,     _______,    _______,        _______,                     _______,   _______,       _______,       _______,     _______,     _______,      _______,    _______,       _______
    ),
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    if (layer_state_is(_PC_CTR)) {
        if (record->event.pressed
            && keycode != KC_LCTL && keycode != C(KC_C) && keycode != C(KC_V) && keycode != C(KC_X)
            && keycode != C(KC_F) && keycode != C(KC_Q) && keycode != C(KC_A) && keycode != C(KC_Z)
            && keycode != C(KC_T) && keycode != C(KC_R) && keycode != C(KC_S) && keycode != C(KC_SLASH)) {
              if (!(mod_state & MOD_MASK_GUI)) {
                 register_mods(MOD_MASK_GUI);
              }
        } else if(record->event.pressed){
            unregister_mods(MOD_MASK_GUI);
        }
    }
    return true; // Process all other keycodes normally
}

void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(0,200,0);
}
uint8_t previous_layer = _BASE;

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(state);
    if (current_layer != _PC_CTR && previous_layer == _PC_CTR)
    {
         unregister_mods(MOD_MASK_GUI);
    }

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
            )
        {
            register_code16(KC_SPACE);
        }
        else {
            if (current_os == MAC){
                register_code16(KC_LGUI);
            } else {
                register_mods(MOD_LGUI);//maybe add_mods
                layer_on(_PC_CTR);
            }
        }
        break;
        case DOUBLE_TAP:
            register_code16(KC_SPACE);
            register_code16(KC_SPACE);
        break;
        case SINGLE_HOLD:
        if (current_os == MAC){
            register_code16(KC_LGUI);
        } else {
            register_mods(MOD_LGUI);
            layer_on(_PC_CTR);
        }
        break;
        case MORE_TAPS:
          if (current_os == MAC){
            register_code16(LGUI(KC_SPACE));
          }else {
            register_code16(KC_LGUI);
          }
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
            if (current_os == MAC) {
                unregister_code16(KC_LGUI);
            } else {
                unregister_mods(MOD_LGUI);
                layer_off(_PC_CTR);
            }
        }
        break;
        case DOUBLE_TAP:
            unregister_code16(KC_SPACE);
            unregister_code16(KC_SPACE);
        break;
        case SINGLE_HOLD:
        if (current_os == MAC){
            unregister_code16(KC_LGUI);
        } else {
            unregister_mods(MOD_LGUI);
            layer_off(_PC_CTR);
        }
        break;
        case MORE_TAPS:
          if (current_os == MAC){
            unregister_code16(LGUI(KC_SPACE));
          }else {
            unregister_code16(KC_LGUI);
          }
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

