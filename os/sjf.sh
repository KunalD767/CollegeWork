#!/bin/bash

sjf_scheduling() {
  n=$1  
  burst_times=("${@:2}")  

  wait_time=()
  turnaround_time=()

  total_wait_time=0
  total_turnaround_time=0

  for ((i = 0; i < n; i++)); do
    for ((j = i + 1; j < n; j++)); do
      if [ "${burst_times[$i]}" -gt "${burst_times[$j]}" ]; then
        temp="${burst_times[$i]}"
        burst_times[$i]="${burst_times[$j]}"
        burst_times[$j]="$temp"
      fi
    done
  done

  wait_time[0]=0  

  for ((i = 1; i < n; i++)); do
    wait_time[$i]=$((${wait_time[$i-1]} + ${burst_times[$i-1]}))
    total_wait_time=$(($total_wait_time + ${wait_time[$i]}))
  done

  for ((i = 0; i < n; i++)); do
    turnaround_time[$i]=$((${wait_time[$i]} + ${burst_times[$i]}))
    total_turnaround_time=$(($total_turnaround_time + ${turnaround_time[$i]}))
  done

  echo "Process   Burst Time   Waiting Time   Turnaround Time"
  for ((i = 0; i < n; i++)); do
    echo "P$i        ${burst_times[$i]}            ${wait_time[$i]}             ${turnaround_time[$i]}"
  done

  avg_wait_time=$(echo "scale=2; $total_wait_time / $n" | bc)
  avg_turnaround_time=$(echo "scale=2; $total_turnaround_time / $n" | bc)

  echo "Average Waiting Time: $avg_wait_time"
  echo "Average Turnaround Time: $avg_turnaround_time"
}

read -p "Enter number of processes: " n
burst_times=()

for ((i = 0; i < n; i++)); do
  read -p "Enter burst time for process P$i: " burst_time
  burst_times+=($burst_time)
done

sjf_scheduling "$n" "${burst_times[@]}"

