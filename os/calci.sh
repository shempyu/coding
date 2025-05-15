#!/bin/bash

echo "Enter num1:"
read n1

echo "Enter num2:"
read n2

echo "Enter operation (+, -, *, /):"
read op

case $op in
 +) echo "Sum is: $(( n1 + n2 ))" ;;
 -) echo "Subtraction is: $((n1 - n2))" ;;
 \*) echo "Multiplication is: $((n1 * n2))";;
 /) if [[ $n2 -eq 0 ]]; then
        echo "Error: Division by zero"
    else
        # Ensure the result is printed correctly with awk
       
        echo "Division is: $(awk "BEGIN {print $n1/$n2}")"
    fi
    ;;
esac
: '
if [[ "$op" == "+" ]]; then
    echo "Sum is: $(($n1 + $n2))"
elif [[ "$op" == "-" ]]; then
    echo "Subtraction is: $(($n1 - $n2))"
elif [[ "$op" == "*" ]]; then
    echo "Multiplication is: $(($n1 * $n2))"
elif [[ "$op" == "/" ]]; then
    # Check for division by zero
    if [[ $n2 == 0 ]]; then
        echo "Error: Division by zero"
    else
        echo "Division is: $(($n1 / $n2))"
    fi
else
    echo "Invalid operation"
fi
'
