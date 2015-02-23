#include "engine/input/input.hpp"
#include "engine/util/initializer.hpp"

#include <stdexcept>

Input::Input(const Window* win) : currentWindow(w)
{
    glfwSetInputMode(currentWindow, GLFW_STICKY_KEYS, 1);
}

Input::~Input()
{

}

Input::isKeyPressed(Key k)
{
    // Special case - ESC also checks if the window wants to be closed
    if (k == Key::ESC) {
        if (glfwWindowShouldClose(currentWindow) {
            return true;
        }
    }

    int keyState = glfwGetKey(window, static_cast<int>(k));
    if (state == GLFW_PRESS) {
        return true;
    }

    return false;
}

const Window* Input::getCurrentWindow() {
    return currentWindow;
}

void Input::setCurrentWindow(const Window* win) {
    currentWindow = win;
    glfwSetInputMode(currentWindow->GetGLFWWindow(), GLFW_STICKY_KEYS, 1);
}
