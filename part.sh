#!/bin/bash

DRIVE=/dev/sdc

dd if=/dev/zero of=$DRIVE bs=1024 count=1024

SIZE=`fdisk -l $DRIVE | grep Disk | awk '{print $5}'`

echo DISK SIZE - $SIZE bytes

parted -s $DRIVE mklabel msdos
parted -s $DRIVE unit s mkpart primary fat16 -- 1 32768
parted -s $DRIVE set 1 boot on

parted -s $DRIVE unit s mkpart primary ext4 -- 32768 -2

mkfs.vfat -F 16 -n "boot" ${DRIVE}${P}1
mkfs.ext4 -L "rootfs" ${DRIVE}${P}2
