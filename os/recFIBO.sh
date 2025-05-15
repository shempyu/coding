#!/bin/bash
########## recurs fibo #######3
fib(){
    n=$1
    a=$2
    b=$3 
    if ((n>0));then
        echo -n "$a "
        fib $((n-1)) $b $((a+b)) 
    fi    
}
read -p "enter a num: " num
fib $num 0 1