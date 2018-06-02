// Modified version of gsm-cospad-ortho-left for gamepad use

#include "cospad.h"
#include "led.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* COSPAD Left Hand Main layer
   *   (USB Port)
   * ,-------------------.
   * | 5  | T  | G  |Space|
   * |----|----|----|----|
   * | 4  | R  | F  |Ctrl|
   * |----|----|----|----|
   * | 3  | E  | D  | C  |
   * |----|----|----|----|
   * | 2  | W  | S  | X  |
   * |----|----|----|----|
   * | 1  | Q  | A  | Z  |
   * |----|----|----|----|
   * | Esc| Tab| _FL|Shft|
   * `-------------------'
 */

 //Reference: https://docs.qmk.fm/keycodes

[_BL] = KEYMAP(
  KC_5,     KC_T,     KC_G,  KC_SPACE, \
  KC_4,     KC_R,     KC_F,  KC_LCTRL, \
  KC_3,     KC_E,     KC_D,      KC_C,  \
  KC_2,     KC_W,     KC_S,      KC_X, \
  KC_1,     KC_Q,     KC_A,      KC_Z, \
  KC_ESC, KC_TAB,    MO(_FL), KC_LSHIFT),

  /* Keymap _FL:
   *   (USB Port)
   * ,-------------------.
   * |RGBT|    |    |    |
   * |----|----|----|----|
   * |RGBM|RGBP|BTOG|    |
   * |----|----|----|----|
   * | HUD| HUI|BON |    |
   * |----|----|----|----|
   * | SAD| SAI|BOFF|    |
   * |----|----|----|----|
   * | VAD| VAS|    |    |
   * |----|----|----|----|
   * |    |    |TRNS| RST|
   * `-------------------'
   * TRNS key required for MO()
   * Keep reset key available
   */

[_FL] = KEYMAP(
  RGB_TOG,  KC_NO,    KC_NO,     KC_NO, \
  RGB_MOD,  RGB_M_P,  BL_TOGG,   KC_NO, \
  RGB_HUD,  RGB_HUI,  BL_ON,     KC_NO, \
  RGB_SAD,  RGB_SAI,  BL_OFF,    KC_NO,   \
  RGB_VAD,  RGB_VAI,  KC_NO,     KC_NO, \
  KC_NO,    KC_NO,    KC_TRNS,   RESET),
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = MO(_FL),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case BL_TOGG:
         if (record->event.pressed) {
            cospad_bl_led_togg();
         }
         return false;
      case BL_ON:
         if (record->event.pressed) {
            cospad_bl_led_on();
         }
         return false;
      case BL_OFF:
         if(record->event.pressed) {
            cospad_bl_led_off();
         }
         return false;
      default:
         return true;
   }
}
