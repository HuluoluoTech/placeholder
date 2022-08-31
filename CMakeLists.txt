cmake_minimum_required (VERSION 3.24)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif ()

set(PROJECTNAME placeholder)
project(${PROJECTNAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb -frrti-no")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file(configuration/Config.h.in src/placeholder/Config.h)

add_subdirectory(src)
