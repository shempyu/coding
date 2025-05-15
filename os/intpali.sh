#!/bin/bash
echo "enetr num"
read n
o=$n
rev=0
while (( n >0 ))   
 do 
   rev=$(((rev * 10) + (n % 10)))
   n=$((n/10))
done
if (( o == rev ));then
 echo "palindrome"
else
  echo "not palindrome"
fi   
 
