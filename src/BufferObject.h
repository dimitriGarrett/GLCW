#pragma once

#include "API.h"
#include "GLM.h"

#include "BitfieldWrapper.h"
#include "Textures.h"

#include "Config.h"

#include <vector>

namespace GL
{
	// the info about each type is from: https://www.khronos.org/opengl/wiki/Vertex_Specification (exact quotes)
	enum class BufferAttribPointerTypes : unsigned int
	{
		/*
		Uncomment the line below if it is truly needed, but from the official khronos website:
		Never use this. It's technically legal, but will almost certainly be a performance trap.
		*/
		//DOUBLE = 0x140A, // A 64-bit double precision

		/*Unsigned integers*/
		UNSIGNED_BYTE = 0x1401, // An unsigned 8-bit value.
		UNSIGNED_SHORT = 0x1403, // An unsigned 16-bit value.
		UNSIGNED_INT = 0x1405, // An unsigned 32-bit value.

		/*Signed integers*/
		BYTE = 0x1400, // A signed 8-bit two's complement value.
		SHORT = 0x1402, // A signed 16-bit two's complement value.
		INT = 0x1404, // A signed 32-bit two's complement value.

		/*Floating point numbers*/
		FLOAT = 0x1406, // A 32-bit single precision floating-point value.
		HALF_FLOAT = 0x140B, // A 16-bit half-precision float-point value. (more info here: https://www.khronos.org/opengl/wiki/Small_Float_Formats)
		FIXED = 0x140C, // A 16-bit fixed-point two's complement value.

		/*Special alignments (with more info below)*/
		UNSIGNED_INT_2_10_10_10_10_REV = 0x8368,
		INT_2_10_10_10_10_REV = 0x8D9F

		/*
		A series of four values packed in a 32-bit unsigned integer. Each individual packed value is a two's complement signed integer, but the overall bitfield is unsigned.
		The bitdepth for the packed fields are 2, 10, 10, and 10, but in reverse order. So the lowest-significant 10-bits are the first component, the next 10 bits are the
		second component, and so on. If you use this, the size must be 4 (or GL_BGRA)

		Here is a visual demonstration of the ordering of the 2_10_10_10_REV types:
		31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
		|  W |              Z              |              Y              |               X            |
		-----------------------------------------------------------------------------------------------
		*/
	};

	enum class BufferTargetFlushed : unsigned int
	{
#if VC(4, 2)
		ATOMIC_COUNTER_BUFFER = 0x92C0,
#endif
#if VC(4, 3)
		DISPATCH_INDIRECT_BUFFER = 0x90EE,
		SHADER_STORAGE_BUFFER = 0x90D2,
#endif
#if VC(4, 4)
		QUERY_BUFFER = 0x9192,
#endif

		ARRAY_BUFFER = 0x8892,
		ELEMENT_ARRAY_BUFFER = 0x8893,
		COPY_READ_BUFFER = 0x8F36,
		COPY_WRITE_BUFFER = 0x8F37,
		PIXEL_PACK_BUFFER = 0x88EB,
		PIXEL_UNPACK_BUFFER = 0x88EC,
		UNIFORM_BUFFER = 0x8A11,
		TRANSFORM_FEEDBACK_BUFFER = 0x8C8E,

#if GL_DESKTOP
		TEXTURE_BUFFER = 0x8C2A,
		DRAW_INDIRECT_BUFFER = 0x8F3F,
#endif
	};

	enum class BufferTarget : unsigned int
	{
#if GL_DESKTOP || EC(3, 0)
		COPY_READ_BUFFER = 0x8F36,
		COPY_WRITE_BUFFER = 0x8F37,
		PIXEL_PACK_BUFFER = 0x88EB,
		PIXEL_UNPACK_BUFFER = 0x88EC,
		UNIFORM_BUFFER = 0x8A11,
		TRANSFORM_FEEDBACK_BUFFER = 0x8C8E,
#endif

#if VC(4, 2) || EC(3, 1)
		ATOMIC_COUNTER_BUFFER = 0x92C0,
#endif
#if VC(4, 3) || EC(3, 1)
		DISPATCH_INDIRECT_BUFFER = 0x90EE,
		SHADER_STORAGE_BUFFER = 0x90D2,
#endif
#if VC(4, 4)
		QUERY_BUFFER = 0x9192,
#endif
#if GL_DESKTOP || EC(3, 1)
		DRAW_INDIRECT_BUFFER = 0x8F3F,
#endif

