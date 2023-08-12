// lain
// Copyright 2022 Takuya Urakawa @hsgw (dm9records.com, 5z6p.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// 変換テーブル（シフト後の値） key : jp_pc : us_pc
const uint16_t auto_shift_map_cnt = 18;
uint16_t auto_shift_map[18][3] = {
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
    ,{QK_USER_16, JP_COLN, S(KC_SCLN)} // ; :
    ,{QK_USER_17, JP_COLN, S(KC_SCLN)} // ; :
    ,{QK_USER_18, JP_SCLN, KC_SCLN} // ; ;
};

// 変換テーブル（シフト前の値） key : jp_pc : us_pc
const uint16_t conv_jis_map_cnt = 18;
uint16_t conv_jis_map[18][3] = {
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
    ,{QK_USER_16, JP_SCLN, KC_SCLN} // ; :
    ,{QK_USER_17, KC_DOT, KC_DOT} // ; :
    ,{QK_USER_18, JP_COLN, S(KC_SCLN)} // : :
};

enum layers { BASE, NUM, FUNC, CONF };
enum custom_keycodes { LED_EN = SAFE_RANGE };
const uint8_t current_layout = 1;
// clang-format off
#define MO_N MO(NUM)
#define MO_F MO(FUNC)
#define DK_L C(KC_LEFT)
#define DK_R C(KC_RGHT)
// #define TL_L LT(NUM, KC_SPC)
// #define TL_R LT(FUNC,KC_BSPC)
#define TL_LA MT(MOD_LALT,KC_LNG2)
#define TL_RC MT(MOD_RCTL,KC_LNG1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_LBRC,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,      QK_USER_7,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_RBRC,   KC_H,   KC_J,    KC_K,    KC_L,    QK_USER_18,KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_SLSH,KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_RSFT,
        KC_ESC,                    XXXXXXX, TL_LA,   MO_N,    KC_SPC,    KC_BSPC,MO_F,    TL_RC,   XXXXXXX, XXXXXXX,   KC_DEL
    ),
    [NUM] = LAYOUT(
        KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     _______,QK_USER_12, KC_F10,  KC_UP,   QK_USER_8,QK_USER_9,_______,
        _______, KC_6,    KC_7,    KC_8,    KC_9,   QK_USER_6,_______,QK_USER_10, KC_LEFT, KC_DOWN, KC_RIGHT,_______,   _______,
        _______, _______, _______, DK_L,    DK_R,   QK_USER_17,          _______, _______, _______, _______, _______,   _______,
        _______,                   _______, _______, _______, _______,   _______, _______, _______, _______, _______,   _______
    ),
    [FUNC] = LAYOUT(
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,   _______, _______, _______, _______, _______, _______,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_F11,  KC_F12,             _______, _______, _______, _______, _______, _______,
        _______,                   _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
    ),
    [CONF] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        LED_EN,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LED_EN:
            if (record->event.pressed) {
                lain_enable_leds_toggle();
            }
            return false;
        default:
            break;
    }
    return true;
}

// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t computed = update_tri_layer_state(state, NUM, FUNC, CONF);
    switch (get_highest_layer(computed)) {
        case NUM:
            lain_set_led(1, 1);
            lain_set_led(2, 0);
            break;
        case FUNC:
            lain_set_led(1, 0);
            lain_set_led(2, 1);
            break;
        case CONF:
            lain_set_led(1, 1);
            lain_set_led(2, 1);
            break;
        default:
            lain_set_led(1, 0);
            lain_set_led(2, 0);
            break;
    }
    return computed;
}

bool led_update_user(led_t led_state) {
    lain_set_led(0, led_state.caps_lock);
    return false;
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
