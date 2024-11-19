cmake_minimum_required(VERSION 3.31)

# Update project name
project(mve_engine)

# Include conan toolchain
include("${CMAKE_BINARY_DIR}/Release/generators/conan_toolchain.cmake")
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/Release/generators")

set(VULKAN_SDK_PATH "C:/Program Files/Vulkan")
set(VULKAN_VAL_LAYERS_PATH "${VULKAN_SDK_PATH}/Bin")
set(VULKAN_LAYERS_LIB_PATH "${VULKAN_SDK_PATH}/Bin")

include_directories(
    ${VULKAN_SDK_PATH}/Include
)
link_directories(
    ${VULKAN_LAYER_LIB_PATH}
)

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
    glm::glm
    "${VULKAN_SDK_PATH}/Lib/vulkan-1.lib"
)

target_compile_definitions(mve_engine PRIVATE
    VULKAN_LAYER_PATH=\"${VULKAN_VAL_LAYERS_PATH}/VkLayer_khronos_validation.json\"
)

target_include_directories(mve_engine PRIVATE 
    ${VULKAN_SDK_PATH}/Include
    "${CMAKE_SOURCE_DIR}/headers")

