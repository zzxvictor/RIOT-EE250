/*
 * Copyright (C) 2017 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    boards_b-l475e-iot01a ST B-L475E-IOT01A
 * @ingroup     boards
 * @brief       Board specific files for the ST b-l475e-iot01a board
 * @{
 *
 * @file
 * @brief       Board specific definitions for the ST b-l475e-iot01a board
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    LED pin definitions and handlers
 * @{
 */
#define LED0_PIN            GPIO_PIN(PORT_A, 5)
#define LED0_MASK           (1 << 5)

#define LED0_ON             (GPIOA->BSRR = LED0_MASK)
#define LED0_OFF            (GPIOA->BSRR = (LED0_MASK << 16))
#define LED0_TOGGLE         (GPIOA->ODR  ^= LED0_MASK)

#define LED1_PIN            GPIO_PIN(PORT_B, 14)
#define LED1_MASK           (1 << 14)

#define LED1_ON             (GPIOB->BSRR = LED1_MASK)
#define LED1_OFF            (GPIOB->BSRR = (LED1_MASK << 16))
#define LED1_TOGGLE         (GPIOB->ODR  ^= LED1_MASK)
/** @} */

/**
 * @brief   User button
 */
#define BTN_B1_PIN          GPIO_PIN(PORT_C, 13)

/**
 * @brief   Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
