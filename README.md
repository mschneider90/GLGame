#GLGame

##Dependencies:
* cmake 3.1
* OpenGL (ships with graphics drivers)
* GLFW
* GLEW
* OpenAL (later)
* libpng (later)
* libvorbis (later)
* ...probably more

##Installation/Compilation:
0. Go to the build folder
  * `cd build`
1. Initial configuration (only need to do this once)
  * `cmake ../source`
2. Compiling
  * `make install`

Now bin/GLGame should be generated.

##Documentation
0. Go to the docs folder
  * `cd docs`
1. Run doxygen
  * `doxygen GLEngine.doxy`
  * `doxygen GLGame.doxy`

Now docs/GLEngine/html and docs/GLGame/html should be generated. Open index.html in your web browser to view the documentation.