		ARRAY_BUFFER = 0x8892,
		ELEMENT_ARRAY_BUFFER = 0x8893,
		TEXTURE_BUFFER = 0x8C2A,
	};

#if GL_DESKTOP || EC(3, 0)
	enum class BufferPointerTarget : unsigned int
	{
		COPY_READ_BUFFER = 0x8F36,
		COPY_WRITE_BUFFER = 0x8F37,
		PIXEL_PACK_BUFFER = 0x88EB,
		PIXEL_UNPACK_BUFFER = 0x88EC,
		UNIFORM_BUFFER = 0x8A11,
		TRANSFORM_FEEDBACK_BUFFER = 0x8C8E,

#if VC(4, 2)
		ATOMIC_COUNTER_BUFFER = 0x92C0,
#endif
#if VC(4, 3)
		DISPATCH_INDIRECT_BUFFER = 0x90EE,
		SHADER_STORAGE_BUFFER = 0x90D2,
#endif
#if VC(4, 4)
		QUERY_BUFFER = 0x9192,
#endif
#if GL_DESKTOP
		DRAW_INDIRECT_BUFFER = 0x8F3F,
		TEXTURE_BUFFER = 0x8C2A,
#endif

		ARRAY_BUFFER = 0x8892,
		ELEMENT_ARRAY_BUFFER = 0x8893,
	};
#endif

	enum class BufferTargetIndexed : unsigned int
	{
#if VC(4, 2) || EC(3, 1)
		ATOMIC_COUNTER_BUFFER = 0x92C0,
#endif
#if VC(4, 3) || EC(3, 1)
		SHADER_STORAGE_BUFFER = 0x90D2,
#endif
		UNIFORM_BUFFER = 0x8A11,
		TRANSFORM_FEEDBACK_BUFFER = 0x8C8E 
	};

	enum class BufferUsage : unsigned int
	{
		STREAM_DRAW = 0x88E0,
		STREAM_READ = 0x88E1,
		STREAM_COPY = 0x88E2,
		STATIC_DRAW = 0x88E4,
		STATIC_READ = 0x88E5,
		STATIC_COPY = 0x88E6,
		DYNAMIC_DRAW = 0x88E8,
		DYNAMIC_READ = 0x88E9,
		DYNAMIC_COPY = 0x88EA
	};

	enum class BufferInternalFormat : unsigned int
	{
		RGBA32F = 0x8814,
		RGBA16F = 0x881A,
		RGB32F = 0x8815,
		RGB32I = 0x8D83,
		RGB32UI = 0x8D71,
		RGBA32UI = 0x8D70,
		RGBA16UI = 0x8D76,
		RGBA8UI = 0x8D7C,
		RGBA32I = 0x8D82,
		RGBA16I = 0x8D88,
		RGBA8I = 0x8D8E,
		RGBA8 = 0x8058,
		RGBA16 = 0x805B,
		RG32UI = 0x823C,
		RG16UI = 0x823A,
		RG8UI = 0x8238,
		RG32I = 0x823B,
		RG16I = 0x8239,
		RG8I = 0x8237,
		RG32F = 0x8230,
		RG16F = 0x822F,
		RG16 = 0x822C,
		RG8 = 0x822B,
		R32UI = 0x8236,
		R16UI = 0x8234,
		R8UI = 0x8232,
		R32I = 0x8235,
		R16I = 0x8233,
		R8I = 0x8231,
		R32F = 0x822E,
		R16F = 0x822D,
		R16 = 0x822A,
		R8 = 0x8229,
	};

	enum class DrawMode : unsigned int
	{
		POINTS = 0x0000,
		LINE_STRIP = 0x0003,
		LINE_LOOP = 0x0002,
		LINES = 0x0001,
		TRIANGLES = 0x0004,
		TRIANGLE_STRIP = 0x0005,
		TRIANGLE_FAN = 0x0006,

#if GL_DESKTOP
		LINE_STRIP_ADJACENCY = 0x000B,
		LINES_ADJACENCY = 0x000A,
		TRIANGLE_STRIP_ADJACENCY = 0x000D,
		TRIANGLES_ADJACENCY = 0x000C,
		PATCHES = 0xE
#endif
	};

