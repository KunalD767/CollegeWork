#!/bin/bash

if [ "$#" -ne 3 ]; then
  echo "Usage: $0 num1 num2 num3"
  exit 1
fi

num1=$1
num2=$2
num3=$3

if [ "$num1" -ge "$num2" ] && [ "$num1" -ge "$num3" ]; then
  echo "$num1 is the greatest"
elif [ "$num2" -ge "$num1" ] && [ "$num2" -ge "$num3" ]; then
  echo "$num2 is the greatest"
else
  echo "$num3 is the greatest"
fi


