#!/bin/sh

# bkup - bla bla

filename=$1
numOfcopies=$2
i="$(( $numOfcopies - 1 ))" 


if [ ! -r $filename ] ; then
  echo "$0: Missing file library $filename" 
  exit 1
fi 

while [ $numOfcopies -ge 1 ] ; do
   if [ $numOfcopies -eq 1 ] ; then
      cp $filename $filename.$numOfcopies
   else
      cp $filename.$i $filename.$numOfcopies
   fi
   numOfcopies="$(( $numOfcopies - 1 ))"
   i="$(( $i - 1 ))"
done

exit 0






