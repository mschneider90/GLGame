#include "game/game.hpp"
#include "engine/engine.hpp"
#include "engine/util/logger.hpp"

#include <iostream>
#include <stdexcept>

using GLEngine::Engine;
using GLEngine::Logger;

int main(int argc, char** argv)
{
    const int EXIT_OK = 0;
    const int EXIT_FAIL = 1;

    std::shared_ptr<Engine> engine = Engine::getEngineInstance();
    std::shared_ptr<Logger> logger = engine->getLoggerInstance();

    if (argc > 1) {
        logger->logMessage("Ignoring command line arguments...");
    }

    try {
        Game::play(*engine);
    }
    catch (const std::runtime_error& e) {
        logger->logMessage("ERROR: Exiting with exception...");
        logger->logMessage(e.what());
        std::cerr << "ERROR: Please see " << logger->getLogFileName() << std::endl;
        return EXIT_FAIL;
    }

    return EXIT_OK;
}
