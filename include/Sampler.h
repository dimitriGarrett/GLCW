#pragma once

#include "Config.h"

#if GL_DESKTOP || EC(3, 0)

#include "API.h"
#include <vector>

namespace GL
{
	enum class SamplerParameter
	{
		TEXTURE_MAG_FILTER = 0x2800,
		TEXTURE_MIN_FILTER = 0x2801,
		TEXTURE_MIN_LOD = 0x813A,
		TEXTURE_MAX_LOD = 0x813B,
		TEXTURE_WRAP_S = 0x2802,
		TEXTURE_WRAP_T = 0x2803,
		TEXTURE_WRAP_R = 0x8072,
		TEXTURE_COMPARE_MODE = 0x884C,
		TEXTURE_COMPARE_FUNC = 0x884D,

#if GL_DESKTOP
		TEXTURE_BORDER_COLOR = 0x1004,
#endif
	};

	//glBindSampler — bind a named sampler to a texturing target
	GLCW_API void bindSampler(unsigned int unit, unsigned int sampler);

#if VC(4, 4)
	//glBindSamplers — bind one or more named sampler objects to a sequence of consecutive sampler units
	GLCW_API void bindSamplers(unsigned int first, int count, const unsigned int* samplers);
	//glBindSamplers — bind one or more named sampler objects to a sequence of consecutive sampler units
	GLCW_API void bindSamplers(unsigned int first, const std::vector<unsigned int>& samplers);
#endif

#if VC(4, 5)
	//glCreateSamplers — create sampler objects
	GLCW_API void createSamplers(int n, unsigned int* samplers);
#endif

	//glDeleteSamplers — delete named sampler objects
	GLCW_API void deleteSamplers(int n, const unsigned int* samplers);

	//glGenSamplers — generate sampler object names
	GLCW_API void genSamplers(int n, unsigned int* samplers);

	//glGetSamplerParameter — return sampler parameter values
	GLCW_API void getSamplerParameterfv(unsigned sampler, SamplerParameter pname, float* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API float getSamplerParameterfv(unsigned sampler, SamplerParameter pname);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API void getSamplerParameteriv(unsigned sampler, SamplerParameter pname, int* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API int getSamplerParameteriv(unsigned sampler, SamplerParameter pname);

#if GL_DESKTOP
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API void getSamplerParameterIiv(unsigned sampler, SamplerParameter pname, int* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API int getSamplerParameterIiv(unsigned sampler, SamplerParameter pname);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API void getSamplerParameterIuiv(unsigned sampler, SamplerParameter pname, unsigned int* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API unsigned int getSamplerParameterIuiv(unsigned sampler, SamplerParameter pname);
#endif

	//glIsSampler — determine if a name corresponds to a sampler object
	GLCW_API bool isSampler(unsigned int id);

	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterf(unsigned sampler, SamplerParameter pname, float param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameteri(unsigned sampler, SamplerParameter pname, int param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterfv(unsigned sampler, SamplerParameter pname, const float* param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameteriv(unsigned sampler, SamplerParameter pname, const int* param);

#if GL_DESKTOP
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterIiv(unsigned sampler, SamplerParameter pname, const int* param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterIuiv(unsigned sampler, SamplerParameter pname, const unsigned int* param);
#endif
}
#endif