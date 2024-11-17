#!/bin/bash

readers=0
writer=0

reader() {
    while true; do
        ((readers++))
        if [ "$readers" -eq 1 ]; then
            echo "First reader blocking writer."
            ((writer++))
        fi
        echo "Reader is reading..."
        sleep 2
        echo "Reader done reading."
        ((readers--))
        if [ "$readers" -eq 0 ]; then
            echo "Last reader unblocking writer."
            ((writer--))
        fi
        sleep 1
    done
}

writer() {
    while true; do
        if [ "$writer" -eq 0 ]; then
            echo "Writer is writing..."
            sleep 2
            echo "Writer done writing."
        else
            echo "Writer waiting for readers..."
        fi
        sleep 1
    done
}

reader &
reader &
writer &

wait
