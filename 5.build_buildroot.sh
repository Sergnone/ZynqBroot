#!/bin/bash

LINDIR=build/linux-865e73109750d465f06dee019396406a354eb9d2
BIFDIR=platform/bifimage
SCRDIR=platform/scripts
UBOOTDIR=u-boot-xlnx

cd buildroot
make clean
make distclean
make br_zynq_defconfig BR2_EXTERNAL=$(pwd)/../board
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

