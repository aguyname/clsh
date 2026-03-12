# CLSH - Command Line Statement Handler

A lightweight C library for parsing command-line arguments into categories:
- Commands (`-v`, `-o`)
- Special statements (`--help`, `--version`)
- Files (arguments containing `.`)
- Unknown (everything else)

##Installation

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
#include "clsh.h"

clsh obj;
initclsh(&obj);
char *cmds[256], *files[256];
CLShandler(&obj, cmds, files, special, unknown, argc, argv);
```
