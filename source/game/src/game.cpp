#include "game/game.hpp"
#include "engine/util/resolution.hpp"

Game::Game()
{

}

Game::~Game()
{

}

void Game::play()
{
    gfx.openWindow("Hello World", Resolution {640, 480} );
    while (true) {
        // main game loop goes here
    }
}
