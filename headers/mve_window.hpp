#pragma once

#include "vulkan/vulkan_core.h"
#define GLFW_INCLUDE_VULKAN // include glfw vulkan headers
#include <GLFW/glfw3.h> // windowing tool

#include <string>

namespace mve 
{
    class MveWindow {
    public:
        MveWindow(int w, int h, std::string name);
        ~MveWindow();

        MveWindow(const MveWindow &) = delete;
        MveWindow &operator = (const MveWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }
        VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    private:
        void initWindow();

        int width, height;
        std::string window_name;

        GLFWwindow *window;
    };
}