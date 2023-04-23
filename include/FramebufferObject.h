#pragma once

#include "Textures.h"
#include "Rendering.h"

namespace GL
{
	enum class FramebufferMipmapTarget : unsigned int
	{
#if GL_DESKTOP
		TEXTURE_1D = 0x0DE0,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
#endif

		TEXTURE_2D = 0x0DE1,
		TEXTURE_3D = 0x806F,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_CUBE_MAP = 0x8513,
	};

	enum class FramebufferStatus : unsigned int
	{
		ERROR_RETURNED = 0,
		FRAMEBUFFER_COMPLETE = 0x8CD5,
		FRAMEBUFFER_UNDEFINED = 0x8219,
		FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
		FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
		FRAMEBUFFER_UNSUPPORTED = 0x8CDD,
		FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56,

#if GL_DESKTOP
		FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB,
		FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC,
		FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8,
#endif
	};

	enum class FramebufferTarget : unsigned int
	{
		READ_FRAMEBUFFER = 0x8CA8,
		DRAW_FRAMEBUFFER = 0x8CA9,
		FRAMEBUFFER = 0x8D40
	};

	enum class FramebufferFilter : unsigned int
	{
		NEAREST = 0x2600,
		LINEAR = 0x2601
	};

	enum class FramebufferDrawPlacements : unsigned int
	{
#if GL_DESKTOP
		FRONT_LEFT = 0x0400,
		FRONT_RIGHT = 0x0401,
		BACK_LEFT = 0x0402,
		BACK_RIGHT = 0x0403,
#else
		BACK = 0x0405,
#endif

		NONE = 0,
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
		COLOR_ATTACHMENT15 = 0x8CEF,
	};

#if VC(4, 3) || EC(3, 1)
	enum class FramebufferParameterPnamei : unsigned int
	{
#if GL_DESKTOP
		FRAMEBUFFER_DEFAULT_LAYERS = 0x9312,
#endif

		FRAMEBUFFER_DEFAULT_WIDTH = 0x9310,
		FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311,
		FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313,
		FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314
	};
#endif

	enum class FramebufferAttachmentPoint : unsigned int
	{
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
		COLOR_ATTACHMENT15 = 0x8CEF,

		DEPTH_ATTACHMENT = 0x8D00,
		STENCIL_ATTACHMENT = 0x8D20,
		DEPTH_STENCIL_ATTACHMENT = 0x821A
	};

	enum class FramebufferTextureTarget : unsigned int
	{
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,

		TEXTURE_RECTANGLE = 0x84F5,

		TEXTURE_2D_MULTISAMPLE = 0x9100,
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,

		TEXTURE_2D = 0x0DE1,
	};

	enum class FramebufferAttachmentParameterPname : unsigned int
	{
		FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
		FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212,
		FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213,
		FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214,
		FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215,
		FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216,
		FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217,
		FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211,
		FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210,
		FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,

#if GL_DESKTOP
		FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7,
#endif

		FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4
	};

#if VC(4, 3) || EC(3, 1)
	enum class FramebufferParameterMorePnamei : unsigned int
	{
		FRAMEBUFFER_DEFAULT_WIDTH = 0x9310,
		FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311,
		FRAMEBUFFER_DEFAULT_LAYERS = 0x9312,
		FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313,
		FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314,

#if VC(4, 5)
		DOUBLEBUFFER = 0x0C32,
		IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A,
		IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
		SAMPLES = 0x80A9,
		SAMPLE_BUFFERS = 0x80A8,
		STEREO = 0x0C33
#endif
	};
#endif

	enum class RenderbufferParameterPnamei : unsigned int
	{
		RENDERBUFFER_WIDTH = 0x8D42,
		RENDERBUFFER_HEIGHT = 0x8D43,
		RENDERBUFFER_INTERNAL_FORMAT = 0x8D44,
		RENDERBUFFER_SAMPLES = 0x8CAB,

		RENDERBUFFER_RED_SIZE = 0x8D50,
		RENDERBUFFER_GREEN_SIZE = 0x8D51,
		RENDERBUFFER_BLUE_SIZE = 0x8D52,
		RENDERBUFFER_ALPHA_SIZE = 0x8D53,
		RENDERBUFFER_DEPTH_SIZE = 0x8D54,
		RENDERBUFFER_STENCIL_SIZE = 0x8D55
	};

