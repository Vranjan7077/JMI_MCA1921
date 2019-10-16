#!/bin/sh
echo "Total no of factorial wants"
read fact

ans=1
counter=0
while [ $fact -ne $counter ]
do
        let counter=counter+1                 
        ans=$((counter*ans))

done

echo "Total of factorial is $ans"
