#pragma once

#include "API.h"
#include "GLM.h"

#include "BitfieldWrapper.h"
#include "Textures.h"

#include "Enums.h"

#include <vector>

namespace GL
{
#if _WIN64 || __x86_64__ || __ppc64__
	using ptrdiff_t = long long;
#else
	using ptrdiff_t = int;
#endif

	using sizeiptr = ptrdiff_t;

	static constexpr BITFIELD_WRAP(0x0001) MAP_READ_BIT;
	static constexpr BITFIELD_WRAP(0x0002) MAP_WRITE_BIT;
#if VC(4, 4)
	static constexpr BITFIELD_WRAP(0x00000040) MAP_PERSISTENT_BIT;
	static constexpr BITFIELD_WRAP(0x00000080) MAP_COHERENT_BIT;
#endif
	static constexpr BITFIELD_WRAP(0x0100) DYNAMIC_STORAGE_BIT;
	static constexpr BITFIELD_WRAP(0x0200) CLIENT_STORAGE_BIT;

	namespace detail
	{
#if VC(4, 4)
		GLCW_API void bufferStorage(GL_ENUM target, sizeiptr size, const void* data, unsigned int flags);
#endif
#if VC(4, 5)
		GLCW_API void namedBufferStorage(unsigned int buffer, sizeiptr size, const void* data, unsigned int flags);
#endif
	}

	//glBindBuffer — bind a named buffer object
	GLCW_API void bindBuffer(GL_ENUM target, unsigned int buffer);

#if GL_DESKTOP || EC(3, 0)
	//glBindBufferBase — bind a buffer object to an indexed buffer target
	GLCW_API void bindBufferBase(GL_ENUM target, unsigned int index, unsigned int buffer);

	//glBindBufferRange — bind a range within a buffer object to an indexed buffer target
	GLCW_API void bindBufferRange(GL_ENUM target, unsigned int index, unsigned int buffer, sizeiptr offset, sizeiptr size);
#endif

#if VC(4, 4)
	//glBindBuffersBase — bind one or more buffer objects to a sequence of indexed buffer targets
	GLCW_API void bindBuffersBase(GL_ENUM target, unsigned int first, int count, const unsigned int* buffers);
	//glBindBuffersRange — bind ranges of one or more buffer objects to a sequence of indexed buffer targets
	GLCW_API void bindBuffersRange(GL_ENUM target, unsigned int first, int count, const unsigned int* buffers, const sizeiptr* offset, const sizeiptr* sizes);
	//glBindBuffersRange — bind ranges of one or more buffer objects to a sequence of indexed buffer targets
	GLCW_API void bindBuffersRange(GL_ENUM target, unsigned int first, const std::vector<unsigned int>& buffers, const std::vector<sizeiptr>& offset, const std::vector<sizeiptr>& sizes);
#endif
#if VC(4, 3) || EC(3, 1)
	//glBindVertexBuffer, glVertexArrayVertexBuffer — bind a buffer to a vertex buffer bind point
	GLCW_API void bindVertexBuffer(unsigned int bindingindex, unsigned int buffer, sizeiptr offset, int stride);
#endif
#if VC(4, 5)
	//glBindVertexBuffer, glVertexArrayVertexBuffer — bind a buffer to a vertex buffer bind point
	GLCW_API void vertexArrayVertexBuffer(unsigned int vaobj, unsigned int bindingindex, unsigned int buffer, sizeiptr offsets, int stride);
#endif
#if VC(4, 4)
	//glBindVertexBuffers, glVertexArrayVertexBuffers — attach multiple buffer objects to a vertex array object
	GLCW_API void bindVertexBuffers(unsigned int first, int count, const unsigned int* buffers, const sizeiptr* offsets, const int* strides);
	//glBindVertexBuffers, glVertexArrayVertexBuffers — attach multiple buffer objects to a vertex array object
	GLCW_API void bindVertexBuffers(unsigned int first, const std::vector<unsigned int>& buffers, const std::vector<sizeiptr>& offsets, const std::vector<int>& strides);
	//glBindVertexBuffers, glVertexArrayVertexBuffers — attach multiple buffer objects to a vertex array object
#endif
#if VC(4, 5)
	GLCW_API void vertexArrayVertexBuffers(unsigned int vaobj, unsigned int first, int count, const unsigned int* buffers, const sizeiptr* offset, const int* strides);
	//glBindVertexBuffers, glVertexArrayVertexBuffers — attach multiple buffer objects to a vertex array object
	GLCW_API void vertexArrayVertexBuffers(unsigned int vaobj, unsigned int first, const std::vector<unsigned int>& buffers, const std::vector<sizeiptr>& offset, const std::vector<int>& strides);
#endif

