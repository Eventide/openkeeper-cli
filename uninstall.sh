#!/bin/bash

INSTALL_PATH="/usr/share/openkeeper"

rm /usr/bin/dialnetkeeper -f
rm /usr/sbin/ok -f
rm /usr/sbin/ok-config -f
rm /usr/sbin/ok-stop -f
rm /usr/sbin/ok-connect -f
rm /usr/sbin/ok-start -f
rm "$INSTALL_PATH" -rf
exit 0
