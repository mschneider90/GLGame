#include "engine/util/resolution.hpp"

#include <string>

class GLFWwindow;
class Input;

class Window
{
public:
    Input* getInputInstance();
private:
    // Window creation should happen only from Graphics
    friend class Graphics;

    Window(const std::string& title, const Resolution& res);
    ~Window();
    
    GLFWwindow* getGLFWwindow();
    GLFWwindow* window;

    Input* input;
};
