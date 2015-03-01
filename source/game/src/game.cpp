#include "game/game.hpp"

#include "engine/input/keys.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/resolution.hpp"

#include <iostream>

void Game::play()
{
    GLEngine::Logger::logMessage("Beginning OpenGL initialization...");
    
    // TODO init sound object and other game objects
    GLEngine::Graphics graphics("GLGame", GLEngine::Resolution { 640, 480 });
    GLEngine::Window* window = graphics.getWindowInstance();
    GLEngine::Input* input = window->getInputInstance();

    GLEngine::Logger::logMessage("OpenGL initialization complete");
    GLEngine::Logger::logMessage(std::string("GPU    : ").append(graphics.getRendererName()));
    GLEngine::Logger::logMessage(std::string("OpenGL : ").append(graphics.getOpenGLVersion()));

    GLEngine::Logger::logMessage("Entering game loop...");
    bool exit = false;
    while (!exit) {
        // main game loop goes here
        graphics.clearFrameBuffer();
        
        input->pollEvents();
        if (input->isKeyPressed(GLEngine::Key::ESC)) {
            exit = true;
        }

        // TEMPORARY so I can figure this out

        graphics.swapFrameBuffer();
    }
    
    GLEngine::Logger::logMessage("Exiting game loop...");
}
