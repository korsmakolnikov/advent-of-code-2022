cmake_minimum_required(VERSION 3.15)
project(AdventDayThreePartOne)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DOMAIN ./src/domain/engine.hpp ./src/domain/rucksack.hpp
                   ./src/domain/rucksack.cpp ./src/domain/engine.cpp)

add_library(APP ./src/app/parser.hpp ./src/app/rucksack_parser.hpp
                ./src/app/rucksack_parser.cpp)
set_target_properties(APP PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME} ./src/main.cpp)
target_link_libraries(${PROJECT_NAME} DOMAIN APP)

find_package(Catch2 3 REQUIRED)

add_executable(tests ./tests/test.cpp ./tests/parser_test.cpp)
target_link_libraries(tests Catch2::Catch2WithMain DOMAIN APP)

include(CTest)
include(Catch)
catch_discover_tests(tests)
