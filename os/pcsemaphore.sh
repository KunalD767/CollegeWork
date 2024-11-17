#!/bin/bash

# Create a temporary file to store the buffer
BUFFER_FILE="/tmp/producer_consumer_buffer"
touch "$BUFFER_FILE"

# Initialize semaphores using temporary files
MUTEX="/tmp/mutex_sem"
EMPTY="/tmp/empty_sem"
FULL="/tmp/full_sem"

# Buffer size
BUFFER_SIZE=5

# Initialize semaphore values
echo $BUFFER_SIZE > "$EMPTY"  # Empty slots = BUFFER_SIZE
echo 0 > "$FULL"             # Full slots = 0
echo 1 > "$MUTEX"            # Binary semaphore for mutual exclusion

# Function to implement P (wait) operation
P() {
    local sem_file=$1
    while true; do
        local value=$(cat "$sem_file")
        if [ $value -gt 0 ]; then
            echo $((value - 1)) > "$sem_file"
            break
        fi
        sleep 0.1  # Small delay to prevent busy waiting
    done
}

# Function to implement V (signal) operation
V() {
    local sem_file=$1
    local value=$(cat "$sem_file")
    echo $((value + 1)) > "$sem_file"
}

# Producer function
producer() {
    local id=$1
    local count=0
    
    while [ $count -lt 10 ]; do  # Produce 10 items
        # Wait for empty slot
        P "$EMPTY"
        # Wait for mutex
        P "$MUTEX"
        
        # Produce item
        local item="Item_${id}_${count}"
        echo "$item" >> "$BUFFER_FILE"
        echo "Producer $id produced: $item"
        
        # Release mutex
        V "$MUTEX"
        # Signal full slot
        V "$FULL"
        
        count=$((count + 1))
        sleep $(( ( RANDOM % 2 ) + 1 ))  # Random delay between 1-2 seconds
    done
}

# Consumer function
consumer() {
    local id=$1
    local count=0
    
    while [ $count -lt 10 ]; do  # Consume 10 items
        # Wait for full slot
        P "$FULL"
        # Wait for mutex
        P "$MUTEX"
        
        # Consume item
        local item=$(tail -n 1 "$BUFFER_FILE")
        sed -i '$ d' "$BUFFER_FILE"  # Remove consumed item
        echo "Consumer $id consumed: $item"
        
        # Release mutex
        V "$MUTEX"
        # Signal empty slot
        V "$EMPTY"
        
        count=$((count + 1))
        sleep $(( ( RANDOM % 3 ) + 1 ))  # Random delay between 1-3 seconds
    done
}

# Cleanup function
cleanup() {
    rm -f "$BUFFER_FILE" "$MUTEX" "$EMPTY" "$FULL"
    echo "Cleaned up temporary files"
    exit 0
}

# Set up cleanup on script exit
trap cleanup EXIT

# Start producers and consumers
producer 1 &
producer 2 &
consumer 1 &
consumer 2 &

# Wait for all background processes to complete
wait

exit 0