#!/bin/bash
s=0
read -p "Enter the number of elements: " n

for ((i = 1; i <= n; i++))
do
  read -p "Enter a number: " num
  s=$((s + num))
done

# Calculate the average using awk

avg=$(awk "BEGIN {print $s / $n}")

echo "Average is $avg"
