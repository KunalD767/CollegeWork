#!/bin/bash

read -p "Enter number of processes: " n
read -p "Enter time quantum: " quantum
declare -a burst remaining waiting turnaround

for ((i=0; i<n; i++))
do
    read -p "Enter burst time for process P$((i+1)): " burst[$i]
    remaining[$i]=${burst[$i]}
done

total=0
time=0
processes_left=$n

while [ $processes_left -gt 0 ]
do
    for ((i=0; i<n; i++))
    do
        if [ ${remaining[$i]} -gt 0 ]; then
            if [ ${remaining[$i]} -le $quantum ]; then
                time=$((time + remaining[$i]))
                remaining[$i]=0
                turnaround[$i]=$time
                waiting[$i]=$((turnaround[$i] - ${burst[$i]}))
                processes_left=$((processes_left - 1))
            else
                time=$((time + $quantum))
                remaining[$i]=$((remaining[$i] - $quantum))
            fi
        fi
    done
done

echo -e "Process\tBurst\tWaiting\tTurnaround"
for ((i=0; i<n; i++))
do
    echo -e "P$((i+1))\t${burst[$i]}\t${waiting[$i]}\t${turnaround[$i]}"
done
