#ifndef INPUT_HPP
#define INPUT_HPP

class Input
{
public:
    Input(const Window* win);
    ~Input();
    
    bool isKeyPressed(Key k);
private:
    const Window* currentWindow;
};

#endif
