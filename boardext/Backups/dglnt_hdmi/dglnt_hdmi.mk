################################################################################
# Digilent HDMI driver
################################################################################
DYNCLK_VERSION = 1.0
DYNCLK_SITE = /home/serg/Documents/Xilinx/ZynqBroot/boardext/package/dgln_hdmi/src
DYNCLK_SITE_METHOD = local
DYNCLK_LICENSE = GPL-2.0

# Call the kernel-module infrastructure first
$(eval $(kernel-module))

# Define installation steps (post-install hook)
define DYNCLK_INSTALL_TARGET_CMDS
	$(INSTALL) -m 0755 $(@D)/dglnt_hdmi.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/
endef

# Call generic-package infrastructure
$(eval $(generic-package))
