/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers
{
  _QWERTYw,
  _QWERTYm,
  _COLEMAKw,
  _COLEMAKm,
  _NAVI,
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
  DVORAK,
  NAVI,
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
#define SCTRL_L LCTL(LSFT(KC_LEFT))
#define SCTRL_R LCTL(LSFT(KC_RIGHT))
#define MACLANG LGUI(KC_SPC)            // change language for MAC
#define MACPASTE LGUI(LALT(LSFT(KC_V))) // Paste without formatting: Option+Shift+Command+V
#define MACNTAB LCTL(KC_TAB)            // next tab for MAC
#define MACPTAB LCTL(LSFT(KC_TAB))      // Previous tab for MAC
#define M_TAB_RVS LGUI(LSFT(KC_T))      // Reopen tab for MAC
#define M_TAB_RVSc LGUI(LSFT(KC_F))      // Reopen tab for MAC in Colemak
// #define MACCAPTURE1 LGUI(LSFT(KC_3)) 
// #define MACCAPTURE2 LGUI(LSFT(KC_4)) 
#define MACCAPTURE3 LGUI(LSFT(KC_5))
#define MACCOPY LGUI(KC_C)
#define MACCUT LGUI(KC_X)
#define MACCLOSE LGUI(KC_W)
#define MACBACK LGUI(KC_LEFT)
#define MACFW LGUI(KC_RIGHT)
#define ESCXTRA2 LT(_EXTRA2, KC_ESC)
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
    //Tap once for Esc, twice for Caps Lock
    [TD_QUOT_DQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
    [TD_LBRC_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RBRC_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_LPRN_LABK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LABK),
    [TD_RPRN_RABK] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RABK),
    [TD_MINS_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_SCLN_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_MINS),
    [TD_Y_AMPR] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_AMPR)
    // Other declarations would go here, separated by commas, if you have them
};
//In Layer declaration, add tap dance item in place of a key code
//TD(TD_ESC_CAPS)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;- |'     |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SFTSLS|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |SFTQUE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |GESC  |EXTRA |  GUI | ALT  |LOWER |    (B)Space |RAISE | RALT | Left |  Down|Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_QWERTYw] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TD(TD_Y_AMPR), KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        CTRLESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        SFTSLSH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, SHIFTL,
        KC_GESC, EXTRA, KC_LGUI, KC_LALT, LOWER, MACRODEL, KC_SPC, RAISE, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),
    /* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |  UP  |SFTQUE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  DOWN|Right |
 * `-----------------------------------------------------------------------------------'
 *COLEMAK is actually MACKEY*/
    // [_COLEMAK] = LAYOUT_planck_grid(
    //     KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, TD(TD_SCLN_MINS), KC_BSPC,
    //     CTRLESC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
    //     SFTSLSH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, SHIFTL,
    //     KC_GESC, EXTRA, KC_LGUI, KC_LALT, LOWER, MACRODEL, KC_SPC, RAISE, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),
    [_QWERTYm] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TD(TD_Y_AMPR), KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        ESCXTRA2, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        SFTSLSH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, SHIFTL,
        KC_GESC, KC_LCTL, KC_LALT, KC_LGUI, LOWER, MACRODEL, KC_SPC, RAISE, MACLANG, KC_LEFT, KC_DOWN, KC_RGHT),
    [_NAVI] = LAYOUT_planck_grid(
        // KC_TAB,  MACPTAB, MACCLOSE,  MACNTAB, MACCAPTURE3, KC_MINS,  KC_7,    KC_8, KC_9,   KC_INS,  KC_HOME, KC_BSPC,
        // KC_LCTL, MACBACK, M_TAB_RVS, MACFW,   KC_MUTE,     KC_PLUS,  KC_4,    KC_5, KC_6,   KC_DEL,  KC_END,  KC_ENT,
        // KC_LSFT, KC_VOLU, MACCUT,    MACCOPY, MACPASTE,    KC_NUBS,  KC_1,    KC_2, KC_3,   KC_PGUP, KC_UP ,  KC_PGDN,
        // RAISE,   KC_VOLD, KC_LALT,  KC_LGUI,  LOWER,       MACRODEL, KC_SPC,  KC_0, KC_DOT, KC_LEFT, KC_DOWN, KC_RIGHT),
        QWERTYm, R2Wc,     MACPASTE,    MACNTAB,  MACFW,      KC_PLUS, KC_RIGHT, TD(TD_RPRN_RABK), KC_BSPC, KC_DEL, KC_SPC, KC_ENT, 
        KC_MUTE, W1Rc,     MACCOPY,     MACCLOSE, M_TAB_RVSc, KC_UP,   KC_DOWN,  TD(TD_RBRC_RCBR), KC_9,    KC_6,   KC_3,   KC_DOT, 
        KC_VOLU, KC_VOLD,  MACCUT,      MACPTAB,  MACBACK,    KC_MINS, KC_LEFT,  TD(TD_LBRC_LCBR), KC_8,    KC_5,   KC_2,   KC_0, 
        KC_ESC,  GMAIL_1c, MACCAPTURE3, KC_HOME,  KC_PGUP,    KC_PGDN, KC_END,   TD(TD_LPRN_LABK), KC_7,    KC_4,   KC_1,   KC_EQL), 
    /* _COLEMAKm
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |  UP  |SFTQUE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  DOWN|Right |
 * `-----------------------------------------------------------------------------------'
  */
    [_COLEMAKw] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, TD(TD_SCLN_MINS), KC_BSPC,
        CTRLESC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        SFTSLSH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_UP, SHIFTcL,
        KC_GESC, EXTRA, KC_LGUI, KC_LALT, LOWER, MACRODEL, KC_SPC, RAISE, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),
    [_COLEMAKm] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, TD(TD_SCLN_MINS), KC_BSPC,
        ESCXTRA2, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        SFTSLSH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_UP, SHIFTcL,
        KC_GESC, KC_LCTL, KC_LALT, KC_LGUI, LOWER, MACRODEL, KC_SPC, RAISE, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT),

    /* SHIFT
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |'     |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SFTSLS|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  ?   |SFTQUE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  GUI | ALT  |LOWER |    Space    |RAISE | RALT | Left |  Down|Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_SHIFT] = LAYOUT_planck_grid(
        RSFT(KC_TAB), RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), RSFT(KC_Y), RSFT(KC_U), RSFT(KC_I), RSFT(KC_O), RSFT(KC_P), RSFT(KC_BSPC),
        RSFT(KC_LCTL), RSFT(KC_A), RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G), RSFT(KC_H), RSFT(KC_J), RSFT(KC_K), RSFT(KC_L), RSFT(KC_SCLN), TD(TD_QUOT_DQT),
        RSFT(KC_QUOT), RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), RSFT(KC_N), RSFT(KC_M), TD(TD_LPRN_LABK), TD(TD_RPRN_RABK), RSFT(KC_SLSH), SHIFTL,
        _______, _______, RSFT(KC_LGUI), RSFT(KC_LALT), _______, RSFT(KC_DEL), RSFT(KC_SPC), _______, _______, RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT)),
    [_SHIFTc] = LAYOUT_planck_grid(
        RSFT(KC_TAB), RSFT(KC_Q), RSFT(KC_W), RSFT(KC_F), RSFT(KC_P), RSFT(KC_G), RSFT(KC_J), RSFT(KC_L), RSFT(KC_U), RSFT(KC_Y), RSFT(KC_SCLN), RSFT(KC_BSPC),
        RSFT(KC_LCTL), RSFT(KC_A), RSFT(KC_R), RSFT(KC_S), RSFT(KC_T), RSFT(KC_D), RSFT(KC_H), RSFT(KC_N), RSFT(KC_E), RSFT(KC_I), RSFT(KC_O), TD(TD_QUOT_DQT),
        RSFT(KC_QUOT), RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), RSFT(KC_B), RSFT(KC_K), RSFT(KC_M), TD(TD_LPRN_LABK), TD(TD_RPRN_RABK), RSFT(KC_SLSH), SHIFTcL,
        _______, _______, RSFT(KC_LGUI), RSFT(KC_LALT), _______, RSFT(KC_DEL), RSFT(KC_SPC), _______, _______, RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT)),

    /* RAISE
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |   F6 |  F7  |  F8  |  F9  |   F10|  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Vol-|  Vol+|  Mute| ALT2 | ALT7 | ALT7 |  Left|  Down| Up   | Right|  \|  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  GRV |      |      |      |      | ALT6 | ALT6 |      |   [{ |  }]  |  PgUP|      |      
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | RCTL | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
    [_RAISE] = LAYOUT_planck_grid(
      
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, ENOTE3, ENOTE1, ENOTE1, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_BSLS,
        KC_LSFT, _______, KC_CUT, KC_COPY, KC_PASTE, ENOTE2, ENOTE2, _______, TD(TD_LBRC_LCBR), TD(TD_RBRC_RCBR), KC_PGUP, KC_RSFT,
        KC_GRV, _______, _______, _______, _______, _______, _______, _______, KC_RCTL, KC_HOME, KC_PGDN, KC_END),

    /* LOWER
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Vol-|  Vol+|  Mute| ALT2 | ALT7 | ALT7 |  Left|  Down| Up   | Right|  \|  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  GRV |      |  cut | copy | paste| ALT6 | ALT6 |      |   [{ |  }]  |  PgUp|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Home | PgDn |   End|
 * `-----------------------------------------------------------------------------------'
 */
    [_LOWER] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TD(TD_MINS_UNDS), KC_EQL,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, ENOTE3, ENOTE1, ENOTE1, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_BSLS,
        KC_LSFT, _______, KC_CUT, KC_COPY, KC_PASTE, ENOTE2, ENOTE2, _______, TD(TD_LBRC_LCBR), TD(TD_RBRC_RCBR), KC_PLUS, KC_RSFT,
        KC_GRV, _______, _______, _______, _______, _______, _______, _______, KC_RALT, KC_TILDE, KC_MINS, KC_EQL),

    /* EXTRA
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |      | AltF4|      |      |   -  |   7  |   8  |   9  |   Ins|  Home|  PgUp|  
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Tab-| Tab x|  Tab+|      |   +  |   4  |   5  |   6  |   Del|   End|  PgDn|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CAPS |  Back| Tab o|   Fwd|      |   *  |   1  |   2  |   3  |      |    Up|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | 0    |   .  | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
    [_EXTRA] = LAYOUT_planck_grid(
        KC_ESC, KC_NO, KC_QUIT, KC_NO, _______, KC_MINS, KC_7, KC_8, KC_9, KC_INS, KC_HOME, KC_BSPC,
        _______, TAB_PRE, TAB_CLS, TAB_NXT, _______, KC_PLUS, KC_4, KC_5, KC_6, KC_DEL, KC_END, _______,
        KC_LSFT, KC_FBCK, TAB_RVS, KC_FFWD, _______, KC_NUBS, KC_1, KC_2, KC_3, _______, _______, KC_RSFT,
        KC_CAPS, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, _______, _______, _______),

    /* EXTRA2
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |      | AltF4|      |      |   -  |   7  |   8  |   9  |   Ins|  Home|  PgUp|  
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Tab-| Tab x|  Tab+|      |   +  |   4  |   5  |   6  |   Del|   End|  PgDn|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CAPS |      | Cut  |  Copy|NoForm|   *  |   1  |   2  |   3  |      |    Up|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | 0    |   .  | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
    [_EXTRA2] = LAYOUT_planck_grid(
        KC_ESC,  MACPTAB, MACCLOSE, MACNTAB, MACCAPTURE3, KC_MINS, KC_7, KC_8, KC_9, KC_INS, KC_HOME, KC_BSPC,
        _______, MACBACK, M_TAB_RVS, MACFW,   _______, KC_PLUS, KC_4, KC_5, KC_6, KC_DEL, KC_END, _______,
        KC_LSFT, _______, MACCUT,  MACCOPY, MACPASTE, KC_NUBS, KC_1, KC_2, KC_3, _______, _______, KC_RSFT,
        KC_CAPS, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, _______, _______, _______),
    /* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |  )   |   _  |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|MACKey|RGBMOD|RGBHUI|RGBHUD|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|Colemk|RGBSAI|RGBSAD|RGBVAI|RGBVAD|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |             |      |      |      | BANDW|HCNTRS|
 * `-----------------------------------------------------------------------------------'
 */
    [_ADJUST] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_LPRN_LABK), TD(TD_RPRN_RABK), KC_UNDS, KC_PLUS,
        _______, _______, MU_MOD, AU_ON, AU_OFF, AG_SWAP, AG_NORM, QWERTYw, QWERTYm, COLEMAKw, COLEMAKm, RGB_HUD,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, NAVI, KC_RSFT,
        RESET, _______, _______, _______, _______, _______, _______, _______, _______, BL_TOGG, BANDW, HCNTRST),

    /* MACRRO
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;- |'     |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SFTSLS|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |SFTQUE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | EXTRA| DEL  |  GUI | ALT  |LOWER |    Space    |RAISE | RALT | Left |  Down|Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_MACRRO] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, WORK_ADD, FOREXMPL, MACCAPTURE3, _______, _______, KC_U, INOWORD, KC_O, PHONE_1, KC_DEL,
        _______, KC_A, GMAIL_1, W1R, R2W, GMAIL_2, HOME_ADD, KC_J, KC_K, KC_L, TD(TD_SCLN_MINS), KC_DQT,
        KC_LSFT, NAME_1, NAME_2, NAME_3, PASTERMAC, GETLINK, KC_N, KC_M, LARW_L, LARW_R, KC_UP, KC_RSFT,
        RCHUNK, _______, KC_LGUI, KC_LALT, LOWER, _______, KC_SPC, RAISE, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),

};

#ifdef AUDIO_ENABLE
float plover_song[][2] = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

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
  case COLEMAKw:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_COLEMAKw);
    }
    return false;
    break;
  case COLEMAKm:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_COLEMAKm);
    }
    return false;
    break;
  case NAVI:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_NAVI);
    }
    return false;
    break;  
  // case MACKEY:
  //   if (record->event.pressed)
  //   {
  //     set_single_persistent_default_layer(_MACKEY);
  //   }
  //   return false;
  //   break;
  case BACKLIT:
    if (record->event.pressed)
    {
      register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
      backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
      writePinLow(E6);
#endif
    }
    else
    {
      unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
      writePinHigh(E6);
#endif
    }
    return false;
    break;
  case PLOVER:
    if (record->event.pressed)
    {
#ifdef AUDIO_ENABLE
      stop_all_notes();
      PLAY_SONG(plover_song);
#endif
      layer_off(_RAISE);
      layer_off(_LOWER);
      layer_off(_ADJUST);
      layer_on(_PLOVER);
      if (!eeconfig_is_enabled())
      {
        eeconfig_init();
      }
      keymap_config.raw = eeconfig_read_keymap();
      keymap_config.nkro = 1;
      eeconfig_update_keymap(keymap_config.raw);
    }
    return false;
    break;
  case EXT_PLV:
    if (record->event.pressed)
    {
#ifdef AUDIO_ENABLE
      PLAY_SONG(plover_gb_song);
#endif
      layer_off(_PLOVER);
    }
    return false;
    break;
  case TAB_DOWN_RTRN:
    if (record->event.pressed)
    {
      SEND_STRING(SS_TAP(X_TAB) SS_TAP(X_DOWN) SS_TAP(X_ENTER));
      return false;
    }
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
  case GMAIL_1:
    if (record->event.pressed)
    {
      SEND_STRING("stephenwonchulsong@gmail.com");
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
  case CBR_FN:
    if (record->event.pressed)
    {
      SEND_STRING("{");
      SEND_STRING("}");
      SEND_STRING(SS_TAP(X_LEFT));
      return false;
    }
    break;
  case BRC_FN:
    if (record->event.pressed)
    {
      SEND_STRING("[");
      SEND_STRING("]");
      SEND_STRING(SS_TAP(X_LEFT));
      return false;
    }
    break;
  case PRN_FN:
    if (record->event.pressed)
    {
      SEND_STRING("(");
      SEND_STRING(")");
      SEND_STRING(SS_TAP(X_LEFT));
      return false;
    }
    break;
  case TAB_UP_RTRN:
    if (record->event.pressed)
    {
      SEND_STRING(SS_TAP(X_TAB) SS_TAP(X_UP) SS_TAP(X_ENTER));
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
  // case FOREXMPL:
  //   if (record->event.pressed)
  //   {
  //     SEND_STRING("(e.g., )");
  //     SEND_STRING((SS_TAP(X_LEFT));
  //     return false;
  //   }
  //   break;
  case FF_TEXT:
    if (record->event.pressed)
    {
      SEND_STRING(SS_TAP(X_LALT));
      SEND_STRING("rff");
      SEND_STRING(SS_TAP(X_LEFT));
      SEND_STRING(SS_TAP(X_ENTER));
      return false;
    }
    break;
  case IN_R:
    if (record->event.pressed)
    {
      SEND_STRING("%in%");
      return false;
    }
    break;
  case LARW_L:
    if (record->event.pressed)
    {
      SEND_STRING("<-");
      return false;
    }
    break;
  case LARW_R:
    if (record->event.pressed)
    {
      SEND_STRING("->");
      return false;
    }
    break;
  case COPYTABPASTETAB:
    if (record->event.pressed)
    {
      SEND_STRING(SS_LCTL("c") SS_DELAY(500));
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(SS_TAP(X_TAB));
      SEND_STRING(SS_UP(X_LALT) SS_DELAY(500));
      SEND_STRING(SS_LCTL("v") SS_DELAY(500));
      SEND_STRING(SS_TAP(X_ENTER));
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(SS_TAP(X_TAB));
      SEND_STRING(SS_UP(X_LALT) SS_DELAY(500));
      return false;
    }
    break;
  case GETLINK:
    if (record->event.pressed)
    {
      SEND_STRING(SS_LCTL("l") SS_DELAY(500));
      SEND_STRING(SS_LCTL("c") SS_DELAY(500));
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(SS_TAP(X_TAB));
      SEND_STRING(SS_UP(X_LALT) SS_DELAY(500));
      SEND_STRING(SS_LCTL("v") SS_DELAY(500));
      SEND_STRING(SS_TAP(X_DOWN) SS_DELAY(500));
      SEND_STRING(SS_TAP(X_LEFT) SS_DELAY(500));
      SEND_STRING(SS_LCTL("c") SS_DELAY(500));
      SEND_STRING(SS_TAP(X_TAB) SS_DELAY(500));
      SEND_STRING(SS_DOWN(X_LALT));
      SEND_STRING(SS_TAP(X_TAB));
      SEND_STRING(SS_UP(X_LALT) SS_DELAY(500));
      SEND_STRING(SS_TAP(X_TAB) SS_DELAY(500));
      SEND_STRING(SS_TAP(X_TAB) SS_DELAY(500));
      SEND_STRING(SS_TAP(X_TAB) SS_DELAY(500));
      SEND_STRING(SS_TAP(X_TAB) SS_DELAY(500));
      SEND_STRING(SS_LCTL("v") SS_DELAY(500));
      SEND_STRING(SS_TAP(X_ENTER));
      return false;
    }
    break;
  case PASTERMAC:
    if (record->event.pressed)
    {
      SEND_STRING(SS_DOWN(X_LGUI));
      SEND_STRING(SS_DOWN(X_LCTL));
      SEND_STRING("c");
      SEND_STRING(SS_UP(X_LCTL));
      SEND_STRING(SS_UP(X_LGUI) SS_DELAY(500));
      SEND_STRING(SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_TAB));
      SEND_STRING(SS_UP(X_LGUI) SS_DELAY(500));
      SEND_STRING(SS_LGUI("v") SS_DELAY(500));
      SEND_STRING(SS_TAP(X_DOWN) SS_DELAY(500));
      SEND_STRING(SS_TAP(X_LEFT) SS_DELAY(500));
      SEND_STRING(SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_TAB) SS_UP(X_LGUI));
      return false;
    }
    break;
  case TOGTERM1:
    if (record->event.pressed)
    {
      SEND_STRING(SS_DOWN(X_LSFT));
      SEND_STRING(SS_LCTL("p"));
      SEND_STRING(SS_UP(X_LSFT) SS_DELAY(200));
      SEND_STRING("terminus toggle panel");
      SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(350));
      SEND_STRING("ipython");
      SEND_STRING(SS_TAP(X_ENTER));
      return false;
    }
    break;
  case TOGTERM2:
    if (record->event.pressed)
    {
      SEND_STRING(SS_DOWN(X_LSFT));
      SEND_STRING(SS_LCTL("p"));
      SEND_STRING(SS_UP(X_LSFT) SS_DELAY(200));
      SEND_STRING("terminus close all");
      SEND_STRING(SS_DELAY(200) SS_TAP(X_ENTER));
      return false;
    }
    break;
  case TOGTERM3:
    if (record->event.pressed)
    {
      SEND_STRING(SS_DOWN(X_LSFT));
      SEND_STRING(SS_LCTL("p"));
      SEND_STRING(SS_UP(X_LSFT) SS_DELAY(200));
      SEND_STRING("terminus toggle panel");
      SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(350));
      SEND_STRING("R");
      SEND_STRING(SS_TAP(X_ENTER));
      return false;
    }
    break;
  case RCHUNK:
    if (record->event.pressed)
    {
      SEND_STRING("```{r}");
      SEND_STRING(SS_TAP(X_ENTER));
      SEND_STRING(SS_TAP(X_ENTER));
      SEND_STRING("```");
      SEND_STRING(SS_TAP(X_UP));
    }
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise)
{
  if (muse_mode)
  {
    if (IS_LAYER_ON(_RAISE))
    {
      if (clockwise)
      {
        muse_offset++;
      }
      else
      {
        muse_offset--;
      }
    }
    else
    {
      if (clockwise)
      {
        muse_tempo += 1;
      }
      else
      {
        muse_tempo -= 1;
      }
    }
  }
  else
  {
    if (clockwise)
    {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_DOWN);
#else
      tap_code(KC_PGDN);
#endif
    }
    else
    {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_UP);
#else
      tap_code(KC_PGUP);
#endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active)
{
  switch (index)
  {
  case 0:
  {
#ifdef AUDIO_ENABLE
    static bool play_sound = false;
#endif
    if (active)
    {
#ifdef AUDIO_ENABLE
      if (play_sound)
      {
        PLAY_SONG(plover_song);
      }
#endif
      layer_on(_ADJUST);
    }
    else
    {
#ifdef AUDIO_ENABLE
      if (play_sound)
      {
        PLAY_SONG(plover_gb_song);
      }
#endif
      layer_off(_ADJUST);
    }
#ifdef AUDIO_ENABLE
    play_sound = true;
#endif
    break;
  }
  case 1:
    if (active)
    {
      muse_mode = true;
    }
    else
    {
      muse_mode = false;
    }
  }
}

void matrix_scan_user(void)
{
#ifdef AUDIO_ENABLE
  if (muse_mode)
  {
    if (muse_counter == 0)
    {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note)
      {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  }
  else
  {
    if (muse_counter)
    {
      stop_all_notes();
      muse_counter = 0;
    }
  }
#endif
}

bool music_mask_user(uint16_t keycode)
{
  switch (keycode)
  {
  case RAISE:
  case LOWER:
    return false;
  default:
    return true;
  }
}
