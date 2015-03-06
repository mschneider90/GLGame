#include "engine/graphics/mesh.hpp"
#include "engine/util/vectors.hpp"
#include "engine/util/gl.hpp"
#include "engine/util/logger.hpp"

#include <vector>
#include <memory>

using GLEngine::Logger;
using GLEngine::Mesh;
using GLEngine::Vec3;

Mesh::Mesh(std::shared_ptr<Logger> logger, const std::vector<Vec3>& vertices) : m_logger(logger),
                                                                                numVertices(0),
                                                                                attributeIndex(0)
{
    numVertices = vertices.size();
    
    std::vector<float> points(numVertices*3);
    int pointIndex = 0;
    // Convert to a 1D array of floats for OpenGL
    for (Vec3 v : vertices)
    {
        points[pointIndex++] = v.x;
        points[pointIndex++] = v.y;
        points[pointIndex++] = v.z;
    }
    
    m_logger->logMessage(std::string("Creating mesh of ").append(std::to_string(numVertices)).append(" vertices"));
    // Generate vertex buffer object
    GLuint bufferIndex = 0;
    const int NUM_BUFFERS = 1;
    glGenBuffers(NUM_BUFFERS, &bufferIndex);
    glBindBuffer(GL_ARRAY_BUFFER, bufferIndex);
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof (float), points.data(), GL_STATIC_DRAW);
    
    // Generate vertex attribute object
    const int NUM_ARRAYS = 1;
    const int ATTRIBUTE_LOCATION = 0;
    const int STRIDE = 0;
    const void* OFFSET = nullptr;
    attributeIndex = 0;
    
    glGenVertexArrays(NUM_ARRAYS, &attributeIndex);
    glBindVertexArray(attributeIndex);
    glEnableVertexAttribArray(ATTRIBUTE_LOCATION);
    glBindBuffer(GL_ARRAY_BUFFER, bufferIndex);
    glVertexAttribPointer(ATTRIBUTE_LOCATION, numVertices, GL_FLOAT, GL_FALSE, STRIDE, OFFSET);
}

Mesh::~Mesh()
{

}

unsigned int Mesh::getNumVertices() const
{
    return numVertices;
}

unsigned int Mesh::getAttributeIndex() const
{
    return static_cast<unsigned int>(attributeIndex);
}

