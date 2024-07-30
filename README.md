# String Calculator TDD Kata

## Overview

This project implements a String Calculator using Test-Driven Development (TDD) in C++ with Google Test.

## Installation

### Google Test

1. Clone the Google Test repository: `git clone https://github.com/google/googletest.git`
2. Build and install Google Test: `cd googletest && mkdir build && cd build && `cmake -G "MinGW Makefiles" ..` && ` C:\MinGW\bin\mingw32-make  ` && ` C:\MinGW\bin\mingw32-make install`

### Project

1. Clone this repository: `git clone https://github.com/your-username/String-Calculator-TDD-Kata.git`
2. Build and run the project:
	* `cd String-Calculator-TDD-Kata`
	* `mkdir build && cd build`
	* `cmake -G "MinGW Makefiles" ..`
	* ` C:\MinGW\bin\mingw32-make  `
	* `./string_calculator_test.cpp`

## TDD Workflow

1. Write a test
2. Run the test
3. Write the code
4. Refactor
5. Repeat

## Google Test Usage

* `GTEST_TEST`: Defines a test case
* `ASSERT_EQ`: Checks if two values are equal
* `EXPECT_EQ`: Checks if two values are equal, and continues execution if they are not
* `RUN_ALL_TESTS()`: Executes all test cases

## Project Structure

* `src/`: Source files for the String Calculator implementation
* `test/`: Test files for the String Calculator implementation
* `include/`: Header files for the String Calculator implementation
* `build/`: Build directory for the project
