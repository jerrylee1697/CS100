#!/bin/sh
if [ $# -lt "3" ]; then
	echo "Too few parameters. Enter only 3 parameters."
	exit 1
else if [ $# -gt "3" ]; then
	echo "Too many parameters. Enter only 3 parameters."
	exit 1
fi
fi

if [ $1 -ge $2 -a $1 -ge $3 ]; then
	echo "$1 is the largest number."
else if [ $2 -ge $1 -a $2 -ge $3 ]; then
	echo "$2 is the largest number."
else
        echo "$3 is the largest number."
fi
fi
