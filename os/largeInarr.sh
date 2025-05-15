#!/bin/bash
##########larg in arr #######3
echo "enter the size: "
read n
declare -a arr
for ((i=0;i<n;i++));do
read -p"enter the data:" data
arr+=($data)
done
larg=${arr[0]}
for ((i = 0;i<n;i++));do
if ((larg < ${arr[i]})) ;then
larg=${arr[i]}
fi
done
echo "larg: $larg"