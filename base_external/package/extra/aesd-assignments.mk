
##############################################################
#
# EXTRA
#
##############################################################

EXTRA_VERSION = '19364daea90aee861a818731e705ec6034b4586e'

EXTRA_SITE = 'git@github.com:Jahnavi-pinnamaneni/AESD-Device_Driver.git'
EXTRA_SITE_METHOD = git
EXTRA_GIT_SUBMODULES = YES

EXTRA_MODULE_SUBDIRS = custom/
EXTRA_MODULE_SUBDIRS += gpio_interrupt/
EXTRA_MODULE_SUBDIRS += ioctl/
EXTRA_MODULE_SUBDIRS += sysfs/
EXTRA_MODULE_SUBDIRS += timer/

# define LDD_BUILD_CMDS
# 	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)/misc-modules
# 	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)/scull
# endef
#
# # TODO add your writer, finder and finder-test utilities/scripts to the installation steps below

define EXTRA_INSTALL_TARGET_CMDS

	#module
	$(INSTALL) -m 0755 $(@D)/custom/*  $(TARGET_DIR)/usr/bin
	$(INSTALL) -m 0755 $(@D)/gpio_interrupt/*  $(TARGET_DIR)/usr/bin
	$(INSTALL) -m 0755 $(@D)/ioctl/*  $(TARGET_DIR)/usr/bin
	$(INSTALL) -m 0755 $(@D)/sysfs/*  $(TARGET_DIR)/usr/bin
	$(INSTALL) -m 0755 $(@D)/timer/*  $(TARGET_DIR)/usr/bin

endef

$(eval $(kernel-module))
$(eval $(generic-package))
