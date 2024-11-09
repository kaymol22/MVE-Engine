cmake_minimum_required(VERSION 3.10)

project(LVE_Renderer)

set(CMAKE_CXXSTANDARD 17)

#Local paths for Vulkan, GLFW, GLM
set(VULKAN_INCLUDE_DIR "$ENV{VULKAN}/include")
set(VULKAN_LIBRARY "$ENV{VULKAN}/Lib/vulkan-1.lib")

set(GLFW_INCLUDE_DIR "$ENV{GLFW_INCLUDE}")
set(GLFW_LIBRARY "$ENV{GLFW_LIB22}/glfw3.lib")

#Include directories
include_directories(${VULKAN_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} headers)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(LVE_Renderer ${SOURCES})

target_link_libraries(LVE_Renderer ${VULKAN_LIBRARY} ${GLFW_LIBRARY})