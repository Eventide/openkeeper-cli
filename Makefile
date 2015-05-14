INSTALL_PATH=/usr/share/openkeeper
SUBDIR=diallinux_v1.0_src_a

all:
	@(cd $(SUBDIR) && $(MAKE) dialnetkeeper)
install: all
	cp diallinux_v1.0_src_a/dialnetkeeper /usr/bin/
	cp ok /usr/sbin/
	cp ok-config /usr/sbin
	cp ok-refresh /usr/sbin
	cp ok-stop /usr/sbin
	mkdir -p $(INSTALL_PATH)
	cp pppoe.conf $(INSTALL_PATH)
	cp pap-secrets $(INSTALL_PATH)
	mv /usr/sbin/pppoe-connect /usr/sbin/pppoe-connect.old
	cp pppoe-connect /usr/sbin/pppoe-connect
uninstall:
	rm /usr/bin/dialnetkeeper -f
	rm /usr/sbin/ok -f
	rm /usr/sbin/ok-refresh -f
	rm /usr/sbin/ok-config -f
	rm /usr/sbin/ok-stop -f
	rm $(INSTALL_PATH) -rf
	rm /usr/sbin/pppoe-connect -f
	mv /usr/sbin/pppoe-connect.old /usr/sbin/pppoe-connect
clean:
	@(cd $(SUBDIR) && $(MAKE) clean)