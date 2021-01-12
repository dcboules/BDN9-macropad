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
#define KC_CZ  LCTL(KC_Z)
#define HIGHEST_LAYER 3
#define KC_MICS KC_F24


int mic_status=0;
bool mic_on=1;

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};
enum bdn9_layers{
  BASE=0,
  MENU,
  ONENOTE,
  CODING,
  PHOTOSHOP,
  STREAM
};
enum custom_keycodes {
    KC_ONEE = SAFE_RANGE,
    KC_ONEP,
    KC_ONEL
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ONEE:
            if (record->event.pressed) {
                tap_code16(LALT(KC_D));
                wait_ms(10);
                tap_code(KC_E);
                wait_ms(10);
                tap_code(KC_M);
            }
            break;
        case KC_ONEP:
            if (record->event.pressed) {
                tap_code16(LALT(KC_D));
                wait_ms(10);
                tap_code(KC_P);
                wait_ms(10);
                tap_code(KC_ENT);
            }
            break;
        case KC_ONEL:
            if (record->event.pressed) {
                tap_code16(LALT(KC_D));
                wait_ms(10);
                tap_code(KC_L);
                wait_ms(10);
                tap_code(KC_ENT);
            }
            break;
        case KC_MICS:
            if (record->event.pressed){
                xprintf("mic_status value: 0b%032lb (%u)\n", mic_status);
                if (mic_status == 0) {
                    xprintf("mic_status value: 0b%032lb (%u)\n", mic_status);
                    mic_status = 1;
                    }
                else {
                    xprintf("mic_status value: 0b%032lb (%u)\n", mic_status);
                    mic_status = 0;

                };
            }
            break;
    }
    return true;
};
void mic_status_indicator(void){
    if (mic_status == 0) {
        xprintf("RGB mic_status value: 0b%032lb (%u)\n", mic_status);
        rgb_matrix_set_color(8, 0, 255, 0);
    } 
    else {
        xprintf("RGB mic_status value: 0b%032lb (%u)\n", mic_status);
        rgb_matrix_set_color(8, 255, 0, 0);
    }
};
void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case BASE:
            rgb_matrix_set_color_all(255, 255, 255);
            mic_status_indicator();
            break;
        case ONENOTE:
            rgb_matrix_set_color_all(135, 31, 120);
            mic_status_indicator();
            break;
        case CODING:
            rgb_matrix_set_color_all(0, 255, 255);
            mic_status_indicator();
            break;
          case PHOTOSHOP: 
            rgb_matrix_set_color_all(0, 0, 255);
            mic_status_indicator();
            break;
          case STREAM:
            rgb_matrix_set_color_all(255, 165, 0);
            mic_status_indicator();
            break;
        case MENU:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(0, 255, 211, 0);
            rgb_matrix_set_color(1, 255, 211, 0);
            rgb_matrix_set_color(2, 255, 211, 0);
            rgb_matrix_set_color(3, 255, 255, 255);
            rgb_matrix_set_color(4, 135, 31, 120);
            rgb_matrix_set_color(5, 0, 255, 255);
            rgb_matrix_set_color(6, 0, 0, 255);
            rgb_matrix_set_color(7, 255, 165, 0);
            mic_status_indicator();
            rgb_matrix_set_color(9, 255, 211, 0);
            rgb_matrix_set_color(10, 255, 211, 0);
            break;  
        default: 
            break;
    }
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [BASE] = LAYOUT(  
       KC_MEDIA_PLAY_PAUSE,      TO(MENU),               KC_F23,
        KC_WWW_FAVORITES,        KC_UP  ,                KC_B,       
        KC_0,                    KC_DOWN,                KC_MICS   
    ),
    [ONENOTE] = LAYOUT(     
        KC_MEDIA_PLAY_PAUSE,     TO(MENU),               KC_F23,       
        KC_ONEL,                 KC_CZ  ,                KC_PGDN,
        KC_ONEP,                 KC_ONEE,                KC_MICS
    ),
    [CODING] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE,     TO(MENU),               KC_F23,
        KC_WWW_FAVORITES,        KC_UP ,                 KC_C,
        KC_2,                    KC_DOWN,                KC_MICS 
    ),
    [PHOTOSHOP] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE,     TO(MENU),               KC_F23,
        KC_LBRC,                 KC_RBRC,                KC_P, 
        KC_CAZ,                  KC_B,                   KC_MICS
    ),
    
    [STREAM] = LAYOUT(
      KC_MEDIA_PLAY_PAUSE,      TO(MENU),                KC_F23,
      KC_WWW_FAVORITES,         KC_UP ,                  KC_S,      
      KC_2,                     KC_DOWN,                 KC_MICS
    ),
    [MENU] = LAYOUT(   
      KC_MEDIA_PLAY_PAUSE,      TO(MENU),                KC_F23,
      TO(BASE),                 TG(ONENOTE) ,            TG(CODING),   
      TG(PHOTOSHOP),            TG(STREAM),              KC_MICS
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
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /*
//         | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
//         | Press: Mute       | Home | Press: Play/Pause  |
//         | Hold: Layer 2     | Up   | RGB Mode           |
//         | Left              | Down | Right              |
//      */
//     [BASE] = LAYOUT(  
//         KC_MEDIA_PLAY_PAUSE,     /*KC_LDN*/ TG (MENU),      KC_F23
//         KC_WWW_FAVORITES,        KC_UP  ,                     /*KC_LUP*/ TG(ONENOTE),
//         KC_0,                    KC_DOWN,                     KC_F24  
//     ),
//     [ONENOTE] = LAYOUT(     
//         KC_MEDIA_PLAY_PAUSE,     /*KC_LDN*/ TO(BASE),         KC_F23,     
//         KC_WWW_FAVORITES,        KC_UP  ,                     /*KC_LUP*/ TG(CODING),
//         KC_1,                    KC_DOWN,                     KC_F2
//     ),
//     [CODING] = LAYOUT(
//         KC_MEDIA_PLAY_PAUSE,     /*KC_LDN*/ TG(ONENOTE),      KC_F23,    
//         KC_WWW_FAVORITES,        KC_UP ,                      /*KC_LUP*/ TG(PHOTOSHOP),    
//         KC_2,                    KC_DOWN,                     KC_F24 
//     ),
//     [PHOTOSHOP] = LAYOUT( 
//          KC_MEDIA_PLAY_PAUSE,     /*KC_LDN*/ TG(CODING),       KC_F23,    
//         KC_LBRC,                 KC_RBRC,                     /*KC_LUP*/ TG(STREAM),   
//         KC_CAZ,                  KC_B,                        KC_F24
//    ),
//     [STREAM] = LAYOUT( 
//       KC_MEDIA_PLAY_PAUSE,     TG(PHOTOSHOP),                  KC_F23,
//       KC_WWW_FAVORITES,        KC_UP ,                        /*KC_LUP*/ TO(BASE),   
//       KC_2,                    KC_DOWN,                       KC_F24
//     )
//         [MENU] = LAYOUT( 
//       KC_MEDIA_PLAY_PAUSE,     TG(PHOTOSHOP),                  KC_F23,
//       KC_WWW_FAVORITES,        KC_UP ,                        /*KC_LUP*/ TO(BASE),  
//       KC_2,                    KC_DOWN,                       KC_F24
//     )
// };
// static uint8_t current_layer =0;
// int layer=0;
// enum custom_keycodes{
//     KC_LUP = SAFE_RANGE,
//     KC_LDN
// };
// void change_RGB(uint8_t current_layerFN){
//   switch(current_layerFN){
//     case 0:
//       #ifdef RGBLIGHT_ENABLE
//       rgblight_setrgb(RGB_WHITE);
//       #endif
//       break;
//     case 1:  
//       #ifdef RGBLIGHT_ENABLE
//       rgblight_setrgb(RGB_RED);
//       #endif
//       break;
//     case 2:
//       #ifdef RGBLIGHT_ENABLE
//       rgblight_setrgb(RGB_GREEN);
// 	    #endif
//       break;
//     case 3:
//       #ifdef RGBLIGHT_ENABLE
//       rgblight_setrgb(RGB_BLUE);
//       #endif
//       break;
//     default:
//       #ifdef RGBLIGHT_ENABLE
//       rgblight_setrgb(0xff,0x00,0xff);
//       #endif
//       break;
//     }
//   return;
// }
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//   case KC_LUP:
//     if(record->event.pressed) {
//       if (current_layer == HIGHEST_LAYER){
//         for (int i=1; i<=HIGHEST_LAYER; i++){
//           layer_off(i);
//         }
//         current_layer=0;
//       } 
//       else { 
//         current_layer++;
//         layer = current_layer;
//         layer_on(current_layer);
//         return false;
//       }
//     }
//     return false;
//   case KC_LDN:
//     if(record->event.pressed) {
//       if (current_layer == 0){
//         for (int i=1; i<=HIGHEST_LAYER; i++){
//           layer_on(i);
//           layer = i;
//         }
//         current_layer=HIGHEST_LAYER;
//       } 
//       else {
//         layer_off(current_layer);
//         current_layer--;
//       }
//     }
//     return false;
//   default:
//     return true;
//   }
// }