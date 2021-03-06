#ifndef GLENGINE_WINDOW_HPP
#define GLENGINE_WINDOW_HPP

#include "engine/util/resolution.hpp"
#include "engine/input/input.hpp"

#include <string>
#include <memory>

class GLFWwindow;

namespace GLEngine 
{

class Input;
class Logger;

/*! @brief Represents the program window on the screen
 *
 *  Input is per-window so that's why an Input instance is obtained from here
 */
class Window
{
public:
    /*! @brief Get an instance to the Input for this Window
     *
     *  @return A pointer to the Input instance.
     */
    std::shared_ptr<Input> getInputInstance();
    
    /*! @brief Destroy the Window
     */
    ~Window();
private:
    // Window creation should happen only from Graphics
    friend class Graphics;
    
    Window(const Window& w) = delete;
    Window& operator=(const Window& w) = delete;

    Window(std::shared_ptr<Logger> logger, const std::string& title, const Resolution& res);
    
    GLFWwindow* getGLFWwindow() const;
    GLFWwindow* m_window;

    std::shared_ptr<Input> m_input;
    std::shared_ptr<Logger> m_logger;
};

}

#endif
