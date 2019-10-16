#!/bin/bash
echo "enter directory name"
read dir
if [ -d $dir ]
then
echo "list of files present  in the directory"
ls -l $dir  && banner BYE           # ls -l  directory-name
else
echo "Enter proper directory name"
fi
