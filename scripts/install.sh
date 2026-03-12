#!/bin/bash

# CLSH Shared Library Installer
# Author: T.Vikram (an idiot don't be like me)
# Date: 12/06/2026

echo "building library's..."

# Get the script's directory (where this installer is located)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
echo "Installer location: $SCRIPT_DIR"

# Navigate to project root (assuming script is in scripts/)
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
echo "Project root: $PROJECT_ROOT"

# Set paths to source files
SRC_DIR="$PROJECT_ROOT/src"
CLSH_C="$SRC_DIR/clsh.c"
CLSH_H="$SRC_DIR/clsh.h"

# Verify source files exist
if [ ! -f "$CLSH_C" ]; then
    echo "Error: Cannot find clsh.c at $CLSH_C"
    exit 1
fi

if [ ! -f "$CLSH_H" ]; then
    echo "Error: Cannot find clsh.h at $CLSH_H"
    exit 1
fi

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo "gcc not found. Please install gcc first."
    exit 1
fi

# Navigate to src directory for compilation
cd "$SRC_DIR" || {
    echo "Failed to enter src directory"
    exit 1
}

echo "Building shared library from: $(pwd)..."

# Compile as shared library
gcc -c -Wall -Wextra -std=c99 -fPIC -O2 clsh.c -o clsh.o
gcc -shared clsh.o -o libclsh.so

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Make library readable
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
    
    # Clean up build files
    rm -f clsh.o
    echo "Build files cleaned up"
else
    echo "Library built locally in $SRC_DIR/libclsh.so"
    echo "Header available at $SRC_DIR/clsh.h"
    
    # Copy library to project root for easier access
    cp libclsh.so "$PROJECT_ROOT/"
    echo "Also copied libclsh.so to project root: $PROJECT_ROOT"
    
    echo ""
    echo "To compile with local library:"
    echo "  cd $PROJECT_ROOT"
    echo "  gcc your_program.c -L. -lclsh -o your_program"
    echo "  export LD_LIBRARY_PATH=.:\$LD_LIBRARY_PATH"
fi

echo
echo "Build complete! Thanks for using my library :)"
