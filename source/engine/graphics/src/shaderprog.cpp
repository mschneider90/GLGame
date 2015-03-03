#include "engine/graphics/shaderprog.hpp"
#include "engine/graphics/vertshader.hpp"
#include "engine/graphics/fragshader.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/gl.hpp"

#include <memory>

GLEngine::ShaderProgram::ShaderProgram(VertexShader& vs,
                                       FragmentShader& fs) : programIndex(0)
{
    programIndex = glCreateProgram();
    glAttachShader(programIndex, vs.getShaderIndex());
    glAttachShader(programIndex, fs.getShaderIndex());
    glLinkProgram(programIndex);
    
    // Check link status
    GLint retVal = GL_FALSE;
    glGetProgramiv(programIndex, GL_LINK_STATUS, &retVal);
    if (retVal == GL_FALSE)
    {
        const int maxLogLength = 2048;
        int actualLogLength = 0;
        char log[maxLogLength];
        glGetProgramInfoLog(programIndex, maxLogLength, &actualLogLength, log);
        GLEngine::Logger::logMessage(std::string(log));
        throw std::runtime_error("graphics: shader linking failed");
    }
}

GLEngine::ShaderProgram::~ShaderProgram()
{

}

unsigned int GLEngine::ShaderProgram::getProgramIndex() const
{
    return static_cast<unsigned int>(programIndex);
}