	enum class FramebufferInvalidateAttachment : unsigned int
	{
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
		COLOR_ATTACHMENT15 = 0x8CEF,

		DEPTH_ATTACHMENT = 0x8D00,
		STENCIL_ATTACHMENT = 0x8D20,
		DEPTH_STENCIL_ATTACHMENT = 0x821A,

		FRONT_LEFT = 0x0400,
		FRONT_RIGHT = 0x0401,
		BACK_LEFT = 0x0402,
		BACK_RIGHT = 0x0403,
		AUX0 = 0x0409,
		AUX1 = 0x040A,
		AUX2 = 0x040B,
		AUX3 = 0x040C,
		ACCUM = 0x0100,
		COLOR = 0x1800,
		DEPTH = 0x1801,
		STENCIL = 0x1802
	};

	namespace detail
	{
#if GL_DESKTOP || EC(3, 0)
		GLCW_API void blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, FramebufferFilter filter);
#endif

#if VC(4, 5)
		GLCW_API void blitNamedFramebuffer(unsigned int readFramebuffer, unsigned int drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, FramebufferFilter filter);
#endif
	}

	//glBindFramebuffer — bind a framebuffer to a framebuffer target
	GLCW_API void bindFramebuffer(FramebufferTarget target, unsigned int framebuffer);

	//glBindRenderbuffer — bind a renderbuffer to a renderbuffer target
	GLCW_API void bindRenderbuffer(/*GL_RENDERBUFFER, */unsigned int renderbuffer);

#if GL_DESKTOP || EC(3, 0)
	//glBlitFramebuffer, glBlitNamedFramebuffer — copy a block of pixels from one framebuffer object to another
	template <unsigned int final_bits>
	void blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, BitfieldWrapper<cti::type_info(COLOR_BUFFER_FILE).hash(), final_bits> mask, FramebufferFilter filter)
	{
		detail::blitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask.value, filter);
	}
#endif

#if VC(4, 5)
	//glBlitFramebuffer, glBlitNamedFramebuffer — copy a block of pixels from one framebuffer object to another
	template <unsigned int final_bits>
	void blitNamedFramebuffer(unsigned int readFramebuffer, unsigned int drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, BitfieldWrapper<cti::type_info(COLOR_BUFFER_FILE).hash(), final_bits> mask, FramebufferFilter filter)
	{
		detail::blitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask.value, filter);
	}
#endif

	//glCheckFramebufferStatus, glCheckNamedFramebufferStatus — check the completeness status of a framebuffer
	GLCW_API FramebufferStatus checkFramebufferStatus(FramebufferTarget target);

#if VC(4, 5)
	//glCheckFramebufferStatus, glCheckNamedFramebufferStatus — check the completeness status of a framebuffer
	GLCW_API FramebufferStatus checkNamedFramebufferStatus(unsigned int framebuffer, FramebufferTarget target);

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
	GLCW_API void drawBuffers(int n, const FramebufferDrawPlacements* bufs);
	//glDrawBuffers, glNamedFramebufferDrawBuffers — Specifies a list of color buffers to be drawn into
	GLCW_API void drawBuffers(const std::vector<FramebufferDrawPlacements>& bufs);
#endif
#if VC(4, 5)
	//glDrawBuffers, glNamedFramebufferDrawBuffers — Specifies a list of color buffers to be drawn into
	GLCW_API void namedFramebufferDrawBuffers(unsigned int framebuffer, int n, const FramebufferDrawPlacements* bufs);
	//glDrawBuffers, glNamedFramebufferDrawBuffers — Specifies a list of color buffers to be drawn into
	GLCW_API void namedFramebufferDrawBuffers(unsigned int framebuffer, const std::vector<FramebufferDrawPlacements>& bufs);
#endif

#if VC(4, 3) || EC(3, 1)
	//glFramebufferParameteri, glNamedFramebufferParameteri — set a named parameter of a framebuffer object
	GLCW_API void framebufferParameteri(FramebufferTarget target, FramebufferParameterPnamei pname, int param);
