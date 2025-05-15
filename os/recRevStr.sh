#!/bin/bash
########## recurs rev string #######3
rev (){
    local str=$1
    local len=${#str}
    if ((len == 0));then
       echo ""
    else
       echo -n "${str: -1}"
       rev "${str:0:len-1}"       
    fi   
}

read -p"enter str: " str
res=$(rev "$str")
echo "fact is: $res"