# CLSH - Command Line Statement Handler

A lightweight C library for parsing command-line arguments into categories:
- Commands (`-v`, `-o`)
- Special statements (`--help`, `--version`)
- Files (arguments containing `.`)
- Unknown (everything else)

## Installation

```bash
git clone https://github.com/aguyname/clsh.git
cd clsh
chmod +x scripts/install.sh
./scripts/install.sh
```
-you can also make it system wide (linux only)

## Features
- Simple API
- Buffer overflow protection
- Configurable limits
- Debug support

## Quick Start
```c
#include <stdio.h>
#include "clsh.c"

int main(int argc, char **argv) {
    clsh my_obj;
    initclsh(&my_obj);

    char *commands[256];
    char *files[256];
    char *spe[256];
    char *unknown[256];

    CLShandler(&my_obj, commands, files, spe, unknown, argc, argv);

    for (int i = 0; i < getspelen(&my_obj); i++) {
        printf("%s\n", spe[i]); // Example: "--help"
    }

    return 0;
}
```
