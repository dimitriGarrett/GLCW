#include "State.h"

#include "GL.h"

inline void GL::blendColor(float r, float g, float b, float a)
{
	glBlendColor(r, g, b, a);
}

inline void GL::blendColor(const glm::vec4& rgba)
{
	glBlendColor(rgba.r, rgba.g, rgba.b, rgba.a);
}

inline void GL::blendEquation(GL_ENUM eq)
{
	glBlendEquation(static_cast<unsigned int>(eq));
}

#if VC(4, 0)
inline void GL::blendEquationi(unsigned int buf, GL_ENUM eq)
{
	glBlendEquationi(buf, static_cast<unsigned int>(eq));
}
#endif

inline void GL::blendEquationSeperate(GL_ENUM rgbMode, GL_ENUM aMode)
{
	glBlendEquationSeparate(static_cast<unsigned int>(rgbMode), static_cast<unsigned int>(aMode));
}

#if VC(4, 0)
inline void GL::blendEquationSeperatei(unsigned int drawBuffer, GL_ENUM rgbMode, GL_ENUM aMode)
{
	glBlendEquationSeparatei(drawBuffer, static_cast<unsigned int>(rgbMode), static_cast<unsigned int>(aMode));
}
#endif

inline void GL::blendFunc(GL_ENUM sfactor, GL_ENUM dfactor)
{
	glBlendFunc(static_cast<unsigned int>(sfactor), static_cast<unsigned int>(dfactor));
}

#if VC(4, 0)
inline void GL::blendFunci(unsigned int drawBuffer, GL_ENUM sfactor, GL_ENUM dfactor)
{
	glBlendFunci(drawBuffer, static_cast<unsigned int>(sfactor), static_cast<unsigned int>(dfactor));
}
#endif

inline void GL::blendFuncSeparate(GL_ENUM srcRGB, GL_ENUM dstRGB, GL_ENUM srcAlpha, GL_ENUM dstAlpha)
{
	glBlendFuncSeparate(static_cast<unsigned int>(srcRGB), static_cast<unsigned int>(dstRGB), static_cast<unsigned int>(srcAlpha), static_cast<unsigned int>(dstAlpha));
}

#if VC(4, 0)
inline void GL::blendFuncSeparatei(unsigned int drawBuffer, GL_ENUM srcRGB, GL_ENUM dstRGB, GL_ENUM srcAlpha, GL_ENUM dstAlpha)
{
	glBlendFuncSeparatei(drawBuffer, static_cast<unsigned int>(srcRGB), static_cast<unsigned int>(dstRGB), static_cast<unsigned int>(srcAlpha), static_cast<unsigned int>(dstAlpha));
}
#endif

#if GL_DESKTOP
inline void GL::clampColor(bool clamp)
{
	glClampColor(GL_CLAMP_READ_COLOR, static_cast<unsigned int>(clamp));
}
#endif

#if VC(4, 5)
inline void GL::clipControl(GL_ENUM origin, GL_ENUM depth)
{
	glClipControl(static_cast<unsigned int>(origin), static_cast<unsigned int>(depth));
}
#endif

inline void GL::colorMask(bool red, bool green, bool blue, bool alpha)
{
	glColorMask(red, green, blue, alpha);
}

inline void GL::colorMask(const glm::bvec4& rgba)
{
	colorMask(rgba.r, rgba.b, rgba.b, rgba.a);
}

#if GL_DESKTOP
	inline void GL::colorMaski(unsigned int drawBuffer, bool red, bool green, bool blue, bool alpha)
	{
		glColorMaski(drawBuffer, red, green, blue, alpha);
	}

	inline void GL::colorMaski(unsigned int drawBuffer, const glm::bvec4& rgba)
	{
		colorMaski(drawBuffer, rgba.r, rgba.b, rgba.b, rgba.a);
	}
#endif

inline void GL::cullFace(GL_ENUM cullMode)
{
	glCullFace(static_cast<unsigned int>(cullMode));
}

inline void GL::depthFunc(GL_ENUM func)
{
	glDepthFunc(static_cast<unsigned int>(func));
}

inline void GL::depthMask(bool write)
{
	glDepthMask(write);
}

#if GL_DESKTOP
inline void GL::depthRange(double near, double far)
{
	glDepthRange(near, far);
}

inline void GL::depthRange(const glm::dvec2& nearAndFar)
{
	depthRange(nearAndFar.x, nearAndFar.y);
}
#endif
#if VC(4, 1) || (!GL_DESKTOP)
inline void GL::depthRangef(float near, float far)
{
	glDepthRangef(near, far);
}

inline void GL::depthRangef(const glm::fvec2& nearAndFar)
{
	depthRangef(nearAndFar.x, nearAndFar.y);
}
#endif

#if VC(4, 1)
inline void GL::depthRangeArrayv(unsigned int first, int count, const std::vector<double>& values)
{
	glDepthRangeArrayv(first, count, &values.front());
}

inline void GL::depthRangeIndexed(unsigned int index, double nearVal, double farVal)
{
	glDepthRangeIndexed(index, nearVal, farVal);
}

