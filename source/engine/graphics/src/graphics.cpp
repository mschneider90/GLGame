#include "engine/graphics/graphics.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/glfw.hpp"

#include <stdexcept>
#include <string>

Graphics::Graphics(const std::string& title,
                   const Resolution& res) : window(nullptr)
{
    if (!glfwInit()) {
        throw std::runtime_error("graphics: glfw initialization failed");
    }

    // GLEW handles openGL extensions
    glewExperimental = GL_TRUE;
    if (!glewInit()) {
        throw std::runtime_error("graphics: glew initialization failed");
    }

    window = new Window(title, res);
}

Graphics::~Graphics()
{
    delete window;
    glfwTerminate();
}

Window* Graphics::getWindowInstance()
{
    return window;
}

void Graphics::swapFrameBuffer()
{
    glfwSwapBuffers(window->getGLFWwindow());
}

std::string Graphics::getRendererName()
{
    return reinterpret_cast<const char*>(glGetString(GL_RENDERER));
}

std::string Graphics::getOpenGLVersion()
{
    return reinterpret_cast<const char*>(glGetString(GL_VERSION));
}

