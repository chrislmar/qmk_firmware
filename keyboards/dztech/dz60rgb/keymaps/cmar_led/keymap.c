#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = LAYOUT_ANSI(
      KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,    KC_6,    KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,    KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,    KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP,
      KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
      ),
  [_LAYER1] = LAYOUT_ANSI(
      KC_ESC,  KC_F1,   TO(2),   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7, KC_F8, KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
      KC_NO,   KC_LALT, KC_UP,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,  KC_PSCR, KC_SLCK, KC_PAUS, RESET,
      KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,  KC_HOME, KC_PGUP, EEP_RST,
      KC_MRWD, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_END, KC_PGDN, KC_MFFD,
      KC_NO,   KC_NO,   KC_NO,   TO(2),   KC_TRNS, KC_NO,   KC_TRNS, KC_NO
      ),
  [_LAYER2] = LAYOUT_ANSI(
      KC_NO, KC_NO,   TO(0), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, RGB_TOG, KC_NO, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_SPI, RGB_SPD, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
      KC_NO, KC_NO,   KC_NO, TO(0),   KC_NO,   KC_TRNS, KC_NO,   KC_NO
      ),
  /*
  [_LAYER] = LAYOUT(
      13,      12,      11,       10,      9,       8,       7,       6,       5,       4,       3,       2,       1,       0,      \
      27,      26,      25,       24,      23,      22,      21,      20,      19,      18,      17,      16,      15,      14,     \
      40,      39,      38,       37,      36,      35,      34,      33,      32,      31,      30,      29,      28,              \
      53,      52,      51,       50,      49,      48,      47,      46,      45,      44,      43,               42,      41,     \
      62,      61,      60,                         59,                        58,      57,               56,      55,      54      \
   )
   */
};

void rgb_matrix_layer_helper(uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
      rgb_matrix_set_color( i, red, green, blue );
    }
  }
}

