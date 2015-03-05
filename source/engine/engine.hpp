#ifndef GLENGINE_ENGINE_HPP
#define GLENGINE_ENGINE_HPP

#include "engine/util/resolution.hpp"

#include <memory>
#include <mutex>

namespace GLEngine
{

class Graphics;
class Sound;
class Logger;

/*! @brief Singleton that is an entry point for creation of all other objects.
 *
 *  Allows for creation of Graphics, Logger, and eventually Sound
 */
class Engine
{
public:
    /*! @brief Get an instance of the Engine
     */
    static std::shared_ptr<Engine> getEngineInstance();
    
    /*! @brief Get an instance of the Graphics object
     *
     *  Note: repeated calls will ignore the parameters and return the previously created instance
     *
     *  @param res The resolution of the window
     *  @param samples The number of anti-aliasing samples
     */
    std::shared_ptr<Graphics> getGraphicsInstance(const Resolution& res, int samples = 0);
    
    // TODO
    //std::shared_ptr<Sound> getSoundInstance();
    
    /*! @brief Get an instance of the Logger object
     */
    std::shared_ptr<Logger> getLoggerInstance();
    
    /*! @brief Destroy the Engine
     */
    ~Engine();
private:
    Engine();
    
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    // prevent concurrent access to avoid double creation of the engine and logger
    std::mutex access;
    
    std::shared_ptr<Graphics> graphics;
    std::shared_ptr<Logger> logger;
    
    // TODO
    //std::shared_ptr<Sound> sound;
    
};

}

#endif
