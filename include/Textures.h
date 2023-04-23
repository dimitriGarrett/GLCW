#pragma once

#include "API.h"
#include "Config.h"

#include <vector>

namespace GL
{
	enum class TextureBindFormat : unsigned int
	{
		RGBA32F = 0x8814,
		RGBA16F = 0x881A,
		RG32F = 0x8230,
#if GL_DESKTOP
		RG16F = 0x822F,
		R11F_G11F_B10F = 0x8C3A,
		R32F = 0x822E,
		R16F = 0x822D,
#endif
		RGBA32UI = 0x8D70,
		RGBA16UI = 0x8D76,
#if GL_DESKTOP
		RGB10_A2UI = 0x906F,
#endif
		RGBA8UI = 0x8D7C,
		RG32UI = 0x823C,
#if GL_DESKTOP
		RG16UI = 0x823A,
		RG8UI = 0x8238,
		R32UI = 0x8236,
		R16UI = 0x8234,
		R8UI = 0x8232,
#endif
		RGBA32I = 0x8D82,
		RGBA16I = 0x8D88,
		RGBA8I = 0x8D8E,
#if GL_DESKTOP
		RG32I = 0x823B,
		RG16I = 0x8239,
		RG8I = 0x8237,
#endif
		R32I = 0x8235,
#if GL_DESKTOP
		R16I = 0x8233,
		R8I = 0x8231,
		RGBA16 = 0x805B,
		RGB10_A2 = 0x8059,

#endif
		RGBA8 = 0x8058,
#if GL_DESKTOP
		RG16 = 0x822C,
		RG8 = 0x822B,
		R16 = 0x822A,
		R8 = 0x8229,
		RGBA16_SNORM = 0x8F9B,
#endif
		RGBA8_SNORM = 0x8F97,
#if GL_DESKTOP
		RG16_SNORM = 0x8F99,
		RG8_SNORM = 0x8F95,
		R16_SNORM = 0x8F98,
		R8_SNORM = 0x8F94
#endif
	};

	enum class TextureAccess : unsigned int
	{
		READ_ONLY = 0x88B8,
		WRITE_ONLY = 0x88B9,
		READ_WRITE = 0x88BA
	};

	enum class TextureTarget : unsigned int
	{
#if GL_DESKTOP
		TEXTURE_1D = 0x0DE0,
#endif
		TEXTURE_2D = 0x0DE1,
		TEXTURE_3D = 0x806F,
#if GL_DESKTOP
		TEXTURE_1D_ARRAY = 0x8C18,
#endif
		TEXTURE_2D_ARRAY = 0x8C1A,
#if GL_DESKTOP
		TEXTURE_RECTANGLE = 0x84F5,
#endif
		TEXTURE_CUBE_MAP = 0x8513,
#if GL_DESKTOP
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
		TEXTURE_BUFFER = 0x8C2A,
		TEXTURE_2D_MULTISAMPLE = 0x9100,
#endif
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,
	};

	enum class TextureInternalFormats : unsigned int
	{
		DEPTH_COMPONENT = 0x1902,
		DEPTH_STENCIL = 0x84F9,

#if VC(4, 4)
		STENCIL_INDEX = 0x1901,
		STENCIL_INDEX8 = 0x8D48,
#endif

		DEPTH_COMPONENT16 = 0x81A5,
		DEPTH_COMPONENT24 = 0x81A6,
		DEPTH_COMPONENT32 = 0x81A7,

		RED = 0x1903,
		RG = 0x8227,
		RGB = 0x1907,
		RGBA = 0x1908,
		BGR = 0x80E0,
		BGRA = 0x80E1,

		R8 = 0x8229,
		R8_SNORM = 0x8F94,
		R16 = 0x822A,
		R16_SNORM = 0x8F98,
		RG8 = 0x822B,
		RG8_SNORM = 0x8F95,
		RG16 = 0x822C,
		RG16_SNORM = 0x8F99,
		R3_G3_B2 = 0x2A10,
		RGB4 = 0x804F,
		RGB5 = 0x8050,
		RGB8 = 0x8051,
		RGB8_SNORM = 0x8F96,
		RGB10 = 0x8052,
		RGB12 = 0x8053,
		RGB16 = 0x8054,
		RGB16_SNORM = 0x8F9A,
		RGBA2 = 0x8055,
		RGBA4 = 0x8056,
		RGB5_A1 = 0x8057,
		RGBA8 = 0x8058,
		RGBA8_SNORM = 0x8F97,
		RGB10_A2 = 0x8059,
		RGB10_A2UI = 0x906F,
		RGBA12 = 0x805A,
		RGBA16 = 0x805B,
		SRGB8 = 0x8C41,
		SRGB8_ALPHA8 = 0x8C43,
		R16F = 0x822D,
		RG16F = 0x822F,
		RGB16F = 0x881B,
		RGBA16F = 0x881A,
		R32F = 0x822E,
		RG32F = 0x8230,
		RGB32F = 0x8815,
		RGBA32F = 0x8814,
		R11F_G11F_B10F = 0x8C3A,
		RGB9_E5 = 0x8C3D,
		R8I = 0x8231,
		R8UI = 0x8232,
		R16I = 0x8233,
		R16UI = 0x8234,
		R32I = 0x8235,
		R32UI = 0x8236,
		RG8I = 0x8237,
		RG8UI = 0x8238,
		RG16I = 0x8239,
		RG16UI = 0x823A,
		RG32I = 0x823B,
		RG32UI = 0x823C,
		RGB8I = 0x8D8F,
		RGB8UI = 0x8D7D,
		RGB16I = 0x8D89,
		RGB16UI = 0x8D77,
		RGB32I = 0x8D83,
		RGB32UI = 0x8D71,
		RGBA8I = 0x8D8E,
		RGBA8UI = 0x8D7C,
		RGBA16I = 0x8D88,
		RGBA16UI = 0x8D76,
		RGBA32I = 0x8D82,
		RGBA32UI = 0x8D70,

