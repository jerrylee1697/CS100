#!/bin/sh
ARRAY=(5 1 4 2 3 8 5 17)
echo ${ARRAY[*]}
done=0
while [ ${done} -ne 1 ]
do
	swap=0
	for i in ${ARRAY[@]}
	do
		if [ $((${#ARRAY[@]}-1)) -gt $i ]; then   #Check bounds
			if [ ${ARRAY[i+1]} -lt $i ]; then
				unset i	
				swap=1
				temp=$i
				${ARRAY[i]}=${ARRAY[i+1]}
				${ARRAY[i+1]}=$temp
			fi
		fi
	done

	if [ $swap -eq 0 ]; then
		done=1
	fi
done
echo ${ARRAY[*]}
