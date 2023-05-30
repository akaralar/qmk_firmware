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
    BASE, // default layer
    NAVI, // navigation layer
    MOUS, // mouse layer
    MDIA, // media keys layer
    NUMB, // numbers layer
    SYMB, // code symbols layer
    SNUM, // numbers from symbols layer
    FUNC, // Function keys layer
};

#define KC_UNDO LGUI(KC_Z)
#define KC_CUT LGUI(KC_X)
#define KC_COPY LGUI(KC_C)
#define KC_PASTE LGUI(KC_V)
#define KC_REDO C_REDO

enum C_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    RGB_SLD,
};

#define C_E MEH_T(KC_E)
#define C_R ALL_T(KC_R)

#define C_A MT(MOD_LCTL, KC_A)
#define C_S MT(MOD_LALT, KC_S)
#define C_D MT(MOD_LGUI, KC_D)
#define C_F MT(MOD_LSFT, KC_F)

#define C_U ALL_T(KC_U)
#define C_I MEH_T(KC_I)

#define C_QUOTE MT(MOD_RCTL, KC_QUOTE)
#define C_L MT(MOD_LALT, KC_L)
#define C_K MT(MOD_RGUI, KC_K)
#define C_J MT(MOD_RSFT, KC_J)

#define C_REDO LGUI(LSFT(KC_Z))

#define C_MOOM LALT(LCTL(LSFT(KC_GRAVE)))
#define C_NAV_ALFD LGUI(LCTL(KC_SLASH))
#define C_ACT_ALFD RGUI(RCTL(KC_BSLS))
#define C_1PASS LALT(LGUI(KC_BSLS))
#define C_1PASS_AF LGUI(LSFT(KC_BSLS))

#define C_L1 LT(1, KC_SPACE)
#define C_L2 LT(2, KC_TAB)
#define C_L3 LT(3, KC_ESCAPE)
#define C_L4 LT(4, KC_BSPC)
#define C_L5 MO(5)
#define C_L6 LT(6, KC_EQUAL)
#define C_L7 LT(7, KC_ENTER)

