// GreenShadowMaker Keymap
// Copy from input_club starting point

// removed code for F() type functions
// removed code for M() old type macros

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define L0 0 // default layer
#define L1 1
#define L2 2

// Used for Macros
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L0] = LAYOUT_ergodox(  // layer 0 : default
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |  ESC  |  0  |  2  |  3  |  4  |  5  |  =  |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |  TAB  |  Q  |  W  |  E  |  R  |  T  |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    | MO(1) |  A  |  S  |  D  |  F  |  G  +-----+
 *    +-------+-----+-----+-----+-----+-----+TG(1)|
 *    | LSHIFT|  Z  |  X  |  C  |  V  |  B  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |  `  |  \  | LALT|LCTRL| LGUI|
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        | APP |CAPS |
 *                                  +-----+-----+-----+
 *                                  |     |     | HOME|
 *                                  |SPACE|BKSPC+-----+
 *                                  |     |     | DEL |
 *                                  +-----+-----+-----+
 */
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_EQL,
        KC_TAB, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, KC_NO,
        MO(L1),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TG(L1),
        KC_GRV, KC_BSLS, KC_LALT, KC_LCTL, KC_LGUI,
                                                       KC_APP, KC_CAPS,
                                                               KC_HOME,
                                            KC_SPACE,  KC_BSPC, KC_DELT,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |LCK-2|  6  |  7  |  8  |  9  |  0  |   -   |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |  [  |  Y  |  U  |  I  |  O  |  P  |   ]   |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  H  |  J  |  K  |  L  |  ;  |   '   |
 *        |TG(2)|-----+-----+-----+-----+-----+-------+
 *        |     |  N  |  M  |  ,  |  .  |  /  | RSHIFT|
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |LEFT |DOWN | UP  |RIGHT|     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    | PSCR|     |
 *    +-----+-----+-----+
 *    | PGUP|     |     |
 *    +-----+ ENT | SPC |
 *    | PGDN|     |     |
 *    +-----+-----+-----+
 */
             TG(L2),  KC_6,   KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
             KC_LBRC, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,     KC_RBRC,
                      KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
             TG(L2),  KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                              KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_NO,
             KC_PSCR, KC_NO,
             KC_PGUP,
             KC_PGDN, KC_ENT, KC_SPC
    ),

[L1] = LAYOUT_ergodox( // layer 1 : function layers
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       | f1  | f2  | f3  | f4  | f5  | f11 |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     | UP  |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |LEFT |DOWN |RIGHT|     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  | ENT |     +-----+
 *                                  |     |     | End |
 *                                  +-----+-----+-----+
 */
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                             KC_ENT, KC_TRNS, KC_END,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | f12 | f6  | f7  | f8  | f9  | f10 |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[L2] = LAYOUT_ergodox(
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | FLASH |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |NMLCK| P/  | P*  | P-  |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     | P7  | P8  | P9  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     | P4  | P5  | P6  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     | P1  | P2  | P3  |PENT |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     | P.  |PENT |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     | P0  |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS,  KC_TRNS, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_PLUS,  KC_TRNS,
                 KC_TRNS, KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_KP_1,    KC_KP_2,     KC_KP_3,        KC_KP_ENTER, KC_TRNS,
                          KC_TRNS,    KC_TRNS,     KC_KP_DOT,      KC_KP_ENTER, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_KP_0
),
};



// New Macro style Not mapped to any key right now
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:  // not using this
      if (record->event.pressed) {
        // in eeconfig.h and eeconfig.c  listed as needs doc.  not sure what it does
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:  // Appears to type version when pressed, should try in keymap
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD: // Appears to change rgb mode, not sure exactly what it does or impact
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs every cycle keypresses are scanned
// Currently only changing backlight state
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    // All LEDs off unless on a layer
    ergodox_board_led_off();
    ergodox_led_LCDlayer1_off();
    ergodox_led_LCDlayer2_off();
    ergodox_led_LCDlayer3_off();

    switch (layer) {
        case 1:
          ergodox_led_LCDlayer1_on();  // triggered in visualizer
          break;
        case 2:
          ergodox_led_LCDlayer2_on();
          break;
        case 3:
          // not currently using but adding here to match from dudeofawesome visualizer.
          ergodox_led_LCDlayer3_on();
          break;
        default:
            // none
            break;
    }

};

