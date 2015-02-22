cmake_minimum_required (VERSION 3.1)

project (GLGameProject)

# Source subdirs
subdirs(engine game)

# Target C++11
add_definitions(-std=c++11)

# GLGame executable and library linkage
add_executable(GLGame main.cpp)
include_directories(${PROJECT_SOURCE_DIR})
target_link_libraries(GLGame game graphics input util)



