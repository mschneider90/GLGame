#ifndef GLENGINE_FRAGSHADER_HPP
#define GLENGINE_FRAGSHADER_HPP

#include "engine/graphics/shader.hpp"

namespace GLEngine
{

class ShaderProgram;

/*! @brief Represents a fragment shader
 */
class FragmentShader : public Shader
{
    friend class ShaderProgram;
public:
private:
    /*! @brief Load a fragment shader
     *
     *  @param fileName The name of the file to be loaded
     */
    FragmentShader(const std::string& fileName);
    ~FragmentShader();
    
    GLuint createShader();
};

}

#endif
