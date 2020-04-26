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

enum unicode_names {
    UEM_SPARKLE,
    UEM_SHRUG,
    UEM_S2,
};

const uint32_t PROGMEM unicode_map[] = {
    [UEM_SPARKLE]  = 0x2728,  // ‽
    [UEM_SHRUG] = 0x1F937,  // ⸮
    [UEM_S2]  = 0x1F3FB, // 🐍
};

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_EMOJ,
  ST_SHOT,
  ST_TPST,
  ST_GO,
  ST_ESPK,
  ST_ESHG,
  ST_MV,
  ST_MADI,
  ST_GMAI,
  ST_HEX,
  ST_ROCK
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
  _MIDI8,
  _MIDI9,
};

#define BASE    TO(_BASE0)
#define LOWER   MO(_LOWER1)
#define RAISE   MO(_RAISE2)
#define ADJUST  MO(_ADJUST3)
#define HELPER  MO(_HELPER4)
#define TRACKER TO(_TRACKER5)
#define TRACKR2 MO(_TRACKER6)
#define MACREC  MO(_MACRO7)
#define MIDI    TO(_MIDI8)
#define MIDI2   TO(_MIDI9)

#define RSH_ENT RSFT_T(KC_ENT)

#define HEX_A   LSFT(KC_A)
#define HEX_B   LSFT(KC_B)
#define HEX_C   LSFT(KC_C)
#define HEX_D   LSFT(KC_D)
#define HEX_E   LSFT(KC_E)
#define HEX_F   LSFT(KC_F)

#define ORYXKEY WEBUSB_PAIR

#define DMPLAY1 DYN_MACRO_PLAY1
#define DMPLAY2 DYN_MACRO_PLAY2
#define DMREC1  DYN_REC_START1
#define DMREC2  DYN_REC_START2
#define DMRSTOP DYN_REC_STOP

