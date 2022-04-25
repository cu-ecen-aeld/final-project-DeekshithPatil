
##############################################################
#
# SOCKET
#
##############################################################


SOCKET_VERSION = '0677f33ec45e43c1906335eeac7f51e664e47456'
SOCKET_SITE = 'git@github.com:cu-ecen-aeld/final-project-Jahnavi-pinnamaneni.git'
SOCKET_SITE_METHOD = git
SOCKET_GIT_SUBMODULES = YES

define SOCKET_BUILD_CMDS
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)/socket all
endef


define SOCKET_INSTALL_TARGET_CMDS

	#socket
	$(INSTALL) -m 0755 $(@D)/socket/*  $(TARGET_DIR)/usr/bin/

endef

$(eval $(generic-package))
