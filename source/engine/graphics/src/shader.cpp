#include "engine/graphics/shader.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/gl.hpp"

#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>

GLEngine::Shader::Shader(std::shared_ptr<Logger> logger,
                         const std::string& fileName) : m_logger(logger), shaderIndex(0), shaderInit(false)
{
    std::ifstream in;
    
    in.open(fileName);
    if (!in.is_open()) {
        throw std::runtime_error(std::string("graphics: failed to load shader ").append(fileName));
    }

    // Read entire file
    in.seekg(0, std::ios::end);
    shaderText.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&shaderText[0], shaderText.size()); 
    in.close();
    
    logger->logMessage(std::string("Read shader from ").append(fileName));
}

GLEngine::Shader::~Shader()
{

}

unsigned int GLEngine::Shader::getShaderIndex() 
{   
    if (!shaderInit) {
        // Defer shader creation/compilation to here since this a virtual function
        // and can't be in the constructor
        shaderIndex = createShader();
        compileShader();
        shaderInit = true;
    }
    
    return static_cast<unsigned int>(shaderIndex);
}

void GLEngine::Shader::compileShader()
{
    const int SHADER_COUNT = 1;
    const GLint* SHADER_LENGTH = nullptr;
    const char* shaderTextCstr = shaderText.c_str();
    glShaderSource(shaderIndex, SHADER_COUNT, &shaderTextCstr, SHADER_LENGTH);
    glCompileShader(shaderIndex);
    
    // Check shader compilation status
    GLint retVal = GL_FALSE;
    glGetShaderiv(shaderIndex, GL_COMPILE_STATUS, &retVal);
    if (retVal != GL_TRUE) // compilation failed, log an error and throw
    {
        const int maxLogLength = 2048;
        int actualLogLength = 0;
        char log[maxLogLength];
        glGetShaderInfoLog(shaderIndex, maxLogLength, &actualLogLength, log);
        m_logger->logMessage(std::string(log));
        throw std::runtime_error("graphics: shader compilation failed");
    }
     
    // Don't need shaderText anymore
    shaderText.clear();
}

