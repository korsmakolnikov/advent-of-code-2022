cmake_minimum_required(VERSION 3.15)
project(AdventDayOne)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CALORIES_COUNTER ./src/calories_counter.hpp
                             ./src/calories_counter.cpp)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} CALORIES_COUNTER)

find_package(Catch2 3 REQUIRED)

add_executable(tests ./tests/test.cpp)
target_link_libraries(tests Catch2::Catch2WithMain CALORIES_COUNTER)

include(CTest)
include(Catch)
catch_discover_tests(tests)
