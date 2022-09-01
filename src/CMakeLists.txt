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

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb -frrti-no")
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

set(DLLNAME placeholder)

file(GLOB DIR_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/events/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/core/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/renderer/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/scene/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/gui/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/utils/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/math/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/placeholder/opengl/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../libs/stb_image/*.cpp
)


file(GLOB DEP_IMGUI_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/../.vendor/imgui/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/../.vendor/imgui/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../.vendor/imgui/backends/imgui_impl_glfw.*
	${CMAKE_CURRENT_SOURCE_DIR}/../.vendor/imgui/backends/imgui_impl_opengl3.*
)

link_directories(
	${PROJECT_SOURCE_DIR}/my_build/lib/
)

# aux_source_directory(./placeholder DIR_MAIN_SRCS)
# add_library(${DLLNAME} SHARED ${DIR_MAIN_SRCS})
# add_library(${DLLNAME} STATIC ${DIR_MAIN_SRCS} ${DIR_SRCS})
# add_library(${DLLNAME} STATIC ${DIR_SRCS})
add_library(${DLLNAME} SHARED ${DIR_SRCS} ${DEP_IMGUI_SRCS})

# include header path
target_include_directories(${DLLNAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/libs/>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/libs/glad/include/>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/.vendor/imgui/>
)

# Link libs

target_link_libraries(${DLLNAME} -lglfw)
target_link_libraries(${DLLNAME} -lGLU)
target_link_libraries(${DLLNAME} -lGL)
target_link_libraries(${DLLNAME} -lXcursor)

target_link_libraries(${DLLNAME} ${CMAKE_DL_LIBS})
target_link_libraries(${DLLNAME} -lm)
target_link_libraries(${DLLNAME} -ldl)

###########################################################################
#
# import vendor
#
###########################################################################
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(spdlog)
target_link_libraries(${DLLNAME} spdlog::spdlog)

include(shaderc)
target_link_libraries(${DLLNAME} shaderc)
target_link_libraries(${DLLNAME} glslang)
target_link_libraries(${DLLNAME} glslc)
target_link_libraries(${DLLNAME} HLSL)
target_link_libraries(${DLLNAME} shaderc_util)
target_link_libraries(${DLLNAME} SPIRV)
target_link_libraries(${DLLNAME} SPIRV-Tools)
target_link_libraries(${DLLNAME} SPIRV-Tools-opt)
target_link_libraries(${DLLNAME} SPIRV-Tools-link)

target_link_libraries(${DLLNAME} -lspirv-cross-cpp)
target_link_libraries(${DLLNAME} -lspirv-cross-core 
-lspirv-cross-glsl
-lspirv-cross-hlsl
-lspirv-cross-msl
-lspirv-cross-reflect
-lspirv-cross-util)



# include(imgui)
# target_link_libraries(${DLLNAME} imgui)