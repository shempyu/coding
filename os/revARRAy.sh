#!/bin/bash
read -p "enter size of arr: " n
declare -a arr
for ((i = 0;i<n;i++));do 
  read -p "enter data: " data
  arr+=($data)
done
echo "orgonal arr: ${arr[@]}"
for ((i = 0;i<n/2;i++));do
  temp=${arr[i]};
  arr[i]=${arr[n-i-1]}
  arr[n-i-1]=$temp
done
echo "reverse array : ${arr[@]}"