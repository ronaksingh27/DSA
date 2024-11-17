#!/bin/bash

# Get the directory path
TARGET_DIR=$(pwd)

# Verify the directory exists
if [ ! -d "$TARGET_DIR" ]; then
  echo "Error: Directory $TARGET_DIR does not exist."
  exit 1
fi

# Find and delete executable files
find "$TARGET_DIR" -type f -perm +111 -exec rm -v {} \;

echo "All executable files have been deleted from $TARGET_DIR and its subfolders."
