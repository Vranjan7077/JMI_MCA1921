#!/bin/sh
echo "ENTER FILE NAME"
read file
if [ -f $file ]
then
echo "FILE NAME IS =  " $file
else
echo "THIS IS NOT A FILE"
fi
echo "NUMBER OF LINES = "       
wc -l $file
echo "NUMBER OF CHARCTERS = " 
wc -c $file 

echo "NUMBER OF WORDS = " 
wc -w $file 
