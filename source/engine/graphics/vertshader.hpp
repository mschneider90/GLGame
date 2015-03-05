#ifndef GLENGINE_VERTSHADER_HPP
#define GLENGINE_VERTSHADER_HPP

#include "engine/graphics/shader.hpp"

#include <memory>

namespace GLEngine
{

class ShaderProgram;
class Logger;

/*! @brief Represents a vertex shader
 */
class VertexShader : public Shader
{
    friend class ShaderManager;
public:
    ~VertexShader();
private:
    /*! @brief Load a vertex shader
     *
     *  @param fileName The name of the file to be loaded
     */
    VertexShader(std::shared_ptr<Logger> logger, const std::string& fileName);
    
    GLuint createShader();
};

}

#endif
