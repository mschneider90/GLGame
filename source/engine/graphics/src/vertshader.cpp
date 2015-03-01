#include "engine/graphics/vertshader.hpp"

GLEngine::VertexShader::VertexShader(const std::string& fileName) : Shader(fileName)
{

}

GLEngine::VertexShader::~VertexShader()
{

}

GLuint GLEngine::VertexShader::createShader()
{
    return glCreateShader(GL_VERTEX_SHADER);
}
