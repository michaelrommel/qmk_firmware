
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
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | HOME   | DEL    | PG UP  | Y      | U      | I      | O      | P      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTRL  | A      | S      | D      | F      | G      | [      | \      | ]      | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | FN     |        |        | LGUI   | LALT   | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | RALT   | RGUI   | LEAD   | TG(MAC)| RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_EN] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOT,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME, KC_DEL,  KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC, KC_BSLS, KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        MO(_FL), _______, _______, KC_LGUI, KC_LALT, KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_RALT, KC_RGUI, KC_LEAD, TG(_MAC),KC_RCTL
    ),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     |        | PRINT  | RESET  | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        | P7     | P8     | P9     |        |        | RGB MD | RGB VD | RGB VI | RGB TG |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        | LEFT   | P4     | P5     | P6     | DOWN   | UP     | RIGHT  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        | P1     | P2     | P3     | +      |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        | P0     |        | P.     | ENTER  |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FL] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_PSCR, RESET,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, RGB_MOD, RGB_VAD, RGB_VAI, RGB_TOG,
        _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_P0,   _______, KC_PDOT, KC_PENT, _______, _______, _______, _______, _______
    ),

    /* MAC
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        | LALT   | LGUI   |        |        |        |        |        | RGUI   | RALT   |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_MAC] = LAYOUT_ortho_5x15( /* FUNCTION */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, KC_RGUI, KC_RALT, _______, _______, _______
    )
};

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

