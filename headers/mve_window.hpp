#pragma once

#define GLFW_INCLUDE_VULKAN // include glfw vulkan headers
#include <GLFW/glfw3.h> // windowing tool

#include <string>

namespace mve 
{
    class MveWindow {
    public:
        MveWindow(int w, int h, std::string name);
        ~MveWindow();
        bool shouldClose() { return glfwWindowShouldClose(window); }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    private:
        void initWindow();

        int width, height;
        std::string window_name;

        GLFWwindow *window;
    };
}