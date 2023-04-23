#pragma once

#include "API.h"
#include "Config.h"

namespace GL
{
#if VC(4, 5)
	enum class VertexArrayParameter : unsigned int
	{
		VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622,
		VERTEX_ATTRIB_ARRAY_SIZE = 0x8623,
		VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624,
		VERTEX_ATTRIB_ARRAY_TYPE = 0x8625,
		VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
		VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD,
		VERTEX_ATTRIB_ARRAY_LONG = 0x874E,
		VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE,
		VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5
	};
#endif

	enum class VertexAttribParameter : unsigned int
	{
		VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
		VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622,
		VERTEX_ATTRIB_ARRAY_SIZE = 0x8623,
		VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624,
		VERTEX_ATTRIB_ARRAY_TYPE = 0x8625,
		VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
		VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD,
		VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE,
		CURRENT_VERTEX_ATTRIB = 0x8626
	};

	enum class VertexAttribParameteri : unsigned int
	{
		VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
		VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622,
		VERTEX_ATTRIB_ARRAY_SIZE = 0x8623,
		VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624,
		VERTEX_ATTRIB_ARRAY_TYPE = 0x8625,
		VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
		VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD,
		VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE
	};

#if GL_DESKTOP || EC(3, 0)
	//glBindVertexArray — bind a vertex array object
	GLCW_API void bindVertexArray(unsigned int array);

#if VC(4, 5)
	//glCreateVertexArrays — create vertex array objects
	GLCW_API void createVertexArrays(int n, unsigned int* arrays);
#endif

	//glDeleteVertexArrays — delete vertex array objects
	GLCW_API void deleteVertexArrays(int n, const unsigned int* arrays);

	//glGenVertexArrays — generate vertex array object names
	GLCW_API void genVertexArrays(int n, unsigned int* arrays);

	//glIsVertexArray — determine if a name corresponds to a vertex array object
	GLCW_API bool isVertexArray(unsigned int array);
#endif

#if VC(4, 5)
	//glGetVertexArrayIndexed — retrieve parameters of an attribute of a vertex array object
	GLCW_API void getVertexArrayIndexed64iv(unsigned int vaobj, unsigned int index, /*VertexArrayParameter pname, MUST BE VERTEX_BINDING_OFFSET*/ long long* param);
	//glGetVertexArrayIndexed — retrieve parameters of an attribute of a vertex array object
	GLCW_API void getVertexArrayIndexediv(unsigned int vaobj, unsigned int index, VertexArrayParameter pname, int* param);
	//glGetVertexArrayIndexed — retrieve parameters of an attribute of a vertex array object
	GLCW_API long long getVertexArrayIndexed64iv(unsigned int vaobj, unsigned int index/*VertexArrayParameter pname, MUST BE VERTEX_BINDING_OFFSET*/);
	//glGetVertexArrayIndexed — retrieve parameters of an attribute of a vertex array object
	GLCW_API int getVertexArrayIndexediv(unsigned int vaobj, unsigned int index, VertexArrayParameter pname);

	//glGetVertexArrayiv — retrieve parameters of a vertex array object
	GLCW_API void getVertexArrayiv(unsigned int vaobj, /*GL_ELEMENT_ARRAY_BUFFER_BINDING*/ int* param);
	//glGetVertexArrayiv — retrieve parameters of a vertex array object
	GLCW_API int getVertexArrayiv(unsigned int vaobj/*GL_ELEMENT_ARRAY_BUFFER_BINDING*/);
#endif
#if GL_DESKTOP
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribdv(unsigned int index, VertexAttribParameter pname, double* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API double getVertexAttribdv(unsigned int index, VertexAttribParameteri pname);
#endif
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribfv(unsigned int index, VertexAttribParameter pname, float* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API float getVertexAttribfv(unsigned int index, VertexAttribParameteri pname);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribiv(unsigned int index, VertexAttribParameter pname, int* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API int getVertexAttribiv(unsigned int index, VertexAttribParameteri pname);

#if GL_DESKTOP || EC(3, 0)
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribIiv(unsigned int index, VertexAttribParameter pname, int* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API int getVertexAttribIiv(unsigned int index, VertexAttribParameteri pname);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribIuiv(unsigned int index, VertexAttribParameter pname, unsigned int* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API unsigned int getVertexAttribIuiv(unsigned int index, VertexAttribParameteri pname);
#endif

#if VC(4, 1)
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribLdv(unsigned int index, VertexAttribParameter pname, double* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API double getVertexAttribLdv(unsigned int index, VertexAttribParameteri pname);
#endif

	//glGetVertexAttribPointerv — return the address of the specified generic vertex attribute pointer
	GLCW_API void getVertexAttribPointerv(unsigned int index, /*GL_VERTEX_ATTRIB_ARRAY_POINTER,*/ void** pointer);
	//glGetVertexAttribPointerv — return the address of the specified generic vertex attribute pointer
	GLCW_API void* getVertexAttribPointerv(unsigned int index/*GL_VERTEX_ATTRIB_ARRAY_POINTER,*/);

#if VC(4, 5)
	//glVertexArrayElementBuffer — configures element array buffer binding of a vertex array object
	GLCW_API void vertexArrayElementBuffer(unsigned int vaobj, unsigned int buffer);
#endif
}