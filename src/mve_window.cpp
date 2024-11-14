#include "mve_window.hpp"

#include <stdexcept>

namespace mve {
    // Member Initialization 
    MveWindow::MveWindow(int w, int h, std::string name) : width { w }, height{ h }, window_name{ name } {

        initWindow();
    }

    MveWindow::~MveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate(); // Free resources used by glfw 
    }

    void MveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Disable EGL functionality
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Disable resizing so Vulkan can handle

        window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    }

    void MveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create window surface");
        }
    }

}