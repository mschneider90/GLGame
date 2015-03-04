#include "engine/graphics/shaderman.hpp"
#include "engine/util/logger.hpp"

#include <string>
#include <memory>
#include <map>

using GLEngine::ShaderProgram;
using GLEngine::ShaderManager;
using GLEngine::VertexShader;
using GLEngine::FragmentShader;
using GLEngine::Logger;

ShaderManager::ShaderManager()
{

}

ShaderManager::~ShaderManager()
{

}

std::unique_ptr<ShaderProgram>
ShaderManager::makeShaderProgram(const std::string& vsPath,
                                 const std::string& fsPath)
{
    // Store what we find (can't copy unique_ptr)
    VertexShader* vsPtr = nullptr;
    FragmentShader* fsPtr = nullptr;
    
    // Load vertex shader from cache or disk
    while (!vsPtr)
    {
        auto vsIter = vertexShaderCache.find(vsPath);
        if (vsIter == vertexShaderCache.end()) { // not already loaded, create a new one
            Logger::logMessage(std::string("Shader cache miss, loading ").append(vsPath));
            std::unique_ptr<VertexShader> vs;
            vertexShaderCache.emplace(vsPath, std::unique_ptr<VertexShader>(new VertexShader(vsPath)));
        }
        else {
            Logger::logMessage(std::string("Shader cache hit, already loaded ").append(vsPath));
            vsPtr = (vsIter->second).get();
        }
    }
    
    // Load fragment shader from cache or disk
    while (!fsPtr)
    {
        auto fsIter = fragmentShaderCache.find(fsPath);
        if (fsIter == fragmentShaderCache.end()) {
            Logger::logMessage(std::string("Shader cache miss, loading ").append(fsPath));
            std::unique_ptr<FragmentShader> fs;
            fragmentShaderCache.emplace(fsPath, std::unique_ptr<FragmentShader>(new FragmentShader(fsPath)));
        }
        else {
            Logger::logMessage(std::string("Shader cache hit, already loaded ").append(fsPath));
            fsPtr = (fsIter->second).get();
        }
    }
    
    Logger::logMessage(std::string("Linking shaders ")
                                     .append(vsPath)
                                     .append(" and ")
                                     .append(fsPath));
                                     
    return std::unique_ptr<ShaderProgram>(new ShaderProgram(*vsPtr, *fsPtr));
}

