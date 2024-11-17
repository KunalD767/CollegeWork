#!/bin/bash

read -p "Enter a number to calculate its factorial: " num

if ! [[ "$num" =~ ^[0-9]+$ ]] || [ "$num" -lt 0 ]; then
  echo "Please enter a valid non-negative integer."
  exit 1
fi

factorial=1
counter=$num

while [ $counter -gt 1 ]; do
  factorial=$((factorial * counter))
  counter=$((counter - 1))
done

echo "The factorial of $num is: $factorial"
