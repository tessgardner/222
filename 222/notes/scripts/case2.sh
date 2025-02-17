#!/bin/bash

case $1 in
	*.txt)
		echo "It's a text file." ;;
	*.jpg | *.png | *.gif)
		echo "It's an image file." ;;
	*.sh)
		echo "It's a shell script." ;;
	*)
		echo "It's a unknown file type." ;;
esac
