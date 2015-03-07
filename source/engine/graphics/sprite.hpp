#ifndef GLENGINE_SPRITE_HPP
#define GLENGINE_SPRITE_HPP

#include "engine/util/vectors.hpp"
#include "engine/util/resolution.hpp"

#include <memory>

namespace GLEngine
{

class Graphics;
class Mesh;
class ShaderProgram;

/*! @brief Represents a square 2D sprite that can be drawn on the screen and moved
 *
 *  TODO Add texture
 */
class Sprite
{
public:
    /*! @brief Create a Sprite
     */
    Sprite(std::shared_ptr<Graphics> graphics, const Vec3& position, const Resolution& resolution);
    
    /*! @brief Destroy a Sprite
     */
    virtual ~Sprite();
    
    /*! @brief Draw the sprite to the screen
     */
    virtual void draw();
private:
    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;
    
    std::shared_ptr<Graphics> m_graphics;
    std::shared_ptr<Mesh> m_mesh;
    std::shared_ptr<ShaderProgram> m_shader;
    
    Vec3 m_position;
    
    // TODO resolution should come from the texture
    Resolution m_resolution;
};

}

#endif
