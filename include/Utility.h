#pragma once

#include "API.h"
#include "GLM.h"
#include "Config.h"

#include "Textures.h"

#undef NO_ERROR

#if VC(4, 2) || EC(3, 1)
	#include "BitfieldWrapper.h"
#endif

namespace GL
{
	enum class UtilityStringName : unsigned int
	{
		VENDOR = 0x1F00,
		RENDERER = 0x1F01,
		VERSION = 0x1F02,
		SHADING_LANGUAGE_VERSION = 0x8B8C,

#if EC(3, 0)
		EXTENSIONS = 0x1F03,
#endif
	};

	enum class UtilityStringNamei : unsigned int
	{
		VENDOR = 0x1F00,
		RENDERER = 0x1F01,
		VERSION = 0x1F02,
		SHADING_LANGUAGE_VERSION = 0x8B8C,
		EXTENSIONS = 0x1F03,
	};

	//glGetString — return a string describing the current GL connection
	GLCW_API std::string_view getString(UtilityStringName name);

#if GL_DESKTOP || EC(3, 0)
	//glGetString — return a string describing the current GL connection
	GLCW_API std::string_view getStringi(UtilityStringNamei name, unsigned int index);
#endif
}

namespace GL
{
#if VC(4, 5)
	enum class UtilityGraphicResetStatus : unsigned int
	{
		NO_ERROR = 0,
		GUILTY_CONTEXT_RESET = 0x8253,
		INNOCENT_CONTEXT_RESET = 0x8254,
		UNKNOWN_CONTEXT_RESET = 0x8255
	};
#endif

#if VC(4, 2) || EC(3, 0)
	enum class UtilityTextureTarget : unsigned int
	{
		RENDERBUFFER = 0x8D41,
		TEXTURE_2D_MULTISAMPLE = 0x9100,

#if VC(4, 2)
		TEXTURE_1D = 0x0DE0,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_2D = 0x0DE1,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_3D = 0x806F,
		TEXTURE_CUBE_MAP = 0x8513,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
		TEXTURE_RECTANGLE = 0x84F5,
		TEXTURE_BUFFER = 0x8C2A,
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102
#endif
	};
#endif

#if VC(4, 2) || EC(3, 0)
	enum class UtilityPname : unsigned int
	{
		NUM_SAMPLE_COUNTS = 0x9380,
		SAMPLES = 0x80A9,
#if VC(4, 3)
		INTERNALFORMAT_SUPPORTED = 0x826F,
		INTERNALFORMAT_PREFERRED = 0x8270,
		INTERNALFORMAT_RED_SIZE = 0x8271,
		INTERNALFORMAT_GREEN_SIZE = 0x8272,
		INTERNALFORMAT_BLUE_SIZE = 0x8273,
		INTERNALFORMAT_ALPHA_SIZE = 0x8274,
		INTERNALFORMAT_DEPTH_SIZE = 0x8275,
		INTERNALFORMAT_STENCIL_SIZE = 0x8276,
		INTERNALFORMAT_SHARED_SIZE = 0x8277,
		INTERNALFORMAT_RED_TYPE = 0x8278,
		INTERNALFORMAT_GREEN_TYPE = 0x8279,
		INTERNALFORMAT_BLUE_TYPE = 0x827A,
		INTERNALFORMAT_ALPHA_TYPE = 0x827B,
		INTERNALFORMAT_DEPTH_TYPE = 0x827C,
		INTERNALFORMAT_STENCIL_TYPE = 0x827D,
		MAX_WIDTH = 0x827E,
		MAX_HEIGHT = 0x827F,
		MAX_DEPTH = 0x8280,
		MAX_LAYERS = 0x8281,
		MAX_COMBINED_DIMENSIONS = 0x8282,
		COLOR_COMPONENTS = 0x8283,
		DEPTH_COMPONENTS = 0x8284,
		STENCIL_COMPONENTS = 0x8285,
		COLOR_RENDERABLE = 0x8286,
		DEPTH_RENDERABLE = 0x8287,
		STENCIL_RENDERABLE = 0x8288,
		FRAMEBUFFER_RENDERABLE = 0x8289,
		FRAMEBUFFER_RENDERABLE_LAYERED = 0x828A,
		FRAMEBUFFER_BLEND = 0x828B,
		READ_PIXELS = 0x828C,
		READ_PIXELS_FORMAT = 0x828D,
		READ_PIXELS_TYPE = 0x828E,
		TEXTURE_IMAGE_FORMAT = 0x828F,
		TEXTURE_IMAGE_TYPE = 0x8290,
		GET_TEXTURE_IMAGE_FORMAT = 0x8291,
		GET_TEXTURE_IMAGE_TYPE = 0x8292,
		MIPMAP = 0x8293,
		GENERATE_MIPMAP = 0x8191,
		AUTO_GENERATE_MIPMAP = 0x8295,
		COLOR_ENCODING = 0x8296,
		SRGB_READ = 0x8297,
		SRGB_WRITE = 0x8298,
		SRGB_DECODE_ARB = 0x8299,
		FILTER = 0x829A,
		VERTEX_TEXTURE = 0x829B,
		TESS_CONTROL_TEXTURE = 0x829C,
		TESS_EVALUATION_TEXTURE = 0x829D,
		GEOMETRY_TEXTURE = 0x829E,
		FRAGMENT_TEXTURE = 0x829F,
		COMPUTE_TEXTURE = 0x82A0,
		TEXTURE_SHADOW = 0x82A1,
		TEXTURE_GATHER = 0x82A2,
		TEXTURE_GATHER_SHADOW = 0x82A3,
		SHADER_IMAGE_LOAD = 0x82A4,
		SHADER_IMAGE_STORE = 0x82A5,
		SHADER_IMAGE_ATOMIC = 0x82A6,
		IMAGE_TEXEL_SIZE = 0x82A7,
		IMAGE_COMPATIBILITY_CLASS = 0x82A8,
		IMAGE_PIXEL_FORMAT = 0x82A9,
		IMAGE_PIXEL_TYPE = 0x82AA,
		IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7,
		SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST = 0x82AC,
		SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST = 0x82AD,
		SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE = 0x82AE,
		SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE = 0x82AF,
		TEXTURE_COMPRESSED = 0x86A1,
		TEXTURE_COMPRESSED_BLOCK_WIDTH = 0x82B1,
		TEXTURE_COMPRESSED_BLOCK_HEIGHT = 0x82B2,
		TEXTURE_COMPRESSED_BLOCK_SIZE = 0x82B3,
		CLEAR_BUFFER = 0x82B4,
		TEXTURE_VIEW = 0x82B5,
		VIEW_COMPATIBILITY_CLASS = 0x82B6,
#endif
#if VC(4, 4)
		CLEAR_TEXTURE = 0x9365
#endif
	};
#endif

#if VC(4, 2) || EC(3, 1)
	static constexpr BITFIELD_WRAP(0x00000001) VERTEX_ATTRIB_ARRAY_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000002) ELEMENT_ARRAY_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000004) UNIFORM_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000008) TEXTURE_FETCH_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000020) SHADER_IMAGE_ACCESS_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000040) COMMAND_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000080) PIXEL_BUFFER_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000100) TEXTURE_UPDATE_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000200) BUFFER_UPDATE_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000400) FRAMEBUFFER_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00000800) TRANSFORM_FEEDBACK_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x00001000) ATOMIC_COUNTER_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0x2000) SHADER_STORAGE_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(0xFFFFFFFF) ALL_BARRIER_BITS;
