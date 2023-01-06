> **Important!** I do not plan to continue development of this project. Feel free to create a fork.

# screepsxx

**screepsxx** is a C++ library for [Screeps](https://screeps.com) API.
It provides wrappers for the majority of classes in [Screeps API](https://docs.screeps.com/api).

## Requirements
* [Emscripten](https://emscripten.org) toolchain
* [CMake](https://cmake.org) 3.16+
* [Ninja](https://ninja-build.org) build system
* (Optional) Python 3 interpreter for artifacts uploading

## Using library in CMake project
1. Copy all files from `example` directory into your project directory.
2. Place library sources somewhere inside your project directory.
If you use git, the recommended way is to add library repository as a submodule.
Or instead you can manually download and extract library files somewhere inside your project.
```shell
cd <your_project_repo>
git submodule add https://github.com/UltraCoderRU/screepsxx.git
```

3. Check top-level `CMakeLists.txt`.
   You can disable automatic artifacts uploading, etc.
4. Configure project. You need to pass location of Emscripten SDK to CMake command.
   Also, always use Release build type! Debug version will not help you to debug WebAssembly code, but its size most probably will exceed 5MB limit of official Screeps server.
```shell
mkdir build
cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=<path_to_emsdk>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake ..
```

5. Build project, collect and upload artifacts.
```shell
cmake --build .
```
