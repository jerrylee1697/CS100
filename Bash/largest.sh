#!/bin/sh
var1=$1
var2=$2
var3=$3
var4=$4
varValid=0
largest=0

if [ -z "$var1" ]
then
	echo "Error: No parameter 1"
else 
#	echo "$var1"
	((varValid++))
	if [ "$var1" -gt "$largest" ] 
	then
		largest=$var1
	fi
fi

if [ -z "$var2" ]
then
	echo "Error: No parameter 2"
else
#	echo "$var2"
	((varValid++))
	if [ "$var2" -gt "$largest" ] 
	then
		largest=$var2
	fi
fi

if [ -z "$var3" ]
then
	echo "Error: No parameter 3"
else
#	echo "$var3"
	((varValid++))
	if [ "$var3" -gt "$largest" ] 
	then
		largest=$var3
	fi
fi

if [ -n "$var4" ]
then
	#echo "$var4"
#else
	echo "Error: Extra parameter added"
	((varValid++))
fi

if [ $varValid == 3 ]
then
	echo "$largest"
fi

#echo "$varValid"
