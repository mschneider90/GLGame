#ifndef GAME_HPP
#define GAME_HPP

#include "engine/engine.hpp"

class Game
{
public:
    static void play(GLEngine::Engine& engine);
private:
    Game() {};
    ~Game() {};
};

#endif
