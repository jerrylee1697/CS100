#!/bin/sh
ARRAY=(9 5 4 6 3 2 1)
counter1=0
counter2=0
echo "Values in unsorted array: ${ARRAY[*]}"

for element1 in "${ARRAY[@]}";
do
	for element2 in "${ARRAY[@]}";
	do
		if [ "$element1" -lt "$element2" ] 
		then
			temp=${ARRAY[counter1]}
			ARRAY[$counter1]=${ARRAY[counter2]}
			ARRAY[$counter2]=$temp
		fi
		((counter2++))
	done
	counter2=0
	((counter1++))
done

echo "Array sorted: ${ARRAY[@]}"

