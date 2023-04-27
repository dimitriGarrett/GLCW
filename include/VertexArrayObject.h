#pragma once

#include "API.h"
#include "Enums.h"

namespace GL
{
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
	GLCW_API void getVertexArrayIndexediv(unsigned int vaobj, unsigned int index, GL_ENUM pname, int* param);
	//glGetVertexArrayIndexed — retrieve parameters of an attribute of a vertex array object
	GLCW_API long long getVertexArrayIndexed64iv(unsigned int vaobj, unsigned int index/*VertexArrayParameter pname, MUST BE VERTEX_BINDING_OFFSET*/);
	//glGetVertexArrayIndexed — retrieve parameters of an attribute of a vertex array object
	GLCW_API int getVertexArrayIndexediv(unsigned int vaobj, unsigned int index, GL_ENUM pname);

	//glGetVertexArrayiv — retrieve parameters of a vertex array object
	GLCW_API void getVertexArrayiv(unsigned int vaobj, /*GL_ELEMENT_ARRAY_BUFFER_BINDING*/ int* param);
	//glGetVertexArrayiv — retrieve parameters of a vertex array object
	GLCW_API int getVertexArrayiv(unsigned int vaobj/*GL_ELEMENT_ARRAY_BUFFER_BINDING*/);
#endif
#if GL_DESKTOP
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribdv(unsigned int index, GL_ENUM pname, double* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API double getVertexAttribdv(unsigned int index, GL_ENUM pname);
#endif
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribfv(unsigned int index, GL_ENUM pname, float* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API float getVertexAttribfv(unsigned int index, GL_ENUM pname);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribiv(unsigned int index, GL_ENUM pname, int* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API int getVertexAttribiv(unsigned int index, GL_ENUM pname);

#if GL_DESKTOP || EC(3, 0)
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribIiv(unsigned int index, GL_ENUM pname, int* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API int getVertexAttribIiv(unsigned int index, GL_ENUM pname);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribIuiv(unsigned int index, GL_ENUM pname, unsigned int* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API unsigned int getVertexAttribIuiv(unsigned int index, GL_ENUM pname);
#endif

#if VC(4, 1)
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API void getVertexAttribLdv(unsigned int index, GL_ENUM pname, double* params);
	//glGetVertexAttrib — Return a generic vertex attribute parameter
	GLCW_API double getVertexAttribLdv(unsigned int index, GL_ENUM pname);
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