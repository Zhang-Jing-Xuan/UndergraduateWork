cmake_minimum_required(VERSION 3.0.0)
project(file VERSION 0.1.0)

include(CTest)
enable_testing()

SET(LIB_LIST Bitmap.cpp DictionaryTree.cpp 
FileSys.cpp File.cpp InodeTable.cpp User.cpp)

add_executable(file main.cpp ${LIB_LIST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
add_definitions(-std=c++11)