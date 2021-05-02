/* Copyright 2021 Michael Rommel <rommel@layer-7.net>
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

#pragma once

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// setting default values
#undef RGBLIGHT_DEFAULT_HUE
#define RGBLIGHT_DEFAULT_HUE 180
#undef RGBLIGHT_DEFAULT_VAL
#define RGBLIGHT_DEFAULT_VAL 160
// selecting animations
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

// #define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 750

#endif