#define C_MCR_ST DYN_REC_STOP
#define C_MCR_1R DYN_REC_START1
#define C_MCR_2R DYN_REC_START2
#define C_MCR_1P DYN_MACRO_PLAY1
#define C_MCR_2P DYN_MACRO_PLAY2

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /*
     * ,--------------------------------------------------.    ,--------------------------------------------------.
     * |    0   |   1  |   2  |   3  |   4  |   5  |  6   |    |  38  |  39  |  40  |  41  |  42  |  43  |   44   |
     * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
     * |    7   |   8  |   9  |  10  |  11  |  12  |  13  |    |  45  |  46  |  47  |  48  |  49  |  50  |   51   |
     * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
     * |   14   |  15  |  16  |  17  |  18  |  19  |------|    |------|  52  |  53  |  54  |  55  |  56  |   57   |
     * |--------+------+------+------+------+------|  26  |    |  58  |------+------+------+------+------+--------|
     * |   20   |  21  |  22  |  23  |  24  |  25  |      |    |      |  59  |  60  |  61  |  62  |  63  |   64   |
     * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
     *   |  27  |  28  |  29  |  30  |  31  |                                |  65  |  66  |  67  |  68  |  69  |
     *   `----------------------------------'                                `----------------------------------'
     *                                       ,-------------.  ,-------------.
     *                                       |  32  |  33  |  |  70  |  71  |
     *                                ,------+------+------|  |------+------+------.
     *                                |      |      |  34  |  |  72  |      |      |
     *                                |  35  |  36  |------|  |------|  74  |  75  |
     *                                |      |      |  37  |  |  73  |      |      |
     *                                `--------------------'  `--------------------'
     */

    [BASE] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,      _______  , _______, _______, _______ , _______, _______ , _______,
    _______, KC_Q   , KC_W   , C_E    , C_R    , KC_T   , _______,      _______  , KC_Y   , C_U    , C_I     , KC_O   , KC_P    , _______,
    _______, C_A    , C_S    , C_D    , C_F    , KC_G   ,                          KC_H   , C_J    , C_K     , C_L    , C_QUOTE , _______,
    _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,      _______  , KC_N   , KC_M   , KC_COMMA, KC_DOT , KC_SLASH, _______,
    _______, _______, _______, _______, C_L3   ,                                            C_L5   , _______ , _______, _______ , _______,

                                                 _______, _______,      _______  , _______,
                                                          _______,      KC_F24   ,
                                        C_L1   , C_L2   , _______,      KC_DELETE, C_L7   , C_L4
    ),

    [NAVI] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______ , _______, _______,      _______, _______ , _______  , _______, _______ , _______     , _______,
    _______, XXXXXXX, XXXXXXX, KC_MEH , KC_HYPR , XXXXXXX, _______,      _______, KC_PGUP , KC_HOME  , KC_UP  , KC_END  , KC_INSERT   , _______,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT , XXXXXXX,                        KC_PGDN , KC_LEFT  , KC_DOWN, KC_RIGHT, KC_CAPS_LOCK, _______,
    _______, KC_UNDO, KC_CUT , KC_COPY, KC_PASTE, KC_REDO, _______,      _______, KC_REDO , KC_PASTE , KC_COPY, KC_CUT  , KC_UNDO     , _______,
    _______, _______, _______, _______, XXXXXXX ,                                           KC_DELETE, _______, _______ , _______     , _______,

                                                  XXXXXXX, XXXXXXX,      _______, _______ ,
                                                           _______,      _______,
                                        _______ , XXXXXXX, XXXXXXX,      _______, KC_ENTER, KC_BSPC
    ),

    [MOUS] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______   , _______   , _______   , _______,      _______, _______      , _______      , _______   , _______       , _______, _______,
    _______, XXXXXXX, XXXXXXX, C_ACT_ALFD, C_NAV_ALFD, C_MOOM    , _______,      _______, KC_MS_WH_UP  , KC_MS_WH_LEFT, KC_MS_UP  , KC_MS_WH_RIGHT, XXXXXXX, _______,
    _______, KC_LCTL, KC_LALT, KC_LGUI   , KC_LSFT   , C_1PASS   ,                        KC_MS_WH_DOWN, KC_MS_LEFT   , KC_MS_DOWN, KC_MS_RIGHT   , XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX   , C_1PASS_AF, _______,      _______, C_REDO       , KC_PASTE     , KC_COPY   , KC_CUT        , KC_UNDO, _______,
    _______, _______, _______, _______   , _______   ,                                                   KC_MS_BTN2   , _______   , _______       , _______, _______,

                                                       XXXXXXX   , XXXXXXX,      _______, _______      ,
                                                                   _______,      _______,
                                           XXXXXXX   , _______   , XXXXXXX,      _______, KC_MS_BTN1   , KC_MS_BTN3
    ),

    [MDIA] = LAYOUT_ergodox_pretty(
    _______, _______, _______    , _______, _______, _______, _______,      _______, _______           , _______            , _______          , _______        , _______            , _______,
    _______, QK_BOOT, WEBUSB_PAIR, XXXXXXX, DM_REC1, DM_PLY1, _______,      _______, RGB_TOG           , KC_BRIGHTNESS_UP   , RGB_HUI          , RGB_SAI        , RGB_VAI            , _______,
    _______, KC_LCTL, KC_LALT    , KC_LGUI, KC_LSFT, DM_RSTP,                        TOGGLE_LAYER_COLOR, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______,
    _______, VRSN   , XXXXXXX    , XXXXXXX, DM_REC2, DM_PLY2, _______,      _______, RGB_MOD           , KC_BRIGHTNESS_DOWN , RGB_HUD          , RGB_SAD        , RGB_VAD            , _______,
    _______, _______, _______    , _______, _______,                                                     KC_AUDIO_MUTE      , _______          , _______        , _______            , _______,

                                                     XXXXXXX, XXXXXXX,      _______, _______           ,
                                                              _______,      _______,
                                            XXXXXXX, XXXXXXX, XXXXXXX,      _______, KC_MEDIA_STOP     , KC_MEDIA_PLAY_PAUSE
    ),

    [NUMB] = LAYOUT_ergodox_pretty(
    _______, _______ , _______, _______, _______, _______ , _______,      _______, _______, _______, _______ , _______, _______ , _______,
    _______, KC_LBRC , KC_7   , KC_8   , KC_9   , KC_RBRC , _______,      _______, XXXXXXX, KC_HYPR, KC_MEH  , KC_RALT, XXXXXXX , _______,
    _______, KC_SCLN , KC_4   , KC_5   , KC_6   , KC_EQUAL,                        XXXXXXX, KC_RSFT, KC_RGUI , KC_LALT, KC_RCTL , _______,
    _______, KC_GRAVE, KC_1   , KC_2   , KC_3   , KC_BSLS , _______,      _______, XXXXXXX, XXXXXXX, KC_COMMA, KC_DOT , KC_SLASH, _______,
    _______, _______ , _______, _______, KC_0   ,                                           XXXXXXX, _______ , _______, _______ , _______,

                                                  XXXXXXX , XXXXXXX,      _______, _______,
                                                            _______,      _______,
                                         _______, KC_MINUS, XXXXXXX,      _______, XXXXXXX, _______
    ),

    [SYMB] = LAYOUT_ergodox_pretty(
    _______, _______, _______ , _______, _______, _______ , _______,      _______, _______ , _______, _______ , _______, _______ , _______,
    _______, KC_TILD, KC_PLUS , KC_RBRC, KC_LBRC, KC_HASH , _______,      _______, KC_CIRC , KC_BSLS, KC_DQUO , KC_ASTR, KC_PERC , _______,
    _______, KC_UNDS, KC_SLASH, KC_LPRN, KC_RPRN, KC_AMPR ,                        KC_PIPE , KC_RCBR, KC_LCBR , KC_COLN, KC_COMMA, _______,
    _______, KC_DLR , KC_QUES , KC_LABK, KC_RABK, KC_GRAVE, _______,      _______, KC_QUOTE, C_L6   , KC_MINUS, KC_EXLM, KC_SCLN , _______,
    _______, _______, _______ , _______, KC_AT  ,                                            XXXXXXX, _______ , _______, _______ , _______,

                                                   XXXXXXX, XXXXXXX,      _______, _______,
                                                            _______,      _______,
                                         _______ , KC_DOT , XXXXXXX,      _______, _______, XXXXXXX
    ),

    [SNUM] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
    _______, KC_NO  , KC_7   , KC_8   , KC_9   , KC_NO  , _______,       _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______,
    _______, KC_NO  , KC_4   , KC_5   , KC_6   , KC_NO  ,                         KC_NO  , _______, KC_NO  , KC_NO  , KC_NO  , _______,
    _______, KC_NO  , KC_1   , KC_2   , KC_3   , KC_NO  , _______,       _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______,
    _______, _______, _______, _______, KC_0   ,                                           _______, _______, _______, _______, _______,
                                                 _______, _______,       _______, _______,
                                                          _______,       _______,
                                        _______, KC_DOT,  _______,       _______, _______, _______
    ),

    [FUNC] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______  , _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F12 , KC_F7  , KC_F8  , KC_F9    , XXXXXXX, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_F11 , KC_F4  , KC_F5  , KC_F6    , XXXXXXX,                        XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, _______,
    _______, KC_F10 , KC_F1  , KC_F2  , KC_F3    , XXXXXXX, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, KC_ESCAPE,                                          _______, _______, _______, _______, _______,

                                                   XXXXXXX, XXXXXXX,      _______, _______,
                                                            _______,      _______,
                                        KC_SPACE , KC_TAB , XXXXXXX,      _______, XXXXXXX, XXXXXXX
    )
};

