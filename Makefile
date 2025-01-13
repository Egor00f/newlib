LINUX_TOOLCHAIN_PATH = /home/autobuild/tools/win32

PathToNewlib = contrib/sdk/sources/newlib/libc

install shared static clean:
	$(MAKE) -C $(PathToNewlib) $@


newlib.deb: static
	mkdir -p newlib$(LINUX_TOOLCHAIN_PATH)/include

	cp -rf $(PathToNewlib)/include/* newlib$(LINUX_TOOLCHAIN_PATH)/include
	cp -f $(PathToNewlib)/*.a newlib$(LINUX_TOOLCHAIN_PATH)/mingw32/lib

	dpkg-deb newlib $@

newlib-dev.deb:

	mkdir -p newlib-dev$(LINUX_TOOLCHAIN_PATH)/include

	cp -rf $(PathToNewlib) newlib-dev$(LINUX_TOOLCHAIN_PATH)


	dpkg-deb newlib-dev $@
