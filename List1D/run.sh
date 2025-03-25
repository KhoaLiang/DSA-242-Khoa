#!/bin/bash

BUILD_CMD="g++ -std=c++17 -o main -Iinclude -Itest -Itest/unit_test_List1D -g main.cpp \
test/unit_test_List1D/unit_test_List1D.cpp test/unit_test.cpp \
 src/Point.cpp test/unit_test_List1D/test_case/*.cpp"

echo "Building project List1D with command:"
echo "$BUILD_CMD"
echo "----------------------------------------"
eval $BUILD_CMD
if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "----------------------------------------"
    echo "To run tests, use one of the following commands:"
    echo "1. Run all tests: ./main "
    echo "2. Run a specific test: ./main nameFunctionUnitTest"
else
    echo "Build failed!"
    exit 1
fi
