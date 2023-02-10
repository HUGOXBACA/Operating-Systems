#!/bin/bash
#hw1.sh

#prompt user to enter a backup name 

echo "Enter a backup directory name:" 

read budir
 
#if backup dir dne, create such in the current dir 
if [ ! -d "$budir" ]
	then 
		mkdir $budir
fi

for f in ./*.cpp
do
	#if file exists in current dir, create back up in budir 
	if [ -f "$f" ]
       	then
		cp -f $f $budir 
		echo "$f file backedup"
	fi

done	

this should work
