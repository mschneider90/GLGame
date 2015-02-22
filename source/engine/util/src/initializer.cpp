#include "engine/util/initializer.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

bool Initializer::init = false;

Initializer::Initializer()
{
    if (init || !glfwInit()) {
        throw std::runtime_error("initializer: glfw initialization failed");
    }
    init = true;
}

Initializer::~Initializer()
{
    glfwTerminate();
}

bool Initializer::isInit()
{
    return init;
}


