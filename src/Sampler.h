#pragma once

#include "Enums.h"

#if GL_DESKTOP || EC(3, 0)

#include "API.h"
#include <vector>

namespace GL
{
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
	GLCW_API void getSamplerParameterfv(unsigned sampler, GL_ENUM pname, float* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API float getSamplerParameterfv(unsigned sampler, GL_ENUM pname);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API void getSamplerParameteriv(unsigned sampler, GL_ENUM pname, int* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API int getSamplerParameteriv(unsigned sampler, GL_ENUM pname);

#if GL_DESKTOP
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API void getSamplerParameterIiv(unsigned sampler, GL_ENUM pname, int* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API int getSamplerParameterIiv(unsigned sampler, GL_ENUM pname);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API void getSamplerParameterIuiv(unsigned sampler, GL_ENUM pname, unsigned int* params);
	//glGetSamplerParameter — return sampler parameter values
	GLCW_API unsigned int getSamplerParameterIuiv(unsigned sampler, GL_ENUM pname);
#endif

	//glIsSampler — determine if a name corresponds to a sampler object
	GLCW_API bool isSampler(unsigned int id);

	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterf(unsigned sampler, GL_ENUM pname, float param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameteri(unsigned sampler, GL_ENUM pname, int param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterfv(unsigned sampler, GL_ENUM pname, const float* param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameteriv(unsigned sampler, GL_ENUM pname, const int* param);

#if GL_DESKTOP
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterIiv(unsigned sampler, GL_ENUM pname, const int* param);
	//glSamplerParameter — set sampler parameters
	GLCW_API void samplerParameterIuiv(unsigned sampler, GL_ENUM pname, const unsigned int* param);
#endif
}
#endif