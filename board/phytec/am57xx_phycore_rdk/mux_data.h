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

	/* SDIO (MMC3) */
	{MMC3_CLK, (M0 | PIN_INPUT_PULLUP)},	/* mmc3_clk.clk */
	{MMC3_CMD, (M0 | PIN_INPUT_PULLUP)},	/* mmc3_cmd.cmd */
	{MMC3_DAT0, (M0 | PIN_INPUT_PULLUP)},	/* mmc3_dat0.dat0 */
	{MMC3_DAT1, (M0 | PIN_INPUT_PULLUP)},	/* mmc3_dat1.dat1 */
	{MMC3_DAT2, (M0 | PIN_INPUT_PULLUP)},	/* mmc3_dat2.dat2 */
	{MMC3_DAT3, (M0 | PIN_INPUT_PULLUP)},	/* mmc3_dat3.dat3 */

	/* BT_EN */
	{MMC3_DAT4, (M14 | PIN_OUTPUT_PULLDOWN)},	/* mmc3_dat4.gpio1_22 */
	/* WLAN EN */
	{MMC3_DAT6, (M14 | PIN_OUTPUT_PULLDOWN)},	/* mmc3_dat6.gpio1_24 */
	/* WLAN_IRQ */
	{MMC3_DAT7, (M14 | PIN_INPUT_PULLUP)},		/* mmc3_dat7.gpio1_15 */

	/* MDIO bus */
	{MDIO_MCLK, (M0 | PIN_INPUT_PULLUP)},	/* mdio_mclk  */
	{MDIO_D, (M0 | PIN_INPUT_PULLUP)},	/* mdio_d  */

	/* ETH0 (RGMII0) */
	{RGMII0_TXC, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* rgmii0_txc.rgmii0_txc */
	{RGMII0_TXCTL, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},/* rgmii0_txctl.rgmii0_txctl */
	{RGMII0_TXD3, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* rgmii0_txd3.rgmii0_txd3 */
	{RGMII0_TXD2, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* rgmii0_txd2.rgmii0_txd2 */
	{RGMII0_TXD1, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* rgmii0_txd1.rgmii0_txd1 */
	{RGMII0_TXD0, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* rgmii0_txd0.rgmii0_txd0 */
	{RGMII0_RXC, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* rgmii0_rxc.rgmii0_rxc */
	{RGMII0_RXCTL, (M0 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},/* rgmii0_rxctl.rgmii0_rxctl */
	{RGMII0_RXD3, (M0 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* rgmii0_rxd3.rgmii0_rxd3 */
	{RGMII0_RXD2, (M0 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* rgmii0_rxd2.rgmii0_rxd2 */
	{RGMII0_RXD1, (M0 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* rgmii0_rxd1.rgmii0_rxd1 */
	{RGMII0_RXD0, (M0 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* rgmii0_rxd0.rgmii0_rxd0 */
	/* nETH0_RST */
	{RMII_MHZ_50_CLK, (M14 | PIN_INPUT_PULLUP)}, 		/* rmii_mhz_50_clk.gpio5_17 */
	/* ETH0 IRQ */
	{VIN2A_CLK0, (M14 | PIN_INPUT)},			/* vin2a_clk0.gpio3_28 */

	/* ETH1 (RGMII1) */
	{VIN2A_D12, (M3 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* vin2a_d12.rgmii1_txc */
	{VIN2A_D13, (M3 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* vin2a_d13.rgmii1_txctl */
	{VIN2A_D14, (M3 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* vin2a_d14.rgmii1_txd3 */
	{VIN2A_D15, (M3 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* vin2a_d15.rgmii1_txd2 */
	{VIN2A_D16, (M3 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* vin2a_d16.rgmii1_txd1 */
	{VIN2A_D17, (M3 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* vin2a_d17.rgmii1_txd0 */
	{VIN2A_D18, (M3 | PIN_INPUT_PULLDOWN | MANUAL_MODE)},	/* vin2a_d18.rgmii1_rxc */
	{VIN2A_D19, (M3 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* vin2a_d19.rgmii1_rxctl */
	{VIN2A_D20, (M3 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* vin2a_d20.rgmii1_rxd3 */
	{VIN2A_D21, (M3 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* vin2a_d21.rgmii1_rxd2 */
	{VIN2A_D22, (M3 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* vin2a_d22.rgmii1_rxd1 */
	{VIN2A_D23, (M3 | PIN_INPUT_PULLUP | MANUAL_MODE)},	/* vin2a_d23.rgmii1_rxd0 */
	/* ETH1 IRQ */
	{GPMC_A12, (M14 | PIN_INPUT)},				/* gpmc_a12.gpio2_2 */

	/* USB1 and USB2 DRVVBUS */
	{USB1_DRVVBUS, (M0 | PIN_INPUT_SLEW)},	/* usb1_drvvbus.usb1_drvvbus */
	{USB2_DRVVBUS, (M0 | PIN_INPUT_SLEW)},	/* usb2_drvvbus.usb2_drvvbus */

	/* QSPI NOR (QSPI1) */
	{GPMC_A18, (M1 | PIN_INPUT_PULLDOWN)},  /* gpmc_a18.qspi1_sclk */
	{GPMC_A16, (M1 | PIN_INPUT_PULLDOWN)},  /* gpmc_a16.qspi1_d0 */
	{GPMC_A17, (M1 | PIN_INPUT_PULLDOWN)},  /* gpmc_a17.qspi1_d1 */
	{GPMC_A15, (M1 | PIN_INPUT_PULLDOWN)},  /* gpmc_a15.qspi1_d2 */
	{GPMC_A14, (M1 | PIN_INPUT_PULLDOWN)},  /* gpmc_a14.qspi1_d3 */
	{GPMC_A3, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_a3.qspi1_cs2 */

	/* QSPI1 expansion chip selects */
	{GPMC_CS2, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_cs2.qspi1_cs0 */
	{GPMC_CS3, (M1 | PIN_INPUT_PULLUP)},	/* gpmc_cs3.qspi1_cs1*/

	/* LCD display (vout2) */
	{VIN2A_DE0, (M4 | PIN_OUTPUT)},		/* vin2a_de0.vout2_de */
	{VIN2A_FLD0, (M4 | PIN_OUTPUT)},	/* vin2a_fld0.vout2_clk */
	{VIN2A_HSYNC0, (M4 | PIN_OUTPUT)},	/* vin2a_hsync0.vout2_hsync */
	{VIN2A_VSYNC0, (M4 | PIN_OUTPUT)},	/* vin2a_vsync0.vout2_vsync */
	{MCASP1_ACLKR, (M6 | PIN_OUTPUT)},	/* mcasp1_aclkr.vout2_d0 */
	{MCASP1_FSR, (M6 | PIN_OUTPUT)},	/* mcasp1_fsr.vout2_d1 */
	{MCASP1_AXR2, (M6 | PIN_OUTPUT)},	/* mcasp1_axr2.vout2_d2 */
	{MCASP1_AXR3, (M6 | PIN_OUTPUT)},	/* mcasp1_axr3.vout2_d3 */
	{MCASP1_AXR4, (M6 | PIN_OUTPUT)},	/* mcasp1_axr4.vout2_d4 */
	{MCASP1_AXR5, (M6 | PIN_OUTPUT)},	/* mcasp1_axr5.vout2_d5 */
	{MCASP1_AXR6, (M6 | PIN_OUTPUT)},	/* mcasp1_axr6.vout2_d6 */
	{MCASP1_AXR7, (M6 | PIN_OUTPUT)},	/* mcasp1_axr7.vout2_d7 */
	{MCASP2_ACLKR, (M6 | PIN_OUTPUT)},	/* mcasp2_aclkr.vout2_d8 */
	{MCASP2_FSR, (M6 | PIN_OUTPUT)},	/* mcasp2_fsr.vout2_d9 */
	{MCASP2_AXR0, (M6 | PIN_OUTPUT)},	/* mcasp2_axr0.vout2_d10 */
	{MCASP2_AXR1, (M6 | PIN_OUTPUT)},	/* mcasp2_axr1.vout2_d11 */
	{MCASP2_AXR4, (M6 | PIN_OUTPUT)},	/* mcasp2_axr4.vout2_d12 */
	{MCASP2_AXR5, (M6 | PIN_OUTPUT)},	/* mcasp2_axr5.vout2_d13 */
	{MCASP2_AXR6, (M6 | PIN_OUTPUT)},	/* mcasp2_axr6.vout2_d14 */
	{MCASP2_AXR7, (M6 | PIN_OUTPUT)},	/* mcasp2_axr7.vout2_d15 */
	{MCASP4_ACLKX, (M6 | PIN_OUTPUT)},	/* mcasp4_aclkx.vout2_d16 */
	{MCASP4_FSX, (M6 | PIN_OUTPUT)},	/* mcasp4_fsx.vout2_d17 */
	{MCASP4_AXR0, (M6 | PIN_OUTPUT)},	/* mcasp4_axr0.vout2_d18 */
	{MCASP4_AXR1, (M6 | PIN_OUTPUT)},	/* mcasp4_axr1.vout2_d19 */
	{MCASP5_ACLKX, (M6 | PIN_OUTPUT)},	/* mcasp5_aclkx.vout2_d20 */
	{MCASP5_FSX, (M6 | PIN_OUTPUT)},	/* mcasp5_fsx.vout2_d21 */
	{MCASP5_AXR0, (M6 | PIN_OUTPUT)},	/* mcasp5_axr0.vout2_d22 */
	{MCASP5_AXR1, (M6 | PIN_OUTPUT)},	/* mcasp5_axr1.vout2_d23 */
	/* LCD EN */
	{VOUT1_D23, (M14 | PIN_OUTPUT_PULLDOWN)},	/* vout1_d23.gpio8_23 */
	/* Backlight PWM */
	{VIN1A_D0, (M10 | PIN_OUTPUT_PULLDOWN)},	/* vin1a_d0.ehrpwm1A */
	/* EDT Touch IRQ */
	{VOUT1_D22, (M14 | PIN_INPUT_PULLUP)},		/* vout1_d22.gpio8_22 */

	/* PCIe PERSTn/PWRGD */
	{VOUT1_D4, (M14 | PIN_INPUT_PULLDOWN)},	/* vout1_d4.gpio8_4 */
	/* PCIe (U28-OE) */
	{VOUT1_D7, (M14 | PIN_INPUT_PULLUP)},	/* vout1_d7.gpio8_7 */

	/* VTT_EN */
	{VIN2A_D7, (M14 | PIN_OUTPUT)},		/* vin2a_d7.gpio4_8 */

	{ON_OFF, (M1 | PIN_OUTPUT_PULLUP)},	/* on_off.on_off */
	{RTC_PORZ, (M0 | PIN_OUTPUT_PULLDOWN)},	/* rtc_porz.rtc_porz */
	{RTCK, (M0 | PIN_INPUT_PULLDOWN)},	/* rtck.rtck */
};

const struct pad_conf_entry early_padconf[] = {
	/* RS232 (UART3) */
	{UART3_RXD, (M0 | PIN_INPUT_SLEW)}, /* UART3_RXD */
	{UART3_TXD, (M0 | PIN_INPUT_SLEW)}, /* UART3_TXD */

	/* I2C1 */
	{I2C1_SDA, (M0 | PIN_INPUT_PULLUP)},	/* I2C1_SDA */
	{I2C1_SCL, (M0 | PIN_INPUT_PULLUP)},	/* I2C1_SCL */
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
	{0x06F0, 471, 0},       /* CFG_RGMII0_RXC_IN */
	{0x06FC, 30, 1919},     /* CFG_RGMII0_RXCTL_IN */
	{0x0708, 74, 1688},     /* CFG_RGMII0_RXD0_IN */
	{0x0714, 94, 1697},     /* CFG_RGMII0_RXD1_IN */
	{0x0720, 0, 1703},      /* CFG_RGMII0_RXD2_IN */
	{0x072C, 70, 1804},     /* CFG_RGMII0_RXD3_IN */
	{0x0740, 90, 70},       /* CFG_RGMII0_TXC_OUT */
	{0x074C, 70, 70},       /* CFG_RGMII0_TXCTL_OUT */
	{0x0758, 180, 70},      /* CFG_RGMII0_TXD0_OUT */
	{0x0764, 35, 70},       /* CFG_RGMII0_TXD1_OUT */
	{0x0770, 0, 0},         /* CFG_RGMII0_TXD2_OUT */
	{0x077C, 180, 70},      /* CFG_RGMII0_TXD3_OUT */
	{0x0A70, 65, 70},       /* CFG_VIN2A_D12_OUT */
	{0x0A7C, 125, 70},      /* CFG_VIN2A_D13_OUT */
	{0x0A88, 0, 70},        /* CFG_VIN2A_D14_OUT */
	{0x0A94, 0, 70},        /* CFG_VIN2A_D15_OUT */
	{0x0AA0, 65, 70},       /* CFG_VIN2A_D16_OUT */
	{0x0AAC, 0, 0},         /* CFG_VIN2A_D17_OUT */
	{0x0AB0, 612, 0},       /* CFG_VIN2A_D18_IN */
	{0x0ABC, 4, 927},       /* CFG_VIN2A_D19_IN */
	{0x0AD4, 136, 1340},    /* CFG_VIN2A_D20_IN */
	{0x0AE0, 130, 1450},    /* CFG_VIN2A_D21_IN */
	{0x0AEC, 144, 1269},    /* CFG_VIN2A_D22_IN */
	{0x0AF8, 0, 1330},      /* CFG_VIN2A_D23_IN */
};
#endif
#endif /* _MUX_DATA_PCM057_H_ */
