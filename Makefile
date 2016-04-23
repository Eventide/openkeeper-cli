INSTALL_PATH=/usr/share/openkeeper
SUBDIR=dialnetkeeper

all:
	@(cd $(SUBDIR) && $(MAKE) )
install: all
	cp dialnetkeeper/dialnetkeeper /usr/local/bin/
	cp ok /usr/local/sbin/
	cp ok-config /usr/local/sbin
	cp ok-stop /usr/local/sbin
	mkdir -p $(INSTALL_PATH)
	cp pppoe.conf $(INSTALL_PATH)
	cp pap-secrets $(INSTALL_PATH)
	cp ok-start	/usr/local/sbin/ok-start
	cp ok-connect /usr/local/sbin/ok-connect
	chmod a+x /usr/local/bin/dialnetkeeper
	chmod a+x /usr/local/sbin/ok
	chmod a+x /usr/local/sbin/ok-*
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
