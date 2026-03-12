#!/bin/bash

# CLSH Shared Library Installer
# Author: T.Vikram (an idiot don't be like me)
# Date: 12/06/2026

echo "==================================="
echo "CLSH - Command Line Statement Handler"
echo "==================================="

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo "gcc not found. Please install gcc first."
    exit 1
fi

# Compile as shared library
echo "building shared library..."
gcc -c -Wall -Wextra -std=c99 -fPIC -O2 clsh.c -o clsh.o
gcc -shared clsh.o -o libclsh.so

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Make library executable
chmod 644 libclsh.so

# Optional: Install system-wide
read -p "Install to /usr/local? (requires sudo) [y/N]: " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]; then
    # Install library
    sudo cp libclsh.so /usr/local/lib/
    sudo ldconfig  # Update linker cache
    
    # Install header
    sudo cp clsh.h /usr/local/include/
    
    echo "Library installed to /usr/local/lib/libclsh.so"
    echo "Header installed to /usr/local/include/clsh.h"
    echo ""
    echo "To compile programs using CLSH:"
    echo " gcc your_program.c -lclsh -o your_program"
else
    echo "Library built locally as ./libclsh.so"
    echo "Header available as ./clsh.h"
    echo ""
    echo "To compile with local library:"
    echo "  gcc your_program.c -L. -lclsh -o your_program"
    echo "  export LD_LIBRARY_PATH=.:\$LD_LIBRARY_PATH"
fi

echo
echo "Build complete! Thanks for using my library :)"
