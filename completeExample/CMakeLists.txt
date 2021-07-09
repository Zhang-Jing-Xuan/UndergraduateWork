cmake_minimum_required(VERSION 3.0.0)

project(main)
SET(CMAKE_CXX_COMPILER_ENV_VAR "CXX")
SET(CMAKE_CXX_FLAGS "-std=c++11")
include_directories(include build src)

# bison and flex
find_package(BISON)
find_package(FLEX)
flex_target(SCANNER src/lex.l  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
bison_target(PARSER src/yacc.y  ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

# src files and make exe
file(GLOB_RECURSE source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(main
    ${source_files}
    ${BISON_PARSER_OUTPUTS}
    ${FLEX_SCANNER_OUTPUTS})