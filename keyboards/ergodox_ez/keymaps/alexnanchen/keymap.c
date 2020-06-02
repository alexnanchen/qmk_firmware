#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german_ch.h"

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
#define KC_UNDER LSFT(KC_MINUS)

// French characters
#define E_AIGU KC_SCOLON
#define E_GRAVE KC_LBRACKET
#define A_GRAVE KC_QUOTE
#define C_CELA LSFT(KC_4)
#define TREMA KC_RBRACKET
#define CIRCUMFLEX KC_EQUAL
#define S_QUOTE KC_QUOTE
#define D_QUOTE LSFT(KC_QUOTE)
#define Q_MARK LSFT(KC_SLASH)

// Others
#define ______________ KC_TRANSPARENT
//#define CMD_TAB LCMD(KC_TAB)
#define BASE     0
#define PUNCT    1
#define PROG     2
#define OTHER    3
#define FR       4

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
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
  [BASE] = LAYOUT_ergodox(
    KC_ESCAPE,       KC_1,           KC_2,           KC_3,           KC_4,             KC_5,           KC_AUDIO_VOL_DOWN,
    KC_GRAVE,        KC_Q,           KC_W,           KC_F,           KC_P,             KC_B,           KC_TAB,
    KC_MINUS,        KC_A,           LT(PROG, KC_R), LT(PUNCT,KC_S), LT(OTHER, KC_T),  KC_G,
    KC_LSHIFT,       KC_Z,           KC_X,           LCTL_T(KC_C),   LALT_T(KC_D),     KC_V,           KC_LGUI,
    KC_CIRC ,        KC_LCTRL,       ______________, KC_LEFT,        KC_RIGHT,


    /*            */ LCTL(KC_Y),     LALT(LCTL(KC_DELETE)),
    /*                            */ LGUI(KC_L),
    KC_SPACE,        KC_ENTER,       KC_LCTRL,


    KC_AUDIO_VOL_UP,  KC_6,          KC_7,           KC_8,             KC_9,           KC_0,           KC_DELETE,
    KC_TAB,           KC_J,          KC_L,           KC_U,             KC_Y,           KC_SCOLON,      KC_BSLASH,
                      KC_M,          LT(PROG, KC_N), LT(PUNCT,KC_E),   LT(OTHER,KC_I), KC_O,           KC_TAB,
    KC_LGUI,          KC_K,          LALT_T(KC_H),   LCTL_T(KC_COMMA),  KC_DOT,        KC_SLASH,       KC_RSHIFT,
    /*                            */ KC_UP,          KC_DOWN,          ______________, KC_LCTRL,       ______________,


    KC_PGDOWN,        LCTL(KC_V),
    KC_PGUP,
    KC_RCTRL,         KC_ENTER,         KC_BSPACE

  ),

  [PUNCT] = LAYOUT_ergodox(
    ______________, KC_F1,          KC_F2,          KC_F3,          KC_F4,            KC_F5,          KC_F6,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, KC_PERCENT    , ______________, ______________, KC_EXLM       , KC_AT         ,
    ______________, ______________, ______________, KC_UNDER      , Q_MARK        , ______________, ______________,
    ______________, ______________, ______________, KC_HOME       , KC_END        ,


    /*            */ ______________, ______________,
    /*                            */ ______________,
    ______________,  ______________, ______________,



      KC_F7       ,    KC_F8      , KC_F9         , KC_F10         , KC_F11        , KC_F12        , ______________,
    ______________, ______________, ______________, KC_EQUAL       , ______________, ______________, ______________,
                    KC_KP_MINUS   , KC_KP_ASTERISK, ______________ , KC_KP_PLUS    , ______________, ______________,
    ______________, ______________, KC_SLASH      , KC_UNDER       , ______________, ______________, ______________,
                                    KC_PGUP       , KC_PGDOWN      , ______________, ______________, ______________,


    ______________,   ______________,
    ______________,
    ______________,   ______________,  ______________

  ),

  [PROG] = LAYOUT_ergodox(
    RESET,          ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, KC_Y          , ______________, KC_LCBR       ,   KC_RCBR,        KC_AMPR,      D_BRC_B,
    ______________, KC_HASH       , ______________, KC_LPRN       ,   KC_RPRN,        KC_DLR,
    ______________, ______________, ______________, KC_LBRACKET   ,   KC_RBRACKET,    KC_TILD,      D_PRN_B,
    ______________, ______________, ______________, ______________,   KC_CIRC,


    /*            */ ______________, ______________,
    /*                            */ ______________,
    KC_TAB        ,  ______________, ______________,


    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, KC_UP         , ______________, ______________, ______________,
                    ______________, ______________, KC_DOWN       , KC_RIGHT      , ______________, ______________,
    D_BRK_B       , ______________, KC_LEFT       , ______________, ______________, ______________, ______________,
                                    ______________, ______________, ______________, ______________, ______________,


    ______________, ______________,
    ______________,
    ______________, ______________, KC_TAB

  ),

  [OTHER] = LAYOUT_ergodox(
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, KC_LEFT       , KC_RIGHT      , ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,


    /*            */ ______________, ______________,
    /*                            */ ______________,
    KC_TAB        ,  ______________, ______________,


    ______________, ______________, ______________, ______________, ______________, ______________, CIRCUMFLEX,
    ______________, ______________, ______________, C_CELA        , ______________, E_GRAVE       , TREMA,
                    KC_0          , S_QUOTE       , D_QUOTE       , ______________, E_AIGU        , A_GRAVE,
    ______________, ______________, KC_SLASH      , ______________, ______________, ______________, ______________,
                                    ______________, ______________, ______________, ______________, ______________,

    ______________, ______________,
    ______________,
    ______________, ______________, KC_TAB

  )

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
