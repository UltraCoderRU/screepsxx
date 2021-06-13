set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ENVIRONMENT=shell")

add_executable(example loop.cpp)
target_link_libraries(example screepsxx)
target_link_options(example PUBLIC -sMODULARIZE=1 --no-entry --bind)

# Collect all artifacts in 'dist' directory
add_custom_command(TARGET example POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/example.wasm ${CMAKE_CURRENT_SOURCE_DIR}/dist/my_module.wasm)
add_custom_command(TARGET example POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/example.js ${CMAKE_CURRENT_SOURCE_DIR}/dist/my_loader.js)
add_custom_command(TARGET example POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/js/main.js ${CMAKE_CURRENT_SOURCE_DIR}/dist/main.js)
add_custom_command(TARGET example POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/js/wasm_loader.js ${CMAKE_CURRENT_SOURCE_DIR}/dist/wasm_loader.js)

# You can add post-build step to automatically upload artifacts to
# official Screeps server using Python script in 'tools' directory.
# To do so, uncomment following lines and set SCREEPS_TOKEN environment
# variable to your Screeps API token (https://docs.screeps.com/auth-tokens.html).
#
#find_package(Python COMPONENTS Interpreter REQUIRED)
#add_custom_command(TARGET example POST_BUILD COMMAND ${Python_EXECUTABLE} ${screepsxx_SOURCE_DIR}/tools/upload.py ${CMAKE_CURRENT_SOURCE_DIR}/dist $ENV{SCREEPS_TOKEN})
