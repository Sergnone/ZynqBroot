#!/bin/bash

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm

LINDIR=build/linux-865e73109750d465f06dee019396406a354eb9d2
BIFDIR=platform/bifimage
SCRDIR=platform/scripts
UBOOTDIR=u-boot-xlnx
DEFCONFNAME=br_zynq_smp_defconfig

export BR2_EXTERNAL="board/configs"
export BR2_EXTERNAL="/home/serg/Documents/Xilinx/ZynqBroot/boardext"

make br_zynq_defconfig BR2_EXTERNAL=../boardext

make BR2_EXTERNAL=../boardext menuconfig

make linux-menuconfig

make linux-savedefconfig BR2_LINUX_KERNEL_CUSTOM_CONFIG_FILE=$(BR2_EXTERNAL)/kernel/linux.config

#make linux-dirclean

cd buildroot
make clean
make distclean
make br_zynq_defconfig BR2_EXTERNAL=$(pwd)/../boardext
make O=$PWD ARCH=arm BR2_JLEVEL="6"

#cp images/uImage ../images/
#cp images/rootfs.tar ../images/
#cp images/rootfs.cpio.uboot ../images/
#cd ..
#cp $UBOOTDIR/arch/arm/dts/zynq-zc702.dtb images/
#cp $UBOOTDIR/arch/arm/dts/zynq-dt.dtb images/
#sudo mv images/zynq-zc702.dtb images/devicetree.dtb
#cp $BIFDIR/zynq-mini-port.dtb images/
#sudo mv images/zynq-mini-port.dtb images/devicetree.dtb

#cd $SCRDIR
#mkimage -A arm -O linux -T script -C none -d boot.txt boot.scr
#cd ../..
#cp $SCRDIR/boot.scr images/



export BR2_EXTERNAL="/home/serg/Documents/Xilinx/ZynqBroot/boardext"
make br_zynq_defconfig BR2_EXTERNAL=../boardext
make linux-menuconfig
make linux-savedefconfig
cp output/build/linux-*/defconfig $BR2_EXTERNAL/kernel/kernel.config