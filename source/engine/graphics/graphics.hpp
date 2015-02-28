#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "engine/util/resolution.hpp"
#include "engine/graphics/window.hpp"

#include <string>

class GLFWwindow;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    Window* getWindowInstance(const std::string& title, const Resolution& res);
    void swapFrameBuffer();

    std::string getRendererName();
    std::string getOpenGLVersion();
private:
    Window* window;
    bool isWindowOpen;
};

#endif
