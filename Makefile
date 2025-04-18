CC = gcc
CFLAGS = -O3 -g
ROOT = $(shell pwd)
TESTS = $(wildcard test/*.c)
SRCS = $(wildcard src/*.c)
DEPS = $(wildcard src/*.h)
OBJS = $(patsubst src/%.c, %.o, $(SRCS))

PREFIX=$(shell sed -n '1p' $(ROOT)/build_cache)

%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

libsieves.a: $(OBJS)
	mkdir $(PREFIX)/lib
	mkdir $(PREFIX)/include
	ar rcs libsieves.a $(OBJS)
	mv libsieves.a $(PREFIX)/lib
	cp $(ROOT)/src/*.h $(PREFIX)/include
	rm $(OBJS)

.PHONY: test
test:
	mkdir -p $(PREFIX)/test
	$(CC) $(CFLAGS) $(TESTS) -o $(PREFIX)/test/tests -I$(PREFIX)/include -L$(PREFIX)/lib -lsieves
	$(PREFIX)/test/tests

clean:
	rm -f *.o
	rm -r $(PREFIX)/include
	rm -r $(PREFIX)/lib
	rm -r $(PREFIX)/test
