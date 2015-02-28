#include "game/game.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
    const int EXIT_OK = 0;
    const int EXIT_FAIL = 1;

    if (argc > 1) {
        std::cerr << "Ignoring command line arguments..." << std::endl;
    }

    try {
        Game::play();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error - " << e.what() << std::endl;
        return EXIT_FAIL;
    }

    return EXIT_OK;
}
