CC=x86_64-linux-musl-gcc

libc:
	$(MAKE) -C libc

kernel: gcc
	$(MAKE) -C kernel

gcc: libc
	$(MAKE) -C gcc

init: libc gcc
	$(MAKE) -C init

pm: libc gcc
	$(CMAKE) -C pm

shell: libc gcc
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
