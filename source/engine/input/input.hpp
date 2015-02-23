#ifndef INPUT_HPP
#define INPUT_HPP

enum class Key : int;
class Window;

class Input
{
public:
    Input(Window* win);
    ~Input();
    
    void pollEvents();
    bool isKeyPressed(Key k);
private:
    Window* currentWindow;
};

#endif