	//glBufferData, glNamedBufferData — creates and initializes a buffer object's data store
	GLCW_API void bufferData(GL_ENUM target, sizeiptr size, const void* data, GL_ENUM usage);

#if VC(4, 5)
	//glBufferData, glNamedBufferData — creates and initializes a buffer object's data store
	GLCW_API void namedBufferData(unsigned int buffer, sizeiptr size, const void* data, GL_ENUM usage);
#endif
#if VC(4, 4)
	//glBufferStorage, glNamedBufferStorage — creates and initializes a buffer object's immutable data store
	template <unsigned int final_bits>
	void bufferStorage(GL_ENUM target, sizeiptr size, const void* data, BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> flags)
	{
		detail::bufferStorage(target, size, data, flags.value);
	}
#endif
#if VC(4, 5)
	//glBufferStorage, glNamedBufferStorage — creates and initializes a buffer object's immutable data store
	template <unsigned int final_bits>
	void namedBufferStorage(unsigned int buffer, sizeiptr size, const void* data, BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> flags)
	{
		detail::namedBufferStorage(buffer, size, data, flags.value);
	}
#endif

	//glBufferSubData, glNamedBufferSubData — updates a subset of a buffer object's data store
	GLCW_API void bufferSubData(GL_ENUM target, sizeiptr offset, sizeiptr size, const void* data);

#if VC(4, 5)
	//glBufferSubData, glNamedBufferSubData — updates a subset of a buffer object's data store
	GLCW_API void namedBufferSubData(unsigned int buffer, sizeiptr offset, sizeiptr size, const void* data);
#endif

#if VC(4, 3)
	//glClearBufferData, glClearNamedBufferData — fill a buffer object's data store with a fixed value
	GLCW_API void clearBufferData(GL_ENUM target, GL_ENUM internalformat, GL_ENUM format, GL_ENUM type, const void* data);
#endif
#if VC(4, 5)
	//glClearBufferData, glClearNamedBufferData — fill a buffer object's data store with a fixed value
	GLCW_API void clearNamedBufferData(unsigned int buffer, GL_ENUM internalformat, GL_ENUM format, GL_ENUM type, const void* data);
#endif
#if VC(4, 3)
	//glClearBufferSubData, glClearNamedBufferSubData — fill all or part of buffer object's data store with a fixed value
	GLCW_API void clearBufferSubData(GL_ENUM target, GL_ENUM internalformat, sizeiptr offset, sizeiptr size, GL_ENUM format, GL_ENUM type, const void* data);
#endif
#if VC(4, 5)
	//glClearBufferSubData, glClearNamedBufferSubData — fill all or part of buffer object's data store with a fixed value
	GLCW_API void clearNamedBufferSubData(unsigned int buffer, GL_ENUM internalformat, sizeiptr offset, sizeiptr size, GL_ENUM format, GL_ENUM type, const void* data);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glCopyBufferSubData, glCopyNamedBufferSubData — copy all or part of the data store of a buffer object to the data store of another buffer object
	GLCW_API void copyBufferSubData(GL_ENUM readTarget, GL_ENUM writeTarget, sizeiptr readOffset, sizeiptr writeOffset, sizeiptr size);
#endif

#if VC(4, 5)
	//glCopyBufferSubData, glCopyNamedBufferSubData — copy all or part of the data store of a buffer object to the data store of another buffer object
	GLCW_API void copyNamedBufferSubData(unsigned int readBuffer, unsigned int writeBuffer, sizeiptr readOffset, sizeiptr writeOffset, sizeiptr size);

	//glCreateBuffers — create buffer objects
	GLCW_API void createBuffers(int n, unsigned int* buffers);
#endif

