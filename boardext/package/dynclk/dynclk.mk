################################################################################
# Dynclk driver
################################################################################
# Name of your package
#DYNCLK_VERSION = 1.0
# Assuming source is in a 'src' subdirectory of your external tree
#DYNCLK_SITE = /home/serg/Documents/Xilinx/ZynqBroot/boardext/package/dynclk/src
#DYNCLK_SITE_METHOD = local

# Specify that this is a kernel module package
#$(eval $(kernel-module))
#$(eval $(generic-package))


# Package metadata
DYNCLK_VERSION = 1.0
DYNCLK_SITE = /home/serg/Documents/Xilinx/ZynqBroot/boardext/package/dynclk/src
DYNCLK_SITE_METHOD = local
DYNCLK_LICENSE = GPL-2.0

# Call the kernel-module infrastructure first
$(eval $(kernel-module))

# Define installation steps (post-install hook)
define DYNCLK_INSTALL_TARGET_CMDS
	$(INSTALL) -m 0755 $(@D)/dynclk_drv.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/
endef

# Call generic-package infrastructure
$(eval $(generic-package))
