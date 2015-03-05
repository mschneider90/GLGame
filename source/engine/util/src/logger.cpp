#include "engine/util/logger.hpp"

#include <fstream>
#include <stdexcept>
#include <mutex>

using GLEngine::Logger;

Logger::Logger(bool forceCritical) : m_forceCritical(forceCritical), m_msgNum(0)
{
    m_logFile.open(FILE_NAME);
}

Logger::~Logger()
{
    // Dump the message log to disk
    m_logFile.seekp(std::ios_base::beg);
    for (std::string msg : m_log)
    {
        m_logFile << msg << std::endl;
    }
    m_logFile.close();
}

void Logger::logMessage(std::string message, bool incrementCount, bool critical)
{
    m_access.lock();
    
    std::string formattedMessage = formatMessage(message);
    if (critical || m_forceCritical) {
        m_logFile << formattedMessage << std::endl;
    }
    m_log.push_back(formattedMessage);
    if (incrementCount) {
        m_msgNum++;
    }
    
    m_access.unlock();
}

std::string Logger::formatMessage(const std::string& message)
{
    std::string formattedMessage = std::to_string(m_msgNum);
    formattedMessage.append(" >> ");
    formattedMessage.append(message);
    return formattedMessage;
}

std::string Logger::getLogFileName() {
    return FILE_NAME;
}

