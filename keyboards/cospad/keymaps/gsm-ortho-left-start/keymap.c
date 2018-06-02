// Copy of Default modified as a left hand starting point for creating gamepad

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
   * | T  | G  | B  | SPC|
   * |----|----|----|----|
   * | R  | F  | V  |    |
   * |----|----|----|----|
   * | E  | D  | C  |Gui |
   * |----|----|----|----|
   * | W  | S  | X  |Alt |
   * |----|----|----|----|
   * | Q  | A  | Z  |ctrl|
   * |----|----|----|----|
   * | Esc| Tab| sft|    |
   * `-------------------'
 */

// Not using additional layer in this version.

[_BL] = KEYMAP(
  KC_T,     KC_G,     KC_B,   KC_SPC, \
  KC_R,     KC_F,     KC_V,   KC_NO, \
  KC_E,     KC_D,     KC_C,   KC_LGUI, \
  KC_W,     KC_S,     KC_X,   KC_LALT, \
  KC_Q,     KC_A,     KC_Z,   KC_LCTL, \
  KC_ESC, KC_TAB,    KC_NO,     KC_LSHIFT),

  /* Keymap _FL:  NOT ACTIVE
   * ,-------------------.
   * |RGBT|TAB | FN | BS |
   * |----|----|----|----|
   * |RGBM|RGBP|BTOG| -  |
   * |----|----|----|----|
   * |HUD |HUI |BON |    |
   * |----|----|----| +  |
   * |SAD |SAI |BOFF|    |
   * |----|----|----|----|
   * |VAD |VAS | 3  |    |
   * |----|----|----| En |
   * |   0     |RST |    |
   * `-------------------'
   */
[_FL] = KEYMAP(
  RGB_TOG,  KC_TAB,   KC_TRNS,   KC_BSPC, \
  RGB_MOD,  RGB_M_P,  BL_TOGG,   KC_PMNS, \
  RGB_HUD,  RGB_HUI,  BL_ON,     KC_PPLS, \
  RGB_SAD,  RGB_SAI,  BL_OFF,    KC_NO,   \
  RGB_VAD,  RGB_VAI,  KC_P3,     KC_PENT, \
  KC_P0,    KC_NO,    RESET,     KC_NO),
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
