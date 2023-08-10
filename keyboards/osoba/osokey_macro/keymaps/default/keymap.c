// osokey_macro
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_jp.h"


// 変換テーブル（シフト後の値） key : jp_pc : us_pc
const uint16_t auto_shift_map_cnt = 16;
uint16_t auto_shift_map[16][3] = {
     {QK_USER_1, JP_DQUO, S(KC_QUOT)} // 2 "
    ,{QK_USER_2, JP_AMPR, S(KC_7)} // 6 &
    ,{QK_USER_3, JP_QUOT, KC_QUOT} // 7 '
    ,{QK_USER_4, JP_LPRN, S(KC_9)} // 8 (
    ,{QK_USER_5, JP_RPRN, S(KC_0)} // 9 )
    ,{QK_USER_6, JP_UNDS, S(KC_MINS)} // 0 _
    ,{QK_USER_7, JP_EQL , KC_EQL} // - =
    ,{QK_USER_8, JP_TILD, S(KC_GRV)} // ^ ~
    ,{QK_USER_9, JP_PIPE, S(KC_BSLS)} // ¥ |
    ,{QK_USER_10, JP_GRV , KC_GRV} // @ `
    ,{QK_USER_11, JP_LCBR, S(KC_LBRC)} // [ {
    ,{QK_USER_12, JP_ASTR, S(KC_8)} // + *
    ,{QK_USER_13, JP_SLSH, KC_SLSH} // - /
    ,{QK_USER_14, JP_RCBR, S(KC_RBRC)} // ] }
    ,{QK_USER_15, JP_EQL, KC_EQL} // =
    ,{QK_USER_16, JP_SCLN, KC_SCLN} // ; :
};

// 変換テーブル（シフト前の値） key : jp_pc : us_pc
const uint16_t conv_jis_map_cnt = 16;
uint16_t conv_jis_map[16][3] = {
     {QK_USER_1, KC_2, KC_2} // 2
    ,{QK_USER_2, KC_6, KC_6} // 6
    ,{QK_USER_3, KC_7, KC_7} // 7
    ,{QK_USER_4, KC_8, KC_8} // 8
    ,{QK_USER_5, KC_9, KC_9} // 9
    ,{QK_USER_6, KC_0, KC_0} // 0
    ,{QK_USER_7, JP_MINS ,KC_MINS} // -
    ,{QK_USER_8, JP_CIRC, S(KC_6)} // ^
    ,{QK_USER_9, JP_YEN, KC_BSLS} // ¥
    ,{QK_USER_10, JP_AT , S(KC_2)} // @
    ,{QK_USER_11, JP_LBRC, KC_LBRC} // [
    ,{QK_USER_12, JP_PLUS, S(KC_EQL)} // +
    ,{QK_USER_13, JP_MINS, KC_MINS} // -
    ,{QK_USER_14, JP_RBRC, KC_RBRC} // ]
    ,{QK_USER_15, JP_EQL, KC_EQL} // =
    ,{QK_USER_16, JP_COLN, S(KC_SCLN)} // ; :
};

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  SP_TS,
};

static uint16_t exec_cnt = 0;
const uint8_t current_layout = 1;
static bool is_timer = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+
   JP_COLN, KC_PEQL, KC_PSLS, KC_PAST, SP_TS,
//+--------+--------+--------+--------+--------+--------+
   KC_TAB,  KC_P7,   KC_P8,   KC_P9,   KC_BSPC, LSG(KC_Z),
//+--------+--------+--------+--------+--------+--------+
   KC_LGUI, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, LGUI(KC_Z),
//+--------+--------+--------+--------+--------+--------+
   KC_LSFT, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, LGUI(KC_C),
//+--------+--------+--------+--------+--------+--------+
   KC_ESC,  _______, KC_P0,   KC_DOT,  KC_ENT,  LGUI(KC_V)
//+--------+--------+--------+--------+--------+--------+
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
  setPinOutput(GP11);
  writePinHigh(GP11);
  rgblight_sethsv_noeeprom(HSV_OFF);
}

uint16_t get_shifted_key(uint16_t keycode) {
    for (int i = 0; i < auto_shift_map_cnt; i++) {
        if (auto_shift_map[i][0] == keycode) return auto_shift_map[i][current_layout];
    }
    return XXXXXXX;
}

uint16_t get_conv_jis_key(uint16_t keycode) {
    for (int i = 0; i < conv_jis_map_cnt; i++) {
        if (conv_jis_map[i][0] == keycode) return conv_jis_map[i][current_layout];
    }
    return XXXXXXX;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t * record) {
    uint16_t shifted_keycode = get_shifted_key(keycode);
    if (shifted_keycode == XXXXXXX) {
        if (shifted) add_weak_mods(MOD_BIT(KC_LSFT));
        register_code16((IS_RETRO(keycode)) ? keycode & 0xFFFF : keycode);
    } else {
        /* =キーなどのjis変換対応 */
        uint16_t conv_keycode = get_conv_jis_key(keycode);
        conv_keycode = conv_keycode == XXXXXXX ? keycode : conv_keycode;
        register_code16((!shifted) ? conv_keycode : shifted_keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t * record) {
    uint16_t shifted_keycode = get_shifted_key(keycode);
    if (shifted_keycode == XXXXXXX) {
        unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFFFF : keycode);
    } else {
        /* =キーなどのjis変換対応 */
        uint16_t conv_keycode = get_conv_jis_key(keycode);
        conv_keycode = conv_keycode == XXXXXXX ? keycode : conv_keycode;
        unregister_code16((!shifted) ? conv_keycode : shifted_keycode);
    }
}

void jamming(void) {
    tap_code(KC_LEFT);
}

void matrix_scan_user(void) {
    if (is_timer) {
        exec_cnt++;
        if (exec_cnt > 10000) {
            jamming();
            exec_cnt = 0;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
        case SP_TS:
            if (record -> event.pressed) {
                is_timer = !is_timer;
                if (is_timer) {
                    rgblight_sethsv_noeeprom(HSV_CYAN);
                    exec_cnt = 0;
                } else {
                    rgblight_sethsv_noeeprom(HSV_OFF);
                }
            }
            return false;
        default:
            break;
    }
    return true;
}
