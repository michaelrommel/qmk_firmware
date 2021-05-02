#include QMK_KEYBOARD_H

// unicode character maps
enum unicode_names {
  AUML,
  CAPAUML,
  UUML,
  CAPUUML,
  OUML,
  CAPOUML,
  ESZETT
};

const uint32_t PROGMEM unicode_map[] = {
  [AUML] = 0x00E4,
  [CAPAUML] = 0x00C4,
  [UUML] = 0x00FC,
  [CAPUUML] = 0x00DC,
  [OUML] = 0x00F6,
  [CAPOUML] = 0x00D6,
  [ESZETT] = 0x00DF
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _EN,
  _FL,
  _MAC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* ANSI with split Backspace and Split Right Shift
   * ,---------------------------------------------------------------------------.
   * | 00| 01|| 02| 03| 04| 05|| 06| 07| 08| 09|| 0a| 0b| 0c| 0d||   | 0e| 0f| 0g|
   * |===========================================================================|
   * | 10| 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c| 1d| 3e|   | 1e| 1f| 1g|
   * |---------------------------------------------------------------------------|
   * | 20  | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2c|  2d |   | 2e| 2f| 2g|
   * |---------------------------------------------------------------------------|
   * | 30   | 31| 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|    3d  |   |   |   |   |
   * |---------------------------------------------------------------------------|
   * | 40     | 42| 43| 44| 45| 46| 47| 48| 49| 4a| 4b|   4c | 4d|   | 4e| 4f| 4g|
   * |---------------------------------------------------------------------------|
   * | 50 | 51 | 52 |       55          58    | 5a | 5b | 5c | 5d|   | 5e| 5f| 5g|
   * `---------------------------------------------------------------------------'
   */
  [_EN] = LAYOUT_all(\
    KC_P1,   KC_P2,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,            KC_F10,           KC_F11,  KC_F12,          _______, _______, _______, \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             KC_MINS,          KC_EQL,  KC_BSLS, KC_GRV, KC_INS,  KC_HOME, KC_PGUP, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,             KC_LBRC,          KC_RBRC, KC_BSPC,         KC_DEL,  KC_END,  KC_PGDN, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,          KC_QUOT,          _______, KC_ENT, \
    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_SLSH,          KC_RSFT, TG(_MAC),        KC_P3,   KC_UP,   KC_P4, \
    MO(_FL), KC_LGUI, KC_LALT,                   KC_SPC,                    KC_SPC,           KC_RALT,          KC_RGUI,          KC_LEAD, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT  ),

  /* Keymap _FL: Function Layer */
  [_FL] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,           _______, _______,          _______, _______, KC_POWER, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_F11,            KC_F12,  KC_PSCR, RESET,   _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_INS , KC_HOME, KC_PGUP, RGB_MOD,         RGB_VAD,           RGB_VAI, RGB_TOG,          _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,         _______,           _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_DEL , KC_END , KC_PGDN, _______,         _______,           _______, _______,          _______, _______, _______, \
    _______, _______, _______,                   _______,                   _______,          _______,         _______,           _______, _______,          _______, _______, _______
  ),

  /* Keymap _MAC: Mac specific keys */
  [_MAC] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______,          _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______,          _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______,          _______, _______, _______, \
    _______, KC_LALT, KC_LGUI,                   _______,                   _______,          KC_RGUI,          KC_RALT,          _______, _______,          _______, _______, _______
  )
};

void keyboard_post_init_user(void) {
  // Set the LEDs, which are available for effects
  rgblight_set_effect_range(7, 7);
  // reset middle bottom leds
  rgblight_sethsv_at(0, 255, 0, 1);
  rgblight_sethsv_at(0, 255, 0, 2);
  rgblight_sethsv_at(0, 255, 0, 3);
  rgblight_sethsv_at(0, 255, 0, 4);
  // Customise these values to desired behaviour
  debug_enable = true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  if (layer_state_cmp(state, _FL)) {
    rgblight_sethsv_at(0, 255, 160, 5);
  } else {
    rgblight_sethsv_at(0, 255, 0, 5);
  };
  if (layer_state_cmp(state, _MAC)) {
    set_unicode_input_mode(UC_MAC);
    rgblight_sethsv_at(64, 255, 160, 0);
  } else {
    set_unicode_input_mode(UC_WIN);
    rgblight_sethsv_at(64, 255, 0, 0);
  };
  return state;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // single keys with SHIFT before
    SEQ_ONE_KEY(KC_A) {
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_hex_string("00C4");
      } else {
        send_unicode_hex_string("00E4");
      }
    }
    SEQ_ONE_KEY(KC_U) {
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_hex_string("00DC");
      } else {
        send_unicode_hex_string("00FC");
      }
    }
    SEQ_ONE_KEY(KC_O) {
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_hex_string("00D6");
      } else {
        send_unicode_hex_string("00F6");
      }
    }
    SEQ_ONE_KEY(KC_S) {
      send_unicode_hex_string("00DF");
    }

    // Shifted keys
    SEQ_TWO_KEYS(KC_RSFT, KC_A) {
      send_unicode_hex_string("00C4");
    }
    SEQ_TWO_KEYS(KC_LSFT, KC_U) {
      send_unicode_hex_string("00DC");
    }
    SEQ_TWO_KEYS(KC_LSFT, KC_O) {
      send_unicode_hex_string("00D6");
    }

    // Double the same key
    SEQ_TWO_KEYS(KC_A, KC_A) {
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_hex_string("00C4");
      } else {
        send_unicode_hex_string("00E4");
      }
    }
    SEQ_TWO_KEYS(KC_U, KC_U) {
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_hex_string("00DC");
      } else {
        send_unicode_hex_string("00FC");
      }
    }
    SEQ_TWO_KEYS(KC_O, KC_O) {
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_hex_string("00D6");
      } else {
        send_unicode_hex_string("00F6");
      }
    }
    SEQ_TWO_KEYS(KC_S, KC_S) {
      send_unicode_hex_string("00DF");
    }
  }
}

