#include "game/game.hpp"
#include "engine/util/logger.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
    const int EXIT_OK = 0;
    const int EXIT_FAIL = 1;
    
    const std::string LOGFILE = "GLGame.log";
    GLEngine::Logger log(LOGFILE);

    if (argc > 1) {
        GLEngine::Logger::logMessage("Ignoring command line arguments...");
    }

    try {
        Game::play();
    }
    catch (const std::runtime_error& e) {
        GLEngine::Logger::logMessage("ERROR: Exiting with exception...");
        GLEngine::Logger::logMessage(e.what());
        std::cerr << "ERROR: Please see" << LOGFILE << std::endl;
        return EXIT_FAIL;
    }

    return EXIT_OK;
}
