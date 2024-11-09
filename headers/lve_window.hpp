#pragma once

#define GLFW_INCLUDE_VULKAN // include glfw vulkan headers
#include <GLFW/glfw3.h> // windowing tool

#include <string>

namespace lve 
{
    class LveWindow {
    public:
        LveWindow(int w, int h, std::string name);
        ~LveWindow();
        bool shouldClose() { return glfwWindowShouldClose(window); }
    private:
        void initWindow();

        int width, height;
        std::string window_name;

        GLFWwindow *window;
    };
}