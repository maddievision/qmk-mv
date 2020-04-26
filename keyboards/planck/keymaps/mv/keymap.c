#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"

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

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
};

enum planck_layers {
  _BASE0,
  _LOWER1,
  _RAISE2,
  _ADJUST3,
  _HELPER4,
  _TRACKER5,
  _TRACKER6,
  _MACRO7,
  _MIDI8
};

#define LOWER MO(_LOWER1)
#define RAISE MO(_RAISE2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE0] = LAYOUT_planck_grid(KC_ESCAPE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_ENTER, MO(4), KC_LCTRL, KC_LALT, LOWER, KC_LGUI, KC_SPACE, KC_NO, RAISE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT),

    [_LOWER1] = LAYOUT_planck_grid(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRANSPARENT, KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS, KC_PLUS, KC_TRANSPARENT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_AUDIO_MUTE, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK),

    [_RAISE2] = LAYOUT_planck_grid(KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE, KC_CAPSLOCK, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS, KC_EQUAL, KC_TRANSPARENT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_AUDIO_MUTE, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_MEDIA_REWIND, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_MEDIA_FAST_FORWARD),

    [_ADJUST3] = LAYOUT_planck_grid(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE, KC_TRANSPARENT, AU_ON, AU_OFF, AU_TOG, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG, RGB_VAI, RGB_VAD, KC_TRANSPARENT, RESET, KC_TRANSPARENT, KC_TRANSPARENT, MU_ON, MU_OFF, MU_TOG, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD, RGB_HUI, RGB_HUD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    [_HELPER4] = LAYOUT_planck_grid(ST_MACRO_0, TO(8), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(5), KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN, WEBUSB_PAIR, DYN_REC_STOP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_RIGHT, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, MO(7), ST_MACRO_1, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_UP, KC_MS_DOWN, KC_MS_RIGHT),

    [_TRACKER5] = LAYOUT_planck_grid(TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(6), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    [_TRACKER6] = LAYOUT_planck_grid(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRANSPARENT, KC_TRANSPARENT, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LSFT(KC_UP)), LGUI(LSFT(KC_DOWN)), KC_TRANSPARENT),

    [_MACRO7] = LAYOUT_planck_grid(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DYN_REC_START1, DYN_REC_START2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    [_MIDI8] = LAYOUT_planck_grid(
      TO(0), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE,
      KC_TAB, KC_A, MI_Cs, MI_Ds, KC_F, MI_Fs, MI_Gs, MI_As, KC_K, MI_Cs_1, MI_Ds_1, KC_QUOTE,
      KC_LSHIFT, MI_C, MI_D, MI_E, MI_F, MI_G, MI_A, MI_B, MI_C_1, MI_D_1, KC_SLASH, KC_ENTER,
      KC_TRANSPARENT, KC_LCTRL, KC_LALT, KC_TRANSPARENT, KC_LGUI, KC_SPACE, KC_NO, KC_TRANSPARENT, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {{224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}, {224, 104, 255}},

    [1] = {{252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {205, 135, 156}, {205, 135, 156}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {150, 12, 242}, {205, 135, 156}, {205, 135, 156}, {252, 119, 255}, {252, 119, 255}, {205, 135, 156}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {150, 12, 242}, {252, 119, 255}, {252, 119, 255}, {252, 119, 255}, {205, 135, 156}, {205, 135, 156}, {205, 135, 156}, {205, 135, 156}, {205, 135, 156}, {205, 135, 156}, {205, 135, 156}, {205, 135, 156}, {150, 12, 242}, {150, 12, 242}, {150, 12, 242}, {205, 135, 156}},

    [2] = {{154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {252, 119, 255}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {150, 12, 242}, {97, 174, 114}, {97, 174, 114}, {154, 86, 255}, {154, 86, 255}, {97, 174, 114}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {150, 12, 242}, {154, 86, 255}, {154, 86, 255}, {154, 86, 255}, {97, 174, 114}, {97, 174, 114}, {97, 174, 114}, {97, 174, 114}, {97, 174, 114}, {97, 174, 114}, {97, 174, 114}, {154, 86, 255}, {150, 12, 242}, {150, 12, 242}, {150, 12, 242}, {195, 61, 255}},

    [3] = {{21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {21, 232, 123}, {21, 232, 123}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {21, 232, 123}, {21, 232, 123}, {50, 153, 244}, {50, 153, 244}, {50, 153, 244}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {50, 153, 244}, {21, 232, 123}, {21, 232, 123}, {50, 153, 244}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}, {21, 232, 123}},

    [4] = {{25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {87, 169, 255}, {25, 139, 141}, {252, 119, 255}, {25, 139, 141}, {25, 139, 141}, {87, 169, 255}, {252, 119, 255}, {0, 183, 238}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {87, 169, 255}, {87, 169, 255}, {87, 169, 255}, {0, 0, 255}, {0, 0, 255}, {25, 139, 141}, {252, 119, 255}, {25, 139, 141}, {25, 139, 141}, {252, 119, 255}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {87, 169, 255}, {87, 169, 255}, {25, 139, 141}, {25, 139, 141}, {252, 119, 255}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {25, 139, 141}, {87, 169, 255}, {87, 169, 255}, {87, 169, 255}, {87, 169, 255}},

    [5] = {{27, 126, 255}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {27, 126, 255}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}, {163, 239, 133}},

    [6] = {{133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {133, 255, 75}, {133, 255, 75}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {133, 255, 75}, {250, 159, 255}, {250, 159, 255}, {133, 255, 75}},

    [7] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {250, 159, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [8] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {250, 159, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

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
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_SPACE))));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_4))));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_V)))));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE2)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER1, _RAISE2, _ADJUST3);
}
