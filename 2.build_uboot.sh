#!/bin/bash

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm
SCRDIR=platform/scripts
UBOOTDIRCFG=u-boot-xlnx/configs
DEFCONF=uboot_zynq_mini_defconfig
cp $PWD/boardext/uboot/$DEFCONF $UBOOTDIRCFG/
cd u-boot-xlnx
make clean
make distclean
make $DEFCONF
make
cd ..
#sudo rm $UBOOTDIRCFG/$DEFCONF

