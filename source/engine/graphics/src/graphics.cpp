#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/resolution.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>

GLEngine::Graphics::Graphics(const std::string& title,
                             const Resolution& res) : window(nullptr)
{
    if (!glfwInit()) {
        throw std::runtime_error("graphics: glfw initialization failed");
    }

    // OpenGL context is alive after this call
    window = new Window(title, res);

    // GLEW handles openGL extensions
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("graphics: glew initialization failed");
    }

    // Depth testing only draws a pixel if it's visible
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

GLEngine::Graphics::~Graphics()
{
    delete window;
    glfwTerminate();
}

GLEngine::Window* GLEngine::Graphics::getWindowInstance()
{
    return window;
}

void GLEngine::Graphics::swapFrameBuffer()
{
    glfwSwapBuffers(window->getGLFWwindow());
}

std::string GLEngine::Graphics::getRendererName()
{
    return reinterpret_cast<const char*>(glGetString(GL_RENDERER));
}

std::string GLEngine::Graphics::getOpenGLVersion()
{
    return reinterpret_cast<const char*>(glGetString(GL_VERSION));
}

