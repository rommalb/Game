# Game

I have compiled and run this project on mac using clang-602.0.53. Since I did not include the libraries in the commit one would need to follow these instructions to get it running.

# Mac Instructions
1. Download SFML source code from: http://www.sfml-dev.org/download/sfml/2.3.2/
2. Build SFML with cmake and specify native compilers to:
  - /usr/bin/clang for C and /usr/bin/clang++ for C++ compiler
3. Generate a Makefile with the default options in Cmake
4. Run make in whatever directory the generated SFML project went to
5. Copy all the libs from SFMLs lib folder to the games lib folder
6. Copy all the frameworks from the SFML source download extlibs/libs-osx/Frameworks/ to your Frameworks directory
7. Run make in this directory and run the game

# Linux Instrunctions
These instructions should be very similar to the Mac instructions but without the frameworks. You'll want to generate .so files and copy them into lib. You may need to download SFMLs dependencies, OpenGL, etc if your distro of linux doesn't have them. I will need to test this on my Ubuntu distro and update the readme.
