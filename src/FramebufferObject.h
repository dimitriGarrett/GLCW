#pragma once

#include "API.h"
#include "Enums.h"
#include "Rendering.h"

namespace GL
{
	namespace detail
	{
#if GL_DESKTOP || EC(3, 0)
		GLCW_API void blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, GL_ENUM filter);
#endif

#if VC(4, 5)
		GLCW_API void blitNamedFramebuffer(unsigned int readFramebuffer, unsigned int drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, GL_ENUM filter);
#endif
	}

	//glBindFramebuffer — bind a framebuffer to a framebuffer target
	GLCW_API void bindFramebuffer(GL_ENUM target, unsigned int framebuffer);

	//glBindRenderbuffer — bind a renderbuffer to a renderbuffer target
	GLCW_API void bindRenderbuffer(/*GL_RENDERBUFFER, */unsigned int renderbuffer);

#if GL_DESKTOP || EC(3, 0)
	//glBlitFramebuffer, glBlitNamedFramebuffer — copy a block of pixels from one framebuffer object to another
	template <unsigned int final_bits>
	void blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, BitfieldWrapper<cti::type_info(COLOR_BUFFER_FILE).hash(), final_bits> mask, GL_ENUM filter)
	{
		detail::blitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask.value, filter);
	}
#endif

#if VC(4, 5)
	//glBlitFramebuffer, glBlitNamedFramebuffer — copy a block of pixels from one framebuffer object to another
	template <unsigned int final_bits>
	void blitNamedFramebuffer(unsigned int readFramebuffer, unsigned int drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, BitfieldWrapper<cti::type_info(COLOR_BUFFER_FILE).hash(), final_bits> mask, GL_ENUM filter)
	{
		detail::blitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask.value, filter);
	}
#endif

	//glCheckFramebufferStatus, glCheckNamedFramebufferStatus — check the completeness status of a framebuffer
	GLCW_API GL_ENUM checkFramebufferStatus(GL_ENUM target);

#if VC(4, 5)
	//glCheckFramebufferStatus, glCheckNamedFramebufferStatus — check the completeness status of a framebuffer
	GLCW_API GL_ENUM checkNamedFramebufferStatus(unsigned int framebuffer, GL_ENUM target);

	//glCreateFramebuffers — create framebuffer objects
	GLCW_API void createFramebuffers(int n, unsigned int* ids);

	//glCreateRenderbuffers — create renderbuffer objects
	GLCW_API void createRenderbuffers(int n, unsigned int* renderbuffers);
#endif

	//glDeleteFramebuffers — delete framebuffer objects
	GLCW_API void deleteFramebuffers(int n, const unsigned int* framebuffers);

	//glDeleteRenderbuffers — delete renderbuffer objects
	GLCW_API void deleteRenderbuffers(int n, const unsigned int* renderbuffers);

#if GL_DESKTOP || EC(3, 0)
	//glDrawBuffers, glNamedFramebufferDrawBuffers — Specifies a list of color buffers to be drawn into
	GLCW_API void drawBuffers(int n, const GL_ENUM* bufs);
	//glDrawBuffers, glNamedFramebufferDrawBuffers — Specifies a list of color buffers to be drawn into
	GLCW_API void drawBuffers(const std::vector<GL_ENUM>& bufs);
#endif
#if VC(4, 5)
	//glDrawBuffers, glNamedFramebufferDrawBuffers — Specifies a list of color buffers to be drawn into
	GLCW_API void namedFramebufferDrawBuffers(unsigned int framebuffer, int n, const GL_ENUM* bufs);
	//glDrawBuffers, glNamedFramebufferDrawBuffers — Specifies a list of color buffers to be drawn into
	GLCW_API void namedFramebufferDrawBuffers(unsigned int framebuffer, const std::vector<GL_ENUM>& bufs);
#endif

#if VC(4, 3) || EC(3, 1)
	//glFramebufferParameteri, glNamedFramebufferParameteri — set a named parameter of a framebuffer object
	GLCW_API void framebufferParameteri(GL_ENUM target, GL_ENUM pname, int param);
#endif
#if VC(4, 5)
	//glFramebufferParameteri, glNamedFramebufferParameteri — set a named parameter of a framebuffer object
	GLCW_API void namedFramebufferParameteri(unsigned int framebuffer, GL_ENUM pname, int param);
#endif

	//glFramebufferRenderbuffer, glNamedFramebufferRenderbuffer — attach a renderbuffer as a logical buffer of a framebuffer object
	GLCW_API void framebufferRenderbuffer(GL_ENUM target, GL_ENUM attachment, /*GL_RENDERBUFFER, */unsigned int renderbuffer);

#if VC(4, 5)
	//glFramebufferRenderbuffer, glNamedFramebufferRenderbuffer — attach a renderbuffer as a logical buffer of a framebuffer object
	GLCW_API void namedFramebufferRenderbuffer(unsigned int texture, GL_ENUM attachment, /*GL_RENDERBUFFER, */unsigned int renderbuffer);
#endif

	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture2D(GL_ENUM target, GL_ENUM attachment, GL_ENUM textarget, unsigned int texture, int level);

#if GL_DESKTOP
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture(GL_ENUM target, GL_ENUM attachment, unsigned int texture, int level);
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture1D(GL_ENUM target, GL_ENUM attachment, /*GL_TEXTURE_1D, */unsigned int texture, int level);
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture3D(GL_ENUM target, GL_ENUM attachment, /*GL_TEXTURE_3D, */unsigned int texture, int level, int layer);
#endif

