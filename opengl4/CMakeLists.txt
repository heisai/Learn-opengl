
cmake_minimum_required (VERSION 3.8)

project (opengl4)

set(CMAKE_CXX_STANDARD 17)
#设置库路径
set(LIBDIR  ./OpenGl/glfw/lib)
#设置头文件路径
set(INCLUDEDIR  ./OpenGl/glad/include  ./OpenGl/glfw/include)
# 加载库路径
link_directories(${LIBDIR})
# 加载头文件路径
include_directories(${INCLUDEDIR})


# 添加 .cpp
file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# 添加 .h
file(GLOB_RECURSE HEADER_FILES  ${CMAKE_SOURCE_DIR}/src/*.h)
# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME}  "main.cpp" ${HEADER_FILES} ${SOURCE_FILES})

# 编译glad 库
add_library(GLAD "src/glad.c")
set(LIBS glfw3 opengl32 GLAD)
# 链接 可执行文件 所需库
target_link_libraries(${PROJECT_NAME} ${LIBS})

 