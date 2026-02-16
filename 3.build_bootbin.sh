#!/bin/bash

PLATFDIR=platform/workspace/platform
BIFDIR=platform/bifimage
UBOOTDIR=u-boot-xlnx

sudo rm -r images
mkdir images
sudo rm $BIFDIR/top_design_wrapper.bit
#sudo rm $BIFDIR/system-top.dts
sudo rm $BIFDIR/fsbl.elf

cp $PLATFDIR/hw/sdt/top_design_wrapper_02.bit $BIFDIR
cp $PLATFDIR/zynq_fsbl/build/fsbl.elf  $BIFDIR
#sudo cp $PLATFDIR/zynq_fsbl/zynq_fsbl_bsp/hw_artifacts/ps7_cortexa9_0_baremetal.dts $BIFDIR
cp $UBOOTDIR/u-boot.elf $BIFDIR

cd $BIFDIR
mv top_design_wrapper_02.bit top_design_wrapper.bit
#mv ps7_cortexa9_0_baremetal.dts system-top.dts
#dtc -I dts -O dtb -o system-top.dtb system-top.dts

cd ..
python3 1.build_bootbin.py
cd ..
cp platform/BOOT.bin images
sudo rm platform/BOOT.bin