#endif
#if VC(4, 5)
	//glFramebufferParameteri, glNamedFramebufferParameteri — set a named parameter of a framebuffer object
	GLCW_API void namedFramebufferParameteri(unsigned int framebuffer, FramebufferParameterPnamei pname, int param);
#endif

	//glFramebufferRenderbuffer, glNamedFramebufferRenderbuffer — attach a renderbuffer as a logical buffer of a framebuffer object
	GLCW_API void framebufferRenderbuffer(FramebufferTarget target, FramebufferAttachmentPoint attachment, /*GL_RENDERBUFFER, */unsigned int renderbuffer);

#if VC(4, 5)
	//glFramebufferRenderbuffer, glNamedFramebufferRenderbuffer — attach a renderbuffer as a logical buffer of a framebuffer object
	GLCW_API void namedFramebufferRenderbuffer(unsigned int texture, FramebufferAttachmentPoint attachment, /*GL_RENDERBUFFER, */unsigned int renderbuffer);
#endif

	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture2D(FramebufferTarget target, FramebufferAttachmentPoint attachment, FramebufferTextureTarget textarget, unsigned int texture, int level);

#if GL_DESKTOP
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture(FramebufferTarget target, FramebufferAttachmentPoint attachment, unsigned int texture, int level);
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture1D(FramebufferTarget target, FramebufferAttachmentPoint attachment, /*GL_TEXTURE_1D, */unsigned int texture, int level);
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTexture3D(FramebufferTarget target, FramebufferAttachmentPoint attachment, /*GL_TEXTURE_3D, */unsigned int texture, int level, int layer);
#endif

#if VC(4, 5)
	//glFramebufferTexture — attach a level of a texture object as a logical buffer of a framebuffer object
	GLCW_API void namedFramebufferTexture(unsigned int framebuffer, FramebufferAttachmentPoint attachment, unsigned int texture, int level);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glFramebufferTextureLayer, glNamedFramebufferTextureLayer — attach a single layer of a texture object as a logical buffer of a framebuffer object
	GLCW_API void framebufferTextureLayer(FramebufferTarget target, FramebufferAttachmentPoint attachment, unsigned int texture, int level, int layer);
#endif

#if VC(4, 5)
	//glFramebufferTextureLayer, glNamedFramebufferTextureLayer — attach a single layer of a texture object as a logical buffer of a framebuffer object
	GLCW_API void namedFramebufferTextureLayer(unsigned int framebuffer, FramebufferAttachmentPoint attachment, unsigned int texture, int level, int layer);
#endif

	//glGenFramebuffers — generate framebuffer object names
	GLCW_API void genFramebuffers(int n, unsigned int* ids);

	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API void genRenderbuffers(int n, unsigned int* renderbuffers);

	//glGenerateMipmap, glGenerateTextureMipmap — generate mipmaps for a specified texture object
	GLCW_API void generateMipmap(FramebufferMipmapTarget target);

#if VC(4, 5)
	//glGenerateMipmap, glGenerateTextureMipmap — generate mipmaps for a specified texture object
	GLCW_API void generateTextureMipmap(unsigned int texture);
#endif

	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API void getFramebufferAttachmentParameteriv(FramebufferTarget target, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname, int* params);
	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API int getFramebufferAttachmentParameteriv(FramebufferTarget target, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname);

#if VC(4, 5)
	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API void getNamedFramebufferAttachmentParameteriv(unsigned int framebuffer, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname, int* params);
	//glGenRenderbuffers — generate renderbuffer object names
	GLCW_API int getNamedFramebufferAttachmentParameteriv(unsigned int framebuffer, FramebufferAttachmentPoint attachment, FramebufferAttachmentParameterPname pname);
#endif

#if VC(4, 3) || EC(3, 1)
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API void getFramebufferParameteriv(FramebufferTarget target, FramebufferParameterMorePnamei pname, int* params);
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API int getFramebufferParameteriv(FramebufferTarget target, FramebufferParameterMorePnamei pname);
#endif

#if VC(4, 5)
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API void getNamedFramebufferParameteriv(unsigned int framebuffer, FramebufferParameterMorePnamei pname, int* params);
	//glGetFramebufferParameteriv, glGetNamedFramebufferParameteriv — query a named parameter of a framebuffer object
	GLCW_API int getNamedFramebufferParameteriv(unsigned int framebuffer, FramebufferParameterMorePnamei pname);
