CC = gcc
CFLAGS = -lcrypto -Wall

dialnetkeeper: dialnetkeeper.c
	$(CC) $(CFLAGS) $< -o $(@F)

.PHONY: clean install uninstall

clean:
	-rm *.o dialnetkeeper

install:
	@sudo cp /usr/bin/dialnetkeeper dialnetkeeper.bak 
	@sudo cp dialnetkeeper /usr/bin/

uninstall:
	@sudo cp dialnetkeeper.bak /usr/bin/dialnetkeeper
