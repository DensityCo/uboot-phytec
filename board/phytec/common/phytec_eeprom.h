/*
 * Copyright (C) 2017 PHYTEC America, LLC
 *
 * Based on board/ti/common/board_detect.h
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __PHYTEC_EEPROM_H
#define __PHYTEC_EEPROM_H

#ifndef PHYTEC_SRAM_SCRATCH_BOARD_EEPROM_START
#define PHYTEC_SRAM_SCRATCH_BOARD_EEPROM_START (SRAM_SCRATCH_SPACE_ADDR + 0x28)
#define PHYTEC_SRAM_SCRATCH_BOARD_EEPROM_END (SRAM_SCRATCH_SPACE_ADDR + 0x200)
#endif

#define PHYTEC_EEPROM_DATA ((struct phytec_common_eeprom *)\
		PHYTEC_SRAM_SCRATCH_BOARD_EEPROM_START)

#define PHYTEC_EEPROM_HEADER_MAGIC	0x07052017
#define PHYTEC_DEAD_EEPROM_MAGIC	0xDEADDEAD

#define PHYTEC_EEPROM_SIZE	32

/* struct phytec_common_eeprom represents PHYTEC boards and config options */
struct phytec_common_eeprom {
	uint32_t header;		/* PHYTEC EEPROM header */
	unsigned char api_version;	/* EEPROM layout API version */
	unsigned char mod_version;	/* PCM/PFL/PCA */
	unsigned char som_pcb_rev;	/* SOM PCB revision */
	unsigned char mac[6];
	unsigned char ksp;		/* 1: KSP, 2: KSM */
	unsigned char kspno;		/* Number for KSP/KSM module */
	unsigned char kit_opt[11];	/* coding for variants */
	unsigned char reserved[5];	/* not used */
	unsigned char bs;		/* Bits set in previous bytes */
} __attribute__ ((__packed__));
/* sizeof(struct phytec_common_eeprom) == 32 */

/**
 * phytec_i2c_eeprom_get() - EEPROM data collection for PHYTEC SoMs
 * @i2c_bus:	target I2C bus address
 * @dev_addr:	target I2C device address
 *
 * ep in SRAM EEPROM scratch is populated by this function for board
 * identification and hardware initialization/configuration.
 */
int __maybe_unused phytec_i2c_eeprom_get(int i2c_bus, int dev_addr);

/**
 * phytec_i2c_eeprom_set() - EEPROM data write for PHYTEC SoMs
 * @i2c_bus:	target I2C bus address
 * @dev_addr:	target I2C device address
 *
 * Target EEPROM is written to at addr 0x0 from ep. ep header must match
 * PHYTEC_EEPROM_HEADER_MAGIC or write will not proceed.
 */
int __maybe_unused phytec_i2c_eeprom_set(int i2c_bus, int dev_addr,
		struct phytec_common_eeprom *ep);

/**
 * phytec_i2c_eeprom_compare() - compare PHYTEC-defined eeprom structs
 * @i2c_bus:	target I2C bus address
 * @dev_addr:	target I2C device address
 *
 * Currently-stored EEPROM information it retrieved and compared to EEPROM
 * struct pointed to by ep.
 */
int __maybe_unused phytec_i2c_eeprom_compare(int i2c_bus, int dev_addr,
		struct phytec_common_eeprom *ep);

#endif /* __PHYTEC_EEPROM_H */
