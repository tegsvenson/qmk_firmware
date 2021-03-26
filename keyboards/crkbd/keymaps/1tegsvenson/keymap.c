/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum planck_layers
{
  _QWERTYw,
  _QWERTYm,
  _COLEMAKw,
  _COLEMAKm,
  _GAMEMODE,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _EXTRA,
  _EXTRA2,
  _SHIFT,
  _SHIFTc,
  _MACRRO,
  _MACKEY
};

enum planck_keycodes
{
  QWERTYw = SAFE_RANGE,
  QWERTYm,
  COLEMAKw,
  COLEMAKm,
  GAMEMODE,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  TAB_DOWN_RTRN,
  TAB_UP_RTRN,
  FF_TEXT,
  CBR_FN,
  BRC_FN,
  PRN_FN,
  HOME_ADD,
  WORK_ADD,
  GMAIL_1,
  GMAIL_2,
  NAME_1,
  NAME_2,
  NAME_3,
  PHONE_1,
  PHONE_2,
  INOWORD,
  FOREXMPL,
  W1R,
  R2W,
  IN_R,
  LARW_R,
  GETLINK,
  COPYTABPASTETAB,
  TABTABTAB,
  LARW_L,
  TOGTERM1,
  TOGTERM2,
  TOGTERM3,
  PASTERMAC,
  MACKEY,
  MACLANG,
  MACPASTE,
  MACNTAB,
  MACPTAB,
  MACCAPTURE1,
  MACCAPTURE2,
  MACCAPTURE3,
  RCHUNK,
  GMAIL_1c,
  W1Rc,
  R2Wc
};
#define KC_QUIT LALT(KC_F4)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRA MO(_EXTRA)
#define EXTRA2 MO(_EXTRA2)
#define SHIFTL MO(_SHIFT)
#define SHIFTcL MO(_SHIFTc)
#define MACRRO MO(_MACRRO)
#define GAMEMODE MO(_GAMEMODE)
#define TAB_PRE LCTL(KC_PGUP)
#define TAB_NXT LCTL(KC_PGDN)
#define TAB_CLS LCTL(KC_W)
#define TAB_RVS LCTL(LSFT(KC_T))
#define ENOTE1 LALT(KC_7)
#define ENOTE2 LALT(KC_6)
#define ENOTE3 LALT(KC_2)
#define ENOTE_M1 LCTL(KC_7)
#define KC_FBCK LALT(KC_LEFT)
#define KC_FFWD LALT(KC_RIGHT)
#define CTRLESC MT(MOD_LCTL, KC_ESC)
//#define SFTQUES MT(MOD_LSFT, LSFT(KC_SLSH))
#define SFTSLSH MT(MOD_LSFT, KC_SLSH)
#define BANDW LGUI(LCTL(KC_C))
#define HCNTRST LALT(LSFT(KC_PSCR))
#define RALTCTL MT(MOD_RCTL, MOD_RALT)
#define MACRODEL LT(_MACRRO, KC_DEL)
#define MACROSPC LT(_MACRRO, KC_SPC)
#define SCTRL_L LCTL(LSFT(KC_LEFT))
#define SCTRL_R LCTL(LSFT(KC_RIGHT))
#define MACLANG LGUI(KC_SPC)            // change language for MAC
#define MACPASTE LGUI(LALT(LSFT(KC_V))) // Paste without formatting: Option+Shift+Command+V
#define MACNTAB LCTL(KC_TAB)            // next tab for MAC
#define MACPTAB LCTL(LSFT(KC_TAB))      // Previous tab for MAC
#define M_TAB_RVS LGUI(LSFT(KC_T))      // Reopen tab for MAC
// #define MACCAPTURE1 LGUI(LSFT(KC_3)) 
// #define MACCAPTURE2 LGUI(LSFT(KC_4)) 
#define MACCAPTURE3 LGUI(LSFT(KC_5))
#define MACCOPY LGUI(KC_C)
#define MACCUT LGUI(KC_X)
#define MACCLOSE LGUI(KC_W)
#define MACBACK LGUI(KC_LEFT)
#define MACFW LGUI(KC_RIGHT)
#define ESCXTRA LT(_EXTRA, KC_ESC)
#define ESCXTRA2 LT(_EXTRA2, KC_ESC)
#define GUIDEL MT(MOD_LGUI, KC_DEL)
#define ALTDEL MT(MOD_LALT, KC_DEL)
#define CTLTAB MT(MOD_LCTL, KC_TAB)
//Tap Dance Declarations
enum
{
  TD_QUOT_DQT = 0,
  TD_LBRC_LCBR,
  TD_RBRC_RCBR,
  TD_LPRN_LABK,
  TD_RPRN_RABK,
  TD_MINS_UNDS,
  TD_SCLN_MINS,
  TD_Y_AMPR
};
//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOT_DQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
    [TD_LBRC_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RBRC_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_LPRN_LABK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LABK),
    [TD_RPRN_RABK] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RABK),
    [TD_MINS_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_SCLN_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_MINS),
    [TD_Y_AMPR] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_AMPR)
};
//In Layer declaration, add tap dance item in place of a key code
//TD(TD_ESC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTYw] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTRLESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SFTSLSH,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, LOWER,  ALTDEL,     KC_SPC,   RAISE, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTYm] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTRLESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SFTSLSH,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, LOWER,  GUIDEL,     KC_SPC,   RAISE, MACLANG
                                      //`--------------------------'  `--------------------------'

  ),

  [_GAMEMODE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTRLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, LOWER,  KC_SPC,     KC_SPC,   RAISE, MACLANG
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6,                            KC_7,    KC_8,    KC_9,    KC_0, TD(TD_MINS_UNDS), KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, W1Rc, R2Wc, GMAIL_1c, _______, _______,                      KC_MUTE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, MACCUT,  MACCOPY, MACPASTE, MACCAPTURE3,                  KC_VOLD, KC_VOLU, TD(TD_LBRC_LCBR), TD(TD_RBRC_RCBR), _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,   _______,  _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F1, KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,                       KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11, KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_MUTE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                 KC_VOLD, KC_VOLU, TD(TD_LBRC_LCBR), TD(TD_RBRC_RCBR), _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|-
                                            _______,   _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,                      KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, GMAIL_1, _______, _______,                      _______, QWERTYw, QWERTYm, GAMEMODE, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, NAME_1, NAME_2, NAME_3, _______, MACCAPTURE3,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SHIFT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    RSFT(KC_TAB), RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), RSFT(KC_Y), RSFT(KC_U), RSFT(KC_I), RSFT(KC_O), RSFT(KC_P), RSFT(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RSFT(KC_LCTL), RSFT(KC_A), RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G), RSFT(KC_H), RSFT(KC_J), RSFT(KC_K), RSFT(KC_L), RSFT(KC_SCLN), TD(TD_QUOT_DQT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RSFT(KC_DQT), RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), RSFT(KC_N), RSFT(KC_M), TD(TD_LPRN_LABK), TD(TD_RPRN_RABK), RSFT(KC_SLSH), SHIFTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        RSFT(KC_LALT), _______,  RSFT(KC_DEL),     RSFT(KC_SPC), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // [_EXTRA] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //    _______, _______, KC_QUIT, _______, _______, _______,                       _______, _______, KC_UP, _______, _______, KC_BSLS,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     _______, TAB_PRE, TAB_CLS, TAB_NXT, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     _______, KC_FBCK, TAB_RVS, KC_FFWD, _______, _______,                      _______, _______, _______, _______, _______, _______, 
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         _______, _______, _______,   _______, _______, _______
  //                                     //`--------------------------'  `--------------------------'
  // ),
  // [_EXTRA2] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //    _______, MACPTAB, MACCLOSE, MACNTAB, MACCAPTURE3, _______,                       _______, _______, KC_UP, _______, _______, KC_BSLS,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     _______, MACBACK, M_TAB_RVS, MACFW, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     _______, _______, MACCUT,  MACCOPY, MACPASTE, _______,                      _______, _______, _______, _______, _______, _______,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'),
  
  [_MACRRO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, WORK_ADD, FOREXMPL, MACCAPTURE3, _______,                 _______, _______, INOWORD, _______, PHONE_1, PHONE_2,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, GMAIL_1, W1R,      R2W,   GMAIL_2,                       HOME_ADD, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, NAME_1, NAME_2, NAME_3, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state)
{
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case QWERTYw:
    if (record->event.pressed)
    {
      print("mode just switched to qwerty and this is a huge string\n");
      set_single_persistent_default_layer(_QWERTYw);
    }
    return false;
    break;
  case QWERTYm:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_QWERTYm);
    }
    return false;
    break;
  case GAMEMODE:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_GAMEMODE);
    }
    return false;
    break;
  case HOME_ADD:
    if (record->event.pressed)
    {
      // SEND_STRING("617 Hiawatha Blvd E");
      SEND_STRING("25, Dokseodang-ro 40-gil, Seongdong-gu, Seoul, 04739");
      return false;
    }
    break;
  case WORK_ADD:
    if (record->event.pressed)
    {
      // SEND_STRING("215 University Pl 13210");
      SEND_STRING("독서당로40길 25");
      return false;
    }
    break;
  case GMAIL_1c:
    if (record->event.pressed)
    {
      SEND_STRING("dfkrhkjw;jchiud;jt@tmalu.c;m");
      return false;
    }    
    break;
  case GMAIL_2:
    if (record->event.pressed)
    {
      SEND_STRING("goodmourningvietnam@gmail.com");
      return false;
    }
    break;
  case W1R:
    if (record->event.pressed)
    {
      SEND_STRING("Rhawlan");
      return false;
    }
    break;
    case W1Rc:
    if (record->event.pressed)
    {
      SEND_STRING("Shawuaj");
      return false;
    }
    break;
  case R2W:
    if (record->event.pressed)
    {
      SEND_STRING("jsrk1027");
      SEND_STRING(SS_TAP(X_ENTER));
      return false;
    }
    break;
    case R2Wc:
    if (record->event.pressed)
    {
      SEND_STRING("ydsn1027");
      SEND_STRING(SS_TAP(X_ENTER));
      return false;
    }
    break;
  case NAME_1:
    if (record->event.pressed)
    {
      SEND_STRING("Stephen");
      return false;
    }
    break;
  case NAME_2:
    if (record->event.pressed)
    {
      SEND_STRING("Wonchul");
      return false;
    }
    break;
  case NAME_3:
    if (record->event.pressed)
    {
      SEND_STRING("Song");
      return false;
    }
    break;
  case PHONE_1:
    if (record->event.pressed)
    {
      // SEND_STRING("3154163646");
      SEND_STRING("01050618229");
      return false;
    }
    break;
  case PHONE_2:
    if (record->event.pressed)
    {
      SEND_STRING("315-416-3646");
      return false;
    }
    break;
  case INOWORD:
    if (record->event.pressed)
    {
      SEND_STRING("(i.e., )");
      SEND_STRING(SS_TAP(X_LEFT));
      return false;
    }
    break;
  case FOREXMPL:
    if (record->event.pressed)
    {
      SEND_STRING("(e.g., )");
      SEND_STRING(SS_TAP(X_LEFT));
      return false;
    }
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
