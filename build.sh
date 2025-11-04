#!/bin/bash
# Build script for CircuitBuilder
# Fixes for Qt 6.9.0 on macOS with Xcode 17+
# - Disables SDK version check (Qt 6.9.0 doesn't officially support macOS SDK 26.1)
# - Removes deprecated AGL framework

set -e  # Exit on error

QMAKE="$HOME/Qt/6.9.0/macos/bin/qmake"

echo "=== CircuitBuilder Build Script ==="
echo ""

# Step 1: Clean previous build
echo "Step 1: Cleaning previous build..."
make clean 2>/dev/null || true
rm -f .qmake.stash Makefile

# Step 2: Generate Makefile
echo "Step 2: Generating Makefile..."
"$QMAKE" CircuitBuilder.pro

# Step 3: Patch Makefile to remove AGL framework
echo "Step 3: Patching Makefile (removing deprecated AGL framework)..."
sed -i.bak 's/-framework AGL //g' Makefile
echo "  - Removed AGL framework references"

# Step 4: Build
echo "Step 4: Building CircuitBuilderApp..."
make "$@"

echo ""
echo "=== Build Complete ==="
echo "Application: CircuitBuilderApp.app/Contents/MacOS/CircuitBuilderApp"
echo ""
echo "To run: open CircuitBuilderApp.app"
