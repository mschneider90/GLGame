#include "game/game.hpp"

#include "engine/engine.hpp"
#include "engine/input/keys.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/resolution.hpp"

// TEMP FOR TESTING
#include "engine/graphics/shaderprog.hpp"
#include "engine/graphics/shaderman.hpp"
#include "engine/graphics/mesh.hpp"
#include "engine/util/vectors.hpp"

#include <iostream>

using namespace GLEngine;

void Game::play(Engine& engine)
{
    // TODO init sound object and other game objects
    std::shared_ptr<Logger> logger = engine.getLoggerInstance();
    std::shared_ptr<Graphics> graphics = engine.getGraphicsInstance(Resolution { 640, 480 }, 4);
    std::shared_ptr<Window> window = graphics->getWindowInstance();
    std::shared_ptr<Input> input = window->getInputInstance();
    
    // TEMPORARY CODE
    std::unique_ptr<ShaderProgram> prog = graphics->makeShaderProgram("data/test_vs.glsl", "data/test_fs.glsl");
    std::unique_ptr<ShaderProgram> prog2 = graphics->makeShaderProgram("data/test_vs.glsl", "data/test_fs.glsl");
    std::vector<Vec3> vertices = { Vec3{ 0.0f,  .5f, 0.0f},
                                   Vec3{  .5f, -.5f, 0.0f},
                                   Vec3{ -.5f, -.5f, 0.0f} };
    // temp pls dont do this
    Mesh mesh(logger, vertices);

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
        graphics->draw(mesh, *prog);
        
        graphics->swapFrameBuffer();
    }
    
    logger->logMessage("Exiting game loop...");
}

