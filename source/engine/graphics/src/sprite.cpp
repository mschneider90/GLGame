#include "engine/graphics/sprite.hpp"
#include "engine/graphics/graphics.hpp"
#include "engine/graphics/shaderprog.hpp"
#include "engine/util/resolution.hpp"
#include "engine/graphics/mesh.hpp"

using GLEngine::Sprite;
using GLEngine::Graphics;
using GLEngine::Resolution;
using GLEngine::Mesh;
using GLEngine::ShaderProgram;

Sprite::Sprite(std::shared_ptr<Graphics> graphics, 
               const Vec3& position,
               const Resolution& resolution) : m_graphics(graphics),
                                               m_position(position),
                                               m_resolution(resolution)
{
    m_shader = graphics->makeShaderProgram("data/test_vs.glsl", "data/test_fs.glsl");
    std::vector<Vec3> vertices = { Vec3{ 0.0f,  .5f, 0.0f},
                                   Vec3{  .5f, -.5f, 0.0f},
                                   Vec3{ -.5f, -.5f, 0.0f} };
    m_mesh = graphics->makeMesh(vertices);
}

Sprite::~Sprite()
{

}

void Sprite::draw()
{
    m_graphics->draw(*m_mesh, *m_shader);
}
