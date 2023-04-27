#include "Textures.h"
#include "GL.h"

#include <cassert>
#include "State.h"

inline void GL::activeTexture(unsigned int offset)
{
	// offset is not GL_TEXTUREi, it is in the range of 0 - MAX_COMBINED_TEXTURE_IMAGE_UNITS
	// offset gets added to GL_TEXTUREi
	assert(offset < getIntegerv(MAX_COMBINED_TEXTURE_IMAGE_UNITS) - 1);

	glActiveTexture(GL_TEXTURE0 + offset);
}

#if VC(4, 2) || EC(3, 1)
	inline void GL::bindImageTexture(unsigned int unit, unsigned int texture, int level, bool layered, int layer, GL_ENUM access, GL_ENUM format)
	{
		glBindImageTexture(unit, texture, level, layered, layer, static_cast<unsigned int>(access), static_cast<unsigned int>(format));
	}
#endif

#if VC(4, 4)
	inline void GL::bindImageTextures(unsigned int first, int count, const unsigned int* textures)
	{
		glBindImageTextures(first, count, textures);
	}

	inline void GL::bindImageTextures(unsigned int first, const std::vector<unsigned int>& textures)
	{
		bindImageTextures(first, static_cast<int>(textures.size()), &textures.front());
	}
#endif

inline void GL::bindTexture(GL_ENUM target, unsigned int texture)
{
	glBindTexture(static_cast<unsigned int>(target), texture);
}

#if VC(4, 5)
	inline void GL::bindTextureUnit(unsigned int unit, unsigned int texture)
	{
		glBindTextureUnit(unit, texture);
	}
#endif

#if VC(4, 4)
	inline void GL::bindTextures(unsigned int first, int count, const unsigned int* target)
	{
		glBindTextures(first, count, target);
	}

	inline void GL::bindTextures(unsigned int first, const std::vector<unsigned int>& target)
	{
		bindTextures(first, static_cast<int>(target.size()), &target.front());
	}
#endif

#if VC(4, 4)
	inline void GL::clearTexImage(unsigned int texture, int level, GL_ENUM format, GL_ENUM type, const void* data)
	{
		glClearTexImage(texture, level, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
	}

	inline void GL::clearTexSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, const void* data)
	{
		glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
	}
#endif

#if GL_DESKTOP
	inline void GL::compressedTexImage1D(GL_ENUM target, int level, GL_ENUM format, int width, int imageSize, const void* data)
	{
		glCompressedTexImage1D(static_cast<unsigned int>(target), level, static_cast<unsigned int>(format), width, 0, imageSize, data);
	}
#endif

inline void GL::compressedTexImage2D(GL_ENUM target, int level, GL_ENUM format, int width, int height, int imageSize, const void* data)
{
	glCompressedTexImage2D(static_cast<unsigned int>(target), level, static_cast<unsigned int>(format), width, height, 0, imageSize, data);
}

#if GL_DESKTOP || EC(3, 0)
	inline void GL::compressedTexImage3D(GL_ENUM target, int level, GL_ENUM format, int width, int height, int depth, int imageSize, const void* data)
	{
		glCompressedTexImage3D(static_cast<unsigned int>(target), level, static_cast<unsigned int>(format), width, height, depth, 0, imageSize, data);
	}
#endif

#if GL_DESKTOP
	inline void GL::compressedTexSubImage1D(int level, int xoffset, int width, GL_ENUM format, int imageSize, const void* data)
	{
		glCompressedTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, static_cast<unsigned int>(format), imageSize, data);
	}
#endif

#if VC(4, 5)
	inline void GL::compressedTextureSubImage1D(unsigned int texture, int level, int xoffset, int width, GL_ENUM format, int imageSize, const void* data)
	{
		glCompressedTextureSubImage1D(texture, level, xoffset, width, static_cast<unsigned int>(format), imageSize, data);
	}
#endif

inline void GL::compressedTexSubImage2D(GL_ENUM target, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, int imageSize, const void* data)
{
	glCompressedTexSubImage2D(static_cast<unsigned int>(target), level, xoffset, yoffset, width, height, static_cast<unsigned int>(format), imageSize, data);
}

#if VC(4, 5)
	inline void GL::compressedTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, int imageSize, const void* data)
	{
		glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, static_cast<unsigned int>(format), imageSize, data);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
	inline void GL::compressedTexSubImage3D(GL_ENUM target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, int imageSize, const void* data)
	{
		glCompressedTexSubImage3D(static_cast<unsigned int>(target), level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), imageSize, data);
	}
