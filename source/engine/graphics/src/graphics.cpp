#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/gl.hpp"

#include <stdexcept>
#include <string>

GLEngine::Graphics::Graphics(const std::string& title,
                             const Resolution& res) : window(nullptr)
{
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit()) {
        throw std::runtime_error("graphics: glfw initialization failed");
    }
    
    // Use OpenGL 3.2 for now
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

void GLEngine::Graphics::clearFrameBuffer()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

std::string GLEngine::Graphics::getRendererName()
{
    return reinterpret_cast<const char*>(glGetString(GL_RENDERER));
}

std::string GLEngine::Graphics::getOpenGLVersion()
{
    return reinterpret_cast<const char*>(glGetString(GL_VERSION));
}

void glfwErrorCallback(int error, const char* msg) 
{
    GLEngine::Logger::logMessage(msg);
}

