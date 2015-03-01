#include "engine/graphics/window.hpp"
#include "engine/input/input.hpp"

#include "engine/util/gl.hpp"
#include <stdexcept>

GLEngine::Window::Window(const std::string& title,
                         const GLEngine::Resolution& res) : window(nullptr), input(nullptr)
{
    const GLFWmonitor* monitor = nullptr;
    const GLFWwindow* share = nullptr;
    window = glfwCreateWindow(res.x, res.y, title.c_str(), nullptr, nullptr);
    if (window) {
        glfwMakeContextCurrent(window);
        return;
    }

    // failed to create window
    throw std::runtime_error("graphics: Window initialized failed");
}

GLEngine::Window::~Window()
{
    glfwDestroyWindow(window);
    window = nullptr;

    if (input) {
        delete input;
    }
}

GLEngine::Input* GLEngine::Window::getInputInstance() 
{
    if (!input) {
        input = new GLEngine::Input(window);
    }
    
    return input;
}

GLFWwindow* GLEngine::Window::getGLFWwindow() {
    return window;
}

