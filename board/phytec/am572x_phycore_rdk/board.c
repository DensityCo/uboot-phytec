/*
 * Copyright (C) 2015 PHYTEC America, LLC
 * Author: Russell Robinson <rrobinson@phytec.com>
 *
 * Based on board/ti/beagle_x15/board.c
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <palmas.h>
#include <sata.h>
#include <usb.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch/dra7xx_iodelay.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sata.h>
#include <asm/arch/gpio.h>
#include <asm/arch/omap.h>
#include <environment.h>
#include <usb.h>
#include <linux/usb/gadget.h>
#include <dwc3-uboot.h>
#include <dwc3-omap-uboot.h>
#include <ti-usb-phy-uboot.h>

#include "emif_config.h"
#include "mux_data.h"
#include "../common/phytec_eeprom.h"

#ifdef CONFIG_DRIVER_TI_CPSW
#include <cpsw.h>
#endif

DECLARE_GLOBAL_DATA_PTR;

#define GPIO_DDR_VTT_EN 104 /* vin2a_d7.gpio4_8 */

const struct omap_sysinfo sysinfo = {
	"Board: phyCORE-AM572x RDK\n"
};

void emif_get_dmm_regs(const struct dmm_lisa_map_regs **dmm_lisa_regs)
{
	struct phytec_common_eeprom *ep;
	uint8_t ecc_opt;
	int rc;

	rc = phytec_i2c_eeprom_get(CONFIG_EEPROM_BUS_ADDRESS,
			CONFIG_EEPROM_CHIP_ADDRESS);
	if (rc)
		printf("%s: I2C read failed! "
			"Using fallback defaults.\n", __func__);
	ep = PHYTEC_EEPROM_DATA;

	/* ECC board population option at ep->kit_opt[1] for am572x */
	ecc_opt = ep->kit_opt[1];

	switch (ecc_opt) {
	case 0:
		*dmm_lisa_regs = &am572x_phycore_rdk_1Gx2_lisa_regs;
		break;
	case 1:
		*dmm_lisa_regs = &am572x_phycore_rdk_1Gx2_ECC_lisa_regs;
		break;
	default:
#if (defined(CONFIG_PCM_057_256M16_x4_DDR) || \
	defined(CONFIG_PCM_057_512M16_x4_DDR))
		*dmm_lisa_regs = &am572x_phycore_rdk_1Gx2_lisa_regs;
#endif
	}
}

void emif_get_reg_dump(u32 emif_nr, const struct emif_regs **regs)
{
	struct phytec_common_eeprom *ep;
	uint8_t ddr3_opt;
	int rc;

	rc = phytec_i2c_eeprom_get(CONFIG_EEPROM_BUS_ADDRESS,
			CONFIG_EEPROM_CHIP_ADDRESS);
	if (rc)
		printf("%s: I2C read failed! "
			"Using fallback defaults.\n", __func__);
	ep = PHYTEC_EEPROM_DATA;

	/* ddr3 board population option at ep->kit_opt[0] for am572x */
	ddr3_opt = ep->kit_opt[0];

	switch (ddr3_opt) {
	case 4:
		*regs = &am572x_phycore_rdk_emif_532mhz_256M16_regs;
		break;
	case 5:
		*regs = &am572x_phycore_rdk_emif_532mhz_512M16_regs;
		break;
	default:
#if defined(CONFIG_PCM_057_256M16_x4_DDR)
		*regs = &am572x_phycore_rdk_emif_532mhz_256M16_regs;
#elif defined(CONFIG_PCM_057_512M16_x4_DDR)
		*regs = &am572x_phycore_rdk_emif_532mhz_512M16_regs;
#endif
	}
}

void emif_get_ext_phy_ctrl_const_regs(u32 emif_nr, const u32 **regs, u32 *size)
{
	*regs = am572x_phycore_rdk_emif_ext_phy_ctrl_const_regs;
	*size = ARRAY_SIZE(am572x_phycore_rdk_emif_ext_phy_ctrl_const_regs);
}

struct vcores_data am572x_phycore_rdk_volts = {
	.mpu.value[OPP_NOM]	= VDD_MPU_DRA7_NOM,
	.mpu.efuse.reg[OPP_NOM]	= STD_FUSE_OPP_VMIN_MPU_NOM,
	.mpu.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.mpu.addr		= TPS659038_REG_ADDR_SMPS12,
	.mpu.pmic		= &tps659038,
	.mpu.abb_tx_done_mask	= OMAP_ABB_MPU_TXDONE_MASK,

