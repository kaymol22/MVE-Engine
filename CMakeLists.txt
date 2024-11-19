cmake_minimum_required(VERSION 3.24)

# Update the project name
project(mve_engine)

# Include conan toolchain
include("${CMAKE_BINARY_DIR}/Release/generators/conan_toolchain.cmake")
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/Release/generators")

find_package(Vulkan REQUIRED)
find_package(VulkanHeaders REQUIRED)
find_package(VulkanLoader REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# Collect all .cpp files in the "src" directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create executable 
add_executable(mve_engine ${SOURCES})

# Link libraries to executable
target_link_libraries(mve_engine 
    PRIVATE 
    glfw 
    vulkan-headers::vulkan-headers 
    Vulkan::Loader 
    glm::glm)

target_include_directories(mve_engine PRIVATE "${CMAKE_SOURCE_DIR}/headers")
