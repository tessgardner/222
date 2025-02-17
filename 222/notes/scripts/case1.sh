#!/bin/bash

read -p "What day is it? " day

case $day in
	"Monday" | "Tuesday" | "Wednesday" | "Thursday")
		echo "It's a weekday." ;;
	"Friday" | "Saturday" | "Sunday")
		echo "It's the weekend!" ;;
	*)
		echo "Invalid day." ;;
esac
