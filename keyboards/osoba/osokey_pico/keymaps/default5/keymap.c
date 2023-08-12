// Copyright 2022 Yoichiro Tanaka (@yoichiro)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// osokeypico
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
};

#define TL_LA MT(MOD_LGUI,KC_LNG2)
#define TL_RC MT(MOD_RGUI,KC_LNG1)
#define TL_SRC LSFT_T(KC_SPC)
const uint8_t current_layout = 1;

#define TL_RA MT(MOD_LALT,KC_A)
#define TL_RQ MT(MOD_LGUI,KC_Q)
#define TL_RZ MT(MOD_LSFT,KC_Z)
#define TL_RS MT(MOD_RSFT,KC_SLSH)
//  QK_USER_16 QK_USER_7
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, TL_RA,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT, _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, TL_RZ,   KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  TL_RS, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   _______,                   KC_ESC, TL_LA, MO(_LOWER),KC_SPC,  KC_BSPC, MO(_RAISE),TL_RC,  KC_RCTL,                    _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),
  [_LOWER] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      QK_USER_12,_______,KC_UP,QK_USER_8,QK_USER_9,_______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, KC_6,    KC_7,    KC_8,    KC_9,    QK_USER_6,                QK_USER_10,KC_LEFT,KC_DOWN,KC_RGHT,QK_USER_16,_______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, QK_USER_11,QK_USER_14,KC_DOT,               KC_TAB, QK_USER_7, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   _______,                   _______, _______, _______, _______, _______, _______, _______, KC_DEL,                   _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),
  [_RAISE] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, KC_F11,  KC_F12,                    _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   _______,                   _______, _______, _______, _______, _______, _______, _______, _______,                   _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),
  [_ADJUST] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   _______,                   _______, _______, _______, _______, _______, _______, _______, _______,                   _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
  setPinOutput(GP11);
  writePinHigh(GP11);
  rgblight_sethsv_noeeprom(HSV_CYAN);
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
