#!/bin/bash

sum=0
count=0

read -p "How many numbers will you enter? " n

if ! [[ "$n" =~ ^[0-9]+$ ]] || [ "$n" -le 0 ]; then
  echo "Please enter a valid positive integer."
  exit 1
fi

while [ $count -lt $n ]; do
  read -p "Enter number $((count + 1)): " number
  if ! [[ "$number" =~ ^-?[0-9]+([.][0-9]+)?$ ]]; then
    echo "Invalid input. Please enter a numeric value."
    continue
  fi
  sum=$(echo "$sum + $number" | bc)
  count=$((count + 1))
done

average=$(echo "$sum / $n" | bc -l)
echo "The average of the $n numbers is: $average"
