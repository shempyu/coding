#!/bin/bash
########## recurs rev string #######3
leap(){
    year=$1
    if ((year % 400 == 0));then
      echo "leap"
    elif ((year %100 == 0));then
      echo "no leap"
    elif ((year %4 == 0)); then
      echo "leap"
    else 
       echo " not leap" 
    fi         

}
read -p "enter a year: " year
leap $year

: '
#!/bin/bash
# decimal to binary
echo " enter a deci num: "
read deci
bin=" "
while((deci > 0)) ; do
rem=$((deci%2))
bin=$rem$bin
deci=$((deci/2))
done
echo "bin: $bin"
'
###############################
: '
#!/bin/bash
# binary to decimal
echo "enter bin "
read bin
len=${#bin}
deci=0
j=0
for ((i=len -1 ;i>=0;i--)) ;do
 bit=${bin:i:1}
 deci=$((deci+ bit *(2 ** j)))
 j=$((j+1))
done
echo "deci : $deci"
'


