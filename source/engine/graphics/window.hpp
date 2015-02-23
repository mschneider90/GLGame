#include "engine/util/resolution.hpp"

#include <string>

class GLFWwindow;
class Input;

class Window
{
public:
    Window();
    ~Window();
    
    void open(const std::string& title, const Resolution& res);
    void close();
private:
    friend class Graphics;
    friend class Input;
    GLFWwindow* getGLFWwindow();

    GLFWwindow* window;
};
