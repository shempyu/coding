#!/bin/bash

# Read the binary number from the user
echo "Enter a binary number:"
read binary
decimal=0
length=${#binary}
for ((i=0; i<length; i++))
do
    digit=${binary:i:1}
    # Multiply the digit by 2 raised to the power of its position (counting from right)
    power=$((length - i - 1))  # Calculate power of 2 for current position
    decimal=$((decimal + digit * (2 ** power)))  # Add to the decimal value
done
echo "The decimal equivalent of binary $binary is: $decimal"
