#!/bin/bash
echo "Enter a decimal number:"
read decimal
binary=""
if ((decimal == 0)); then
  binary="0"
fi
while ((decimal > 0)); do
  # Get the remainder (either 0 or 1)
  remainder=$((decimal % 2))
  # Prepend the remainder to the binary string
  binary="$remainder$binary"
  decimal=$((decimal / 2))
done

echo "The binary equivalent is: $binary"
