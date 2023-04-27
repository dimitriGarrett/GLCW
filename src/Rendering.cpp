#include "Rendering.h"

#include "GL.h"

inline void GL::detail::clear(unsigned int bitfield)
{
	glClear(bitfield);
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::clearBufferiv(GL_ENUM buffer, int drawbuffer, const int* value)
{
	glClearBufferiv(static_cast<unsigned int>(buffer), drawbuffer, value);
}

inline void GL::clearBufferuiv(GL_ENUM buffer, int drawbuffer, const unsigned int* value)
{
	glClearBufferuiv(static_cast<unsigned int>(buffer), drawbuffer, value);
}

inline void GL::clearBufferfv(GL_ENUM buffer, int drawbuffer, const float* value)
{
	glClearBufferfv(static_cast<unsigned int>(buffer), drawbuffer, value);
}

inline void GL::clearBufferfi(GL_ENUM buffer, int drawbuffer, float depth, int stencil)
{
	glClearBufferfi(static_cast<unsigned int>(buffer), drawbuffer, depth, stencil);
}
#endif

#if VC(4, 5)
inline void GL::clearNamedFramebufferiv(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, const int* value)
{
	glClearNamedFramebufferiv(framebuffer, static_cast<unsigned int>(buffer), drawbuffer, value);
}

inline void GL::clearNamedFramebufferuiv(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, const unsigned int* value)
{
	glClearNamedFramebufferuiv(framebuffer, static_cast<unsigned int>(buffer), drawbuffer, value);
}

inline void GL::clearNamedFramebufferfv(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, float* value)
{
	glClearNamedFramebufferfv(framebuffer, static_cast<unsigned int>(buffer), drawbuffer, value);
}

inline void GL::clearNamedFramebufferfi(unsigned int framebuffer, GL_ENUM buffer, int drawbuffer, float depth, int stencil)
{
	glClearNamedFramebufferfi(framebuffer, static_cast<unsigned int>(buffer), drawbuffer, depth, stencil);
}
#endif

inline void GL::clearColor(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
}

#if GL_DESKTOP
inline void GL::clearDepth(double depth)
{
	glClearDepth(depth);
}
#endif

#if VC(4, 1) || (!GL_DESKTOP)
inline void GL::clearDepthf(float depth)
{
	glClearDepthf(depth);
}
#endif

inline void GL::clearStencil(int s)
{
	glClearStencil(s);
}

#if GL_DESKTOP
inline void GL::drawBuffer(GL_ENUM buf)
{
	glDrawBuffer(static_cast<unsigned int>(buf));
}
#endif

#if VC(4, 5)
inline void GL::namedFramebufferDrawBuffer(unsigned int framebuffer, GL_ENUM buf)
{
	glNamedFramebufferDrawBuffer(framebuffer, static_cast<unsigned int>(buf));
}
#endif

inline void GL::finish()
{
	glFinish();
}

inline void GL::flush()
{
	glFlush();
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::readBuffer(GL_ENUM mode)
{
	glReadBuffer(static_cast<unsigned int>(mode));
}
#endif

#if VC(4, 5)
inline void GL::namedFramebufferReadBuffer(unsigned int framebuffer, GL_ENUM mode)
{
	glNamedFramebufferReadBuffer(framebuffer, static_cast<unsigned int>(mode));
}
#endif

inline void GL::readPixels(int x, int y, int width, int height, GL_ENUM format, GL_ENUM type, void* data)
{
	glReadPixels(x, y, width, height, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
}

#if VC(4, 5)
inline void GL::readnPixels(int x, int y, int width, int height, GL_ENUM format, GL_ENUM type, int bufSize, void* data)
{
	glReadnPixels(x, y, width, height, static_cast<unsigned int>(format), static_cast<unsigned int>(type), bufSize, data);
}
#endif