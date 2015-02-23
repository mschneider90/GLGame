# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

# GLEW
find_package(GLEW REQUIRED)

# GL
find_package(OpenGL REQUIRED)

include_directories(../.)
add_library(graphics graphics.cpp window.cpp)

target_link_libraries(graphics 
                      ${GLFW_STATIC_LIBRARIES}
                      ${GLEW_LIBRARIES}
                      ${OPENGL_LIBRARIES} 
                     )
