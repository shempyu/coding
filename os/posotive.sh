#!/bin/bash
echo "Enter a  str:"
read n
if [ $n -gt 0 ];then
echo "positive"
elif [ $n -lt 0 ];then
echo "negative"
else
 echo "zero"
 fi