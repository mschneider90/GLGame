subdirs(graphics sound input util)

add_library(GLEngine engine.cpp)
target_link_libraries(GLEngine GLEngineGraphics GLEngineInput GLEngineUtil)
