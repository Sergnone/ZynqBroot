#!/bin/bash

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm

export BR2_EXTERNAL="/home/serg/Documents/Xilinx/ZynqBroot/boardext"

cd buildroot
make linux-rebuild

make br_zynq_defconfig BR2_EXTERNAL=../boardext
make linux-menuconfig
make linux-savedefconfig
cp output/build/linux-865e73109750d465f06dee019396406a354eb9d2/arch/arm/boot/uImage ../images
cp output/images/rootfs.cpio.uboot ../images
