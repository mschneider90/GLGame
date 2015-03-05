#ifndef GLENGINE_SHADERMAN_HPP
#define GLENGINE_SHADERMAN_HPP

#include "engine/graphics/shaderprog.hpp"
#include "engine/graphics/vertshader.hpp"
#include "engine/graphics/fragshader.hpp"

#include <map>

namespace GLEngine
{

class Graphics;
class Shader;

/*! @brief Manages (caches) shaders
 */
class ShaderManager
{
    friend class Graphics;
public:
    ~ShaderManager();
    
    /*! @brief Make a shader program
     */
    std::unique_ptr<ShaderProgram> makeShaderProgram(const std::string& vsPath, const std::string& fsPath);
private:
    /*! @brief Create a shader manager
     */
    ShaderManager(std::shared_ptr<Logger> logger);
    
    ShaderManager(ShaderManager&) = delete;
    ShaderManager& operator=(ShaderManager&) = delete;
    
    std::map<std::string, std::unique_ptr<VertexShader>> vertexShaderCache;
    std::map<std::string, std::unique_ptr<FragmentShader>> fragmentShaderCache;
    
    std::shared_ptr<Logger> m_logger;
};

}
#endif