#define TR_ROWU LGUI(LSFT(KC_UP))
#define TR_ROWD LGUI(LSFT(KC_DOWN))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE0] = LAYOUT_planck_grid(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSH_ENT,
      KC_LCTL, HELPER,  KC_LALT, KC_LGUI, LOWER,  KC_SPC,   KC_NO,   RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_LOWER1] = LAYOUT_planck_grid(
      KC_TILD, KC_P1,   KC_P2,   KC_P3,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_UNDS, KC_DEL, 
      KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_PEQL, KC_PPLS, 
      RAISE,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_F11,  KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_ASTR, KC_PMNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   ADJUST,  KC_GRV,  ST_ROCK, KC_PIPE, KC_BSLS
    ),

    [_RAISE2] = LAYOUT_planck_grid(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_NO,   HEX_E,   HEX_F,   KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_DEL,
      KC_NO,   KC_DLR,  KC_PERC, KC_CIRC, KC_NO,   HEX_C,   HEX_D,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO, 
      KC_TRNS, KC_AMPR, KC_ASTR, ST_HEX,  KC_NO,   HEX_A,   HEX_B,   KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PENT,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJUST,  KC_TRNS, KC_NO,   KC_TRNS, KC_P0,   KC_PDOT, KC_ASTR, KC_PENT
    ),

    [_ADJUST3] = LAYOUT_planck_grid(
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
      KC_NO,   KC_TRNS, AU_ON,   AU_OFF,  AU_TOG,  KC_TRNS, KC_TRNS, RGB_TOG, RGB_VAI, RGB_VAD, KC_TRNS, RESET,
      KC_TRNS, KC_TRNS, MU_ON,   MU_OFF,  MU_TOG,  KC_TRNS, KC_TRNS, RGB_MOD, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_HELPER4] = LAYOUT_planck_grid(
      ST_EMOJ, MIDI,    ORYXKEY, DMPLAY1, DMPLAY2, TRACKER, KC_NO,   KC_NO,   KC_NO,   KC_NO,   DMRSTOP, KC_NO,
      MACREC,  ST_ESPK, ST_ESHG, KC_NO,   DMRSTOP, ST_GO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DMPLAY1, DMPLAY2,
      KC_CAPS, KC_NO,   KC_NO,   KC_NO,   ST_TPST, KC_NO,   ST_MADI, ST_MV,   KC_NO,   KC_MPLY, KC_NO,   KC_NO,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, ST_SHOT
    ),

    [_TRACKER5] = LAYOUT_planck_grid(
      BASE,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      TRACKR2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_TRACKER6] = LAYOUT_planck_grid(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
      KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, TR_ROWU, TR_ROWD, KC_TRNS
    ),

    [_MACRO7] = LAYOUT_planck_grid(
      KC_TRNS, KC_TRNS, KC_TRNS, DMREC1,  DMREC2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DMREC1,  DMREC2,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_MIDI8] = LAYOUT_planck_grid(
      BASE,    MI_OCTD, MI_OCTU, MI_TRNSD,MI_TRNSU,KC_TRNS, MI_VEL_3,MI_VEL_5,MI_VEL_8,MI_VEL_9,MI_VEL_10,KC_TRNS,
      KC_TRNS, KC_TRNS, MI_Cs,   MI_Ds,   KC_TRNS, MI_Fs,   MI_Gs,   MI_As,   KC_TRNS, MI_Cs_1, MI_Ds_1, KC_TRNS,
      MIDI2,   MI_C,    MI_D,    MI_E,    MI_F,    MI_G,    MI_A,    MI_B,    MI_C_1,  MI_D_1,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_MIDI9] = LAYOUT_planck_grid(
      KC_TRNS, MI_OCTD, MI_OCTU, KC_TRNS, KC_TRNS, KC_TRNS, MI_VEL_3,MI_VEL_5,MI_VEL_8,MI_VEL_9,MI_VEL_10,KC_TRNS,
      KC_TRNS, KC_TRNS, MI_Cs_1, MI_Ds_1, KC_TRNS, MI_Fs_1, MI_Gs_1, MI_As_1, KC_TRNS, MI_Cs_2, MI_Ds_2, KC_TRNS,
      KC_TRNS, MI_C_1,  MI_D_1,  MI_E_1,  MI_F_1,  MI_G_1,  MI_A_1,  MI_B_1,  MI_C_2,  MI_D_2,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
/*
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
*/

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER1] = {
      { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {  0,  0,  0}, 
      {  0,  0,  0}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {  0,  0,  0}, 
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},                {215,246,201}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}
    },

    [_RAISE2] = {
      {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {125,250,252}, {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {125,250,252}, {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {125,250,252}, {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},                {  0,  0,  0}, { 80,255,255}, {125,250,252}, {125,250,252}, {  0,  0,  0}
    },

    [_ADJUST3] = {
      {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {125,250,252},
      {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252},
      {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252},
      {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252},                {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}
    },

    [_HELPER4] = {
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255},
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255},
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255},
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255},                { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}
    },

    [_TRACKER5] = {
      { 27,126,255}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},
      { 27,126,255}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},
      {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},
      {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},                {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}
    },

    [_TRACKER6] = {
      {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75},
      {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {133,255, 75},
      {133,255, 75}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {133,255, 75},
      {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75},                {133,255, 75}, {133,255, 75}, {250,159,255}, {250,159,255}, {133,255, 75}
    },

    [_MACRO7] = {
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,255}, {  0,  0,255},
      {250,159,255}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},                {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}
    }
};

void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_OSX);
}

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
    case _LOWER1:
      set_layer_color(_LOWER1);
      break;
    case _RAISE2:
      set_layer_color(_RAISE2);
      break;
    case _ADJUST3:
      set_layer_color(_ADJUST3);
      break;
    case _HELPER4:
      set_layer_color(_HELPER4);
      break;
    case _TRACKER5:
      set_layer_color(_TRACKER5);
      break;
    case _TRACKER6:
      set_layer_color(_TRACKER6);
      break;
    case _MACRO7:
      set_layer_color(_MACRO7);
      break;
    case _MIDI8:
      set_layer_color(_MIDI8);
      break;
    case _MIDI9:
      set_layer_color(_MIDI9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE
    )
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_EMOJ:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_SPACE))));

    }
    break;
    case ST_SHOT:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_4))));

    }
    break;
    case ST_TPST:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_V)))));

    }
    break;
    case ST_GO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G));
      SEND_STRING(SS_TAP(X_O));
      SEND_STRING(SS_TAP(X_SLASH));
    }
    break;
    case ST_ESPK:
    if (record->event.pressed) {
      send_string("zsparkle");
    }
    break;
    case ST_ESHG:
    if (record->event.pressed) {
      send_string("zshrug");
    }
    break;
    case ST_MV:
    if (record->event.pressed) {
      send_string("maddievision");
    }
    break;
    case ST_MADI:
    if (record->event.pressed) {
      send_string("maddie");
    }
    break;
    case ST_HEX:
    if (record->event.pressed) {
      send_string("0x");
    }
    break;
    case ST_ROCK:
    if (record->event.pressed) {
      send_string("=>");
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

// uint32_t layer_state_set_user(uint32_t state) {
//     return update_tri_layer_state(state, _LOWER1, _RAISE2, _ADJUST3);
// }
