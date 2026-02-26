################################################################################
# Digilent HDMI driver
################################################################################
DGLNT_HDMI_VERSION = 1.0
DGLNT_HDMI_SITE = $(TOPDIR)/../boardext/package/dglnt_hdmi/src
DGLNT_HDMI_SITE_METHOD = local
DGLNT_HDMI_LICENSE = GPL-2.0

# Call the kernel-module infrastructure first
$(eval $(kernel-module))

# Define installation steps (post-install hook)
define DGLNT_HDMI_INSTALL_TARGET_CMDS
	$(INSTALL) -m 0755 $(@D)/dglnt_hdmi.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/
endef

# Call generic-package infrastructure
$(eval $(generic-package))