	enum class DrawElementsType : unsigned int
	{
		UNSIGNED_BYTE = 0x1401,
		UNSIGNED_SHORT = 0x1403,
		UNSIGNED_INT = 0x1405
	};

	enum class BufferParameter : unsigned int
	{
		BUFFER_ACCESS = 0x88BB,
		BUFFER_ACCESS_FLAGS = 0x911F,
		BUFFER_IMMUTABLE_STORAGE = 0x821F,
		BUFFER_MAPPED = 0x88BC,
		BUFFER_MAP_LENGTH = 0x9120,
		BUFFER_MAP_OFFSET = 0x9121,
		BUFFER_SIZE = 0x8764,
		BUFFER_STORAGE_FLAGS = 0x8220,
		BUFFER_USAGE = 0x8765
	};

	enum class BufferAccess : unsigned int
	{
		READ_ONLY = 0x88B8,
		WRITE_ONLY = 0x88B9,
		READ_WRITE = 0x88BA
	};

	enum class PatchParameter : unsigned int
	{
		PATCH_VERTICES = 0x8E72,
		PATCH_DEFAULT_OUTER_LEVEL = 0x8E74,
		PATCH_DEFAULT_INNER_LEVEL = 0x8E73
	};

	enum class ProvokeMode : unsigned int
	{
		FIRST_VERTEX_CONVENTION = 0x8E4D,
		LAST_VERTEX_CONVENTION = 0x8E4E
	};

	enum class VertexAttribType : unsigned int
	{
		UNSIGNED_INT_2_10_10_10_REV = 0x8368,
		INT_2_10_10_10_REV = 0x8D9F,
		UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B
	};

	enum class VertexAttribFormatType : unsigned int
	{
		UNSIGNED_BYTE = 0x1401,
		BYTE = 0x1400,
		UNSIGNED_SHORT = 0x1403,
		SHORT = 0x1402,
		UNSIGNED_INT = 0x1405,
		INT = 0x1404,
		FIXED = 0x140C,
		HALF_FLOAT = 0x140B,
		FLOAT = 0x1406,
		DOUBLE = 0x140A,

		UNSIGNED_INT_2_10_10_10_REV = 0x8368,
		INT_2_10_10_10_REV = 0x8D9F,
		UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B
	};

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
		GLCW_API void bufferStorage(BufferTarget target, sizeiptr size, const void* data, unsigned int flags);
#endif
#if VC(4, 5)
		GLCW_API void namedBufferStorage(unsigned int buffer, sizeiptr size, const void* data, unsigned int flags);
#endif
	}

	//glBindBuffer — bind a named buffer object
	GLCW_API void bindBuffer(BufferTarget target, unsigned int buffer);

#if GL_DESKTOP || EC(3, 0)
	//glBindBufferBase — bind a buffer object to an indexed buffer target
	GLCW_API void bindBufferBase(BufferTargetIndexed target, unsigned int index, unsigned int buffer);

	//glBindBufferRange — bind a range within a buffer object to an indexed buffer target
	GLCW_API void bindBufferRange(BufferTargetIndexed target, unsigned int index, unsigned int buffer, sizeiptr offset, sizeiptr size);
#endif

#if VC(4, 4)
	//glBindBuffersBase — bind one or more buffer objects to a sequence of indexed buffer targets
	GLCW_API void bindBuffersBase(BufferTargetIndexed target, unsigned int first, int count, const unsigned int* buffers);
	//glBindBuffersRange — bind ranges of one or more buffer objects to a sequence of indexed buffer targets
	GLCW_API void bindBuffersRange(BufferTargetIndexed target, unsigned int first, int count, const unsigned int* buffers, const sizeiptr* offset, const sizeiptr* sizes);
	//glBindBuffersRange — bind ranges of one or more buffer objects to a sequence of indexed buffer targets
	GLCW_API void bindBuffersRange(BufferTargetIndexed target, unsigned int first, const std::vector<unsigned int>& buffers, const std::vector<sizeiptr>& offset, const std::vector<sizeiptr>& sizes);
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
	GLCW_API void bufferData(BufferTarget target, sizeiptr size, const void* data, BufferUsage usage);

