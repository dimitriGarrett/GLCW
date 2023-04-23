#pragma once

#include "API.h"
#include "GLM.h"

#include "BitfieldWrapper.h"

#include "Config.h"

namespace GL
{
	enum class RenderingBuffers : unsigned int
	{
		COLOR = 0x1800,
		DEPTH = 0x1801,
		STENCIL = 0x1802,
		DEPTH_STENCIL = 0x84F9
	};

	enum class RenderingBufferTargets : unsigned int
	{
		BACK = 0x0405,
		NONE = 0,

#if GL_DESKTOP
		FRONT_LEFT = 0x0400,
		FRONT_RIGHT = 0x0401,
		BACK_LEFT = 0x0402,
		BACK_RIGHT = 0x0403,
		FRONT = 0x0404,
		LEFT = 0x0406,
		RIGHT = 0x0407,
		FRONT_AND_BACK = 0x0408,
#endif
		COLOR_ATTACHMENT0 = 0x8CE0,
		COLOR_ATTACHMENT1 = 0x8CE1,
		COLOR_ATTACHMENT2 = 0x8CE2,
		COLOR_ATTACHMENT3 = 0x8CE3,
		COLOR_ATTACHMENT4 = 0x8CE4,
		COLOR_ATTACHMENT5 = 0x8CE5,
		COLOR_ATTACHMENT6 = 0x8CE6,
		COLOR_ATTACHMENT7 = 0x8CE7,
		COLOR_ATTACHMENT8 = 0x8CE8,
		COLOR_ATTACHMENT9 = 0x8CE9,
		COLOR_ATTACHMENT10 = 0x8CEA,
		COLOR_ATTACHMENT11 = 0x8CEB,
		COLOR_ATTACHMENT12 = 0x8CEC,
		COLOR_ATTACHMENT13 = 0x8CED,
		COLOR_ATTACHMENT14 = 0x8CEE,
		COLOR_ATTACHMENT15 = 0x8CEF
	};

	enum class ReadPixelType : unsigned int
	{
		UNSIGNED_BYTE = 0x1401,
		UNSIGNED_INT = 0x1405,
		UNSIGNED_INT_2_10_10_10_REV = 0x8368,
		INT = 0x1404,
		FLOAT = 0x1406,
		
#if GL_DESKTOP
		BYTE = 0x1400,
		UNSIGNED_SHORT = 0x1403,
		SHORT = 0x1402,
		HALF_FLOAT = 0x140B,
		UNSIGNED_SHORT_5_6_5 = 0x8363,
		UNSIGNED_SHORT_4_4_4_4 = 0x8033,
		UNSIGNED_SHORT_4_4_4_4_REV = 0x8365,
		UNSIGNED_SHORT_5_5_5_1 = 0x8034,
		UNSIGNED_SHORT_1_5_5_5_REV = 0x8366,
		UNSIGNED_INT_8_8_8_8 = 0x8035,
		UNSIGNED_INT_8_8_8_8_REV = 0x8367,
		UNSIGNED_INT_10_10_10_2 = 0x8036,
		UNSIGNED_INT_24_8 = 0x84FA,
		UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B,
		UNSIGNED_INT_5_9_9_9_REV = 0x8C3E,
		FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD,
#endif
	};

	enum class RenderingFormats
	{
		RGBA = 0x1908,

#if GL_DESKTOP
		STENCIL_INDEX = 0x1901,
		DEPTH_COMPONENT = 0x1902,
		DEPTH_STENCIL = 0x84F9,
		RED = 0x1903,
		GREEN = 0x1904,
		BLUE = 0x1905,
		RGB = 0x1907,
		BGR = 0x80E0,
		BGRA = 0x80E1,
#else 
		RGBA_INTEGER = 0x8D99,
#endif
	};

	static constexpr BITFIELD_WRAP(0x00004000) COLOR_BUFFER_BIT;
	static constexpr BITFIELD_WRAP(0x00000100) DEPTH_BUFFER_BIT;
	static constexpr BITFIELD_WRAP(0x00000400) STENCIL_BUFFER_BIT;

	namespace detail
	{
		GLCW_API void clear(unsigned int bitfield);
	}

	static constexpr const char* COLOR_BUFFER_FILE = __FILE__;

	//glClear — clear buffers to preset values
	template <unsigned int final_bits>
	void clear(BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> bitfield)
	{
		detail::clear(bitfield.value);
	}

#if GL_DESKTOP || EC(3, 0)
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferiv(RenderingBuffers buffer, int drawbuffer, const int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferuiv(RenderingBuffers buffer, int drawbuffer, const unsigned int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferfv(RenderingBuffers buffer, int drawbuffer, const float* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferfi(RenderingBuffers buffer, int drawbuffer, float depth, int stencil);
#endif

#if VC(4, 5)
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferiv(unsigned int framebuffer, RenderingBuffers buffer, int drawbuffer, const int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferuiv(unsigned int framebuffer, RenderingBuffers buffer, int drawbuffer, const unsigned int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferfv(unsigned int framebuffer, RenderingBuffers buffer, int drawbuffer, float* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferfi(unsigned int framebuffer, RenderingBuffers buffer, int drawbuffer, float depth, int stencil);
#endif

	//glClearColor — specify clear values for the color buffers
	GLCW_API void clearColor(float red, float green, float blue, float alpha);
	//glClearColor — specify clear values for the color buffers
	GLCW_API inline void clearColor(const glm::vec4& rgba)
	{
		clearColor(rgba.r, rgba.g, rgba.b, rgba.a);
	}

#if GL_DESKTOP
	//glClearDepth — specify the clear value for the depth buffer
	GLCW_API void clearDepth(double depth);
#endif

#if VC(4, 1) || (!GL_DESKTOP)
	//glClearDepth — specify the clear value for the depth buffer
	GLCW_API void clearDepthf(float depth);
#endif

	//glClearStencil — specify the clear value for the stencil buffer
	GLCW_API void clearStencil(int s);

#if GL_DESKTOP
	//glDrawBuffer, glNamedFramebufferDrawBuffer — specify which color buffers are to be drawn into
	GLCW_API void drawBuffer(RenderingBufferTargets buf);
#endif

#if VC(4, 5)
	//glDrawBuffer, glNamedFramebufferDrawBuffer — specify which color buffers are to be drawn into
	GLCW_API void namedFramebufferDrawBuffer(unsigned int framebuffer, RenderingBufferTargets buf);
#endif

	//glFinish — block until all GL execution is complete
	GLCW_API void finish();

	//glFlush — force execution of GL commands in finite time
	GLCW_API void flush();

#if GL_DESKTOP || EC(3, 0)
	//glReadBuffer, glNamedFramebufferReadBuffer — select a color buffer source for pixels
	GLCW_API void readBuffer(RenderingBufferTargets mode);
#endif

#if VC(4, 5)
	//glReadBuffer, glNamedFramebufferReadBuffer — select a color buffer source for pixels
	GLCW_API void namedFramebufferReadBuffer(unsigned int framebuffer, RenderingBufferTargets mode);
#endif

	//glReadPixels, glReadnPixels — read a block of pixels from the frame buffe
	GLCW_API void readPixels(int x, int y, int width, int height, RenderingFormats format, ReadPixelType type, void* data);

#if VC(4, 5)
	//glReadPixels, glReadnPixels — read a block of pixels from the frame buffe
	GLCW_API void readnPixels(int x, int y, int width, int height, RenderingFormats format, ReadPixelType type, int bufSize, void* data);
#endif
}