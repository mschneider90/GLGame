#include "engine/graphics/window.hpp"
#include "engine/input/input.hpp"

#include "engine/util/gl.hpp"
#include <stdexcept>

GLEngine::Window::Window(const std::string& title,
                         const GLEngine::Resolution& res) : m_window(nullptr), m_input(nullptr)
{
    GLFWmonitor* const monitor = nullptr;
    GLFWwindow* const share = nullptr;
    m_window = glfwCreateWindow(res.x, res.y, title.c_str(), monitor, share);
    if (m_window) {
        glfwMakeContextCurrent(m_window);
        return;
    }

    // failed to create window
    throw std::runtime_error("graphics: Window initialized failed");
}

GLEngine::Window::~Window()
{
    glfwDestroyWindow(m_window);
    m_window = nullptr;
}

GLEngine::Input& GLEngine::Window::getInputInstance() 
{
    if (!m_input) {
        m_input = std::unique_ptr<GLEngine::Input>(new GLEngine::Input(m_window));
    }
    
    return *m_input;
}

GLFWwindow* GLEngine::Window::getGLFWwindow() {
    return m_window;
}

