/* Copyright 2021 HellSingCoder
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


#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
    _SHIFTLAYER,
    _MINECRAFT
};

// clang-format off
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_BSPC_DEL,
    KC_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | ESPA | /Enter  /       \Space \  |Enter | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

// [_QWERTY] = LAYOUT(
//     KC_ESC,         KC_1,           KC_2,           KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
//     KC_TAB,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BACKSLASH,
//     KC_CAPS_LOCK,   HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN,   KC_QUOT,
//     KC_LSFT,        KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,     KC_BTN1,                KC_BTN2,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                                     KC_LGUI,        KC_LALT, KC_LCTL, KC_SPC, LT(_LOWER,KC_ENT),        LT(_RAISE,KC_SPC), KC_ENTER, KC_RCTL, KC_RALT, KC_RGUI
// ),

[_QWERTY] = LAYOUT(
    KC_ESC,         KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                       KC_6,    KC_7,    KC_8,     KC_9,   KC_0,       KC_BSPC,
    KC_TAB,         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                       KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,       ES_BSLS,
    KC_CAPS_LOCK,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,     KC_L,   ES_SCLN,    ES_QUOT,
    KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,     KC_BTN1,                KC_BTN2,  KC_N,    KC_M,    KC_COMM,  KC_DOT, ES_SLSH,    LT(_SHIFTLAYER, KC_RSFT),
                KC_LGUI,    KC_RCTL,    KC_LCTL,    KC_SPC, LT(_LOWER,KC_ENT),   LT(_RAISE,KC_SPC), KC_ENTER, KC_RCTL, KC_RALT, C(KC_S)
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  *   |   $  |   %  |   {  |   }  |   <  |                    |   >  |   -  |   _  |  #   |   ~  |       |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  *   |  €   |   [  |  ]   |  !   |-------.    ,-------|  ?   |   =  |  +   |  "   |  /   |       |
 * |------+------+------+------+------+------|CLICK1 |    |CLICK2 |------+------+------+------+------+------|
 * |      |      |  ¬   |  [   |  ]  |  ¡  |-------|    |-------|   ¿   |   ^   |  &   |  ç   |  ñ   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /Raise  /       \Raise \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

// LOWER con modificaciones 
[_LOWER] = LAYOUT(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    ES_EURO,  ES_DLR,   ES_PERC,  ES_LCBR,  ES_RCBR,  ES_LABK,                          ES_RABK,  ES_MINS,  ES_UNDS,  ES_HASH,  ES_TILD,  XXXXXXX,
    XXXXXXX,  ES_ASTR,  ES_AT,  ES_LPRN,  ES_RPRN,  ES_EXLM,                          ES_QUES,  ES_EQL,   ES_PLUS,  ES_DQUO,  ES_SLSH,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  ES_NOT,   ES_LBRC,  ES_RBRC,  ES_IEXL,  KC_F13,      XXXXXXX,  ES_IQUE,  ES_CIRC,  ES_AMPR,  ES_CCED,  ES_NTIL,  XXXXXXX,
                        KC_LALT, _______, _______, _______, _______,           _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* SHIFTLAYER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | SUPR |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |  º   |  |   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |   ´  |  :   |  "   |
 * |------+------+------+------+------+------| ADJUST|    |      |-------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |  <   |   >  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_SHIFTLAYER] = LAYOUT(
    _______, KC_EXLM, ES_AT, ES_HASH, KC_DLR, KC_PERC,                           ES_CIRC, ES_AMPR, ES_ASTR, ES_LPRN, ES_RPRN, KC_DELETE,
    XXXXXXX, KC_PEQL, KC_1, KC_2, KC_3, KC_PSLS,                           XXXXXXX, XXXXXXX, XXXXXXX, ES_GRV, ES_MORD, ES_PIPE,
    XXXXXXX, KC_PCMM, KC_4, KC_5, KC_6, KC_PAST,                           XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, ES_COLN, ES_DQUO,
    XXXXXXX, KC_PDOT, KC_7, KC_8, KC_9, KC_PMNS,  TO(_ADJUST),       XXXXXXX,  XXXXXXX, XXXXXXX, ES_LABK, ES_RABK, ES_QUES, XXXXXXX,
                    XXXXXXX, KC_0, KC_PPLS, KC_PENT, _______,             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | MUTE | CALC | BSEA | BHOM | BBAC | BFOR |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | VOLU |      |      |  UP  |      |      |                    |  F1  |  F2  |  F3  |  F4  | PGUP |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | VOLD |      | LEFT | DOWN | RIGHT|      |-------.    ,-------|  F5  |  F6  |  F7  |  F8  | PDDO |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | SLEP |      |      |      |      |      |-------|    |-------|  F9  | F10  | F11  | F12  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | PREVI | NEXT | STOP | /       /       \      \  |      | PRIN | HOME | HOME |
 *            |      |      |      | PLAY  |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    KC_MUTE, KC_CALC, KC_WSCH, KC_WHOM, KC_WBAK, KC_WFWD,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    KC_VOLU, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,                           KC_F1, KC_F2, KC_F3, KC_F4, KC_PGUP, XXXXXXX,
    KC_VOLD, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,                           KC_F5, KC_F6, KC_F7, KC_F8, KC_PGDN, XXXXXXX,
    KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  TO(_ADJUST),       XXXXXXX,  KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, KC_RSFT,
                    XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, _______,             _______, _______, KC_PSCR, KC_HOME, KC_HOME
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | BOOT |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | +SPD |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | -SPD | MODE |-------.    ,-------| MODE |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |ON/OFF|-------|    |-------|      |      |      |      |      | BOOT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    QK_BOOT, RGB_M_P , RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN,                        RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_GAME),
    XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_MOD,                           RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_MINECRAFT),
    TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_GAME] = LAYOUT(
    KC_ESC,         KC_1,           KC_2,           KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
    KC_TAB,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BACKSLASH,
    KC_CAPS_LOCK,   KC_A,           KC_S,           KC_D,    KC_F,      KC_G,                                       KC_H, KC_J, KC_K, KC_L, KC_SCLN,   KC_QUOT,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,     KC_BTN1,                KC_BTN2,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                    KC_LGUI,        KC_LALT, KC_LCTL, KC_SPC, KC_ENTER,        LT(_RAISE,KC_SPC), KC_ENTER, KC_RCTL, KC_RALT, C(KC_S)
),

[_MINECRAFT] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_ACCEL2, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_H, XXXXXXX, XXXXXXX, KC_T,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_A, KC_S, XXXXXXX, KC_F, KC_G,                           XXXXXXX, KC_F3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_B, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)



//                                  INICIO LAYERS ENTRADA EN INGLES


// #include QMK_KEYBOARD_H

// enum sofle_layers {
//     /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
//     _QWERTY = 0,
//     _LOWER,
//     _RAISE,
//     _ADJUST,
//     _GAME,
// };

// // clang-format off
// enum custom_keycodes {
//     KC_QWERTY = SAFE_RANGE,
//     KC_GAMING,
//     KC_LOWER,
//     KC_RAISE,
//     KC_ADJUST,
//     KC_PRVWD,
//     KC_NXTWD,
//     KC_LSTRT,
//     KC_LEND,
//     KC_DLINE,
//     KC_BSPC_DEL,
//     KC_LAYER
// };

// // Left-hand home row mods
// // #define HOME_A LGUI_T(KC_A)
// // #define HOME_S LALT_T(KC_S)
// // #define HOME_D LSFT_T(KC_D)
// // #define HOME_F LCTL_T(KC_F)

// // // Right-hand home row mods
// // #define HOME_J RCTL_T(KC_J)
// // #define HOME_K RSFT_T(KC_K)
// // #define HOME_L LALT_T(KC_L)
// // #define HOME_SCLN RGUI_T(KC_SCLN)

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * QWERTY
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR | ESPA | /Enter  /       \Space \  |Enter | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */

