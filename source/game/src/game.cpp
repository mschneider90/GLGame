#include "game/game.hpp"

Game::Game()
{

}

Game::~Game()
{

}

void Game::play()
{
    gfx.openWindow("Hello World", std::pair<int, int>(640, 480));
    while (true) {
        // main game loop goes here
    }
}
