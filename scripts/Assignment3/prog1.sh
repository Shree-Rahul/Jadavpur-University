#!/bin/bash

echo -n "Enter the input file name :"
read input_file
echo -n "Enter the output file name:"
read output_file

if [ ! -f $input_file ]; then
    echo "Invalid Directory !"
    exit 1
fi

while read line; do
    num1=$(echo $line | awk '{print $1}')
    num2=$(echo $line | awk '{print $2}')
    num3=$(echo $line | awk '{print $3}')

    sum=$(($num1 + $num2 + $num3 ))
    echo $sum >> $output_file
done < $input_file

echo "Some of all the lines are stored in $output_file"