CC = x86_64-linux-musl-gcc

BUILDDIR = $(CURDIR)/build
DISTDIR = $(BUILDDIR)/root

all: $(DISTDIR)

kernel:
	$(MAKE) -C kernel

core: pm
	$(MAKE) -C core

pm:
	$(MAKE) -C pm

shell: pm
	$(MAKE) -C shell

$(DISTDIR): core pm shell kernel
	mkdir -p $(DISTDIR)/Applications
	mkdir -p $(DISTDIR)/Users
	mkdir -p $(DISTDIR)/System/Applications
	mkdir -p $(DISTDIR)/System/Devices
	mkdir -p $(DISTDIR)/System/Processes
	mkdir -p $(DISTDIR)/System/Sys
	mkdir -p $(DISTDIR)/System/Config
	$(MAKE) -C kernel install DISTDIR=$(DISTDIR)
	$(MAKE) -C core install DISTDIR=$(DISTDIR)
	$(MAKE) -C pm install DISTDIR=$(DISTDIR)
	$(MAKE) -C shell install DISTDIR=$(DISTDIR)

$(BUILDDIR)/ramdisk.cpio: $(DISTDIR)
	cd $^;\
	find . | cpio -ov --format=newc > $@

ramdisk: $(BUILDDIR)/ramdisk.cpio

run: $(BUILDDIR)/ramdisk.cpio
	qemu-system-x86_64 -kernel /boot/vmlinuz-linux -initrd $(BUILDDIR)/ramdisk.cpio -append "rdinit=/System/Applications/penguinburger.system.core/Content/Init console=ttyS0" -serial stdio -display none

clean:
	rm -rf $(BUILDDIR)
	$(MAKE) -C kernel clean
	$(MAKE) -C core clean
	$(MAKE) -C pm clean
	$(MAKE) -C shell clean

.PHONY: core pm shell kernel all clean run ramdisk $(DISTDIR) $(BUILDDIR)/ramdisk.cpio
