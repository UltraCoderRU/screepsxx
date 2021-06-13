# screepsxx

**screepsxx** is a C++ library for [Screeps](https://screeps.com) API.
It provides wrappers for the majority of classes in [Screeps API](https://docs.screeps.com/api).

## Requirements
* [Emscripten](https://emscripten.org) toolchain
* [CMake](https://cmake.org) 3.16+
* [Ninja](https://ninja-build.org) build system
* (Optional) Python 3 interpreter for artifacts uploading

## Building
```shell
git clone https://github.com/UltraCoderRU/screepsxx.git
cd screepsxx
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=<path_to_emsdk>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
# Add -DSCREEPSXX_BUILD_EXAMPLE=ON to build example application (see 'example' directory)
```

## Using library in CMake project
The simplest way to use screepsxx library is to add it to your project with `add_subdirectory()`:
```cmake
cmake_minimum_required(VERSION 3.16)

project(MyProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s STRICT=0 -s ASSERTIONS=0 -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT=shell -s MALLOC=emmalloc --cache ${CMAKE_BINARY_DIR}/cache")

add_subdirectory(screepsxx)

add_executable(myapp loop.cpp)
target_link_libraries(myapp screepsxx)
target_link_options(myapp PUBLIC -sMODULARIZE=1 --no-entry --bind)
```

Compiled WASM-module (`myapp.wasm`) and corresponding JavaScript module (`myapp.js`) will appear in your build directory (`CMAKE_BINARY_DIR`).
To use them inside Screeps, you need two additional JavaScript modules located in `js` directory.
Put all four files into one directory and upload them to Screeps server.
You can use Python script `tools\upload.py`, see `example/CMakeLists.txt` for details.
