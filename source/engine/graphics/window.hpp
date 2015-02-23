#include "engine/util/resolution.hpp"

#include <string>

class Window
{
public:
    Window();
    ~Window();
    
    void open(const std::string& title, const Resolution& res);
    void close();
private:
    GLFWwindow* window;
}
