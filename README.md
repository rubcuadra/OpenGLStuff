# OpenGLStuff
here I'll upload some C/C++ code using Glut/Glew/Freeglut/etc (Computer Graphics Topic)

All the codes are written from a Macbook Pro late 2016 with an AMD Radeon Pro 460 .OpenGL version supported 2.1 ATI-1.48.21

If you are using Xcode (I really recommend to use it) you must create a new project depending if you plan to write using C or C++
After that you must open the .xcodeproj(All from the Xcode IDE) and go:

  General > Linked Frameworks and Libraries > Add OpenGL.framework
  General > Linked Frameworks and Libraries > Add GLUT.framework (If you plan to use freeglut or other then don't add this)

This are steps if you use homebrew, it is really easy to install stuff like freeglut, glew, X11, blablabla with it. If you plan to use any of them then add this to your xcode project

  Build Settings > Search Paths > Header Search Paths : /usr/local/include
  Build Settings > Search Paths > Library Search Paths : /usr/local/lib
  
At the end we must say to xcode to add some libraries (By flags) when compiling the code:
  Build Settings > Linking > Other Linker Flags > -lGLEW
  Build Settings > Linking > Other Linker Flags > -lglut

And if you plan to use more then you add them here, if you are not planning to use glew then you could simply remove it, it my crash if you say that you'll use it and you dont have it installed
