#include "game/game.hpp"

#include "engine/util/glfw.hpp"
#include "engine/input/keys.hpp"
#include "engine/util/resolution.hpp"

#include <iostream>

void Game::play()
{
    // TODO init sound object and other game objects
    Graphics graphics;
    Window* window = graphics.getWindowInstance("GLGame", Resolution { 640, 480 } );
    Input* input = window->getInputInstance();

    std::cout << "GPU    : " << graphics.getRendererName() << std::endl;
    std::cout << "OpenGL : " << graphics.getOpenGLVersion() << std::endl;

    bool exit = false;
    while (!exit) {
        // main game loop goes here
        input->pollEvents();
        if (input->isKeyPressed(Key::ESC)) {
            exit = true;
        }

        // TEMPORARY so I can figure this out

        graphics.swapFrameBuffer();
    }
}
