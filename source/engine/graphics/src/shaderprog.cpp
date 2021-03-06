#include "engine/graphics/shaderprog.hpp"
#include "engine/graphics/vertshader.hpp"
#include "engine/graphics/fragshader.hpp"
#include "engine/util/logger.hpp"
#include "engine/util/gl.hpp"

#include <memory>

using GLEngine::ShaderProgram;
using GLEngine::VertexShader;
using GLEngine::FragmentShader;

ShaderProgram::ShaderProgram(std::shared_ptr<Logger> logger,
                             VertexShader& vs,
                             FragmentShader& fs) : m_logger(logger), programIndex(0)
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
        logger->logMessage(std::string(log));
        throw std::runtime_error("graphics: shader linking failed");
    }
}

ShaderProgram::~ShaderProgram()
{

}

unsigned int ShaderProgram::getProgramIndex() const
{
    return static_cast<unsigned int>(programIndex);
}
