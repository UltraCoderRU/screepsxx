cmake_minimum_required(VERSION 3.16)

project(screepsxx CXX)

option(SCREEPSXX_ENABLE_PCH "Enable precompiled headers" ON)
option(SCREEPSXX_BUILD_EXAMPLE "Build example WASM application" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s STRICT=0 -s ALLOW_MEMORY_GROWTH=1")

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(screepsxx STATIC ${SOURCES})
target_include_directories(screepsxx
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Screeps
)

if (SCREEPSXX_ENABLE_PCH)
	target_precompile_headers(screepsxx PRIVATE
		<map>
		<memory>
		<optional>
		<string>
		<vector>
		<emscripten/val.h>
	)
endif()

if (SCREEPSXX_BUILD_EXAMPLE)
	add_subdirectory(example)
endif()
