#!/bin/bash
echo "Enter a string:"
read str
len=${#str}
rev=""
for (( i = len-1; i>=0; i-- ))
do
  rev=$rev${str:i:1}
done
if [  $rev == $str ] ;then
echo "it is palindromestring"
else 
  echo "not pali string"
fi  
