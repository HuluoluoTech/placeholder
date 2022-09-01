cmake_minimum_required (VERSION 3.24)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif ()

set(PROJECTNAME test)
project(${PROJECTNAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb -frrti-no")

message(STATUS "${PROJECT_SOURCE_DIR}/")

link_directories(
	${PROJECT_SOURCE_DIR}/../my_build/lib/
	${PROJECT_SOURCE_DIR}/../libs/>
)

aux_source_directory(. DIR_MAIN_SRCS)
add_executable(${PROJECTNAME} ${DIR_MAIN_SRCS})

# include header path
target_include_directories(${PROJECTNAME} PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/../src/>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/../.vendor/spdlog/include> #spdlog
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/../.vendor/imgui/> #spdlog
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/../libs/> #spdlog
)

# Link libs

target_link_libraries(${PROJECTNAME} -lplaceholder)
target_link_libraries(${PROJECTNAME} ${CMAKE_DL_LIBS})

target_link_libraries(${PROJECTNAME} -lshaderc)
target_link_libraries(${PROJECTNAME} -lglslang)
target_link_libraries(${PROJECTNAME} -lglslc)
target_link_libraries(${PROJECTNAME} -lHLSL)
target_link_libraries(${PROJECTNAME} -lshaderc_util)
target_link_libraries(${PROJECTNAME} -lSPIRV)
target_link_libraries(${PROJECTNAME} -lSPIRV-Tools)
target_link_libraries(${PROJECTNAME} -lSPIRV-Tools-opt)
target_link_libraries(${PROJECTNAME} 
-lspirv-cross-cpp
-lspirv-cross-core 
-lspirv-cross-glsl
-lspirv-cross-hlsl
-lspirv-cross-msl
-lspirv-cross-reflect
-lspirv-cross-util)