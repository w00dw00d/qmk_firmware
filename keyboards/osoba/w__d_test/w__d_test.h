/* Copyright 2019 e3w2q
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

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define layout( \
    L00, L01, \
    L02, L03 \
) \
{ \
    { L00, L01 } , \
    { L02, L03 } \
}

/*
{ \
    { k001, k101, k201, k301, KC_NO } , \
    { k002, k102, k202, k302, k402 } , \
    { k003, k103, k203, k303, k403 } , \
    { k004, k104, k204, k304, k404 } , \
    { k005, k105, k205, k305, k405 } , \
    { k006, k106, k206, k306, KC_NO } , \
    { k007, k107, k207, k307, k407 } , \
    { k008, k108, k208, k308, k408 },   \
    { k009, k109, k209, k309, k409 } , \
    { k010, k110, k210, k310, KC_NO } , \
    { k011, k111, k211, k311, k411 } , \
    { k012, k112, k212, k312, k412 } , \
    { k013, k113, k213, k313, k413 } , \
    { k014, k114, k214, k314, KC_NO } , \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } , \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
*/
