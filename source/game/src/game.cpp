#include "game/game.hpp"
#include "engine/util/resolution.hpp"
#include "engine/util/initializer.hpp"

void Game::play()
{
    // This needs to happen before anything else to initialize the engine
    // Engine is automatically de-initialized (?) when this is destroyed at the end of this scope
    Initializer i;

    // TODO init sound object and other game objects
    Graphics gfx;
    Input in;

    gfx.openWindow("Hello World", Resolution {640, 480} );

    bool exit = false;
    while (!exit) {
        // main game loop goes here
    }

    gfx.closeWindow();
}
