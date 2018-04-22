/*
 * (C) Copyright 2015 PHYTEC America, LLC
 * Author: Russell Robinson <rrobinson@phytec.com>
 *
 * Configuration settings for the PHYTEC phyCORE-AM572x RDK.
 * See ti_omap5_common.h for omap5 common settings.
 *
 * Based on include/configs/beagle_x15.h
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_AM572X_PHYCORE_RDKH
#define __CONFIG_AM572X_PHYCORE_RDKH

#define CONFIG_DRA7XX

#define CONFIG_IODELAY_RECALIBRATION

#define CONFIG_BOARD_EARLY_INIT_F

#define CONFIG_VERY_BIG_RAM
#define CONFIG_PHYS_64BIT
#define CONFIG_MAX_MEM_MAPPED		0x80000000
#define CONFIG_NR_DRAM_BANKS		2

/* Store environment on SD card by default
 *
 * To store the u-boot environment in eMMC instead of
 * SD, uncomment the CONFIG_ENV_IS_IN_MMC line below
 * and comment the CONFIG_ENV_IS_IN_FAT line instead
 */
/* #define CONFIG_ENV_IS_IN_MMC */
#define CONFIG_ENV_IS_IN_FAT

#define CONFIG_ENV_SIZE			(64 << 10)

#ifdef CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		1
#define CONFIG_ENV_OFFSET		0x200000
#define CONFIG_ENV_OFFSET_REDUND	0x210000
#endif

#ifdef CONFIG_ENV_IS_IN_FAT
#define FAT_ENV_INTERFACE		"mmc"
#define FAT_ENV_DEVICE_AND_PART		"0:1"
#define FAT_ENV_FILE			"uboot.env"
#endif

#define CONSOLEDEV			"ttyO2"
#define CONFIG_SYS_NS16550_COM1		UART1_BASE	/* Base EVM has UART0 */
#define CONFIG_SYS_NS16550_COM2		UART2_BASE	/* UART2 */
#define CONFIG_SYS_NS16550_COM3		UART3_BASE	/* UART3 */
#define CONFIG_BAUDRATE			115200

#define CONFIG_SYS_OMAP_ABE_SYSCK

/*
 * Environment setup
 */
/* Define the default GPT table for eMMC */
#define PARTS_DEFAULT \
	"uuid_disk=${uuid_gpt_disk};" \
	"name=env,start=2MiB,size=1MiB,uuid=${uuid_gpt_env};" \
	"name=rootfs,start=3MiB,size=-,uuid=${uuid_gpt_rootfs}"

#define DFU_ALT_INFO_MMC \
	"dfu_alt_info_mmc=" \
	"boot part 0 1;" \
	"rootfs part 0 2;" \
	"MLO fat 0 1;" \
	"MLO.raw raw 0x100 0x100;" \
	"u-boot.img.raw raw 0x300 0x800;" \
	"spl-os-args.raw raw 0x80 0x80;" \
	"spl-os-image.raw raw 0x1400 0x2000;" \
	"spl-os-args fat 0 1;" \
	"spl-os-image fat 0 1;" \
	"u-boot.img fat 0 1;" \
	"uEnv.txt fat 0 1\0"

#define DFU_ALT_INFO_EMMC \
	"dfu_alt_info_emmc=" \
	"rawemmc raw 0 3751936;" \
	"boot part 1 1;" \
	"rootfs part 1 2;" \
	"MLO fat 1 1;" \
	"MLO.raw raw 0x100 0x100;" \
	"u-boot.img.raw raw 0x300 0x800;" \
	"spl-os-args.raw raw 0x80 0x80;" \
	"spl-os-image.raw raw 0x1400 0x2000;" \
	"spl-os-args fat 1 1;" \
	"spl-os-image fat 1 1;" \
	"u-boot.img fat 1 1;" \
	"uEnv.txt fat 1 1\0"

#define DFU_ALT_INFO_QSPI \
	"dfu_alt_info_qspi=" \
	"MLO raw 0x0 0x040000;" \
	"u-boot.img raw 0x040000 0x0100000;" \
	"u-boot-spl-os raw 0x140000 0x080000;" \
	"u-boot-env raw 0x1C0000 0x010000;" \
	"u-boot-env.backup raw 0x1D0000 0x010000;" \
	"kernel raw 0x1E0000 0x800000\0"

#define DFU_ALT_INFO_RAM \
	"dfu_alt_info_ram=" \
	"kernel ram 0x80200000 0x4000000;" \
	"fdt ram 0x80f80000 0x80000;" \
	"ramdisk ram 0x81000000 0x4000000\0"

#define DFUARGS \
	"dfu_bufsiz=0x10000\0" \
	DFU_ALT_INFO_MMC \
	DFU_ALT_INFO_EMMC \
	DFU_ALT_INFO_QSPI \
	DFU_ALT_INFO_RAM

