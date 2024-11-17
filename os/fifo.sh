#!/bin/bash

fifo_page_replacement() {
    frames=$1
    ref_string=("${@:2}")

    declare -a pages=()
    page_faults=0
    index=0

    for page in "${ref_string[@]}"; do
        if [[ ! " ${pages[@]} " =~ " ${page} " ]]; then
            ((page_faults++))
            if [ ${#pages[@]} -lt $frames ]; then
                pages+=($page)
            else
                pages[$index]=$page
                index=$(( (index+1) % frames ))
            fi
        fi
        echo "Pages in memory: ${pages[@]}"
    done

    echo "Total page faults: $page_faults"
}

read -p "Enter the number of frames: " frames
read -p "Enter the reference string (space-separated): " -a ref_string

fifo_page_replacement "$frames" "${ref_string[@]}"
