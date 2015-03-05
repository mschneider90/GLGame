#include "engine/graphics/window.hpp"
#include "engine/util/logger.hpp"
#include "engine/input/input.hpp"

#include "engine/util/gl.hpp"
#include <stdexcept>

using GLEngine::Window;
using GLEngine::Resolution;
using GLEngine::Input;

Window::Window(std::shared_ptr<Logger> logger,
                         const std::string& title,
                         const Resolution& res) : m_logger(logger), m_window(nullptr), m_input(nullptr)
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

Window::~Window()
{
    if (!m_input.unique()) {
        m_logger->logMessage("graphics: Input should not be alive after window destruction, deleting now");
    }
    m_input.reset();
    glfwDestroyWindow(m_window);
    m_window = nullptr;
}

std::shared_ptr<Input> Window::getInputInstance() 
{
    if (!m_input) {
        m_input = std::shared_ptr<Input>(new Input(m_window));
    }
    
    return m_input;
}

GLFWwindow* Window::getGLFWwindow() {
    return m_window;
}

