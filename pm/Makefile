CC = x86_64-linux-musl-gcc
LD = x86_64-linux-musl-gcc

CFLAGS = -Iinclude
LDFLAGS = -static

.PHONY: all

all: build/PackageManager

build/PackageManager: obj/pm.o
	$(LD) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean install

clean:
	rm -f obj/*.o
	rm -f build/*

install: all info
	mkdir -p $(DISTDIR)/System/Applications/penguinburger.system.pm/Content
	install -Dm755 info $(DISTDIR)/System/Applications/penguinburger.system.pm/package
	for file in build/*; do\
		install -Dm755 -t $(DISTDIR)/System/Applications/penguinburger.system.pm/Content $$file;\
	done