#endif

#if VC(4, 5)
	inline void GL::compressedTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, int imageSize, const void* data)
	{
		glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), imageSize, data);
	}
#endif

#if VC(4, 3)
	inline void GL::copyImageSubData(unsigned int srcName, GL_ENUM srcTarget, int srcLevel, int srcX, int srcY, int srcZ, unsigned int dstName, GL_ENUM dstTarget, int dstLevel, int dstX, int dstY, int dstZ, int srcWidth, int srcHeight, int srcDepth)
	{
		glCopyImageSubData(srcName, static_cast<unsigned int>(srcTarget), srcLevel, srcX, srcY, srcZ, dstName, static_cast<unsigned int>(dstTarget), dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
	}
#endif

#if GL_DESKTOP
	inline void GL::copyTexImage1D(int level, GL_ENUM internalformat, int x, int y, int width)
	{
		glCopyTexImage1D(GL_TEXTURE_1D, level, static_cast<unsigned int>(internalformat), x, y, width, 0);
	}
#endif

inline void GL::copyTexImage2D(GL_ENUM target, int level, GL_ENUM internalformat, int x, int y, int width, int height)
{
	glCopyTexImage2D(static_cast<unsigned int>(target), level, static_cast<unsigned int>(internalformat), x, y, width, height, 0);
}

#if GL_DESKTOP
inline void GL::copyTexSubImage1D(int level, int xoffset, int x, int y, int width)
{
	glCopyTexSubImage1D(GL_TEXTURE_1D, level, xoffset, x, y, width);
}
#endif

#if VC(4, 5)
inline void GL::copyTextureSubImage1D(unsigned int texture, int level, int xoffset, int x, int y, int width)
{
	glCopyTextureSubImage1D(texture, level, xoffset, x, y, width);
}
#endif

inline void GL::copyTexSubImage2D(GL_ENUM target, int level, int xoffset, int yoffset, int x, int y, int width, int height)
{
	glCopyTexSubImage2D(static_cast<unsigned int>(target), level, xoffset, yoffset, x, y, width, height);
}

inline void GL::copyTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int x, int y, int width, int height)
{
	glCopyTexSubImage2D(texture, level, xoffset, yoffset, x, y, width, height);
}

#if GL_DESKTOP || EC(3, 0)
	inline void GL::copyTexSubImage3D(GL_ENUM target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height)
	{
		glCopyTexSubImage3D(static_cast<unsigned int>(target), level, xoffset, yoffset, zoffset, x, y, width, height);
	}
#endif

#if VC(4, 5)
	inline void GL::copyTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height)
	{
		glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
	}
#endif

#if VC(4, 5)
	inline void GL::createTextures(GL_ENUM target, int n, unsigned int* textures)
	{
		glCreateTextures(static_cast<unsigned int>(target), n, textures);
	}
#endif

inline void GL::deleteTextures(int n, const unsigned int* textures)
{
	glDeleteTextures(n, textures);
}

inline void GL::genTextures(int n, unsigned int* textures)
{
	glGenTextures(n, textures);
}

inline void GL::getCompressedTexImage(GL_ENUM target, int level, void* pixels)
{
	glGetCompressedTexImage(static_cast<unsigned int>(target), level, pixels);
}

#if VC(4, 5)
	inline void GL::getnCompressedTexImage(GL_ENUM target, int level, int bufSize, void* pixels)
	{
		glGetnCompressedTexImage(static_cast<unsigned int>(target), level, bufSize, pixels);
	}

	inline void GL::getCompressedTextureImage(unsigned int texture, int level, int bufSize, void* pixels)
	{
		glGetCompressedTextureImage(texture, level, bufSize, pixels);
	}

	inline void GL::getCompressedTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int bufSize, void* pixels)
	{
		glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
	}
#endif

inline void GL::getTexImage(GL_ENUM target, int level, GL_ENUM format, GL_ENUM type, void* pixels)
{
	glGetTexImage(static_cast<unsigned int>(target), level, static_cast<unsigned int>(format), static_cast<unsigned int>(type), pixels);
}

