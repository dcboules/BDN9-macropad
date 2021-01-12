#include <stdint.h>
#include <stdbool.h>

#include QMK_KEYBOARD_H

#define HIGHEST_LAYER 3
#define KC_CAZ LALT(LCTL(KC_Z))
#define KC_SCRN LSFT(LGUI(KC_S))
#define KC_CZ  LCTL(KC_Z)
#define KC_DMIC KC_F24
#define KC_ZCHAT LALT(KC_H)
#define KC_WINR LGUI(KC_R)

int dmic_status=0;
int zmic_status=1;
int zvid_status=1;

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};
enum bdn9_layers{
  MENU = 0,
  ZOOM,
  ONENOTE,
  CODING,
  PHOTOSHOP,
  STREAM
};
enum custom_keycodes {
    KC_ONEE = SAFE_RANGE,
    KC_ONEP,
    KC_ONEL,
    KC_LINK,
    KC_NOTE,
    KC_ZMIC,
    KC_ZVID,
    KC_GPUS,
    KC_GPUL,
    KC_INCL,
    KC_USER
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ONEE:
            if (record->event.pressed) {
                tap_code16(LALT(KC_D));
                wait_ms(30);
                tap_code(KC_E);
                wait_ms(30);
                tap_code(KC_M);
            }
            break;
        case KC_ONEP:
            if (record->event.pressed) {
                tap_code16(LALT(KC_D));
                wait_ms(30);
                tap_code(KC_P);
                wait_ms(30);
                tap_code(KC_ENT);
            }
            break;
        case KC_ONEL:
            if (record->event.pressed) {
                tap_code16(LALT(KC_D));
                wait_ms(30);
                tap_code(KC_L);
                wait_ms(30);
                tap_code(KC_ENT);
            }
            break;
        case KC_LINK:
            if(record->event.pressed){
                tap_code16(KC_WINR);
                wait_ms(50);
                SEND_STRING("http://elearn.ucr.edu/");
                wait_ms(50);
                tap_code(KC_ENT);
            }
            break;
        case KC_NOTE:
            if(record->event.pressed){
                tap_code16(KC_WINR);
                wait_ms(50);
                SEND_STRING("onenote.exe");
                wait_ms(50);
                tap_code(KC_ENT);
            }
            break;
        case KC_DMIC:
            if (record->event.pressed){
                if (dmic_status == 0) {
                    dmic_status = 1;
                }
                else {
                    dmic_status = 0;
                };
            }
            break;
        case KC_ZMIC:
            if (record->event.pressed){
                tap_code16(LALT(KC_A));
                if (zmic_status == 0) {
                    zmic_status = 1;
                }
                else {
                    zmic_status = 0;
                };
            }
            break;
        case KC_ZVID:
            if (record->event.pressed){
                tap_code16(LALT(KC_V));
                if (zvid_status == 0) {
                    zvid_status = 1;
                }
                else {
                    zvid_status = 0;
                };
            }
            break;
        case KC_GPUS:
            if(record->event.pressed){
                SEND_STRING("git push");
            }
            break;
        case KC_GPUL:
            if(record->event.pressed){
                SEND_STRING("git pull");
            }
            break;
        case KC_INCL:
            if (record->event.pressed){
                SEND_STRING("#include <>");
            }
            break;
        case KC_USER:
            if (record->event.pressed){
                SEND_STRING("dcboules");
            }
            break;
    }
    return true;
};
void dmic_status_indicator(void){
    if (dmic_status == 0) {
        rgb_matrix_set_color(8, 0, 255, 0);
    } 
    else {
        rgb_matrix_set_color(8, 255, 0, 0);
    }
};
void zmic_status_indicator(void){
    if (zmic_status == 0) {
        rgb_matrix_set_color(3, 0, 255, 0);
    } 
    else {
        rgb_matrix_set_color(3, 255, 0, 0);
    }
};
void zvid_status_indicator(void){
    if (zvid_status == 0) {
        rgb_matrix_set_color(4, 0, 255, 0);
    } 
    else {
        rgb_matrix_set_color(4, 255, 0, 0);
    }
}
void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
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
            dmic_status_indicator();
            rgb_matrix_set_color(9, 255, 211, 0);
            rgb_matrix_set_color(10, 255, 211, 0);
            break; 
        case ZOOM:
            rgb_matrix_set_color_all(255, 255, 255);
            zmic_status_indicator();
            zvid_status_indicator();
            dmic_status_indicator();
            break;
        case ONENOTE:
            rgb_matrix_set_color_all(135, 31, 120);
            dmic_status_indicator();
            break;
        case CODING:
            rgb_matrix_set_color_all(0, 255, 255);
            dmic_status_indicator();
            break;
          case PHOTOSHOP: 
            rgb_matrix_set_color_all(0, 0, 255);
            dmic_status_indicator();
            break;
          case STREAM:
            rgb_matrix_set_color_all(255, 165, 0);
            dmic_status_indicator();
            break; 
        default: 
            break;
    }
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MENU] = LAYOUT(   
      KC_MEDIA_PLAY_PAUSE,      TO(MENU),                KC_F23,
      TO(ZOOM),                 TG(ONENOTE) ,            TG(CODING),   
      TG(PHOTOSHOP),            TG(STREAM),              KC_DMIC
    ),
    [ZOOM] = LAYOUT(  
        KC_MEDIA_PLAY_PAUSE,     TO(MENU),               KC_F23,
        KC_ZMIC,                 KC_ZVID,                KC_ZCHAT,       
        KC_LINK,                 KC_NOTE,                KC_DMIC   
    ),
    [ONENOTE] = LAYOUT(     
        KC_MEDIA_PLAY_PAUSE,     TO(MENU),               KC_F23,       
        KC_ONEL,                 KC_CZ  ,                KC_PGDN,
        KC_ONEP,                 KC_ONEE,                KC_DMIC
    ),
    [CODING] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE,     TO(MENU),               KC_F23,
        KC_GPUS,                 KC_GPUL ,               KC_INCL,
        KC_SCRN,                 KC_USER,                KC_DMIC 
    ),
    [PHOTOSHOP] = LAYOUT(
        KC_MEDIA_PLAY_PAUSE,     TO(MENU),               KC_F23,
        KC_LBRC,                 KC_RBRC,                KC_CAZ, 
        KC_B,                    KC_E,                   KC_DMIC
    ),
    
    [STREAM] = LAYOUT(
      KC_MEDIA_PLAY_PAUSE,      TO(MENU),                KC_F23,
      KC_WWW_FAVORITES,         KC_UP ,                  KC_S,      
      KC_2,                     KC_DOWN,                 KC_DMIC
    )
  
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } 
        else {
            tap_code(KC_MPRV);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } 
        else {
            tap_code(KC_UP);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_SLCK);
        } 
        else {
            tap_code(KC_NLCK);
        }
    }
}