		COMPRESSED_RED = 0x8225,
		COMPRESSED_RG = 0x8226,
		COMPRESSED_RGB = 0x84ED,
		COMPRESSED_RGBA = 0x84EE,
		COMPRESSED_SRGB = 0x8C48,
		COMPRESSED_SRGB_ALPHA = 0x8C49,

		COMPRESSED_RED_RGTC1 = 0x8DBB,
		COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC,
		COMPRESSED_RG_RGTC2 = 0x8DBD,
		COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE,
		COMPRESSED_RGBA_BPTC_UNORM = 0x8E8C,

		COMPRESSED_SRGB_ALPHA_BPTC_UNORM = 0x8E8D,
		COMPRESSED_RGB_BPTC_SIGNED_FLOAT = 0x8E8E,
		COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = 0x8E8F
	};

	enum class TextureCompressedFormat : unsigned int
	{
#if GL_DESKTOP
		COMPRESSED_RED_RGTC1 = 0x8DBB,
		COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC,
		COMPRESSED_RG_RGTC2 = 0x8DBD,
		COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE,
		COMPRESSED_RGBA_BPTC_UNORM = 0x8E8C,
		COMPRESSED_SRGB_ALPHA_BPTC_UNORM = 0x8E8D,
		COMPRESSED_RGB_BPTC_SIGNED_FLOAT = 0x8E8E,
		COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = 0x8E8F,
#endif

#if VC(4, 3) || (!GL_DESKTOP)
		COMPRESSED_RGB8_ETC2 = 0x9274,
		COMPRESSED_SRGB8_ETC2 = 0x9275,
		COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276,
		COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277,
		COMPRESSED_RGBA8_ETC2_EAC = 0x9278,
		COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279,
		COMPRESSED_R11_EAC = 0x9270,
		COMPRESSED_SIGNED_R11_EAC = 0x9271,
		COMPRESSED_RG11_EAC = 0x9272,
		COMPRESSED_SIGNED_RG11_EAC = 0x9273,
#endif
	};

	enum class TextureTypes : unsigned int
	{
		UNSIGNED_BYTE = 0x1401,
		BYTE = 0x1400,
		UNSIGNED_SHORT = 0x1403,
		SHORT = 0x1402,
		UNSIGNED_INT = 0x1405,
		INT = 0x1404,
		HALF_FLOAT = 0x140B,
		FLOAT = 0x1406,
		UNSIGNED_SHORT_5_6_5 = 0x8363,
		UNSIGNED_SHORT_4_4_4_4 = 0x8033,
		UNSIGNED_SHORT_5_5_5_1 = 0x8034,
		UNSIGNED_INT_2_10_10_10_REV = 0x8368,

#if GL_DESKTOP
		UNSIGNED_BYTE_3_3_2 = 0x8032,
		UNSIGNED_BYTE_2_3_3_REV = 0x8362,
		UNSIGNED_SHORT_5_6_5_REV = 0x8364,
		UNSIGNED_SHORT_4_4_4_4_REV = 0x8365,
		UNSIGNED_SHORT_1_5_5_5_REV = 0x8366,
		UNSIGNED_INT_8_8_8_8 = 0x8035,
		UNSIGNED_INT_8_8_8_8_REV = 0x8367,
		UNSIGNED_INT_10_10_10_2 = 0x8036,
#else
		UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B,
		UNSIGNED_INT_5_9_9_9_REV = 0x8C3E,
		UNSIGNED_INT_24_8 = 0x84FA,
		FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD
#endif
	};

	enum class Texture1DTargets : unsigned int
	{
		TEXTURE_1D = 0x0DE0,
		PROXY_TEXTURE_1D = 0x8063
	};

	enum class Texture2DTargets : unsigned int
	{
		TEXTURE_2D = 0x0DE1,
#if GL_DESKTOP
		PROXY_TEXTURE_2D = 0x8064,
		TEXTURE_1D_ARRAY = 0x8C18,
		PROXY_TEXTURE_1D_ARRAY = 0x8C19,
#endif
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,

#if GL_DESKTOP
		PROXY_TEXTURE_CUBE_MAP = 0x851B
#endif
	};

	enum class Texture2DTargetsTex : unsigned int
	{
		TEXTURE_2D = 0x0DE1,
#if GL_DESKTOP
		TEXTURE_1D_ARRAY = 0x8C18,
#endif
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,
	};

	enum class Texture3DTargets : unsigned int
	{
		TEXTURE_3D = 0x806F,
		TEXTURE_2D_ARRAY = 0x8C1A,
#if GL_DESKTOP
		PROXY_TEXTURE_3D = 0x8070,
		PROXY_TEXTURE_2D_ARRAY = 0x8C1B
#endif
	};

	enum class Texture3DTexTargets : unsigned int
	{
		TEXTURE_3D = 0x806F,
		TEXTURE_2D_ARRAY = 0x8C1A,
#if GL_DESKTOP
		TEXTURE_CUBE_MAP_ARRAY = 0x9009
#endif
	};

	enum class TextureCopyTarget : unsigned int
	{
		RENDERBUFFER = 0x8D41,
		TEXTURE_1D = 0x0DE0,
		TEXTURE_2D = 0x0DE1,
		TEXTURE_3D = 0x806F,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_RECTANGLE = 0x84F5,
		TEXTURE_CUBE_MAP = 0x8513,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
		TEXTURE_2D_MULTISAMPLE = 0x9100,
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,
	};

