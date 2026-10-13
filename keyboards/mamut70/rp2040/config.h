// Copyright 2023 Przemysław (@przlel)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Double tap of the reset button enters the RP2040 bootloader. No LED is
 * defined: GP16 drives the WS2812 data line, not a plain LED. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
