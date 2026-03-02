#!/bin/bash

cd buildroot
sudo rm -r output/build/regwriter-1.0
sudo rm -r output/build/xlnx_video-1.0
sudo rm -r output/build/linux-865e73109750d465f06dee019396406a354eb9d2/arch/arm/boot/uImage
sudo rm -r output/images/rootfs.cpio.uboot
make regwriter-rebuild
make xlnx_video-rebuild
make linux-rebuild
make
cp output/build/linux-865e73109750d465f06dee019396406a354eb9d2/arch/arm/boot/uImage ../images
cp output/images/rootfs.cpio.uboot ../images