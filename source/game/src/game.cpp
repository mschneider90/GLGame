#include "game/game.hpp"

#include "engine/input/keys.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/graphics/window.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/resolution.hpp"

// TEMP FOR TESTING
#include "engine/graphics/shaderprog.hpp"
#include "engine/graphics/mesh.hpp"
#include "engine/util/vectors.hpp"

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
    
    // TEMP FOR TESTING
    GLEngine::ShaderProgram prog("data/test_vs.glsl", "data/test_fs.glsl");
    std::vector<GLEngine::Vec3> vertices = { GLEngine::Vec3{ 0.0f,  .5f, 0.0f},
                                             GLEngine::Vec3{  .5f, -.5f, 0.0f},
                                             GLEngine::Vec3{ -.5f, -.5f, 0.0f} };
    GLEngine::Mesh mesh(vertices);

    // main game loop goes here
    GLEngine::Logger::logMessage("Entering game loop...");
    bool exit = false;
    while (!exit) {
        
        graphics.clearFrameBuffer();
        
        // check for input
        input->pollEvents();
        if (input->isKeyPressed(GLEngine::Key::ESC)) {
            exit = true;
        }
        
        // update game state (TODO)
        
        // draw stuff
        graphics.draw(mesh, prog);
        
        graphics.swapFrameBuffer();
    }
    
    GLEngine::Logger::logMessage("Exiting game loop...");
}

