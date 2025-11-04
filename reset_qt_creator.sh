#!/bin/bash
# Reset Qt Creator configuration for CircuitBuilder
# Run this script, then reopen the project in Qt Creator

echo "=== Resetting Qt Creator Configuration ==="
echo ""

# Step 1: Remove Qt Creator user files
echo "Step 1: Removing Qt Creator user configuration..."
rm -f CircuitBuilder.pro.user
rm -f CircuitBuilder.pro.user.*
rm -f .qmake.conf
echo "  ✓ Removed .pro.user files"

# Step 2: Clean build artifacts
echo ""
echo "Step 2: Cleaning build artifacts..."
if [ -f Makefile ]; then
    make clean 2>/dev/null || true
fi
rm -f Makefile Makefile.bak
rm -f .qmake.stash
rm -f moc_*.cpp moc_*.o
rm -f qrc_*.cpp qrc_*.o
rm -f ui_*.h
rm -f *.o
echo "  ✓ Cleaned build artifacts"

# Step 3: Remove shadow build directories
echo ""
echo "Step 3: Searching for shadow build directories..."
SHADOW_BUILDS=$(find .. -maxdepth 2 -name "build-CircuitBuilder*" -type d 2>/dev/null)
if [ -n "$SHADOW_BUILDS" ]; then
    echo "Found shadow build directories:"
    echo "$SHADOW_BUILDS"
    echo ""
    read -p "Delete these directories? (y/n) " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo "$SHADOW_BUILDS" | while read dir; do
            rm -rf "$dir"
            echo "  ✓ Deleted $dir"
        done
    fi
else
    echo "  ✓ No shadow build directories found"
fi

echo ""
echo "=== Reset Complete ==="
echo ""
echo "Next steps:"
echo "1. Open Qt Creator"
echo "2. Open CircuitBuilder.pro"
echo "3. Configure the project with Qt 6.9.0 kit"
echo "4. Build → Clean All Projects"
echo "5. Build → Run qmake"
echo "6. Build → Build All Projects"
echo ""
echo "If Qt Creator still has issues, use command-line build:"
echo "  ./build.sh"
