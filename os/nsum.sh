#!/bin/bash

read -p "Enter a number to calculate the sum of its digits: " num

if ! [[ "$num" =~ ^[0-9]+$ ]]; then
  echo "Please enter a valid non-negative integer."
  exit 1
fi

sum=0
while [ $num -gt 0 ]; do
  digit=$((num % 10))
  sum=$((sum + digit))
  num=$((num / 10))
done

echo "The sum of the digits is: $sum"
