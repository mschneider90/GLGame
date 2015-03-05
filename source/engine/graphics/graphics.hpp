#ifndef GLENGINE_GRAPHICS_HPP
#define GLENGINE_GRAPHICS_HPP

#include "engine/util/resolution.hpp"
#include "engine/graphics/window.hpp"

// TEMP
#include "engine/graphics/mesh.hpp"
#include "engine/graphics/shaderprog.hpp"

#include <string>

class GLFWwindow;

namespace GLEngine
{

class Engine;
class Window;
class ShaderManager;
class Logger;

/*! @brief Allows for creating a window and drawing to the screen
 */
class Graphics
{
    friend class Engine;
public:
    /*! @brief Destroy a Graphics object
     */
    ~Graphics();

    /*! @brief Get the instance of the currently open Window
     *  
     *  @return A reference to the Window.
     */
    std::shared_ptr<Window> getWindowInstance();
    
    /*! @brief Create a ShaderProgram from the specified source files
     */
    std::unique_ptr<ShaderProgram> makeShaderProgram(const std::string& vsPath, const std::string& fsPath); 
    
    /*! @brief Create a Mesh from the vertices
     */
    std::unique_ptr<Mesh> makeMesh(const std::vector<Vec3>& vertices);

    /*! @brief Swap the framebuffers
     */
    void swapFrameBuffer();
    
    /*! @brief Clear the current framebuffer
     */
    void clearFrameBuffer();
    
    /*! @brief Draw a mesh to the framebuffer with the specified shader program (TEMPORARY)
     */
    void draw(const Mesh& mesh, const ShaderProgram& prog);

    /*! @brief Get the name of the renderer (GPU)
     *
     *  @return The name of the renderer (GPU)
     */
    std::string getRendererName();

    /*! @brief Get the OpenGL Version
     *
     *  @return The OpenGL version
     */
    std::string getOpenGLVersion();

private:
    /*! @brief Intanstiate a Graphics object
     *
     *  Initializes the OpenGL environment and context. Opens a Window whose
     *  reference can be obtained with getWindowInstance()
     * 
     *  @param windowTitle The title of the Window
     *  @param windowRes The resolution of the Window
     *  @param windowSamples The number of anti-aliasing samples to use for the Window
     */
    Graphics(std::shared_ptr<Logger> logger,
             const std::string& windowTitle,
             const Resolution& windowRes,
             int windowSamples = 0);
    
    Graphics(const Graphics& g) = delete;
    Graphics& operator=(const Graphics& g) = delete;
    
    std::shared_ptr<Window> m_window;
    std::unique_ptr<ShaderManager> m_shaderMan;
    std::shared_ptr<Logger> m_logger;
};

}

/*! @brief Callback for any GLFW errors
 */
void glfwErrorCallback(int error, const char* msg);

#endif