inline void GL::depthRangeIndexed(unsigned int index, const glm::vec2& nearAndFar)
{
	depthRangeIndexed(index, nearAndFar.x, nearAndFar.y);
}
#endif

inline void GL::enable(GL_ENUM cap)
{
	glEnable(static_cast<unsigned int>(cap));
}

inline void GL::disable(GL_ENUM cap)
{
	glDisable(static_cast<unsigned int>(cap));
}

#if GL_DESKTOP
inline void GL::enablei(GL_ENUM cap, unsigned int index)
{
	glEnablei(static_cast<unsigned int>(cap), index);
}

inline void GL::disablei(GL_ENUM cap, unsigned int index)
{
	glDisablei(static_cast<unsigned int>(cap), index);
}
#endif

inline void GL::frontFace(GL_ENUM mode)
{
	glFrontFace(static_cast<unsigned int>(mode));
}

inline void GL::getBooleanv(GL_ENUM pname, unsigned char* values)
{
	glGetBooleanv(static_cast<unsigned int>(pname), values);
}

#if GL_DESKTOP
inline void GL::getDoublev(GL_ENUM pname, double* values)
{
	glGetDoublev(static_cast<unsigned int>(pname), values);
}
#endif

inline void GL::getFloatv(GL_ENUM pname, float* values)
{
	glGetFloatv(static_cast<unsigned int>(pname), values);
}

inline void GL::getIntegerv(GL_ENUM pname, int* values)
{
	glGetIntegerv(static_cast<unsigned int>(pname), values);
}

inline void GL::getInteger64v(GL_ENUM pname, signed long long* values)
{
	glGetInteger64v(static_cast<unsigned int>(pname), values);
}

inline void GL::getBooleani_v(GL_ENUM target, unsigned int index, unsigned char* values)
{
	glGetBooleani_v(static_cast<unsigned int>(target), index, values);
}

inline void GL::getIntegeri_v(GL_ENUM target, unsigned int index, int* values)
{
	glGetIntegeri_v(static_cast<unsigned int>(target), index, values);
}

inline void GL::getFloati_v(GL_ENUM target, unsigned int index, float* values)
{
	glGetFloati_v(static_cast<unsigned int>(target), index, values);
}

#if GL_DESKTOP
inline void GL::getDoublei_v(GL_ENUM target, unsigned int index, double* values)
{
	glGetDoublei_v(static_cast<unsigned int>(target), index, values);
}
#endif

inline void GL::getInteger64i_v(GL_ENUM target, unsigned int index, signed long long* values)
{
	glGetInteger64i_v(static_cast<unsigned int>(target), index, values);
}

inline bool GL::getBooleanv(GL_ENUM pname)
{
	unsigned char temp;
	getBooleanv(pname, &temp);
	return temp;
}

#if GL_DESKTOP
inline double GL::getDoublev(GL_ENUM pname)
{
	double temp;
	getDoublev(pname, &temp);
	return temp;
}
#endif

inline float GL::getFloatv(GL_ENUM pname)
{
	float temp;
	getFloatv(pname, &temp);
	return temp;
}

inline int GL::getIntegerv(GL_ENUM pname)
{
	int temp;
	getIntegerv(pname, &temp);
	return temp;
}

inline signed long long GL::getInteger64v(GL_ENUM pname)
{
	signed long long temp;
	getInteger64v(pname, &temp);
	return temp;
}

inline bool GL::getBooleani_v(GL_ENUM target, unsigned int index)
{
	unsigned char temp;
	getBooleani_v(target, index, &temp);
	return temp;
}

inline int GL::getIntegeri_v(GL_ENUM target, unsigned int index)
{
	int temp;
	getIntegeri_v(target, index, &temp);
	return temp;
}

inline float GL::getFloati_v(GL_ENUM target, unsigned int index)
{
	float temp;
	getFloati_v(target, index, &temp);
	return temp;
}

#if GL_DESKTOP
inline double GL::getDoublei_v(GL_ENUM target, unsigned int index)
{
	double temp;
	getDoublei_v(target, index, &temp);
	return temp;
}
#endif

inline signed long long GL::getInteger64i_v(GL_ENUM target, unsigned int index)
{
	signed long long temp;
	getInteger64i_v(target, index, &temp);
	return temp;
}

inline GL::GL_ENUM GL::getError()
{
	return static_cast<GL_ENUM>(glGetError());
}

inline void GL::hint(GL_ENUM target, GL_ENUM mode)
{
	glHint(static_cast<unsigned int>(target), static_cast<unsigned int>(mode));
}

inline bool GL::isEnabled(GL_ENUM cap)
{
	return static_cast<bool>(glIsEnabled(static_cast<unsigned int>(cap)));
}

#if GL_DESKTOP
inline bool GL::isEnabledi(GL_ENUM cap, unsigned int index)
{
	return static_cast<bool>(glIsEnabledi(static_cast<unsigned int>(cap), index));
}
#endif

