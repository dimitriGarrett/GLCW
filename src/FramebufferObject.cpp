#include "FramebufferObject.h"
#include "GL.h"

inline void GL::bindFramebuffer(FramebufferTarget target, unsigned int framebuffer)
{
	glBindFramebuffer(static_cast<unsigned int>(target), framebuffer);
}

inline void GL::bindRenderbuffer(unsigned int renderbuffer)
{
	glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::detail::blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, FramebufferFilter filter)
{
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, static_cast<unsigned int>(filter));
}
#endif

#if VC(4, 5)
inline void GL::detail::blitNamedFramebuffer(unsigned int readFramebuffer, unsigned int drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, FramebufferFilter filter)
{
	glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, static_cast<unsigned int>(filter));
}
#endif

inline GL::FramebufferStatus GL::checkFramebufferStatus(FramebufferTarget target)
{
	return static_cast<FramebufferStatus>(glCheckFramebufferStatus(static_cast<unsigned int>(target)));
}

#if VC(4, 5)
inline GL::FramebufferStatus GL::checkNamedFramebufferStatus(unsigned int framebuffer, FramebufferTarget target)
{
	return static_cast<FramebufferStatus>(glCheckNamedFramebufferStatus(framebuffer, static_cast<unsigned int>(target)));
}

inline void GL::createFramebuffers(int n, unsigned int* ids)
{
	glCreateFramebuffers(n, ids);
}

inline void GL::createRenderbuffers(int n, unsigned int* renderbuffers)
{
	glCreateRenderbuffers(n, renderbuffers);
}
#endif

inline void GL::deleteFramebuffers(int n, const unsigned int* framebuffers)
{
	glDeleteFramebuffers(n, framebuffers);
}

