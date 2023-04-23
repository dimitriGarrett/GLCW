#include "Sampler.h"

#if GL_DESKTOP || EC(3, 0)
#include "GL.h"

inline void GL::bindSampler(unsigned int unit, unsigned int sampler)
{
	glBindSampler(unit, sampler);
}

#if VC(4, 4)
inline void GL::bindSamplers(unsigned int first, int count, const unsigned int* samplers)
{
	glBindSamplers(first, count, samplers);
}

inline void GL::bindSamplers(unsigned int first, const std::vector<unsigned int>& samplers)
{
	bindSamplers(first, static_cast<int>(samplers.size()), &samplers.front());
}
#endif

#if VC(4, 5)
inline void GL::createSamplers(int n, unsigned int* samplers)
{
	glCreateSamplers(n, samplers);
}
#endif

inline void GL::deleteSamplers(int n, const unsigned int* samplers)
{
	glDeleteSamplers(n, samplers);
}

inline void GL::genSamplers(int n, unsigned int* samplers)
{
	glGenSamplers(n, samplers);
}

inline void GL::getSamplerParameterfv(unsigned sampler, SamplerParameter pname, float* params)
{
	glGetSamplerParameterfv(sampler, static_cast<unsigned int>(pname), params);
}

inline float GL::getSamplerParameterfv(unsigned sampler, SamplerParameter pname)
{
	float temp;
	getSamplerParameterfv(sampler, pname, &temp);
	return temp;
}

inline void GL::getSamplerParameteriv(unsigned sampler, SamplerParameter pname, int* params)
{
	glGetSamplerParameteriv(sampler, static_cast<unsigned int>(pname), params);
}

inline int GL::getSamplerParameteriv(unsigned sampler, SamplerParameter pname)
{
	int temp;
	getSamplerParameteriv(sampler, pname, &temp);
	return temp;
}

#if GL_DESKTOP
inline void GL::getSamplerParameterIiv(unsigned sampler, SamplerParameter pname, int* params)
{
	glGetSamplerParameterIiv(sampler, static_cast<unsigned int>(pname), params);
}

inline int GL::getSamplerParameterIiv(unsigned sampler, SamplerParameter pname)
{
	int temp;
	getSamplerParameterIiv(sampler, pname, &temp);
	return temp;
}

inline void GL::getSamplerParameterIuiv(unsigned sampler, SamplerParameter pname, unsigned int* params)
{
	glGetSamplerParameterIuiv(sampler, static_cast<unsigned int>(pname), params);
}

inline unsigned int GL::getSamplerParameterIuiv(unsigned sampler, SamplerParameter pname)
{
	unsigned int temp;
	getSamplerParameterIuiv(sampler, pname, &temp);
	return temp;
}
#endif

inline bool GL::isSampler(unsigned int id)
{
	return static_cast<bool>(glIsSampler(id));
}

inline void GL::samplerParameterf(unsigned sampler, SamplerParameter pname, float param)
{
	glSamplerParameterf(sampler, static_cast<unsigned int>(pname), param);
}

inline void GL::samplerParameteri(unsigned sampler, SamplerParameter pname, int param)
{
	glSamplerParameteri(sampler, static_cast<unsigned int>(pname), param);
}

inline void GL::samplerParameterfv(unsigned sampler, SamplerParameter pname, const float* param)
{
	glSamplerParameterfv(sampler, static_cast<unsigned int>(pname), param);
}

inline void GL::samplerParameteriv(unsigned sampler, SamplerParameter pname, const int* param)
{
	glSamplerParameteriv(sampler, static_cast<unsigned int>(pname), param);
}

#if GL_DESKTOP
inline void GL::samplerParameterIiv(unsigned sampler, SamplerParameter pname, const int* param)
{
	glSamplerParameterIiv(sampler, static_cast<unsigned int>(pname), param);
}

inline void GL::samplerParameterIuiv(unsigned sampler, SamplerParameter pname, const unsigned int* param)
{
	glSamplerParameterIuiv(sampler, static_cast<unsigned int>(pname), param);
}
#endif
#endif