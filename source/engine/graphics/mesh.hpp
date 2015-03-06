#ifndef GLENGINE_MESH_HPP
#define GLENGINE_MESH_HPP

#include "engine/util/vectors.hpp"
#include "engine/util/gl.hpp"

#include <vector>
#include <memory>

namespace GLEngine
{

class Logger;

/*! @brief Represents a mesh, which is a collection of vertices that define a shape
 */
class Mesh
{
public:
    /*! @brief Create a mesh from a list of vertices
     */
    Mesh(std::shared_ptr<Logger> logger, const std::vector<Vec3>& vertices);
    
    /*! @brief Destroy the mesh
     */
    ~Mesh();
    
    /*! @brief Get the number of vertices in the mesh
     */
    unsigned int getNumVertices() const;
    
    /*! @brief Get the index of the mesh
     */
    unsigned int getAttributeIndex() const;
private:
    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;
    
    unsigned int numVertices;
    GLuint attributeIndex;
    std::shared_ptr<Logger> m_logger;
};

}

#endif
