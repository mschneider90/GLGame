#ifndef GLENGINE_SHADERMAN_HPP
#define GLENGINE_SHADERMAN_HPP

#include "engine/graphics/shaderprog.hpp"
#include "engine/util/logger.hpp"

#include <map>

namespace GLEngine
{

class Graphics;
class Shader;

/*! @brief Manages (caches) shaders
 */
class ShaderManager
{
    //friend class Graphics;
public:
    /*! @brief Create a shader manager
     */
    ShaderManager();
    ~ShaderManager();
    
    /*! @brief Make a shader program
     */
    ShaderProgram* makeShaderProgram(const std::string& vsPath, const std::string& fsPath);
private:
    std::map<std::string, VertexShader*> vertexShaderCache;
    std::map<std::string, FragmentShader*> fragmentShaderCache;
};

}
#endif