	.eve.value[OPP_NOM]	= VDD_EVE_DRA7_NOM,
	.eve.value[OPP_OD]	= VDD_EVE_DRA7_OD,
	.eve.value[OPP_HIGH]	= VDD_EVE_DRA7_HIGH,
	.eve.efuse.reg[OPP_NOM]	= STD_FUSE_OPP_VMIN_DSPEVE_NOM,
	.eve.efuse.reg[OPP_OD]	= STD_FUSE_OPP_VMIN_DSPEVE_OD,
	.eve.efuse.reg[OPP_HIGH]	= STD_FUSE_OPP_VMIN_DSPEVE_HIGH,
	.eve.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.eve.addr		= TPS659038_REG_ADDR_SMPS45,
	.eve.pmic		= &tps659038,
	.eve.abb_tx_done_mask	= OMAP_ABB_EVE_TXDONE_MASK,

	.gpu.value[OPP_NOM]	= VDD_GPU_DRA7_NOM,
	.gpu.value[OPP_OD]	= VDD_GPU_DRA7_OD,
	.gpu.value[OPP_HIGH]	= VDD_GPU_DRA7_HIGH,
	.gpu.efuse.reg[OPP_NOM]	= STD_FUSE_OPP_VMIN_GPU_NOM,
	.gpu.efuse.reg[OPP_OD]	= STD_FUSE_OPP_VMIN_GPU_OD,
	.gpu.efuse.reg[OPP_HIGH]	= STD_FUSE_OPP_VMIN_GPU_HIGH,
	.gpu.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.gpu.addr		= TPS659038_REG_ADDR_SMPS45,
	.gpu.pmic		= &tps659038,
	.gpu.abb_tx_done_mask	= OMAP_ABB_GPU_TXDONE_MASK,

	.core.value[OPP_NOM]	= VDD_CORE_DRA7_NOM,
	.core.efuse.reg[OPP_NOM]	= STD_FUSE_OPP_VMIN_CORE_NOM,
	.core.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.core.addr		= TPS659038_REG_ADDR_SMPS6,
	.core.pmic		= &tps659038,

	.iva.value[OPP_NOM]	= VDD_IVA_DRA7_NOM,
	.iva.value[OPP_OD]	= VDD_IVA_DRA7_OD,
	.iva.value[OPP_HIGH]	= VDD_IVA_DRA7_HIGH,
	.iva.efuse.reg[OPP_NOM]	= STD_FUSE_OPP_VMIN_IVA_NOM,
	.iva.efuse.reg[OPP_OD]	= STD_FUSE_OPP_VMIN_IVA_OD,
	.iva.efuse.reg[OPP_HIGH]	= STD_FUSE_OPP_VMIN_IVA_HIGH,
	.iva.efuse.reg_bits	= DRA752_EFUSE_REGBITS,
	.iva.addr		= TPS659038_REG_ADDR_SMPS45,
	.iva.pmic		= &tps659038,
	.iva.abb_tx_done_mask	= OMAP_ABB_IVA_TXDONE_MASK,
};

void hw_data_init(void)
{
	*prcm = &dra7xx_prcm;
	*dplls_data = &dra7xx_dplls;
	*omap_vcores = &am572x_phycore_rdk_volts;
	*ctrl = &dra7xx_ctrl;
}

int board_init(void)
{
	gpmc_init();
	gd->bd->bi_boot_params = (CONFIG_SYS_SDRAM_BASE + 0x100);

	return 0;
}

void dram_init_banksize(void)
{
	struct phytec_common_eeprom *ep;
	uint8_t ddr3_opt;
	u64 ram_size;
	int rc;

	rc = phytec_i2c_eeprom_get(CONFIG_EEPROM_BUS_ADDRESS,
			CONFIG_EEPROM_CHIP_ADDRESS);
	if (rc)
		printf("%s: I2C read failed! "
			"Using fallback defaults.\n", __func__);

	ep = PHYTEC_EEPROM_DATA;

	/* ddr3 board population option at ep->kit_opt[0] for am572x */
	ddr3_opt = ep->kit_opt[0];

	switch (ddr3_opt) {
	case 4:
		ram_size = 0x80000000;
		break;
	case 5:
		ram_size = 0x100000000;
		break;
	default:
#if defined(CONFIG_PCM_057_256M16_x4_DDR)
		ram_size = 0x80000000;
#elif defined(CONFIG_PCM_057_512M16_x4_DDR)
		ram_size = 0x100000000;
#endif
	}

	gd->bd->bi_dram[0].start = CONFIG_SYS_SDRAM_BASE;
	gd->bd->bi_dram[0].size = get_effective_memsize();
	if (ram_size > CONFIG_MAX_MEM_MAPPED) {
		gd->bd->bi_dram[1].start = 0x200000000;
		gd->bd->bi_dram[1].size = ram_size - CONFIG_MAX_MEM_MAPPED;
	}
}

