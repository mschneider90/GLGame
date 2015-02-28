#include "engine/input/input.hpp"
#include "engine/input/keys.hpp"
#include "engine/graphics/window.hpp"

#include <GLFW/glfw3.h>
#include <stdexcept>

GLEngine::Input::Input(GLFWwindow* win) : window(win)
{
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
}

GLEngine::Input::~Input()
{

}

void GLEngine::Input::pollEvents()
{
    glfwPollEvents();
}

bool GLEngine::Input::isKeyPressed(Key k)
{
    // Special case - ESC also checks if the window wants to be closed
    if (k == GLEngine::Key::ESC) {
        if (glfwWindowShouldClose(window)) {
            return true;
        }
    }

    int keyState = glfwGetKey(window, static_cast<int>(k));
    if (keyState == GLFW_PRESS) {
        return true;
    }

    return false;
}

