@echo off
setlocal enabledelayedexpansion

set BUILD_CMD=g++ -std=c++17 -o main -Iinclude -Itest -Itest\unit_test_inventory main.cpp ^
test\unit_test_inventory\unit_test_inventory.cpp test\unit_test.cpp ^
src\Point.cpp src\inventory.cpp 


for %%F in (test\unit_test_inventory\test_case\*.cpp) do (
    set BUILD_CMD=!BUILD_CMD! %%F
)

echo Building project inventory with command:
echo %BUILD_CMD%
echo ----------------------------------------

%BUILD_CMD%
if %ERRORLEVEL%==0 (
    echo Build successful!
    echo ----------------------------------------
    echo To run tests, use one of the following commands:
    echo 1. Run all tests: main
    echo 2. Run a specific test: main nameFunctionUnitTest
) else (
    echo Build failed!
    exit /b 1
)

endlocal
