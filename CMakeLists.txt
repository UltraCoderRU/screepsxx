cmake_minimum_required(VERSION 3.16)

project(screepsxx CXX)

option(SCREEPSXX_ENABLE_PCH ON "Enable precompiled headers")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1 -s DEMANGLE_SUPPORT=1 -s ASSERTIONS=1 --cache ${CMAKE_BINARY_DIR}/cache")

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
