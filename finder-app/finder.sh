#!/bin/bash

filesdir=$1
searchstr=$2

if [[ $# -lt 2 ]]
then
    echo "Error: Please provide the filesdir and searchstr"
    exit 1
fi

if [[ ! -d $filesdir ]]
then
    echo "Error: $filesdir is not a directory"
    exit 1
fi

# Counting the number of files in the directory and all subdirectories
num_files=$(find "$filesdir" -type f | wc -l)

# Counting the number of matching lines in the files
num_matching_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

# Printing the result
echo "The number of files are $num_files and the number of matching lines are $num_matching_lines"
