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

/*! @brief
 */
class Engine
{
public:
    /*! @brief
     */
    static std::shared_ptr<Engine> getEngineInstance();
    
    /*! @brief
     */
    std::shared_ptr<Graphics> getGraphicsInstance(const Resolution& res, int samples = 0);
    
    // TODO
    //std::shared_ptr<Sound> getSoundInstance();
    
    /*! @brief
     */
    std::shared_ptr<Logger> getLoggerInstance();
    
    /*! @brief
     */
    ~Engine();
private:
    Engine();
    
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    std::mutex access;
    
    std::shared_ptr<Graphics> graphics;
    std::shared_ptr<Logger> logger;
    
    // TODO
    //std::shared_ptr<Sound> sound;
    
};

}

#endif