#define CONFIG_EXTRA_ENV_SETTINGS \
	DEFAULT_LINUX_BOOT_ENV \
	DEFAULT_MMC_TI_ARGS \
	DEFAULT_FIT_TI_ARGS \
	"console=" CONSOLEDEV ",115200n8\0" \
	"fdtfile=undefined\0" \
	"bootpart=0:2\0" \
	"bootdir=/boot\0" \
	"bootfile=zImage\0" \
	"usbtty=cdc_acm\0" \
	"vram=16M\0" \
	"partitions=" PARTS_DEFAULT "\0" \
	"optargs=\0" \
	"dofastboot=0\0" \
	"boot_net=run findfdt; " \
		"run netboot;\0" \
	"netboot=echo Booting from network ...; " \
		"tftp ${loadaddr} ${tftploc}${bootfile}; " \
		"tftp ${fdtaddr} ${tftploc}${fdtfile}; " \
		"run netargs; " \
		"bootz ${loadaddr} - ${fdtaddr}\0" \
	"override_board=\0" \
	"findfdt="\
		"if test $board_name = am572x_phycore_rdk; then " \
			"setenv fdtfile am572x-phycore-rdk.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_41300111i; then " \
			"setenv fdtfile am572x-phycore-rdk-41300111i.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_41201111i; then " \
			"setenv fdtfile am572x-phycore-rdk-41201111i.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_40201111i; then " \
			"setenv fdtfile am572x-phycore-rdk-40201111i.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_50201111i; then " \
			"setenv fdtfile am572x-phycore-rdk-50201111i.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_50500111i; then " \
			"setenv fdtfile am572x-phycore-rdk-50500111i.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_10200110i; then " \
			"setenv fdtfile am572x-phycore-rdk-10200110i.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_40200110c; then " \
			"setenv fdtfile am572x-phycore-rdk-40200110c.dtb; fi;" \
		"if test $board_name = am572x_phycore_rdk_40a00111i; then " \
			"setenv fdtfile am572x-phycore-rdk-40a00111i.dtb; fi;" \
		"if test $fdtfile = undefined; then " \
			"echo WARNING: Could not determine device tree to use; fi; \0" \
	DFUARGS \
	NETARGS \

#define CONFIG_BOOTCOMMAND \
	"if test ${dofastboot} -eq 1; then " \
		"echo Boot fastboot requested, resetting dofastboot ...;" \
		"setenv dofastboot 0; saveenv;" \
		"echo Booting into fastboot ...; fastboot 0;" \
	"fi;" \
	"if test ${boot_fit} -eq 1; then " \
		"run update_to_fit;" \
	"fi;" \
	"run findfdt; " \
	"run envboot; " \
	"run mmcboot;" \
	"setenv mmcdev 1; setenv bootpart 1:2; run mmcboot" \
	""

#include <configs/ti_omap5_common.h>

/* Enhance our eMMC support / experience. */
#define CONFIG_CMD_GPT
#define CONFIG_EFI_PARTITION
#define CONFIG_RANDOM_UUID
#define CONFIG_HSMMC2_8BIT

/* CPSW Ethernet */
#define CONFIG_BOOTP_DNS		/* Configurable parts of CMD_DHCP */
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_NET_RETRY_COUNT		10
#define CONFIG_DRIVER_TI_CPSW		/* Driver for IP block */
#define CONFIG_MII			/* Required in net/eth.c */
#define CONFIG_PHY_GIGE			/* per-board part of CPSW */
#define CONFIG_PHYLIB
#define PHY_ANEG_TIMEOUT	16000	/* PHY needs longer aneg time at 1G */

#define CONFIG_CMD_MEMTEST
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + \
						0x10000000)

#define CONFIG_SUPPORT_EMMC_BOOT

/* USB xHCI HOST */
#define CONFIG_USB_XHCI_OMAP
#define CONFIG_SYS_USB_XHCI_MAX_ROOT_PORTS 2

#define CONFIG_OMAP_USB_PHY
#define CONFIG_OMAP_USB3PHY1_HOST

/* SATA */
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_CMD_SCSI
#define CONFIG_LIBATA
#define CONFIG_SCSI_AHCI
#define CONFIG_SCSI_AHCI_PLAT
#define CONFIG_SYS_SCSI_MAX_SCSI_ID	1
#define CONFIG_SYS_SCSI_MAX_LUN		1
#define CONFIG_SYS_SCSI_MAX_DEVICE	(CONFIG_SYS_SCSI_MAX_SCSI_ID * \
						CONFIG_SYS_SCSI_MAX_LUN)

/* EEPROM */
#define CONFIG_EEPROM_BUS_ADDRESS	0
#define CONFIG_EEPROM_CHIP_ADDRESS	0x50

/*
 * Default to using SPI for environment, etc.
 * 0x000000 - 0x040000 : QSPI.SPL (256KiB)
 * 0x040000 - 0x140000 : QSPI.u-boot (1MiB)
 * 0x140000 - 0x1C0000 : QSPI.u-boot-spl-os (512KiB)
 * 0x1C0000 - 0x1D0000 : QSPI.u-boot-env (64KiB)
 * 0x1D0000 - 0x1E0000 : QSPI.u-boot-env.backup1 (64KiB)
 * 0x1E0000 - 0x9E0000 : QSPI.kernel (8MiB)
 * 0x9E0000 - 0x2000000 : USERLAND
 */
#define CONFIG_SYS_SPI_KERNEL_OFFS      0x1E0000
#define CONFIG_SYS_SPI_ARGS_OFFS        0x140000
#define CONFIG_SYS_SPI_ARGS_SIZE        0x80000

/* SPI SPL */
#define CONFIG_TI_EDMA3
#define CONFIG_SPL_SPI_LOAD
#define CONFIG_SYS_SPI_U_BOOT_OFFS     0x40000

/* SPI */
#undef	CONFIG_OMAP3_SPI
#define CONFIG_TI_SPI_MMAP
#define CONFIG_SF_DEFAULT_SPEED                76800000
#define CONFIG_SF_DEFAULT_MODE                 SPI_MODE_0
#define CONFIG_QSPI_QUAD_SUPPORT

#endif /* __CONFIG_AM572X_PHYCORE_RDK_H */
