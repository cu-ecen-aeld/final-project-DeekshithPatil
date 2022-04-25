
##############################################################
#
# TEST
#
##############################################################


TEST_VERSION = '6f10aa22d9f62679efd23a3d1e768d30f754c495'
TEST_SITE = 'git@github.com:Jahnavi-pinnamaneni/AESD-Device_Driver.git'
TEST_SITE_METHOD = git
TEST_GIT_SUBMODULES = YES

define TEST_BUILD_CMDS
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)/test all
endef


define TEST_INSTALL_TARGET_CMDS

	#socket
	$(INSTALL) -m 0755 $(@D)/test/*  $(TARGET_DIR)/usr/bin/

endef

$(eval $(generic-package))
