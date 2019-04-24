#!/bin/bash

read x
read y
read z

if [ $x -lt 1 -o $y -lt 1 -o $z -lt 1 -o \
     $x -gt 1000 -o $y -gt 1000 -o $z -gt 1000 ]; then
  exit 0
fi
if [ $(( $x + $y )) -le $z -o \
     $(( $x + $z )) -le $y -o \
     $(( $y + $z )) -le $x ]; then
  exit 0
fi

if [ $x -eq $y -a $y -eq $z ]; then
  echo "EQUILATERAL"
fi

if [ $x -ne $y -a $x -ne $z -a $y -ne $z ]; then
  echo "SCALENE"
fi

if [ $x -eq $y -a $y -ne $z ] || \
   [ $x -eq $z -a $y -ne $z ] || \
   [ $y -eq $z -a $x -ne $y ]; then
  echo "ISOSCELES"
fi
