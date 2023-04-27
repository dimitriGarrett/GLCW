#include "BufferObject.h"
#include "GL.h"

#if VC(4, 4)
inline void GL::detail::bufferStorage(GL_ENUM target, sizeiptr size, const void* data, unsigned int flags)
{
	glBufferStorage(static_cast<unsigned int>(target), size, data, flags);
}
#endif
#if VC(4, 5)
inline void GL::detail::namedBufferStorage(unsigned int buffer, sizeiptr size, const void* data, unsigned int flags)
{
	glNamedBufferStorage(buffer, size, data, flags);
}
#endif

inline void GL::bindBuffer(GL_ENUM target, unsigned int buffer)
{
	glBindBuffer(static_cast<unsigned int>(target), buffer);
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::bindBufferBase(GL_ENUM target, unsigned int index, unsigned int buffer)
{
	glBindBufferBase(static_cast<unsigned int>(target), index, buffer);
}

inline void GL::bindBufferRange(GL_ENUM target, unsigned int index, unsigned int buffer, sizeiptr offset, sizeiptr size)
{
	glBindBufferRange(static_cast<unsigned int>(target), index, buffer, offset, size);
}
#endif

#if VC(4, 4) 
inline void GL::bindBuffersBase(GL_ENUM target, unsigned int first, int count, const unsigned int* buffers)
{
	glBindBuffersBase(static_cast<unsigned int>(target), first, count, buffers);
}

inline void GL::bindBuffersRange(GL_ENUM target, unsigned int first, int count, const unsigned int* buffers, const sizeiptr* offset, const sizeiptr* sizes)
{
	glBindBuffersRange(static_cast<unsigned int>(target), first, count, buffers, offset, sizes);
}

inline void GL::bindBuffersRange(GL_ENUM target, unsigned int first, const std::vector<unsigned int>& buffers, const std::vector<sizeiptr>& offset, const std::vector<sizeiptr>& sizes)
{
	glBindBuffersRange(static_cast<unsigned int>(target), first, static_cast<int>(buffers.size()), buffers.data(), offset.data(), sizes.data());
}
#endif
#if VC(4, 3) || EC(3, 1)
inline void GL::bindVertexBuffer(unsigned int bindingindex, unsigned int buffer, sizeiptr offset, int stride)
{
	glBindVertexBuffer(bindingindex, buffer, offset, stride);
}
#endif
#if VC(4, 5) 
inline void GL::vertexArrayVertexBuffer(unsigned int vaobj, unsigned int bindingindex, unsigned int buffer, sizeiptr offset, int stride)
{
	glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
}
#endif
#if VC(4, 4) 
inline void GL::bindVertexBuffers(unsigned int first, int count, const unsigned int* buffers, const sizeiptr* offsets, const int* strides)
{
	glBindVertexBuffers(first, count, buffers, offsets, strides);
}

inline void GL::bindVertexBuffers(unsigned int first, const std::vector<unsigned int>& buffers, const std::vector<sizeiptr>& offsets, const std::vector<int>& strides)
{
	glBindVertexBuffers(first, static_cast<int>(buffers.size()), buffers.data(), offsets.data(), strides.data());
}
#endif
#if VC(4, 5) 
inline void GL::vertexArrayVertexBuffers(unsigned int vaobj, unsigned int first, int count, const unsigned int* buffers, const sizeiptr* offsets, const int* strides)
{
	glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides);
}

inline void GL::vertexArrayVertexBuffers(unsigned int vaobj, unsigned int first, const std::vector<unsigned int>& buffers, const std::vector<sizeiptr>& offsets, const std::vector<int>& strides)
{
	glVertexArrayVertexBuffers(vaobj, first, static_cast<int>(buffers.size()), buffers.data(), offsets.data(), strides.data());
}
#endif

inline void GL::bufferData(GL_ENUM target, sizeiptr size, const void* data, GL_ENUM usage)
{
	glBufferData(static_cast<unsigned int>(target), size, data, static_cast<unsigned int>(usage));
}

#if VC(4, 5) 
inline void GL::namedBufferData(unsigned int buffer, sizeiptr size, const void* data, GL_ENUM usage)
{
	glNamedBufferData(buffer, size, data, static_cast<unsigned int>(usage));
}
#endif

