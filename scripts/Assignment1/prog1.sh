#!/bin/bash

echo "Enter length of the rectangle :"

read len

echo "Enter width of the rectangle :"
read width
if [ $len == $width ]
then
	echo "Length and width can not be same."
else
perimeter=$(echo "2 * ($len + $width)" | bc)
area=$(expr $len \* $width)
echo "perimeter of the given rectangle = $perimeter and area = $area"
fi
