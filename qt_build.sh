#!/bin/bash
# Qt Creator build helper script
# This patches the Makefile and builds the project

# Patch Makefile to remove AGL framework
if [ -f "Makefile" ]; then
    sed -i.bak 's/-framework AGL //g' Makefile
fi

# Run make with all arguments passed to this script
make "$@"
