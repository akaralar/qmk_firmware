/* Copyright 2021 Your Name (@akaralar)
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

// Disable key repeating for tap-hold keys
#define QUICK_TAP_TERM 0

// Tap-hold configuration for home row mods.
#undef TAPPING_TERM
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

// Turn keyboard lights off after 5 minutes
#define RGB_MATRIX_TIMEOUT 300000

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#define RGB_MATRIX_DEFAULT_SPD 60

// Activate Caps Word by pressing both shift keys
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

// #define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0

#define FIRMWARE_VERSION u8"yBAgx/nwR3b"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT
