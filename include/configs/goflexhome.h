/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2022 Tony Dinh <mibodhi@gmai.com>
 * Copyright (C) 2013 Suriyan Ramasami <suriyan.r@gmail.com>
 *
 * Based on dockstar.h originally written by
 * Copyright (C) 2010  Eric C. Cooper <ecc@cmu.edu>
 *
 * Based on sheevaplug.h originally written by
 * Prafulla Wadaskar <prafulla@marvell.com>
 * (C) Copyright 2009
 * Marvell Semiconductor <www.marvell.com>
 */

#ifndef _CONFIG_GOFLEXHOME_H
#define _CONFIG_GOFLEXHOME_H

#include <linux/bitops.h>

/*
 * Default GPIO configuration and LED status
 */
#define GOFLEXHOME_OE_LOW               (~(0))
#define GOFLEXHOME_OE_HIGH              (~(0))
#define GOFLEXHOME_OE_VAL_LOW		BIT(29)		/* USB_PWEN low */
#define GOFLEXHOME_OE_VAL_HIGH          BIT(17)		/* LED pin high */

#include "mv-common.h"

/*
 * Default environment variables
 */

#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=console=ttyS0,115200\0" \
	"mtdids=nand0=orion_nand\0" \
	"mtdparts=" CONFIG_MTDPARTS_DEFAULT \
	"kernel=/boot/uImage\0" \
	"bootargs_root=ubi.mtd=root root=ubi0:root rootfstype=ubifs ro\0"

/*
 * Ethernet Driver configuration
 */
#define CONFIG_MVGBE_PORTS	{1, 0}	/* enable port 0 only */
#define CONFIG_PHY_BASE_ADR	0
#ifdef CONFIG_RESET_PHY_R
#undef CONFIG_RESET_PHY_R      /* remove legacy reset_phy() */
#endif

/* SATA driver configuration */
#define CONFIG_LBA48

#endif /* _CONFIG_GOFLEXHOME_H */
