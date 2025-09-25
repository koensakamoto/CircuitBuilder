#!/bin/bash

# Script to run unit and integration tests with coverage

set -e

echo "=== Building and Running CircuitBuilder Tests ==="

# Create build directory for tests
mkdir -p build-tests
cd build-tests

# Configure with CMake for coverage
echo "Configuring CMake..."
cmake ../tests -DCMAKE_BUILD_TYPE=Debug

# Build tests
echo "Building tests..."
make -j$(nproc)

# Create test reports directory first
mkdir -p ../test-reports

# Run tests with coverage
echo "Running tests..."
./circuit_tests --gtest_output=xml:../test-reports/test-results.xml

# Generate coverage report
echo "Generating coverage reports..."

# Generate lcov report
lcov --capture --directory . --output-file ../test-reports/coverage.info
lcov --remove ../test-reports/coverage.info '/usr/*' '*/test/*' --output-file ../test-reports/coverage.info

# Generate HTML report
genhtml ../test-reports/coverage.info --output-directory ../test-reports/html

# Generate Cobertura XML for CI/CD integration
gcovr -r .. --xml --xml-pretty --output ../test-reports/coverage.xml

# Calculate coverage percentage
COVERAGE=$(lcov --summary ../test-reports/coverage.info 2>&1 | grep "lines" | sed 's/.*: \([0-9.]*\)%.*/\1/')

echo "=== Test Summary ==="
echo "Coverage: ${COVERAGE}%"

# Check if coverage meets minimum requirement (90%)
if (( $(echo "$COVERAGE < 90" | bc -l) )); then
    echo "WARNING: Code coverage is below 90% threshold!"
    exit 1
else
    echo "SUCCESS: Code coverage meets the 90% requirement!"
fi

echo "Test reports generated in test-reports/"
echo "  - test-results.xml: JUnit test results"
echo "  - coverage.xml: Cobertura coverage report"
echo "  - coverage.info: LCOV coverage data"
echo "  - html/: HTML coverage report"