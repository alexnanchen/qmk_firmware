#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

#define ______________ KC_TRANSPARENT

#define BASE     0

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  E_AIGU,
  E_GRV,
  E_TREM,
  E_HAT,
  A_GRV,
  A_HAT,
  O_HAT,
  I_HAT,
  U_GRV,
  D_PRN,
  D_BRC,
  D_BRK,
  D_PRN_B,
  D_BRC_B,
  D_BRK_B,
  D_QUOT_B,
  D_SQUOT_B,
  D_BASH,
  C_POINTER,
  C_END_FCT,
  PY_END_FCT,
  D_ASTERIX,
  D_CHEVRON,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_AUDIO_VOL_DOWN,                              KC_AUDIO_VOL_UP,  KC_6,           KC_7,           KC_8,             KC_9,           KC_0,           KC_DELETE,
    ______________,    KC_Q,           KC_W,           KC_F,           LT(7,KC_P),     KC_B,           TG(6),                                          ______________,   KC_J,           KC_L,           KC_U,             KC_Y,           KC_SCOLON,      KC_BSLASH,
    KC_LCTRL,          LT(4,KC_A),     LT(3,KC_R),     LT(1,KC_S),     LSFT_T(KC_T),   LT(5,KC_G),                                                                       KC_M,           LSFT_T(KC_N),   LT(1,KC_E),       LT(2,KC_I),     KC_O,           KC_QUOTE,
    KC_LSHIFT,         KC_Z,           KC_X,           LCTL_T(KC_C),   LALT_T(KC_D),   KC_V,           KC_LGUI,                                         KC_LGUI,         KC_K,           LCTL_T(KC_H),   LALT_T(KC_COMMA), KC_DOT,         KC_SLASH,       KC_RSHIFT,
    ______________,    KC_LCTRL,    ______________,    KC_LEFT,        KC_RIGHT,                                                                                                         KC_UP,          KC_DOWN,          KC_LBRACKET,    KC_RBRACKET,    KC_LCTRL,
                                                                                                    LCTL(KC_Y),     LALT(LCTL(KC_DELETE)),   ______________,    LCTL(KC_V),
                                                                                                                    LGUI(KC_L),               KC_PGUP,
                                                                                    KC_SPACE,       KC_TAB,         ______________,           KC_PGDOWN,        KC_ENTER,     KC_BSPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    ______________, KC_F1,          KC_F2,          KC_F3,          KC_F4,            KC_F5,          KC_F6,                                          KC_F7       ,    KC_F8      , KC_F9         , KC_F10        , KC_F11        , KC_F12        , ______________,
    ______________, ______________, ______________, ______________, ______________,   D_BRC_B     , ______________,                                 ______________, ______________, KC_KP_PLUS   , KC_EQUAL      , KC_KP_ASTERISK, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,   D_PRN_B     ,                                                                 ______________, KC_KP_MINUS   , ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,   D_BRK_B     , ______________,                                 ______________, ______________, KC_SLASH      , ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  ),
  [2] = LAYOUT_ergodox_pretty(
    RESET,          ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, KC_PIPE,        KC_UNDS,        KC_LCBR,        KC_RCBR,        KC_BSLASH,      ______________,                                 ______________, ______________, KC_PC_CUT,      ______________, ______________, ______________, ______________,
    ______________, KC_QUOTE,       KC_DQUO,        KC_LPRN,        KC_RPRN,        KC_COLN,                                                                        ______________, KC_PC_COPY,     ______________, ______________, ______________, ______________,
    ______________, KC_GRAVE,       KC_TILD,        KC_LBRACKET,    KC_RBRACKET,    KC_SCOLON,      ______________,                                 ______________, ______________, KC_PC_PASTE,    ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, KC_DLR,         KC_CIRC,                                                                                                        ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  ),
  [3] = LAYOUT_ergodox_pretty(
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, KC_PGUP,        KC_UP,          KC_PGDOWN,      ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________,                                                                 KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  ),
  [4] = LAYOUT_ergodox_pretty(
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, KC_AUDIO_VOL_UP,______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________,                                                                 ______________, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_MEDIA_NEXT_TRACK,______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    RGB_TOG,        MAGIC_TOGGLE_NKRO,______________, ______________, KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE
  ),
  [5] = LAYOUT_ergodox_pretty(
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, KC_MS_WH_UP,    KC_MS_UP,       ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________,                                                                 ______________, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_ACCEL0,   ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, KC_MS_WH_DOWN,  ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    KC_MS_ACCEL0,   KC_MS_ACCEL1,   ______________, ______________, KC_MS_BTN2,     KC_MS_BTN1
  ),
  [6] = LAYOUT_ergodox_pretty(
    KC_TAB,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           ______________,                                 ______________, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           ______________,
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           ______________,                                 LCTL(KC_Y),     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_DELETE,                                      LCTL(KC_Z),     KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    ______________, ______________, ______________, KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    KC_CAPSLOCK,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, KC_PGUP,
                                                                                    KC_SPACE,       KC_BSPACE,      ______________, KC_PGDOWN,      KC_TAB,         KC_ENTER
  ),
  [7] = LAYOUT_ergodox_pretty(
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________,                                                                 ______________, LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),     ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  ),
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128}, {129,255,128} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;

    case E_AIGU:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("'")"e");
        /* layer_off(PROG); */
      }
      return false;
      break;
    case E_GRV:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("`")"e");
      }
      return false;
      break;

    case E_TREM:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("\"")"e");
      }
      return false;
      break;

    case E_HAT:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("6")"e");
      }
      return false;
      break;

    case A_GRV:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("`")"a");
      }
      return false;
      break;

    case A_HAT:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("6")"a");
      }
      return false;
      break;

    case I_HAT:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("6")"i");
      }
      return false;
      break;
    case O_HAT:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("6")"o");
      }
      return false;
      break;
    case U_GRV:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("`")"u");
      }
      return false;
      break;

    case D_PRN:
      if (record->event.pressed) {
        SEND_STRING("()");
      }
      return false;
      break;
    case D_BRC:
      if (record->event.pressed) {
        SEND_STRING("{}");
      }
      return false;
      break;
    case D_BRK:
      if (record->event.pressed) {
        SEND_STRING("[]");
      }
      return false;
      break;
    case D_PRN_B:
      if (record->event.pressed) {
        SEND_STRING("()"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case D_BRC_B:
      if (record->event.pressed) {
        SEND_STRING("{}"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case D_BRK_B:
      if (record->event.pressed) {
        SEND_STRING("[]"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case D_BASH:
      if (record->event.pressed) {
        SEND_STRING("${}"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case D_QUOT_B:
      if (record->event.pressed) {
        SEND_STRING("\"\""SS_TAP(X_LEFT));
      }
      return false;
      break;
    case D_SQUOT_B:
      if (record->event.pressed) {
        SEND_STRING("''"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case C_POINTER:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
      break;
    case C_END_FCT:
      if (record->event.pressed) {
        SEND_STRING("();"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      }
      return false;
      break;
    case PY_END_FCT:
      if (record->event.pressed) {
        SEND_STRING("():"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      }
      return false;
      break;
    case D_ASTERIX:
      if (record->event.pressed) {
        SEND_STRING("**"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case D_CHEVRON:
      if (record->event.pressed) {
        SEND_STRING("<>"SS_TAP(X_LEFT));
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