// // [_QWERTY] = LAYOUT(
// //     KC_ESC,         KC_1,           KC_2,           KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
// //     KC_TAB,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BACKSLASH,
// //     KC_CAPS_LOCK,   HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN,   KC_QUOT,
// //     KC_LSFT,        KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,     KC_BTN1,                KC_BTN2,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
// //                                     KC_LGUI,        KC_LALT, KC_LCTL, KC_SPC, LT(_LOWER,KC_ENT),        LT(_RAISE,KC_SPC), KC_ENTER, KC_RCTL, KC_RALT, KC_RGUI
// // ),

// [_QWERTY] = LAYOUT(
//     KC_ESC,         KC_1,           KC_2,           KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
//     KC_TAB,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BACKSLASH,
//     KC_CAPS_LOCK,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,   KC_QUOT,
//     KC_LSFT,        KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,     KC_BTN1,                KC_BTN2,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                                     KC_LGUI,        KC_LCTL, KC_LCTL, KC_SPC, LT(_LOWER,KC_ENT),        LT(_RAISE,KC_SPC), KC_ENTER, KC_RCTL, KC_RALT, C(KC_S)
// ),

// /* LOWER
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |  *   |   $  |   %  |   ^  |   &  |   <  |                    |   >  |   #  |   ~  |  -_  |   _  |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |  (   |  )   |   [  |  ]   |  !   |-------.    ,-------|  ?   |  {   |  }   |  "   |  /?  |   '  |
//  * |------+------+------+------+------+------|CLICK1 |    |CLICK2 |------+------+------+------+------+------|
//  * |      |      | UNDO |PASTE | COPY | CUT  |-------|    |-------|  +   |  =   |  \   |  /   |      |      |
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            |      |      |      |      | /Raise  /       \Raise \  |      |      |      |      |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// // [_LOWER] = LAYOUT(
// //     _______,  _______,  _______,  _______,  _______,  _______,                          _______,  _______,  _______,  _______,  _______,  _______,
// //     KC_ASTR,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_LT,                            KC_GT,    KC_MINS,  KC_UNDS,  KC_HASH,  KC_TILD,  _______,
// //     _______,  KC_LPRN,  KC_RPRN,  KC_LBRC,  KC_RBRC,  KC_EXLM,                          KC_QUES,  KC_LCBR,  KC_RCBR,  KC_DQUO,  KC_SLSH,  _______,
// //     _______,  _______,  KC_UNDO,  KC_PASTE,  KC_COPY,  KC_CUT,  _______,      _______,  KC_PLUS,  KC_EQL,   KC_BSLS,  KC_SLSH,  _______,  _______,
// //                         _______, _______, _______, _______, XXXXXXX,           XXXXXXX, _______, _______, _______, _______
// // ),

