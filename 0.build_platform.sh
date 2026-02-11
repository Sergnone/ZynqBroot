#!/bin/bash

source /tools/xilinx/2025.2/Vitis/settings64.sh

cd platform
sudo rm -r workspace
vitis -s 0.build_platform.py
