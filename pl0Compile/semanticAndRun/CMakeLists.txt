cmake_minimum_required(VERSION 3.0.0)

project(pl0)
SET(CMAKE_CXX_COMPILER_ENV_VAR "CXX")
SET(CMAKE_CXX_FLAGS "-std=c++11")
include_directories(build src)

# bison and flex
find_package(BISON)
find_package(FLEX)

if(BISON_FOUND)
    message ("bison found")
else()
    message ("Cannot find bison")
endif()

if(FLEX_FOUND)
    message ("flex found")
else()
    message ("Cannot find flex")
endif()

flex_target(SCANNER src/LexicalPl0.l  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
bison_target(PARSER src/SyntaxPl0.y  ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

# src files and make exe
file(GLOB_RECURSE source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(pl0
    ${source_files}
    ${BISON_PARSER_OUTPUTS}
    ${FLEX_SCANNER_OUTPUTS})