// // LOWER con modificaciones 
// [_LOWER] = LAYOUT(
//     _______,  _______,  _______,  _______,  _______,  _______,                          _______,  _______,  _______,  _______,  _______,  _______,
//     _______,  KC_DLR,   KC_PERC,  KC_LCBR,  KC_RCBR,  KC_LT,                            KC_GT,    KC_HASH,  KC_TILD,  KC_MINS,  KC_UNDS,  _______,
//     _______,  KC_ASTR,  XXXXXXX,  KC_LPRN,  KC_RPRN,  KC_EXLM,                          KC_QUES,  KC_CIRC,  KC_AMPR,  KC_DQUO,  KC_SLSH,  _______,
//     _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,  _______,      _______,  KC_PLUS,  KC_EQL,   KC_BSLS,  KC_SLSH,  _______,  _______,
//                         _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
// ),

// /* RAISE
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |      |      |  UP  |      |      |                    |  F1  |  F2  |  F3  |  F4  | PGUP |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |      | LEFT | DOWN | RIGHT|      |-------.    ,-------|  F5  |  F6  |  F7  |  F8  | PDDO |      |
//  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
//  * |      |      |      |      |      |      |-------|    |-------|  F9  | F10  | F11  | F12  |      |      |
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            |      |      |ADJUST|      | /       /       \      \  |      | PRIN | HOME | HOME |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [_RAISE] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, KC_UP, _______, _______,                           KC_F1, KC_F2, KC_F3, KC_F4, KC_PGUP, _______,
//     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                           KC_F5, KC_F6, KC_F7, KC_F8, KC_PGDN, _______,
//     _______, _______, _______, _______, _______, _______,  TO(_ADJUST),       _______,  KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
//                     _______, _______, _______, _______, _______,             _______, _______, KC_PSCR, KC_HOME, KC_HOME
// ),
// /* RAISE
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * | BOOT |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |      |      |      | +SPD |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |      |      |      | -SPD | MODE |-------.    ,-------| MODE |      |      |      |      |      |
//  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
//  * |QWERTY|      |      |      |      |ON/OFF|-------|    |-------|      |      |      |      |      | BOOT |
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            |      |      |      |      | /       /       \      \  |      |      |      |      |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [_ADJUST] = LAYOUT(
//     QK_BOOT, RGB_M_P , RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN,                        RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______,
//     _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,                           _______, _______, _______, _______, _______, TO(_GAME),
//     _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_MOD,                           RGB_RMOD, _______, _______, _______, _______, _______,
//     TO(_QWERTY), _______, _______, _______, _______, RGB_TOG, _______,     _______, _______, _______, _______, _______, _______, QK_BOOT,
//                     _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______
// ),

// [_GAME] = LAYOUT(
//     KC_ESC,         KC_1,           KC_2,           KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
//     KC_TAB,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BACKSLASH,
//     KC_CAPS_LOCK,   KC_A,           KC_S,           KC_D,    KC_F,      KC_G,                                       KC_H, KC_J, KC_K, KC_L, KC_SCLN,   KC_QUOT,
//     KC_LSFT,        KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,     KC_BTN1,                KC_BTN2,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                                     KC_LGUI,        KC_LALT, KC_LCTL, KC_SPC, KC_ENTER,        LT(_RAISE,KC_SPC), KC_ENTER, KC_RCTL, KC_RALT, C(KC_S)
// )


//                                          FIN LAYERS PARA ENTRADA INGLES

};
// clang-format on

