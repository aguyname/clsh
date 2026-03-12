# CLSH - Command Line Statement Handler

A lightweight C library for parsing command-line arguments into categories:
- Commands (`-v`, `-o`)
- Special statements (`--help`, `--version`)
- Files (arguments containing `.`)
- Unknown (everything else)

## Features
- Simple API
- Buffer overflow protection
- Configurable limits
- Debug support

## Quick Start
```c
#include "clsh.h"

clsh obj;
initclsh(&obj);
char *cmds[256], *files[256];
CLShandler(&obj, cmds, files, special, unknown, argc, argv);
