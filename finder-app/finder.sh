#!/bin/bash

# Check if two arguments are given
if [ $# -ne 2 ]; then
    echo "Usage: finder.sh <dir> <file>"
    exit 1
fi

# Check if the first argument is a directory
if [ ! -d "$1" ]; then
    echo "$1 is not a directory"
    exit 1
fi

# Find the number of matches and files
files_count=0
matching_lines=0

# For each file in the directory provided by $1 add one to files_count
for file in $(find "$1" -type f); do
    files_count=$((files_count+1))
    matching_lines=$((matching_lines+$(grep -c "$2" "$file")))
done

echo "The number of files are $files_count and the number of matching lines are $matching_lines"