#if VC(4, 5)
	//glBufferData, glNamedBufferData — creates and initializes a buffer object's data store
	GLCW_API void namedBufferData(unsigned int buffer, sizeiptr size, const void* data, BufferUsage usage);
#endif
#if VC(4, 4)
	//glBufferStorage, glNamedBufferStorage — creates and initializes a buffer object's immutable data store
	template <unsigned int final_bits>
	void bufferStorage(BufferTarget target, sizeiptr size, const void* data, BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> flags)
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
	GLCW_API void bufferSubData(BufferTarget target, sizeiptr offset, sizeiptr size, const void* data);

#if VC(4, 5)
	//glBufferSubData, glNamedBufferSubData — updates a subset of a buffer object's data store
	GLCW_API void namedBufferSubData(unsigned int buffer, sizeiptr offset, sizeiptr size, const void* data);
#endif

#if VC(4, 3)
	//glClearBufferData, glClearNamedBufferData — fill a buffer object's data store with a fixed value
	GLCW_API void clearBufferData(BufferTarget target, BufferInternalFormat internalformat, TextureFormat format, TextureTypes type, const void* data);
#endif
#if VC(4, 5)
	//glClearBufferData, glClearNamedBufferData — fill a buffer object's data store with a fixed value
	GLCW_API void clearNamedBufferData(unsigned int buffer, BufferInternalFormat internalformat, TextureFormat format, TextureTypes type, const void* data);
#endif
#if VC(4, 3)
	//glClearBufferSubData, glClearNamedBufferSubData — fill all or part of buffer object's data store with a fixed value
	GLCW_API void clearBufferSubData(BufferTarget target, BufferInternalFormat internalformat, sizeiptr offset, sizeiptr size, TextureFormat format, TextureTypes type, const void* data);
#endif
#if VC(4, 5)
	//glClearBufferSubData, glClearNamedBufferSubData — fill all or part of buffer object's data store with a fixed value
	GLCW_API void clearNamedBufferSubData(unsigned int buffer, BufferInternalFormat internalformat, sizeiptr offset, sizeiptr size, TextureFormat format, TextureTypes type, const void* data);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glCopyBufferSubData, glCopyNamedBufferSubData — copy all or part of the data store of a buffer object to the data store of another buffer object
	GLCW_API void copyBufferSubData(BufferTarget readTarget, BufferTarget writeTarget, sizeiptr readOffset, sizeiptr writeOffset, sizeiptr size);
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
	GLCW_API void drawArrays(DrawMode mode, int first, int count);

#if VC(4, 0) || EC(3, 1)
	//glDrawArraysIndirect — render primitives from array data, taking parameters from memory
	GLCW_API void drawArraysIndirect(DrawMode mode, const void* indirect);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glDrawArraysInstanced — draw multiple instances of a range of elements
	GLCW_API void drawArraysInstanced(DrawMode mode, int first, int count, int primcount);
#endif

#if VC(4, 2)
	//glDrawArraysInstancedBaseInstance — draw multiple instances of a range of elements with offset applied to instanced attributes
	GLCW_API void drawArraysInstancedBaseInstance(DrawMode mode, int first, int count, int primcount, unsigned int baseinstance);
#endif

	//glDrawElements — render primitives from array data
	GLCW_API void drawElements(DrawMode mode, int count, DrawElementsType type, const void* indices);

#if GL_DESKTOP
	//glDrawElementsBaseVertex — render primitives from array data with a per-element offset
	GLCW_API void drawElementsBaseVertex(DrawMode mode, int count, DrawElementsType type, void* indices, int basevertex);
#endif

#if VC(4, 0) || EC(3, 1)
	//glDrawElementsIndirect — render indexed primitives from array data, taking parameters from memory
	GLCW_API void drawElementsIndirect(DrawMode mode, DrawElementsType type, const void* indirect);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glDrawElementsInstanced — draw multiple instances of a set of elements
	GLCW_API void drawElementsInstanced(DrawMode mode, int count, DrawElementsType type, const void* indices, int primcount);
#endif

#if VC(4, 2)
	//glDrawElementsInstancedBaseInstance — draw multiple instances of a set of elements with offset applied to instanced attributes
	GLCW_API void drawElementsInstancedBaseInstance(DrawMode mode, int count, DrawElementsType type, const void* indices, int primcount, unsigned int baseinstance);
