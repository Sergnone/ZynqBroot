#!/bin/bash

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm

cd u-boot-xlnx
make zynq_mini_defconfig
make
cd ..
