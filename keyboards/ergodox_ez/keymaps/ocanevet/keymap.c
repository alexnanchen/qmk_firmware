#include QMK_KEYBOARD_H
/* #include "ergodox_ez.h" */
#include "debug.h"
#include "action_layer.h"
#include "version.h"
/* #include "ergodox_ez.h" */
/* #include "debug.h" */
/* #include "action_layer.h" */
/* #include "version.h" */

#define ______________ KC_TRANSPARENT

#define BASE     0
#define QWERTY   1
#define PROG     2
#define EMACS    3
#define KEYPAD   5
#define EMACS_C  6
#define EMACS_A  4
#define NAV      7


#define EMACS_CTRL_K LCTL(LSFT(KC_DELETE))

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


/* LT(3,KC_QUOTE), */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox
  (
   LT(NAV,KC_GRV), KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,
   KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           ______________,
   TO(EMACS),      KC_A,           KC_R,           KC_S,           LSFT_T(KC_T) ,  KC_D,
   KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TAB,
   KC_LCTRL,       KC_MEH,         TT(KEYPAD),     MO(PROG),       KC_UNDERSCORE,

   /*           */ KC_ESCAPE,      KC_DELETE,
   /*                           */ ______________,
   KC_LCTRL,       KC_LALT,        KC_TAB,

   KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_EQUAL,       KC_BSPACE,
   ______________, KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_BSLASH,
   /*           */ KC_H,           LSFT_T(KC_N),   KC_E,           KC_I,           KC_O,           KC_QUOTE,
   KC_ENTER,       KC_K,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
   /*                           */ MO(PROG),       KC_RALT,        KC_LBRACKET,    KC_RBRACKET,    KC_RCTRL,

   KC_LEFT,        KC_RIGHT,
   KC_UP,
   KC_DOWN,        LSFT_T(KC_BSPACE),      KC_SPACE

   ),

  [QWERTY] = LAYOUT_ergodox
  (
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           ______________,
   LT(NAV, KC_NO), KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
   ______________, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           ______________,
   ______________, ______________, ______________, ______________, ______________,

   /*           */ ______________, ______________,
   /*                           */ ______________,
   ______________, ______________, ______________,

   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
   /*           */ KC_H,           KC_J,           KC_K,           KC_L,           LT(NAV, KC_SCOLON), LT(NAV, KC_QUOTE),
   ______________, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       ______________,
   /*                           */ ______________, ______________, ______________, ______________, ______________,

   ______________, ______________,
   ______________,
   ______________, ______________, ______________

   ),

  [PROG] = LAYOUT_ergodox
  (
   ______________, ______________, ______________, ______________, D_BASH,         ______________, ______________,
   ______________, A_HAT,          ______________, ______________, ______________, C_POINTER,      ______________,
   ______________, A_GRV,          D_BRC_B,        D_BRK_B,        D_PRN_B,        D_QUOT_B,
   ______________, ______________, ______________, PY_END_FCT,     C_END_FCT,      ______________, ______________,
   ______________, ______________, ______________, ______________, ______________,

   /*           */ ______________, ______________,
   /*                           */ ______________,
   ______________, ______________, ______________,

   ______________, D_ASTERIX,      ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, U_GRV,          I_HAT,          ______________, ______________,
   /*           */ E_TREM,         E_AIGU,         E_GRV,          E_HAT,          O_HAT,          ______________,
   ______________, ______________, ______________, D_CHEVRON,      ______________, ______________, ______________,
   /*                           */ ______________, ______________, ______________, ______________, ______________,

   ______________, ______________,
   ______________,
   ______________, ______________, ______________

     ),


  [EMACS] = LAYOUT_ergodox
  (
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   TO(BASE),       ______________, ______________, ______________, ______________, ______________,
   ______________, CTL_T(KC_Z),    ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________,

   /*           */ ______________, ______________,
   /*                           */ ______________,
   LT(EMACS_C, KC_NO), ______________, ______________,
   /* LT(EMACS_C, KC_NO), LT(EMACS_A, KC_NO), ______________, */

   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   /*           */ ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   /*           */ ______________, ______________, ______________, ______________, ______________,

   ______________, ______________,
   ______________,
   ______________, ______________, ______________

   ),

  /* Emulate Ctrl behaviour of Emacs */
  [EMACS_C] = LAYOUT_ergodox
   (
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, LCTL(KC_W),     KC_RIGHT,       KC_UP,          KC_ESCAPE,      ______________,
   ______________, KC_HOME,        ______________, LCTL(KC_F),     LCTL(KC_T),     KC_DELETE,
   ______________, ______________, ______________, ______________, KC_PGDOWN,      KC_LEFT,        ______________,
   ______________, ______________, ______________, ______________, ______________,

   /*           */ ______________, ______________,
   /*                           */ ______________,
   ______________, ______________, ______________,

   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, KC_ENTER,       ______________, ______________, LCTL(KC_V),     ______________, ______________,
   /*           */ ______________, KC_DOWN,        KC_END,         KC_TAB,         ______________, ______________,
   ______________, EMACS_CTRL_K,   ______________, ______________, ______________, LCTL(KC_Z),     ______________,
   /*           */ ______________, ______________, ______________, ______________, ______________,

   ______________, ______________,
   ______________,
   ______________, LCTL(KC_BSPC),  ______________

 ),

  /* Emulate Alt behaviour of Emacs */
 [EMACS_A] = LAYOUT_ergodox
  (
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, LCTL(KC_LEFT),  ______________,
   ______________, ______________, ______________, ______________, ______________,

   /*           */ ______________, ______________,
   /*                           */ ______________,
   ______________, ______________, ______________,

   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   /*           */ ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, LCTL(KC_Z),     ______________,
   /*                           */ ______________, ______________, ______________, ______________, ______________,

   ______________, ______________,
   ______________,
   ______________, ______________, ______________

),

 [KEYPAD] = LAYOUT_ergodox
  (
   KC_VOLU       , KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,
   KC_VOLD       , ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________,

   /*           */ ______________, ______________,
   /*                           */ ______________,
   ______________, ______________, ______________,

   KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_VOLU,
   ______________, ______________, KC_7,           KC_8,           KC_9,           KC_KP_SLASH,    KC_VOLD,
   /*           */ ______________, KC_4,           KC_5,           KC_6,           KC_KP_ASTERISK, ______________,
   ______________, ______________, KC_1,           KC_2,           KC_3,           KC_KP_PLUS,     ______________,
   /*                           */ KC_0,           KC_DOT,         KC_DOT,         KC_KP_MINUS,    ______________,

   ______________, ______________,
   ______________,
   ______________, ______________, ______________

),

  [NAV] = LAYOUT_ergodox
  (
   ______________, TO(BASE),       TO(EMACS),      TO(QWERTY),     ______________, TO(5),          ______________,
   KC_MS_BTN3,     ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________, ______________, ______________,
   ______________, ______________, ______________, ______________, ______________,

   /*           */ ______________, ______________,
   /*                           */ ______________,
   ______________, ______________, ______________,

   ______________, ______________, LALT(KC_LEFT),  ______________, LALT(KC_RIGHT), ______________, ______________,
   KC_MS_WH_UP,    ______________, LCTL(KC_PGUP),  KC_UP,          LCTL(KC_PGDOWN),______________, ______________,
   /*           */ KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         ______________,
   KC_MS_WH_DOWN,  ______________, ______________, ______________, ______________, ______________, ______________,
   /*                           */ ______________, ______________, ______________, ______________, ______________,

   ______________, ______________,
   ______________,
   ______________, ______________, KC_LCTRL

   ),

  /* [6] = LAYOUT_ergodox(KC_PLUS,RALT(KC_1),RALT(KC_2),RALT(KC_3),RALT(KC_4),RALT(KC_5),______________,LSFT(KC_MINUS),LSFT(KC_1),LSFT(KC_2),RALT(KC_7),RALT(KC_0),RALT(KC_RBRACKET),______________,______________,______________,LSFT(KC_NONUS_BSLASH),LSFT(KC_8),LSFT(KC_9),LSFT(KC_7),______________,RALT(KC_NONUS_BSLASH),LSFT(KC_6),RALT(KC_8),RALT(KC_9),RALT(KC_MINUS),______________,______________,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,______________,______________,KC_F8,LSFT(KC_RBRACKET),RALT(KC_6),RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0),______________,KC_KP_MINUS,LSFT(KC_0),KC_7,KC_8,KC_9,______________,KC_PLUS,KC_KP_PLUS,KC_4,KC_5,KC_6,______________,KC_LBRACKET,KC_KP_SLASH,KC_KP_ASTERISK,KC_1,KC_2,KC_3,______________,______________,KC_0,KC_DOT,______________,______________,______________,KC_F11,KC_F12,KC_F10,KC_F9,______________,______________), */

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

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


//  [2] = LAYOUT_ergodox
//   (
//    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
//    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
//    ______________, ______________, ______________, ______________, ______________, ______________,
//    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
//    ______________, ______________, ______________, ______________, ______________,
//
//    /*           */ ______________, ______________,
//    /*                           */ ______________,
//    ______________, ______________, ______________,
//
//    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
//    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
//    /*           */ ______________, ______________, ______________, ______________, ______________, ______________,
//    ______________, ______________, ______________, ______________, ______________, ______________, ______________,
//    /*                           */ ______________, ______________, ______________, ______________, ______________,
//
//    ______________, ______________,
//    ______________,
//    ______________, ______________, ______________
//
// ),