#if VC(4, 5)
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void namedFramebufferTexture(unsigned int framebuffer, GL_ENUM attachment, unsigned int texture, int level);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glFramebufferTextureLayer, glNamedFramebufferTextureLayer — attach a single layer of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTextureLayer(GL_ENUM target, GL_ENUM attachment, unsigned int texture, int level, int layer);
#endif

#if VC(4, 5)
	//glFramebufferTextureLayer, glNamedFramebufferTextureLayer — attach a single layer of a texture object as a logical buffer of a framebuffer object
	GLCW_API void namedFramebufferTextureLayer(unsigned int framebuffer, GL_ENUM attachment, unsigned int texture, int level, int layer);
#endif

	//glGenFramebuffers — generate framebuffer object names
	GLCW_API void genFramebuffers(int n, unsigned int* ids);

	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API void genRenderbuffers(int n, unsigned int* renderbuffers);

	//glGenerateMipmap, glGenerateTextureMipmap — generate mipmaps for a specified texture object
	GLCW_API void generateMipmap(GL_ENUM target);

#if VC(4, 5)
	//glGenerateMipmap, glGenerateTextureMipmap — generate mipmaps for a specified texture object
	GLCW_API void generateTextureMipmap(unsigned int texture);
#endif

	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API void getFramebufferAttachmentParameteriv(GL_ENUM target, GL_ENUM attachment, GL_ENUM pname, int* params);
	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API int getFramebufferAttachmentParameteriv(GL_ENUM target, GL_ENUM attachment, GL_ENUM pname);

#if VC(4, 5)
	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API void getNamedFramebufferAttachmentParameteriv(unsigned int framebuffer, GL_ENUM attachment, GL_ENUM pname, int* params);
	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API int getNamedFramebufferAttachmentParameteriv(unsigned int framebuffer, GL_ENUM attachment, GL_ENUM pname);
#endif

#if VC(4, 3) || EC(3, 1)
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API void getFramebufferParameteriv(GL_ENUM target, GL_ENUM pname, int* params);
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API int getFramebufferParameteriv(GL_ENUM target, GL_ENUM pname);
#endif

#if VC(4, 5)
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API void getNamedFramebufferParameteriv(unsigned int framebuffer, GL_ENUM pname, int* params);
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API int getNamedFramebufferParameteriv(unsigned int framebuffer, GL_ENUM pname);
#endif

	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API void getRenderbufferParameteriv(/*GL_RENDERBUFFER, */GL_ENUM pname, int* params);
	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API int getRenderbufferParameteriv(/*GL_RENDERBUFFER, */GL_ENUM pname);

#if VC(4, 5)
	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API void getNamedRenderbufferParameteriv(unsigned int renderbuffer, GL_ENUM pname, int* params);
	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API int getNamedRenderbufferParameteriv(unsigned int renderbuffer, GL_ENUM pname);
#endif

#if VC(4, 3) || EC(3, 0)
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateFramebuffer(GL_ENUM target, int numAttachments, const GL_ENUM* attachments);
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateFramebuffer(GL_ENUM target, const std::vector<GL_ENUM>& attachments);
#endif

#if VC(4, 5)
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferData(unsigned int framebuffer, int numAttachments, const GL_ENUM* attachments);
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferData(unsigned int framebuffer, const std::vector<GL_ENUM>& attachments);
#endif

#if VC(4, 3) || EC(3, 0)
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateSubFramebuffer(GL_ENUM target, int numAttachments, const GL_ENUM* attachments, int x, int y, int width, int height);
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateSubFramebuffer(GL_ENUM target, const std::vector<GL_ENUM>& attachments, int x, int y, int width, int height);
#endif
#if VC(4, 5)
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferSubData(unsigned int framebuffer, int numAttachments, const GL_ENUM* attachments, int x, int y, int width, int height);
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferSubData(unsigned int framebuffer, const std::vector<GL_ENUM>& attachments, int x, int y, int width, int height);
#endif

	//glIsFramebuffer — determine if a name corresponds to a framebuffer object
	GLCW_API bool isFramebuffer(unsigned int framebuffer);

	//glIsRenderbuffer — determine if a name corresponds to a renderbuffer object
	GLCW_API bool isRenderbuffer(unsigned int renderbuffer);

	//glRenderbufferStorage, glNamedRenderbufferStorage — establish data storage, format and dimensions of a renderbuffer object's image
	GLCW_API void renderbufferStorage(/*GL_RENDERBUFFER, */GL_ENUM internalformat, int width, int height);

#if VC(4, 5)
	//glRenderbufferStorage, glNamedRenderbufferStorage — establish data storage, format and dimensions of a renderbuffer object's image
	GLCW_API void namedRenderbufferStorage(unsigned int renderbuffer, GL_ENUM internalformat, int width, int height);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glRenderbufferStorageMultisample, glNamedRenderbufferStorageMultisample — establish data storage, format, dimensions and sample count of a renderbuffer object's image
	GLCW_API void renderbufferStorageMultisample(/*GL_RENDERBUFFER, */int samples, GL_ENUM internalformat, int width, int height);
#endif
#if VC(4, 5)
	//glRenderbufferStorageMultisample, glNamedRenderbufferStorageMultisample — establish data storage, format, dimensions and sample count of a renderbuffer object's image
	GLCW_API void namedRenderbufferStorageMultisample(unsigned int renderbuffer, int samples, GL_ENUM internalformat, int width, int height);
#endif

#if GL_DESKTOP || EC(3, 1)
	//glSampleMaski — set the value of a sub-word of the sample mask
	GLCW_API void sampleMaski(unsigned int maskNumber, unsigned int mask);
#endif
}