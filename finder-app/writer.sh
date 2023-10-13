#!/bin/bash

# Check if two arguments are given
if [ $# -ne 2 ]; then
    echo "Usage: writer.sh <file> <input_text>"
    exit 1
fi

# Remove the file if exists
if [ -f "$1" ]; then
    rm "$1"
fi

# Create the file and directory if not exists
mkdir -p "$(dirname "$1")"
echo "$2" > "$1"

# Check if the file was created
if ! [ -f "$1" ]; then
    echo "File was not created"
    exit 1
fi
