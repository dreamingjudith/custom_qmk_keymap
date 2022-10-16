/* Copyright 2022 Judith Jeong
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(KC_LCTL, KC_C, KC_V),

};

/* Lighting Layers */

// Light LED 1 (Stack Overflow logo key) to white
const rgblight_segment_t PROGMEM key_indicator_logo[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_OFF},
    {1, 1, HSV_WHITE},
    {2, 3, HSV_OFF}
);
// Light LED 2 (C key) to white
const rgblight_segment_t PROGMEM key_indicator_c[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_OFF},
    {2, 1, HSV_WHITE},
    {3, 2, HSV_OFF}
);
// Light LED 3 (V key) to white
const rgblight_segment_t PROGMEM key_indicator_v[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_OFF},
    {3, 1, HSV_WHITE},
    {4, 1, HSV_OFF}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    key_indicator_logo,
    key_indicator_c,
    key_indicator_v
);

void keyboard_post_init_user(void) {
    /* RGB Settings */
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    rgblight_layers = rgb_layers;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
            if (record->event.pressed) {
                // Do something when pressed
                rgblight_unblink_all_but_layer(0);
                rgblight_blink_layer(0, 500);
            }
            return true; // Let QMK send the enter press/release events
        case KC_C:
            if (record->event.pressed) {
                // Do something when pressed
                rgblight_unblink_all_but_layer(1);
                rgblight_blink_layer(1, 500);
            }
            return true; // Let QMK send the enter press/release events
        case KC_V:
            if (record->event.pressed) {
                // Do something when pressed
                rgblight_unblink_all_but_layer(2);
                rgblight_blink_layer(2, 500);
            }
            return true; // Let QMK send the enter press/release events
        default:
            return true; // Process all other keycodes normally
    }
}
