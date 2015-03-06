#ifndef GLENGINE_FRAGSHADER_HPP
#define GLENGINE_FRAGSHADER_HPP

#include "engine/graphics/shader.hpp"

#include <memory>

namespace GLEngine
{

class ShaderProgram;
class Logger;

/*! @brief Represents a fragment shader
 */
class FragmentShader : public Shader
{
    friend class ShaderManager;
public:
    ~FragmentShader();
private:
    /*! @brief Load a fragment shader
     *
     *  @param fileName The name of the file to be loaded
     */
    FragmentShader(std::shared_ptr<Logger> logger, const std::string& fileName);
    
    FragmentShader(const FragmentShader&) = delete;
    FragmentShader& operator=(const FragmentShader&) = delete;
    
    GLuint createShader();
};

}

#endif
