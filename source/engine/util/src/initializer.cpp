#include "engine/util/initializer.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

bool Initializer::init = false;

Initializer::Initializer()
{
    // Make sure to check that init is false to prevent double initialization (even though I don't think
    // GLFW would mind, if you're double initializing you're probably being retarded)
    if (init) {
        throw std::runtime_error("initializer: glfw already initialized");
    }
    if (!glfwInit()) {
        throw std::runtime_error("initializer: glfw initialization failed");
    }
    init = true;
}

Initializer::~Initializer()
{
    if (init) {
        glfwTerminate();
    }
}

bool Initializer::isInit()
{
    return init;
}


