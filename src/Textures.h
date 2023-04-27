#pragma once

#include "API.h"
#include "Enums.h"

#include <vector>

namespace GL
{
	//glActiveTexture — select active texture unit IMPORTANT: offset is added to GL_TEXTURE0
	GLCW_API void activeTexture(/*GL_TEXTURE0 + */unsigned int offset);

#if VC(4, 2) || EC(3, 1)
	//glBindImageTexture — bind a level of a texture to an image unit
	GLCW_API void bindImageTexture(unsigned int unit, unsigned int texture, int level, bool layered, int layer, GL_ENUM access, GL_ENUM format);
#endif

#if VC(4, 4)
	//glBindImageTextures — bind one or more named texture images to a sequence of consecutive image units
	GLCW_API void bindImageTextures(unsigned int first, int count, const unsigned int* textures);
	//glBindImageTextures — bind one or more named texture images to a sequence of consecutive image units
	GLCW_API void bindImageTextures(unsigned int first, const std::vector<unsigned int>& textures);
#endif

	//glBindTexture — bind a named texture to a texturing target
	GLCW_API void bindTexture(GL_ENUM target, unsigned int texture);

#if VC(4, 5)
	//glBindTextureUnit — bind an existing texture object to the specified texture unit
	GLCW_API void bindTextureUnit(unsigned int unit, unsigned int texture);
#endif

#if VC(4, 4)
	//glBindTextures — bind one or more named textures to a sequence of consecutive texture units
	GLCW_API void bindTextures(unsigned int first, int count, const unsigned int* target);
	//glBindTextures — bind one or more named textures to a sequence of consecutive texture units
	GLCW_API void bindTextures(unsigned int first, const std::vector<unsigned int>& target);
#endif

#if VC(4, 4)
	//glClearTexImage — fills all a texture image with a constant value
	GLCW_API void clearTexImage(unsigned int texture, int level, GL_ENUM format, GL_ENUM type, const void* data);

	//glClearTexSubImage — fills all or part of a texture image with a constant value
	GLCW_API void clearTexSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, const void* data);
#endif

#if GL_DESKTOP
	//glCompressedTexImage1D — specify a one-dimensional texture image in a compressed format
	GLCW_API void compressedTexImage1D(GL_ENUM target, int level, GL_ENUM format, int width, int imageSize, const void* data);
#endif

	//glCompressedTexImage2D — specify a two-dimensional texture image in a compressed format
	GLCW_API void compressedTexImage2D(GL_ENUM target, int level, GL_ENUM format, int width, int height, int imageSize, const void* data);

#if GL_DESKTOP || EC(3, 0)
	//glCompressedTexImage3D — specify a three-dimensional texture image in a compressed format
	GLCW_API void compressedTexImage3D(GL_ENUM target, int level, GL_ENUM format, int width, int height, int depth, int imageSize, const void* data);
#endif

#if GL_DESKTOP
	//glCompressedTexSubImage1D, glCompressedTextureSubImage1D — specify a one-dimensional texture subimage in a compressed format
	GLCW_API void compressedTexSubImage1D(int level, int xoffset, int width, GL_ENUM format, int imageSize, const void* data);
#endif
#if VC(4, 5)
	//glCompressedTexSubImage1D, glCompressedTextureSubImage1D — specify a one-dimensional texture subimage in a compressed format
	GLCW_API void compressedTextureSubImage1D(unsigned int texture, int level, int xoffset, int width, GL_ENUM format, int imageSize, const void* data);
#endif

	//glCompressedTexSubImage2D, glCompressedTextureSubImage2D — specify a two-dimensional texture subimage in a compressed format
	GLCW_API void compressedTexSubImage2D(GL_ENUM target, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, int imageSize, const void* data);
