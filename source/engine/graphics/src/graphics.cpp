#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/graphics/shaderman.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/gl.hpp"

#include <stdexcept>
#include <string>

GLEngine::Graphics::Graphics(const std::string& windowTitle, const Resolution& windowRes, int windowSamples)
{
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit()) {
        throw std::runtime_error("graphics: glfw initialization failed");
    }
    
    // Use OpenGL 3.2 for now
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // OpenGL context is alive after this call
    m_window = std::unique_ptr<GLEngine::Window>(new GLEngine::Window(windowTitle, windowRes));

    // GLEW handles openGL extensions
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("graphics: glew initialization failed");
    }
    
    // 4x antialiasing
    glfwWindowHint(GLFW_SAMPLES, windowSamples);
    
    m_shaderMan = std::unique_ptr<GLEngine::ShaderManager>(new GLEngine::ShaderManager());
}

GLEngine::Graphics::~Graphics()
{
    m_shaderMan.reset();
    m_window.reset();
    glfwTerminate();
}

GLEngine::Window& GLEngine::Graphics::getWindowInstance()
{
    return *m_window;
}

std::unique_ptr<GLEngine::ShaderProgram> 
GLEngine::Graphics::makeShaderProgram(const std::string& vsPath,
                                      const std::string& fsPath)
{
    return m_shaderMan->makeShaderProgram(vsPath, fsPath);
}

void GLEngine::Graphics::draw(const GLEngine::Mesh& mesh, const GLEngine::ShaderProgram& prog)
{
    glUseProgram(prog.getProgramIndex());
    glBindVertexArray(mesh.getAttributeIndex());
    glDrawArrays(GL_TRIANGLES, 0, mesh.getNumVertices());
}

void GLEngine::Graphics::swapFrameBuffer()
{
    glfwSwapBuffers(m_window->getGLFWwindow());
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

