#include "engine/graphics/window.hpp"
#include "engine/input/input.hpp"

#include <GLFW/glfw3.h>
#include <stdexcept>

Window::Window(const std::string& title, const Resolution& res) : window(nullptr), input(nullptr)
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

Window::~Window()
{
    glfwDestroyWindow(window);
    window = nullptr;

    if (input) {
        delete input;
    }
}

Input* Window::getInputInstance() 
{
    if (!input) {
        input = new Input(window);
    }
    
    return input;
}

GLFWwindow* Window::getGLFWwindow() {
    return window;
}

