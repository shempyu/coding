#!/bin/bash
echo "array operation"
echo "enter the size of an array "
read n
declare -a arr
for ((i=0; i<n; i++))
do 
 read -p "enter the element: " data
 arr+=($data)
 done
  for ((i=0; i<n; i++))
     do
      for ((j=i+1; j<n; j++))
      do
        if [ "${arr[i]}" -gt "${arr[j]}" ]
        then
           temp=${arr[i]}
           arr[i]=${arr[j]}
           arr[j]=$temp
           fi
           done
           done
         echo "sorted array: ${arr[@]} "
         echo "the largest element is: ${arr[n-1]} "