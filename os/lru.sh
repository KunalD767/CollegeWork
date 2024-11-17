#!/bin/bash

lru_page_replacement() {
    frames=$1
    ref_string=("${@:2}")

    declare -a pages=()
    declare -a last_used=()
    page_faults=0
    time=0

    for page in "${ref_string[@]}"; do
        found=0
        # Check if the page is already in the memory
        for ((i=0; i<${#pages[@]}; i++)); do
            if [ "${pages[$i]}" == "$page" ]; then
                found=1
                last_used[$i]=$time  # Update the time for LRU
                break
            fi
        done

        if [ $found -eq 0 ]; then
            ((page_faults++))
            if [ ${#pages[@]} -lt $frames ]; then
                pages+=($page)
                last_used+=($time)
            else
                # Find the least recently used page
                lru_index=0
                for ((i=1; i<${#pages[@]}; i++)); do
                    if [ ${last_used[$i]} -lt ${last_used[$lru_index]} ]; then
                        lru_index=$i
                    fi
                done
                pages[$lru_index]=$page
                last_used[$lru_index]=$time
            fi
        fi
        echo "Pages in memory: ${pages[@]}"
        ((time++))
    done

    echo "Total page faults: $page_faults"
}

read -p "Enter the number of frames: " frames
read -p "Enter the reference string (space-separated): " -a ref_string

lru_page_replacement "$frames" "${ref_string[@]}"
