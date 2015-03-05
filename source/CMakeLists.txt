cmake_minimum_required(VERSION 3.1)

project(GLGameProject)

# Source subdirs
subdirs(engine game)

# Target C++11 for gcc
# cmake has built in support to do this but I can't get it to work
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions(-std=c++11)
endif()

# GLGame executable and library linkage
add_executable(GLGame ./game/src/main.cpp ./game/src/game.cpp)
include_directories(${PROJECT_SOURCE_DIR})
target_link_libraries(GLGame GLEngine)

# Copy the executable to the bin/ folder
install( PROGRAMS ${CMAKE_BINARY_DIR}/GLGame DESTINATION ${CMAKE_BINARY_DIR}/../bin/ )

# Copy data folder to the bin/ folder
install( DIRECTORY ${PROJECT_SOURCE_DIR}/game/data DESTINATION ${CMAKE_BINARY_DIR}/../bin/ )




