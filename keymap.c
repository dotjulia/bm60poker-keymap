#include QMK_KEYBOARD_H
#include "raw_hid.h"

#define KEY_COUNT 61

/* FIRST ROW */
#define ESC_LED 0
#define N1_LED 1
#define N2_LED 2
#define N3_LED 3
#define N4_LED 4
#define N5_LED 5
#define N6_LED 6
#define N7_LED 7
#define N8_LED 8
#define N9_LED 9
#define N10_LED 10
#define N11_LED 11
#define N12_LED 12
#define BACKSPACE_LED 13

/* SECOND ROW */
#define TAB_LED 14
#define Q_LED 15
#define W_LED 16
#define E_LED 17
#define R_LED 18
#define T_LED 19
#define Y_LED 20
#define U_LED 21
#define I_LED 22
#define O_LED 23
#define P_LED 24
#define OPENING_SQUARE_BRACKET_LED 25
#define CLOSING_SQUARE_BRACKET_LED 26
#define BACKSLASH_LED 27

/* THIRD ROW */
#define CAPS_LED 28
#define A_LED 29
#define S_LED 30
#define D_LED 31
#define F_LED 32
#define G_LED 33
#define H_LED 34
#define J_LED 35
#define K_LED 36
#define L_LED 37
#define SEMICOLON_LED 38
#define QUOTE_LED 39
#define RETURN_LED 40

/* FOURTH ROW */
#define SHIFT_LED 41
#define Z_LED 42
#define X_LED 43
#define C_LED 44
#define V_LED 45
#define B_LED 46
#define N_LED 47
#define M_LED 48
#define COMMA__LED 49
#define DOT_LED 50
#define SLASH_LED 51
#define RSHIFT_LED 52

/* FIFTH ROW */
#define CTRL_LED 53
#define OS_LED 54
#define ALT_LED 55
#define SPACE_LED 56
#define FN_LED 57
#define RWIN_LED 58
#define RALT_LED 59
#define RCTRL_LED 60

#define LIGHT_LAYER_KEY(k, r, g, b) if(i == k) { rgb_matrix_set_color(k, r, g, b); continue; }

typedef struct {
  uint8_t red;
  uint8_t blue;
  uint8_t green;
} color;
color leds[KEY_COUNT];

bool modifierPressed = false;

void showRGB(void) {
    for(int i = 0; i < KEY_COUNT; i++) {
        /*
         * For performance reasons (because this function is called every matrix scan)
         * I'm not iterating over an array which includes all layer 2 keys and what color
         * they should light up. Instead I'm writing all these if statements. I know it's ugly
         */
        if(modifierPressed) {
            /* FIRST ROW */
            LIGHT_LAYER_KEY(ESC_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N1_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N2_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N3_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N4_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N5_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N6_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N7_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N8_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N9_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N10_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N11_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N12_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(BACKSPACE_LED, 255, 0, 0);

            /* SECOND ROW */
            LIGHT_LAYER_KEY(CAPS_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(OPENING_SQUARE_BRACKET_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(BACKSLASH_LED, 255, 0, 0);

            /* THIRD ROW */
            LIGHT_LAYER_KEY(A_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(S_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(D_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(SEMICOLON_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(QUOTE_LED, 255, 0, 0);

            /* FOURTH ROW */
            LIGHT_LAYER_KEY(B_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(N_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(M_LED, 255, 0, 0);
            LIGHT_LAYER_KEY(SLASH_LED, 255, 0, 0);
        } else {
            rgb_matrix_set_color(i, leds[i].red, leds[i].green, leds[i].blue);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MO(1):
            if(record->event.pressed) {
                modifierPressed = true;
            } else {
                modifierPressed = false;
            }
            return true;
            break;
        default:
            return true;
    }
    return true;
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
 * [0] mode
 */
void raw_hid_receive(uint8_t *data, uint8_t length) {
    if(data[0] == 0) { // Set all LEDs
        /*
         * [0] mode = 0
         * [1] red
         * [2] green
         * [3] blue
         */
        for(int i = 0; i<KEY_COUNT; i++) {
            leds[i].red = data[1];
            leds[i].green = data[2];
            leds[i].blue = data[3];
        }
    } else if(data[0] == 1) { // Set single LED
        /*
         * [0] mode = 1
         * [1] index
         * [2] red
         * [3] green
         * [4] blue
         */
        if(data[1] < KEY_COUNT) {
            leds[data[1]].red = data[2];
            leds[data[1]].green = data[3];
            leds[data[1]].blue = data[4];
        }
    }
}

void matrix_scan_user(void) {
    showRGB();
}