CC = gcc
CFLAGS = -lssl -lcrypto -Wall

DIST = $(shell chmod 755 dist.sh && ./dist.sh)

ifeq ($(DIST), ubuntu-16-04)
	CFLAGS += /lib/$(uname -m)-linux-gnu/
endif

dialnetkeeper: dialnetkeeper.o
	$(CC) $(CFLAGS) $< -o $(@F)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean install uninstall

clean:
	-rm *.o dialnetkeeper

install:
	@sudo cp dialnetkeeper /usr/bin/

uninstall:
	@sudo rm /usr/bin/dialnetkeeper
