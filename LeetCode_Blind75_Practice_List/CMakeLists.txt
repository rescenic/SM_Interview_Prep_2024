cmake_minimum_required(VERSION 3.20)

project(HankerRank LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(IntegerToRoman "IntegerToRoman.cpp")
add_executable(RomanToInteger "RomanToInteger.cpp")
add_executable(MaxPointsOnALine "MaxPointsOnALine.cpp")
add_executable(CountPrimes "CountPrimes.cpp")
add_executable(SuperPow "SuperPow.cpp")
add_executable(FibonacciNumber "FibonacciNumber.cpp")
add_executable(FourDivisors "FourDivisors.cpp")
