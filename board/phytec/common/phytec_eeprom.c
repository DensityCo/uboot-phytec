/*
 * Copyright (C) 2017 PHYTEC America, LLC
 *
 * Based on board/ti/common/board_detect.c
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <i2c.h>
#include "phytec_eeprom.h"

__weak void gpi2c_init(void)
{
}

static int __maybe_unused phytec_i2c_eeprom_init(int i2c_bus, int dev_addr)
{
	int rc;

	if (i2c_bus >= 0) {
		rc = i2c_set_bus_num(i2c_bus);
		if (rc)
			return rc;
	}

	return i2c_probe(dev_addr);
}

int __maybe_unused phytec_i2c_eeprom_get(int i2c_bus, int dev_addr)
{
	struct phytec_common_eeprom *ep;
	uint32_t addr_len;
	int rc;
#ifndef CONFIG_SPL_BUILD
	struct udevice *i2c_dev;
#endif

	ep = PHYTEC_EEPROM_DATA;

	if (ep->header == PHYTEC_EEPROM_HEADER_MAGIC)
		return 0;	/* EEPROM has already been read */

	gpi2c_init();
	rc = phytec_i2c_eeprom_init(i2c_bus, dev_addr);
	if (rc)
		return rc;

	/* Set header to PHYTEC_DEAD_EEPROM_MAGIC to check for read failure */
	ep->header = PHYTEC_DEAD_EEPROM_MAGIC;
	/* Ensure fall-through to defaults on EEPROM read failure */
	memset(&ep->kit_opt, 0xFF, 11);

	addr_len = 2;
#ifndef CONFIG_SPL_BUILD
	rc = i2c_get_chip_for_busnum(i2c_bus, dev_addr, addr_len, &i2c_dev);

	if (rc)
		printf("%s: i2c_get_chip_for_busnum failed: %d\n",
			__func__, rc);

	rc = i2c_set_chip_offset_len(i2c_dev, addr_len);
	if (rc)
		printf("%s: i2c_set_chip_offset_len failed: %d\n",
			__func__, rc);
#endif
	rc = i2c_read(dev_addr, 0x0, addr_len, (uint8_t *)ep, PHYTEC_EEPROM_SIZE);

	/* If EEPROM read fails */
	if (rc || ep->header == PHYTEC_DEAD_EEPROM_MAGIC)
		return rc;

	return 0;
}

int __maybe_unused phytec_i2c_eeprom_set(int i2c_bus, int dev_addr,
		struct phytec_common_eeprom *ep)
{
	int rc;
	uint32_t addr_len;
#ifndef CONFIG_SPL_BUILD
	struct udevice *i2c_dev;
#endif

	if (!ep || ep->header != PHYTEC_EEPROM_HEADER_MAGIC)
		return -EINVAL;

	rc = phytec_i2c_eeprom_init(i2c_bus, dev_addr);
	if (rc)
		return rc;

	addr_len = 2;
#ifndef CONFIG_SPL_BUILD
	rc = i2c_get_chip_for_busnum(i2c_bus, dev_addr, addr_len, &i2c_dev);

	if (rc)
		printf("%s: i2c_get_chip_for_busnum failed: %d\n",
			__func__, rc);

	rc = i2c_set_chip_offset_len(i2c_dev, 2);
	if (rc)
		printf("%s: i2c_set_chip_offset_len failed: %d\n",
			__func__, rc);
#endif

	rc = i2c_write(dev_addr, 0x0, addr_len,
			(uint8_t *)ep, PHYTEC_EEPROM_SIZE);

	return 0;
}

int __maybe_unused phytec_i2c_eeprom_compare(int i2c_bus, int dev_addr,
		struct phytec_common_eeprom *ep)
{
	int rc;
	struct phytec_common_eeprom *phytec_ep;

	if (!ep)
		return -EINVAL;

	rc = phytec_i2c_eeprom_get(i2c_bus, dev_addr);

	if (rc) {
		printf("%s: phytec_i2c_eeprom_get failed: %d\n",
			__func__, rc);
		return rc;
	}

	phytec_ep = PHYTEC_EEPROM_DATA;

	if (ep->header != phytec_ep->header)
		return -EINVAL;

	if (ep->api_version != phytec_ep->api_version)
		return -EINVAL;

	if (ep->mod_version != phytec_ep->mod_version)
		return -EINVAL;

	if (ep->som_pcb_rev != phytec_ep->som_pcb_rev)
		return -EINVAL;

	rc = strncmp((const char *)ep->mac, (const char *)phytec_ep->mac, 6);
	if (rc)
		return -EINVAL;

	if (ep->ksp != phytec_ep->ksp)
		return -EINVAL;

	if (ep->kspno != phytec_ep->kspno)
		return -EINVAL;

	rc = strncmp((const char *)ep->kit_opt,
			(const char *)phytec_ep->kit_opt, 11);
	if (rc)
		return -EINVAL;

	if (ep->bs != phytec_ep->bs)
		return -EINVAL;

	return 0;
}