inline void GL::bufferSubData(GL_ENUM target, sizeiptr offset, sizeiptr size, const void* data)
{
	glBufferSubData(static_cast<unsigned int>(target), offset, size, data);
}

#if VC(4, 5)
	inline void GL::namedBufferSubData(unsigned int buffer, sizeiptr offset, sizeiptr size, const void* data)
	{
		glNamedBufferSubData(buffer, offset, size, data);
	}
#endif
#if VC(4, 3)
	inline void GL::clearBufferData(GL_ENUM target, GL_ENUM internalformat, GL::GL_ENUM format, GL::GL_ENUM type, const void* data)
	{
		glClearBufferData(static_cast<unsigned int>(target), static_cast<unsigned int>(internalformat), static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
	}
#endif
#if VC(4, 5)
	inline void GL::clearNamedBufferData(unsigned int buffer, GL_ENUM internalformat, GL_ENUM format, GL_ENUM type, const void* data)
	{
		glClearBufferData(buffer, static_cast<unsigned int>(internalformat), static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
	}
#endif
#if VC(4, 3)
	inline void GL::clearBufferSubData(GL_ENUM target, GL_ENUM internalformat, sizeiptr offset, sizeiptr size, GL_ENUM format, GL_ENUM type, const void* data)
	{
		glClearBufferSubData(static_cast<unsigned int>(target), static_cast<unsigned int>(internalformat), offset, size, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
	}
#endif
#if VC(4, 5)
	inline void GL::clearNamedBufferSubData(unsigned int buffer, GL_ENUM internalformat, sizeiptr offset, sizeiptr size, GL_ENUM format, GL_ENUM type, const void* data)
	{
		glClearNamedBufferSubData(buffer, static_cast<unsigned int>(internalformat), offset, size, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::copyBufferSubData(GL_ENUM readTarget, GL_ENUM writeTarget, sizeiptr readOffset, sizeiptr writeOffset, sizeiptr size)
{
	glCopyBufferSubData(static_cast<unsigned int>(readTarget), static_cast<unsigned int>(writeTarget), readOffset, writeOffset, size);
}
#endif

#if VC(4, 5)
	inline void GL::copyNamedBufferSubData(unsigned int readBuffer, unsigned int writeBuffer, sizeiptr readOffset, sizeiptr writeOffset, sizeiptr size)
	{
		glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
	}

	inline void GL::createBuffers(int n, unsigned int* buffers)
	{
		glCreateBuffers(n, buffers);
	}
#endif

inline void GL::deleteBuffers(int n, const unsigned int* buffers)
{
	glDeleteBuffers(n, buffers);
}

inline void GL::drawArrays(GL_ENUM mode, int first, int count)
{
	glDrawArrays(static_cast<unsigned int>(mode), first, count);
}

#if VC(4, 0) || EC(3, 1)
inline void GL::drawArraysIndirect(GL_ENUM mode, const void* indirect)
{
	glDrawArraysIndirect(static_cast<unsigned int>(mode), indirect);
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::drawArraysInstanced(GL_ENUM mode, int first, int count, int primcount)
{
	glDrawArraysInstanced(static_cast<unsigned int>(mode), first, count, primcount);
}
#endif

#if VC(4, 2)
inline void GL::drawArraysInstancedBaseInstance(GL_ENUM mode, int first, int count, int primcount, unsigned int baseinstance)
{
	glDrawArraysInstancedBaseInstance(static_cast<unsigned int>(mode), first, count, primcount, baseinstance);
}
#endif

inline void GL::drawElements(GL_ENUM mode, int count, GL_ENUM type, const void* indices)
{
	glDrawElements(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices);
}

#if GL_DESKTOP
inline void GL::drawElementsBaseVertex(GL_ENUM mode, int count, GL_ENUM type, void* indices, int basevertex)
{
	glDrawElementsBaseVertex(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices, basevertex);
}
#endif

#if VC(4, 0) || EC(3, 1)
	inline void GL::drawElementsIndirect(GL_ENUM mode, GL_ENUM type, const void* indirect)
	{
		glDrawElementsIndirect(static_cast<unsigned int>(mode), static_cast<unsigned int>(type), indirect);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::drawElementsInstanced(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount)
{
	glDrawElementsInstanced(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices, primcount);
}
#endif

#if VC(4, 2)
	inline void GL::drawElementsInstancedBaseInstance(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount, unsigned int baseinstance)
	{
		glDrawElementsInstancedBaseInstance(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices, primcount, baseinstance);
	}
#endif

#if GL_DESKTOP
inline void GL::drawElementsInstancedBaseVertex(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount, int basevertex)
{
	glDrawElementsInstancedBaseVertex(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices, primcount, basevertex);
}
#endif

#if VC(4, 2)
	inline void GL::drawElementsInstancedBaseVertexBaseInstance(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount, int basevertex, unsigned int baseinstance)
	{
		glDrawElementsInstancedBaseVertexBaseInstance(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices, primcount, basevertex, baseinstance);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::drawRangeElements(GL_ENUM mode, unsigned int start, unsigned int end, int count, GL_ENUM type, const void* indices)
{
	glDrawRangeElements(static_cast<unsigned int>(mode), start, end, count, static_cast<unsigned int>(type), indices);
}
#endif

#if GL_DESKTOP
inline void GL::drawRangeElementsBaseVertex(GL_ENUM mode, unsigned int start, unsigned int end, int count, GL_ENUM type, void* indices, int basevertex)
{
	glDrawRangeElementsBaseVertex(static_cast<unsigned int>(mode), start, end, count, static_cast<unsigned int>(type), indices, basevertex);
}
#endif

inline void GL::enableVertexAttribArray(unsigned int index)
{
	glEnableVertexAttribArray(index);
}

inline void GL::disableVertexAttribArray(unsigned int index)
{
	glDisableVertexAttribArray(index);
}

#if VC(4, 5)
	inline void GL::enableVertexArrayAttrib(unsigned int vaobj, unsigned int index)
	{
		glEnableVertexArrayAttrib(vaobj, index);
	}

	inline void GL::disableVertexArrayAttrib(unsigned int vaobj, unsigned int index)
	{
		glDisableVertexArrayAttrib(vaobj, index);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::flushMappedBufferRange(GL_ENUM target, sizeiptr offset, sizeiptr length)
{
	glFlushMappedBufferRange(static_cast<unsigned int>(target), offset, length);
}
#endif

#if VC(4, 5)
	inline void GL::flushMappedNamedBufferRange(unsigned int buffer, sizeiptr offset, sizeiptr length)
	{
		glFlushMappedNamedBufferRange(buffer, offset, length);
	}
#endif

inline void GL::genBuffers(int n, unsigned int* buffers)
{
	glGenBuffers(n, buffers);
}

inline void GL::getBufferParameteriv(GL_ENUM target, GL_ENUM value, int* data)
{
	glGetBufferParameteriv(static_cast<unsigned int>(target), static_cast<unsigned int>(value), data);
}

inline int GL::getBufferParameteriv(GL_ENUM target, GL_ENUM value)
{
	int temp;
	getBufferParameteriv(target, value, &temp);
	return temp;
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::getBufferParameteri64v(GL_ENUM target, GL_ENUM value, long long* data)
{
	glGetBufferParameteri64v(static_cast<unsigned int>(target), static_cast<unsigned int>(value), data);
}

inline long long GL::getBufferParameteri64v(GL_ENUM target, GL_ENUM value)
{
	long long temp;
	getBufferParameteri64v(target, value, &temp);
	return temp;
}
#endif

#if VC(4, 5)
	inline void GL::getNamedBufferParameteriv(unsigned int buffer, GL_ENUM value, int* data)
	{
		glGetNamedBufferParameteriv(buffer, static_cast<unsigned int>(value), data);
	}

	inline int GL::getNamedBufferParameteriv(unsigned int buffer, GL_ENUM value)
	{
		int temp;
		getNamedBufferParameteriv(buffer, value, &temp);
		return temp;
	}

	inline void GL::getNamedBufferParameteri64v(unsigned int buffer, GL_ENUM value, long long* data)
	{
		glGetNamedBufferParameteri64v(buffer, static_cast<unsigned int>(value), data);
	}

	inline long long GL::getNamedBufferParameteri64v(unsigned int buffer, GL_ENUM value)
	{
		long long temp;
		getNamedBufferParameteri64v(buffer, value, &temp);
		return temp;
	}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::getBufferPointerv(GL_ENUM target, void** params)
{
	glGetBufferPointerv(static_cast<unsigned int>(target), GL_BUFFER_MAP_POINTER, params);
}

inline void* GL::getBufferPointerv(GL_ENUM target)
{
	void* temp;
	getBufferPointerv(target, &temp);
	return temp;
}
#endif

#if VC(4, 5)
	inline void GL::getNamedBufferPointerv(unsigned int buffer, void** params)
	{
		glGetNamedBufferPointerv(buffer, GL_BUFFER_MAP_POINTER, params);
	}

	inline void* GL::getNamedBufferPointerv(unsigned int buffer)
	{
		void* temp;
		getNamedBufferPointerv(buffer, &temp);
		return temp;
	}
#endif

#if GL_DESKTOP
inline void GL::getBufferSubData(GL_ENUM target, sizeiptr offset, sizeiptr size, void* data)
{
	glGetBufferSubData(static_cast<unsigned int>(target), offset, size, data);
}
#endif

#if VC(4, 5)
	inline void GL::getNamedBufferSubData(unsigned int buffer, sizeiptr offset, sizeiptr size, void* data)
	{
		glGetNamedBufferSubData(buffer, offset, size, data);
	}
#endif
#if VC(4, 3)
	inline void GL::invalidateBufferData(unsigned int buffer)
	{
		glInvalidateBufferData(buffer);
	}

	inline void GL::invalidateBufferSubData(unsigned int buffer, sizeiptr offset, sizeiptr length)
	{
		glInvalidateBufferSubData(buffer, offset, length);
	}
#endif

inline bool GL::isBuffer(unsigned int buffer)
{
	return glIsBuffer(buffer);
}

#if GL_DESKTOP
inline void* GL::mapBuffer(GL_ENUM target, GL_ENUM access)
{
	return glMapBuffer(static_cast<unsigned int>(target), static_cast<unsigned int>(access));
}
#endif

#if VC(4, 5)
	inline void* GL::mapNamedBuffer(unsigned int buffer, GL_ENUM access)
	{
		return glMapNamedBuffer(buffer, static_cast<unsigned int>(access));
	}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void* GL::mapBufferRange(GL_ENUM target, sizeiptr offset, sizeiptr length, GL_ENUM access)
{
	return glMapBufferRange(static_cast<unsigned int>(target), offset, length, static_cast<unsigned int>(access));
}
#endif

#if VC(4, 5)
	inline void* GL::mapNamedBufferRange(unsigned int buffer, sizeiptr offset, sizeiptr length, GL_ENUM access)
	{
		return glMapNamedBufferRange(buffer, offset, length, static_cast<unsigned int>(access));
	}
#endif

#if GL_DESKTOP
inline void GL::multiDrawArrays(GL_ENUM mode, const int* first, const int* count, int drawcount)
{
	glMultiDrawArrays(static_cast<unsigned int>(mode), first, count, drawcount);
}
#endif

#if VC(4, 3)
	inline void GL::multiDrawArraysIndirect(GL_ENUM mode, const void* indirect, int drawcount, int stride)
	{
		glMultiDrawArraysIndirect(static_cast<unsigned int>(mode), indirect, drawcount, stride);
	}
#endif

#if GL_DESKTOP
inline void GL::multiDrawElements(GL_ENUM mode, const int* count, GL_ENUM type, const void* const* indices, int drawcount)
{
	glMultiDrawElements(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices, drawcount);
}

inline void GL::multiDrawElementsBaseVertex(GL_ENUM mode, int* count, GL_ENUM type, void** indices, int drawcount, int* basevertex)
{
	glMultiDrawElementsBaseVertex(static_cast<unsigned int>(mode), count, static_cast<unsigned int>(type), indices, drawcount, basevertex);
}
#endif

#if VC(4, 3)
	inline void GL::multiDrawElementsIndirect(GL_ENUM mode, GL_ENUM type, const void* indirect, int drawcount, int stride)
	{
		glMultiDrawElementsIndirect(static_cast<unsigned int>(mode), static_cast<unsigned int>(type), indirect, drawcount, stride);
	}
#endif
#if VC(4, 0)
	inline void GL::patchParameteri(GL_ENUM pname, int value)
	{
		glPatchParameteri(static_cast<unsigned int>(pname), value);
	}

	inline void GL::patchParameterfv(GL_ENUM pname, const float* values)
	{
		glPatchParameterfv(static_cast<unsigned int>(pname), values);
	}
#endif

#if GL_DESKTOP
inline void GL::primitiveRestartIndex(unsigned int index)
{
	glPrimitiveRestartIndex(index);
}

inline void GL::provokingVertex(GL_ENUM provokeMode)
{
	glProvokingVertex(static_cast<unsigned int>(provokeMode));
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline bool GL::unmapBuffer(GL_ENUM target)
{
	return glUnmapBuffer(static_cast<unsigned int>(target));
}
#endif

#if VC(4, 5)
	inline bool GL::unmapNamedBuffer(unsigned int buffer)
	{
		return glUnmapNamedBuffer(buffer);
	}
#endif

inline void GL::vertexAttrib1f(unsigned int index, float v0)
{
	glVertexAttrib1f(index, v0);
}

#if GL_DESKTOP
inline void GL::vertexAttrib1s(unsigned int index, short v0)
{
	glVertexAttrib1s(index, v0);
}

inline void GL::vertexAttrib1d(unsigned int index, double v0)
{
	glVertexAttrib1d(index, v0);
}

inline void GL::vertexAttribI1i(unsigned int index, int v0)
{
	glVertexAttribI1i(index, v0);
}

inline void GL::vertexAttribI1ui(unsigned int index, unsigned int v0)
{
	glVertexAttribI1ui(index, v0);
}
#endif

inline void GL::vertexAttrib2f(unsigned int index, int v0, int v1)
{
	glVertexAttrib2f(index, v0, v1);
}

inline void GL::vertexAttrib2f(unsigned int index, const glm::vec2& v)
{
	glVertexAttrib2f(index, v.x, v.y);
}

#if GL_DESKTOP
inline void GL::vertexAttrib2s(unsigned int index, short v0, short v1)
{
	glVertexAttrib2s(index, v0, v1);
}

inline void GL::vertexAttrib2s(unsigned int index, const glm::vec<2, short>& v)
{
	glVertexAttrib2s(index, v.x, v.y);
}

inline void GL::vertexAttrib2d(unsigned int index, double v0, double v1)
{
	glVertexAttrib2d(index, v0, v1);
}

inline void GL::vertexAttrib2d(unsigned int index, const glm::dvec2& v)
{
	glVertexAttrib2d(index, v.x, v.y);
}
inline void GL::vertexAttribI2i(unsigned int index, int v0, int v1)
{
	glVertexAttribI2i(index, v0, v1);
}

inline void GL::vertexAttribI2i(unsigned int index, const glm::ivec2& v)
{
	glVertexAttribI2i(index, v.x, v.y);
}

inline void GL::vertexAttribI2ui(unsigned int index, unsigned int v0, unsigned int v1)
{
	glVertexAttribI2ui(index, v0, v1);
}

inline void GL::vertexAttribI2ui(unsigned int index, const glm::uvec2& v)
{
	glVertexAttribI2ui(index, v.x, v.y);
}
#endif

inline void GL::vertexAttrib3f(unsigned int index, int v0, int v1, int v2)
{
	glVertexAttrib3f(index, v0, v1, v2);
}

inline void GL::vertexAttrib3f(unsigned int index, const glm::vec3& v)
{
	glVertexAttrib3f(index, v.x, v.y, v.z);
}

#if GL_DESKTOP
inline void GL::vertexAttrib3s(unsigned int index, short v0, short v1, short v2)
{
	glVertexAttrib3s(index, v0, v1, v2);
}

inline void GL::vertexAttrib3s(unsigned int index, const glm::vec<3, short>& v)
{
	glVertexAttrib3s(index, v.x, v.y, v.z);
}

inline void GL::vertexAttrib3d(unsigned int index, double v0, double v1, double v2)
{
	glVertexAttrib3d(index, v0, v1, v2);
}

inline void GL::vertexAttrib3d(unsigned int index, const glm::dvec3& v)
{
	glVertexAttrib3d(index, v.x, v.y, v.z);
}

inline void GL::vertexAttribI3i(unsigned int index, int v0, int v1, int v2)
{
	glVertexAttribI3i(index, v0, v1, v2);
}

inline void GL::vertexAttribI3i(unsigned int index, const glm::ivec3& v)
{
	glVertexAttribI3i(index, v.x, v.y, v.z);
}

inline void GL::vertexAttribI3ui(unsigned int index, unsigned int v0, unsigned int v1, unsigned int v2)
{
	glVertexAttribI3ui(index, v0, v1, v2);
}

inline void GL::vertexAttribI3ui(unsigned int index, const glm::uvec3& v)
{
	glVertexAttribI3ui(index, v.x, v.y, v.z);
}
#endif

inline void GL::vertexAttrib4f(unsigned int index, int v0, int v1, int v2, int v3)
{
	glVertexAttrib4f(index, v0, v1, v2, v3);
}

inline void GL::vertexAttrib4f(unsigned int index, const glm::vec4& v)
{
	glVertexAttrib4f(index, v.x, v.y, v.z, v.w);
}

#if GL_DESKTOP
inline void GL::vertexAttrib4s(unsigned int index, short v0, short v1, short v2, short v3)
{
	glVertexAttrib4s(index, v0, v1, v2, v3);
}

inline void GL::vertexAttrib4s(unsigned int index, const glm::vec<4, short>& v)
{
	glVertexAttrib4s(index, v.x, v.y, v.z, v.w);
}

inline void GL::vertexAttrib4d(unsigned int index, double v0, double v1, double v2, double v3)
{
	glVertexAttrib4d(index, v0, v1, v2, v3);
}

inline void GL::vertexAttrib4d(unsigned int index, const glm::dvec4& v)
{
	glVertexAttrib4d(index, v.x, v.y, v.z, v.w);
}

inline void GL::vertexAttribI4i(unsigned int index, int v0, int v1, int v2, int v3)
{
	glVertexAttribI4i(index, v0, v1, v2, v3);
}

inline void GL::vertexAttribI4i(unsigned int index, const glm::ivec4& v)
{
	glVertexAttribI4i(index, v.x, v.y, v.z, v.w);
}

inline void GL::vertexAttribI4ui(unsigned int index, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
{
	glVertexAttribI4ui(index, v0, v1, v2, v3);
}

inline void GL::vertexAttribI4ui(unsigned int index, const glm::uvec4& v)
{
	glVertexAttribI4ui(index, v.x, v.y, v.z, v.w);
}

inline void GL::vertexAttrib1fv(unsigned int index, const float* v)
{
	glVertexAttrib1fv(index, v);
}
#endif

#if GL_DESKTOP
inline void GL::vertexAttrib1sv(unsigned int index, const short* v)
{
	glVertexAttrib1sv(index, v);
}

inline void GL::vertexAttrib1dv(unsigned int index, const double* v)
{
	glVertexAttrib1dv(index, v);
}

inline void GL::vertexAttribI1iv(unsigned int index, const int* v)
{
	glVertexAttribI1iv(index, v);
}

inline void GL::vertexAttribI1uiv(unsigned int index, const unsigned int* v)
{
	glVertexAttribI1uiv(index, v);
}

inline void GL::vertexAttrib2fv(unsigned int index, const float* v)
{
	glVertexAttrib2fv(index, v);
}

inline void GL::vertexAttrib2sv(unsigned int index, const short* v)
{
	glVertexAttrib2sv(index, v);
}

inline void GL::vertexAttrib2dv(unsigned int index, const double* v)
{
	glVertexAttrib2dv(index, v);
}

inline void GL::vertexAttribI2iv(unsigned int index, const int* v)
{
	glVertexAttribI2iv(index, v);
}

inline void GL::vertexAttribI2uiv(unsigned int index, const unsigned int* v)
{
	glVertexAttribI2uiv(index, v);
}
#endif

inline void GL::vertexAttrib3fv(unsigned int index, const float* v)
{
	glVertexAttrib3fv(index, v);
}

#if GL_DESKTOP
inline void GL::vertexAttrib3sv(unsigned int index, const short* v)
{
	glVertexAttrib3sv(index, v);
}

inline void GL::vertexAttrib3dv(unsigned int index, const double* v)
{
	glVertexAttrib3dv(index, v);
}

inline void GL::vertexAttribI3iv(unsigned int index, const int* v)
{
	glVertexAttribI3iv(index, v);
}

inline void GL::vertexAttribI3uiv(unsigned int index, const unsigned int* v)
{
	glVertexAttribI3uiv(index, v);
}
#endif

inline void GL::vertexAttrib4fv(unsigned int index, const float* v)
{
	glVertexAttrib4fv(index, v);
}

#if GL_DESKTOP
inline void GL::vertexAttrib4sv(unsigned int index, const short* v)
{
	glVertexAttrib4sv(index, v);
}

inline void GL::vertexAttrib4dv(unsigned int index, const double* v)
{
	glVertexAttrib4dv(index, v);
}

inline void GL::vertexAttrib4iv(unsigned int index, const int* v)
{
	glVertexAttrib4iv(index, v);
}

inline void GL::vertexAttrib4bv(unsigned int index, const signed char* v)
{
	glVertexAttrib4bv(index, v);
}

inline void GL::vertexAttrib4ubv(unsigned int index, const unsigned char* v)
{
	glVertexAttrib4ubv(index, v);
}

inline void GL::vertexAttrib4usv(unsigned int index, const unsigned short* v)
{
	glVertexAttrib4usv(index, v);
}

inline void GL::vertexAttrib4uiv(unsigned int index, const unsigned int* v)
{
	glVertexAttrib4uiv(index, v);
}

inline void GL::vertexAttrib4Nbv(unsigned int index, const signed char* v)
{
	glVertexAttrib4Nbv(index, v);
}

inline void GL::vertexAttrib4Nsv(unsigned int index, const short* v)
{
	glVertexAttrib4Nsv(index, v);
}

inline void GL::vertexAttrib4Niv(unsigned int index, const int* v)
{
	glVertexAttrib4Niv(index, v);
}

inline void GL::vertexAttrib4Nubv(unsigned int index, const unsigned char* v)
{
	glVertexAttrib4Nubv(index, v);
}

inline void GL::vertexAttrib4Nusv(unsigned int index, const unsigned short* v)
{
	glVertexAttrib4Nusv(index, v);
}

inline void GL::vertexAttrib4Nuiv(unsigned int index, const unsigned int* v)
{
	glVertexAttrib4Nuiv(index, v);
}

inline void GL::vertexAttribI4bv(unsigned int index, const signed char* v)
{
	glVertexAttribI4bv(index, v);
}

inline void GL::vertexAttribI4ubv(unsigned int index, const unsigned char* v)
{
	glVertexAttribI4ubv(index, v);
}

inline void GL::vertexAttribI4sv(unsigned int index, const short* v)
{
	glVertexAttribI4sv(index, v);
}

inline void GL::vertexAttribI4usv(unsigned int index, const unsigned short* v)
{
	glVertexAttribI4usv(index, v);
}
#endif

inline void GL::vertexAttribI4iv(unsigned int index, const int* v)
{
	glVertexAttribI4iv(index, v);
}

inline void GL::vertexAttribI4uiv(unsigned int index, const unsigned int* v)
{
	glVertexAttribI4uiv(index, v);
}

#if VC(4, 1)
	inline void GL::vertexAttribL1dv(unsigned int index, const double* v)
	{
		glVertexAttribL1dv(index, v);
	}

	inline void GL::vertexAttribL2dv(unsigned int index, const double* v)
	{
		glVertexAttribL2dv(index, v);
	}

	inline void GL::vertexAttribL3dv(unsigned int index, const double* v)
	{
		glVertexAttribL3dv(index, v);
	}

	inline void GL::vertexAttribL4dv(unsigned int index, const double* v)
	{
		glVertexAttribL4dv(index, v);
	}
#endif

#if GL_DESKTOP
inline void GL::vertexAttribP1uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v)
{
	glVertexAttribP1uiv(index, static_cast<unsigned int>(type), normalized, v);
}

inline void GL::vertexAttribP2uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v)
{
	glVertexAttribP2uiv(index, static_cast<unsigned int>(type), normalized, v);
}

inline void GL::vertexAttribP3uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v)
{
	glVertexAttribP3uiv(index, static_cast<unsigned int>(type), normalized, v);
}

inline void GL::vertexAttribP4uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v)
{
	glVertexAttribP4uiv(index, static_cast<unsigned int>(type), normalized, v);
}
#endif

#if VC(4, 3) || EC(3, 1)
	inline void GL::vertexAttribBinding(unsigned int attribindex, unsigned int bindingindex)
	{
		glVertexAttribBinding(attribindex, bindingindex);
	}
#endif
#if VC(4, 5)
	inline void GL::vertexArrayAttribBinding(unsigned int vaobj, unsigned int attribindex, unsigned int bindingindex)
	{
		glVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::vertexAttribDivisor(unsigned index, unsigned int divisor)
{
	glVertexAttribDivisor(index, divisor);
}
#endif

#if VC(4, 3) || EC(3, 1)
	inline void GL::vertexAttribFormat(unsigned int attribindex, int size, GL_ENUM type, bool normalized, unsigned int relativeoffset)
	{
		glVertexAttribFormat(attribindex, size, static_cast<unsigned int>(type), normalized, relativeoffset);
	}

	inline void GL::vertexAttribIFormat(unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset)
	{
		glVertexAttribIFormat(attribindex, size, static_cast<unsigned int>(type), relativeoffset);
	}
#endif

#if VC(4, 3)
	inline void GL::vertexAttribLFormat(unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset)
	{
		glVertexAttribLFormat(attribindex, size, static_cast<unsigned int>(type), relativeoffset);
	}
#endif
#if VC(4, 5)
	inline void GL::vertexArrayAttribFormat(unsigned int vaobj, unsigned int attribindex, int size, GL_ENUM type, bool normalized, unsigned int relativeoffset)
	{
		glVertexArrayAttribFormat(vaobj, attribindex, size, static_cast<unsigned int>(type), normalized, relativeoffset);
	}

	inline void GL::vertexArrayAttribIFormat(unsigned int vaobj, unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset)
	{
		glVertexArrayAttribIFormat(vaobj, attribindex, size, static_cast<unsigned int>(type), relativeoffset);
	}

	inline void GL::vertexArrayAttribLFormat(unsigned int vaobj, unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset)
	{
		glVertexArrayAttribLFormat(vaobj, attribindex, size, static_cast<unsigned int>(type), relativeoffset);
	}
#endif

inline void GL::vertexAttribPointer(unsigned int index, int size, GL_ENUM type, bool normalized, int stride, const void* pointer)
{
	glVertexAttribPointer(index, size, static_cast<unsigned int>(type), normalized, stride, pointer);
}

#if GL_DESKTOP
inline void GL::vertexAttribIPointer(unsigned int index, int size, GL_ENUM type, int stride, const void* pointer)
{
	glVertexAttribIPointer(index, size, static_cast<unsigned int>(type), stride, pointer);
}
#endif

#if VC(4, 1)
	inline void GL::vertexAttribLPointer(unsigned int index, int size, int stride, const void* pointer)
	{
		glVertexAttribLPointer(index, size, GL_DOUBLE, stride, pointer);
	}
#endif
#if VC(4, 3) || EC(3, 1)
	inline void GL::vertexBindingDivisor(unsigned int bindingindex, unsigned int divisor)
	{
		glVertexBindingDivisor(bindingindex, divisor);
	}
#endif
#if VC(4, 5)
	inline void GL::vertexArrayBindingDivisor(unsigned int vaobj, unsigned int bindingindex, unsigned int divisor)
	{
		glVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
	}
#endif
