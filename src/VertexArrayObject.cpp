#include "VertexArrayObject.h"
#include "GL.h"

#if GL_DESKTOP || EC(3, 0)
inline void GL::bindVertexArray(unsigned int array)
{
	glBindVertexArray(array);
}

#if VC(4, 5)
	inline void GL::createVertexArrays(int n, unsigned int* arrays)
	{
		glCreateVertexArrays(n, arrays);
	}
#endif

inline void GL::deleteVertexArrays(int n, const unsigned int* arrays)
{
	glDeleteVertexArrays(n, arrays);
}

inline void GL::genVertexArrays(int n, unsigned int* arrays)
{
	glGenVertexArrays(n, arrays);
}

inline bool GL::isVertexArray(unsigned int array)
{
	return static_cast<bool>(glIsVertexArray(array));
}
#endif

#if VC(4, 5)
	inline void GL::getVertexArrayIndexed64iv(unsigned int vaobj, unsigned int index, long long* param)
	{
		glGetVertexArrayIndexed64iv(vaobj, index, GL_VERTEX_BINDING_OFFSET, param);
	}

	inline void GL::getVertexArrayIndexediv(unsigned int vaobj, unsigned int index, VertexArrayParameter pname, int* param)
	{
		glGetVertexArrayIndexediv(vaobj, index, static_cast<unsigned int>(pname), param);
	}

	inline long long GL::getVertexArrayIndexed64iv(unsigned int vaobj, unsigned int index)
	{
		long long temp;
		getVertexArrayIndexed64iv(vaobj, index, &temp);
		return temp;
	}

	inline int GL::getVertexArrayIndexediv(unsigned int vaobj, unsigned int index, VertexArrayParameter pname)
	{
		int temp;
		getVertexArrayIndexediv(vaobj, index, pname, &temp);
		return temp;
	}

	inline void GL::getVertexArrayiv(unsigned int vaobj, int* param)
	{
		glGetVertexArrayiv(vaobj, GL_ELEMENT_ARRAY_BUFFER_BINDING, param);
	}

	inline int GL::getVertexArrayiv(unsigned int vaobj)
	{
		int temp;
		getVertexArrayiv(vaobj, &temp);
		return temp;
	}
#endif
#if GL_DESKTOP
	inline void GL::getVertexAttribdv(unsigned int index, VertexAttribParameter pname, double* params)
	{
		glGetVertexAttribdv(index, static_cast<unsigned int>(pname), params);
	}

	inline double GL::getVertexAttribdv(unsigned int index, VertexAttribParameteri pname)
	{
		double temp;
		getVertexAttribdv(index, static_cast<VertexAttribParameter>(pname), &temp);
		return temp;
	}
#endif

inline void GL::getVertexAttribfv(unsigned int index, VertexAttribParameter pname, float* params)
{
	glGetVertexAttribfv(index, static_cast<unsigned int>(pname), params);
}

inline float GL::getVertexAttribfv(unsigned int index, VertexAttribParameteri pname)
{
	float temp;
	getVertexAttribfv(index, static_cast<VertexAttribParameter>(pname), &temp);
	return temp;
}

inline void GL::getVertexAttribiv(unsigned int index, VertexAttribParameter pname, int* params)
{
	glGetVertexAttribiv(index, static_cast<unsigned int>(pname), params);
}

inline int GL::getVertexAttribiv(unsigned int index, VertexAttribParameteri pname)
{
	int temp;
	getVertexAttribiv(index, static_cast<VertexAttribParameter>(pname), &temp);
	return temp;
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::getVertexAttribIiv(unsigned int index, VertexAttribParameter pname, int* params)
{
	glGetVertexAttribIiv(index, static_cast<unsigned int>(pname), params);
}

inline int GL::getVertexAttribIiv(unsigned int index, VertexAttribParameteri pname)
{
	int temp;
	getVertexAttribIiv(index, static_cast<VertexAttribParameter>(pname), &temp);
	return temp;
}

inline void GL::getVertexAttribIuiv(unsigned int index, VertexAttribParameter pname, unsigned int* params)
{
	glGetVertexAttribIuiv(index, static_cast<unsigned int>(pname), params);
}

inline unsigned int GL::getVertexAttribIuiv(unsigned int index, VertexAttribParameteri pname)
{
	unsigned int temp;
	getVertexAttribIuiv(index, static_cast<VertexAttribParameter>(pname), &temp);
	return temp;
}
#endif

#if VC(4, 1)
	inline void GL::getVertexAttribLdv(unsigned int index, VertexAttribParameter pname, double* params)
	{
		glGetVertexAttribLdv(index, static_cast<unsigned int>(pname), params);
	}

	inline double GL::getVertexAttribLdv(unsigned int index, VertexAttribParameteri pname)
	{
		double temp;
		getVertexAttribLdv(index, static_cast<VertexAttribParameter>(pname), &temp);
		return temp;
	}
#endif

inline void GL::getVertexAttribPointerv(unsigned int index, void** pointer)
{
	glGetVertexAttribPointerv(index, GL_VERTEX_ATTRIB_ARRAY_POINTER, pointer);
}

inline void* GL::getVertexAttribPointerv(unsigned int index)
{
	void* temp;
	getVertexAttribPointerv(index, &temp);
	return temp;
}

#if VC(4, 5)
	inline void GL::vertexArrayElementBuffer(unsigned int vaobj, unsigned int buffer)
	{
		glVertexArrayElementBuffer(vaobj, buffer);
	}
#endif