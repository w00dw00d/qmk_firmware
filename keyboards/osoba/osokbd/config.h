// Copyright 2022 Yoichiro Tanaka (@yoichiro)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

//#define SERIAL_DEBUG

#define WS2812_DI_PIN GP28
#define WS2812_PIO_USE_PIO1
#define DUPLEX_MATRIX
#define RGBLIGHT_LED_MAP { 0,1,2,3,4,5,6,7 }
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define AUTO_SHIFT_TIMEOUT 180
#define AUTO_SHIFT_TIMEOUT_PER_KEY
// #define NO_AUTO_SHIFT_NUMERIC
// #define NO_AUTO_SHIFT_ALPHA
