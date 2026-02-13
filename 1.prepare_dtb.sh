#!/bin/bash

PLATFDIR=platform/workspace/platform
BIFDIR=platform/bifimage
UBOOTDIR=u-boot-xlnx

sudo rm $BIFDIR/zynq-mini-port.dts
sudo rm $BIFDIR/zynq-mini-port.dtb
cp $PLATFDIR/zynq_fsbl/zynq_fsbl_bsp/hw_artifacts/ps7_cortexa9_0_baremetal.dts $BIFDIR
cd $BIFDIR
mv ps7_cortexa9_0_baremetal.dts zynq-mini-port.dts
dtc -I dts -O dtb -o zynq-mini-port.dtb zynq-mini-port.dts
cd ../..
#sudo cp $BIFDIR/zynq-mini-port.dts $UBOOTDIR/arch/arm/dts

