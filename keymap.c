/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <stdbool.h>
#include QMK_KEYBOARD_H

#define KC_CAZ LALT(LCTL(KC_Z))
#define HIGHEST_LAYER 3

static uint8_t current_layer =0;
int layer=0;
enum custom_keycodes{
    KC_LUP = SAFE_RANGE,
    KC_LDN
};

void change_RGB(uint8_t current_layerFN){
  switch(current_layerFN){
    case 0:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(RGB_WHITE);
      #endif
      break;
    case 1:  
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(RGB_RED);
      #endif
      break;
    case 2:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(RGB_GREEN);
	    #endif
      break;
    case 3:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(RGB_BLUE);
      #endif
      break;
    default:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0x00,0xff);
      #endif
      break;
    }
  return;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_LUP:
    if(record->event.pressed) {
      if (current_layer == HIGHEST_LAYER){
        for (int i=1; i<=HIGHEST_LAYER; i++){
          layer_off(i);
        }
        current_layer=0;
      } 
      else { 
        current_layer++;
        layer = current_layer;
        layer_on(current_layer);
        return false;
      }
    }
    return false;
  case KC_LDN:
    if(record->event.pressed) {
      if (current_layer == 0){
        for (int i=1; i<=HIGHEST_LAYER; i++){
          layer_on(i);
          layer = i;
        }
        current_layer=HIGHEST_LAYER;
      } 
      else {
        layer_off(current_layer);
        current_layer--;
      }
    }
    return false;
  default:
    return true;
  }
}

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE,     KC_LDN,     KC_F23,

        KC_WWW_FAVORITES,        KC_UP  ,    KC_LUP,
        
        KC_0,                    KC_DOWN,    KC_F24
    ),
    [1] = LAYOUT(   
        KC_MEDIA_PLAY_PAUSE,     KC_LDN ,      KC_F23,
       
        KC_WWW_FAVORITES,        KC_UP  ,      KC_LUP,
        
        KC_1,                    KC_DOWN,      KC_F24
    ),
    [2] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE,     KC_LDN,       KC_F23,
       
        KC_WWW_FAVORITES,        KC_UP , KC_LUP,
       
        KC_2, KC_DOWN, KC_F24
    ),
    [3] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE,     KC_LDN,      KC_F23,
        
        KC_LBRC,                 KC_RBRC,     KC_LUP,
      
        KC_CAZ,                  KC_B,        KC_F24
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_SLCK);
        } else {
            tap_code(KC_NLCK);
        }
    }
}