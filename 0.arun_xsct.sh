#!/bin/bash


cd /tools/xilinx/2025.2/Vitis/bin

./xsct

connect
targets
targets 4

fpga /home/serg/Documents/Xilinx/ZynqBroot/platform/bifimage/top_design_wrapper.bit
targets -set -nocase -filter {name =~ "arm*#0"}
dow /home/serg/Documents/Xilinx/ZynqBroot/platform/bifimage/fsbl.elf
con
stop

targets
targets 1

source /home/serg/Documents/Xilinx/ZynqBroot/platform/workspace/platform/hw/sdt/ps7_init.tcl

ps7_init
ps7_post_config

targets -set -nocase -filter {name =~ "arm*#0"}
set device_tree_offset 0x10000


dow -data /home/serg/Documents/Xilinx/ZynqBroot/u-boot-xlnx/u-boot.dtb ${device_tree_offset}
dow /home/serg/Documents/Xilinx/ZynqBroot/u-boot-xlnx/u-boot.elf

con

#LINUX KERNEL
targets -set -nocase -filter {name =~ "arm*#0"}
set device_tree_offset 0x1f00000
set linux_kernel_offset 0x3000000
set rootfs_offset 0x2000000
stop
dow -data /home/serg/Documents/Xilinx/ZynqBroot/u-boot-xlnx/arch/arm/dts/zynq-zc702.dtb ${device_tree_offset}
dow -data /home/serg/Documents/Xilinx/ZynqBroot/buildroot/images/uImage ${linux_kernel_offset}
dow -data /home/serg/Documents/Xilinx/ZynqBroot/buildroot/images/rootfs.cpio.uboot ${rootfs_offset}

dtc -I dtb -O dts -o outppp.dts u-boot-z.dtb
dtc -I dts -O dtb -o u-boot-new.dtb u-boot-new.dts