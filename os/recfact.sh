#!/bin/bash
########## recurs factorial #######3
factorial(){
    local num=$1
    if (( $num <= 1 ));then
      echo 1
    else
      echo $((num *  $(factorial $((num -1)) ) ))
 
    fi  
}

read -p"enter a num to find a facto: " number
res=$(factorial $number)
echo "the fact of $number is: $res"