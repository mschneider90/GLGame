#ifndef GLENGINE_VERTSHADER_HPP
#define GLENGINE_VERTSHADER_HPP

#include "engine/graphics/shader.hpp"

namespace GLEngine
{

class ShaderProgram;

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
    VertexShader(const std::string& fileName);
    
    GLuint createShader();
};

}

#endif
