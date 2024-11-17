#!/bin/bash

read -p "Enter the number of terms for the Fibonacci series: " n

if ! [[ "$n" =~ ^[0-9]+$ ]] || [ "$n" -le 0 ]; then
  echo "Please enter a valid positive integer."
  exit 1
fi

a=0
b=1
count=0

echo "Fibonacci series up to $n terms:"
while [ $count -lt $n ]; do
  echo -n "$a "
  temp=$a
  a=$b
  b=$((temp + b))
  count=$((count + 1))
done
echo
