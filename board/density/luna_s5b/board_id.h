/*
 * Copyright (C) 2022 Density, Inc.
 * Author: Erik Bolton <erik.bolton@density.io>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef _BOARD_ID_S5B_H_
#define _BOARD_ID_S5B_H_

#include <asm/arch/mux_dra7xx.h>
#include <asm/arch-omap5/clock.h>

typedef enum JUNO_BOARD_ID {
    REV_7008_0    = 0b0001,
    X1_275_1400   = 0b0010,
    A1_275_1400   = 0b0011,
    X1_MICRON     = 0b1000,
    X1_SAMSUNG    = 0b1001,
    A1_A2_SAMSUNG = 0b1010,
    A3            = 0b1011,
    A4            = 0b1100,
    A5            = 0b1111,
    INVALID       = 0b0000
} juno_board_id;

#define BOARD_ID_PIN_3	GPIO_TO_PIN(1, 29)
#define BOARD_ID_PIN_2  GPIO_TO_PIN(1, 28) 
#define BOARD_ID_PIN_1	GPIO_TO_PIN(1, 27)
#define BOARD_ID_PIN_0	GPIO_TO_PIN(1, 26)

#define CM_WKUPAON_GPIO1_CLKCTRL    0x4AE07838
#define GPIO1_CONFIG_BASE           0x4AE10000
#define GPIO1_SYSCONFIG             0x0010
#define GPIO1_SYSCSTATUS            0x0114
#define GPIO1_CTRL                  0x0130
#define GPIO1_OE                    0x0134
#define GPIO1_DATAIN                0x0138

/* CM_WKUPAON_GPIO1_CLKCTRL */
#define IDLEST_ACTIVE  (MODULE_CLKCTRL_IDLEST_FULLY_FUNCTIONAL << MODULE_CLKCTRL_IDLEST_SHIFT)

/* GPIO1_SYSCONFIG */
#define SOFTRESET      1 << 1
#define NO_WAKEUP      0 << 2
#define NO_IDLE        1 << 3
#define AUTO_GATE      1

#define BOARD_ID_MASK  0b00111100000000000000000000000000
#define BOARD_ID_SHIFT 26

/* static juno_board_id board_id = INVALID; */

static inline juno_board_id get_board_id_raw(void)
{
    juno_board_id board_id = INVALID;
    
    /* if (board_id != INVALID) return board_id; */

    unsigned int reg = 0;

    /* GPIO1 - pad control */
    writel((M14 | PIN_INPUT), (0x4A002000 + 0x1450));
    writel((M14 | PIN_INPUT), (0x4A002000 + 0x1454));
    writel((M14 | PIN_INPUT), (0x4A002000 + 0x1458));
    writel((M14 | PIN_INPUT), (0x4A002000 + 0x145C));  

    /* GPIO1 - clock system */
    reg = readl(CM_WKUPAON_GPIO1_CLKCTRL);
    writel(reg & (IDLEST_ACTIVE | MODULE_CLKCTRL_MODULEMODE_HW_AUTO), CM_WKUPAON_GPIO1_CLKCTRL);

    /* GPIO1 - soft reset */
    writel(SOFTRESET, (GPIO1_CONFIG_BASE + GPIO1_SYSCONFIG));
    while (readl(GPIO1_CONFIG_BASE + GPIO1_SYSCSTATUS) == 0)

    /* GPIO1 - config */
    reg = readl(GPIO1_CONFIG_BASE + GPIO1_SYSCONFIG);
    writel(reg & (NO_WAKEUP | NO_IDLE | AUTO_GATE), (GPIO1_CONFIG_BASE + GPIO1_SYSCONFIG));

    /* GPIO1 - enable */
    writel(0x0, (GPIO1_CONFIG_BASE + GPIO1_CTRL));

    /* GPIO1 - set pins to input */
    reg = readl((GPIO1_CONFIG_BASE + GPIO1_OE));
    writel(reg & BOARD_ID_MASK, (GPIO1_CONFIG_BASE + GPIO1_OE));

    /* GPIO1 - read pins */
    reg = (readl(GPIO1_CONFIG_BASE + GPIO1_DATAIN) & BOARD_ID_MASK) >> BOARD_ID_SHIFT;
    board_id = (reg > 0) ? (juno_board_id)reg : INVALID;

    return board_id;
}

static inline juno_board_id get_board_id(void)
{
    juno_board_id board_id = INVALID;
    /* if (board_id != INVALID) return board_id; */

    if (gpio_request(BOARD_ID_PIN_3, "board_id_pin_3") != 0) return INVALID;
    printf("%s: gpio 3 requested\n", __func__);
    if (gpio_request(BOARD_ID_PIN_2, "board_id_pin_2") != 0) return INVALID;
    printf("%s: gpio 2 requested\n", __func__);
    if (gpio_request(BOARD_ID_PIN_1, "board_id_pin_1") != 0) return INVALID;
    printf("%s: gpio 1 requested\n", __func__);
    if (gpio_request(BOARD_ID_PIN_0, "board_id_pin_0") != 0) return INVALID;

    printf("%s: gpios requested\n", __func__);

    if (gpio_direction_input(BOARD_ID_PIN_3) != 0) return INVALID;
    printf("%s: gpio 3 direction set\n", __func__);
    if (gpio_direction_input(BOARD_ID_PIN_2) != 0) return INVALID;
    printf("%s: gpio 2 direction set\n", __func__);
    if (gpio_direction_input(BOARD_ID_PIN_1) != 0) return INVALID;
    printf("%s: gpio 1 direction set\n", __func__);
    if (gpio_direction_input(BOARD_ID_PIN_0) != 0) return INVALID;

    printf("%s: gpios set to input\n", __func__);

    board_id = (juno_board_id)
        gpio_get_value(BOARD_ID_PIN_3) << 3 |
        gpio_get_value(BOARD_ID_PIN_2) << 2 |
        gpio_get_value(BOARD_ID_PIN_1) << 1 |
        gpio_get_value(BOARD_ID_PIN_0);

    return board_id;
}

#endif
