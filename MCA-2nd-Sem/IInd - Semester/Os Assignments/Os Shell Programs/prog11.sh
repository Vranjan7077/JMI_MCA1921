#!/bin/sh
echo "ENTER FILE NAME"
read file
if [ -f $file ]
then
echo "FILE NAME = " $file
sed -e " s/\([^ ]*\)  *\([^ ]*\)/\2  \1 /g " $file

echo "SWAP FIRST 2 WORDS IN EACH LINE IN A FILE"
echo "**********************"
else
echo "THIS NOT A FILE NAME "
fi

 