 /* Copyright 2020 Ralph Azucena <ralphie02@live.com>
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

#define LAYOUT_mamut_70(\
    L00, L01, L02, L03, L04, L05, L06,                      R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,                      R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,                      R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,                      R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43, L44, L45, L46,                      R40, R41, R42, R43, R44, R45, R46 \
    )\
    {\
        { L00, L01, L02, L03, L04, L05, L06 },   \
        { L10, L11, L12, L13, L14, L15, L16 },   \
        { L20, L21, L22, L23, L24, L25, L26 },   \
        { L30, L31, L32, L33, L34, L35, L36 },   \
        { L40, L41, L42, L43, L44, L45, L46 }, \
                                            \
        { R00, R01, R02, R03, R04, R05, R06 },   \
        { R10, R11, R12, R13, R14, R15, R16 },   \
        { R20, R21, R22, R23, R24, R25, R26 },   \
        { R30, R31, R32, R33, R34, R35, R36 },   \
        { R40, R41, R42, R43, R44, R45, R46 },   \
}
