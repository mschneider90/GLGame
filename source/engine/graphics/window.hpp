#include "engine/util/resolution.hpp"

#include <string>

class GLFWwindow;
class Input;

class Window
{
public:
    void open(const std::string& title, const Resolution& res);
    void close();
private:
    // Window creation should happen only from Graphics
    friend class Graphics;
    // TODO Input only needs a GLFWwindow*
    friend class Input;
    Window();
    ~Window();
    
    GLFWwindow* getGLFWwindow();

    GLFWwindow* window;
};
