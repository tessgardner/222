#!/bin/bash

Bonus=2
read -p "Enter grade for quiz 1: " q1
read -p "Enter grade for quiz 2: " q2

if [[ "$q1" -eq 10 && "$q2" -eq 10 ]]
then
	echo "You don't need any bonus points"
else
	echo "you get a bonus of $Bonus"
fi
