/* Copyright 2015-2021 Jack Humbert
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

// https://github.com/harlequin144/planck-keymap/blob/master/docs/config_options.md

#pragma once

#undef AU_OFF
#undef MU_OFF
#undef NO_AUDIO_ENABLE
#undef NO_PRINT
#undef NO_DEBUG

#define FORCE_NKRO
#define PREVENT_STUCK_MODIFIERS

#define LEADER_TIMEOUT 300

#define TAPPING_FORCE_HOLD
// makes it possible to use a dual role key as modifier shortly after having been tapped See Hold after tap

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_SPECIAL // Do not Auto Shift special keys, which include -_, =+, [{, ]}, ;:, '", ,<, .>, /?, and the KC_TAB
#define NO_AUTO_SHIFT_NUMERIC // Do not Auto Shift numeric keys, which include 1234567890
#define NO_AUTO_SHIFT_ENTER
#define AUTO_SHIFT_NO_AUTO_REPEAT  // Disables automatically keyrepeating when AUTO_SHIFT_TIMEOUT is exceeded.


// hello world.my name is john doe.i am a computer programmer playing with keyboards right now.
// [PRESS AS_DOWN quite a few times]
// heLLo woRLd.mY nAMe is JOHn dOE.i AM A compUTeR proGRaMMER PlAYiNG witH KEYboArDS RiGHT NOw.
// [PRESS AS_UP a few times]
// hello world.my name is john Doe.i am a computer programmer playing with keyboarDs right now.
// [PRESS AS_RPT]
// 115

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

    /*
     * MIDI options
     */

    /* enable basic MIDI features:
       - MIDI notes can be sent when in Music mode is on
    */

    // #define MIDI_BASIC

    /* enable advanced MIDI features:
       - MIDI notes can be added to the keymap
       - Octave shift and transpose
       - Virtual sustain, portamento, and modulation wheel
       - etc.
    */
    // #define MIDI_ADVANCED

    /* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
    // #define MIDI_TONE_KEYCODE_OCTAVES 2

    // Most tactile encoders have detents every 4 stages
    // #define ENCODER_RESOLUTION 4
