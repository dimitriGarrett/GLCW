# GLCW

# Forewarning
GLCW is only an OpenGL wrapper! That means that this does not have a windowing library! (if you need one, GLW might suit your needs)

# Dependencies
GLCW requires the CTI library (submodule already included), GLM library (submodule already included), and GLEW. GLEW libraries are included, but if you have different ones, by all means use those. 

# Support
GLCW is a OpenGL wrapper that has support for OpenGL 3.3 to 4.5, and OpenGL ES 2.0, 3.0, and 3.1.

To change the version, go to Config.h, and change the GL_VERSION_MAJOR, and GL_VERSION_MINOR values. Change GL_DESKTOP to signal use of OpenGL ES, or not.

# C++17
C++17 is required, because the library heavily uses std::string_view, but support in the future may be added for any other version, by removing std::string_view with something else.

# Example

```
#include "GLCW.h"

int main()
{
    //create a window...

    unsigned int texture;
    GL::genTextures(1, &texture);
    GL::bindTexture(GL::TEXTURE_2D, texture);

    //use the texture...

    while (window.open())
    {
        GL::clear(1.0f, 0.0f, 0.0f, 1.0f);

        //draw...

        //clear window...
    }
}
```
