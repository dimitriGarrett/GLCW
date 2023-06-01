#pragma once

#include "vec.h"

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

/*

	Provided types are bare minimum, if you want a good math library, look at GLM, it is made for OpenGL, and it is very easy to use.

	Guidelines for using your own types: 

	Vectors must have x/y/z/w for according type
	The values must be contiguous, and for the matrices they must be column-major

*/
using fvec2 = math::vec2<float>;
using dvec2 = math::vec2<double>;
using svec2 = math::vec2<short>;
using uvec2 = math::vec2<unsigned int>;
using ivec2 = math::vec2<int>;
using bvec2 = math::vec2<bool>;

using fvec3 = math::vec3<float>;
using dvec3 = math::vec3<double>;
using svec3 = math::vec3<short>;
using uvec3 = math::vec3<unsigned int>;
using ivec3 = math::vec3<int>;
using bvec3 = math::vec3<bool>;

using fvec4 = math::vec4<float>;
using dvec4 = math::vec4<double>;
using svec4 = math::vec4<short>;
using uvec4 = math::vec4<unsigned int>;
using ivec4 = math::vec4<int>;
using bvec4 = math::vec4<bool>;

using mat2 = math::matrix2;
using mat3 = math::matrix3;
using mat4 = math::matrix4;

using mat2x3 = math::matrix2x3;
using mat3x2 = math::matrix3x2;
using mat4x2 = math::matrix4x2;
using mat2x4 = math::matrix2x4;
using mat3x4 = math::matrix3x4;
using mat4x3 = math::matrix4x3;