#endif

	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API void getRenderbufferParameteriv(/*GL_RENDERBUFFER, */RenderbufferParameterPnamei pname, int* params);
	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API int getRenderbufferParameteriv(/*GL_RENDERBUFFER, */RenderbufferParameterPnamei pname);

#if VC(4, 5)
	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API void getNamedRenderbufferParameteriv(unsigned int renderbuffer, RenderbufferParameterPnamei pname, int* params);
	//glGetRenderbufferParameteriv, glGetNamedRenderbufferParameteriv — query a named parameter of a renderbuffer object
	GLCW_API int getNamedRenderbufferParameteriv(unsigned int renderbuffer, RenderbufferParameterPnamei pname);
#endif

#if VC(4, 3) || EC(3, 0)
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateFramebuffer(FramebufferTarget target, int numAttachments, const FramebufferInvalidateAttachment* attachments);
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateFramebuffer(FramebufferTarget target, const std::vector<FramebufferInvalidateAttachment>& attachments);
#endif

#if VC(4, 5)
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferData(unsigned int framebuffer, int numAttachments, const FramebufferInvalidateAttachment* attachments);
	//glInvalidateFramebuffer, glInvalidateNamedFramebufferData — invalidate the content of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferData(unsigned int framebuffer, const std::vector<FramebufferInvalidateAttachment>& attachments);
#endif

#if VC(4, 3) || EC(3, 0)
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateSubFramebuffer(FramebufferTarget target, int numAttachments, const FramebufferInvalidateAttachment* attachments, int x, int y, int width, int height);
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateSubFramebuffer(FramebufferTarget target, const std::vector<FramebufferInvalidateAttachment>& attachments, int x, int y, int width, int height);
#endif
#if VC(4, 5)
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferSubData(unsigned int framebuffer, int numAttachments, const FramebufferInvalidateAttachment* attachments, int x, int y, int width, int height);
	//glInvalidateSubFramebuffer, glInvalidateNamedFramebufferSubData — invalidate the content of a region of some or all of a framebuffer's attachments
	GLCW_API void invalidateNamedFramebufferSubData(unsigned int framebuffer, const std::vector<FramebufferInvalidateAttachment>& attachments, int x, int y, int width, int height);
#endif

	//glIsFramebuffer — determine if a name corresponds to a framebuffer object
	GLCW_API bool isFramebuffer(unsigned int framebuffer);

	//glIsRenderbuffer — determine if a name corresponds to a renderbuffer object
	GLCW_API bool isRenderbuffer(unsigned int renderbuffer);

	//glRenderbufferStorage, glNamedRenderbufferStorage — establish data storage, format and dimensions of a renderbuffer object's image
	GLCW_API void renderbufferStorage(/*GL_RENDERBUFFER, */TextureInternalFormats internalformat, int width, int height);

#if VC(4, 5)
	//glRenderbufferStorage, glNamedRenderbufferStorage — establish data storage, format and dimensions of a renderbuffer object's image
	GLCW_API void namedRenderbufferStorage(unsigned int renderbuffer, TextureInternalFormats internalformat, int width, int height);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glRenderbufferStorageMultisample, glNamedRenderbufferStorageMultisample — establish data storage, format, dimensions and sample count of a renderbuffer object's image
	GLCW_API void renderbufferStorageMultisample(/*GL_RENDERBUFFER, */int samples, TextureInternalFormats internalformat, int width, int height);
#endif
#if VC(4, 5)
	//glRenderbufferStorageMultisample, glNamedRenderbufferStorageMultisample — establish data storage, format, dimensions and sample count of a renderbuffer object's image
	GLCW_API void namedRenderbufferStorageMultisample(unsigned int renderbuffer, int samples, TextureInternalFormats internalformat, int width, int height);
#endif

#if GL_DESKTOP || EC(3, 1)
	//glSampleMaski — set the value of a sub-word of the sample mask
	GLCW_API void sampleMaski(unsigned int maskNumber, unsigned int mask);
#endif
}