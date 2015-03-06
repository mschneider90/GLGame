#ifndef GLENGINE_SHADER_HPP
#define GLENGINE_SHADER_HPP

#include "engine/util/gl.hpp"
#include <string>
#include <memory>

namespace GLEngine
{

class Logger;

/*! @brief Represents an abstract shader program
 *
 *  The shader will be loaded from disk from a ASCII text format (.glsl), and then compiled
 */
class Shader
{
public:
    /*! @brief Get the index of the compiled shader
     */
    unsigned int getShaderIndex();
protected:
    Shader(std::shared_ptr<Logger> logger, const std::string& fileName);
    virtual ~Shader();
    
    virtual GLuint createShader() = 0;
private:
    void compileShader();
    
    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
    
    std::shared_ptr<Logger> m_logger;
    GLuint shaderIndex;
    bool shaderInit;
    std::string shaderText;
};

}

#endif
