#!/bin/bash

fcfs() {
  n=$1  
  burst_times=("${@:2}")  

  wait_time[0]=0
  total_wait_time=0
  total_turnaround_time=0

  echo "Process   Burst Time   Waiting Time   Turnaround Time"

  for ((i=0; i<n; i++)); do
    if ((i > 0)); then
      wait_time[i]=$((wait_time[i-1] + burst_times[i-1]))
    fi

    turnaround_time[i]=$((wait_time[i] + burst_times[i]))

    echo "P$i        ${burst_times[i]}            ${wait_time[i]}               ${turnaround_time[i]}"

    total_wait_time=$((total_wait_time + wait_time[i]))
    total_turnaround_time=$((total_turnaround_time + turnaround_time[i]))
  done

  avg_wait_time=$(echo "scale=2; $total_wait_time / $n" | bc)
  avg_turnaround_time=$(echo "scale=2; $total_turnaround_time / $n" | bc)

  echo "Average Waiting Time: $avg_wait_time"
  echo "Average Turnaround Time: $avg_turnaround_time"
}

# Input for FCFS scheduling
read -p "Enter number of processes: " n
burst_times=()  

for ((i=0; i<n; i++)); do
  read -p "Enter burst time for process P$i: " bt
  burst_times+=($bt)  
done

fcfs "$n" "${burst_times[@]}"
