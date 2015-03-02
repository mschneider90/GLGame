#ifndef GLENGINE_SHADERPROG_HPP
#define GLENGINE_SHADERPROG_HPP

#include "engine/util/gl.hpp"

#include <string>

namespace GLEngine
{

class VertexShader;
class FragmentShader;

class ShaderProgram
{
public:
    ShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    ~ShaderProgram();
    
    unsigned int getProgramIndex();
private:
    VertexShader* vs;
    FragmentShader* fs;
    
    GLuint programIndex;
};

}

#endif
