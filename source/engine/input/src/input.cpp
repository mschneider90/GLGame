#include "engine/input/input.hpp"
#include "engine/input/keys.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/glfw.hpp"

#include <stdexcept>

Input::Input(GLFWwindow* win) : window(win)
{
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
}

Input::~Input()
{

}

void Input::pollEvents()
{
    glfwPollEvents();
}

bool Input::isKeyPressed(Key k)
{
    // Special case - ESC also checks if the window wants to be closed
    if (k == Key::ESC) {
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