// clang-format on

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return true;
        default:
            return false;
    }
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}

// Custom Keycodes defined in this file
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            }
    }
    return true;
}

/*  This part is related to RGB matrix and fails to compile if the board has
    RGB matrix disabled */
#if RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BASE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [NAVI] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {163,218,204}, {163,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {163,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MOUS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {0,0,0}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {0,0,0}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {122,255,255}, {122,255,255}, {122,255,255}, {0,0,0}, {0,0,0}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {122,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MDIA] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [NUMB] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0} },

    [SYMB] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [SNUM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [FUNC] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {211,218,204}, {211,218,204}, {211,218,204}, {211,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {211,218,204}, {211,218,204}, {211,218,204}, {211,218,204}, {0,0,0}, {211,218,204}, {211,218,204}, {211,218,204}, {211,218,204}, {0,0,0}, {211,218,204}, {211,218,204}, {211,218,204}, {211,218,204}, {211,218,204}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case BASE ... FUNC:
            set_layer_color(biton32(layer_state));
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }

    return false;
}

// End block related to RGB features
#endif

// LED light behaviour for Caps Lock & Caps Word

void matrix_scan_user() {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        ergodox_right_led_3_on();
    } else {
        uint8_t layer = get_highest_layer(layer_state);
        if (layer != 3 && layer != 5 && layer != 6 && layer != 7) {
            ergodox_right_led_3_off();
        }
    }

    if (is_caps_word_on()) {
        ergodox_right_led_2_on();
    } else {
        uint8_t layer = get_highest_layer(layer_state);
        if (layer != 2 && layer != 4 && layer != 6 && layer != 7) {
            ergodox_right_led_2_off();
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
