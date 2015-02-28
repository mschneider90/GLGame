#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "engine/util/resolution.hpp"
#include "engine/graphics/window.hpp"

#include <string>

class GLFWwindow;

class Graphics
{
public:
    Graphics(const std::string& title, const Resolution& res);
    ~Graphics();

    Window* getWindowInstance();
    void swapFrameBuffer();

    std::string getRendererName();
    std::string getOpenGLVersion();
private:
    Window* window;
};

#endif
