#include "engine/graphics/shader.hpp"
#include "engine/util/logger.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>

GLEngine::Shader::Shader(const std::string& fileName)
{
    std::ifstream in;
    
    in.open(fileName);
    in >> shaderText;
    in.close();
    
    GLEngine::Logger::logMessage(std::string("Read shader from ").append(fileName));
    GLEngine::Logger::logMessage(shaderText);
}

GLEngine::Shader::~Shader()
{
    glDeleteShader(shaderIndex);
}

unsigned int GLEngine::Shader::getShaderIndex() 
{
    // This can't be inside the constructor since createShader is virtual
    GLuint index = createShader();
    
    const int SHADER_COUNT = 1;
    const GLint* SHADER_LENGTH = nullptr;
    const char* shaderTextCstr = shaderText.c_str();
    glShaderSource(index, SHADER_COUNT, &shaderTextCstr, SHADER_LENGTH);
    glCompileShader(index);
    
    // Don't need shaderText anymore
    shaderText.clear();
    
    return static_cast<unsigned int>(shaderIndex);
}