#if VC(4, 5)
	inline void GL::getnTexImage(GL_ENUM target, int level, GL_ENUM format, GL_ENUM type, int bufSize, void* pixels)
	{
		glGetnTexImage(static_cast<unsigned int>(target), level, static_cast<unsigned int>(format), static_cast<unsigned int>(type), bufSize, pixels);
	}

	inline void GL::getTextureImage(unsigned int texture, int level, GL_ENUM format, GL_ENUM type, int bufSize, void* pixels)
	{
		glGetTextureImage(texture, level, static_cast<unsigned int>(format), static_cast<unsigned int>(type), bufSize, pixels);
	}
#endif

#if GL_DESKTOP || EC(3, 1)
	inline void GL::getTexLevelParameterfv(GL_ENUM target, int level, GL_ENUM pname, float* params)
	{
		glGetTexLevelParameterfv(static_cast<unsigned int>(target), level, static_cast<unsigned int>(pname), params);
	}

	inline float GL::getTexLevelParameterfv(GL_ENUM target, int level, GL_ENUM pname)
	{
		float temp;
		getTexLevelParameterfv(target, level, pname, &temp);
		return temp;
	}

	inline void GL::getTexLevelParameteriv(GL_ENUM target, int level, GL_ENUM pname, int* params)
	{
		glGetTexLevelParameteriv(static_cast<unsigned int>(target), level, static_cast<unsigned int>(pname), params);
	}

	inline int GL::getTexLevelParameteriv(GL_ENUM target, int level, GL_ENUM pname)
	{
		int temp;
		getTexLevelParameteriv(target, level, pname, &temp);
		return temp;
	}
#endif

#if VC(4, 5)
	GLCW_API void GL::getTextureLevelParameterfv(unsigned int texture, int level, GL_ENUM pname, float* params)
	{
		glGetTextureLevelParameterfv(texture, level, static_cast<unsigned int>(pname), params);
	}

	GLCW_API float GL::getTextureLevelParameterfv(unsigned int texture, int level, GL_ENUM pname)
	{
		float temp;
		getTextureLevelParameterfv(texture, level, pname, &temp);
		return temp;
	}

	GLCW_API void GL::getTextureLevelParameteriv(unsigned int texture, int level, GL_ENUM pname, int* params)
	{
		glGetTextureLevelParameteriv(texture, level, static_cast<unsigned int>(pname), params);
	}

	GLCW_API int GL::getTextureLevelParameteriv(unsigned int texture, int level, GL_ENUM pname)
	{
		int temp;
		getTextureLevelParameteriv(texture, level, pname, &temp);
		return temp;
	}
#endif

inline void GL::getTexParameterfv(GL_ENUM target, GL_ENUM pname, float* param)
{
	glGetTexParameterfv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
}

inline float GL::getTexParameterfv(GL_ENUM target, GL_ENUM pname)
{
	float temp;
	getTexParameterfv(target, static_cast<GL_ENUM >(pname), &temp);
	return temp;
}

inline void GL::getTexParameteriv(GL_ENUM target, GL_ENUM pname, int* param)
{
	glGetTexParameteriv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
}

inline int GL::getTexParameteriv(GL_ENUM target, GL_ENUM pname)
{
	int temp;
	getTexParameteriv(target, pname, &temp);
	return temp;
}

#if GL_DESKTOP
	inline void GL::getTexParameterIiv(GL_ENUM target, GL_ENUM pname, int* param)
	{
		glGetTexParameterIiv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
	}

	inline int GL::getTexParameterIiv(GL_ENUM target, GL_ENUM pname)
	{
		int temp;
		getTexParameterIiv(target, pname, &temp);
		return temp;
	}

	inline void GL::getTexParameterIuiv(GL_ENUM target, GL_ENUM pname, unsigned int* param)
	{
		glGetTexParameterIuiv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
	}

	inline unsigned int GL::getTexParameterIuiv(GL_ENUM target, GL_ENUM pname)
	{
		unsigned int temp;
		getTexParameterIuiv(target, pname, &temp);
		return temp;
	}
#endif

