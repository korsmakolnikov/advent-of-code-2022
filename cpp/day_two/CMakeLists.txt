cmake_minimum_required(VERSION 3.15)
project(AdventDayTwo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(GAME_ENGINE ./src/engine.hpp ./src/engine.cpp)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} GAME_ENGINE)

find_package(Catch2 3 REQUIRED)

add_executable(tests ./tests/test.cpp)
target_link_libraries(tests Catch2::Catch2WithMain GAME_ENGINE)

include(CTest)
include(Catch)
catch_discover_tests(tests)
