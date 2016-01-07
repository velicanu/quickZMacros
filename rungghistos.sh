#!/bin/bash
if [ $# -lt 2 ]
then
  echo "Usage: ./rungghistos.sh <inputlist> <outfile>"
  exit 1
fi

uid=`date +%s%N`
count=0
for i in `cat $1`
do
  ./ggTrack.exe $i tmp${uid}_$count.root &
  count=$(($count+1))
done
wait
hadd -f $2 tmp${uid}_*.root
rm tmp${uid}_*.root
