################################################################################
# Digilent HDMI driver
################################################################################
XLNX_VIDEO_VERSION = 1.0
XLNX_VIDEO_SITE = $(TOPDIR)/../boardext/package/xlnx_video/src
XLNX_VIDEO_SITE_METHOD = local
XLNX_VIDEO_LICENSE = GPL-2.0

$(eval $(generic-package))

define XLNX_VIDEO_BUILD_CMDS
	$(MAKE) -C $(@D) all
endef

# Define installation steps (post-install hook)
define XLNX_VIDEO_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/xlnx_video $(TARGET_DIR)/usr/bin/xlnx_video
endef