#endif

#if GL_DESKTOP
	//glDrawElementsInstancedBaseVertex — render multiple instances of a set of primitives from array data with a per-element offset
	GLCW_API void drawElementsInstancedBaseVertex(DrawMode mode, int count, DrawElementsType type, const void* indices, int primcount, int basevertex);
#endif

#if VC(4, 2)
	//glDrawElementsInstancedBaseVertexBaseInstance — render multiple instances of a set of primitives from array data with a per-element offset
	GLCW_API void drawElementsInstancedBaseVertexBaseInstance(DrawMode mode, int count, DrawElementsType type, const void* indices, int primcount, int basevertex, unsigned int baseinstance);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glDrawRangeElements — render primitives from array data
	GLCW_API void drawRangeElements(DrawMode mode, unsigned int start, unsigned int end, int count, DrawElementsType type, const void* indices);
#endif

#if GL_DESKTOP
	//glDrawRangeElementsBaseVertex — render primitives from array data with a per-element offset
	GLCW_API void drawRangeElementsBaseVertex(DrawMode mode, unsigned int start, unsigned int end, int count, DrawElementsType type, void* indices, int basevertex);
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
	GLCW_API void flushMappedBufferRange(BufferTargetFlushed target, sizeiptr offset, sizeiptr length);
#endif

#if VC(4, 5)
	//glFlushMappedBufferRange, glFlushMappedNamedBufferRange — indicate modifications to a range of a mapped buffer
	GLCW_API void flushMappedNamedBufferRange(unsigned int buffer, sizeiptr offset, sizeiptr length);
