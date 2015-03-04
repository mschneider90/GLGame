#ifndef GLENGINE_SHADERPROG_HPP
#define GLENGINE_SHADERPROG_HPP

#include "engine/util/gl.hpp"
#include "engine/graphics/fragshader.hpp"
#include "engine/graphics/vertshader.hpp"

#include <string>
#include <memory>

namespace GLEngine
{

class ShaderManager;
class VertexShader;
class FragmentShader;

/*! @brief Represents a shader program, which links a vertex shader and fragment shader
 */
class ShaderProgram
{
    friend class ShaderManager;
public:
    /*! @brief Destroy a ShaderProgram
     */
    ~ShaderProgram();
    
    /*! @brief Get the index of the shader program
     */
    unsigned int getProgramIndex() const;
private:
    /*! @brief Load a ShaderProgram from disk
     *
     *  @param The path to the vertex shader file on disk
     *  @param The path to the fragment shader file on disk
     */
    ShaderProgram(VertexShader& vs,
                  FragmentShader& fs);
                  
    GLuint programIndex;
};

}

#endif
