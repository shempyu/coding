#!/bin/bash
echo "enter num1"
read n
s=0
len=${#n}
for ((i = 0;i<len;i++));do
  dig=${n:i:1}
  s=$((s + (dig ** len)))
done
echo "the $s"


