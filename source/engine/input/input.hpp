#ifndef INPUT_HPP
#define INPUT_HPP

class Input
{
public:
    Input();
    ~Input();
    
    // Plan: this function will call glfwGetKey in STICKY mode
    // It can also call other functions, like isKeyPressed(ESC) can also check if the window is closed so this
    // can be handled in one go
    // GLFW is retarded and defined in their keys in macros. So define a Key class that translates
    // a key enum to GLFW keys
    //bool isKeyPressed(Key k)
};

#endif
