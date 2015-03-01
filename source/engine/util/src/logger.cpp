#include "engine/util/logger.hpp"

#include <fstream>
#include <stdexcept>
#include <mutex>

std::vector<std::string> GLEngine::Logger::log;
bool GLEngine::Logger::isOpen = false;

GLEngine::Logger::Logger(const std::string& fileName)
{
    openMutex.lock();
    if (isOpen) {
        throw std::runtime_error("Only one logger instance allowed");
    }
    isOpen = true;
    openMutex.unlock();
    logFile.open(fileName);
}

GLEngine::Logger::~Logger()
{
    // Dump the message log to disk
    for (std::string msg : log)
    {
        logFile << msg << std::endl;
    }
    logFile.close();
}

void GLEngine::Logger::logMessage(std::string msg)
{
    static std::mutex logMutex;
    
    if (isOpen) {
        logMutex.lock();
        log.push_back(msg);
        logMutex.unlock();
    }
}
