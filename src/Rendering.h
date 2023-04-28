#pragma once

#include "API.h"
#include "GLM.h"

#include "BitfieldWrapper.h"

#include "Enums.h"

namespace GL
{
	static constexpr BITFIELD_WRAP(0x00004000) COLOR_BUFFER_BIT;
	static constexpr BITFIELD_WRAP(0x00000100) DEPTH_BUFFER_BIT;
	static constexpr BITFIELD_WRAP(0x00000400) STENCIL_BUFFER_BIT;

	namespace detail
	{
		GLCW_API void clear(unsigned int bitfield);
	}

	inline constexpr const char* COLOR_BUFFER_FILE = __FILE__;

	//glClear — clear buffers to preset values
	template <unsigned int final_bits>
	void clear(BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> bitfield)
	{
		detail::clear(bitfield.value);
	}

#if GL_DESKTOP || EC(3, 0)
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferiv(GL_ENUM buffer, int drawbuffer, const int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferuiv(GL_ENUM buffer, int drawbuffer, const unsigned int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferfv(GL_ENUM buffer, int drawbuffer, const float* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearBufferfi(GL_ENUM buffer, int drawbuffer, float depth, int stencil);
#endif

#if VC(4, 5)
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferiv(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, const int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferuiv(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, const unsigned int* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferfv(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, float* value);
	//glClearBuffer — clear individual buffers of a framebuffer
	GLCW_API void clearNamedFramebufferfi(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, float depth, int stencil);
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
	GLCW_API void drawBuffer(GL_ENUM buf);
#endif

#if VC(4, 5)
	//glDrawBuffer, glNamedFramebufferDrawBuffer — specify which color buffers are to be drawn into
	GLCW_API void namedFramebufferDrawBuffer(unsigned int framebuffer, GL_ENUM buf);
#endif

	//glFinish — block until all GL execution is complete
	GLCW_API void finish();

	//glFlush — force execution of GL commands in finite time
	GLCW_API void flush();

#if GL_DESKTOP || EC(3, 0)
	//glReadBuffer, glNamedFramebufferReadBuffer — select a color buffer source for pixels
	GLCW_API void readBuffer(GL_ENUM mode);
#endif

#if VC(4, 5)
	//glReadBuffer, glNamedFramebufferReadBuffer — select a color buffer source for pixels
	GLCW_API void namedFramebufferReadBuffer(unsigned int framebuffer, GL_ENUM mode);
#endif

	//glReadPixels, glReadnPixels — read a block of pixels from the frame buffe
	GLCW_API void readPixels(int x, int y, int width, int height, GL_ENUM format, GL_ENUM type, void* data);

#if VC(4, 5)
	//glReadPixels, glReadnPixels — read a block of pixels from the frame buffe
	GLCW_API void readnPixels(int x, int y, int width, int height, GL_ENUM format, GL_ENUM type, int bufSize, void* data);
#endif
}