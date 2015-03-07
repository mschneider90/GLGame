# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

# GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

# GL
find_package(OpenGL REQUIRED)

# libPNG
find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})

# Xxf86vm (linked against by GLFW)
find_library(LIB_XXF Xxf86vm)
if (NOT LIB_XXF)
    message(FATAL_ERROR "Shared library Xxf86vm missing")
endif()

# Pthread (linked against by GLFW)
find_package(Threads REQUIRED)

# Xrandr (linked against by GLFW)
find_library(LIB_XRR Xrandr)
if (NOT LIB_XRR)
    message(FATAL_ERROR "Shared library Xrandr missing")
endif()

# Xi (linked against by GLFW)
find_library(LIB_XI Xi)
if (NOT LIB_XI)
    message(FATAL_ERROR "Shared library Xi missing")
endif()

# X11 (linked against by GLFW)
find_library(LIB_X11 X11)
if (NOT LIB_X11)
    message(FATAL_ERROR "Shared library X11 missing")
endif()

# Xinerama (linked against by X11)
find_library(LIB_XIN Xinerama)
if (NOT LIB_XIN)
    message(FATAL_ERROR "Shared library Xinerama missing")
endif()

# Xcursor (linked against by X11)
find_library(LIB_XCR Xcursor)
if (NOT LIB_XCR)
    message(FATAL_ERROR "Shared library Xcursor missing")
endif()

include_directories(../.)
add_library(GLEngineGraphics
            graphics.cpp
            window.cpp
            shader.cpp
            fragshader.cpp
            vertshader.cpp
            shaderprog.cpp
            mesh.cpp
            shaderman.cpp
            sprite.cpp
           )

target_link_libraries(GLEngineGraphics
                      ${GLFW_LIBRARIES}
                      ${GLEW_LIBRARIES}
                      ${OPENGL_LIBRARIES}
                      ${PNG_LIBRARIES}
                      ${LIB_XXF}
                      ${CMAKE_THREAD_LIBS_INIT}
                      ${LIB_XRR}
                      ${LIB_XI}
                      ${LIB_X11}
                      ${LIB_XIN}
                      ${LIB_XCR}
                     )