#endif

	namespace detail
	{
#if VC(4, 2) || EC(3, 1)
		GLCW_API void memoryBarrier(unsigned int bitfield);
#endif
#if VC(4, 5) || EC(3, 1)
		GLCW_API void memoryBarrierByRegion(unsigned int bitfield);
#endif
	}

#if VC(4, 3) || EC(3, 1)
	//glDispatchCompute — launch one or more compute work groups
	GLCW_API void dispatchCompute(unsigned int num_groups_x, unsigned int num_groups_y, unsigned int num_groups_z);
	//glDispatchCompute — launch one or more compute work groups
	GLCW_API void dispatchCompute(const glm::uvec3& num_groups);

	//glDispatchComputeIndirect — launch one or more compute work groups using parameters stored in a buffer
	GLCW_API void dispatchComputeIndirect(long long indirect);
#endif
#if VC(4, 5)
	//glGetGraphicsResetStatus — check if the rendering context has not been lost due to software or hardware issues
	GLCW_API UtilityGraphicResetStatus getGraphicsResetStatus();
#endif
#if VC(4, 2) || EC(3, 0)
	//glGetInternalformat — retrieve information about implementation-dependent support for internal formats
	GLCW_API void getInternalformativ(UtilityTextureTarget target, TextureInternalFormats internalFormat, UtilityPname pname, int bufSize, int* params);
#endif
#if VC(4, 3)
	//glGetInternalformat — retrieve information about implementation-dependent support for internal formats
	GLCW_API void getInternalformati64v(UtilityTextureTarget target, TextureInternalFormats internalFormat, UtilityPname pname, int bufSize, signed long long* params);
#endif
#if GL_DESKTOP || EC(3, 1)
	//glGetMultisamplefv — retrieve the location of a sample
	GLCW_API void getMultisamplefv(unsigned int index, float* val);
	//glGetMultisamplefv — retrieve the location of a sample
	GLCW_API glm::vec2 getMultisamplefv(unsigned int index);
#endif
#if VC(4, 2) || EC(3, 1)
	//glMemoryBarrier — defines a barrier ordering memory transactions
	template <unsigned int final_bits>
	void memoryBarrier(BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> bitfield)
	{
		detail::memoryBarrier(bitfield.value);
	}
#endif
#if VC(4, 5) || EC(3, 1)
	//glMemoryBarrier — defines a barrier ordering memory transactions
	template <unsigned int final_bits>
	void memoryBarrierByRegion(BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> bitfield)
	{
		detail::memoryBarrierByRegion(bitfield.value);
	}
#endif
}