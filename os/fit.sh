#!/bin/bash

first_fit() {
    local processes=("$@")
    echo "First Fit:"
    for i in "${!processes[@]}"; do
        allocated=0
        for j in "${!blocks[@]}"; do
            if [ "${blocks[j]}" -ge "${processes[i]}" ]; then
                echo "Process $((i+1)) of size ${processes[i]} is allocated to block $((j+1)) of size ${blocks[j]}"
                blocks[j]=$((blocks[j] - processes[i]))
                allocated=1
                break
            fi
        done
        if [ "$allocated" -eq 0 ]; then
            echo "Process $((i+1)) of size ${processes[i]} cannot be allocated"
        fi
    done
}

best_fit() {
    local processes=("$@")
    echo "Best Fit:"
    for i in "${!processes[@]}"; do
        best_index=-1
        for j in "${!blocks[@]}"; do
            if [ "${blocks[j]}" -ge "${processes[i]}" ]; then
                if [ "$best_index" -eq -1 ] || [ "${blocks[j]}" -lt "${blocks[best_index]}" ]; then
                    best_index=$j
                fi
            fi
        done
        if [ "$best_index" -ne -1 ]; then
            echo "Process $((i+1)) of size ${processes[i]} is allocated to block $((best_index+1)) of size ${blocks[best_index]}"
            blocks[best_index]=$((blocks[best_index] - processes[i]))
        else
            echo "Process $((i+1)) of size ${processes[i]} cannot be allocated"
        fi
    done
}

# Function for Worst Fit Algorithm
worst_fit() {
    local processes=("$@")
    echo "Worst Fit:"
    for i in "${!processes[@]}"; do
        worst_index=-1
        for j in "${!blocks[@]}"; do
            if [ "${blocks[j]}" -ge "${processes[i]}" ]; then
                if [ "$worst_index" -eq -1 ] || [ "${blocks[j]}" -gt "${blocks[worst_index]}" ]; then
                    worst_index=$j
                fi
            fi
        done
        if [ "$worst_index" -ne -1 ]; then
            echo "Process $((i+1)) of size ${processes[i]} is allocated to block $((worst_index+1)) of size ${blocks[worst_index]}"
            blocks[worst_index]=$((blocks[worst_index] - processes[i]))
        else
            echo "Process $((i+1)) of size ${processes[i]} cannot be allocated"
        fi
    done
}

blocks=(100 500 200 300 600)
processes=(212 417 112 426)

echo "Memory Blocks: ${blocks[@]}"
echo "Processes: ${processes[@]}"


blocks_copy=("${blocks[@]}")
first_fit "${processes[@]}"

blocks=("${blocks_copy[@]}")
best_fit "${processes[@]}"

blocks=("${blocks_copy[@]}")
worst_fit "${processes[@]}"
