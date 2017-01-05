INSTALL_PATH=/usr/share/openkeeper
SUBDIR=dialnetkeeper

all:
	@(cd $(SUBDIR) && $(MAKE) )
install: all
	mkdir -p $(INSTALL_PATH)
	install -m 755 dialnetkeeper/dialnetkeeper /usr/bin/
	install -m 755 ok /usr/sbin/
	install -m 755 ok-config /usr/sbin
	install -m 755 ok-stop /usr/sbin
	install -m 755 ok-start /usr/sbin
	install -m 755 ok-connect /usr/sbin
	install -m 644 pppoe.conf $(INSTALL_PATH)
	install -m 644 pap-secrets $(INSTALL_PATH)
uninstall:
	rm /usr/bin/dialnetkeeper -f
	rm /usr/local/sbin/ok -f
	rm /usr/local/sbin/ok-config -f
	rm /usr/local/sbin/ok-stop -f
	rm $(INSTALL_PATH) -rf
	rm /usr/local/sbin/ok-connect -f
	rm /usr/local/sbin/ok-start -f
clean:
	@(cd $(SUBDIR) && $(MAKE) clean)
