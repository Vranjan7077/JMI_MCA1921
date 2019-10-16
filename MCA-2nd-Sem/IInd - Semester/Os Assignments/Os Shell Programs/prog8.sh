#!/bin/sh
echo "Enter file name"
read file
count=0
awk '$0!~/[aeiou]/{ count++ }
END{printf "The number of lines that does not contain vowels are: %d\n",count}' $file