int board_late_init(void)
{
	/*
	 * DEV_CTRL.DEV_ON = 1 please - else palmas switches off in 8 seconds
	 * This is the POWERHOLD-in-Low behavior.
	 */
	palmas_i2c_write_u8(TPS65903X_CHIP_P1, 0xA0, 0x1);

	if (get_device_type() == HS_DEVICE)
		setenv("boot_fit", "1");

	return 0;
}

void set_muxconf_regs(void)
{
	do_set_mux32((*ctrl)->control_padconf_core_base,
			early_padconf, ARRAY_SIZE(early_padconf));
}

#ifdef CONFIG_SPL_BUILD
void do_board_detect(void)
{
	int rc;
	rc = phytec_i2c_eeprom_get(CONFIG_EEPROM_BUS_ADDRESS,
			CONFIG_EEPROM_CHIP_ADDRESS);
	if (rc)
		printf("%s: phytec_i2c_eeprom_get failed %d\n",
			__func__, rc);
}
#endif

#ifdef CONFIG_IODELAY_RECALIBRATION
void recalibrate_iodelay(void)
{
	const struct iodelay_cfg_entry *iod;
	int iod_sz;
	int ret;

	/* Setup I/O isolation */
	ret = __recalibrate_iodelay_start();
	if (ret)
		goto err;

	/* Do the muxing here */
	do_set_mux32((*ctrl)->control_padconf_core_base,
			core_padconf_array_essential,
			ARRAY_SIZE(core_padconf_array_essential));

	if (omap_revision() == DRA752_ES1_1) {
		iod = iodelay_cfg_array_sr1_1;
		iod_sz = ARRAY_SIZE(iodelay_cfg_array_sr1_1);
	} else {
		iod = iodelay_cfg_array_sr2_0;
		iod_sz = ARRAY_SIZE(iodelay_cfg_array_sr2_0);
	}

	/* Setup IOdelay configuration */
	ret = do_set_iodelay((*ctrl)->iodelay_config_base, iod, iod_sz);

err:
	/* Closeup.. remove isolation */
	__recalibrate_iodelay_end(ret);
}
#endif

#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_GENERIC_MMC)
int board_mmc_init(bd_t *bis)
{
	omap_mmc_init(0, 0, 0, -1, -1);
	omap_mmc_init(1, 0, 0, -1, -1);

	return 0;
}
#endif

#ifdef CONFIG_OMAP_HSMMC
int platform_fixup_disable_uhs_mode(void)
{
	return omap_revision() == DRA752_ES1_1;
}
#endif

#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_OS_BOOT)
int spl_start_uboot(void)
{
	/* break into full u-boot on 'c' */
	if (serial_tstc() && serial_getc() == 'c')
		return 1;

#ifdef CONFIG_SPL_ENV_SUPPORT
	env_init();
	env_relocate_spec();
	if (getenv_yesno("boot_os") != 1)
		return 1;
#endif

	return 0;
}
#endif

#ifdef CONFIG_USB_DWC3
static struct dwc3_device usb_otg_ss1 = {
	.maximum_speed = USB_SPEED_SUPER,
	.base = DRA7_USB_OTG_SS1_BASE,
	.tx_fifo_resize = false,
	.index = 0,
};

static struct dwc3_omap_device usb_otg_ss1_glue = {
	.base = (void *)DRA7_USB_OTG_SS1_GLUE_BASE,
	.utmi_mode = DWC3_OMAP_UTMI_MODE_SW,
	.index = 0,
};

static struct ti_usb_phy_device usb_phy1_device = {
	.pll_ctrl_base = (void *)DRA7_USB3_PHY1_PLL_CTRL,
	.usb2_phy_power = (void *)DRA7_USB2_PHY1_POWER,
	.usb3_phy_power = (void *)DRA7_USB3_PHY1_POWER,
	.index = 0,
};