	enum class TextureCopyInternalFormat : unsigned int
	{
#if (!GL_DESKTOP)
		ALPHA = 0x1906,
		LUMINANCE = 0x1909,
		LUMINANCE_ALPHA = 0x190A,
		RGB = 0x1907,
		RGBA = 0x1908,
		R8 = 0x8229,
		RG8 = 0x822B,
		RGB565 = 0x8D62,
		RGB8 = 0x8051,
		RGBA4 = 0x8056,
		RGB5_A1 = 0x8057,
		RGBA8 = 0x8058,
		RGB10_A2 = 0x8059,
		SRGB8 = 0x8C41,
		SRGB8_ALPHA8 = 0x8C43,
		R8I = 0x8231,
		R8UI = 0x8232,
		R16I = 0x8233,
		R16UI = 0x8234,
		R32I = 0x8235,
		R32UI = 0x8236,
		RG8I = 0x8237,
		RG8UI = 0x8238,
		RG16I = 0x8239,
		RG16UI = 0x823A,
		RG32I = 0x823B,
		RG32UI = 0x823C,
		RGB8I = 0x8D8F,
		RGBA8UI = 0x8D7C,
		RGB10_A2UI = 0x906F,
		RGBA16I = 0x8D88,
		RGBA16UI = 0x8D76,
		RGBA32I = 0x8D82,
		RGBA32UI = 0x8D70

#else
		DEPTH_COMPONENT = 0x1902,
		DEPTH_COMPONENT16 = 0x81A5,
		DEPTH_COMPONENT24 = 0x81A6,
		DEPTH_COMPONENT32 = 0x81A7,

#if VC(4, 4)
		STENCIL_INDEX8 = 0x8D48,
#endif

		RED = 0x1903,
		RG = 0x8227,
		RGB = 0x1907,
		RGBA = 0x1908,

		R3_G3_B2 = 0x2A10,
		RGB4 = 0x804F,
		RGB5 = 0x8050,
		RGB8 = 0x8051,
		RGB10 = 0x8052,
		RGB12 = 0x8053,
		RGB16 = 0x8054,
		RGBA2 = 0x8055,
		RGBA4 = 0x8056,
		RGB5_A1 = 0x8057,
		RGBA8 = 0x8058,
		RGB10_A2 = 0x8059,
		RGBA12 = 0x805A,
		RGBA16 = 0x805B,
		SRGB8 = 0x8C41,
		SRGB_ALPHA = 0x8C42,
		SRGB8_ALPHA8 = 0x8C43,
		
		COMPRESSED_RED = 0x8225,
		COMPRESSED_RG = 0x8226,
		COMPRESSED_RGB = 0x84ED,
		COMPRESSED_RGBA = 0x84EE,
		COMPRESSED_SRGB = 0x8C48,
		COMPRESSED_SRGB_ALPHA = 0x8C49
#endif
	};

	enum class TextureCopy2DTargets : unsigned int
	{
		TEXTURE_2D = 0x0DE1,
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A
	};

	enum class TextureCopy2DSubTargets : unsigned int
	{
#if GL_DESKTOP
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_RECTANGLE = 0x84F5,
#endif
		TEXTURE_2D = 0x0DE1,
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,
	};

	enum class TextureCopy3DTargets : unsigned int
	{
		TEXTURE_3D = 0x806F,
		TEXTURE_2D_ARRAY = 0x8C1A, 
	};

	enum class TextureGetTarget : unsigned int
	{
		TEXTURE_1D = 0x0DE0,
		TEXTURE_2D = 0x0DE1,
		TEXTURE_3D = 0x806F,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_RECTANGLE = 0x84F5,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A
	};

	enum class TextureGetFormat : unsigned int
	{
#if VC(4, 4)
		STENCIL_INDEX = 0x1901,
#endif
		DEPTH_COMPONENT = 0x1902,
		DEPTH_STENCIL = 0x84F9,
		RED = 0x1903,
		GREEN = 0x1904,
		BLUE = 0x1905,
		RG = 0x8227,
		RGB = 0x1907,
		RGBA = 0x1908,
		BGR = 0x80E0,
		BGRA = 0x80E1,
		RED_INTEGER = 0x8D94,
		GREEN_INTEGER = 0x8D95,
		BLUE_INTEGER = 0x8D96,
		RG_INTEGER = 0x8228,
		RGB_INTEGER = 0x8D98,
		RGBA_INTEGER = 0x8D99,
		BGR_INTEGER = 0x8D9A,
		BGRA_INTEGER = 0x8D9B
	};

	enum class TextureGetTexLevelTargets : unsigned int
	{
		TEXTURE_2D = 0x0DE1,
		TEXTURE_3D = 0x806F,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_2D_MULTISAMPLE = 0x9100,
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,

#if GL_DESKTOP
		TEXTURE_1D = 0x0DE0,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_RECTANGLE = 0x84F5,
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,

		PROXY_TEXTURE_1D = 0x8063,
		PROXY_TEXTURE_2D = 0x8064,
		PROXY_TEXTURE_3D = 0x8070,
		PROXY_TEXTURE_1D_ARRAY = 0x8C19,
		PROXY_TEXTURE_2D_ARRAY = 0x8C1B,
		PROXY_TEXTURE_RECTANGLE = 0x84F7,
		PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101,
		PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103, 
		PROXY_TEXTURE_CUBE_MAP = 0x851B,
		TEXTURE_BUFFER = 0x8C2A
#endif
	};

	enum class TextureGetPname : unsigned int
	{
		TEXTURE_WIDTH = 0x1000,
		TEXTURE_HEIGHT = 0x1001,
		TEXTURE_DEPTH = 0x8071,
		TEXTURE_INTERNAL_FORMAT = 0x1003,

#if (!GL_DESKTOP)
		TEXTURE_SAMPLES = 0x9106,
		TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107,
		TEXTURE_STENCIL_SIZE = 0x88F1,
		TEXTURE_SHARED_SIZE = 0x8C3F,
		TEXTURE_RED_TYPE = 0x8C10,
		TEXTURE_GREEN_TYPE = 0x8C11,
		TEXTURE_BLUE_TYPE = 0x8C12,
		TEXTURE_ALPHA_TYPE = 0x8C13,
		TEXTURE_DEPTH_TYPE = 0x8C16,
		TEXTURE_COMPRESSED = 0x86A1,
#endif
		TEXTURE_RED_SIZE = 0x805C,
		TEXTURE_GREEN_SIZE = 0x805D,
		TEXTURE_BLUE_SIZE = 0x805E,
		TEXTURE_ALPHA_SIZE = 0x805F,
		TEXTURE_DEPTH_SIZE = 0x884A,

#if GL_DESKTOP
		TEXTURE_COMPRESSED = 0x86A1,
		TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0,
#endif

#if VC(4, 3)
		TEXTURE_BUFFER_OFFSET = 0x919D,
		TEXTURE_BUFFER_SIZE = 0x919E
#endif
	};

