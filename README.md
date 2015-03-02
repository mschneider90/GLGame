#GLGame

##Dependencies:
* cmake 3.1
* OpenGL (ships with graphics drivers)
* GLFW
* GLEW
* libpng
* OpenAL (later)
* libvorbis (later)
* ...probably more

##Compilation and Installation:
0. Go to the build directory
  * `cd build`
1. Initial configuration (only need to do this once)
  * `cmake ../source`
2. Compilation
  * `make`
  * Now build/GLGame should be generated.
3. Installation
  * `make install`
  * Now bin/GLGame should be generated, along with all data files necessary.
  
GLGame can then be run from the bin/ directory.

##Documentation
0. Go to the docs directory
  * `cd docs`
1. Run doxygen
  * `doxygen GLEngine.doxy`
  * `doxygen GLGame.doxy`

Now contents of docs/GLEngine/ and docs/GLGame/ should be generated. Open index.html in your web browser to view the documentation.