#if VC(4, 5)
	//glCompressedTexSubImage2D, glCompressedTextureSubImage2D — specify a two-dimensional texture subimage in a compressed format
	GLCW_API void compressedTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, int imageSize, const void* data);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glCompressedTexSubImage3D, glCompressedTextureSubImage3D — specify a three-dimensional texture subimage in a compressed format
	GLCW_API void compressedTexSubImage3D(GL_ENUM target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, int imageSize, const void* data);
#endif
#if VC(4, 5)
	//glCompressedTexSubImage3D, glCompressedTextureSubImage3D — specify a three-dimensional texture subimage in a compressed format
	GLCW_API void compressedTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, int imageSize, const void* data);
#endif

#if VC(4, 3)
	//glCopyImageSubData — perform a raw data copy between two images
	GLCW_API void copyImageSubData(unsigned int srcName, GL_ENUM srcTarget, int srcLevel, int srcX, int srcY, int srcZ, unsigned int dstName, GL_ENUM dstTarget, int dstLevel, int dstX, int dstY, int dstZ, int srcWidth, int srcHeight, int srcDepth);
#endif

#if GL_DESKTOP
	//glCopyTexImage1D — copy pixels into a 1D texture image
	GLCW_API void copyTexImage1D(/*GL_TEXTURE_1D target, */int level, GL_ENUM internalformat, int x, int y, int width);
#endif

	//glCopyTexImage2D — copy pixels into a 2D texture image
	GLCW_API void copyTexImage2D(GL_ENUM target, int level, GL_ENUM internalformat, int x, int y, int width, int height);

#if GL_DESKTOP
	//glCopyTexSubImage1D, glCopyTextureSubImage1D — copy a one-dimensional texture subimage
	GLCW_API void copyTexSubImage1D(/*GL_TEXTURE_1D target, */int level, int xoffset, int x, int y, int width);
#endif
#if VC(4, 5)
	//glCopyTexSubImage1D, glCopyTextureSubImage1D — copy a one-dimensional texture subimage
	GLCW_API void copyTextureSubImage1D(unsigned int texture, int level, int xoffset, int x, int y, int width);
#endif

	//glCopyTexSubImage2D, glCopyTextureSubImage2D — copy a two-dimensional texture subimage
	GLCW_API void copyTexSubImage2D(GL_ENUM target, int level, int xoffset, int yoffset, int x, int y, int width, int height);
	//glCopyTexSubImage2D, glCopyTextureSubImage2D — copy a two-dimensional texture subimage
	GLCW_API void copyTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int x, int y, int width, int height);

#if GL_DESKTOP || EC(3, 0)
	//glCopyTexSubImage3D, glCopyTextureSubImage3D — copy a three-dimensional texture subimage
	GLCW_API void copyTexSubImage3D(GL_ENUM target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
#endif
#if VC(4, 5)
	//glCopyTexSubImage3D, glCopyTextureSubImage3D — copy a three-dimensional texture subimage
	GLCW_API void copyTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
#endif

#if VC(4, 5)
	//glCreateTextures — create texture objects
	GLCW_API void createTextures(GL_ENUM target, int n, unsigned int* textures);
#endif

	//glDeleteTextures — delete named textures
	GLCW_API void deleteTextures(int n, const unsigned int* textures);

	//glGenTextures — generate texture names
	GLCW_API void genTextures(int n, unsigned int* textures);

	//glGetCompressedTexImage — return a compressed texture image
	GLCW_API void getCompressedTexImage(GL_ENUM target, int level, void* pixels);

#if VC(4, 5)
	//glGetCompressedTexImage — return a compressed texture image
	GLCW_API void getnCompressedTexImage(GL_ENUM target, int level, int bufSize, void* pixels);
	//glGetCompressedTexImage — return a compressed texture image
	GLCW_API void getCompressedTextureImage(unsigned int texture, int level, int bufSize, void* pixels);

	//glGetCompressedTextureSubImage — retrieve a sub-region of a compressed texture image from a compressed texture object
	GLCW_API void getCompressedTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int bufSize, void* pixels);
#endif

	//glGetTexImage — return a texture image
	GLCW_API void getTexImage(GL_ENUM target, int level, GL_ENUM format, GL_ENUM type, void* pixels);
