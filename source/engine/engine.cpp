#include "engine/engine.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/util/logger.hpp"

#include <mutex>

using GLEngine::Engine;
using GLEngine::Graphics;
using GLEngine::Logger;

Engine::Engine()
{

}

Engine::~Engine()
{
    if (!graphics.unique()) {
        if (logger) {
            logger->logMessage("engine: graphics should not live beyond engine, deleting now");
        }
        graphics.reset();
    }
}

std::shared_ptr<Engine> Engine::getEngineInstance()
{
    static auto engine = std::shared_ptr<Engine>(new Engine());
    return engine;
}

std::shared_ptr<Graphics> Engine::getGraphicsInstance(const Resolution& res, int samples)
{
    access.lock();
    if (!graphics) {
        graphics = std::shared_ptr<Graphics>(new Graphics(logger, "GLEngine", res, samples));
    }
    access.unlock();
    
    return graphics;
}

std::shared_ptr<Logger> Engine::getLoggerInstance()
{
    access.lock();
    if (!logger) {
        logger = std::shared_ptr<Logger>(new Logger());
    }
    access.unlock();
    
    return logger;
}

