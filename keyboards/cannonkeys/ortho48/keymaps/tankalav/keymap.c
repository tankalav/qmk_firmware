/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _FUN 2
#define _NUM 3
#define _HEX 4
#define _TG 5
#define _WM 6

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
    * ,-----------------------------------------------------------------------------------.
    * |  Tab |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc/C|  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  '   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Ls/( |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   | Rs/) |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Ctrl |  Alt | Super|  Num |    Space    |Ent/Fn| Super| Alt  | Ctrl |WM/Del|
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_ortho_4x12(KC_TAB        , KC_Q   , KC_W   , KC_E   , KC_R    , KC_T   , KC_Y   , KC_U            , KC_I   , KC_O   , KC_P   , KC_BSPC,
                                  LCTL_T(KC_ESC), KC_A   , KC_S   , KC_D   , KC_F    , KC_G   , KC_H   , KC_J            , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
                                  KC_LSPO       , KC_Z   , KC_X   , KC_C   , KC_V    , KC_B   , KC_N   , KC_M            , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC,
                                  XXXXXXX       , KC_LCTL, KC_LALT, KC_LGUI, MO(_NUM), KC_SPC , KC_SPC , LT(_FUN, KC_ENT), KC_RGUI, KC_RALT, KC_RCTL, LT(_WM, KC_DEL)),
    /* COLEMAK
    * ,-----------------------------------------------------------------------------------.
    * |  Tab |  Q   |  W   |  F   |  P   |  B   |  J   |  L   |  U   |  Y   |  ;   | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc/C|  A   |  R   |  S   |  T   |  G   |  M   |  N   |  E   |  I   |  O   |  '   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Ls/( |  Z   |  X   |  C   |  D   |  V   |  K   |  H   |  ,   |  .   |  /   | RS/) |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |  WM  | Ctrl |  Alt | Super|  Num |    Space    | Func | Super| Alt  | Ctrl | Del  |
    * `-----------------------------------------------------------------------------------'
    */
    [_COLEMAK] = LAYOUT_ortho_4x12(KC_TAB        , KC_Q   , KC_D   , KC_F   , KC_P    , KC_B   , KC_J   , KC_L            , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
                                   LCTL_T(KC_ESC), KC_A   , KC_R   , KC_S   , KC_T    , KC_G   , KC_M   , KC_N            , KC_E   , KC_I   , KC_O   , KC_QUOT,
                                   KC_LSPO       , KC_Z   , KC_X   , KC_C   , KC_D    , KC_V   , KC_K   , KC_H            , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC,
                                   XXXXXXX       , KC_LCTL, KC_LALT, KC_LGUI, MO(_NUM), KC_SPC , KC_SPC , LT(_FUN, KC_ENT), KC_RGUI, KC_RALT, KC_RCTL, LT(_WM, KC_DEL)),


    /* Functions
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |      | Home | PgDn | PgUp | End  |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |      | Left | Down |  Up  | Right|      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |Toggle|             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FUN] = LAYOUT_ortho_4x12(XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, XXXXXXX,
                               XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
                               XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_TG), XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
    /* Numbers
    * ,-----------------------------------------------------------------------------------.
    * |  ~   |  [   |      |      |  ]   |      |  |   |  7   |  8   |  9   |  ,   |  =   |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |  `   |  {   | Hex  | Shft |  }   |      |  \   |  4   |  5   |  6   |  *   |  /   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  <   |      |      |  >   |      |  _   |  1   |  2   |  3   |  -   |  +   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |    Space    |  0   |  .   |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUM] = LAYOUT_ortho_4x12(KC_TILD, KC_LBRC, XXXXXXX           , XXXXXXX, KC_RBRC, XXXXXXX, KC_PIPE, KC_7   , KC_9   , KC_9   , KC_COMM, KC_EQL ,
                               KC_GRV , KC_LCBR, LM(_HEX, MOD_LSFT), KC_LSFT, KC_RCBR, XXXXXXX, KC_BSLS, KC_4   , KC_5   , KC_6   , KC_ASTR, KC_SLSH,
                               XXXXXXX, KC_LABK, XXXXXXX           , XXXXXXX, KC_RABK, XXXXXXX, KC_UNDS, KC_1   , KC_2   , KC_3   , KC_MINS, KC_PLUS,
                               XXXXXXX, XXXXXXX, XXXXXXX           , XXXXXXX, _______, _______, _______, KC_0   , KC_DOT , XXXXXXX, XXXXXXX, XXXXXXX),

    /* Toggles
    * ,-----------------------------------------------------------------------------------.
    * |      | Qwer |      |      |      |      |      | Vol+ | Next | Bri+ |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Caps |      |      |      |      |      |      | VolM | Play |      |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      | Cole |      |      |      | Vol- | Prev | Bri- |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_TG] = LAYOUT_ortho_4x12(XXXXXXX, DF(_QWERTY), XXXXXXX, XXXXXXX     , XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_MNXT, KC_BRIU, XXXXXXX, XXXXXXX,
                              KC_CAPS, XXXXXXX    , XXXXXXX, XXXXXXX     , XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX    , XXXXXXX, DF(_COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MPRV, KC_BRID, XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX    , XXXXXXX, XXXXXXX     , _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
    /* Window Management
    * ,-----------------------------------------------------------------------------------.
    * |      | Next | Wk 9 | Wk 8 | Wk 7 |      |      |      |      |      |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |Recent| Wk 6 | Wk 5 | Wk 4 |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      | Prev | Wk 3 | Wk 2 | Wk 1 |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |Focus |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_WM] = LAYOUT_ortho_4x12(XXXXXXX, G(KC_RBRC), G(KC_9), G(KC_8), G(KC_7)  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, G(KC_TAB) , G(KC_6), G(KC_5), G(KC_4)  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, G(KC_LBRC), G(KC_3), G(KC_2), G(KC_1)  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX   , XXXXXXX, XXXXXXX, G(KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______)
};
