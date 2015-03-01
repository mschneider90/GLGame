#include "game/game.hpp"

#include "engine/input/keys.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/resolution.hpp"

#include <iostream>

void Game::play()
{
    Logger log("GLGame.log");
    
    // TODO init sound object and other game objects
    GLEngine::Graphics graphics("GLGame", GLEngine::Resolution { 640, 480 });
    GLEngine::Window* window = graphics.getWindowInstance();
    GLEngine::Input* input = window->getInputInstance();

    Logger::logMessage(std::string("GPU    : " << graphics.getRendererName()));
    Logger::logMessage(std::string("OpenGL : " << graphics.getOpenGLVersion()));

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
