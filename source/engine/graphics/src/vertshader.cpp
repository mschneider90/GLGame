#include "engine/graphics/vertshader.hpp"

using GLEngine::VertexShader;

VertexShader::VertexShader(std::shared_ptr<Logger> logger,
                                     const std::string& fileName) : Shader(logger, fileName)
{

}

VertexShader::~VertexShader()
{

}

GLuint VertexShader::createShader()
{
    return glCreateShader(GL_VERTEX_SHADER);
}
