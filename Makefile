gcc:
	$(MAKE) -C gcc

kernel: gcc
	$(MAKE) -C kernel

libc: gcc
	$(MAKE) -C libc

init: libc
	$(MAKE) -C init

pm: libc
	$(CMAKE) -C pm

shell: libc
	$(CMAKE) -C shell

root: gcc kernel libc init pm shell
	mkdir -p build/root/Applications
	mkdir -p build/root/Users
	mkdir -p build/root/System/Applications
	mkdir -p build/root/System/Devices
	mkdir -p build/root/System/Processes
	mkdir -p build/root/System/Sys
	mkdir -p build/root/System/Config
	# TODO: install pm in build/root
	# TODO: use pm and chroot to install system packages

all: root

.PHONY: gcc kernel libc init pm shell root all
