#ifndef GLENGINE_VECTORS_HPP
#define GLENGINE_VECTORS_HPP

namespace GLEngine
{

/*! @brief Represents a three-wide floating point vector
 */
typedef struct 
{
    float x;
    float y;
    float z;
} Vec3;

/*! @brief Represents a four-wide floating point vector
 */
typedef struct 
{
    float x;
    float y;
    float z;
    float w;
} Vec4;

}

#endif
