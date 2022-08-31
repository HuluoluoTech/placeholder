cmake_minimum_required (VERSION 3.24)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif ()

set(PROJECTNAME test)
project(${PROJECTNAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb -frrti-no")

# message(STATUS ${PROJECT_SOURCE_DIR})
# message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${PROJECT_SOURCE_DIR}/../my_build/lib/)

link_directories(
	${PROJECT_SOURCE_DIR}/../my_build/lib/
)

aux_source_directory(. DIR_MAIN_SRCS)
add_executable(${PROJECTNAME} ${DIR_MAIN_SRCS})

# include header path
target_include_directories(${PROJECTNAME} PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/../src/>
)

# Link libs
target_link_libraries(${PROJECTNAME} -lpthread)
target_link_libraries(${PROJECTNAME} -ldl)
target_link_libraries(${PROJECTNAME} -lGL)
target_link_libraries(${PROJECTNAME} -lplaceholder)