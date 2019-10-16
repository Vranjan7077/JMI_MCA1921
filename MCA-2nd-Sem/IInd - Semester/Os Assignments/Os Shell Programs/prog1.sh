#!/bin/sh
echo "enter the filename"
read fname
echo "enter the starting line number"
read s
echo "enter the ending line number"
read n
sed -n -e $s,$n\p $fname | banner bye
 