#if VC(4, 5)
	inline void GL::getTextureParameterfv(unsigned int texture, GL_ENUM pname, float* param)
	{
		glGetTextureParameterfv(texture, static_cast<unsigned int>(pname), param);
	}

	inline float GL::getTextureParameterfv(unsigned int texture, GL_ENUM pname)
	{
		float temp;
		getTextureParameterfv(texture, pname, &temp);
		return temp;
	}

	inline void GL::getTextureParameteriv(unsigned int texture, GL_ENUM pname, int* param)
	{
		glGetTextureParameteriv(texture, static_cast<unsigned int>(pname), param);
	}

	inline int GL::getTextureParameteriv(unsigned int texture, GL_ENUM pname)
	{
		int temp;
		getTextureParameteriv(texture, pname, &temp);
		return temp;
	}

	inline void GL::getTextureParameterIiv(unsigned int texture, GL_ENUM pname, int* param)
	{
		glGetTextureParameterIiv(texture, static_cast<unsigned int>(pname), param);
	}

	inline int GL::getTextureParameterIiv(unsigned int texture, GL_ENUM pname)
	{
		int temp;
		getTextureParameterIiv(texture, pname, &temp);
		return temp;
	}

	inline void GL::getTextureParameterIuiv(unsigned int texture, GL_ENUM pname, unsigned int* param)
	{
		glGetTextureParameterIuiv(texture, static_cast<unsigned int>(pname), param);
	}

	inline unsigned int GL::getTextureParameterIuiv(unsigned int texture, GL_ENUM pname)
	{
		unsigned int temp;
		getTextureParameterIuiv(texture, pname, &temp);
		return temp;
	}
#endif

#if VC(4, 5)
	inline void GL::getTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, int bufSize, void* pixels)
	{
		glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), static_cast<unsigned int>(type), bufSize, pixels);
	}
#endif

#if VC(4, 3)
	inline void GL::invalidateTexImage(unsigned int texture, int level)
	{
		glInvalidateTexImage(texture, level);
	}

	inline void GL::invalidateTexSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth)
	{
		glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
	}
#endif

inline bool GL::isTexture(unsigned int texture)
{
	return static_cast<bool>(glIsTexture(texture));
}

inline void GL::texBuffer(GL_ENUM internalFormat, unsigned int buffer)
{
	glTexBuffer(GL_TEXTURE_BUFFER, static_cast<unsigned int>(internalFormat), buffer);
}

#if VC(4, 5)
	inline void GL::textureBuffer(unsigned int texture, GL_ENUM internalFormat, unsigned int buffer)
	{
		glTextureBuffer(texture, static_cast<unsigned int>(internalFormat), buffer);
	}
#endif

#if VC(4, 3)
	inline void GL::texBufferRange(GL_ENUM internalFormat, unsigned int buffer, signed long long offset, signed long long size)
	{
		glTexBufferRange(GL_TEXTURE_BUFFER, static_cast<unsigned int>(internalFormat), buffer, offset, size);
	}
#endif

#if VC(4, 5)
	inline void GL::textureBufferRange(unsigned int texture, GL_ENUM internalFormat, unsigned int buffer, signed long long offset, signed long long size)
	{
		glTextureBufferRange(texture, static_cast<unsigned int>(internalFormat), buffer, offset, size);
	}
#endif

