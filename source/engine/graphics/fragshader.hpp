#ifndef GLENGINE_FRAGSHADER_HPP
#define GLENGINE_FRAGSHADER_HPP

#include "engine/graphics/shader.hpp"

namespace GLEngine
{

/*! @brief Allows for loading of a fragment shader from disk
 */
class FragmentShader : public Shader
{
public:
    /*! @brief Load a fragment shader
     *
     *  @param fileName The name of the file to be loaded
     */
    FragmentShader(const std::string& fileName);
    ~FragmentShader();
private:
    GLuint createShader();
};

}

#endif