	//glDeleteBuffers — delete named buffer objects
	GLCW_API void deleteBuffers(int n, const unsigned int* buffers);

	//glDrawArrays — render primitives from array data
	GLCW_API void drawArrays(GL_ENUM mode, int first, int count);

#if VC(4, 0) || EC(3, 1)
	//glDrawArraysIndirect — render primitives from array data, taking parameters from memory
	GLCW_API void drawArraysIndirect(GL_ENUM mode, const void* indirect);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glDrawArraysInstanced — draw multiple instances of a range of elements
	GLCW_API void drawArraysInstanced(GL_ENUM mode, int first, int count, int primcount);
#endif

#if VC(4, 2)
	//glDrawArraysInstancedBaseInstance — draw multiple instances of a range of elements with offset applied to instanced attributes
	GLCW_API void drawArraysInstancedBaseInstance(GL_ENUM mode, int first, int count, int primcount, unsigned int baseinstance);
#endif

	//glDrawElements — render primitives from array data
	GLCW_API void drawElements(GL_ENUM mode, int count, GL_ENUM type, const void* indices);

#if GL_DESKTOP
	//glDrawElementsBaseVertex — render primitives from array data with a per-element offset
	GLCW_API void drawElementsBaseVertex(GL_ENUM mode, int count, GL_ENUM type, void* indices, int basevertex);
#endif

#if VC(4, 0) || EC(3, 1)
	//glDrawElementsIndirect — render indexed primitives from array data, taking parameters from memory
	GLCW_API void drawElementsIndirect(GL_ENUM mode, GL_ENUM type, const void* indirect);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glDrawElementsInstanced — draw multiple instances of a set of elements
	GLCW_API void drawElementsInstanced(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount);
#endif

#if VC(4, 2)
	//glDrawElementsInstancedBaseInstance — draw multiple instances of a set of elements with offset applied to instanced attributes
	GLCW_API void drawElementsInstancedBaseInstance(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount, unsigned int baseinstance);
#endif

#if GL_DESKTOP
	//glDrawElementsInstancedBaseVertex — render multiple instances of a set of primitives from array data with a per-element offset
	GLCW_API void drawElementsInstancedBaseVertex(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount, int basevertex);
#endif

#if VC(4, 2)
	//glDrawElementsInstancedBaseVertexBaseInstance — render multiple instances of a set of primitives from array data with a per-element offset
	GLCW_API void drawElementsInstancedBaseVertexBaseInstance(GL_ENUM mode, int count, GL_ENUM type, const void* indices, int primcount, int basevertex, unsigned int baseinstance);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glDrawRangeElements — render primitives from array data
	GLCW_API void drawRangeElements(GL_ENUM mode, unsigned int start, unsigned int end, int count, GL_ENUM type, const void* indices);
#endif

#if GL_DESKTOP
	//glDrawRangeElementsBaseVertex — render primitives from array data with a per-element offset
	GLCW_API void drawRangeElementsBaseVertex(GL_ENUM mode, unsigned int start, unsigned int end, int count, GL_ENUM type, void* indices, int basevertex);
#endif

	//glEnableVertexAttribArray — Enable or disable a generic vertex attribute array
	GLCW_API void enableVertexAttribArray(unsigned int index);
	//glEnableVertexAttribArray — Enable or disable a generic vertex attribute array
	GLCW_API void disableVertexAttribArray(unsigned int index);

#if VC(4, 5)
	//glEnableVertexAttribArray — Enable or disable a generic vertex attribute array
	GLCW_API void enableVertexArrayAttrib(unsigned int vaobj, unsigned int index);
	//glEnableVertexAttribArray — Enable or disable a generic vertex attribute array
	GLCW_API void disableVertexArrayAttrib(unsigned int vaobj, unsigned int index);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glFlushMappedBufferRange, glFlushMappedNamedBufferRange — indicate modifications to a range of a mapped buffer
	GLCW_API void flushMappedBufferRange(GL_ENUM target, sizeiptr offset, sizeiptr length);
#endif

#if VC(4, 5)
	//glFlushMappedBufferRange, glFlushMappedNamedBufferRange — indicate modifications to a range of a mapped buffer
	GLCW_API void flushMappedNamedBufferRange(unsigned int buffer, sizeiptr offset, sizeiptr length);
#endif

