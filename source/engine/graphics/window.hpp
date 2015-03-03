#ifndef GLENGINE_WINDOW_HPP
#define GLENGINE_WINDOW_HPP

#include "engine/util/resolution.hpp"

#include <string>

class GLFWwindow;

namespace GLEngine 
{

class Input;

/*! @brief Represents the program window on the screen
 *
 *  Input is per-window so that's why an Input instance is obtained from here
 */
class Window
{
public:
    /*! @brief Get an instance to the Input for this Window
     *
     *  @return A pointer to the Input instance. Guaranteed to not be null.
     */
    Input* getInputInstance();
    
    /*! @brief Destroy the Window
     */
    ~Window();
private:
    // Window creation should happen only from Graphics
    friend class Graphics;

    Window(const std::string& title, const Resolution& res);
    
    GLFWwindow* getGLFWwindow();
    GLFWwindow* window;

    Input* input;
};

}

#endif
