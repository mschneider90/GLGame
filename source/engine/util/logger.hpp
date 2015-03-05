#ifndef GLENGINE_LOGGER_H
#define GLENGINE_LOGGER_H

#include <fstream>
#include <vector>
#include <mutex>

namespace GLEngine
{

/*! @brief Provides the ability to generate a log file
 *
 */
class Logger
{
    friend class Engine;
public:
    /*! @brief Destroy the Logger and dump the contents to disk
     */
    ~Logger();
    
    /*! @brief Log a message
     * 
     *  @param msg The message to be logged
     */
    void logMessage(std::string msg, bool incrementCount = true, bool critical = false);
    
    /*! @brief Get the log file name
     */
    std::string getLogFileName();
private:
    /*! @brief Instantiate the Logger
     * 
     *  @param forceCritical Force critical messages (dump to disk immediately)
     */
    Logger(bool forceCritical = false);
    
    std::string formatMessage(const std::string& msg);
    
    const std::string FILE_NAME = "GLEngine.log";
    
    std::vector<std::string> m_log;
    bool m_forceCritical;
    unsigned int m_msgNum;
    std::mutex m_access;
    std::ofstream m_logFile;
};

}

#endif
