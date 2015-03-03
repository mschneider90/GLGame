#include "engine/graphics/shaderman.hpp"

#include <string>
#include <map>

GLEngine::ShaderManager::ShaderManager()
{

}

GLEngine::ShaderManager::~ShaderManager()
{
    for (auto vsIter = vertexShaderCache.begin(); vsIter != vertexShaderCache.end(); vsIter++)
    {
        delete vsIter->second;
    }
    
    for (auto fsIter = fragmentShaderCache.begin(); fsIter != fragmentShaderCache.end(); fsIter++)
    {
        delete fsIter->second;
    }
}

GLEngine::ShaderProgram* 
GLEngine::ShaderManager::makeShaderProgram(const std::string& vsPath,
                                           const std::string& fsPath)
{
    VertexShader* vs = nullptr;
    FragmentShader* fs = nullptr;
    
    // Load vertex shader from cache or disk
    auto vsIter = vertexShaderCache.find(vsPath);
    if (vsIter == vertexShaderCache.end()) { // not already loaded, create a new one
        GLEngine::Logger::logMessage(std::string("Shader cache miss, loading ").append(vsPath));
        vs = new VertexShader(vsPath);
        vertexShaderCache.emplace(vsPath, vs);
    }
    else {
        GLEngine::Logger::logMessage(std::string("Shader cache hit, already loaded ").append(vsPath));
        vs = vsIter->second;
    }
    
    // Load fragment shader from cache or disk
    auto fsIter = fragmentShaderCache.find(fsPath);
    if (fsIter == fragmentShaderCache.end()) {
        GLEngine::Logger::logMessage(std::string("Shader cache miss, loading ").append(fsPath));
        fs = new FragmentShader(fsPath);
        fragmentShaderCache.emplace(fsPath, fs);
    }
    else {
        GLEngine::Logger::logMessage(std::string("Shader cache hit, already loaded ").append(fsPath));
        fs = fsIter->second;
    }
    
    // Create the shader program which performs linking
    GLEngine::Logger::logMessage(std::string("Linking shaders ")
                                     .append(vsPath)
                                     .append(" and ")
                                     .append(fsPath));
                                     
    return new ShaderProgram(*vs, *fs);
}

