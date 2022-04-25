
##############################################################
#
# GPIO
#
##############################################################

GPIO_VERSION = '59b8b083148e2dc679f154b3be77d561e681f8e9'

GPIO_SITE = 'git@github.com:Jahnavi-pinnamaneni/device-driver.git'
GPIO_SITE_METHOD = git
GPIO_GIT_SUBMODULES = YES

GPIO_MODULE_SUBDIRS = GPIO_driver/
# GPIO_MODULE_SUBDIRS += GPIO_driver/

# define LDD_BUILD_CMDS
# 	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)/misc-modules
# 	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)/scull
# endef
#
# # TODO add your writer, finder and finder-test utilities/scripts to the installation steps below

define GPIO_INSTALL_TARGET_CMDS

	#module
	# $(INSTALL) -m 0755 $(@D)/01_simple_LKM/*  $(TARGET_DIR)/usr/bin
	$(INSTALL) -m 0755 $(@D)/GPIO_driver/*  $(TARGET_DIR)/usr/bin

endef

$(eval $(kernel-module))
$(eval $(generic-package))
