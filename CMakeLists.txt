cmake_minimum_required(VERSION 3.13)

project(StringCalculator)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up Google Test
set(GOOGLETEST_INCLUDE_DIR "C:/Users/dellc/Documents/String_Calculator_CPP/test/googletest/googletest/include")
set(GOOGLETEST_LIB_DIR "C:/Users/dellc/Documents/String_Calculator_CPP/test/googletest/build/lib")

# Add source files
set(SOURCES
    src/string_calculator.cpp
)

set(TEST_SOURCES
    test/string_calculator_test.cpp
)

# Add library
add_library(string_calculator STATIC ${SOURCES})

# Add executable for tests
add_executable(string_calculator_test ${TEST_SOURCES})

# Include Google Test headers
include_directories(${GOOGLETEST_INCLUDE_DIR})

# Link Google Test libraries
target_link_libraries(string_calculator_test
    ${GOOGLETEST_LIB_DIR}/libgtest.a
    ${GOOGLETEST_LIB_DIR}/libgtest_main.a
    string_calculator
)

# Enable testing
enable_testing()

# Add tests
add_test(NAME StringCalculatorTests COMMAND string_calculator_test)
