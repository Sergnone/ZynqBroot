################################################################################
# Digilent HDMI driver
################################################################################
AONCV_VERSION = 1.0
AONCV_SITE = $(TOPDIR)/../boardext/package/aoncv/src
AONCV_SITE_METHOD = local
AONCV_LICENSE = GPL-2.0

#AONCV_LIBS = $(shell $(PKG_CONFIG) --libs opencv4)
#AONCV_CFLAGS = $(shell $(PKG_CONFIG) --cflags opencv4)
#$(TARGET_CC) $(TARGET_CFLAGS) $(TARGET_LDFLAGS) aoncv.cpp -o $@ $(AONCV_LIBS)

$(eval $(generic-package))

define AONCV_BUILD_CMDS
	$(MAKE) -C $(@D) all
endef

# Define installation steps (post-install hook)
define AONCV_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/aoncv $(TARGET_DIR)/usr/bin/aoncv
endef


