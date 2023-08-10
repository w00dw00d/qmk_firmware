// dz60

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    SP_LC,
};

#define DK_L C(KC_LEFT)
#define DK_R C(KC_RGHT)
static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,
        XXXXXXX, KC_LCTL, MT(MOD_LALT,KC_LNG2),LT(_LOWER,KC_SPC), KC_LNG2, KC_BSPC,           MT(MOD_RALT,KC_LNG1), KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_LOWER] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______, _______, _______, _______, DK_L,    DK_R,    _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, KC_LNG1, _______,           _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SP_LC:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if(timer_elapsed(key_timer) < 150) {
                    tap_code(KC_LNG2);
                } else {
                    tap_code(KC_LNG1);
                }
            }
            return false;
        default:
            break;
    }
    return true;
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    const uint16_t long_time = 20 + 100;

    if (keycode == KC_COMM || keycode == KC_DOT || keycode == KC_SLSH) {
            return get_generic_autoshift_timeout() + 50 + long_time;
    }

    switch(keycode) {
        case AUTO_SHIFT_ALPHA:
            return get_generic_autoshift_timeout() + long_time;
        case AUTO_SHIFT_NUMERIC:
        case AUTO_SHIFT_SPECIAL:
        default:
            return get_generic_autoshift_timeout();
    }
}

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_OFF);
}
