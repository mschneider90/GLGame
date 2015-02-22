#ifndef GAME_HPP
#define GAME_HPP

#include "engine/graphics/graphics.hpp"

class Game
{
public:
    Game();
    ~Game();
    void play();
private:
    Graphics gfx;
};

#endif
