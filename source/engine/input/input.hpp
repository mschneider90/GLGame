#ifndef INPUT_HPP
#define INPUT_HPP

enum class Key : int;
class Window;
class GLFWwindow;

class Input
{
public:
    void pollEvents();
    bool isKeyPressed(Key k);
private:
    // Input corresponds to a Window, so only Window should be able to create this
    friend class Window;

    Input(GLFWwindow* win);
    ~Input();

    GLFWwindow* window;
};

#endif
