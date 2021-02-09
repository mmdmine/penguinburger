AR = $(CROSS_COMPILE)ar
RANLIB = $(CROSS_COMPILE)ranlib
ARCH = x86_64
SUBARCH = 
ASMSUBARCH = 
srcdir = .
prefix = /System/Applications/penguinburger.system.musl
exec_prefix = /System/Applications/penguinburger.system.musl/Content
bindir = /System/Applications/penguinburger.system.musl/Content
libdir = /System/Applications/penguinburger.system.musl/Library
includedir = /System/Applications/penguinburger.system.musl/Include
syslibdir = /System/Applications/penguinburger.system.musl/Library
CC = gcc
CFLAGS = 
CFLAGS_AUTO = -Os -pipe -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -Werror=implicit-function-declaration -Werror=implicit-int -Werror=pointer-sign -Werror=pointer-arith
CFLAGS_C99FSE = -std=c99 -nostdinc -ffreestanding -fexcess-precision=standard -frounding-math -Wa,--noexecstack
CFLAGS_MEMOPS = -fno-tree-loop-distribute-patterns
CFLAGS_NOSSP = -fno-stack-protector
CPPFLAGS = 
LDFLAGS = 
LDFLAGS_AUTO = -Wl,--sort-section,alignment -Wl,--sort-common -Wl,--gc-sections -Wl,--hash-style=both -Wl,--no-undefined -Wl,--exclude-libs=ALL -Wl,--dynamic-list=./dynamic.list
CROSS_COMPILE =
LIBCC = -lgcc -lgcc_eh
OPTIMIZE_GLOBS = internal/*.c malloc/*.c string/*.c
ALL_TOOLS =  obj/musl-gcc
TOOL_LIBS =  lib/musl-gcc.specs
ADD_CFI = no
MALLOC_DIR = mallocng
WRAPCC_GCC = $(CC)
AOBJS = $(LOBJS)
