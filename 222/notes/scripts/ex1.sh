#!/bin/bash

read -p "Enter your grade: " grade

if [ ! "$grade" -lt 70 ]; then
	echo "You will pass the class."
else
	echo "You needed to do more to pass the class"
fi
