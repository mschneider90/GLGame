#ifndef INPUT_HPP
#define INPUT_HPP

class GLFWwindow;

namespace GLEngine
{

enum class Key : int;
class Window;

/*! @brief Allows checking keyboard and mouse input
 */
class Input
{
public:
    /*! @brief Poll events from the OS. Should be called every frame.
     */
    void pollEvents();
 
    /*! @brief Checks if a key has been pressed since the last time this was called
     *  
     *  Keys are "sticky". If X is pressed at t=5, isKeyPressed(Key::X) will return
     *  true at t=10. This way you don't miss any key presses. It is assumed that
     *  all keys will be checked every frame.
     *
     *  @param k The Key to check
     *  @return True if the key has been pressed, false otherwise
     */
    bool isKeyPressed(Key k);
private:
    // Input corresponds to a Window, so only Window should be able to create this
    friend class Window;

    Input(GLFWwindow* win);
    ~Input();

    GLFWwindow* window;
};

}

#endif