static struct dwc3_device usb_otg_ss2 = {
	.maximum_speed = USB_SPEED_HIGH,
	.base = DRA7_USB_OTG_SS2_BASE,
	.tx_fifo_resize = false,
	.index = 1,
};

static struct dwc3_omap_device usb_otg_ss2_glue = {
	.base = (void *)DRA7_USB_OTG_SS2_GLUE_BASE,
	.utmi_mode = DWC3_OMAP_UTMI_MODE_SW,
	.index = 1,
};

static struct ti_usb_phy_device usb_phy2_device = {
	.usb2_phy_power = (void *)DRA7_USB2_PHY2_POWER,
	.index = 1,
};

int usb_gadget_handle_interrupts(int index)
{
	u32 status;

	status = dwc3_omap_uboot_interrupt_status(index);
	if (status)
		dwc3_uboot_handle_interrupt(index);

	return 0;
}

int board_usb_init(int index, enum usb_init_type init)
{
	enable_usb_clocks(index);
	switch (index) {
	case 0:
		if (init == USB_INIT_DEVICE) {
			printf("port %d can't be used as device\n", index);
			disable_usb_clocks(index);
			return -EINVAL;
		} else {
			usb_otg_ss1.dr_mode = USB_DR_MODE_HOST;
			usb_otg_ss1_glue.vbus_id_status = OMAP_DWC3_ID_GROUND;
		}

		ti_usb_phy_uboot_init(&usb_phy1_device);
		dwc3_omap_uboot_init(&usb_otg_ss1_glue);
		dwc3_uboot_init(&usb_otg_ss1);
		break;
	case 1:
		if (init == USB_INIT_DEVICE) {
			usb_otg_ss2.dr_mode = USB_DR_MODE_PERIPHERAL;
			usb_otg_ss2_glue.vbus_id_status = OMAP_DWC3_VBUS_VALID;
		} else {
			usb_otg_ss2.dr_mode = USB_DR_MODE_HOST;
			usb_otg_ss2_glue.vbus_id_status = OMAP_DWC3_ID_GROUND;
		}

		ti_usb_phy_uboot_init(&usb_phy2_device);
		dwc3_omap_uboot_init(&usb_otg_ss2_glue);
		dwc3_uboot_init(&usb_otg_ss2);
		break;
	default:
		printf("Invalid Controller Index\n");
	}

	return 0;
}

int board_usb_cleanup(int index, enum usb_init_type init)
{
	switch (index) {
	case 0:
	case 1:
		ti_usb_phy_uboot_exit(index);
		dwc3_uboot_exit(index);
		dwc3_omap_uboot_exit(index);
		break;
	default:
		printf("Invalid Controller Index\n");
	}
	disable_usb_clocks(index);
	return 0;
}
#endif /* CONFIG_USB_DWC3 */

#ifdef CONFIG_DRIVER_TI_CPSW

/* Delay value to add to calibrated value */
#define RGMII0_TXCTL_DLY_VAL		((0x3 << 5) + 0x8)
#define RGMII0_TXD0_DLY_VAL		((0x3 << 5) + 0x8)
#define RGMII0_TXD1_DLY_VAL		((0x3 << 5) + 0x2)
#define RGMII0_TXD2_DLY_VAL		((0x4 << 5) + 0x0)
#define RGMII0_TXD3_DLY_VAL		((0x4 << 5) + 0x0)
#define VIN2A_D13_DLY_VAL		((0x3 << 5) + 0x8)
#define VIN2A_D17_DLY_VAL		((0x3 << 5) + 0x8)
#define VIN2A_D16_DLY_VAL		((0x3 << 5) + 0x2)
#define VIN2A_D15_DLY_VAL		((0x4 << 5) + 0x0)
#define VIN2A_D14_DLY_VAL		((0x4 << 5) + 0x0)

static void cpsw_control(int enabled)
{
	/* VTP can be added here */
}

static struct cpsw_slave_data cpsw_slaves[] = {
	{
		.slave_reg_ofs	= 0x208,
		.sliver_reg_ofs	= 0xd80,
		.phy_addr	= 1,
	},
	{
		.slave_reg_ofs	= 0x308,
		.sliver_reg_ofs	= 0xdc0,
		.phy_addr	= 2,
	},
};

