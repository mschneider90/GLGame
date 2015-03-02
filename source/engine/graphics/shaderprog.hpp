#ifndef GLENGINE_SHADERPROG_HPP
#define GLENGINE_SHADERPROG_HPP

#include "engine/util/gl.hpp"

#include <string>

namespace GLEngine
{

class VertexShader;
class FragmentShader;

/*! @brief Represents a shader program, which links a vertex shader and fragment shader
 */
class ShaderProgram
{
public:
    /*! @brief Load a ShaderProgram from disk
     *
     *  @param vertexShaderPath The path to the vertex shader file
     *  @param fragmentShaderPath The path to the fragment shader file
     */
    ShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    
    /*! @brief Destroy a ShaderProgram
     */
    ~ShaderProgram();
    
    /*! @brief Get the index of the shader program
     */
    unsigned int getProgramIndex() const;
private:
    VertexShader* vs;
    FragmentShader* fs;
    
    GLuint programIndex;
};

}

#endif
