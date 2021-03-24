#include QMK_KEYBOARD_H
#include "raw_hid.h"

#define KEY_COUNT 61

typedef struct {
  uint8_t red;
  uint8_t blue;
  uint8_t green;
} color;
color leds[KEY_COUNT];

void showRGB(void) {
    for(int i = 0; i < KEY_COUNT; i++) {
        rgb_matrix_set_color(i, leds[i].red, leds[i].green, leds[i].blue);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              MO(1),   KC_RGUI,   KC_RALT,     KC_RCTL
    ),
    [1] = LAYOUT_60_ansi(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_CAPS,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, KC_UP, _______, RESET,
        _______,       KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RIGHT, _______,
        _______,            _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_DOWN, _______,
        _______,   _______,   _______,                      _______,                              _______,   _______,   _______,   _______
    ),

};

// Data:
// e r g b
/*
 * [0] r - red
 * [1] g - green
 * [2] b - blue
 */
void raw_hid_receive(uint8_t *data, uint8_t length) {
    for(int i = 0; i<KEY_COUNT; i++) {
      leds[i].red = data[0];
      leds[i].green = data[1];
      leds[i].blue = data[2];
    }
}

void matrix_scan_user(void) {
    showRGB();
}