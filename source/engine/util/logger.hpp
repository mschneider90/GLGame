#ifndef GLENGINE_LOGGER_H
#define GLENGINE_LOGGER_H

#include <fstream>
#include <vector>
#include <mutex>

namespace GLEngine
{

/*! @brief Provides the ability to generate a log file
 *
 *  Allows for two logging modes: non-critical and critical. Non-critical is stored
 *  in memory until the object is destroyed, upon which it is dumped to disk. Critical
 *  messages are dumped to disk immediately.
 */
class Logger
{
    friend class Engine;
public:
    /*! @brief Destroy the Logger and dump the (non-critical) contents to disk
     */
    ~Logger();
    
    /*! @brief Log a message
     * 
     *  @param message The message to be logged
     *  @param newSection Start a new message section
     *  @param critical Is this a critical message
     */
    void logMessage(std::string message, bool newSection = true, bool critical = false);
    
    /*! @brief Get the log file name
     *
     *  @return The name of the log file on disk
     */
    std::string getLogFileName() const;
private:
    /*! @brief Instantiate the Logger
     * 
     *  @param forceCritical Force critical messages (dump to disk immediately)
     */
    Logger(bool forceCritical = false);
    
    /*! @brief Format the message
     */
    std::string formatMessage(const std::string& msg, bool newSection) const;
    
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    const std::string FILE_NAME = "GLEngine.log";
    
    std::vector<std::string> m_log;
    bool m_forceCritical;
    std::mutex m_access;
    std::ofstream m_logFile;
};

}

#endif