inline void GL::lineWidth(float width)
{
	glLineWidth(width);
}

#if GL_DESKTOP
inline void GL::logicOp(GL_ENUM opcode)
{
	glLogicOp(static_cast<unsigned int>(opcode));
}

inline void GL::pixelStoref(GL_ENUM pname, float param)
{
	glPixelStoref(static_cast<unsigned int>(pname), param);
}
#endif

inline void GL::pixelStorei(GL_ENUM pname, int param)
{
	glPixelStorei(static_cast<unsigned int>(pname), param);
}

#if GL_DESKTOP
inline void GL::pointParameterf(GL_ENUM pname, float param)
{
	glPointParameterf(static_cast<unsigned int>(pname), param);
}

inline void GL::pointParameteri(GL_ENUM pname, int param)
{
	glPointParameteri(static_cast<unsigned int>(pname), param);
}

inline void GL::pointParameterfv(GL_ENUM pname, const float* params)
{
	glPointParameterfv(static_cast<unsigned int>(pname), params);
}

inline void GL::pointParameteriv(GL_ENUM pname, const int* params)
{
	glPointParameteriv(static_cast<unsigned int>(pname), params);
}

inline void GL::pointSize(float size)
{
	glPointSize(size);
}

inline void GL::polygonMode(GL_ENUM mode)
{
	glPolygonMode(GL_FRONT_AND_BACK, static_cast<unsigned int>(mode));
}
#endif

inline void GL::polygonOffset(float factor, float units)
{
	glPolygonOffset(factor, units);
}

inline void GL::sampleCoverage(float value, bool invert)
{
	glSampleCoverage(value, static_cast<unsigned char>(invert));
}

inline void GL::scissor(int x, int y, int width, int height)
{
	glScissor(x, y, width, height);
}

inline void GL::scissor(const glm::ivec4& xYWidthHeight)
{
	scissor(xYWidthHeight.x, xYWidthHeight.y, xYWidthHeight.z, xYWidthHeight.w);
}

#if GL_DESKTOP
inline void GL::scissorArrayv(unsigned int first, int count, const std::vector<int>& values)
{
	glScissorArrayv(first, count, &values.front());
}

inline void GL::scissorIndexed(unsigned int index, int left, int bottom, int width, int height)
{
	glScissorIndexed(index, left, bottom, width, height);
}

inline void GL::scissorIndexed(unsigned int index, const glm::ivec4& leftBottomWidthHeight)
{
	scissorIndexed(index, leftBottomWidthHeight.x, leftBottomWidthHeight.y, leftBottomWidthHeight.z, leftBottomWidthHeight.w);
}

inline void GL::scissorIndexedv(unsigned int index, const std::vector<int>& values)
{
	glScissorIndexedv(index, &values.front());
}
#endif

inline void GL::stencilFunc(GL_ENUM func, int ref, unsigned int mask)
{
	glStencilFunc(static_cast<unsigned int>(func), ref, mask);
}

inline void GL::stencilFuncSeparate(GL_ENUM face, GL_ENUM func, int ref, unsigned int mask)
{
	glStencilFuncSeparate(static_cast<unsigned int>(face), static_cast<unsigned int>(func), ref, mask);
}

inline void GL::stencilMask(unsigned int mask)
{
	glStencilMask(mask);
}

inline void GL::stencilMaskSeparate(GL_ENUM face, unsigned int mask)
{
	glStencilMaskSeparate(static_cast<unsigned int>(face), mask);
}

inline void GL::stencilOp(GL_ENUM sfail, GL_ENUM dpfail, GL_ENUM dppass)
{
	glStencilOp(static_cast<unsigned int>(sfail), static_cast<unsigned int>(dpfail), static_cast<unsigned int>(dppass));
}

inline void GL::stencilOpSeparate(GL_ENUM face, GL_ENUM sfail, GL_ENUM dpfail, GL_ENUM dppass)
{
	glStencilOpSeparate(static_cast<unsigned int>(face), static_cast<unsigned int>(sfail), static_cast<unsigned int>(dpfail), static_cast<unsigned int>(dppass));
}

inline void GL::viewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}

inline void GL::viewport(const glm::ivec4& xYWidthHeight)
{
	viewport(xYWidthHeight.x, xYWidthHeight.y, xYWidthHeight.z, xYWidthHeight.w);
}

#if VC(4, 1)
inline void GL::viewportArrayv(unsigned int first, int count, const std::vector<float>& values)
{
	glViewportArrayv(first, count, &values.front());
}

inline  void GL::viewportIndexedf(unsigned int index, float x, float y, float width, float height)
{
	glViewportIndexedf(index, x, y, width, height);
}

inline void GL::viewportIndexedf(unsigned int index, const glm::vec4& xYWidthHeight)
{
	viewportIndexedf(index, xYWidthHeight.x, xYWidthHeight.y, xYWidthHeight.z, xYWidthHeight.w);
}

inline void GL::viewportIndexedfv(unsigned int index, const std::vector<float>& values)
{
	glViewportIndexedfv(index, &values.front());
}
#endif