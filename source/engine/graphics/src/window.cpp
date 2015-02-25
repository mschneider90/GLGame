#include "engine/graphics/window.hpp"
#include "engine/input/input.hpp"
#include "engine/util/glfw.hpp"

#include <stdexcept>

Window::Window() : window(nullptr), input(nullptr)
{

}

Window::~Window()
{
    if (window) {
        close();
    }

    if (input) {
        delete input;
    }
}

void Window::open(const std::string& title, const Resolution& res)
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

void Window::close()
{
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
        return;
    }

    // Window wasn't open in the first place
    throw std::runtime_error("graphics: Window destruction failed");
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

