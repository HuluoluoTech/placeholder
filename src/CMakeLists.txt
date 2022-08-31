cmake_minimum_required (VERSION 3.24)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif ()

if(NOT DEFINED CMAKE_CXX_STANDARD OR CMAKE_CXX_STANDARD LESS 11)
	message(FATAL_ERROR "ERROR: CMAKE_CXX_STANDARD is not set or it is too low. Minimum C++ v11 is required to compile \"DLib\" library.")
endif()

# only linux support
message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	message(FATAL_ERROR "Placeholder only support Linux!")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb -frrti-no")

# message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(./placeholder DIR_MAIN_SRCS)
add_library(placeholder SHARED ${DIR_MAIN_SRCS})

# include header path
target_include_directories(${PROJECTNAME} PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/configuration/>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/>
)

# Link libs
target_link_libraries(${PROJECTNAME} -lglfw)
target_link_libraries(${PROJECTNAME} -lpthread)
target_link_libraries(${PROJECTNAME} -ldl)
target_link_libraries(${PROJECTNAME} -lGL)

###########################################################################
#
# import vendor
#
###########################################################################
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(spdlog)	# 填写文件名

target_link_libraries(${PROJECTNAME} PRIVATE spdlog::spdlog)
