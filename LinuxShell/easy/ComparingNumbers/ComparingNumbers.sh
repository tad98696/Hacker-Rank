#!/bin/bash

read x
read y

[ $x -lt $y ] && echo "X is less than Y"
[ $x -gt $y ] && echo "X is greater than Y"
[ $x -eq $y ] && echo "X is equal to Y"
