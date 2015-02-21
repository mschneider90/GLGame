#include "engine/graphics/graphics.hpp"

// OpenGL headers live here
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

Graphics::Graphics()
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
