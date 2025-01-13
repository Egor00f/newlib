LINUX_TOOLCHAIN_PATH = /home/autobuild/tools/win32

PathToNewlib = contrib/sdk/sources/newlib
PathToLibc = $(PathToNewlib)/libc

ALL_PACKAGES = newlib.deb

install shared static:
	$(MAKE) -C $(PathToLibc) $@


package: static
	mkdir -p newlib$(LINUX_TOOLCHAIN_PATH)/include
	mkdir -p newlib$(LINUX_TOOLCHAIN_PATH)/mingw32/lib

	cp -rf $(PathToLibc)/include/* newlib$(LINUX_TOOLCHAIN_PATH)/include
	cp -f $(PathToLibc)/*.a newlib$(LINUX_TOOLCHAIN_PATH)/mingw32/lib

	chmod 775 -R newlib

	dpkg-deb --build newlib $@


clean:
	$(MAKE) -C $(PathToLibc) $@

	rm -f $(ALL_PACKAGES)
	rm -rf newlib/home
