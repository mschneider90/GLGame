#ifndef GLENGINE_LOGGER_H
#define GLENGINE_LOGGER_H

#include <ofstream>
#include <mutex>

namespace GLEngine
{

/*! @brief Provides the ability to generate a log file
 * 
 *  Logs to memory then dumps the log to disk when the object is destroyed.
 *  This could be extended in the future to dump directly to disk in case
 *  we're encountering scenarios where the program isn't terminating nicely.
 *
 *  The design of this class assumes that you'll instantiate as a local
 *  variable in your main function and that when that function returns
 *  the log will be written.
 */
class Logger
{
public:
    /*! @brief Instantiate the Logger
     * 
     *  @param fileName The path of the log file to be written
     */
    Logger(const std::string& fileName);
    
    /*! @brief Destroy the Logger and dump the contents to disk
     */
    ~Logger();
    
    /*! @brief Log a message
     * 
     *  This implementation only writes the message to memory. The memory
     *  is dumped to disk when the object is destroyed. Thread safe.
     *
     *  @param msg The message to be logged
     */
    static void logMessage(std::string msg);
private:
    std::mutex openMutex;
    static bool isOpen;
    static std::vector<std::string> log;
    std::ofstream logFile;
};

}

#endif
