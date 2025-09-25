cmake_minimum_required(VERSION 3.16)
project(CircuitBuilderTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# Find required packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test)
find_package(GTest REQUIRED)

# Enable code coverage
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/../
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
    ${Qt6Test_INCLUDE_DIRS}
)

# Source files to test (minimal for now)
set(SOURCE_FILES
    ../Gate.cpp
)

# Test files (simple working tests)
set(TEST_FILES
    test_simple.cpp
)

# Create test executable
add_executable(circuit_tests
    main_test.cpp
    ${TEST_FILES}
    ${SOURCE_FILES}
)

# Link libraries
target_link_libraries(circuit_tests
    Qt6::Core
    Qt6::Widgets
    Qt6::Test
    GTest::GTest
    GTest::Main
    pthread
)

# Add test discovery
include(GoogleTest)
gtest_discover_tests(circuit_tests)