#if GL_DESKTOP
	inline void GL::texImage1D(GL_ENUM target, int level, GL_ENUM internalFormat, int width, GL_ENUM format, GL_ENUM type, const void* data)
	{
		glTexImage1D(static_cast<unsigned int>(target), level, static_cast<unsigned int>(internalFormat), width, 0, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
	}
#endif

inline void GL::texImage2D(GL_ENUM target, int level, GL_ENUM internalFormat, int width, int height, GL_ENUM format, GL_ENUM type, const void* data)
{
	glTexImage2D(static_cast<unsigned int>(target), level, static_cast<unsigned int>(internalFormat), width, height, 0, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
}

#if GL_DESKTOP
	inline void GL::texImage2DMultisample(GL_ENUM target, int samples, GL_ENUM internalformat, int width, int height, bool fixedsamplelocations)
	{
		glTexImage2DMultisample(static_cast<unsigned int>(target), samples, static_cast<unsigned int>(internalformat), width, height, fixedsamplelocations);
	}
#endif

inline void GL::texImage3D(GL_ENUM target, int level, GL_ENUM internalFormat, int width, int height, int depth, GL_ENUM format, GL_ENUM type, const void* data)
{
	glTexImage3D(static_cast<unsigned int>(target), level, static_cast<unsigned int>(internalFormat), width, height, depth, 0, static_cast<unsigned int>(format), static_cast<unsigned int>(type), data);
}

#if GL_DESKTOP
	inline void GL::texImage3DMultisample(GL_ENUM target, int samples, GL_ENUM internalformat, int width, int height, int depth, bool fixedsamplelocations)
	{
		glTexImage3DMultisample(static_cast<unsigned int>(target), samples, static_cast<unsigned int>(internalformat), width, height, depth, fixedsamplelocations);
	}
#endif

inline void GL::texParameterf(GL_ENUM target, GL_ENUM pname, float param)
{
	glTexParameterf(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
}

inline void GL::texParameteri(GL_ENUM target, GL_ENUM pname, int param)
{
	glTexParameterf(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
}

#if VC(4, 5)
	inline void GL::textureParameterf(unsigned int texture, GL_ENUM pname, float param)
	{
		glTexParameterf(texture, static_cast<unsigned int>(pname), param);
	}

	inline void GL::textureParameteri(unsigned int texture, GL_ENUM pname, int param)
	{
		glTexParameteri(texture, static_cast<unsigned int>(pname), param);
	}
#endif

inline void GL::texParameterfv(GL_ENUM target, GL_ENUM pname, const float* param)
{
	glTexParameterfv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
}

inline void GL::texParameterfv(GL_ENUM target, GL_ENUM pname, const std::vector<float>& param)
{
	texParameterfv(target, pname, &param.front());
}

inline void GL::texParameteriv(GL_ENUM target, GL_ENUM pname, const int* param)
{
	glTexParameteriv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
}

inline void GL::texParameteriv(GL_ENUM target, GL_ENUM pname, const std::vector<int>& param)
{
	texParameteriv(target, pname, &param.front());
}

#if GL_DESKTOP
	inline void GL::texParameterIiv(GL_ENUM target, GL_ENUM pname, const int* param)
	{
		glTexParameterIiv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
	}

	inline void GL::texParameterIiv(GL_ENUM target, GL_ENUM pname, const std::vector<int>& param)
	{
		texParameterIiv(target, pname, &param.front());
	}

	inline void GL::texParameterIuiv(GL_ENUM target, GL_ENUM pname, const unsigned int* param)
	{
		glTexParameterIuiv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), param);
	}

	inline void GL::texParameterIuiv(GL_ENUM target, GL_ENUM pname, const std::vector<unsigned int>& param)
	{
		texParameterIuiv(target, pname, &param.front());
	}
#endif

#if VC(4, 5)
	inline void GL::textureParameterfv(unsigned int texture, GL_ENUM pname, const float* param)
	{
		glTextureParameterfv(texture, static_cast<unsigned int>(pname), param);
	}

	inline void GL::textureParameterfv(unsigned int texture, GL_ENUM pname, const std::vector<float>& param)
	{
		textureParameterfv(texture, pname, &param.front());
	}

	inline void GL::textureParameteriv(unsigned int texture, GL_ENUM pname, const int* param)
	{
		glTextureParameteriv(texture, static_cast<unsigned int>(pname), param);
	}

	inline void GL::textureParameteriv(unsigned int texture, GL_ENUM pname, const std::vector<int>& param)
	{
		textureParameteriv(texture, pname, &param.front());
	}

	inline void GL::textureParameterIiv(unsigned int texture, GL_ENUM pname, const int* param)
	{
		glTextureParameterIiv(texture, static_cast<unsigned int>(pname), param);
	}

	inline void GL::textureParameterIiv(unsigned int texture, GL_ENUM pname, const std::vector<int>& param)
	{
		textureParameterIiv(texture, pname, &param.front());
	}

	inline void GL::textureParameterIuiv(unsigned int texture, GL_ENUM pname, const unsigned int* param)
	{
		glTextureParameterIuiv(texture, static_cast<unsigned int>(pname), param);
	}

	inline void GL::textureParameterIuiv(unsigned int texture, GL_ENUM pname, const std::vector<unsigned int>& param)
	{
		textureParameterIuiv(texture, pname, &param.front());
	}
#endif

#if VC(4, 2)
	inline void GL::texStorage1D(GL_ENUM target, int levels, GL_ENUM internalformat, int width)
	{
		glTexStorage1D(static_cast<unsigned int>(target), levels, static_cast<unsigned int>(internalformat), width);
	}
#endif

#if VC(4, 5)
	inline void GL::textureStorage1D(unsigned int texture, int levels, GL_ENUM internalformat, int width)
	{
		glTextureStorage1D(texture, levels, static_cast<unsigned int>(internalformat), width);
	}
#endif

#if VC(4, 2) || EC(3, 0)
	inline void GL::texStorage2D(GL_ENUM target, int levels, GL_ENUM internalformat, int width, int height)
	{
		glTexStorage2D(static_cast<unsigned int>(target), levels, static_cast<unsigned int>(internalformat), width, height);
	}
#endif

#if VC(4, 5)
	inline void GL::textureStorage2D(unsigned int texture, int levels, GL_ENUM internalformat, int width, int height)
	{
		glTextureStorage2D(texture, levels, static_cast<unsigned int>(internalformat), width, height);
	}
#endif

#if VC(4, 3) || EC(3, 1)
	inline void GL::texStorage2DMultisample(GL_ENUM target, int samples, GL_ENUM internalformat, int width, int height, bool fixedsamplelocations)
	{
		glTexStorage2DMultisample(static_cast<unsigned int>(target), samples, static_cast<unsigned int>(internalformat), width, height, fixedsamplelocations);
	}
#endif
	
#if VC(4, 5)
	inline void GL::textureStorage2DMultisample(unsigned int texture, int samples, GL_ENUM internalformat, int width, int height, bool fixedsamplelocations)
	{
		glTextureStorage2DMultisample(texture, samples, static_cast<unsigned int>(internalformat), width, height, fixedsamplelocations);
	}
#endif

#if VC(4, 2) || EC(3, 0)
	inline void GL::texStorage3D(GL_ENUM target, int levels, GL_ENUM format, int width, int height, int depth)
	{
		glTexStorage3D(static_cast<unsigned int>(target), levels, static_cast<unsigned int>(format), width, height, depth);
	}
#endif

#if VC(4, 5)
	inline void GL::textureStorage3D(unsigned int texture, int levels, GL_ENUM format, int width, int height, int depth)
	{
		glTextureStorage3D(texture, levels, static_cast<unsigned int>(format), width, height, depth);
	}
#endif

#if VC(4, 3)
	inline void GL::texStorage3DMultisample(GL_ENUM target, int samples, GL_ENUM format, int width, int height, int depth, bool fixedsamplelocations)
	{
		glTexStorage3DMultisample(static_cast<unsigned int>(target), samples, static_cast<unsigned int>(format), width, height, depth, fixedsamplelocations);
	}
#endif

#if VC(4, 5)
	inline void GL::textureStorage3DMultisample(unsigned int texture, int samples, GL_ENUM format, int width, int height, int depth, bool fixedsamplelocations)
	{
		glTextureStorage3DMultisample(texture, samples, static_cast<unsigned int>(format), width, height, depth, fixedsamplelocations);
	}
#endif

#if GL_DESKTOP
	inline void GL::texSubImage1D(int level, int xoffset, int width, GL_ENUM format, GL_ENUM type, const void* pixels)
	{
		glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, static_cast<unsigned int>(format), static_cast<unsigned int>(type), pixels);
	}
#endif

#if VC(4, 5)
	inline void GL::textureSubImage1D(unsigned int texture, int level, int xoffset, int width, GL_ENUM format, GL_ENUM type, const void* pixels)
	{
		glTextureSubImage1D(texture, level, xoffset, width, static_cast<unsigned int>(format), static_cast<unsigned int>(type), pixels);
	}
#endif

inline void GL::texSubImage2D(GL_ENUM target, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, GL_ENUM type, const void* pixels)
{
	glTexSubImage2D(static_cast<unsigned int>(target), level, xoffset, yoffset, width, height, static_cast<unsigned int>(format), static_cast<unsigned int>(type), pixels);
}

#if VC(4, 5)
	inline void GL::textureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, GL_ENUM type, const void* pixels)
	{
		glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, static_cast<unsigned int>(format), static_cast<unsigned int>(type), pixels);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
	inline void GL::texSubImage3D(GL_ENUM target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, const void* pixels)
	{
		glTexSubImage3D(static_cast<unsigned int>(target), level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), static_cast<unsigned int>(type), pixels);
	}
#endif

#if VC(4, 5)
	inline void GL::textureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, const void* pixels)
	{
		glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), static_cast<unsigned int>(type), pixels);
	}
#endif

#if VC(4, 3)
	inline void GL::textureView(unsigned int texture, GL_ENUM target, unsigned int origtexture, GL_ENUM internalFormat, int minlevel, int numlevels, int minlayer, int numlayers)
	{
		glTextureView(texture, static_cast<unsigned int>(target), origtexture, static_cast<unsigned int>(internalFormat), minlevel, numlevels, minlayer, numlayers);
	}
#endif