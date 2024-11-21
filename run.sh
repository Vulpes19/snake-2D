#!/bin/bash

# Detect and run the executable
if [ -f "build/Debug/snake-2d.exe" ]; then
    echo "Running Debug version"
    build/Debug/snake-2d.exe
elif [ -f "build/Release/snake-2d.exe" ]; then
    echo "Running Release version"
    build/Release/snake-2d.exe
else
    echo "Executable not found. Please build the project first."
    exit 1
fi