#pragma once

#include "API.h"
#include "GLM.h"
#include "Enums.h"

#include "Textures.h"

#undef NO_ERROR

#if VC(4, 2) || EC(3, 1)
	#include "BitfieldWrapper.h"
#endif

namespace GL
{
	//glGetString — return a string describing the current GL connection
	GLCW_API std::string_view getString(GL_ENUM name);

#if GL_DESKTOP || EC(3, 0)
	//glGetString — return a string describing the current GL connection
	GLCW_API std::string_view getStringi(GL_ENUM name, unsigned int index);
#endif
}

namespace GL
{
#if VC(4, 2) || EC(3, 1)
	static constexpr BITFIELD_WRAP(1) VERTEX_ATTRIB_ARRAY_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(2) ELEMENT_ARRAY_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(4) UNIFORM_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(8) TEXTURE_FETCH_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(32) SHADER_IMAGE_ACCESS_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(64) COMMAND_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(128) PIXEL_BUFFER_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(256) TEXTURE_UPDATE_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(512) BUFFER_UPDATE_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(1024) FRAMEBUFFER_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(2048) TRANSFORM_FEEDBACK_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(4096) ATOMIC_COUNTER_BARRIER_BIT;
	static constexpr BITFIELD_WRAP(8192) SHADER_STORAGE_BARRIER_BIT;
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
	GLCW_API GL_ENUM getGraphicsResetStatus();
#endif
#if VC(4, 2) || EC(3, 0)
	//glGetInternalformat — retrieve information about implementation-dependent support for internal formats
	GLCW_API void getInternalformativ(GL_ENUM target, GL_ENUM internalFormat, GL_ENUM pname, int bufSize, int* params);
#endif
#if VC(4, 3)
	//glGetInternalformat — retrieve information about implementation-dependent support for internal formats
	GLCW_API void getInternalformati64v(GL_ENUM target, GL_ENUM internalFormat, GL_ENUM pname, int bufSize, signed long long* params);
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