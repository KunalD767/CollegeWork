#!/bin/bash

read -p "Enter a string to check if it's a palindrome: " input

# Remove spaces and convert to lowercase for comparison
cleaned_input=$(echo "$input" | tr -d ' ' | tr '[:upper:]' '[:lower:]')

start=0
end=$((${#cleaned_input} - 1))
is_palindrome=1

while [ $start -lt $end ]; do
  if [ "${cleaned_input:$start:1}" != "${cleaned_input:$end:1}" ]; then
    is_palindrome=0
    break
  fi
  start=$((start + 1))
  end=$((end - 1))
done

if [ $is_palindrome -eq 1 ]; then
  echo "The string \"$input\" is a palindrome."
else
  echo "The string \"$input\" is not a palindrome."
fi
