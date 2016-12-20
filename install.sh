#!/bin/bash

INSTALL_PATH="/usr/share/openkeeper"
SRC_PATH="src"

mkdir -p "$INSTALL_PATH"
install -m 755 "$SRC_PATH"/dialnetkeeper /usr/bin/
install -m 755 ok /usr/sbin/
install -m 755 ok-config /usr/sbin
install -m 755 ok-stop /usr/sbin
install -m 755 ok-start /usr/sbin
install -m 755 ok-connect /usr/sbin
install -m 644 pppoe.conf "$INSTALL_PATH"
install -m 644 pap-secrets "$INSTALL_PATH"

exit 0
