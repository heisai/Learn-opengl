cmake_minimum_required(VERSION 3.23.1.0)
cmake_policy(SET CMP0091 OLD)
cmake_policy(SET CMP0126 OLD)
project(CMAKE_TRY_COMPILE C)
set_property(DIRECTORY PROPERTY INCLUDE_DIRECTORIES "")
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_C_FLAGS "/DWIN32 /D_WINDOWS /W3")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILE_DEFINITIONS}")
set(CMAKE_EXE_LINKER_FLAGS "/machine:x64")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${EXE_LINKER_FLAGS}")
include_directories(${INCLUDE_DIRECTORIES})
set(CMAKE_SUPPRESS_REGENERATION 1)
link_directories(${LINK_DIRECTORIES})
cmake_policy(SET CMP0065 NEW)
cmake_policy(SET CMP0083 OLD)
include("${CMAKE_ROOT}/Modules/Internal/HeaderpadWorkaround.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "E:/GLTest/Learn-opengl/opengl5/build/CMakeFiles/CMakeTmp")
add_executable(cmTC_a33cd "D:/TOOL/CMake/cmake-3.23.1-windows-x86_64/share/cmake-3.23/Modules/CMakeCCompilerABI.c")
target_link_libraries(cmTC_a33cd ${LINK_LIBRARIES})
