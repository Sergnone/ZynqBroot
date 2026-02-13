#!/bin/bash

source /tools/xilinx/2025.2/Vitis/settings64.sh

./0.build_platform.sh
./1.prepare_dtb.sh
./2.build_uboot.sh
./3.build_bootbin.sh


sudo make O=$PWD ARCH=arm BR2_JLEVEL="$(($(nproc) - 1))"

file:///home/serg/Documents/Xilinx/ZynqBroot/platform/configs/zynq_mini_defconfig
