LINUX_TOOLCHAIN_PATH = /home/autobuild/tools/win32

PathToNewlib = contrib/sdk/sources/newlib
PathToLibc = $(PathToNewlib)/libc

PackageName = newlib

install shared static:
	$(MAKE) -C $(PathToLibc) $@


package: static
	mkdir -p $(PackageName)$(LINUX_TOOLCHAIN_PATH)/include
	mkdir -p $(PackageName)$(LINUX_TOOLCHAIN_PATH)/mingw32/lib

	cp -rf $(PathToLibc)/include/* $(PackageName)$(LINUX_TOOLCHAIN_PATH)/include
	cp -f $(PathToLibc)/*.a $(PackageName)$(LINUX_TOOLCHAIN_PATH)/mingw32/lib

	chmod 775 -R newlib

	dpkg-deb --build $(PackageName) $(PackageName).deb


clean:
	$(MAKE) -C $(PathToLibc) $@

	rm -f $(ALL_PACKAGES)
	rm -rf newlib/home
