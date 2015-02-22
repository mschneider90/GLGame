#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

class Initializer
{
public:
    Initializer();
    ~Initializer();
    static bool isInit();
private:
    static bool init;
};

#endif
