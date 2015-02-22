#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "engine/util/resolution.hpp"

#include <utility> // std::pair
#include <string>

class GLFWwindow;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void openWindow(const std::string& title, const Resolution& res);
    void closeWindow();
private:
    GLFWwindow* window;
};

#endif
