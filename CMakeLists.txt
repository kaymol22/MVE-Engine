cmake_minimum_required(VERSION 3.24)

# Update project name
project(lve_engine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Explicit setting of linker flags
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")


# Paths to dependencies
set(VULKAN_SDK "$ENV{VULKAN}")
set(GLFW_DIR "$ENV{GLFW}")

# Include directories
include_directories(
    ${VULKAN_SDK}/Include 
    ${GLFW_DIR}/include 
    headers
)

set(VULKAN_LIB "$ENV{VULKAN}/Lib/vulkan-1.lib")
set(GLFW_LIB "C:/glfw/build/src/libglfw3.a")

message("GLFW_LIB path: ${GLFW_LIB}")

# Collect all .cpp files in the "src" directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create executable 
add_executable(lve_engine ${SOURCES})

# Link libraries to executable
target_link_libraries(lve_engine mingw32 ${VULKAN_LIB} ${GLFW_LIB} opengl32)

