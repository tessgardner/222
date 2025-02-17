#!/bin/bash

if [ -f "$1" ]; then #spaces are important
	echo "parameter $1 is a file"
else
	echo "parameter $1 is not a file"
fi