inline void GL::deleteRenderbuffers(int n, const unsigned int* renderbuffers)
{
	glDeleteRenderbuffers(n, renderbuffers);
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::drawBuffers(int n, const FramebufferDrawPlacements* bufs)
{
	glDrawBuffers(n, reinterpret_cast<const unsigned int*>(bufs));
}

inline void GL::drawBuffers(const std::vector<FramebufferDrawPlacements>& bufs)
{
	glDrawBuffers(static_cast<int>(bufs.size()), reinterpret_cast<const unsigned int*>(&bufs.front()));
}
#endif

#if VC(4, 5)
inline void GL::namedFramebufferDrawBuffers(unsigned int framebuffer, int n, const FramebufferDrawPlacements* bufs)
{
	glNamedFramebufferDrawBuffers(framebuffer, n, reinterpret_cast<const unsigned int*>(bufs));
}

inline void GL::namedFramebufferDrawBuffers(unsigned int framebuffer, const std::vector<FramebufferDrawPlacements>& bufs)
{
	glNamedFramebufferDrawBuffers(framebuffer, static_cast<int>(bufs.size()), reinterpret_cast<const unsigned int*>(&bufs.front()));
}
#endif

#if VC(4, 3) || EC(3, 1)
inline void GL::framebufferParameteri(FramebufferTarget target, FramebufferParameterPnamei pname, int param)
{
	glFramebufferParameteri(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
}
#endif

#if VC(4, 5)
inline void GL::namedFramebufferParameteri(unsigned int framebuffer, FramebufferParameterPnamei pname, int param)
{
	glNamedFramebufferParameteri(framebuffer, static_cast<unsigned int>(pname), param);
}
#endif

inline void GL::framebufferRenderbuffer(FramebufferTarget target, FramebufferAttachmentPoint attachment, unsigned int renderbuffer)
{
	glFramebufferRenderbuffer(static_cast<unsigned int>(target), static_cast<unsigned int>(attachment), GL_RENDERBUFFER, renderbuffer);
}

#if VC(4, 5)
inline void GL::namedFramebufferRenderbuffer(unsigned int texture, FramebufferAttachmentPoint attachment, unsigned int renderbuffer)
{
	glNamedFramebufferRenderbuffer(texture, static_cast<unsigned int>(attachment), GL_RENDERBUFFER, renderbuffer);
}
#endif

inline void GL::framebufferTexture2D(FramebufferTarget target, FramebufferAttachmentPoint attachment, FramebufferTextureTarget textarget, unsigned int texture, int level)
{
	glFramebufferTexture2D(static_cast<unsigned int>(target), static_cast<unsigned int>(attachment), static_cast<unsigned int>(textarget), texture, level);
}

#if GL_DESKTOP
inline void GL::framebufferTexture(FramebufferTarget target, FramebufferAttachmentPoint attachment, unsigned int texture, int level)
{
	glFramebufferTexture(static_cast<unsigned int>(target), static_cast<unsigned int>(attachment), texture, level);
}

inline void GL::framebufferTexture1D(FramebufferTarget target, FramebufferAttachmentPoint attachment, unsigned int texture, int level)
{
	glFramebufferTexture1D(static_cast<unsigned int>(target), static_cast<unsigned int>(attachment), GL_TEXTURE_1D, texture, level);
}

inline void GL::framebufferTexture3D(FramebufferTarget target, FramebufferAttachmentPoint attachment, unsigned int texture, int level, int layer)
{
	glFramebufferTexture3D(static_cast<unsigned int>(target), static_cast<unsigned int>(attachment), GL_TEXTURE_3D, texture, level, layer);
}
#endif

#if VC(4, 5)
inline void GL::namedFramebufferTexture(unsigned int framebuffer, FramebufferAttachmentPoint attachment, unsigned int texture, int level)
{
	glNamedFramebufferTexture(framebuffer, static_cast<unsigned int>(attachment), texture, level);
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::framebufferTextureLayer(FramebufferTarget target, FramebufferAttachmentPoint attachment, unsigned int texture, int level, int layer)
{
	glFramebufferTextureLayer(static_cast<unsigned int>(target), static_cast<unsigned int>(attachment), texture, level, layer);
}
#endif

#if VC(4, 5)
inline void GL::namedFramebufferTextureLayer(unsigned int framebuffer, FramebufferAttachmentPoint attachment, unsigned int texture, int level, int layer)
{
	glNamedFramebufferTextureLayer(framebuffer, static_cast<unsigned int>(attachment), texture, level, layer);
}
#endif

inline void GL::genFramebuffers(int n, unsigned int* ids)
{
	glGenFramebuffers(n, ids);
}

inline void GL::genRenderbuffers(int n, unsigned int* renderbuffers)
{
	glGenRenderbuffers(n, renderbuffers);
}

inline void GL::generateMipmap(FramebufferMipmapTarget target)
{
	glGenerateMipmap(static_cast<unsigned int>(target));
}

#if VC(4, 5)
inline void GL::generateTextureMipmap(unsigned int texture)
{
	glGenerateTextureMipmap(texture);
}
#endif

inline void GL::getFramebufferAttachmentParameteriv(FramebufferTarget target, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname, int* params)
{
	glGetFramebufferAttachmentParameteriv(static_cast<unsigned int>(target), static_cast<unsigned int>(attachment), static_cast<unsigned int>(pname), params);
}

inline int GL::getFramebufferAttachmentParameteriv(FramebufferTarget target, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname)
{
	int temp;
	getFramebufferAttachmentParameteriv(target, attachment, pname, &temp);
	return temp;
}

#if VC(4, 5)
inline void GL::getNamedFramebufferAttachmentParameteriv(unsigned int framebuffer, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname, int* params)
{
	glGetNamedFramebufferAttachmentParameteriv(framebuffer, static_cast<unsigned int>(attachment), static_cast<unsigned int>(pname), params);
}

inline int GL::getNamedFramebufferAttachmentParameteriv(unsigned int framebuffer, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname)
{
	int temp;
	getNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, &temp);
	return temp;
}
#endif

#if VC(4, 3) || EC(3, 1)
inline void GL::getFramebufferParameteriv(FramebufferTarget target, FramebufferParameterMorePnamei pname, int* params)
{
	glGetFramebufferParameteriv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), params);
}

inline int GL::getFramebufferParameteriv(FramebufferTarget target, FramebufferParameterMorePnamei pname)
{
	int temp;
	getFramebufferParameteriv(target, pname, &temp);
	return temp;
}
#endif

#if VC(4, 5)
inline void GL::getNamedFramebufferParameteriv(unsigned int framebuffer, FramebufferParameterMorePnamei pname, int* params)
{
	glGetNamedFramebufferParameteriv(framebuffer, static_cast<unsigned int>(pname), params);
}

inline int GL::getNamedFramebufferParameteriv(unsigned int framebuffer, FramebufferParameterMorePnamei pname)
{
	int temp;
	getNamedFramebufferParameteriv(framebuffer, pname, &temp);
	return temp;
}
#endif

inline void GL::getRenderbufferParameteriv(RenderbufferParameterPnamei pname, int* params)
{
	glGetRenderbufferParameteriv(GL_RENDERBUFFER, static_cast<unsigned int>(pname), params);
}

inline int GL::getRenderbufferParameteriv(RenderbufferParameterPnamei pname)
{
	int temp;
	getRenderbufferParameteriv(pname, &temp);
	return temp;
}

#if VC(4, 5)
inline void GL::getNamedRenderbufferParameteriv(unsigned int renderbuffer, RenderbufferParameterPnamei pname, int* params)
{
	glGetNamedRenderbufferParameteriv(renderbuffer, static_cast<unsigned int>(pname), params);
}

