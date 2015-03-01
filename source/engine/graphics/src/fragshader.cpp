#include "engine/graphics/fragshader.hpp"

GLEngine::FragmentShader::FragmentShader(const std::string& fileName) : Shader(fileName)
{

}

GLEngine::FragmentShader::~FragmentShader()
{

}

GLuint GLEngine::FragmentShader::createShader()
{
    return glCreateShader(GL_FRAGMENT_SHADER);
}
