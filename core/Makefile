CC = x86_64-linux-musl-gcc
LD = x86_64-linux-musl-gcc

CFLAGS = -Iinclude
LDFLAGS = -static

.PHONY: all

all: build/Init build/Shutdown build/Reboot

build/Init: obj/log.o obj/pm.o obj/power.o obj/signal_handlers.o obj/init_filesystem.o obj/init.o
	$(LD) $(LDFLAGS) -o $@ $^

build/Shutdown: obj/shutdown.o
	$(LD) $(LDFLAGS) -o $@ $^

build/Reboot: obj/reboot.o obj/power.o
	$(LD) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean install

clean:
	rm -f obj/*.o
	rm -f build/*

install: all info
	mkdir -p $(DISTDIR)/System/Applications/penguinburger.system.core/Content
	install -Dm755 info $(DISTDIR)/System/Applications/penguinburger.system.core/package
	for file in build/*; do\
		install -Dm755 -t $(DISTDIR)/System/Applications/penguinburger.system.core/Content $$file;\
	done
