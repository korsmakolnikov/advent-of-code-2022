cmake_minimum_required(VERSION 3.15)
project(AdventDayTwoPartTwo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(GAME_ENGINE ./src/engine.hpp ./src/engine.cpp)

add_library(ADAPTER ./src/parser.hpp ./src/tuple_parser.hpp)
set_target_properties(ADAPTER PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME} ./src/main.cpp)
target_link_libraries(${PROJECT_NAME} GAME_ENGINE ADAPTER)

find_package(Catch2 3 REQUIRED)

add_executable(tests ./tests/test.cpp)
target_link_libraries(tests Catch2::Catch2WithMain GAME_ENGINE ADAPTER)

include(CTest)
include(Catch)
catch_discover_tests(tests)
