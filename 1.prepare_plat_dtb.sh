#!/bin/bash

PLATFDIR=platform/workspace/platform
BIFDIR=platform/bifimage
UBOOTDIR=u-boot-xlnx
DTSNAME=ps7_cortexa9_0_baremetal.dts

sudo rm $BIFDIR/zynq-boot.dts
sudo rm $BIFDIR/zynq-boot.dtb
sudo cp $PLATFDIR/zynq_fsbl/zynq_fsbl_bsp/hw_artifacts/$DTSNAME $BIFDIR
cd $BIFDIR
mv ps7_cortexa9_0_baremetal.dts zynq-boot.dts
dtc -I dts -O dtb -o zynq-boot.dtb zynq-boot.dts
cd ../..
