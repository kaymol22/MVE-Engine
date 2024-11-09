#include "lve_window.hpp"

namespace lve {
    // Member Initialization 
    LveWindow::LveWindow(int w, int h, std::string name) : width { w }, height{ h }, window_name{ name } {

        initWindow();
    }

    LveWindow::~LveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate(); // Free resources used by glfw 
    }

    void LveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Disable EGL functionality
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Disable resizing so Vulkan can handle

        window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    }
}