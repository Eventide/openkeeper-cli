INSTALL_PATH=/usr/share/openkeeper
SUBDIR=dialnetkeeper

all:
	@(cd $(SUBDIR) && $(MAKE) )
install: all
	cp dialnetkeeper/dialnetkeeper /usr/bin/
	cp ok /usr/sbin/
	cp ok-config /usr/sbin
	cp ok-stop /usr/sbin
	mkdir -p $(INSTALL_PATH)
	cp pppoe.conf $(INSTALL_PATH)
	cp pap-secrets $(INSTALL_PATH)
	cp ok-start	/usr/sbin/ok-start
	cp ok-connect /usr/sbin/ok-connect
	chmod a+x /usr/bin/dialnetkeeper
	chmod a+x /usr/sbin/ok
	chmod a+x /usr/sbin/ok-*
uninstall:
	rm /usr/bin/dialnetkeeper -f
	rm /usr/sbin/ok -f
	rm /usr/sbin/ok-config -f
	rm /usr/sbin/ok-stop -f
	rm $(INSTALL_PATH) -rf
	rm /usr/sbin/ok-connect -f
	rm /usr/sbin/ok-start -f
clean:
	@(cd $(SUBDIR) && $(MAKE) clean)
