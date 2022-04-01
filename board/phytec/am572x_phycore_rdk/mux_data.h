/*
 * Copyright (C) 2015 PHYTEC America, LLC
 * Author: Russell Robinson <rrobinson@phytec.com>
 *
 * Based on board/ti/beagle_x15/mux_data.h
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef _MUX_DATA_PCM057_H_
#define _MUX_DATA_PCM057_H_

#include <asm/arch/mux_dra7xx.h>

const struct pad_conf_entry core_padconf_array_essential[] = {
	/* SD Card Slot (MMC1) */
	{MMC1_CLK, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_clk.clk */
	{MMC1_CMD, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_cmd.cmd */
	{MMC1_DAT0, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat0.dat0 */
	{MMC1_DAT1, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat1.dat1 */
	{MMC1_DAT2, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat2.dat2 */
	{MMC1_DAT3, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_dat3.dat3 */
	{MMC1_SDCD, (M0 | PIN_INPUT_PULLUP)},	/* mmc1_sdcd.sdcd */
	{MMC1_SDWP, (M14 | PIN_INPUT_PULLDOWN)},/* mmc1_sdwp.gpio6_28 */

	/* eMMC (MMC2) */
	{GPMC_A19, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a19.mmc2_dat4 */
	{GPMC_A20, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a20.mmc2_dat5 */
	{GPMC_A21, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a21.mmc2_dat6 */
	{GPMC_A22, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a22.mmc2_dat7 */
	{GPMC_A23, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a23.mmc2_clk */
	{GPMC_A24, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a24.mmc2_dat0 */
	{GPMC_A25, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a25.mmc2_dat1 */
	{GPMC_A26, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a26.mmc2_dat2 */
	{GPMC_A27, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a27.mmc2_dat3 */
	{GPMC_CS1, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_cs1.mmc2_cmd */

	/* MDIO bus */
	{MDIO_MCLK, (M0 | PIN_OUTPUT)},	/* mdio_mclk  */
	{MDIO_D, (M0 | PIN_INPUT)},	/* mdio_d  */

	/* ETH0 (RGMII0) */
	{RGMII0_TXC, (M0 | PIN_OUTPUT | MANUAL_MODE)},	/* rgmii0_txc.rgmii0_txc */
	{RGMII0_TXCTL, (M0 | PIN_OUTPUT | MANUAL_MODE)},/* rgmii0_txctl.rgmii0_txctl */
	{RGMII0_TXD3, (M0 | PIN_OUTPUT | MANUAL_MODE)},	/* rgmii0_txd3.rgmii0_txd3 */
	{RGMII0_TXD2, (M0 | PIN_OUTPUT | MANUAL_MODE)},	/* rgmii0_txd2.rgmii0_txd2 */
	{RGMII0_TXD1, (M0 | PIN_OUTPUT | MANUAL_MODE)},	/* rgmii0_txd1.rgmii0_txd1 */
	{RGMII0_TXD0, (M0 | PIN_OUTPUT | MANUAL_MODE)},	/* rgmii0_txd0.rgmii0_txd0 */
	{RGMII0_RXC, (M0 | PIN_INPUT | MANUAL_MODE)},	/* rgmii0_rxc.rgmii0_rxc */
	{RGMII0_RXCTL, (M0 | PIN_INPUT | MANUAL_MODE)},/* rgmii0_rxctl.rgmii0_rxctl */
	{RGMII0_RXD3, (M0 | PIN_INPUT | MANUAL_MODE)},	/* rgmii0_rxd3.rgmii0_rxd3 */
	{RGMII0_RXD2, (M0 | PIN_INPUT | MANUAL_MODE)},	/* rgmii0_rxd2.rgmii0_rxd2 */
	{RGMII0_RXD1, (M0 | PIN_INPUT | MANUAL_MODE)},	/* rgmii0_rxd1.rgmii0_rxd1 */
	{RGMII0_RXD0, (M0 | PIN_INPUT | MANUAL_MODE)},	/* rgmii0_rxd0.rgmii0_rxd0 */
	/* nETH0_RST */
	{RMII_MHZ_50_CLK, (M14 | PIN_INPUT_PULLUP)}, 		/* rmii_mhz_50_clk.gpio5_17 */
	/* ETH0 IRQ */
	{VIN2A_CLK0, (M14 | PIN_INPUT)},			/* vin2a_clk0.gpio3_28 */

	/* USB1 and USB2 DRVVBUS */
	{USB1_DRVVBUS, (M0 | PIN_OUTPUT)},	/* usb1_drvvbus.usb1_drvvbus */
	{USB2_DRVVBUS, (M0 | PIN_OUTPUT_PULLDOWN)},	/* usb2_drvvbus.usb2_drvvbus */

	/* QSPI NOR (QSPI1) */
	{GPMC_A18, (M1 | PIN_INPUT)},  /* gpmc_a18.qspi1_sclk */
	{GPMC_A16, (M1 | PIN_INPUT)},  /* gpmc_a16.qspi1_d0 */
	{GPMC_A17, (M1 | PIN_INPUT)},  /* gpmc_a17.qspi1_d1 */
	{GPMC_A15, (M1 | PIN_INPUT_PULLUP)},  /* gpmc_a15.qspi1_d2 */
	{GPMC_A14, (M1 | PIN_INPUT_PULLUP)},  /* gpmc_a14.qspi1_d3 */
	{GPMC_A13, (M1 | PIN_INPUT)},  /* gpmc_a13.qspi1_rtclk */
	{GPMC_A3, (M1 | PIN_OUTPUT)},	/* gpmc_a3.qspi1_cs2 */

	/* QSPI1 expansion chip selects */
	{GPMC_CS2, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_cs2.qspi1_cs0 */
	{GPMC_CS3, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_cs3.qspi1_cs1*/

	/* VTT_EN */
	{VIN2A_D7, (M14 | PIN_OUTPUT)},		/* vin2a_d7.gpio4_8 */

	/* 5V TOF */
	{VIN2A_D4, (M14 | PIN_OUTPUT)},		/* vin2a_d4.gpio4_5 */

	{ON_OFF, (M1 | PIN_OUTPUT)},	/* on_off.on_off */
	{RTC_PORZ, (M0 | PIN_INPUT)},	/* rtc_porz.rtc_porz */
	{RTCK, (M0 | PIN_OUTPUT)},	/* rtck.rtck */
	{EMU0, (M0 | PIN_INPUT)},	/* emu0.emu0 */
	{EMU1, (M0 | PIN_INPUT)},	/* emu1.emu1 */
	{NMIN_DSP, (M0 | PIN_INPUT)},	/* nmin_dsp.nmin_dsp */
	{RSTOUTN, (M0 | PIN_OUTPUT)},	/* rstoutn.rstoutn */

};

const struct pad_conf_entry early_padconf[] = {
	/* RS232 (UART3) */
	{UART3_RXD, (M0 | PIN_INPUT_SLEW)}, /* UART3_RXD */
	{UART3_TXD, (M0 | PIN_INPUT_SLEW)}, /* UART3_TXD */

	/* I2C1 */
	{I2C1_SDA, (M0 | PIN_INPUT_PULLUP)},	/* I2C1_SDA */
	{I2C1_SCL, (M0 | PIN_INPUT_PULLUP)},	/* I2C1_SCL */

	/* I2C3 */
	{GPIO6_10, (M2 | PIN_INPUT_PULLUP)},	/* I2C3_SDA */
	{GPIO6_11, (M2 | PIN_INPUT_PULLUP)},	/* I2C3_SCL */
};

#ifdef CONFIG_IODELAY_RECALIBRATION
const struct iodelay_cfg_entry iodelay_cfg_array_sr1_1[] = {
	{0x0114, 2980, 0},	/* CFG_GPMC_A0_IN */
	{0x0120, 2648, 0},	/* CFG_GPMC_A10_IN */
	{0x012C, 2918, 0},	/* CFG_GPMC_A11_IN */
	{0x0198, 2917, 0},	/* CFG_GPMC_A1_IN */
	{0x0204, 3156, 178},	/* CFG_GPMC_A2_IN */
	{0x0210, 3109, 246},	/* CFG_GPMC_A3_IN */
	{0x021C, 3142, 100},	/* CFG_GPMC_A4_IN */
	{0x0228, 3084, 33},	/* CFG_GPMC_A5_IN */
	{0x0234, 2778, 0},	/* CFG_GPMC_A6_IN */
	{0x0240, 3110, 0},	/* CFG_GPMC_A7_IN */
	{0x024C, 2874, 0},	/* CFG_GPMC_A8_IN */
	{0x0258, 3072, 0},	/* CFG_GPMC_A9_IN */
	{0x0264, 2466, 0},	/* CFG_GPMC_AD0_IN */
	{0x0270, 2523, 0},	/* CFG_GPMC_AD10_IN */
	{0x027C, 2453, 0},	/* CFG_GPMC_AD11_IN */
	{0x0288, 2285, 0},	/* CFG_GPMC_AD12_IN */
	{0x0294, 2206, 0},	/* CFG_GPMC_AD13_IN */
	{0x02A0, 1898, 0},	/* CFG_GPMC_AD14_IN */
	{0x02AC, 2473, 0},	/* CFG_GPMC_AD15_IN */
	{0x02B8, 2307, 0},	/* CFG_GPMC_AD1_IN */
	{0x02C4, 2691, 0},	/* CFG_GPMC_AD2_IN */
	{0x02D0, 2384, 0},	/* CFG_GPMC_AD3_IN */
	{0x02DC, 2462, 0},	/* CFG_GPMC_AD4_IN */
	{0x02E8, 2335, 0},	/* CFG_GPMC_AD5_IN */
	{0x02F4, 2370, 0},	/* CFG_GPMC_AD6_IN */
	{0x0300, 2389, 0},	/* CFG_GPMC_AD7_IN */
	{0x030C, 2672, 0},	/* CFG_GPMC_AD8_IN */
	{0x0318, 2334, 0},	/* CFG_GPMC_AD9_IN */
	{0x06F0, 480, 0},	/* CFG_RGMII0_RXC_IN */
	{0x06FC, 111, 1641},	/* CFG_RGMII0_RXCTL_IN */
	{0x0708, 272, 1116},	/* CFG_RGMII0_RXD0_IN */
	{0x0714, 243, 1260},	/* CFG_RGMII0_RXD1_IN */
	{0x0720, 0, 1614},	/* CFG_RGMII0_RXD2_IN */
	{0x072C, 105, 1673},	/* CFG_RGMII0_RXD3_IN */
	{0x0740, 531, 120},	/* CFG_RGMII0_TXC_OUT */
	{0x074C, 201, 60},	/* CFG_RGMII0_TXCTL_OUT */
	{0x0758, 229, 120},	/* CFG_RGMII0_TXD0_OUT */
	{0x0764, 141, 0},	/* CFG_RGMII0_TXD1_OUT */
	{0x0770, 495, 120},	/* CFG_RGMII0_TXD2_OUT */
	{0x077C, 660, 120},	/* CFG_RGMII0_TXD3_OUT */
	{0x0A70, 1551, 115},	/* CFG_VIN2A_D12_OUT */
	{0x0A7C, 816, 0},	/* CFG_VIN2A_D13_OUT */
	{0x0A88, 876, 0},	/* CFG_VIN2A_D14_OUT */
	{0x0A94, 312, 0},	/* CFG_VIN2A_D15_OUT */
	{0x0AA0, 58, 0},	/* CFG_VIN2A_D16_OUT */
	{0x0AAC, 0, 0},		/* CFG_VIN2A_D17_OUT */
	{0x0AB0, 702, 0},	/* CFG_VIN2A_D18_IN */
	{0x0ABC, 136, 976},	/* CFG_VIN2A_D19_IN */
	{0x0AD4, 210, 1357},	/* CFG_VIN2A_D20_IN */
	{0x0AE0, 189, 1462},	/* CFG_VIN2A_D21_IN */
	{0x0AEC, 232, 1278},	/* CFG_VIN2A_D22_IN */
	{0x0AF8, 0, 1397},	/* CFG_VIN2A_D23_IN */
};

const struct iodelay_cfg_entry iodelay_cfg_array_sr2_0[] = {
	{0x0114, 2519, 702},    /* CFG_GPMC_A0_IN */
	{0x0120, 2435, 411},    /* CFG_GPMC_A10_IN */
	{0x012C, 2379, 755},    /* CFG_GPMC_A11_IN */
	{0x0198, 2384, 778},    /* CFG_GPMC_A1_IN */
	{0x0204, 2499, 1127},   /* CFG_GPMC_A2_IN */
	{0x0210, 2455, 1181},   /* CFG_GPMC_A3_IN */
	{0x021C, 2486, 1039},   /* CFG_GPMC_A4_IN */
	{0x0228, 2456, 938},    /* CFG_GPMC_A5_IN */
	{0x0234, 2463, 573},    /* CFG_GPMC_A6_IN */
	{0x0240, 2608, 783},    /* CFG_GPMC_A7_IN */
	{0x024C, 2430, 656},    /* CFG_GPMC_A8_IN */
	{0x0258, 2465, 850},    /* CFG_GPMC_A9_IN */
	{0x0264, 2316, 301},    /* CFG_GPMC_AD0_IN */
	{0x0270, 2324, 406},    /* CFG_GPMC_AD10_IN */
	{0x027C, 2278, 352},    /* CFG_GPMC_AD11_IN */
	{0x0288, 2297, 160},    /* CFG_GPMC_AD12_IN */
	{0x0294, 2278, 108},    /* CFG_GPMC_AD13_IN */
	{0x02A0, 2035, 0},      /* CFG_GPMC_AD14_IN */
	{0x02AC, 2279, 378},    /* CFG_GPMC_AD15_IN */
	{0x02B8, 2440, 70},     /* CFG_GPMC_AD1_IN */
	{0x02C4, 2404, 446},    /* CFG_GPMC_AD2_IN */
	{0x02D0, 2343, 212},    /* CFG_GPMC_AD3_IN */
	{0x02DC, 2355, 322},    /* CFG_GPMC_AD4_IN */
	{0x02E8, 2337, 192},    /* CFG_GPMC_AD5_IN */
	{0x02F4, 2270, 314},    /* CFG_GPMC_AD6_IN */
	{0x0300, 2339, 259},    /* CFG_GPMC_AD7_IN */
	{0x030C, 2308, 577},    /* CFG_GPMC_AD8_IN */
	{0x0318, 2334, 166},    /* CFG_GPMC_AD9_IN */
	{0x06F0, 260, 0},       /* CFG_RGMII0_RXC_IN */
	{0x06FC, 0, 1412},      /* CFG_RGMII0_RXCTL_IN */
	{0x0708, 123, 1047},    /* CFG_RGMII0_RXD0_IN */
	{0x0714, 139, 1081},    /* CFG_RGMII0_RXD1_IN */
	{0x0720, 195, 1100},    /* CFG_RGMII0_RXD2_IN */
	{0x072C, 239, 1216},    /* CFG_RGMII0_RXD3_IN */
	{0x0740, 89, 0},        /* CFG_RGMII0_TXC_OUT */
	{0x074C, 15, 125},      /* CFG_RGMII0_TXCTL_OUT */
	{0x0758, 339, 162},     /* CFG_RGMII0_TXD0_OUT */
	{0x0764, 146, 94},      /* CFG_RGMII0_TXD1_OUT */
	{0x0770, 0, 27},        /* CFG_RGMII0_TXD2_OUT */
	{0x077C, 291, 205},     /* CFG_RGMII0_TXD3_OUT */
	{0x0A70, 0, 0},         /* CFG_VIN2A_D12_OUT */
	{0x0A7C, 219, 101},     /* CFG_VIN2A_D13_OUT */
	{0x0A88, 92, 58},       /* CFG_VIN2A_D14_OUT */
	{0x0A94, 135, 100},     /* CFG_VIN2A_D15_OUT */
	{0x0AA0, 154, 101},     /* CFG_VIN2A_D16_OUT */
	{0x0AAC, 78, 27},       /* CFG_VIN2A_D17_OUT */
	{0x0AB0, 411, 0},       /* CFG_VIN2A_D18_IN */
	{0x0ABC, 0, 382},       /* CFG_VIN2A_D19_IN */
	{0x0AD4, 320, 750},     /* CFG_VIN2A_D20_IN */
	{0x0AE0, 192, 836},     /* CFG_VIN2A_D21_IN */
	{0x0AEC, 294, 669},     /* CFG_VIN2A_D22_IN */
	{0x0AF8, 5, 700},       /* CFG_VIN2A_D23_IN */
};
#endif
#endif /* _MUX_DATA_PCM057_H_ */
