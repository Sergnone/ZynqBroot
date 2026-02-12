#!/bin/bash

source /tools/xilinx/2025.2/Vitis/settings64.sh

./0.build_platform.sh
./1.build_uboot.sh
./2.build_bootbin.sh

