#!/bin/bash
read x
read y

if [ $x -lt -100 -o $y -lt -100 -o $x -gt 100 -o $y -gt 100 ]; then
  exit 0
fi
[ $y -eq 0 ] && exit 0

echo $(( $x + $y ))
echo $(( $x - $y ))
echo $(( $x * $y ))
echo $(( $x / $y ))
