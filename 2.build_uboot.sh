#!/bin/bash

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm
#export DEVICE_TREE=zynq-mini-port

cd u-boot-xlnx
#make clean
#make distclean
make zynq_mini_02_defconfig
make
cd ..
