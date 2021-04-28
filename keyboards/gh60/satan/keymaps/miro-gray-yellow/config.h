/*
Copyright 2021 Michael Rommel <rommel@layer-7.net>

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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// free pin B2 
#undef LED_CAPS_LOCK_PIN
// change pin where WS2812B LEDs are attached
#undef RGB_DI_PIN
#define RGB_DI_PIN B2
// number of attached WS2812B LEDs
#define RGBLED_NUM 8
// turn on RGB layers
#define RGBLIGHT_LAYERS
#undef RGBLIGHT_LAYER_BLINK
// setting default values
#undef RGBLIGHT_DEFAULT_HUE
#define RGBLIGHT_DEFAULT_HUE 180
#undef RGBLIGHT_DEFAULT_VAL
#define RGBLIGHT_DEFAULT_VAL 160
// selecting animations
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_EFFECT_TWINKLE_LIFE 255
#define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 10/127

#endif
