CC ?= gcc
CFLAGS = -lssl -lcrypto -Wall

dialnetkeeper: dialnetkeeper.o
	$(CC) $< $(CFLAGS) -o $(@F)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

.PHONY: clean install uninstall

clean:
	-rm *.o dialnetkeeper

install:
	@sudo cp dialnetkeeper /usr/bin/

uninstall:
	@sudo rm /usr/bin/dialnetkeeper
