#include "engine/input/input.hpp"
#include "engine/util/initializer.hpp"

#include <stdexcept>

Input::Input()
{
    if (!Initializer::isInit()) {
        throw std::runtime_error("input: Engine not initialized");
    }   
}

Input::~Input()
{

}