#endif

	//glGenBuffers — generate buffer object names
	GLCW_API void genBuffers(int n, unsigned int* buffers);

	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getBufferParameteriv(BufferTarget target, BufferParameter value, int* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API int getBufferParameteriv(BufferTarget target, BufferParameter value);

#if GL_DESKTOP || EC(3, 0)
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getBufferParameteri64v(BufferTarget target, BufferParameter value, long long* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API long long getBufferParameteri64v(BufferTarget target, BufferParameter value);
#endif

#if VC(4, 5)
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getNamedBufferParameteriv(unsigned int buffer, BufferParameter value, int* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API int getNamedBufferParameteriv(unsigned int buffer, BufferParameter value);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API void getNamedBufferParameteri64v(unsigned int buffer, BufferParameter value, long long* data);
	//glGetBufferParameter — return parameters of a buffer object
	GLCW_API long long getNamedBufferParameteri64v(unsigned int buffer, BufferParameter value);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void getBufferPointerv(BufferPointerTarget target, /*GL_BUFFER_MAP_POINTER, */void** params);
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void* getBufferPointerv(BufferPointerTarget target /*GL_BUFFER_MAP_POINTER, */);
#endif

#if VC(4, 5)
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void getNamedBufferPointerv(unsigned int buffer, /*GL_BUFFER_MAP_POINTER, */void** params);
	//glGetBufferPointerv, glGetNamedBufferPointerv — return the pointer to a mapped buffer object's data store
	GLCW_API void* getNamedBufferPointerv(unsigned int buffer/*GL_BUFFER_MAP_POINTER, */);
#endif

#if GL_DESKTOP
	//glGetBufferSubData, glGetNamedBufferSubData — returns a subset of a buffer object's data store
	GLCW_API void getBufferSubData(BufferTarget target, sizeiptr offset, sizeiptr size, void* data);
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
	GLCW_API void* mapBuffer(BufferTarget target, BufferAccess access);
#endif

#if VC(4, 5)
	//glMapBuffer, glMapNamedBuffer — map all of a buffer object's data store into the client's address space
	GLCW_API void* mapNamedBuffer(unsigned int buffer, BufferAccess access);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glMapBufferRange, glMapNamedBufferRange — map all or part of a buffer object's data store into the client's address space
	GLCW_API void* mapBufferRange(BufferTarget target, sizeiptr offset, sizeiptr length, BufferAccess access);
#endif

#if VC(4, 5)
	//glMapBufferRange, glMapNamedBufferRange — map all or part of a buffer object's data store into the client's address space
	GLCW_API void* mapNamedBufferRange(unsigned int buffer, sizeiptr offset, sizeiptr length, BufferAccess access);
#endif

#if GL_DESKTOP
	//glMultiDrawArrays — render multiple sets of primitives from array data
	GLCW_API void multiDrawArrays(DrawMode mode, const int* first, const int* count, int drawcount);
#endif

#if VC(4, 3)
	//glMultiDrawArraysIndirect — render multiple sets of primitives from array data, taking parameters from memory
	GLCW_API void multiDrawArraysIndirect(DrawMode mode, const void* indirect, int drawcount, int stride);
#endif

#if GL_DESKTOP
	//glMultiDrawElements — render multiple sets of primitives by specifying indices of array data elements
	GLCW_API void multiDrawElements(DrawMode mode, const int* count, DrawElementsType type, const void* const* indices, int drawcount);

	//glMultiDrawElementsBaseVertex — render multiple sets of primitives by specifying indices of array data elements and an index to apply to each index
	GLCW_API void multiDrawElementsBaseVertex(DrawMode mode, int* count, DrawElementsType type, void** indices, int drawcount, int* basevertex);
#endif

#if VC(4, 3)
	//glMultiDrawElementsIndirect — render indexed primitives from array data, taking parameters from memory
	GLCW_API void multiDrawElementsIndirect(DrawMode mode, DrawElementsType type, const void* indirect, int drawcount, int stride);
#endif

#if VC(4, 0)
	//glPatchParameter — specifies the parameters for patch primitives
	GLCW_API void patchParameteri(PatchParameter pname, int value);
	//glPatchParameter — specifies the parameters for patch primitives
	GLCW_API void patchParameterfv(PatchParameter pname, const float* values);
#endif

#if GL_DESKTOP
	//glPrimitiveRestartIndex — specify the primitive restart index
	GLCW_API void primitiveRestartIndex(unsigned int index);

	//glProvokingVertex — specifiy the vertex to be used as the source of data for flat shaded varyings
	GLCW_API void provokingVertex(ProvokeMode provokeMode);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glUnmapBuffer, glUnmapNamedBuffer — release the mapping of a buffer object's data store into the client's address space
	GLCW_API bool unmapBuffer(BufferTarget target);
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
	GLCW_API void vertexAttribP1uiv(unsigned int index, VertexAttribType type, bool normalized, const unsigned int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribP2uiv(unsigned int index, VertexAttribType type, bool normalized, const unsigned int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribP3uiv(unsigned int index, VertexAttribType type, bool normalized, const unsigned int* v);
	//glVertexAttrib — Specifies the value of a generic vertex attribute
	GLCW_API void vertexAttribP4uiv(unsigned int index, VertexAttribType type, bool normalized, const unsigned int* v);
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
	GLCW_API void vertexAttribFormat(unsigned int attribindex, int size, VertexAttribFormatType type, bool normalized, unsigned int relativeoffset);
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexAttribIFormat(unsigned int attribindex, int size, VertexAttribFormatType type, unsigned int relativeoffset);
#endif

#if VC(4, 3)
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexAttribLFormat(unsigned int attribindex, int size, VertexAttribFormatType type, unsigned int relativeoffset);
#endif
#if VC(4, 5)
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexArrayAttribFormat(unsigned int vaobj, unsigned int attribindex, int size, VertexAttribFormatType type, bool normalized, unsigned int relativeoffset);
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexArrayAttribIFormat(unsigned int vaobj, unsigned int attribindex, int size, VertexAttribFormatType type, unsigned int relativeoffset);
	//glVertexAttribFormat, glVertexArrayAttribFormat — specify the organization of vertex arrays
	GLCW_API void vertexArrayAttribLFormat(unsigned int vaobj, unsigned int attribindex, int size, VertexAttribFormatType type, unsigned int relativeoffset);
#endif

	//glVertexAttribPointer — define an array of generic vertex attribute data
	GLCW_API void vertexAttribPointer(unsigned int index, int size, BufferAttribPointerTypes type, bool normalized, int stride, const void* pointer);

#if GL_DESKTOP
	//glVertexAttribPointer — define an array of generic vertex attribute data
	GLCW_API void vertexAttribIPointer(unsigned int index, int size, BufferAttribPointerTypes type, int stride, const void* pointer);
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