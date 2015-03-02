#ifndef GLENGINE_GRAPHICS_HPP
#define GLENGINE_GRAPHICS_HPP

#include "engine/util/resolution.hpp"
#include "engine/graphics/mesh.hpp"
#include "engine/graphics/shaderprog.hpp"

#include <string>

class GLFWwindow;

namespace GLEngine
{

class Window;

/*! @brief Allows for creating a window and drawing to the screen
 */
class Graphics
{
public:
    /*! @brief Intanstiate a Graphics object
     *
     *  Initializes the OpenGL environment and context. Opens a Window whose
     *  reference can be obtained with getWindowInstance()
     * 
     *  @param title The title of the Window
     *  @param res The resolution of the Window
     */
    Graphics(const std::string& title, const Resolution& res);

    /*! @brief Destroy a Graphics object
     */
    ~Graphics();

    /*! @brief Get the instance of the currently open Window
     *  
     *  @return A pointer to the Window. Guaranteed to not be null.
     */
    Window* getWindowInstance();

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
    Window* window;
};

}

/*! @brief Callback for any GLFW errors
 */
void glfwErrorCallback(int error, const char* msg);

#endif
