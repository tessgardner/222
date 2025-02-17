#!/bin/bash

testfile(){
	if [ $# -gt 0 ]; then
	if [[ -f $1 ]]; then
		echo $1 is a file
	else
		if test -d $1; then
			echo $1 is a directory
		fi
	fi
	fi
}

testfile .
testfile fake
testfile first.sh
