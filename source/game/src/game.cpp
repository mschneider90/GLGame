#include "game/game.hpp"

#include "engine/input/keys.hpp"
#include "engine/util/resolution.hpp"

void Game::play()
{
    // TODO init sound object and other game objects
    Graphics gfx;
    Window* window = gfx.getWindowInstance("GLGame", Resolution { 640, 480 } );
    Input* input = window->getInputInstance();

    bool exit = false;
    while (!exit) {
        // main game loop goes here
        input->pollEvents();
        if (input->isKeyPressed(Key::ESC)) {
            exit = true;
        }

        gfx.swapFrameBuffer();
    }
}
