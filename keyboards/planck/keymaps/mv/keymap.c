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
#include <string.h>
#include <printf.h>

#include <LUFA/Drivers/USB/USB.h>
#include "midi.h"
#include "qmk_midi.h"

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
  ST_ROCK,
  ENTBASE,
  CONSOLE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _HELPER,
  _TRACKER,
  _TRACKER2,
  _MACRO,
  _MIDI,
  _MIDI2,
  _SPECIAL,
  _CONSOLE,
  _L_MOD_CMD, //light only
};

#define BASE    TO(_BASE)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)
#define HELPER  MO(_HELPER)
#define TRACKER TO(_TRACKER)
#define TRACKR2 MO(_TRACKER2)
#define MACREC  MO(_MACRO)
#define MIDI    TO(_MIDI)
#define MIDI2   MO(_MIDI2)
#define SPECIAL TO(_SPECIAL)

#define RSH_RGT RSFT_T(KC_RGHT)

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

#define SEL_ALL LGUI(KC_A)
#define TR_ROWU LGUI(LSFT(KC_UP))
#define TR_ROWD LGUI(LSFT(KC_DOWN))

int mod_is_down = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      KC_LCTL, HELPER,  KC_LALT, KC_LGUI, LOWER,  KC_SPC,   KC_NO,   RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
      KC_TILD, KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_UNDS, KC_DEL, 
      KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_PEQL, KC_PPLS, 
      RAISE,   KC_7,    KC_8,    KC_9,    KC_0,    KC_F11,   KC_NO,  KC_NO,   KC_LCBR, KC_RCBR, KC_ASTR, KC_PMNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   ADJUST,  KC_GRV,  ST_ROCK, KC_PIPE, KC_BSLS
    ),

    [_RAISE] = LAYOUT_planck_grid(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_NO,   HEX_E,   HEX_F,   KC_7,    KC_8,    KC_9,    KC_PSLS, KC_DEL,
      KC_NO,   KC_DLR,  KC_PERC, KC_CIRC, KC_NO,   HEX_C,   HEX_D,   KC_4,    KC_5,    KC_6,    KC_PPLS, KC_NO, 
      KC_TRNS, KC_AMPR, KC_ASTR, ST_HEX,  KC_NO,   HEX_A,   HEX_B,   KC_1,    KC_2,    KC_3,    KC_PPLS, KC_PENT,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJUST,  KC_TRNS, KC_NO,   KC_TRNS, KC_0,    KC_PDOT, KC_ASTR, KC_PENT
    ),

    [_ADJUST] = LAYOUT_planck_grid(
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
      KC_NO,   KC_TRNS, AU_ON,   AU_OFF,  AU_TOG,  KC_TRNS, KC_TRNS, RGB_TOG, RGB_VAI, RGB_VAD, KC_TRNS, RESET,
      KC_TRNS, KC_TRNS, MU_ON,   MU_OFF,  MU_TOG,  KC_TRNS, KC_TRNS, RGB_MOD, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_HELPER] = LAYOUT_planck_grid(
      ST_EMOJ, MIDI,    ORYXKEY, DMPLAY1, DMPLAY2, TRACKER, CONSOLE, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, SPECIAL,
      MACREC,  ST_ESPK, ST_ESHG, KC_NO,   DMRSTOP, ST_GO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DMPLAY1, DMPLAY2,
      KC_TRNS, ST_SHOT, KC_NO,   KC_NO,   ST_TPST, KC_NO,   ST_MADI, ST_MV,   KC_NO,   KC_UP,   KC_NO,   KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_TRACKER] = LAYOUT_planck_grid(
      BASE,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      TRACKR2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_TRACKER2] = LAYOUT_planck_grid(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
      KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, TR_ROWU, TR_ROWD, KC_TRNS
    ),

    [_MACRO] = LAYOUT_planck_grid(
      KC_TRNS, KC_TRNS, KC_TRNS, DMREC1,  DMREC2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DMREC1,  DMREC2,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_MIDI] = LAYOUT_planck_grid(
      BASE,    MI_G_3,  MI_A_3,  MI_B_3,  MI_C_4,  MI_D_4,  MI_E_4,  MI_F_4,  MI_G_4,  MI_A_4,  MI_B_4,  MI_OCTU,
      KC_TRNS, MI_G_2,  MI_A_2,  MI_B_2,  MI_C_3,  MI_D_3,  MI_E_3,  MI_F_3,  MI_G_3,  MI_A_3,  MI_B_3,  MI_OCTD,
      MIDI2,   MI_G_1,  MI_A_1,  MI_B_1,  MI_C_2,  MI_D_2,  MI_E_2,  MI_F_2,  MI_G_2,  MI_A_2,  MI_B_2,  MIDI2,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, MI_VEL_9,MI_SUS
    ),

    [_MIDI2] = LAYOUT_planck_grid(
      KC_TRNS, MI_G_3,  MI_A_3,  MI_As_3, MI_C_4,  MI_D_4,  MI_Ds_4, MI_F_4,  MI_G_4,  MI_A_4,  MI_As_4, MI_OCTU,
      KC_TRNS, MI_G_2,  MI_A_2,  MI_As_2, MI_C_3,  MI_D_3,  MI_Ds_3, MI_F_3,  MI_G_3,  MI_A_3,  MI_As_3, MI_OCTD,
      KC_TRNS, MI_G_1,  MI_A_1,  MI_As_1, MI_C_2,  MI_D_2,  MI_Ds_2, MI_F_2,  MI_G_2,  MI_A_2,  MI_As_2, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, MI_VEL_9,MI_SUS
    ),

    [_SPECIAL]  = LAYOUT_planck_grid(
      BASE,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TILD,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ENTBASE, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJUST,  KC_TRNS, KC_NO,   SEL_ALL, KC_BSPC, KC_TILD, KC_QUES, KC_EXLM
    ),

    [_CONSOLE]  = LAYOUT_planck_grid(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
/*
    [_LAYERx]  = LAYOUT_planck_grid(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
*/

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER] = {
      { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {  0,  0,  0}, 
      {  0,  0,  0}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {  0,  0,  0}, 
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},                {215,246,201}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}
    },

    [_RAISE] = {
      {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {125,250,252}, {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {125,250,252}, {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, {215,246,201}, {215,246,201}, {215,246,201}, {  0,  0,  0}, {125,250,252}, {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {215,246,201}, {  0,  0,  0}, 
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},                {  0,  0,  0}, { 80,255,255}, {125,250,252}, {125,250,252}, {  0,  0,  0}
    },

    [_ADJUST] = {
      {125,250,252}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, { 80,255,255}, {125,250,252},
      {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252},
      {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252},
      {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252},                {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}, {125,250,252}
    },

    [_HELPER] = {
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, {128,255,255}, {160,255,255}, {160,255,255}, {160,255,255}, { 38,255,255},
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255},
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, {192,255,255}, { 38,255,255}, { 38,255,255},
      { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255}, { 38,255,255},                { 38,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, { 38,255,255}
    },

    [_TRACKER] = {
      { 27,126,255}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},
      { 27,126,255}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},
      {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},
      {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133},                {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}, {163,239,133}
    },

    [_TRACKER2] = {
      {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75},
      {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {133,255, 75},
      {133,255, 75}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {133,255, 75},
      {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75}, {133,255, 75},                {133,255, 75}, {133,255, 75}, {250,159,255}, {250,159,255}, {133,255, 75}
    },
    
    [_MACRO] = {
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,255}, {  0,  0,255},
      {250,159,255}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},                {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}
    },

    [_MIDI] = {
      { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, {128,255,255}, {128,255,255}, {128,255,255}, { 64,255,255},
      { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, {128,255,255}, {128,255,255}, {128,255,255}, { 64,255,255},
      { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, {128,255,255}, {128,255,255}, {128,255,255}, { 64,255,255},
      { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255},                { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}, { 64,255,255}
    },

    [_MIDI2] = {
      {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {192,255,255},
      {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {192,255,255},
      {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {192,255,255},
      {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255},                {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}
    },

    [_SPECIAL] = {
      {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0},
      {  0,  0,  0}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, {  0,  0,  0},
      {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0}, { 80,255,255}, {  0,  0,  0},
      {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0},                {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}
    },

    [_CONSOLE] = {
      {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255},
      {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255},
      {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255},
      {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255},                {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}, {  0,  0,255}
    },


    [_L_MOD_CMD] = {
      {  0,255,255}, {160,255,255}, {160,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
      {  0,255,255}, { 32,255,255}, { 32,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
      {  0,255,255}, { 32,255,255}, {224,255,255}, {224,255,255}, {224,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},
      {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255},                {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}, {  0,255,255}
    },
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

void rgb_matrix_set_hsv_color_all(int h, int s, int v) {
    HSV hsv = {
      .h = h,
      .s = s,
      .v = v,
    };
    RGB rgb = hsv_to_rgb( hsv );
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color_all( f * rgb.r, f * rgb.g, f * rgb.b );
}

enum mod_is_down_bits {
  MOD_DOWN_CMD = 1,
  MOD_DOWN_ALT = 2,
  MOD_DOWN_CTRL = 4,
  MOD_DOWN_LSHIFT = 8,
  MOD_DOWN_RSHIFT = 16,
};

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  if (mod_is_down) {
    switch (mod_is_down) {
      case MOD_DOWN_CMD:
      set_layer_color(_L_MOD_CMD);
      break;
      case MOD_DOWN_LSHIFT:
      case MOD_DOWN_RSHIFT:
      rgb_matrix_set_hsv_color_all(32, 255, 255);
      break;
      case MOD_DOWN_ALT:
      rgb_matrix_set_hsv_color_all(128, 255, 255);
      break;
      case MOD_DOWN_CTRL:
      rgb_matrix_set_hsv_color_all(64, 255, 255);
      break;
      default: // more than one down
      rgb_matrix_set_hsv_color_all(192, 255, 255);
    }
    return;
  }
  switch (biton32(layer_state)) {
    case _LOWER:
      set_layer_color(_LOWER);
      break;
    case _RAISE:
      set_layer_color(_RAISE);
      break;
    case _ADJUST:
      set_layer_color(_ADJUST);
      break;
    case _HELPER:
      set_layer_color(_HELPER);
      break;
    case _TRACKER:
      set_layer_color(_TRACKER);
      break;
    case _TRACKER2:
      set_layer_color(_TRACKER2);
      break;
    case _MACRO:
      set_layer_color(_MACRO);
      break;
    case _MIDI:
      set_layer_color(_MIDI);
      break;
    case _MIDI2:
      set_layer_color(_MIDI2);
      break;
    case _SPECIAL:
      set_layer_color(_SPECIAL);
      break;
    case _CONSOLE:
      set_layer_color(_CONSOLE);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE
    )
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool console_enabled = false;

#define CONSOLE_MAX 256

char console_buffer[256];
char console_last[256] = "";
size_t console_last_index = 0;
size_t console_index = 0;
enum console_states {
  CINPUT,
};

void console_prompt(void) {
  send_string("> ");
}
void enter_console(void) {
  console_enabled = true;
  layer_move(_CONSOLE);
  send_string("--------\n\nconsole VISION v0.01\n\nwelcome!\n\n");
  console_prompt();
}

void console_command(char buf[]) {
  send_string("\n");
  if (strcmp(buf, "exit") == 0) {
    send_string("goodbye!\n\n--------\n\n");
    console_enabled = false;
    layer_move(_BASE);
    return;
  } else if (strcmp(buf, "help") == 0) {
    send_string("i can't help you now... sorry!\n\n");
  } else if (strcmp(buf, "send_midi 60") == 0) {
    midi_send_noteon(&midi_device, 0, 60, 127); 
  } else {
    char msg[128];
    sprintf(msg, "unknown command: %s\n\n", buf);
    send_string(msg);
  }
  console_prompt();
}

void console_bspace(int count) {
  for (int i = 0; i < count; ++i) {
    SEND_STRING(SS_TAP(X_BSPACE));
  }
}

bool process_mv_console(uint16_t keycode, keyrecord_t *record) {
  char inp = 0;
  if (record->event.pressed) {
    if (keycode >= KC_A && keycode <= KC_Z) {
      inp = keycode - KC_A + 'a';
    } else if (keycode >= KC_1 && keycode <= KC_9) {
      inp = keycode - KC_1 + '1';
    } else {
      switch (keycode) {
        case KC_0:
        inp = '0';
        break;
        case KC_ENTER:
        console_buffer[console_index] = 0;
        strcpy(console_last, console_buffer);
        console_last_index = console_index;
        console_index = 0;
        console_command(console_buffer);
        return false;
        break;
        case KC_BSPACE:
        if (console_index <= 0) {
          console_index = 0;
          return false;
        }
        console_index--;
        break;
        case KC_SPACE:
        inp = ' ';
        break;
        case KC_UNDERSCORE:
        inp = '_';
        break;
        case KC_UP:
        strcpy(console_buffer, console_last);
        console_bspace(console_index);
        send_string(console_buffer);
        console_index = console_last_index;
        return false;
        break;
        // disabled keys
        case KC_ESCAPE:
        case KC_TAB:
        case KC_LEFT:
        case KC_DOWN:
        case KC_RIGHT:
        break;
        return false;
      }
    }
    if (inp) { // leave space for string termination
      if (console_index >= CONSOLE_MAX - 2) {
        return false; //prevent key send
      } else {
        console_buffer[console_index++] = inp;
      }
    }
  }
  return true;
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LGUI:
    if (record->event.pressed) {
      mod_is_down |= MOD_DOWN_CMD;
    } else {
      mod_is_down &= ~MOD_DOWN_CMD;
    }
    break;
    case KC_LSHIFT:
    if (record->event.pressed) {
      mod_is_down |= MOD_DOWN_LSHIFT;
    } else {
      mod_is_down &= ~MOD_DOWN_LSHIFT;
    }
    break;
    case KC_RSHIFT:
    if (record->event.pressed) {
      mod_is_down |= MOD_DOWN_RSHIFT;
    } else {
      mod_is_down &= ~MOD_DOWN_RSHIFT;
    }
    break;
    case KC_LALT:
    if (record->event.pressed) {
      mod_is_down |= MOD_DOWN_ALT;
    } else {
      mod_is_down &= ~MOD_DOWN_ALT;
    }
    break;
    case KC_LCTRL:
    if (record->event.pressed) {
      mod_is_down |= MOD_DOWN_CTRL;
    } else {
      mod_is_down &= ~MOD_DOWN_CTRL;
    }
    break;
  }

  if (console_enabled) {
    return process_mv_console(keycode, record);
  }

  switch (keycode) {
    case CONSOLE:
    if (record->event.pressed) {
      enter_console();
      return false;
    }
    break;
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
    case ENTBASE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ENTER));
      layer_move(_BASE);
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
        if (IS_LAYER_ON(_RAISE)) {
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
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
