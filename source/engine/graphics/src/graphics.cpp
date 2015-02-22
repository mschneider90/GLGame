#include "engine/graphics/graphics.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/initializer.hpp"

// OpenGL headers live here
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <utility> // std::pair
#include <string>

Graphics::Graphics() : window(nullptr)
{
    if (!Initializer::isInit()) {
        throw std::runtime_error("graphics: Engine not initialized");
    }
}

Graphics::~Graphics()
{
}

void Graphics::openWindow(const std::string& title, const Resolution& res)
{
    if (!window) {
        const GLFWmonitor* monitor = nullptr;
        const GLFWwindow* share = nullptr;
        window = glfwCreateWindow(res.x, res.y, title.c_str(), nullptr, nullptr);
        if (window) {
            glfwMakeContextCurrent(window);
            return;
        }
    }

    // Either window was already open or failed to create one
    throw std::runtime_error("graphics: Window initialized failed");
}

void Graphics::closeWindow()
{
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
        return;
    }

    // Window wasn't open in the first place
    throw std::runtime_error("graphics: Window destruction failed");
}
