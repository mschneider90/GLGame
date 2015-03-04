#include "game/game.hpp"

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

void Game::play()
{
    Logger::logMessage("Beginning OpenGL initialization...");
    
    // TODO init sound object and other game objects
    Graphics graphics("GLGame", Resolution { 640, 480 }, 4);
    Window& window = graphics.getWindowInstance();
    Input& input = window.getInputInstance();

    Logger::logMessage("OpenGL initialization complete");
    Logger::logMessage(std::string("GPU    : ").append(graphics.getRendererName()));
    Logger::logMessage(std::string("OpenGL : ").append(graphics.getOpenGLVersion()));
    
    // TEMP FOR TESTING
    ShaderManager shaderMan;
    ShaderProgram* prog = shaderMan.makeShaderProgram("data/test_vs.glsl", "data/test_fs.glsl");
    ShaderProgram* prog2 = shaderMan.makeShaderProgram("data/test_vs.glsl", "data/test_fs.glsl");
    std::vector<Vec3> vertices = { Vec3{ 0.0f,  .5f, 0.0f},
                                   Vec3{  .5f, -.5f, 0.0f},
                                   Vec3{ -.5f, -.5f, 0.0f} };
    Mesh mesh(vertices);

    // main game loop goes here
    Logger::logMessage("Entering game loop...");
    bool exit = false;
    while (!exit) {
        graphics.clearFrameBuffer();
        
        // check for input
        input.pollEvents();
        if (input.isKeyPressed(Key::ESC)) {
            exit = true;
        }
        
        // update game state (TODO)
        
        // draw stuff
        graphics.draw(mesh, *prog);
        
        graphics.swapFrameBuffer();
    }
    
    Logger::logMessage("Exiting game loop...");
}

