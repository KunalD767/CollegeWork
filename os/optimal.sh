#!/bin/bash

# Optimal Page Replacement
optimal_page_replacement() {
    frames=$1
    ref_string=("${@:2}")

    declare -a pages=()
    page_faults=0

    for ((i=0; i<${#ref_string[@]}; i++)); do
        page=${ref_string[$i]}
        if [[ ! " ${pages[@]} " =~ " ${page} " ]]; then
            ((page_faults++))
            if [ ${#pages[@]} -lt $frames ]; then
                pages+=($page)
            else
                # Find the page to replace
                replace_index=-1
                furthest_use=-1
                for ((j=0; j<${#pages[@]}; j++)); do
                    next_use=1000
                    for ((k=$i+1; k<${#ref_string[@]}; k++)); do
                        if [ ${pages[$j]} -eq ${ref_string[$k]} ]; then
                            next_use=$k
                            break
                        fi
                    done
                    if [ $next_use -gt $furthest_use ]; then
                        furthest_use=$next_use
                        replace_index=$j
                    fi
                done
                pages[$replace_index]=$page
            fi
        fi
        echo "Pages in memory: ${pages[@]}"
    done

    echo "Total page faults: $page_faults"
}

read -p "Enter the number of frames: " frames
read -p "Enter the reference string (space-separated): " -a ref_string

optimal_page_replacement "$frames" "${ref_string[@]}"