	//glGenBuffers — generate buffer object names
	GLCW_API void genBuffers(int n, unsigned int* buffers);

	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getBufferParameteriv(GL_ENUM target, GL_ENUM value, int* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API int getBufferParameteriv(GL_ENUM target, GL_ENUM value);

#if GL_DESKTOP || EC(3, 0)
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getBufferParameteri64v(GL_ENUM target, GL_ENUM value, long long* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API long long getBufferParameteri64v(GL_ENUM target, GL_ENUM value);
#endif

#if VC(4, 5)
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getNamedBufferParameteriv(unsigned int buffer, GL_ENUM value, int* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API int getNamedBufferParameteriv(unsigned int buffer, GL_ENUM value);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getNamedBufferParameteri64v(unsigned int buffer, GL_ENUM value, long long* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API long long getNamedBufferParameteri64v(unsigned int buffer, GL_ENUM value);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void getBufferPointerv(GL_ENUM target, /*GL_BUFFER_MAP_POINTER, */void** params);
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void* getBufferPointerv(GL_ENUM target /*GL_BUFFER_MAP_POINTER, */);
#endif

#if VC(4, 5)
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void getNamedBufferPointerv(unsigned int buffer, /*GL_BUFFER_MAP_POINTER, */void** params);
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void* getNamedBufferPointerv(unsigned int buffer/*GL_BUFFER_MAP_POINTER, */);
#endif

#if GL_DESKTOP
	//glGetBufferSubData, glGetNamedBufferSubData — returns a subset of a buffer object's data store
	GLCW_API void getBufferSubData(GL_ENUM target, sizeiptr offset, sizeiptr size, void* data);
#endif

#if VC(4, 5)
	//glGetBufferSubData, glGetNamedBufferSubData — returns a subset of a buffer object's data store
	GLCW_API void getNamedBufferSubData(unsigned int buffer, sizeiptr offset, sizeiptr size, void* data);
#endif

#if VC(4, 3)
	//glInvalidateBufferData — invalidate the content of a buffer object's data store
	GLCW_API void invalidateBufferData(unsigned int buffer);

	//glInvalidateBufferSubData — invalidate a region of a buffer object's data store
	GLCW_API void invalidateBufferSubData(unsigned int buffer, sizeiptr offset, sizeiptr length);
#endif

	//glIsBuffer — determine if a name corresponds to a buffer object
	GLCW_API bool isBuffer(unsigned int buffer);

#if GL_DESKTOP
	//glMapBuffer, glMapNamedBuffer — map all of a buffer object's data store into the client's address space
	GLCW_API void* mapBuffer(GL_ENUM target, GL_ENUM access);
#endif

#if VC(4, 5)
	//glMapBuffer, glMapNamedBuffer — map all of a buffer object's data store into the client's address space
	GLCW_API void* mapNamedBuffer(unsigned int buffer, GL_ENUM access);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glMapBufferRange, glMapNamedBufferRange — map all or part of a buffer object's data store into the client's address space
	GLCW_API void* mapBufferRange(GL_ENUM target, sizeiptr offset, sizeiptr length, GL_ENUM access);
#endif

#if VC(4, 5)
	//glMapBufferRange, glMapNamedBufferRange — map all or part of a buffer object's data store into the client's address space
	GLCW_API void* mapNamedBufferRange(unsigned int buffer, sizeiptr offset, sizeiptr length, GL_ENUM access);
#endif

#if GL_DESKTOP
	//glMultiDrawArrays — render multiple sets of primitives from array data
	GLCW_API void multiDrawArrays(GL_ENUM mode, const int* first, const int* count, int drawcount);
#endif

#if VC(4, 3)
	//glMultiDrawArraysIndirect — render multiple sets of primitives from array data, taking parameters from memory
	GLCW_API void multiDrawArraysIndirect(GL_ENUM mode, const void* indirect, int drawcount, int stride);
#endif

#if GL_DESKTOP
	//glMultiDrawElements — render multiple sets of primitives by specifying indices of array data elements
	GLCW_API void multiDrawElements(GL_ENUM mode, const int* count, GL_ENUM type, const void* const* indices, int drawcount);

	//glMultiDrawElementsBaseVertex — render multiple sets of primitives by specifying indices of array data elements and an index to apply to each index
	GLCW_API void multiDrawElementsBaseVertex(GL_ENUM mode, int* count, GL_ENUM type, void** indices, int drawcount, int* basevertex);
#endif

#if VC(4, 3)
	//glMultiDrawElementsIndirect — render indexed primitives from array data, taking parameters from memory
	GLCW_API void multiDrawElementsIndirect(GL_ENUM mode, GL_ENUM type, const void* indirect, int drawcount, int stride);
#endif

#if VC(4, 0)
	//glPatchParameter — specifies the parameters for patch primitives
	GLCW_API void patchParameteri(GL_ENUM pname, int value);
	//glPatchParameter — specifies the parameters for patch primitives
	GLCW_API void patchParameterfv(GL_ENUM pname, const float* values);
#endif

#if GL_DESKTOP
	//glPrimitiveRestartIndex — specify the primitive restart index
	GLCW_API void primitiveRestartIndex(unsigned int index);

	//glProvokingVertex — specifiy the vertex to be used as the source of data for flat shaded varyings
	GLCW_API void provokingVertex(GL_ENUM provokeMode);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glUnmapBuffer, glUnmapNamedBuffer — release the mapping of a buffer object's data store into the client's address space
	GLCW_API bool unmapBuffer(GL_ENUM target);
#endif

#if VC(4, 5)
	//glUnmapBuffer, glUnmapNamedBuffer — release the mapping of a buffer object's data store into the client's address space
	GLCW_API bool unmapNamedBuffer(unsigned int buffer);
#endif

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib1f(unsigned int index, float v0);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2f(unsigned int index, int v0, int v1);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2f(unsigned int index, const glm::vec2& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3f(unsigned int index, int v0, int v1, int v2);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3f(unsigned int index, const glm::vec3& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4f(unsigned int index, int v0, int v1, int v2, int v3);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4f(unsigned int index, const glm::vec4& v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4i(unsigned int index, int v0, int v1, int v2, int v3);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4i(unsigned int index, const glm::ivec4& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4ui(unsigned int index, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4ui(unsigned int index, const glm::uvec4& v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib1fv(unsigned int index, const float* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2fv(unsigned int index, const float* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3fv(unsigned int index, const float* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4fv(unsigned int index, const float* v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4iv(unsigned int index, const int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4uiv(unsigned int index, const unsigned int* v);

#if GL_DESKTOP
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib1s(unsigned int index, short v0);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib1d(unsigned int index, double v0);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI1i(unsigned int index, int v0);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI1ui(unsigned int index, unsigned int v0);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2s(unsigned int index, short v0, short v1);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2s(unsigned int index, const glm::vec<2, short>& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2d(unsigned int index, double v0, double v1);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2d(unsigned int index, const glm::dvec2& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI2i(unsigned int index, int v0, int v1);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI2i(unsigned int index, const glm::ivec2& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI2ui(unsigned int index, unsigned int v0, unsigned int v1);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI2ui(unsigned int index, const glm::uvec2& v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3s(unsigned int index, short v0, short v1, short v2);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3s(unsigned int index, const glm::vec<3, short>& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3d(unsigned int index, double v0, double v1, double v2);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3d(unsigned int index, const glm::dvec3& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI3i(unsigned int index, int v0, int v1, int v2);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI3i(unsigned int index, const glm::ivec3& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI3ui(unsigned int index, unsigned int v0, unsigned int v1, unsigned int v2);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI3ui(unsigned int index, const glm::uvec3& v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4s(unsigned int index, short v0, short v1, short v2, short v3);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4s(unsigned int index, const glm::vec<4, short>& v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4d(unsigned int index, double v0, double v1, double v2, double v3);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4d(unsigned int index, const glm::dvec4& v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib1sv(unsigned int index, const short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib1dv(unsigned int index, const double* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI1iv(unsigned int index, const int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI1uiv(unsigned int index, const unsigned int* v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2sv(unsigned int index, const short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib2dv(unsigned int index, const double* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI2iv(unsigned int index, const int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI2uiv(unsigned int index, const unsigned int* v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3sv(unsigned int index, const short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib3dv(unsigned int index, const double* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI3iv(unsigned int index, const int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI3uiv(unsigned int index, const unsigned int* v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4sv(unsigned int index, const short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4dv(unsigned int index, const double* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4iv(unsigned int index, const int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4bv(unsigned int index, const signed char* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4ubv(unsigned int index, const unsigned char* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4usv(unsigned int index, const unsigned short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4uiv(unsigned int index, const unsigned int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4Nbv(unsigned int index, const signed char* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4Nsv(unsigned int index, const short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4Niv(unsigned int index, const int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4Nubv(unsigned int index, const unsigned char* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4Nusv(unsigned int index, const unsigned short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttrib4Nuiv(unsigned int index, const unsigned int* v);

	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4bv(unsigned int index, const signed char* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4ubv(unsigned int index, const unsigned char* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4sv(unsigned int index, const short* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribI4usv(unsigned int index, const unsigned short* v);
#endif

#if VC(4, 1)
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribL1dv(unsigned int index, const double* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribL2dv(unsigned int index, const double* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribL3dv(unsigned int index, const double* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribL4dv(unsigned int index, const double* v);
#endif

#if GL_DESKTOP
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribP1uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribP2uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribP3uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribP4uiv(unsigned int index, GL_ENUM type, bool normalized, const unsigned int* v);
#endif

#if VC(4, 3) || EC(3, 1)
	//glVertexAttribBinding — associate a vertex attribute and a vertex buffer binding for a vertex array object
	GLCW_API void vertexAttribBinding(unsigned int attribindex, unsigned int bindingindex);
	//glVertexAttribBinding — associate a vertex attribute and a vertex buffer binding for a vertex array object
#endif
#if VC(4, 5)
	GLCW_API void vertexArrayAttribBinding(unsigned int vaobj, unsigned int attribindex, unsigned int bindingindex);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glVertexAttribDivisor — modify the rate at which generic vertex attributes advance during instanced rendering
	GLCW_API void vertexAttribDivisor(unsigned index, unsigned int divisor);
#endif

#if VC(4, 3) || EC(3, 1)
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexAttribFormat(unsigned int attribindex, int size, GL_ENUM type, bool normalized, unsigned int relativeoffset);
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexAttribIFormat(unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset);
#endif

#if VC(4, 3)
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexAttribLFormat(unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset);
#endif
#if VC(4, 5)
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexArrayAttribFormat(unsigned int vaobj, unsigned int attribindex, int size, GL_ENUM type, bool normalized, unsigned int relativeoffset);
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexArrayAttribIFormat(unsigned int vaobj, unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset);
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexArrayAttribLFormat(unsigned int vaobj, unsigned int attribindex, int size, GL_ENUM type, unsigned int relativeoffset);
#endif

	//glVertexAttribPointer — define an array of generic vertex attribute data
	GLCW_API void vertexAttribPointer(unsigned int index, int size, GL_ENUM type, bool normalized, int stride, const void* pointer);

#if GL_DESKTOP
	//glVertexAttribPointer — define an array of generic vertex attribute data
	GLCW_API void vertexAttribIPointer(unsigned int index, int size, GL_ENUM type, int stride, const void* pointer);
#endif

#if VC(4, 1)
	//glVertexAttribPointer — define an array of generic vertex attribute data
	GLCW_API void vertexAttribLPointer(unsigned int index, int size, /*GL_DOUBLE,*/ int stride, const void* pointer);
#endif

#if VC(4, 3) || EC(3, 1)
	//glVertexBindingDivisor, glVertexArrayBindingDivisor — modify the rate at which generic vertex attributes advance
	GLCW_API void vertexBindingDivisor(unsigned int bindingindex, unsigned int divisor);
#endif
#if VC(4, 5)
	//glVertexBindingDivisor, glVertexArrayBindingDivisor — modify the rate at which generic vertex attributes advance
	GLCW_API void vertexArrayBindingDivisor(unsigned int vaobj, unsigned int bindingindex, unsigned int divisor);
#endif
}