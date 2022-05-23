/* =========================================================================					
 *   Copyright (C) 2017-2019 Texas Instruments Incorporated					
 *					
 *   All rights reserved. Property of Texas Instruments Incorporated.					
 *   Restricted rights to use, duplicate or disclose this code are					
 *   granted through contract.					
 *					
 *   The program may not be used without the written permission					
 *   of Texas Instruments Incorporated or against the terms and conditions					
 *   stipulated in the agreement under which this program has been					
 *   supplied.					
 * ========================================================================= */					
					
/*					
 *  AM571x_DDR3L_532MHz_DENSITY_LUNA_S5b_512MB_config.c					
 *     Created on: 05/20/2022					
 *     Created with: EMIF_RegisterConfig_v2.0.3					
 */					
					
					
const struct ctrl_ioregs AM571x_DDR3L_532MHz_DENSITY_LUNA_S5b_512MB_ctrl_ioregs = {					
    .ctrl_ddr3ch = 0x60606060,					
    .ctrl_ddrch = 0x40404040,					
    .ctrl_ddrio_0 = 0x00094A40,					
    .ctrl_ddrio_1 = 0x00000000,					
    .ctrl_lpddr2ch = 0x00404000,					
    .ctrl_emif_sdram_config_ext = 0x0002C123					
};					
					
const struct dmm_lisa_map_regs AM571x_DDR3L_532MHz_DENSITY_LUNA_S5b_512MB_dmm_regs = {					
    .dmm_lisa_map_0 = 0x00000000,					
    .dmm_lisa_map_1 = 0x00000000,					
    .dmm_lisa_map_2 = 0x80500100,					
    .dmm_lisa_map_3 = 0xFF020100,					
    .is_ma_present = 0x1					
};					
					
const struct emif_regs AM571x_DDR3L_532MHz_DENSITY_LUNA_S5b_512MB_emif_regs = {					
    .sdram_config_init = 0x61855B32,
    .sdram_config = 0x61855B32,
    .sdram_config2 = 0x00000000,
    .ref_ctrl = 0x100040F1,
    .ref_ctrl_final = 0x10001035,
    .sdram_tim1 = 0xCCCF36B3,
    .sdram_tim2 = 0x308F7FDA,
    .sdram_tim3 = 0x407F88A8,
    .read_idle_ctrl = 0x00050000,
    .zq_config = 0x5007190B,
    .temp_alert_config = 0x00000000,
	.emif_ddr_phy_ctlr_1_init = 0x0024400b,
	.emif_ddr_phy_ctlr_1	= 0x0e24400b,
	.emif_ddr_ext_phy_ctrl_1 = 0x10040100,
	.emif_ddr_ext_phy_ctrl_2 = 0x00910091,
	.emif_ddr_ext_phy_ctrl_3 = 0x00950095,
	.emif_ddr_ext_phy_ctrl_4 = 0x009b009b,
	.emif_ddr_ext_phy_ctrl_5 = 0x009e009e,
	.emif_rd_wr_lvl_rmp_win	= 0x00000000,
	.emif_rd_wr_lvl_rmp_ctl	= 0x80000000,
	.emif_rd_wr_lvl_ctl	= 0x00000000,
	.emif_rd_wr_exec_thresh	= 0x00000305			
					
};					
					
/*					
 * DLL Ratio Values are an estimate based on trace lengths.					
 * Hardware leveling should be performed to determine					
 * final DLL values.					
 */					
const unsigned int AM571x_DDR3L_532MHz_DENSITY_LUNA_S5b_512MB_emif1_ext_phy_regs [] = {					
    0x04040100,	/* EMIF1_EXT_PHY_CTRL_1 */	
    0x006B008D,	/* EMIF1_EXT_PHY_CTRL_2 */	
    0x006B008B,	/* EMIF1_EXT_PHY_CTRL_3 */	
    0x006B006B,	/* EMIF1_EXT_PHY_CTRL_4 */	
    0x006B006B,	/* EMIF1_EXT_PHY_CTRL_5 */	
    0x006B006B,	/* EMIF1_EXT_PHY_CTRL_6 */	
    0x002F002F,	/* EMIF1_EXT_PHY_CTRL_7 */	
    0x002F002F,	/* EMIF1_EXT_PHY_CTRL_8 */	
    0x002F002F,	/* EMIF1_EXT_PHY_CTRL_9 */	
    0x002F002F,	/* EMIF1_EXT_PHY_CTRL_10 */	
    0x002F002F,	/* EMIF1_EXT_PHY_CTRL_11 */	
    0x00600070,	/* EMIF1_EXT_PHY_CTRL_12 */	
    0x00600071,	/* EMIF1_EXT_PHY_CTRL_13 */	
    0x00600060,	/* EMIF1_EXT_PHY_CTRL_14 */	
    0x00600060,	/* EMIF1_EXT_PHY_CTRL_15 */	
    0x00600060,	/* EMIF1_EXT_PHY_CTRL_16 */	
    0x00400050,	/* EMIF1_EXT_PHY_CTRL_17 */	
    0x00400051,	/* EMIF1_EXT_PHY_CTRL_18 */	
    0x00400040,	/* EMIF1_EXT_PHY_CTRL_19 */	
    0x00400040,	/* EMIF1_EXT_PHY_CTRL_20 */	
    0x00400040,	/* EMIF1_EXT_PHY_CTRL_21 */	
    0x00800080,	/* EMIF1_EXT_PHY_CTRL_22 */	
    0x00800080,	/* EMIF1_EXT_PHY_CTRL_23 */	
    0x40010080,	/* EMIF1_EXT_PHY_CTRL_24 */	
    0x08102040,	/* EMIF1_EXT_PHY_CTRL_25 */	
    0x0000007D,	/* EMIF1_EXT_PHY_CTRL_26 */	
    0x0000007B,	/* EMIF1_EXT_PHY_CTRL_27 */	
    0x00000000,	/* EMIF1_EXT_PHY_CTRL_28 */	
    0x00000000,	/* EMIF1_EXT_PHY_CTRL_29 */	
    0x00000000,	/* EMIF1_EXT_PHY_CTRL_30 */	
    0x00000040,	/* EMIF1_EXT_PHY_CTRL_31 */	
    0x00000041,	/* EMIF1_EXT_PHY_CTRL_32 */	
    0x00000000,	/* EMIF1_EXT_PHY_CTRL_33 */	
    0x00000000,	/* EMIF1_EXT_PHY_CTRL_34 */	
    0x00000000,	/* EMIF1_EXT_PHY_CTRL_35 */	
    0x00000077	/* EMIF1_EXT_PHY_CTRL_36 */				
};					
