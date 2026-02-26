################################################################################
# Dynclk driver
################################################################################

# Package metadata
DGLNT_DYNCLK_VERSION = 1.0
DGLNT_DYNCLK_SITE = $(TOPDIR)/../boardext/package/dglnt_dynclk/src
DGLNT_DYNCLK_SITE_METHOD = local
DGLNT_DYNCLK_LICENSE = GPL-2.0

# Call the kernel-module infrastructure first
$(eval $(kernel-module))

# Define installation steps (post-install hook)
define DDGLNT_DYNCLK_INSTALL_TARGET_CMDS
	$(INSTALL) -m 0755 $(@D)/dglnt_dynclk.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/
endef

# Call generic-package infrastructure
$(eval $(generic-package))