	enum class TextureGetParameterTarget : unsigned int
	{
		TEXTURE_2D = 0x0DE1,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_3D = 0x806F,
		TEXTURE_CUBE_MAP = 0x8513,

#if GL_DESKTOP
		TEXTURE_1D = 0x0DE0,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_2D_MULTISAMPLE = 0x9100,
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,
		TEXTURE_RECTANGLE = 0x84F5,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009
#endif
	};

	enum class TextureGetTexParameterPname : unsigned int
	{
#if VC(4, 3) || (!GL_DESKTOP)
		DEPTH_STENCIL_TEXTURE_MODE = 0x90EA,
		TEXTURE_IMMUTABLE_LEVELS = 0x82DF,
#endif

		TEXTURE_BASE_LEVEL = 0x813C,
		TEXTURE_COMPARE_FUNC = 0x884D,
		TEXTURE_COMPARE_MODE = 0x884C,
		TEXTURE_IMMUTABLE_FORMAT = 0x912F,
		TEXTURE_MAG_FILTER = 0x2800,
		TEXTURE_MAX_LEVEL = 0x813D,
		TEXTURE_MAX_LOD = 0x813B,
		TEXTURE_MIN_FILTER = 0x2801,
		TEXTURE_MIN_LOD = 0x813A,
		TEXTURE_SWIZZLE_R = 0x8E42,
		TEXTURE_SWIZZLE_G = 0x8E43,
		TEXTURE_SWIZZLE_B = 0x8E44,
		TEXTURE_SWIZZLE_A = 0x8E45,
		TEXTURE_WRAP_S = 0x2802,
		TEXTURE_WRAP_T = 0x2803,
		TEXTURE_WRAP_R = 0x8072,

#if VC(4, 2)
		IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7,
#endif

#if GL_DESKTOP
		TEXTURE_BORDER_COLOR = 0x1004,
		TEXTURE_LOD_BIAS = 0x8501,
		TEXTURE_SWIZZLE_RGBA = 0x8E46,
#endif

#if VC(4, 5)
		TEXTURE_TARGET = 0x1006,
#endif

#if VC(4, 3)
		TEXTURE_VIEW_MIN_LAYER = 0x82DD,
		TEXTURE_VIEW_MIN_LEVEL = 0x82DB,
		TEXTURE_VIEW_NUM_LAYERS = 0x82DE,
		TEXTURE_VIEW_NUM_LEVELS = 0x82DC,
#endif
	};

	enum class TextureGetTexParameterPnamei : unsigned int
	{
#if VC(4, 3) || (!GL_DESKTOP)
		DEPTH_STENCIL_TEXTURE_MODE = 0x90EA,
		TEXTURE_IMMUTABLE_LEVELS = 0x82DF,
#endif

		TEXTURE_BASE_LEVEL = 0x813C,
		TEXTURE_COMPARE_FUNC = 0x884D,
		TEXTURE_COMPARE_MODE = 0x884C,
		TEXTURE_IMMUTABLE_FORMAT = 0x912F,
		TEXTURE_MAG_FILTER = 0x2800,
		TEXTURE_MAX_LEVEL = 0x813D,
		TEXTURE_MAX_LOD = 0x813B,
		TEXTURE_MIN_FILTER = 0x2801,
		TEXTURE_MIN_LOD = 0x813A,
		TEXTURE_SWIZZLE_R = 0x8E42,
		TEXTURE_SWIZZLE_G = 0x8E43,
		TEXTURE_SWIZZLE_B = 0x8E44,
		TEXTURE_SWIZZLE_A = 0x8E45,
		TEXTURE_WRAP_S = 0x2802,
		TEXTURE_WRAP_T = 0x2803,
		TEXTURE_WRAP_R = 0x8072,

#if VC(4, 2)
		IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7,
#endif

#if GL_DESKTOP
		TEXTURE_LOD_BIAS = 0x8501,
#endif

#if VC(4, 5)
		TEXTURE_TARGET = 0x1006,
#endif

#if VC(4, 3)
		TEXTURE_VIEW_MIN_LAYER = 0x82DD,
		TEXTURE_VIEW_MIN_LEVEL = 0x82DB,
		TEXTURE_VIEW_NUM_LAYERS = 0x82DE,
		TEXTURE_VIEW_NUM_LEVELS = 0x82DC,
#endif
	};

	enum class TextureGetReturnFormat : unsigned int
	{
		RED = 0x1903,
		RG = 0x8227,
		RGB = 0x1907,
		BGR = 0x80E0,
		RGBA = 0x1908,
		BGRA = 0x80E1,

		RED_INTEGER = 0x8D94,
		GREEN_INTEGER = 0x8D95,
		BLUE_INTEGER = 0x8D96,
		RG_INTEGER = 0x8228,
		RGB_INTEGER = 0x8D98,
		RGBA_INTEGER = 0x8D99,
		BGR_INTEGER = 0x8D9A,
		BGRA_INTEGER = 0x8D9B,

		STENCIL_INDEX = 0x1901,
		DEPTH_COMPONENT = 0x1902,
		DEPTH_STENCIL = 0x84F9,
	};

	enum class TextureFormat : unsigned int
	{
		RED = 0x1903,
		RG = 0x8227,
		RGB = 0x1907,
		BGR = 0x80E0,
		RGBA = 0x1908,
		BGRA = 0x80E1,

		RED_INTEGER = 0x8D94,
		RG_INTEGER = 0x8228,
		RGB_INTEGER = 0x8D98,
		BGR_INTEGER = 0x8D9A,
		RGBA_INTEGER = 0x8D99,
		BGRA_INTEGER = 0x8D9B,

