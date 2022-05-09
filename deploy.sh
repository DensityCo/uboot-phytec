#!/bin/bash

DEV_ID=sdc
VOL_ID=635D-40A4
ROOTFS_VOL_ID=9ac10878-a0df-48e3-af57-8e516646794b

cp MLO /media/ebolton/$VOL_ID/ && sync
cp u-boot.img /media/ebolton/$VOL_ID/u-boot.img && sync

./tools/mkenvimage -s 0x10000 -r -o uboot.env uEnv-emmc.txt
cp uboot.env /media/ebolton/$VOL_ID/ && sync

sudo dd if=uboot.env of=/dev/$DEV_ID bs=1024 seek=1024