#if VC(4, 5)
	//glGetTexImage — return a texture image
	GLCW_API void getnTexImage(GL_ENUM target, int level, GL_ENUM format, GL_ENUM type, int bufSize, void* pixels);
	//glGetTexImage — return a texture image
	GLCW_API void getTextureImage(unsigned int texture, int level, GL_ENUM format, GL_ENUM type, int bufSize, void* pixels);
#endif

#if GL_DESKTOP || EC(3, 1)
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTexLevelParameterfv(GL_ENUM target, int level, GL_ENUM pname, float* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API float getTexLevelParameterfv(GL_ENUM target, int level, GL_ENUM pname);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTexLevelParameteriv(GL_ENUM target, int level, GL_ENUM pname, int* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API int getTexLevelParameteriv(GL_ENUM target, int level, GL_ENUM pname);
#endif

#if VC(4, 5)
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTextureLevelParameterfv(unsigned int texture, int level, GL_ENUM pname, float* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API float getTextureLevelParameterfv(unsigned int texture, int level, GL_ENUM pname);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTextureLevelParameteriv(unsigned int texture, int level, GL_ENUM pname, int* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API int getTextureLevelParameteriv(unsigned int texture, int level, GL_ENUM pname);
#endif

	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameterfv(GL_ENUM target, GL_ENUM pname, float* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API float getTexParameterfv(GL_ENUM target, GL_ENUM pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameteriv(GL_ENUM target, GL_ENUM pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTexParameteriv(GL_ENUM target, GL_ENUM pname);

#if GL_DESKTOP
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameterIiv(GL_ENUM target, GL_ENUM pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTexParameterIiv(GL_ENUM target, GL_ENUM pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameterIuiv(GL_ENUM target, GL_ENUM pname, unsigned int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API unsigned int getTexParameterIuiv(GL_ENUM target, GL_ENUM pname);
#endif

#if VC(4, 5)
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameterfv(unsigned int texture, GL_ENUM pname, float* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API float getTextureParameterfv(unsigned int texture, GL_ENUM pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameteriv(unsigned int texture, GL_ENUM pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTextureParameteriv(unsigned int texture, GL_ENUM pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameterIiv(unsigned int texture, GL_ENUM pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTextureParameterIiv(unsigned int texture, GL_ENUM pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameterIuiv(unsigned int texture, GL_ENUM pname, unsigned int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API unsigned int getTextureParameterIuiv(unsigned int texture, GL_ENUM pname);
#endif

#if VC(4, 5)
	//glGetTextureSubImage — retrieve a sub-region of a texture image from a texture object
	GLCW_API void getTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, int bufSize, void* pixels);
#endif

#if VC(4, 3)
	//glInvalidateTexImage — invalidate the entirety a texture image
	GLCW_API void invalidateTexImage(unsigned int texture, int level);

	//glInvalidateTexSubImage — invalidate a region of a texture image
	GLCW_API void invalidateTexSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth);
#endif

	//glIsTexture — determine if a name corresponds to a texture
	GLCW_API bool isTexture(unsigned int texture);

	//glTexBuffer, glTextureBuffer — attach a buffer object's data store to a buffer texture object
	GLCW_API void texBuffer(/*GL_TEXTURE_BUFFER, */GL_ENUM internalFormat, unsigned int buffer);

#if VC(4, 5)
	//glTexBuffer, glTextureBuffer — attach a buffer object's data store to a buffer texture object
	GLCW_API void textureBuffer(unsigned int texture, GL_ENUM internalFormat, unsigned int buffer);
#endif

#if VC(4, 3)
	//glTexBufferRange, glTextureBufferRange — attach a range of a buffer object's data store to a buffer texture object
	GLCW_API void texBufferRange(/*GL_TEXTURE_BUFFER, */GL_ENUM internalFormat, unsigned int buffer, signed long long offset, signed long long size);
#endif

#if VC(4, 5)
	//glTexBufferRange, glTextureBufferRange — attach a range of a buffer object's data store to a buffer texture object
	GLCW_API void textureBufferRange(unsigned int texture, GL_ENUM internalFormat, unsigned int buffer, signed long long offset, signed long long size);
#endif

#if GL_DESKTOP
	//glTexImage1D — specify a one-dimensional texture image
	GLCW_API void texImage1D(GL_ENUM target, int level, GL_ENUM internalFormat, int width, /*int border = 0,*/ GL_ENUM format, GL_ENUM type, const void* data);
#endif

	//glTexImage2D — specify a two-dimensional texture image
	GLCW_API void texImage2D(GL_ENUM target, int level, GL_ENUM internalFormat, int width, int height, /*int border = 0,*/GL_ENUM format, GL_ENUM type, const void* data);

#if GL_DESKTOP
	//glTexImage2DMultisample — establish the data storage, format, dimensions, and number of samples of a multisample texture's image
	GLCW_API void texImage2DMultisample(GL_ENUM target, int samples, GL_ENUM internalformat, int width, int height, bool fixedsamplelocations);
#endif

	//glTexImage3D — specify a three-dimensional texture image
	GLCW_API void texImage3D(GL_ENUM target, int level, GL_ENUM internalFormat, int width, int height, int depth, /*int border = 0,*/GL_ENUM format, GL_ENUM type, const void* data);

#if GL_DESKTOP
	//glTexImage3DMultisample — establish the data storage, format, dimensions, and number of samples of a multisample texture's image
	GLCW_API void texImage3DMultisample(GL_ENUM target, int samples, GL_ENUM internalformat, int width, int height, int depth, bool fixedsamplelocations);
#endif

	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterf(GL_ENUM target, GL_ENUM pname, float param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameteri(GL_ENUM target, GL_ENUM pname, int param);
#if VC(4, 5)
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterf(unsigned int texture, GL_ENUM pname, float param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameteri(unsigned int texture, GL_ENUM pname, int param);
#endif
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterfv(GL_ENUM target, GL_ENUM pname, const float* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterfv(GL_ENUM target, GL_ENUM pname, const std::vector<float>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameteriv(GL_ENUM target, GL_ENUM pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameteriv(GL_ENUM target, GL_ENUM pname, const std::vector<int>& param);
#if GL_DESKTOP
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIiv(GL_ENUM target, GL_ENUM pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIiv(GL_ENUM target, GL_ENUM pname, const std::vector<int>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIuiv(GL_ENUM target, GL_ENUM pname, const unsigned int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIuiv(GL_ENUM target, GL_ENUM pname, const std::vector<unsigned int>& param);
#endif
#if VC(4, 5)
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterfv(unsigned int texture, GL_ENUM pname, const float* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterfv(unsigned int texture, GL_ENUM pname, const std::vector<float>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameteriv(unsigned int texture, GL_ENUM pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameteriv(unsigned int texture, GL_ENUM pname, const std::vector<int>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIiv(unsigned int texture, GL_ENUM pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIiv(unsigned int texture, GL_ENUM pname, const std::vector<int>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIuiv(unsigned int texture, GL_ENUM pname, const unsigned int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIuiv(unsigned int texture, GL_ENUM pname, const std::vector<unsigned int>& param);
#endif

#if VC(4, 2)
	//glTexStorage1D, glTextureStorage1D — simultaneously specify storage for all levels of a one-dimensional texture
	GLCW_API void texStorage1D(GL_ENUM target, int levels, GL_ENUM internalformat, int width);
#endif
#if VC(4, 5)
	//glTexStorage1D, glTextureStorage1D — simultaneously specify storage for all levels of a one-dimensional texture
	GLCW_API void textureStorage1D(unsigned int texture, int levels, GL_ENUM internalformat, int width);
#endif

#if VC(4, 2) || EC(3, 0)
	//glTexStorage2D, glTextureStorage2D — simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
	GLCW_API void texStorage2D(GL_ENUM target, int levels, GL_ENUM internalformat, int width, int height);
#endif
#if VC(4, 5)
	//glTexStorage2D, glTextureStorage2D — simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
	GLCW_API void textureStorage2D(unsigned int texture, int levels, GL_ENUM internalformat, int width, int height);
#endif

#if VC(4, 3) || EC(3, 1)
	//glTexStorage2DMultisample, glTextureStorage2DMultisample — specify storage for a two-dimensional multisample texture
	GLCW_API void texStorage2DMultisample(GL_ENUM target, int samples, GL_ENUM internalformat, int width, int height, bool fixedsamplelocations);
#endif

#if VC(4, 5)
	//glTexStorage2DMultisample, glTextureStorage2DMultisample — specify storage for a two-dimensional multisample texture
	GLCW_API void textureStorage2DMultisample(unsigned int texture, int samples, GL_ENUM internalformat, int width, int height, bool fixedsamplelocations);
#endif

#if VC(4, 2) || EC(3, 0)
	//glTexStorage3D, glTextureStorage3D — simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture
	GLCW_API void texStorage3D(GL_ENUM target, int levels, GL_ENUM format, int width, int height, int depth);
#endif

#if VC(4, 5)
	//glTexStorage3D, glTextureStorage3D — simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture
	GLCW_API void textureStorage3D(unsigned int texture, int levels, GL_ENUM format, int width, int height, int depth);
#endif

#if VC(4, 3)
	//glTexStorage3DMultisample, glTextureStorage3DMultisample — specify storage for a two-dimensional multisample array texture
	GLCW_API void texStorage3DMultisample(GL_ENUM target, int samples, GL_ENUM format, int width, int height, int depth, bool fixedsamplelocations);
#endif

#if VC(4, 5)
	//glTexStorage3DMultisample, glTextureStorage3DMultisample — specify storage for a two-dimensional multisample array texture
	GLCW_API void textureStorage3DMultisample(unsigned int texture, int samples, GL_ENUM format, int width, int height, int depth, bool fixedsamplelocations);
#endif

#if GL_DESKTOP
	//glTexSubImage1D, glTextureSubImage1D — specify a one-dimensional texture subimage
	GLCW_API void texSubImage1D(/*GL_TEXTURE_1D, */int level, int xoffset, int width, GL_ENUM format, GL_ENUM type, const void* pixels);
#endif

#if VC(4, 5)
	//glTexSubImage1D, glTextureSubImage1D — specify a one-dimensional texture subimage
	GLCW_API void textureSubImage1D(unsigned int texture, int level, int xoffset, int width, GL_ENUM format, GL_ENUM type, const void* pixels);
#endif

	//glTexSubImage2D, glTextureSubImage2D — specify a two-dimensional texture subimage
	GLCW_API void texSubImage2D(GL_ENUM target, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, GL_ENUM type, const void* pixels);

#if VC(4, 5)
	//glTexSubImage2D, glTextureSubImage2D — specify a two-dimensional texture subimage
	GLCW_API void textureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int width, int height, GL_ENUM format, GL_ENUM type, const void* pixels);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glTexSubImage3D, glTextureSubImage3D — specify a three-dimensional texture subimage
	GLCW_API void texSubImage3D(GL_ENUM target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, const void* pixels);
#endif

#if VC(4, 5)
	//glTexSubImage3D, glTextureSubImage3D — specify a three-dimensional texture subimage
	GLCW_API void textureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, GL_ENUM format, GL_ENUM type, const void* pixels);
#endif

#if VC(4, 3)
	//glTextureView — initialize a texture as a data alias of another texture's data store
	GLCW_API void textureView(unsigned int texture, GL_ENUM target, unsigned int origtexture, GL_ENUM internalFormat, int minlevel, int numlevels, int minlayer, int numlayers);
#endif
}