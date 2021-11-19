cmake_minimum_required(VERSION 3.11)

project(OpenGL_CMake VERSION 0.1)

# Dependancy Variables
set(EXTERN_GLFW extern/glfw)
set(EXTERN_GLAD extern/glad)

# Build GLAD
find_package(OpenGL REQUIRED)
add_subdirectory(${EXTERN_GLAD})
set(DEPEND ${DEPEND} glad OpenGL::GL)

# Build GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${EXTERN_GLFW})
set(DEPEND ${DEPEND} glfw)

# Build OpenGL_CMake
set(SOURCE
    src/gfx/shader.cpp
    src/gfx/material.cpp
    src/gfx/window.cpp
	
	src/main.cpp)

add_executable(OpenGL_CMake ${SOURCE})

target_include_directories(OpenGL_CMake PUBLIC src/)
target_link_libraries(OpenGL_CMake PUBLIC ${DEPEND})