#!/bin/bash
########## array #######3
echo "enter the size: "
read n
declare -a arr
for ((i=0;i<n;i++));do
read -p"enter the data:" data
arr+=($data)
done
for ((i=0;i<n;i++));do
echo -n "${arr[i]} "
done
echo "arr ${arr[@]}" # whole array printing