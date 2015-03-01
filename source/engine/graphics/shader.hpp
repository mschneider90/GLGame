#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace GLEngine
{

/*! @brief Represents a shader program (abstract)
 *
 *  The shader will be loaded from disk from a ASCII text format (.glsl), and then compiled
 */
class Shader
{
public:
    /*! @brief Get the index of the compiled shader
     */
    unsigned int getShaderIndex();
protected:
    Shader(const std::string& fileName);
    virtual ~Shader();
    
    virtual GLuint createShader() = 0;
private:
    GLuint shaderIndex;
    std::string shaderText;
};

}
