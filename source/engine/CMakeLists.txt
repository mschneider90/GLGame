subdirs(graphics input sound networking util)

add_library(GLEngine engine.cpp)
target_link_libraries(GLEngine GLEngineGraphics GLEngineInput GLEngineUtil)
