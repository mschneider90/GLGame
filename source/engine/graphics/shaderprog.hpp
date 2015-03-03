#ifndef GLENGINE_SHADERPROG_HPP
#define GLENGINE_SHADERPROG_HPP

#include "engine/util/gl.hpp"
#include "engine/graphics/fragshader.hpp"
#include "engine/graphics/vertshader.hpp"

#include <string>
#include <memory>

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
     *  @param TODO
     *  @param TODO
     */
    ShaderProgram(VertexShader& vs,
                  FragmentShader& fs);
    
    /*! @brief Destroy a ShaderProgram
     */
    ~ShaderProgram();
    
    /*! @brief Get the index of the shader program
     */
    unsigned int getProgramIndex() const;
private:
    GLuint programIndex;
};

}

#endif