inline int GL::getNamedRenderbufferParameteriv(unsigned int renderbuffer, RenderbufferParameterPnamei pname)
{
	int temp;
	getNamedRenderbufferParameteriv(renderbuffer, pname, &temp);
	return temp;
}
#endif

#if VC(4, 3) || EC(3, 0)
inline void GL::invalidateFramebuffer(FramebufferTarget target, int numAttachments, const FramebufferInvalidateAttachment* attachments)
{
	glInvalidateFramebuffer(static_cast<unsigned int>(target), numAttachments, reinterpret_cast<const unsigned int*>(attachments));
}

inline void GL::invalidateFramebuffer(FramebufferTarget target, const std::vector<FramebufferInvalidateAttachment>& attachments)
{
	glInvalidateFramebuffer(static_cast<unsigned int>(target), static_cast<int>(attachments.size()), reinterpret_cast<const unsigned int*>(&attachments.front()));
}
#endif

#if VC(4, 5)
inline void GL::invalidateNamedFramebufferData(unsigned int framebuffer, int numAttachments, const FramebufferInvalidateAttachment* attachments)
{
	glInvalidateNamedFramebufferData(framebuffer, numAttachments, reinterpret_cast<const unsigned int*>(attachments));
}

inline void GL::invalidateNamedFramebufferData(unsigned int framebuffer, const std::vector<FramebufferInvalidateAttachment>& attachments)
{
	glInvalidateNamedFramebufferData(framebuffer, static_cast<int>(attachments.size()), reinterpret_cast<const unsigned int*>(&attachments.front()));
}
#endif

#if VC(4, 3) || EC(3, 0)
inline void GL::invalidateSubFramebuffer(FramebufferTarget target, int numAttachments, const FramebufferInvalidateAttachment* attachments, int x, int y, int width, int height)
{
	glInvalidateSubFramebuffer(static_cast<unsigned int>(target), numAttachments, reinterpret_cast<const unsigned int*>(attachments), x, y, width, height);
}

inline void GL::invalidateSubFramebuffer(FramebufferTarget target, const std::vector<FramebufferInvalidateAttachment>& attachments, int x, int y, int width, int height)
{
	glInvalidateSubFramebuffer(static_cast<unsigned int>(target), static_cast<int>(attachments.size()), reinterpret_cast<const unsigned int*>(&attachments.front()), x, y, width, height);
}
#endif

#if VC(4, 5)
inline void GL::invalidateNamedFramebufferSubData(unsigned int framebuffer, int numAttachments, const FramebufferInvalidateAttachment* attachments, int x, int y, int width, int height)
{
	glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, reinterpret_cast<const unsigned int*>(attachments), x, y, width, height);
}

inline void GL::invalidateNamedFramebufferSubData(unsigned int framebuffer, const std::vector<FramebufferInvalidateAttachment>& attachments, int x, int y, int width, int height)
{
	glInvalidateNamedFramebufferSubData(framebuffer, static_cast<int>(attachments.size()), reinterpret_cast<const unsigned int*>(&attachments.front()), x, y, width, height);
}
#endif

inline bool GL::isFramebuffer(unsigned int framebuffer)
{
	return static_cast<bool>(glIsFramebuffer(framebuffer));
}

inline bool GL::isRenderbuffer(unsigned int renderbuffer)
{
	return static_cast<bool>(glIsRenderbuffer(renderbuffer));
}

inline void GL::renderbufferStorage(TextureInternalFormats internalformat, int width, int height)
{
	glRenderbufferStorage(GL_RENDERBUFFER, static_cast<unsigned int>(internalformat), width, height);
}

#if VC(4, 5)
inline void GL::namedRenderbufferStorage(unsigned int renderbuffer, TextureInternalFormats internalformat, int width, int height)
{
	glNamedRenderbufferStorage(renderbuffer, static_cast<unsigned int>(internalformat), width, height);
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::renderbufferStorageMultisample(int samples, TextureInternalFormats internalformat, int width, int height)
{
	glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, static_cast<unsigned int>(internalformat), width, height);
}
#endif

#if VC(4, 5)
inline void GL::namedRenderbufferStorageMultisample(unsigned int renderbuffer, int samples, TextureInternalFormats internalformat, int width, int height)
{
	glNamedRenderbufferStorageMultisample(renderbuffer, samples, static_cast<unsigned int>(internalformat), width, height);
}
#endif

#if GL_DESKTOP || EC(3, 1)
inline void GL::sampleMaski(unsigned int maskNumber, unsigned int mask)
{
	glSampleMaski(maskNumber, mask);
}
#endif