cmake_minimum_required(VERSION 3.16)

project(example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s STRICT=0 -s ASSERTIONS=0 -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT=shell -s MALLOC=emmalloc --cache ${CMAKE_BINARY_DIR}/cache")

add_subdirectory(screepsxx)

# If you change TARGET_NAME, please, make corresponding changes in main.js.
set(TARGET_NAME app)

add_executable(${TARGET_NAME} loop.cpp)
target_link_libraries(${TARGET_NAME} screepsxx)
target_link_options(${TARGET_NAME} PUBLIC -sMODULARIZE=1 --no-entry --bind)

# Collect all artifacts in 'dist' directory
# WASM-module and corresponding JS-module must have different base names in order to use them in Screeps, so we add suffixes.
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${TARGET_NAME}.wasm ${CMAKE_SOURCE_DIR}/dist/${TARGET_NAME}_module.wasm)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${TARGET_NAME}.js ${CMAKE_SOURCE_DIR}/dist/${TARGET_NAME}_loader.js)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/js/main.js ${CMAKE_SOURCE_DIR}/dist/main.js)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/js/wasm_loader.js ${CMAKE_SOURCE_DIR}/dist/wasm_loader.js)

# Following post-build step will automatically upload artifacts to
# official Screeps server. If you want to use it, please,
# set SCREEPS_TOKEN environment variable to your Screeps API token
# (https://docs.screeps.com/auth-tokens.html).
# If you don't want to use this script, please, remove following lines.
find_package(Python COMPONENTS Interpreter REQUIRED)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${Python_EXECUTABLE} ${screepsxx_SOURCE_DIR}/tools/upload.py ${CMAKE_SOURCE_DIR}/dist $ENV{SCREEPS_TOKEN})
