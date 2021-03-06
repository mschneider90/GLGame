#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/graphics/shaderman.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/gl.hpp"

#include <stdexcept>
#include <string>

using GLEngine::Graphics;
using GLEngine::Resolution;
using GLEngine::Window;
using GLEngine::ShaderProgram;
using GLEngine::Mesh;
using GLEngine::ShaderManager;

Graphics::Graphics(std::shared_ptr<Logger> logger, 
                             const std::string& windowTitle,
                             const Resolution& windowRes,
                             int windowSamples) : m_logger(logger)
{
    logger->logMessage("Initializing openGL...");
    
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
    m_window = std::shared_ptr<Window>(new Window(m_logger, windowTitle, windowRes));

    // GLEW handles openGL extensions
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("graphics: glew initialization failed");
    }
    
    // set antialiasing
    glfwWindowHint(GLFW_SAMPLES, windowSamples);
    
    logger->logMessage("OpenGL initialization OK");
    logger->logMessage(getRendererName(), false);
    logger->logMessage(getOpenGLVersion(), false);
}

Graphics::~Graphics()
{
    m_shaderMan.reset();
    if (!m_window.unique()) {
        m_logger->logMessage("graphics: window should not be kept alive past graphics, destroying now");
    }
    m_window.reset();
    glfwTerminate();
}

std::shared_ptr<Window> Graphics::getWindowInstance() const
{
    return m_window;
}

std::unique_ptr<ShaderProgram> 
Graphics::makeShaderProgram(const std::string& vsPath,
                                      const std::string& fsPath)
{
    if (!m_shaderMan) {         
        m_shaderMan = std::unique_ptr<ShaderManager>(new ShaderManager(m_logger));
    }
    return m_shaderMan->makeShaderProgram(vsPath, fsPath);
}

std::unique_ptr<Mesh>
Graphics::makeMesh(const std::vector<Vec3>& vertices)
{
    return std::unique_ptr<Mesh>(new Mesh(m_logger, vertices));
}

void Graphics::draw(const Mesh& mesh, const ShaderProgram& prog)
{
    glUseProgram(prog.getProgramIndex());
    glBindVertexArray(mesh.getAttributeIndex());
    glDrawArrays(GL_TRIANGLES, 0, mesh.getNumVertices());
}

void Graphics::swapFrameBuffer()
{
    glfwSwapBuffers(m_window->getGLFWwindow());
}

void Graphics::clearFrameBuffer()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

std::string Graphics::getRendererName() const
{
    return reinterpret_cast<const char*>(glGetString(GL_RENDERER));
}

std::string Graphics::getOpenGLVersion() const
{
    return reinterpret_cast<const char*>(glGetString(GL_VERSION));
}

#include "engine/engine.hpp"
using GLEngine::Engine;
void glfwErrorCallback(int error, const char* msg) 
{
    // have to access logger globally from here pls dont do this
    Engine::getEngineInstance()->getLoggerInstance()->logMessage(msg);
}