void rgb_matrix_indicators_user(void)
{
  // #F6BD9D
  // 22°, 36%, 96%
  //HSV orange_hsv = { 16, 186/*92*/, 100/*245*/ };
  HSV orange_hsv = { 50, 160, rgb_matrix_config.hsv.v };
  RGB orange = hsv_to_rgb(orange_hsv);

  // #FF808B
  // 355°, 50%, 100%
  //HSV pink_hsv = { 251, 50, rgb_matrix_config.hsv.v };
  HSV pink_hsv = { 20, 120, rgb_matrix_config.hsv.v };
  RGB pink = hsv_to_rgb(pink_hsv);

  // #CD6C8F
  // 338°, 47%, 80%
  HSV purple_hsv = { 239, 47, rgb_matrix_config.hsv.v };
  RGB purple = hsv_to_rgb(purple_hsv);

  // #34657F
  // 201°, 59%, 50%
  // HSV blue_hsv = { 142, 150, rgb_matrix_config.hsv.v };
  HSV blue_hsv = { 142, 170, rgb_matrix_config.hsv.v };
  RGB blue = hsv_to_rgb(blue_hsv);

  if (!g_suspend_state && rgb_matrix_config.enable) {
    // Backspace -> 7
    for (int i = 0; i <= 6; i++) {
      rgb_matrix_set_color(i, blue.r, blue.g, blue.b);
    }
    // Pipe -> Y
    for (int i = 14; i <= 21; i++) {
      rgb_matrix_set_color(i, blue.r, blue.g, blue.b);
    }
    // Enter -> G
    for (int i = 28; i <= 35; i++) {
      rgb_matrix_set_color(i, blue.r, blue.g, blue.b);
    }
    // RShift -> V
    for (int i = 41; i <= 49; i++) {
      rgb_matrix_set_color(i, blue.r, blue.g, blue.b);
    }
    // RCTL -> Space
    for (int i = 54; i <= 59; i++) {
      rgb_matrix_set_color(i, blue.r, blue.g, blue.b);
    }

    // 6, T, F, C
    rgb_matrix_set_color(7, purple.r, purple.g, purple.b);
    rgb_matrix_set_color(22, purple.r, purple.g, purple.b);
    rgb_matrix_set_color(36, purple.r, purple.g, purple.b);
    rgb_matrix_set_color(50, purple.r, purple.g, purple.b);

    // 4, 5
    rgb_matrix_set_color(8, pink.r, pink.g, pink.b);
    rgb_matrix_set_color(9, pink.r, pink.g, pink.b);
    // E, R
    rgb_matrix_set_color(23, pink.r, pink.g, pink.b);
    rgb_matrix_set_color(24, pink.r, pink.g, pink.b);
    // S, D
    rgb_matrix_set_color(37, pink.r, pink.g, pink.b);
    rgb_matrix_set_color(38, pink.r, pink.g, pink.b);
    // Z, X
    rgb_matrix_set_color(51, pink.r, pink.g, pink.b);
    rgb_matrix_set_color(52, pink.r, pink.g, pink.b);
    // LALT, WIN
    rgb_matrix_set_color(60, pink.r, pink.g, pink.b);
    rgb_matrix_set_color(61, pink.r, pink.g, pink.b);

    // 3 -> 1
    for (int i = 10; i <= 12; i++) {
      rgb_matrix_set_color(i, orange.r, orange.g, orange.b);
    }

    // ~ Gengar
    rgb_matrix_set_color(13, purple.r, purple.g, purple.b*2);

    // W, Q, Tab
    for (int i = 25; i <= 27; i++) {
      rgb_matrix_set_color(i, orange.r, orange.g, orange.b);
    }

    // A, Caps
    rgb_matrix_set_color(39, orange.r, orange.g, orange.b);
    rgb_matrix_set_color(40, orange.r, orange.g, orange.b);

    // LShift
    rgb_matrix_set_color(53, orange.r, orange.g, orange.b);

    // LCTL
    rgb_matrix_set_color(62, orange.r, orange.g, orange.b);

    switch (biton32(layer_state)) {
      case _LAYER0:
        break;
      case _LAYER1:
        // 1
        rgb_matrix_set_color(12, 0xFF, 0xFF, 0xFF);
        break;
      case _LAYER2:
        // 2
        rgb_matrix_set_color(11, 0xFF, 0xFF, 0xFF);
        break;
    }
  }

  //if (this_led & (1 << USB_LED_CAPS_LOCK)) {
  //  rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
  //}

  /*
  switch (biton32(layer_state)) {
    case _LAYER3:
      if (this_led & (1 << USB_LED_NUM_LOCK)) {
        rgb_matrix_set_color(13, 0xFF, 0x00, 0x00);
      } else {
        rgb_matrix_set_color(13, 0x00, 0x00, 0x00);
      }

      rgb_matrix_set_color(0, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(1, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(1, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(2, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(3, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(4, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(5, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(6, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(7, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(8, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(9, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(10, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(11, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(12, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(14, 0x00, 0x00, 0xFF);
      rgb_matrix_set_color(15, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(16, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(17, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(18, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(19, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(20, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(21, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(22, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(23, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(24, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(25, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(26, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(27, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(28, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(29, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(30, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(31, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(32, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(33, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(34, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(35, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(36, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(37, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(38, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(39, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(40, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(41, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(42, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(43, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(44, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(45, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(46, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(47, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(48, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(49, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(50, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(51, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(52, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(53, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(54, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(55, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(56, 0x00, 0x00, 0x00);
      rgb_matrix_set_color(57, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(58, 0x00, 0xFF, 0x00);
      rgb_matrix_set_color(59, 0xFF, 0x00, 0x00);
      rgb_matrix_set_color(60, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(61, 0xFF, 0xFF, 0x00);
      rgb_matrix_set_color(62, 0x00, 0x00, 0x00);
      break;
  }
  */
}

void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
  return true;
}
