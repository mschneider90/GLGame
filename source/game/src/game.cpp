#include "game/game.hpp"

#include "engine/engine.hpp"
#include "engine/input/keys.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/vectors.hpp"
#include "engine/graphics/sprite.hpp"

using namespace GLEngine;

void Game::play(Engine& engine)
{
    // TODO init sound object and other game objects
    std::shared_ptr<Logger> logger = engine.getLoggerInstance();
    std::shared_ptr<Graphics> graphics = engine.getGraphicsInstance(Resolution { 640, 480 }, 4);
    std::shared_ptr<Window> window = graphics->getWindowInstance();
    std::shared_ptr<Input> input = window->getInputInstance();
    
    Sprite sprite(graphics, Vec3 { 0, 0, 0}, Resolution { 64, 64});

    // main game loop goes here
    logger->logMessage("Entering game loop...");
    bool exit = false;
    while (!exit) {
        graphics->clearFrameBuffer();
        
        // check for input
        input->pollEvents();
        if (input->isKeyPressed(Key::ESC)) {
            exit = true;
        }
        
        // update game state (TODO)
        
        // draw stuff
        sprite.draw();
        
        graphics->swapFrameBuffer();
    }
    
    logger->logMessage("Exiting game loop...");
}

