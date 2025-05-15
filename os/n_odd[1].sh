#!/bin/bash

echo "Enter number:"
read n

# Initialize the count of odd numbers printed
count=0
i=1

# Loop to print the first n odd numbers
while (( count < n ))
do
    echo -n " $i"
    i=$((i + 2))   # Increment to the next odd number
    count=$((count + 1))
done
