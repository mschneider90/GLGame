#include "engine/graphics/graphics.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/glfw.hpp"

#include <stdexcept>
#include <string>

Graphics::Graphics() : window(nullptr), isWindowOpen(false)
{
    if (!glfwInit()) {
        throw std::runtime_error("graphics: glfw initialization failed");
    }

    window = new Window();
}

Graphics::~Graphics()
{
    delete window;
    glfwTerminate();
}

Window* Graphics::getWindowInstance(const std::string& title, const Resolution& res)
{
    if (isWindowOpen) {
        throw std::runtime_error("graphics: Window instance already created");
    }

    window->open(title, res);
    isWindowOpen = true;
    return window;
}

void Graphics::swapFrameBuffer()
{
    if (!isWindowOpen) {
        throw std::runtime_error("graphics: Window must be open to swap framebuffer");
    }

    glfwSwapBuffers(window->getGLFWwindow());
}