		DEPTH_COMPONENT = 0x1902,
		DEPTH_STENCIL = 0x84F9,

#if VC(4, 4)
		STENCIL_INDEX = 0x1901,
#endif
	};

	enum class TextureAll2DTargets : unsigned int
	{
		TEXTURE_2D = 0x0DE1,
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,

#if GL_DESKTOP
		PROXY_TEXTURE_2D = 0x8064,
		TEXTURE_1D_ARRAY = 0x8C18,
		PROXY_TEXTURE_1D_ARRAY = 0x8C19,
		TEXTURE_RECTANGLE = 0x84F5,
		PROXY_TEXTURE_RECTANGLE = 0x84F7,
		PROXY_TEXTURE_CUBE_MAP = 0x851B
#endif
	};

	enum class Texture2DMultisampleTarget : unsigned int
	{
		TEXTURE_2D_MULTISAMPLE = 0x9100,

#if GL_DESKTOP
		PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101
#endif
	};

	enum class Texture3DMultisampleTarget : unsigned int
	{
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,
		PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103
	};

	enum class TextureParameterPname : unsigned int
	{
#if GL_DESKTOP
		TEXTURE_BORDER_COLOR = 0x1004,
		TEXTURE_LOD_BIAS = 0x8501,
		TEXTURE_SWIZZLE_RGBA = 0x8E46,
#endif

#if VC(4, 4)
		DEPTH_STENCIL_TEXTURE_MODE = 0x90EA,
#endif

		TEXTURE_BASE_LEVEL = 0x813C,
		TEXTURE_COMPARE_MODE = 0x884C,
		TEXTURE_COMPARE_FUNC = 0x884D,
		TEXTURE_MAG_FILTER = 0x2800,
		TEXTURE_MAX_LEVEL = 0x813D,
		TEXTURE_MAX_LOD = 0x813B,
		TEXTURE_MIN_FILTER = 0x2801,
		TEXTURE_MIN_LOD = 0x813A,
		TEXTURE_SWIZZLE_R = 0x8E42,
		TEXTURE_SWIZZLE_G = 0x8E43,
		TEXTURE_SWIZZLE_B = 0x8E44,
		TEXTURE_SWIZZLE_A = 0x8E45,
		TEXTURE_WRAP_S = 0x2802,
		TEXTURE_WRAP_T = 0x2803,
		TEXTURE_WRAP_R = 0x8072
	};

	enum class Texture2DStorageTarget : unsigned int
	{
#if EC(3, 0)
		TEXTURE_CUBE_MAP = 0x8513,
#endif

#if GL_DESKTOP
		PROXY_TEXTURE_2D = 0x8064,
		TEXTURE_1D_ARRAY = 0x8C18,
		PROXY_TEXTURE_1D_ARRAY = 0x8C19,
		TEXTURE_RECTANGLE = 0x84F5,
		PROXY_TEXTURE_RECTANGLE = 0x84F7,
		PROXY_TEXTURE_CUBE_MAP = 0x851B,
#endif

		TEXTURE_2D = 0x0DE1,
	};

	enum class Texture3DStorageTargets : unsigned int
	{
		TEXTURE_3D = 0x806F,
		TEXTURE_2D_ARRAY = 0x8C1A,

#if GL_DESKTOP
		PROXY_TEXTURE_3D = 0x8070,
		PROXY_TEXTURE_2D_ARRAY = 0x8C1B,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
		PROXY_TEXTURE_CUBE_MAP_ARRAY = 0x900B
#endif
	};

	enum class TextureSubImage2DTarget : unsigned int
	{
		TEXTURE_2D = 0x0DE1,
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,

#if GL_DESKTOP
		TEXTURE_1D_ARRAY = 0x8C18,
#endif
	};

	enum class TextureSubImage3DTarget : unsigned int
	{
		TEXTURE_3D = 0x806F,
		TEXTURE_2D_ARRAY = 0x8C1A,
	};

	enum class TextureViewNewTarget : unsigned int
	{
		TEXTURE_1D = 0x0DE0,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_2D = 0x0DE1,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_3D = 0x806F,
		TEXTURE_CUBE_MAP = 0x8513,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
		TEXTURE_RECTANGLE = 0x84F5,
		TEXTURE_2D_MULTISAMPLE = 0x9100,
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,
	};

	//glActiveTexture — select active texture unit IMPORTANT: offset is added to GL_TEXTURE0
	GLCW_API void activeTexture(/*GL_TEXTURE0 + */unsigned int offset);

#if VC(4, 2) || EC(3, 1)
	//glBindImageTexture — bind a level of a texture to an image unit
	GLCW_API void bindImageTexture(unsigned int unit, unsigned int texture, int level, bool layered, int layer, TextureAccess access, TextureBindFormat format);
#endif

#if VC(4, 4)
	//glBindImageTextures — bind one or more named texture images to a sequence of consecutive image units
	GLCW_API void bindImageTextures(unsigned int first, int count, const unsigned int* textures);
	//glBindImageTextures — bind one or more named texture images to a sequence of consecutive image units
	GLCW_API void bindImageTextures(unsigned int first, const std::vector<unsigned int>& textures);
#endif

	//glBindTexture — bind a named texture to a texturing target
	GLCW_API void bindTexture(TextureTarget target, unsigned int texture);

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
	GLCW_API void clearTexImage(unsigned int texture, int level, TextureInternalFormats format, TextureTypes type, const void* data);

	//glClearTexSubImage — fills all or part of a texture image with a constant value
	GLCW_API void clearTexSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureInternalFormats format, TextureTypes type, const void* data);
#endif

#if GL_DESKTOP
	//glCompressedTexImage1D — specify a one-dimensional texture image in a compressed format
	GLCW_API void compressedTexImage1D(Texture1DTargets target, int level, TextureCompressedFormat format, int width, int imageSize, const void* data);
#endif

	//glCompressedTexImage2D — specify a two-dimensional texture image in a compressed format
	GLCW_API void compressedTexImage2D(Texture2DTargets target, int level, TextureCompressedFormat format, int width, int height, int imageSize, const void* data);

