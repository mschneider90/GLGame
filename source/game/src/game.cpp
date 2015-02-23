#include "game/game.hpp"
#include "engine/util/resolution.hpp"

void Game::play()
{
    // TODO init sound object and other game objects
    Graphics gfx;
    Window* window = gfx.getWindowInstance("Hello World", Resolution { 640, 480} );
    Input input(window);

    bool exit = false;
    while (!exit) {
        // main game loop goes here
        if (input.isKeyPressed(Keys::ESC) {
            exit = true;
        }
    }
}
