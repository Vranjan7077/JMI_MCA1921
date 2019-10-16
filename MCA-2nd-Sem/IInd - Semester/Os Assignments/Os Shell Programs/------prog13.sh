#!/bin/sh
echo "enter a user name"
read name
uinfo=`who |grep -w $name | grep 'pts'`

if [ $? -ne 0 ]
then
    echo "user is not loged in yet"
else
    echo "user is there"
min=`who | grep -w $name |tr -s " " " " | cut -c 27-28`
hrs=`who | grep -w $name |tr -s " " " " | cut -c 24-25`
    echo "$uinfo"
    
    mnow=`date +%M`
    if [ $min -le $mnow ]
    then
    echo "some thing"
    min=((($min+60)-$mnow))
    hrs=(($hrs -1))
    echo " $min : $hrs "

fi