#if GL_DESKTOP || EC(3, 0)
	//glCompressedTexImage3D — specify a three-dimensional texture image in a compressed format
	GLCW_API void compressedTexImage3D(Texture3DTargets target, int level, TextureCompressedFormat format, int width, int height, int depth, int imageSize, const void* data);
#endif

#if GL_DESKTOP
	//glCompressedTexSubImage1D, glCompressedTextureSubImage1D — specify a one-dimensional texture subimage in a compressed format
	GLCW_API void compressedTexSubImage1D(int level, int xoffset, int width, TextureCompressedFormat format, int imageSize, const void* data);
#endif
#if VC(4, 5)
	//glCompressedTexSubImage1D, glCompressedTextureSubImage1D — specify a one-dimensional texture subimage in a compressed format
	GLCW_API void compressedTextureSubImage1D(unsigned int texture, int level, int xoffset, int width, TextureCompressedFormat format, int imageSize, const void* data);
#endif

	//glCompressedTexSubImage2D, glCompressedTextureSubImage2D — specify a two-dimensional texture subimage in a compressed format
	GLCW_API void compressedTexSubImage2D(Texture2DTargetsTex target, int level, int xoffset, int yoffset, int width, int height, TextureCompressedFormat format, int imageSize, const void* data);
#if VC(4, 5)
	//glCompressedTexSubImage2D, glCompressedTextureSubImage2D — specify a two-dimensional texture subimage in a compressed format
	GLCW_API void compressedTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int width, int height, TextureCompressedFormat format, int imageSize, const void* data);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glCompressedTexSubImage3D, glCompressedTextureSubImage3D — specify a three-dimensional texture subimage in a compressed format
	GLCW_API void compressedTexSubImage3D(Texture3DTexTargets target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureCompressedFormat format, int imageSize, const void* data);
#endif
#if VC(4, 5)
	//glCompressedTexSubImage3D, glCompressedTextureSubImage3D — specify a three-dimensional texture subimage in a compressed format
	GLCW_API void compressedTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureCompressedFormat format, int imageSize, const void* data);
#endif

#if VC(4, 3)
	//glCopyImageSubData — perform a raw data copy between two images
	GLCW_API void copyImageSubData(unsigned int srcName, TextureCopyTarget srcTarget, int srcLevel, int srcX, int srcY, int srcZ, unsigned int dstName, TextureCopyTarget dstTarget, int dstLevel, int dstX, int dstY, int dstZ, int srcWidth, int srcHeight, int srcDepth);
#endif

#if GL_DESKTOP
	//glCopyTexImage1D — copy pixels into a 1D texture image
	GLCW_API void copyTexImage1D(/*GL_TEXTURE_1D target, */int level, TextureCopyInternalFormat internalformat, int x, int y, int width);
#endif

	//glCopyTexImage2D — copy pixels into a 2D texture image
	GLCW_API void copyTexImage2D(TextureCopy2DTargets target, int level, TextureCopyInternalFormat internalformat, int x, int y, int width, int height);

#if GL_DESKTOP
	//glCopyTexSubImage1D, glCopyTextureSubImage1D — copy a one-dimensional texture subimage
	GLCW_API void copyTexSubImage1D(/*GL_TEXTURE_1D target, */int level, int xoffset, int x, int y, int width);
#endif
#if VC(4, 5)
	//glCopyTexSubImage1D, glCopyTextureSubImage1D — copy a one-dimensional texture subimage
	GLCW_API void copyTextureSubImage1D(unsigned int texture, int level, int xoffset, int x, int y, int width);
#endif

	//glCopyTexSubImage2D, glCopyTextureSubImage2D — copy a two-dimensional texture subimage
	GLCW_API void copyTexSubImage2D(TextureCopy2DSubTargets target, int level, int xoffset, int yoffset, int x, int y, int width, int height);
	//glCopyTexSubImage2D, glCopyTextureSubImage2D — copy a two-dimensional texture subimage
	GLCW_API void copyTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int x, int y, int width, int height);

#if GL_DESKTOP || EC(3, 0)
	//glCopyTexSubImage3D, glCopyTextureSubImage3D — copy a three-dimensional texture subimage
	GLCW_API void copyTexSubImage3D(TextureCopy3DTargets target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
#endif
#if VC(4, 5)
	//glCopyTexSubImage3D, glCopyTextureSubImage3D — copy a three-dimensional texture subimage
	GLCW_API void copyTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
#endif

#if VC(4, 5)
	//glCreateTextures — create texture objects
	GLCW_API void createTextures(TextureTarget target, int n, unsigned int* textures);
#endif

	//glDeleteTextures — delete named textures
	GLCW_API void deleteTextures(int n, const unsigned int* textures);

	//glGenTextures — generate texture names
	GLCW_API void genTextures(int n, unsigned int* textures);

	//glGetCompressedTexImage — return a compressed texture image
	GLCW_API void getCompressedTexImage(TextureGetTarget target, int level, void* pixels);

#if VC(4, 5)
	//glGetCompressedTexImage — return a compressed texture image
	GLCW_API void getnCompressedTexImage(TextureGetTarget target, int level, int bufSize, void* pixels);
	//glGetCompressedTexImage — return a compressed texture image
	GLCW_API void getCompressedTextureImage(unsigned int texture, int level, int bufSize, void* pixels);

	//glGetCompressedTextureSubImage — retrieve a sub-region of a compressed texture image from a compressed texture object
	GLCW_API void getCompressedTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int bufSize, void* pixels);
#endif

	//glGetTexImage — return a texture image
	GLCW_API void getTexImage(TextureGetTarget target, int level, TextureGetFormat format, TextureTypes type, void* pixels);
#if VC(4, 5)
	//glGetTexImage — return a texture image
	GLCW_API void getnTexImage(TextureGetTarget target, int level, TextureGetFormat format, TextureTypes type, int bufSize, void* pixels);
	//glGetTexImage — return a texture image
	GLCW_API void getTextureImage(unsigned int texture, int level, TextureGetFormat format, TextureTypes type, int bufSize, void* pixels);
