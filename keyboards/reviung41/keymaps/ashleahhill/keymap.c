/* Copyright 2020 gtips
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
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    LALT_T(KC_TAB),      KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_CAPS),     KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    KC_LCTL,   LOWER,    LT(_FN, KC_SPC),   RAISE,    KC_RALT
  ),

  [_LOWER] = LAYOUT_reviung41(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 	    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RAISE] = LAYOUT_reviung41(
    KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5, 	            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,
    KC_LGUI, KC_TRNS, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, 	KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,  KC_RGUI,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_END,  KC_PGDN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_ADJUST] = LAYOUT_reviung41(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_LGUI, KC_NO,   KC_NO,   KC_NO,   RGB_TOG, RGB_VAD, 	RGB_VAI, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RGUI,
    KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_M_P, 	RGB_M_B, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL,
    KC_TRNS, KC_TRNS,  KC_TRNS, KC_ENT,  KC_TRNS
  ),

  [_FN] = LAYOUT_reviung41(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_LGUI, KC_NO,   KC_NO,   KC_NO,   RGB_TOG, RGB_VAD, 	RGB_SAD, RGB_HUD, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_CTL,
    KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_M_P, 	RGB_M_B, RGB_M_K, RGB_M_R,   KC_NO,   KC_NO,   KC_RCTL,
    KC_TRNS, KC_TRNS,  KC_TRNS, KC_ENT,  KC_TRNS
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

