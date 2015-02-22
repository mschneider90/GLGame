#include "engine/graphics/graphics.hpp"

// OpenGL headers live here
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <utility> // std::pair
#include <string>

Graphics::Graphics() : window(nullptr)
{
    int ret = glfwInit();
    if (!ret) {
        throw std::runtime_error("OpenGL initialization failed");
    }
}

Graphics::~Graphics()
{
    glfwTerminate();
}

void Graphics::openWindow(const std::string& title, const std::pair<int, int>& resolution)
{
    if (!window) {
        const GLFWmonitor* monitor = nullptr;
        const GLFWwindow* share = nullptr;
        window = glfwCreateWindow(resolution.first, resolution.second, title.c_str(), nullptr, nullptr);
        if (window) {
            glfwMakeContextCurrent(window);
            return;
        }
    }

    // Either window was already open or failed to create one
    throw std::runtime_error("Window initialized failed");
}

void Graphics::closeWindow()
{
    glfwDestroyWindow(window);
    window = nullptr;
}
