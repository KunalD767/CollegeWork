#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 filename"
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "File not found!"
  exit 1
fi

while IFS= read -r line || [ -n "$line" ]; do
  words=$(echo "$line" | wc -w)
  chars=$(echo "$line" | wc -c)
  echo "Line: \"$line\" -> Words: $words, Characters: $chars"
done < "$1"
