CC = x86_64-linux-musl-gcc
LD = x86_64-linux-musl-gcc

CFLAGS = -Iinclude
LDFLAGS = -static

.PHONY: all

all: build/Shell

build/Shell: obj/shell.o
	$(LD) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean install

clean:
	rm -f obj/*.o
	rm -f build/*

install: all info
	mkdir -p $(DISTDIR)/Applications/penguinburger.shell/Content
	install -Dm755 info $(DISTDIR)/Applications/penguinburger.shell/package
	for file in build/*; do\
		install -Dm755 -t $(DISTDIR)/Applications/penguinburger.shell/Content $$file;\
	done
