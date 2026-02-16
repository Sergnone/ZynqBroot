#!/bin/bash

VITISDIR=/tools/xilinx/2025.2/Vitis/settings64.sh
PLATFDIR=platform/workspace/platform
BIFDIR=platform/bifimage
UBOOTDIR=u-boot-xlnx
DWRAPPERIN=top_design_wrapper.bit
DWRAPPEROUT=top_design_wrapper.bit

source $VITISDIR

sudo rm -r images
mkdir images
sudo rm $BIFDIR/$DWRAPPERIN
sudo rm $BIFDIR/fsbl.elf

cp $PLATFDIR/hw/sdt/$DWRAPPERIN $BIFDIR
cp $PLATFDIR/zynq_fsbl/build/fsbl.elf  $BIFDIR
cp $UBOOTDIR/u-boot.elf $BIFDIR

cd $BIFDIR
mv $DWRAPPEROUT $DWRAPPERIN

cd ..
python3 1.build_bootbin.py
cd ..
cp platform/BOOT.bin images
sudo rm platform/BOOT.bin