#endif

#if GL_DESKTOP || EC(3, 1)
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTexLevelParameterfv(TextureGetTexLevelTargets target, int level, TextureGetPname pname, float* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API float getTexLevelParameterfv(TextureGetTexLevelTargets target, int level, TextureGetPname pname);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTexLevelParameteriv(TextureGetTexLevelTargets target, int level, TextureGetPname pname, int* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API int getTexLevelParameteriv(TextureGetTexLevelTargets target, int level, TextureGetPname pname);
#endif

#if VC(4, 5)
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTextureLevelParameterfv(unsigned int texture, int level, TextureGetPname pname, float* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API float getTextureLevelParameterfv(unsigned int texture, int level, TextureGetPname pname);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API void getTextureLevelParameteriv(unsigned int texture, int level, TextureGetPname pname, int* params);
	//glGetTexLevelParameter — return texture parameter values for a specific level of detail
	GLCW_API int getTextureLevelParameteriv(unsigned int texture, int level, TextureGetPname pname);
#endif

	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameterfv(TextureGetParameterTarget target, TextureGetTexParameterPname pname, float* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API float getTexParameterfv(TextureGetParameterTarget target, TextureGetTexParameterPnamei pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameteriv(TextureGetParameterTarget target, TextureGetTexParameterPname pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTexParameteriv(TextureGetParameterTarget target, TextureGetTexParameterPnamei pname);

#if GL_DESKTOP
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameterIiv(TextureGetParameterTarget target, TextureGetTexParameterPname pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTexParameterIiv(TextureGetParameterTarget target, TextureGetTexParameterPnamei pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTexParameterIuiv(TextureGetParameterTarget target, TextureGetTexParameterPname pname, unsigned int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API unsigned int getTexParameterIuiv(TextureGetParameterTarget target, TextureGetTexParameterPnamei pname);
#endif

#if VC(4, 5)
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameterfv(unsigned int texture, TextureGetTexParameterPname pname, float* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API float getTextureParameterfv(unsigned int texture, TextureGetTexParameterPnamei pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameteriv(unsigned int texture, TextureGetTexParameterPname pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTextureParameteriv(unsigned int texture, TextureGetTexParameterPnamei pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameterIiv(unsigned int texture, TextureGetTexParameterPname pname, int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API int getTextureParameterIiv(unsigned int texture, TextureGetTexParameterPnamei pname);
	//glGetTexParameter — return texture parameter values
	GLCW_API void getTextureParameterIuiv(unsigned int texture, TextureGetTexParameterPname pname, unsigned int* param);
	//glGetTexParameter — return texture parameter values
	GLCW_API unsigned int getTextureParameterIuiv(unsigned int texture, TextureGetTexParameterPnamei pname);
#endif

#if VC(4, 5)
	//glGetTextureSubImage — retrieve a sub-region of a texture image from a texture object
	GLCW_API void getTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureGetReturnFormat format, TextureTypes type, int bufSize, void* pixels);
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
	GLCW_API void texBuffer(/*GL_TEXTURE_BUFFER, */TextureInternalFormats internalFormat, unsigned int buffer);

#if VC(4, 5)
	//glTexBuffer, glTextureBuffer — attach a buffer object's data store to a buffer texture object
	GLCW_API void textureBuffer(unsigned int texture, TextureInternalFormats internalFormat, unsigned int buffer);
#endif

#if VC(4, 3)
	//glTexBufferRange, glTextureBufferRange — attach a range of a buffer object's data store to a buffer texture object
	GLCW_API void texBufferRange(/*GL_TEXTURE_BUFFER, */TextureInternalFormats internalFormat, unsigned int buffer, signed long long offset, signed long long size);
#endif

#if VC(4, 5)
	//glTexBufferRange, glTextureBufferRange — attach a range of a buffer object's data store to a buffer texture object
	GLCW_API void textureBufferRange(unsigned int texture, TextureInternalFormats internalFormat, unsigned int buffer, signed long long offset, signed long long size);
#endif

#if GL_DESKTOP
	//glTexImage1D — specify a one-dimensional texture image
	GLCW_API void texImage1D(Texture1DTargets target, int level, TextureInternalFormats internalFormat, int width, /*int border = 0,*/ TextureFormat format, TextureTypes type, const void* data);
#endif

	//glTexImage2D — specify a two-dimensional texture image
	GLCW_API void texImage2D(TextureAll2DTargets target, int level, TextureInternalFormats internalFormat, int width, int height, /*int border = 0,*/TextureFormat format, TextureTypes type, const void* data);

#if GL_DESKTOP
	//glTexImage2DMultisample — establish the data storage, format, dimensions, and number of samples of a multisample texture's image
	GLCW_API void texImage2DMultisample(Texture2DMultisampleTarget target, int samples, TextureInternalFormats internalformat, int width, int height, bool fixedsamplelocations);
#endif

	//glTexImage3D — specify a three-dimensional texture image
	GLCW_API void texImage3D(Texture3DTargets target, int level, TextureInternalFormats internalFormat, int width, int height, int depth, /*int border = 0,*/TextureFormat format, TextureTypes type, const void* data);

#if GL_DESKTOP
	//glTexImage3DMultisample — establish the data storage, format, dimensions, and number of samples of a multisample texture's image
	GLCW_API void texImage3DMultisample(Texture3DMultisampleTarget target, int samples, TextureInternalFormats internalformat, int width, int height, int depth, bool fixedsamplelocations);
#endif

	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterf(TextureTarget target, TextureParameterPname pname, float param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameteri(TextureTarget target, TextureParameterPname pname, int param);
#if VC(4, 5)
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterf(unsigned int texture, TextureParameterPname pname, float param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameteri(unsigned int texture, TextureParameterPname pname, int param);
#endif
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterfv(TextureTarget target, TextureParameterPname pname, const float* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterfv(TextureTarget target, TextureParameterPname pname, const std::vector<float>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameteriv(TextureTarget target, TextureParameterPname pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameteriv(TextureTarget target, TextureParameterPname pname, const std::vector<int>& param);
#if GL_DESKTOP
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIiv(TextureTarget target, TextureParameterPname pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIiv(TextureTarget target, TextureParameterPname pname, const std::vector<int>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIuiv(TextureTarget target, TextureParameterPname pname, const unsigned int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void texParameterIuiv(TextureTarget target, TextureParameterPname pname, const std::vector<unsigned int>& param);
#endif
#if VC(4, 5)
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterfv(unsigned int texture, TextureParameterPname pname, const float* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterfv(unsigned int texture, TextureParameterPname pname, const std::vector<float>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameteriv(unsigned int texture, TextureParameterPname pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameteriv(unsigned int texture, TextureParameterPname pname, const std::vector<int>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIiv(unsigned int texture, TextureParameterPname pname, const int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIiv(unsigned int texture, TextureParameterPname pname, const std::vector<int>& param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIuiv(unsigned int texture, TextureParameterPname pname, const unsigned int* param);
	//glTexParameter, glTextureParameter — set texture parameters
	GLCW_API void textureParameterIuiv(unsigned int texture, TextureParameterPname pname, const std::vector<unsigned int>& param);
#endif

#if VC(4, 2)
	//glTexStorage1D, glTextureStorage1D — simultaneously specify storage for all levels of a one-dimensional texture
	GLCW_API void texStorage1D(Texture1DTargets target, int levels, TextureInternalFormats internalformat, int width);
#endif
#if VC(4, 5)
	//glTexStorage1D, glTextureStorage1D — simultaneously specify storage for all levels of a one-dimensional texture
	GLCW_API void textureStorage1D(unsigned int texture, int levels, TextureInternalFormats internalformat, int width);
#endif

#if VC(4, 2) || EC(3, 0)
	//glTexStorage2D, glTextureStorage2D — simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
	GLCW_API void texStorage2D(Texture2DStorageTarget target, int levels, TextureInternalFormats internalformat, int width, int height);
#endif
#if VC(4, 5)
	//glTexStorage2D, glTextureStorage2D — simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
	GLCW_API void textureStorage2D(unsigned int texture, int levels, TextureInternalFormats internalformat, int width, int height);
#endif

#if VC(4, 3) || EC(3, 1)
	//glTexStorage2DMultisample, glTextureStorage2DMultisample — specify storage for a two-dimensional multisample texture
	GLCW_API void texStorage2DMultisample(Texture2DMultisampleTarget target, int samples, TextureInternalFormats internalformat, int width, int height, bool fixedsamplelocations);
#endif

#if VC(4, 5)
	//glTexStorage2DMultisample, glTextureStorage2DMultisample — specify storage for a two-dimensional multisample texture
	GLCW_API void textureStorage2DMultisample(unsigned int texture, int samples, TextureInternalFormats internalformat, int width, int height, bool fixedsamplelocations);
#endif

#if VC(4, 2) || EC(3, 0)
	//glTexStorage3D, glTextureStorage3D — simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture
	GLCW_API void texStorage3D(Texture3DStorageTargets target, int levels, TextureInternalFormats format, int width, int height, int depth);
#endif

#if VC(4, 5)
	//glTexStorage3D, glTextureStorage3D — simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture
	GLCW_API void textureStorage3D(unsigned int texture, int levels, TextureInternalFormats format, int width, int height, int depth);
#endif

#if VC(4, 3)
	//glTexStorage3DMultisample, glTextureStorage3DMultisample — specify storage for a two-dimensional multisample array texture
	GLCW_API void texStorage3DMultisample(Texture3DMultisampleTarget target, int samples, TextureInternalFormats format, int width, int height, int depth, bool fixedsamplelocations);
#endif

#if VC(4, 5)
	//glTexStorage3DMultisample, glTextureStorage3DMultisample — specify storage for a two-dimensional multisample array texture
	GLCW_API void textureStorage3DMultisample(unsigned int texture, int samples, TextureInternalFormats format, int width, int height, int depth, bool fixedsamplelocations);
#endif

#if GL_DESKTOP
	//glTexSubImage1D, glTextureSubImage1D — specify a one-dimensional texture subimage
	GLCW_API void texSubImage1D(/*GL_TEXTURE_1D, */int level, int xoffset, int width, TextureFormat format, TextureTypes type, const void* pixels);
#endif

#if VC(4, 5)
	//glTexSubImage1D, glTextureSubImage1D — specify a one-dimensional texture subimage
	GLCW_API void textureSubImage1D(unsigned int texture, int level, int xoffset, int width, TextureFormat format, TextureTypes type, const void* pixels);
#endif

	//glTexSubImage2D, glTextureSubImage2D — specify a two-dimensional texture subimage
	GLCW_API void texSubImage2D(TextureSubImage2DTarget target, int level, int xoffset, int yoffset, int width, int height, TextureFormat format, TextureTypes type, const void* pixels);

#if VC(4, 5)
	//glTexSubImage2D, glTextureSubImage2D — specify a two-dimensional texture subimage
	GLCW_API void textureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int width, int height, TextureFormat format, TextureTypes type, const void* pixels);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glTexSubImage3D, glTextureSubImage3D — specify a three-dimensional texture subimage
	GLCW_API void texSubImage3D(TextureSubImage3DTarget target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureFormat format, TextureTypes type, const void* pixels);
#endif

#if VC(4, 5)
	//glTexSubImage3D, glTextureSubImage3D — specify a three-dimensional texture subimage
	GLCW_API void textureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureFormat format, TextureTypes type, const void* pixels);
#endif

#if VC(4, 3)
	//glTextureView — initialize a texture as a data alias of another texture's data store
	GLCW_API void textureView(unsigned int texture, TextureViewNewTarget target, unsigned int origtexture, TextureFormat internalFormat, int minlevel, int numlevels, int minlayer, int numlayers);
#endif
}