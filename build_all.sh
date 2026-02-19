#!/bin/bash

source /tools/xilinx/2025.2/Vitis/settings64.sh

./0.build_platform.sh
./1.prepare_dtb.sh
./2.build_uboot.sh
./3.build_bootbin.sh

#

v4l2-ctl -d /dev/video0 --list-formats
v4l2-ctl -d /dev/video0 --set-fmt-video=width=1280,height=720,pixelformat='RGB3'


media-ctl -d /dev/media0 -V '"43c00000.v_tpg":0 [fmt:RBG888_1X24/1280x720 field:none]'
v4l2-ctl -d /dev/v4l-subdev0 -L 
v4l2-ctl -d /dev/v4l-subdev0 --set-ctrl=test_pattern=9

gst-launch-1.0 v4l2src device=/dev/video0 ! video/x-raw, width=1280, height=720, format=UYVY ! xvimagesink
gst-launch-1.0 v4l2src device=/dev/video0 ! video/x-raw,width=1920,height=1080 ! kmssink


