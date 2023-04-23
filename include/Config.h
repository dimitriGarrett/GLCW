#pragma once

#define GL_DESKTOP true

#define GL_VERSION_MAJOR 4
#define GL_VERSION_MINOR 5

#if GL_DESKTOP
	#if GL_VERSION_MAJOR < 3 || (GL_VERSION_MAJOR == 3 && GL_VERSION_MINOR < 3)
		#error "GLCW does not target opengl below 3.3! (must use modern GL!)"
	#endif

	#define VC(major, minor) ((GL_VERSION_MAJOR >= major) && (GL_VERSION_MINOR >= minor))
	#define EC(major, minor) false

#else
	#if (GL_VERSION_MAJOR != 2 && GL_VERSION_MAJOR != 3) || (GL_VERSION_MAJOR == 2 && GL_VERSION_MINOR != 0) || (GL_VERSION_MAJOR == 3 && GL_VERSION_MINOR > 2)
		#error "GLCW only supports OpenGL ES 2.0, 3.0, and 3.1!"
	#endif

	#define VC(major, minor) false
	#define EC(major, minor) ((GL_VERSION_MAJOR >= major) && (GL_VERSION_MINOR >= minor))

#endif