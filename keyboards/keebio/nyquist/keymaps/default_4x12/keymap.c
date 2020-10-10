#include QMK_KEYBOARD_H

enum layer_names {
    _DEFAULT,
    _RAISE,
    _LOWER,
    _FUNCTION,
    _ADJUST,
    _RESET,
    _NAVIGATION,
    _GUI,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define DESK_LEFT LCTL(LGUI(KC_LEFT))
#define DESK_RIGHT LCTL(LGUI(KC_RIGHT))
#define SPC_GUI LT(7, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | LAlt/Tab|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LCtrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ; |RCtrl / '|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   / |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Function|< Desk|Desk >|      |Lower| Space|Space |Raise|       | Vol-| Vol+| Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_ortho_4x12(
  LALT_T(KC_TAB),        KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  MO(3), DESK_LEFT, DESK_RIGHT, XXXXXXX, LOWER, SPC_GUI, SPC_GUI, RAISE, KC_LEFT, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE
),

[_RAISE] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, XXXXXXX, XXXXXXX, KC_INS,  KC_HOME, KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, KC_DEL,  KC_END,  KC_PGDN, KC_NO,   KC_NO,   KC_NO,   KC_NO,    XXXXXXX, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(4),   TG(6),   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LOWER] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RALT,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, GUI_ON, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, GUI_OFF, KC_NO,   KC_NO, KC_COMM, KC_DOT, KC_SLSH, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, TG(6), MO(4), _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_FUNCTION] = LAYOUT_ortho_4x12(
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CALTDEL,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, TO(4),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP
)

[_ADJUST] = LAYOUT_ortho_4x12(
  _______, _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, CALTDEL,
  _______, _______, XXXXXXX, XXXXXXX, GUI_ON,  GUI_OFF, TO(0),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, MO(5),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP
),

[_RESET] = LAYOUT_ortho_4x12(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_NAVIGATION] = LAYOUT_ortho_4x12(
  _______, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, DESK_LEFT, XXXXXXX, XXXXXXX, DESK_RIGHT, XXXXXXX, KC_RALT,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN2, KC_LEFT,   KC_DOWN, KC_UP,   KC_RIGHT,   XXXXXXX, KC_RCTL,
  KC_F1,    KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_GUI] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