#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM hell_logo[] = {0x00, 0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x78, 0x1e, 0x06, 0x00, 0x0c, 0x1c, 0x18, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x01, 0x03, 0x07, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x70, 0x60, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x07, 0x03, 0x01, 0x00, 0xf8, 0xf8, 0x80, 0x80, 0x80, 0xf8, 0xf8, 0x00, 0x80, 0xc0, 0xc0, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0xf8, 0xf8, 0x00, 0xf8, 0xf8, 0x00, 0x08, 0x38, 0x08, 0x00, 0x38, 0x08, 0x30, 0x08, 0x38, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00, 0x0f, 0x1f, 0x1a, 0x12, 0x1a, 0x1b, 0x0b, 0x00, 0x1f, 0x1f, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(hell_logo, sizeof(hell_logo));
}

/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* Smart Backspace Delete */

bool            shift_held = false;
static uint16_t held_shift = 0;

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _ADJUST:
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
       
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;

            /* Smart Backspace Delete */

        case KC_RSFT:
        case KC_LSFT:
            shift_held = record->event.pressed;
            held_shift = keycode;
            break;
        case KC_BSPC_DEL:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_DEL);
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
                if (shift_held) {
                    register_code(held_shift);
                }
            }
            return false;


            /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

            /* KEYBOARD PET STATUS END */
    }
    return true;
}

/* #ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (shift_held) {
                tap_code(KC_LEFT);
            } else {
                tap_code(KC_RIGHT);
            }
        } else {
            if (shift_held) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_LEFT);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            if (shift_held) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_DOWN);
            }
        } else {
            if (shift_held) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_UP);
            }
        }
    }
    return true;
}

#endif */


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)){
        case _QWERTY:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_MS_U);
                } else {
                    tap_code(KC_MS_D);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_MS_L);
                } else {
                    tap_code(KC_MS_R);
                }
            }
            break;
        case _RAISE:
            if (index == 0) {
                if (clockwise) {
                        tap_code(KC_WH_U);
                } else {
                        tap_code(KC_WH_D);
                }
            } else if (index == 1) {
                if (clockwise) {
                        tap_code(KC_WH_R);
                } else {
                        tap_code(KC_WH_L);
                }
            }
            break;
        case _LOWER:
            if (index == 0) {
                if (clockwise) {
                        tap_code(KC_UP);
                } else {
                        tap_code(KC_DOWN);
                }
            } else if (index == 1) {
                if (clockwise) {
                        tap_code(KC_RIGHT);
                } else {
                        tap_code(KC_LEFT);
                }
            }
            break;
    }
    return true;
}

#endif



/*
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { //LEEDS XNO0


    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:

                rgb_matrix_set_color(i, RGB_BLUE);
                if (host_keyboard_led_state().caps_lock) {
                    rgb_matrix_set_color(9, RGB_MAGENTA); 
                } else {
                    rgb_matrix_set_color(9, RGB_BLUE);
                }
                break;            
            case _LOWER:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            case _RAISE:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            case _ADJUST:
                rgb_matrix_set_color(i, RGB_MAGENTA);
                break;

        }
    }
    return false;
}
*/
