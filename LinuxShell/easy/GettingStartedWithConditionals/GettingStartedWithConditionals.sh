#!/bin/bash

read input

[ $input == "y" -o $input == "Y" ] && echo "YES"
[ $input == "n" -o $input == "N" ] && echo "NO"
