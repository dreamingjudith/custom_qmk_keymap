/* Copyright 2021 matejsemancik
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

// There is a total of 20 LEDs on the board.
// The 4 Logo LEDs have indices 16, 17, 18, 19.
#define LED_MODE_LOGO 0
#define LED_MODE_UNDER 1
#define LED_MODE_ALL 2
#define LED_MODE_OFF 3

enum custom_keycodes {
    RGB_RNG = SAFE_RANGE  // Toggle between logo, backlight, both, off
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t led_mode : 8;
    };
} user_config_t;

void update_led_mode(void);
void persist_led_mode(void);

user_config_t user_config;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_RNG:
            if (record->event.pressed) {
                user_config.led_mode = (user_config.led_mode + 1) % 4;
                update_led_mode();
                persist_led_mode();
            }
            return false;
        default:
            return true;
    }
    return true;
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    update_led_mode();
}

void eeconfig_init_user(void) {
    user_config.raw      = 0;
    user_config.led_mode = LED_MODE_LOGO;
    eeconfig_update_user(user_config.raw);
    rgblight_enable();
}

void update_led_mode(void) {
    rgblight_setrgb(0, 0, 0);
    switch (user_config.led_mode) {
        case LED_MODE_LOGO:
            rgblight_set_effect_range(16, 4);
            rgblight_enable_noeeprom();
            break;
        case LED_MODE_UNDER:
            rgblight_set_effect_range(0, 16);
            rgblight_enable_noeeprom();
            break;
        case LED_MODE_ALL:
            rgblight_set_effect_range(0, RGBLED_NUM);
            rgblight_enable_noeeprom();
            break;
        default:
            rgblight_disable_noeeprom();
    }
}

void persist_led_mode(void) { eeconfig_update_user(user_config.raw); }

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_68_ansi_split_rshift(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL, KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,    KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_68_ansi_split_rshift(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,    _______, QK_BOOT,
        _______, RGB_RNG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
        _______, _______, _______,                            _______,                            _______, _______, _______,    _______, _______, _______
    ),
    [2] = LAYOUT_68_ansi_split_rshift(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
        _______, _______, _______,                            _______,                            _______, _______, _______,    _______, _______, _______
    ),
    [3] = LAYOUT_68_ansi_split_rshift(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
        _______, _______, _______,                            _______,                            _______, _______, _______,    _______, _______, _______
    ),
};

// clang-format on
