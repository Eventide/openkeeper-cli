#!/bin/bash

dist=`cat /etc/issue`
dist=`echo $dist | awk '{print $2}'`

if [ "16.04" == "$dist" ]; then
	echo "ubuntu-16-04"
else
	echo "$dist"
fi

exit 0
