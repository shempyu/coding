#!/bin/bash

echo "enter string :"
read str

len=${#str}
reverse=" "

for ((i=len-1; i>=0; i--))
do  
   reverse=$reverse${str:i:1}
done

echo "after reverse : $reverse"