#!/bin/sh
echo "Enter the pattern to be searched: "
read pattern
echo "Enter the file to be used: "
read filename
echo "Searching for $pattern from file $filename"
echo "The selected records are: "
grep "$pattern" $filename
echo "The no.of lines contains the word( $pattern ) :"
grep -c "$pattern" $filename                   # -c to count number of lines
