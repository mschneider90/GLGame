#include "engine/graphics/fragshader.hpp"

GLEngine::FragmentShader::FragmentShader(std::shared_ptr<Logger> logger,
                                         const std::string& fileName) : Shader(logger, fileName)
{

}

GLEngine::FragmentShader::~FragmentShader()
{

}

GLuint GLEngine::FragmentShader::createShader()
{
    return glCreateShader(GL_FRAGMENT_SHADER);
}