static struct cpsw_platform_data cpsw_data = {
	.mdio_base		= CPSW_MDIO_BASE,
	.cpsw_base		= CPSW_BASE,
	.mdio_div		= 0xff,
	.channels		= 8,
	.cpdma_reg_ofs		= 0x800,
	.slaves			= 2,
	.slave_data		= cpsw_slaves,
	.ale_reg_ofs		= 0xd00,
	.ale_entries		= 1024,
	.host_port_reg_ofs	= 0x108,
	.hw_stats_reg_ofs	= 0x900,
	.bd_ram_ofs		= 0x2000,
	.mac_control		= (1 << 5),
	.control		= cpsw_control,
	.host_port_num		= 0,
	.version		= CPSW_CTRL_VERSION_2,
};

int board_eth_init(bd_t *bis)
{
	int ret;
	uint8_t mac_addr[6];
	uint32_t mac_hi, mac_lo;
	uint32_t ctrl_val;

	/* try reading mac address from efuse */
	mac_lo = readl((*ctrl)->control_core_mac_id_0_lo);
	mac_hi = readl((*ctrl)->control_core_mac_id_0_hi);
	mac_addr[0] = (mac_hi & 0xFF0000) >> 16;
	mac_addr[1] = (mac_hi & 0xFF00) >> 8;
	mac_addr[2] = mac_hi & 0xFF;
	mac_addr[3] = (mac_lo & 0xFF0000) >> 16;
	mac_addr[4] = (mac_lo & 0xFF00) >> 8;
	mac_addr[5] = mac_lo & 0xFF;

	if (!getenv("ethaddr")) {
		printf("<ethaddr> not set. Validating first E-fuse MAC\n");

		if (is_valid_ethaddr(mac_addr))
			eth_setenv_enetaddr("ethaddr", mac_addr);
	}

	mac_lo = readl((*ctrl)->control_core_mac_id_1_lo);
	mac_hi = readl((*ctrl)->control_core_mac_id_1_hi);
	mac_addr[0] = (mac_hi & 0xFF0000) >> 16;
	mac_addr[1] = (mac_hi & 0xFF00) >> 8;
	mac_addr[2] = mac_hi & 0xFF;
	mac_addr[3] = (mac_lo & 0xFF0000) >> 16;
	mac_addr[4] = (mac_lo & 0xFF00) >> 8;
	mac_addr[5] = mac_lo & 0xFF;

	if (!getenv("eth1addr")) {
		if (is_valid_ethaddr(mac_addr))
			eth_setenv_enetaddr("eth1addr", mac_addr);
	}

	ctrl_val = readl((*ctrl)->control_core_control_io1) & (~0x33);
	ctrl_val |= 0x22;
	writel(ctrl_val, (*ctrl)->control_core_control_io1);

	ret = cpsw_register(&cpsw_data);
	if (ret < 0)
		printf("Error %d registering CPSW switch\n", ret);

	return ret;
}
#endif

#ifdef CONFIG_BOARD_EARLY_INIT_F
/* VTT regulator enable */
static inline void vtt_regulator_enable(void)
{
	if (omap_hw_init_context() == OMAP_INIT_CONTEXT_UBOOT_AFTER_SPL)
		return;

	gpio_request(GPIO_DDR_VTT_EN, "ddr_vtt_en");
	gpio_direction_output(GPIO_DDR_VTT_EN, 1);
}

int board_early_init_f(void)
{
	vtt_regulator_enable();
	return 0;
}
#endif

#ifdef CONFIG_SPL_LOAD_FIT
int board_fit_config_name_match(const char *name)
{

	if (!strcmp(name, "am572x-phycore-rdk"))
		return 0;
	else if (!strcmp(name, "am572x-phycore-rdk-41300111i"))
		return 0;
	else if (!strcmp(name, "am572x-phycore-rdk-41201111i"))
		return 0;
	else if (!strcmp(name, "am572x-phycore-rdk-40201111i"))
		return 0;
	else if (!strcmp(name, "am572x-phycore-rdk-50201111i"))
		return 0;
	else if (!strcmp(name, "am572x-phycore-rdk-50500111i"))
		return 0;
	else
		return -1;

}
#endif

#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
int ft_board_setup(void *blob, bd_t *bd)
{
	ft_cpu_setup(blob, bd);

	return 0;
}
#endif
