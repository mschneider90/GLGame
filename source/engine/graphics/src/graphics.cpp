#include "engine/graphics/graphics.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/initializer.hpp"

// OpenGL headers live here
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <string>

Graphics::Graphics() : window(nullptr)
{
    if (!glfwInit()) {
        throw std::runtime_error("graphics: glfw initialization failed");
    }
}

Graphics::~Graphics()
{
    if (window) {
        delete window;
    }
    glfwTerminate();
}

Window* Graphics::getWindowInstance(const std::string& title, const Resolution& res)
{
    if (window) {
        throw std::runtime_error("graphics: Window instance already created");
    }

    window = new Window();
    window->open(title, res);
    return window;
}


