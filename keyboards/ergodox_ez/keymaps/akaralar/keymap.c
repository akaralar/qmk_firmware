/* Copyright 2022 Ahmet Karalar (@akaralar)
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
#include "version.h"

enum layers {
    QWER, // default qwerty layer
    BARE, // Only letters without modtaps
    COLE, // default colemak layer
    NAVI, // navigation layer
    MOUS, // mouse layer
    MDIA, // media keys layer
    NUMB, // numbers layer
    SYMB, // code symbols layer
    SNUM, // numbers from symbols layer
    FUNC, // Function keys layer
};

enum C_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    RGB_SLD,
    // Increase/decrease the difference from tapping term for ring/pinky fingers
    DT_R_UP,
    DT_R_DN,
    // Increase/decrease the difference from tapping term for index fingers
    DT_I_UP,
    DT_I_DN,
    // Print all the differences and the tapping term
    DT_PALL,

    // Keycode for activating casemodes
    CM_TOGL
};

// macOS keycodes
#define KC_CUT LGUI(KC_X)
#define KC_COPY LGUI(KC_C)
#define KC_PSTE LGUI(KC_V)
#define KC_UNDO LGUI(KC_Z)
#define KC_REDO LGUI(LSFT(KC_Z))
#define KC_FN KC_F24 // F24 is converted to fn key with karabiner

// mod-tap keys same for qwerty and colemak
#define MT_A MT(MOD_LCTL, KC_A)

// mod-tap keys for qwerty
#define MT_Q_E MEH_T(KC_E)
#define MT_Q_R ALL_T(KC_R)
#define MT_Q_U ALL_T(KC_U)
#define MT_Q_I MEH_T(KC_I)
#define MT_Q_F MT(MOD_LSFT, KC_F)
#define MT_Q_D MT(MOD_LGUI, KC_D)
#define MT_Q_S MT(MOD_LALT, KC_S)
#define MT_Q_J MT(MOD_RSFT, KC_J)
#define MT_Q_K MT(MOD_RGUI, KC_K)
#define MT_Q_L MT(MOD_LALT, KC_L)
#define MT_Q_QT MT(MOD_RCTL, KC_QUOTE)

// mod-tap keys for colemak-dh
#define MT_C_F MEH_T(KC_F)
#define MT_C_P ALL_T(KC_P)
#define MT_C_L ALL_T(KC_L)
#define MT_C_U MEH_T(KC_U)
#define MT_C_T MT(MOD_LSFT, KC_T)
#define MT_C_S MT(MOD_LGUI, KC_S)
#define MT_C_R MT(MOD_LALT, KC_R)
#define MT_C_N MT(MOD_RSFT, KC_N)
#define MT_C_E MT(MOD_RGUI, KC_E)
#define MT_C_I MT(MOD_LALT, KC_I)
#define MT_C_O MT(MOD_RCTL, KC_O)

// Layer-tap keys
#define LT_NAVI LT(NAVI, KC_SPACE)
#define LT_MOUS LT(MOUS, KC_TAB)
#define LT_MDIA LT(MDIA, KC_ESCAPE)
#define LT_NUMB LT(NUMB, KC_BSPC)
#define LT_SNUM LT(SNUM, KC_EQUAL)
#define LT_FUNC LT(FUNC, KC_ENTER)

// One-shot modifiers
#define OS_LSFT OSM(MOD_LSFT)

// Layer switching
#define LS_SYMB MO(SYMB)
#define LS_BARE TT(BARE)

// Changing default layer
#define DF_QWER DF(QWER)
#define DF_COLE DF(COLE)

// ZSA specific keys
#define ZSA_USB WEBUSB_PAIR
#define ZSA_TOG TOGGLE_LAYER_COLOR

// Application shortcuts
#define MOOM LALT(LCTL(LSFT(KC_GRAVE))) // Moom
#define ALF_NAV LGUI(LCTL(KC_SLASH))    // Alfred file navigation
#define ALF_ACT RGUI(RCTL(KC_BSLS))     // Alfred action selection
#define ONEP_QA LALT(LGUI(KC_BSLS))     // 1password quick access
#define ONEP_AF LGUI(LSFT(KC_BSLS))     // 1password autofill
#define TH_QE MEH(KC_T)                 // Things quick entry
#define TH_QEAF HYPR(KC_T)              // Things quick entry with autofill

// clang-format off

/* Matrix positions in Column:Row format
 * ,--------------------------------------------------.
 * |   0:0  | 0:1  | 0:2  | 0:3  | 0:4  | 0:5  | 0:6  |
 * |--------+------+------+------+------+-------------|
 * |   1:0  | 1:1  | 1:2  | 1:3  | 1:4  | 1:5  | 1:6  |
 * |--------+------+------+------+------+------|      |
 * |   2:0  | 2:1  | 2:2  | 2:3  | 2:4  | 2:5  |------|
 * |--------+------+------+------+------+------| 3:6  |
 * |   3:0  | 3:1  | 3:2  | 3:3  | 3:4  | 3:5  |      |
 * `--------+------+------+------+------+-------------'
 *   | 4:0  | 4:1  | 4:2  | 4:3  | 4:4  |
 *   `----------------------------------'
 *                                      ,-------------.
 *                                      | 5:5  | 5:6  |
 *                               ,------|------|------|
 *                               |      |      | 5:4  |
 *                               | 5:3  | 5:2  |------|
 *                               |      |      | 5:1  |
 *                               `--------------------'
 * ,--------------------------------------------------.
 * |  0:7 |  0:8 |  0:9 | 0:10 | 0:11 | 0:12 | 0:13   |
 * |------+------+------+------+------+------+--------|
 * |  1:7 |  1:8 |  1:9 | 1:10 | 1:11 | 1:12 | 1:13   |
 * |      |------+------+------+------+------+--------|
 * |------|  2:8 |  2:9 | 2:10 | 2:11 | 2:12 | 2:13   |
 * |  3:7 |------+------+------+------+------+--------|
 * |      |  3:8 |  3:9 | 3:10 | 3:11 | 3:12 | 3:13   |
 * `-------------+------+------+------+------+--------'
 *               |  4:9 | 4:10 | 4:11 | 4:12 | 4:13 |
 *               `----------------------------------'
 * ,-------------.
 * |  5:7 | 5:8  |
 * |------+------+------.
 * |  5:9 |      |      |
 * |------| 5:11 | 5:10 |
 * | 5:12 |      |      |
 * `--------------------'
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWER] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q   , KC_W   , MT_Q_E , MT_Q_R , KC_T   , _______,
        _______, MT_A   , MT_Q_S , MT_Q_D , MT_Q_F , KC_G   ,
        _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,
        _______, _______, _______, _______, LT_MDIA,
                                                     _______, _______,
                                                              OS_LSFT,
                                            LT_NAVI, LT_MOUS, LS_BARE,

        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Y   , MT_Q_U , MT_Q_I , KC_O   , KC_P   , _______,
                 KC_H   , MT_Q_J , MT_Q_K , MT_Q_L , MT_Q_QT, _______,
        _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,
                          LS_SYMB, _______, _______, _______, _______,
        _______, _______,
        CM_TOGL,
        KC_FN  , LT_FUNC, LT_NUMB
    ),

    [BARE] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_E   , _______, _______, _______,
        _______, KC_A   , KC_S   , _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_U   , KC_I   , _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),

    [COLE] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q   , KC_W   , MT_C_F , MT_C_P , KC_B   , _______,
        _______, MT_A   , MT_C_R , MT_C_S , MT_C_T , KC_G   ,
        _______, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , _______,
        _______, _______, _______, _______, LT_MDIA,
                                                     _______, _______,
                                                              OS_LSFT,
                                            LT_NAVI, LT_MOUS, LS_BARE,

        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_J   , MT_C_L , MT_C_U , KC_Y   , KC_QUOT, _______,
                 KC_M   , MT_C_N , MT_C_E , MT_C_I , MT_C_O , _______,
        _______, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, _______,
                          LS_SYMB, _______, _______, _______, _______,
        _______, _______,
        CM_TOGL,
        KC_FN  , LT_FUNC, LT_NUMB
    ),

    [NAVI] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, KC_MEH , KC_HYPR, XXXXXXX, _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,
        _______, KC_UNDO, KC_CUT , KC_COPY, KC_PSTE, KC_REDO, _______,
        _______, _______, _______, _______, XXXXXXX,
                                                     _______, _______,
                                                              _______,
                                           _______ , XXXXXXX, _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS , _______,
                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS, _______,
        _______, KC_REDO, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, KC_ENT , KC_BSPC
    ),

    [MOUS] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, ALF_ACT, ALF_NAV, MOOM   , _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, ONEP_QA,
        _______, XXXXXXX, _______, TH_QE  , TH_QEAF, ONEP_AF, _______,
        _______, _______, _______, _______, _______,
                                                     _______, _______,
                                                              _______,
                                            XXXXXXX, _______, _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, _______,
                 KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______,
        _______, KC_REDO, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, _______,
                          KC_BTN2, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, KC_BTN1, KC_BTN3
    ),

    [MDIA] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, QK_BOOT, ZSA_USB, XXXXXXX, DM_REC1, DM_PLY1, _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, DM_RSTP,
        _______, VRSN   , DF_COLE, DF_QWER, DM_REC2, DM_PLY2, _______,
        _______, _______, _______, _______, _______,
                                                     _______, _______,
                                                              _______,
                                            XXXXXXX, XXXXXXX, _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, KC_BRIU, RGB_HUI, RGB_SAI, RGB_VAI, _______,
                 ZSA_TOG, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
        _______, RGB_MOD, KC_BRID, RGB_HUD, RGB_SAD, RGB_VAD, _______,
                          KC_MUTE, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, KC_MSTP, KC_MPLY
    ),

    [NUMB] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC, _______,
        _______, KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL ,
        _______, KC_GRV , KC_1   , KC_2   , KC_3   , KC_BSLS, _______,
        _______, _______, _______, _______, KC_0   ,
                                                     _______, _______,
                                                              _______,
                                            _______, KC_MINS, _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, KC_HYPR, KC_MEH , KC_RALT, XXXXXXX, _______,
                 XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, _______,
        _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                          XXXXXXX, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, XXXXXXX, _______
    ),

    [SYMB] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_HASH, _______,
        _______, KC_UNDS, KC_SLSH, KC_LPRN, KC_RPRN, KC_AMPR,
        _______, KC_DLR , KC_QUES, KC_LABK, KC_RABK, KC_GRV , _______,
        _______, _______, _______, _______, KC_AT  ,
                                                     _______, _______,
                                                              _______,
                                            _______, KC_DOT , _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_CIRC, KC_BSLS, KC_DQUO, KC_ASTR, KC_PERC, _______,
                 KC_PIPE, KC_RCBR, KC_LCBR, KC_COLN, KC_COMM, _______,
        _______, KC_QUOT, LT_SNUM, KC_MINS, KC_EXLM, KC_SCLN, _______,
                          XXXXXXX, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, XXXXXXX
    ),

    [SNUM] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, KC_7   , KC_8   , KC_9   , XXXXXXX, _______,
        _______, XXXXXXX, KC_4   , KC_5   , KC_6   , XXXXXXX,
        _______, XXXXXXX, KC_1   , KC_2   , KC_3   , XXXXXXX, _______,
        _______, _______, _______, _______, KC_0   ,
                                                     _______, _______,
                                                              _______,
                                            _______, KC_DOT , _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                 XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),

    [FUNC] = LAYOUT_ergodox(
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F12 , KC_F7  , KC_F8  , KC_F9  , XXXXXXX, _______,
        _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , XXXXXXX,
        _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , XXXXXXX, _______,
        _______, _______, _______, _______, KC_ESC ,
                                                     _______, _______,
                                                              _______,
                                            KC_SPC , KC_TAB , _______,

        _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, DT_I_UP, DT_UP  , DT_R_UP, XXXXXXX, _______,
                 DT_PALL, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, _______,
        _______, XXXXXXX, DT_I_DN, DT_DOWN, DT_R_DN, XXXXXXX, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, XXXXXXX, XXXXXXX
    )
};

// clang-format on

//------------------------------------------------------------------------------
// Custom keycode handling
//------------------------------------------------------------------------------
static void send_string_if_enabled(const char *string) {
#ifdef SEND_STRING_ENABLE
    send_string(string);
#endif
}

bool process_custom_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
#ifdef RGB_MATRIX_ENABLE
                rgblight_mode(1);
#endif
            }
            return false;
        case VRSN:
            if (record->event.pressed) {
                const char* str = QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION;
                send_string_if_enabled(str);
            }
            return false;
        default:
            return true;
    }
};

//------------------------------------------------------------------------------
// Combos
//------------------------------------------------------------------------------
const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};


//------------------------------------------------------------------------------
// QMK User space functions
//------------------------------------------------------------------------------
void keyboard_post_init_user(void) {
#if RGB_MATRIX_ENABLE
    rgb_matrix_enable();
#endif

#if CONSOLE_ENABLE
    enable_debug_user();
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process custom keycodes defined in this file
    if (!process_custom_keycodes(keycode, record)) { return false; }

    return true;
};

//------------------------------------------------------------------------------
// Add empty functions for Magic Keycodes to save some space
// see https://docs.qmk.fm/#/squeezing_avr?id=magic-functions
//------------------------------------------------------------------------------
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
