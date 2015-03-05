#include "engine/graphics/fragshader.hpp"

using GLEngine::FragmentShader;

FragmentShader::FragmentShader(std::shared_ptr<Logger> logger,
                               const std::string& fileName) : Shader(logger, fileName)
{

}

FragmentShader::~FragmentShader()
{

}

GLuint FragmentShader::createShader()
{
    return glCreateShader(GL_FRAGMENT_SHADER);
}
