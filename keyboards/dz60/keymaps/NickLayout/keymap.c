#include QMK_KEYBOARD_H

enum custom_keycodes {
  CTL_LEFT = SAFE_RANGE,
  CTL_DOWN,
  CTL_UP,
  CTL_RIGHT
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if(record->event.pressed) {
    switch (keycode) {
      case CTL_LEFT:
        register_code(KC_LCTL);
        register_code(KC_LEFT);
        unregister_code(KC_LEFT);
        unregister_code(KC_LCTL);
        break;
      case CTL_DOWN:
        register_code(KC_LCTL);
        register_code(KC_DOWN);
        unregister_code(KC_DOWN);
        unregister_code(KC_LCTL);
        break;
      case CTL_UP:
        register_code(KC_LCTL);
        register_code(KC_UP);
        unregister_code(KC_UP);
        unregister_code(KC_LCTL);
        break;
      case CTL_RIGHT:
        register_code(KC_LCTL);
        register_code(KC_RIGHT);
        unregister_code(KC_RIGHT);
        unregister_code(KC_LCTL);
        break;
    }
  }
  return true;
};

enum keyboard_layers {
  _BL = 0, // Base Layer
  _FL,     // Function Layer
  _VI      // Control Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 
   * ,-----------------------------------------------------------.
   * |Esc|1 !|2 "|3 £|4 $|5 %|6 ^|7 &|8 *|9 (|0 )|- _|= +|bck|bck|
   * |-----------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P |[ {|] }|Enter|
   * |------------------------------------------------------.    |
   * | Fn1  | A | S | D | F | G | H | J | K | L |; :|' @|# ~|    |
   * |-----------------------------------------------------------|
   * |Sft |  || Z | X | C | V | B | N | M |, <|. >|/ ?|sft |x |c |
   * |-----------------------------------------------------------|
   * |Ctrl |GUI|Alt  |         Space          |FN |GUI|ctrl|v |f |
   * `-----------------------------------------------------------'
   */

//    LAYOUT_all(
////QWERTY Base layer:
////  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
//    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                  KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//  ),

[_BL] = LAYOUT_all(
//QWERTY Base layer:
//  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLASH,
    MO(2)  , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,KC_RSFT, KC_UP,    KC_DEL,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO,            KC_SPC,                    KC_NO,            TO(1),   KC_RGUI, KC_LEFT, KC_DOWN,  KC_RIGHT
  ),
[_FL] = LAYOUT_all(
//QWERTY Funtion layer for toggle:
//  1        2        3        4        5        6        7        8        9        10       11       12       13       14       15
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                   KC_TRNS,          TO(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
[_VI] = LAYOUT_all(
//QWERTY VIM ARROWS:
//  1        2        3        4        5        6        7          8          9          10          11       12       13       14       15
    KC_GRV,  KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,
    KC_CAPS, RGB_TOG, RGB_MOD,KC_NO,   KC_NO,    KC_NO,   CTL_LEFT,  CTL_DOWN,  CTL_UP,    CTL_RIGHT,  KC_NO,   KC_NO,   KC_NO,   RESET,
    KC_TRNS, KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,   KC_NO,   KC_NO,   KC_NO,
    KC_LSFT, KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_TRNS,   KC_HOME,   KC_PGDN,   KC_PGUP,    KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LCTL, KC_LGUI, KC_NO,  KC_NO,             KC_NO,                         KC_TRNS,               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
};

const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_WHITE}
);

const rgblight_segment_t PROGMEM my_layer1_function[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer2_vi[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_layer2_caps[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_base_layer,
    my_layer1_function,
    my_layer2_vi
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_enable_noeeprom();
    layer_state_set_user(_BL);
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(_BL, layer_state_cmp(state, _BL));
    rgblight_set_layer_state(_FL, layer_state_cmp(state, _FL));
    rgblight_set_layer_state(_VI, layer_state_cmp(state, _VI));
    rgblight_set();
  return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(3, led_state.caps_lock);
    return true;
}