#!/bin/bash

for i in {1..10}; do
	if [ $i -le 3 ]; then
		echo "continue"
		continue
	fi
	echo $i
	if [ $i -ge 8 ]; then
		echo "break"
		break
	fi
done
