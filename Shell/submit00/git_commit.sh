#!/bin/bash

# Get the last 5 commit IDs using git log command
commit_ids=$(git log --format="%H" -n 5)

# Loop through the commit IDs and display them
for commit_id in $commit_ids; do
    echo "$commit_id"
done