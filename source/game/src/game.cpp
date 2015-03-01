#include "game/game.hpp"

#include "engine/input/keys.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/resolution.hpp"

#include <iostream>

void Game::play()
{
    // TODO init sound object and other game objects
    GLEngine::Graphics graphics("GLGame", GLEngine::Resolution { 640, 480 });
    GLEngine::Window* window = graphics.getWindowInstance();
    GLEngine::Input* input = window->getInputInstance();

    GLEngine::Logger::logMessage(std::string("GPU    : ").append(graphics.getRendererName()));
    GLEngine::Logger::logMessage(std::string("OpenGL : ").append(graphics.getOpenGLVersion()));

    bool exit = false;
    while (!exit) {
        // main game loop goes here
        input->pollEvents();
        if (input->isKeyPressed(GLEngine::Key::ESC)) {
            exit = true;
        }

        // TEMPORARY so I can figure this out

        graphics.swapFrameBuffer();
    }
}
