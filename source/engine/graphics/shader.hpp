#ifndef GLENGINE_SHADER_HPP
#define GLENGINE_SHADER_HPP

#include "engine/util/gl.hpp"
#include <string>

namespace GLEngine
{

/*! @brief Represents a shader program (abstract)
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
    Shader(const std::string& fileName);
    virtual ~Shader();
    
    virtual GLuint createShader() = 0;
private:
    void compileShader();
    
    GLuint shaderIndex;
    bool shaderInit;
    std::string shaderText;
};

}

#endif
