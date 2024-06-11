#include QMK_KEYBOARD_H

#define KC_MAC_UNDO LCTL(KC_Z)
#define KC_MAC_CUT LCTL(KC_X)
#define KC_MAC_COPY LCTL(KC_C)
#define KC_MAC_PASTE LCTL(KC_V)
#define KC_LCAG LCAG(KC_NO)

enum custom_keycodes {
  KC_COMMA_LBRACE = SAFE_RANGE,
  KC_DOT_RBRACE,
  KC_LBRACKET_RBRACKET,
  KC_LANGLEBR_RANGLEBR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESCAPE,        KC_1,          KC_2,          KC_3,         KC_4,            KC_5,           KC_6,                                             KC_7,                  KC_8,          KC_9,            KC_0,             KC_MINUS,        KC_EQUAL,           KC_BSPC,
    KC_TAB,           KC_Q,          KC_W,          KC_E,         KC_R,            KC_T,           KC_DOT,                                           KC_DOT,                KC_Y,          KC_U,            KC_I,             KC_O,            KC_P,               KC_BSLS,
    KC_LEFT_SHIFT,    LCTL_T(KC_A),  LGUI_T(KC_S),  LALT_T(KC_D), LSFT_T(KC_F),    LCAG_T(KC_G),   KC_DOT,                                           KC_BSLS,               LCAG_T(KC_H),  LSFT_T(KC_J),    LALT_T(KC_K),     LGUI_T(KC_L),    LCTL_T(KC_SCLN),    LT(2,KC_QUOTE),
    KC_LEFT_CTRL,     KC_Z,          KC_X,          KC_C,         KC_V,            KC_B,           KC_LEFT_BRACKET,                                  KC_RIGHT_BRACKET,      KC_N,          KC_M,            KC_COMMA_LBRACE,  KC_DOT_RBRACE,   RALT_T(KC_SLASH),   RALT_T(KC_LANGLEBR_RANGLEBR),
                                                                  LT(2,KC_SPACE),  LT(3,KC_ENTER), KC_DELETE,                                        KC_BSPC,               LT(3,KC_ENTER),  LT(1,KC_SPACE)
  ),

  [1] = LAYOUT(
    KC_GRAVE,         KC_F1,         KC_F2,         KC_F3,        KC_F4,           KC_F5,          KC_F6,                                            KC_NO,                 KC_NO,         KC_NO,           KC_NO,            KC_NO,           KC_NO,              KC_NO,
    KC_NO,            KC_NO,         KC_MS_BTN2,    KC_MS_UP,     KC_MS_BTN1,      KC_MS_WH_UP,    KC_NO,                                            QK_BOOTLOADER,         KC_MAC_CUT,    KC_MS_BTN1,      KC_NO,            KC_MS_BTN2,      KC_NO,              KC_NO,
    KC_LEFT_SHIFT,    KC_PGUP,       KC_MS_LEFT,    KC_MS_DOWN,   KC_MS_RIGHT,     KC_MS_WH_DOWN,  KC_NO,                                            QK_CLEAR_EEPROM,       KC_MAC_COPY,   KC_LSFT,         KC_LALT,          KC_LGUI,         KC_LCTL,            KC_NO,
    KC_LEFT_CTRL,     KC_PGDN,       KC_MAC_CUT,    KC_MAC_COPY,  KC_MAC_PASTE,    KC_NO,          KC_NO,                                            KC_NO,                 KC_MAC_PASTE,  KC_NO,           KC_NO,            KC_NO,           KC_NO,              KC_NO,
                                                                  KC_MS_BTN1,      KC_MS_BTN2,     KC_AUDIO_VOL_DOWN,                                KC_AUDIO_VOL_UP,       QK_BOOTLOADER, KC_NO
  ),

  [2] = LAYOUT(
    QK_BOOTLOADER,    KC_NO,         KC_NO,         KC_NO,        KC_NO,           KC_NO,          KC_NO,                                            KC_F7,                 KC_F8,         KC_F9,           KC_F10,           KC_F11,          KC_F12,             KC_BSPC,
    KC_NO,            KC_NO,         KC_NO,         KC_NO,        KC_NO,           KC_NO,          KC_NO,                                            QK_BOOTLOADER,         KC_MAC_CUT,    LALT(KC_LEFT),   KC_UP,            LALT(KC_RIGHT),  KC_NO,              KC_NO,
    KC_LEFT_SHIFT,    KC_LCTL,       KC_LGUI,       KC_LALT,      KC_LSFT,         KC_LCAG,        KC_NO,                                            QK_CLEAR_EEPROM,       KC_MAC_COPY,   KC_LEFT,         KC_DOWN,          KC_RIGHT,        KC_PGUP,            KC_NO,
    KC_LEFT_CTRL,     LCA_T(KC_TAB), KC_MAC_CUT,    KC_MAC_COPY,  KC_MAC_PASTE,    KC_NO,          KC_NO,                                            KC_NO,                 KC_MAC_PASTE,  LGUI(KC_LEFT),   KC_NO,            LGUI(KC_RIGHT),  KC_PGDN,            KC_NO,
                                                                  KC_NO,           QK_BOOTLOADER,  KC_AUDIO_VOL_DOWN,                                KC_AUDIO_VOL_UP,       KC_NO,         KC_NO
  ),

  [3] = LAYOUT(
    QK_BOOTLOADER,    KC_NO,         KC_NO,         KC_NO,        KC_NO,           KC_NO,          KC_NO,                                            KC_F7,                 KC_F8,         KC_NUM_LOCK,     KC_KP_SLASH,      KC_KP_ASTERISK,  KC_KP_MINUS,             KC_BSPC,
    KC_NO,            KC_NO,         KC_NO,         KC_NO,        KC_NO,           KC_NO,          KC_NO,                                            QK_BOOTLOADER,         KC_MAC_CUT,    KC_KP_7,         KC_KP_8,          KC_KP_9,         KC_KP_PLUS,              KC_NO,
    KC_LEFT_SHIFT,    KC_LCTL,       KC_LGUI,       KC_LALT,      KC_LSFT,         KC_LCAG,        KC_NO,                                            QK_CLEAR_EEPROM,       KC_MAC_COPY,   KC_KP_4,         KC_KP_5,          KC_KP_6,         KC_KP_PLUS,            KC_NO,
    KC_LEFT_CTRL,     KC_NO,         KC_MAC_CUT,    KC_MAC_COPY,  KC_MAC_PASTE,    KC_NO,          KC_NO,                                            KC_NO,                 KC_KP_0,       KC_KP_1,         KC_KP_2,          KC_KP_3,         KC_KP_ENTER,            KC_NO,
                                                                  KC_NO,           QK_BOOTLOADER,  KC_AUDIO_VOL_DOWN,                                KC_AUDIO_VOL_UP,       KC_NO,         KC_NO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_COMMA_LBRACE:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT)) {
          register_code(KC_LBRC);
        } else {
          register_code(KC_COMMA);
        }
      } else {
        unregister_code(KC_LBRC);
        unregister_code(KC_COMMA);
      }
      return false;
    case KC_DOT_RBRACE:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT)) {
          register_code(KC_RBRC);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_RBRC);
        unregister_code(KC_DOT);
      }
      return false;
    case KC_LBRACKET_RBRACKET: {
      static bool we_unshifted = false;
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT)) {
          we_unshifted = true;
          unregister_code(KC_LSFT);
          register_code(KC_RBRC);
        } else {
          register_code(KC_LBRC);
        }
      } else {
        if (we_unshifted) {
          we_unshifted = false;
          register_code(KC_LSFT);
        }
        unregister_code(KC_RBRC);
        unregister_code(KC_LBRC);
      }
      return false;
    }
    case KC_LANGLEBR_RANGLEBR: {
      static bool we_shifted = false;
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT)) {
          register_code(KC_DOT);
        } else {
          we_shifted = true;
          register_code(KC_LSFT);
          register_code(KC_COMMA);
        }
      } else {
        if (we_shifted) {
          we_shifted = false;
          unregister_code(KC_LSFT);
        }
        unregister_code(KC_DOT);
        unregister_code(KC_COMMA);
      }
      return false;
    }
  }
  return true;
}
