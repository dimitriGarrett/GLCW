#include "Utility.h"
#include "GL.h"

#if VC(4, 3) || EC(3, 1)
	inline void GL::dispatchCompute(unsigned int num_groups_x, unsigned int num_groups_y, unsigned int num_groups_z)
	{
		glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
	}

	inline void GL::dispatchCompute(const glm::uvec3& num_groups)
	{
		dispatchCompute(num_groups.x, num_groups.y, num_groups.z);
	}

	inline void GL::dispatchComputeIndirect(long long indirect)
	{
		glDispatchComputeIndirect(indirect);
	}
#endif

#if VC(4, 5)
	inline GL::UtilityGraphicResetStatus GL::getGraphicsResetStatus()
	{
		return static_cast<UtilityGraphicResetStatus>(glGetGraphicsResetStatus());
	}
#endif

#if VC(4, 2) || EC(3, 0)
	inline void GL::getInternalformativ(UtilityTextureTarget target, TextureInternalFormats internalFormat, UtilityPname pname, int bufSize, int* params)
	{
		glGetInternalformativ(static_cast<unsigned int>(target), static_cast<unsigned int>(internalFormat), static_cast<unsigned int>(pname), bufSize, params);
	}
#endif

#if VC(4, 3)
	inline void GL::getInternalformati64v(UtilityTextureTarget target, TextureInternalFormats internalFormat, UtilityPname pname, int bufSize, signed long long* params)
	{
		glGetInternalformati64v(static_cast<unsigned int>(target), static_cast<unsigned int>(internalFormat), static_cast<unsigned int>(pname), bufSize, params);
	}
#endif

#if GL_DESKTOP || EC(3, 1)
	inline void GL::getMultisamplefv(unsigned int index, float* val)
	{
		glGetMultisamplefv(GL_SAMPLE_POSITION, index, val);
	}

	inline glm::vec2 GL::getMultisamplefv(unsigned int index)
	{
		glm::vec2 temp;
		glGetMultisamplefv(GL_SAMPLE_POSITION, index, &temp.x);
		return temp;
	}
#endif

inline std::string_view GL::getString(UtilityStringName name)
{
	return std::string_view(reinterpret_cast<const char*>(glGetString(static_cast<unsigned int>(name))));
}

#if GL_DESKTOP || EC(3, 0)
	inline std::string_view GL::getStringi(UtilityStringNamei name, unsigned int index)
	{
		return std::string_view(reinterpret_cast<const char*>(glGetStringi(static_cast<unsigned int>(name), index)));
	}
#endif

#if VC(4, 2) || EC(3, 1)
	inline void GL::detail::memoryBarrier(unsigned int bitfield)
	{
		glMemoryBarrier(bitfield);
	}
#endif
#if VC(4, 5) || EC(3, 1)
	inline void GL::detail::memoryBarrierByRegion(unsigned int bitfield)
	{
		glMemoryBarrierByRegion(bitfield);
	}
#endif