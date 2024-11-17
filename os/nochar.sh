#!/bin/bash
read input
if [[ "$input" =~ ^[0-9]+$ ]]; then
  echo "Input is a number"
else
  echo "Input is a string"
fi
