/*
 * Copyright (C) 2018 PHYTEC America, LLC - https://www.phytec.com
 *
 * Based on board/ti/am65x/evm.c
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <environment.h>
#include <dm.h>
#include <asm/arch/utils.h>
#include <asm/io.h>
#include <spl.h>
#include <usb.h>
#include <debug_uart.h>
#include <dt-bindings/pinctrl/k3-am6.h>
#include <power/regulator.h>

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_DEBUG_UART_OMAP
void board_debug_uart_init(void)
{
	/*
	 * NOTE: For the PADCONFIG registers on K3 to be accessible the
	 * corresponding CTRL_MMR region must have gotten unlocked first.
	 */

	/* (P4) MCU_OSPI1_D1.MCU_UART0_RXD */
	writel(PIN_INPUT | MUX_MODE4,
	       WKUP_CTRL_MMR0_BASE + CTRLMMR_PADCONFIG(17));

	/* (P5) MCU_OSPI1_D2.MCU_UART0_TXD */
	writel(PIN_OUTPUT | MUX_MODE4,
	       WKUP_CTRL_MMR0_BASE + CTRLMMR_PADCONFIG(18));

	/* (P1) MCU_OSPI_D3.MCU_UART0_CTSn */
	writel(PIN_INPUT | MUX_MODE4,
	       WKUP_CTRL_MMR0_BASE + CTRLMMR_PADCONFIG(19));

	/* (N3) MCU_OSPI1_CSn1.MCU_UART0_RTSn */
	writel(PIN_OUTPUT | MUX_MODE4,
	       WKUP_CTRL_MMR0_BASE + CTRLMMR_PADCONFIG(21));
}
#endif

int gpio_fan_enable(void)
{
	struct udevice *regulator;
	int ret;

	ret = regulator_get_by_platname("gpio-fan", &regulator);
	if (ret) {
		printf("%s: can't get regulator 'gpio-fan': %d\n", __func__,
			ret);

		return ret;
	}

	ret = regulator_set_value(regulator, 3300000);
	if (ret) {
		printf("%s: can't set 'gpio-fan' regulator to 3.3V: %d\n",
			__func__, ret);

		return ret;
	}

	return 0;
}

int board_init(void)
{
	int ret;

	/* enable carrier board GPIO fan */
	ret = gpio_fan_enable();

	return ret;
}

int dram_init(void)
{
	gd->ram_size = 0x80000000;

	return 0;
}

ulong board_get_usable_ram_top(ulong total_size)
{
#ifdef CONFIG_PHYS_64BIT
	/* Limit RAM used by U-Boot to the DDR low region */
	if (gd->ram_top > 0x100000000)
		return 0x100000000;
#endif

	return gd->ram_top;
}

int dram_init_banksize(void)
{
	/* Bank 0 declares the memory available in the DDR low region */
	gd->bd->bi_dram[0].start = CONFIG_SYS_SDRAM_BASE;
	gd->bd->bi_dram[0].size = 0x80000000;

	return 0;
}

#ifdef CONFIG_SPL_LOAD_FIT
int board_fit_config_name_match(const char *name)
{
#ifdef CONFIG_TARGET_AM65XX_PHYCORE_KIT_A53
	if (!strcmp(name, "k3-am65xx-phycore-kit"))
		return 0;
#endif
#ifdef CONFIG_TARGET_AM65XX_PHYCORE_KIT_R5
	if (!strcmp(name, "k3-am65xx-phycore-kit-r5"))
		return 0;
#endif

	return -1;
}
#endif

#ifdef CONFIG_USB_DWC3
int board_usb_init(int index, enum usb_init_type init)
{
	struct udevice *dev;
	int ret;

	if (init != USB_INIT_DEVICE)
		return 0;

	ret = uclass_get_device(UCLASS_USB_DEV_GENERIC, index, &dev);
	if (!dev || ret) {
		printf("No USB device found\n");
		return -ENODEV;
	}

	return 0;
}
#endif

int board_late_init(void)
{
	k3_set_fastboot_vars();

	return 0;
}

int do_board_detect(void)
{
	return 0;
}

#if defined(CONFIG_USB_FUNCTION_FASTBOOT) && !defined(CONFIG_ENV_IS_NOWHERE)
int fb_set_reboot_flag(void)
{
	printf("Setting reboot to fastboot flag ...\n");
	env_set("dofastboot", "1");
	env_save();
	return 0;
}
#endif
