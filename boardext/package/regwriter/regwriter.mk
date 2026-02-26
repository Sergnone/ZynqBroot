################################################################################
# Dynclk driver
################################################################################

# Package metadata
REGWRITER_VERSION = 1.0
REGWRITER_SITE = $(TOPDIR)/../boardext/package/regwriter/src
REGWRITER_SITE_METHOD = local
REGWRITER_LICENSE = GPL-2.0

# Call the kernel-module infrastructure first
$(eval $(kernel-module))

# Define installation steps (post-install hook)
define REGWRITER_INSTALL_TARGET_CMDS
	$(INSTALL) -m 0755 $(@D)/regwriter.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/
endef

# Call generic-package infrastructure
$(eval $(generic-package))
