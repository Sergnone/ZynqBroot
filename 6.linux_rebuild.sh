#!/bin/bash

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm

export BR2_EXTERNAL="/home/serg/Documents/Xilinx/ZynqBroot/boardext"

cd buildroot
sudo rm -r output/build/dynclk-1.0
make dynclk-rebuild
make linux-rebuild

make br_zynq_defconfig BR2_EXTERNAL=../boardext
make linux-menuconfig
make linux-savedefconfig
cp output/build/linux-865e73109750d465f06dee019396406a354eb9d2/arch/arm/boot/uImage ../images
cp output/images/rootfs.cpio.uboot ../images


export CROSS_COMPILE=/tools/xilinx/2025.2/Vitis/gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-
/tools/xilinx/2025.2/Vitis/gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-gcc

export PATH=$PATH:/path/to/your/cross-compiler/bin

export CC=tools/xilinx/2025.2/Vitis/gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-


cmake -D CMAKE_C_COMPILER=tools/xilinx/2025.2/Vitis/gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-gcc \
      -D CMAKE_CXX_COMPILER=/path/to/your/g++ \
      /path/to/your/source/directory

LD_LIBRARY_PATH=/tools/xilinx/2025.2/tps/lnx64/cmake-3.24.2/libs/Ubuntu:$LD_LIBRARY_PATH