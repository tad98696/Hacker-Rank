#!/bin/bash

read expression

value=$(bc -l <<< "$expression")
printf "%.3f\n" "$value"
