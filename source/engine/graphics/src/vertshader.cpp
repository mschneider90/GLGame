#include "engine/graphics/vertshader.hpp"

GLEngine::VertexShader::VertexShader(std::shared_ptr<Logger> logger,
                                     const std::string& fileName) : Shader(logger, fileName)
{

}

GLEngine::VertexShader::~VertexShader()
{

}

GLuint GLEngine::VertexShader::createShader()
{
    return glCreateShader(GL_VERTEX_SHADER);
}
