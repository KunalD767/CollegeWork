#!/bin/bash

declare -A allocation
declare -A max_need
declare -A need
declare -a available
declare -a processes
declare -a safe_sequence
declare -a work
declare -a finish

init_data() {
    processes=(P0 P1 P2 P3 P4)
    resources=(A B C)
    
    allocation=(
        [P0,A]=0 [P0,B]=1 [P0,C]=0
        [P1,A]=2 [P1,B]=0 [P1,C]=0
        [P2,A]=3 [P2,B]=0 [P2,C]=2
        [P3,A]=2 [P3,B]=1 [P3,C]=1
        [P4,A]=0 [P4,B]=0 [P4,C]=2
    )
    
    max_need=(
        [P0,A]=7 [P0,B]=5 [P0,C]=3
        [P1,A]=3 [P1,B]=2 [P1,C]=2
        [P2,A]=9 [P2,B]=0 [P2,C]=2
        [P3,A]=2 [P3,B]=2 [P3,C]=2
        [P4,A]=4 [P4,B]=3 [P4,C]=3
    )
    
    available=(3 3 2)
    
    for p in "${processes[@]}"; do
        finish[$p]=0
        for r in "${resources[@]}"; do
            need[$p,$r]=$((max_need[$p,$r] - allocation[$p,$r]))
        done
    done
}

print_state() {
    echo "Current State:"
    echo "Process  Allocation  Max Need  Need        Available"
    echo "        A  B  C     A  B  C   A  B  C     A  B  C"
    echo "---------------------------------------------------"
    
    for p in "${processes[@]}"; do
        printf "%-8s" "$p"
        printf "%d  %d  %d     " "${allocation[$p,A]}" "${allocation[$p,B]}" "${allocation[$p,C]}"
        printf "%d  %d  %d   " "${max_need[$p,A]}" "${max_need[$p,B]}" "${max_need[$p,C]}"
        printf "%d  %d  %d     " "${need[$p,A]}" "${need[$p,B]}" "${need[$p,C]}"
        if [ "$p" = "${processes[0]}" ]; then
            printf "%d  %d  %d" "${available[0]}" "${available[1]}" "${available[2]}"
        fi
        echo
    done
    echo
}

is_safe() {
    local -a work=("${available[@]}")
    local -A finish
    local -a sequence=()
    
    for p in "${processes[@]}"; do
        finish[$p]=0
    done
    
    while true; do
        local found=0
        for p in "${processes[@]}"; do
            if [ "${finish[$p]}" -eq 0 ]; then
                local can_allocate=1
                for ((r=0; r<${#resources[@]}; r++)); do
                    if [ "${need[$p,${resources[$r]}]}" -gt "${work[$r]}" ]; then
                        can_allocate=0
                        break
                    fi
                done
                
                if [ $can_allocate -eq 1 ]; then
                    for ((r=0; r<${#resources[@]}; r++)); do
                        work[$r]=$((work[$r] + allocation[$p,${resources[$r]}]))
                    done
                    finish[$p]=1
                    sequence+=("$p")
                    found=1
                fi
            fi
        done
        
        if [ $found -eq 0 ]; then
            break
        fi
    done
    
    for p in "${processes[@]}"; do
        if [ "${finish[$p]}" -eq 0 ]; then
            return 1
        fi
    done
    
    safe_sequence=("${sequence[@]}")
    return 0
}

request_resources() {
    local process=$1
    local -a request=("${@:2}")
    
    echo "Processing request from $process: ${request[*]}"
    
    for ((r=0; r<${#resources[@]}; r++)); do
        if [ "${request[$r]}" -gt "${need[$process,${resources[$r]}]}" ]; then
            echo "Error: Request exceeds maximum need"
            return 1
        fi
        if [ "${request[$r]}" -gt "${available[$r]}" ]; then
            echo "Error: Request exceeds available resources"
            return 1
        fi
    done
    
    for ((r=0; r<${#resources[@]}; r++)); do
        available[$r]=$((available[$r] - request[$r]))
        allocation[$process,${resources[$r]}]=$((allocation[$process,${resources[$r]}] + request[$r]))
        need[$process,${resources[$r]}]=$((need[$process,${resources[$r]}] - request[$r]))
    done
    
    if is_safe; then
        echo "Request granted. System is in safe state."
        echo "Safe sequence: ${safe_sequence[*]}"
        return 0
    else
        echo "Request denied. System would enter unsafe state."
        for ((r=0; r<${#resources[@]}; r++)); do
            available[$r]=$((available[$r] + request[$r]))
            allocation[$process,${resources[$r]}]=$((allocation[$process,${resources[$r]}] - request[$r]))
            need[$process,${resources[$r]}]=$((need[$process,${resources[$r]}] + request[$r]))
        done
        return 1
    fi
}

main() {
    init_data
    print_state
    
    echo "Checking if initial state is safe..."
    if is_safe; then
        echo "Initial state is safe."
        echo "Safe sequence: ${safe_sequence[*]}"
    else
        echo "Initial state is unsafe!"
        exit 1
    fi
    
    echo -e "\nTesting resource requests..."
    
    echo -e "\nTest Case 1: P1 requests (1, 0, 2)"
    request_resources "P1" 1 0 2
    print_state
    
    echo -e "\nTest Case 2: P4 requests (3, 3, 0)"
    request_resources "P4" 3 3 0
    print_state
    
    echo -e "\nTest Case 3: P0 requests (0, 2, 0)"
    request_resources "P0" 0 2 0
    print_state
}

main