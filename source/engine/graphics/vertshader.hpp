#ifndef GLENGINE_VERTSHADER_HPP
#define GLENGINE_VERTSHADER_HPP

#include "engine/graphics/shader.hpp"

namespace GLEngine
{

/*! @brief Allows for loading of a vertex shader from disk
 */
class VertexShader : public Shader
{
public:
    /*! @brief Load a vertex shader
     *
     *  @param fileName The name of the file to be loaded
     */
    VertexShader(const std::string& fileName);
    ~VertexShader();
private:
    GLuint createShader();
};

}

#endif
