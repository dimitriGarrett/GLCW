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

inline void GL::blendEquation(BlendEquations eq)
{
	glBlendEquation(static_cast<unsigned int>(eq));
}

#if VC(4, 0)
inline void GL::blendEquationi(unsigned int buf, BlendEquations eq)
{
	glBlendEquationi(buf, static_cast<unsigned int>(eq));
}
#endif

inline void GL::blendEquationSeperate(BlendEquations rgbMode, BlendEquations aMode)
{
	glBlendEquationSeparate(static_cast<unsigned int>(rgbMode), static_cast<unsigned int>(aMode));
}

#if VC(4, 0)
inline void GL::blendEquationSeperatei(unsigned int drawBuffer, BlendEquations rgbMode, BlendEquations aMode)
{
	glBlendEquationSeparatei(drawBuffer, static_cast<unsigned int>(rgbMode), static_cast<unsigned int>(aMode));
}
#endif

inline void GL::blendFunc(BlendFuncs sfactor, BlendFuncs dfactor)
{
	glBlendFunc(static_cast<unsigned int>(sfactor), static_cast<unsigned int>(dfactor));
}

#if VC(4, 0)
inline void GL::blendFunci(unsigned int drawBuffer, BlendFuncs sfactor, BlendFuncs dfactor)
{
	glBlendFunci(drawBuffer, static_cast<unsigned int>(sfactor), static_cast<unsigned int>(dfactor));
}
#endif

inline void GL::blendFuncSeparate(BlendFuncs srcRGB, BlendFuncs dstRGB, BlendFuncs srcAlpha, BlendFuncs dstAlpha)
{
	glBlendFuncSeparate(static_cast<unsigned int>(srcRGB), static_cast<unsigned int>(dstRGB), static_cast<unsigned int>(srcAlpha), static_cast<unsigned int>(dstAlpha));
}

#if VC(4, 0)
inline void GL::blendFuncSeparatei(unsigned int drawBuffer, BlendFuncs srcRGB, BlendFuncs dstRGB, BlendFuncs srcAlpha, BlendFuncs dstAlpha)
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
inline void GL::clipControl(Clips origin, ClipDepths depth)
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

inline void GL::cullFace(Faces cullMode)
{
	glCullFace(static_cast<unsigned int>(cullMode));
}

inline void GL::depthFunc(StateCompareFuncs func)
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

inline void GL::enable(StateEnables cap)
{
	glEnable(static_cast<unsigned int>(cap));
}

inline void GL::disable(StateEnables cap)
{
	glDisable(static_cast<unsigned int>(cap));
}

#if GL_DESKTOP
inline void GL::enablei(StateEnables cap, unsigned int index)
{
	glEnablei(static_cast<unsigned int>(cap), index);
}

inline void GL::disablei(StateEnables cap, unsigned int index)
{
	glDisablei(static_cast<unsigned int>(cap), index);
}
#endif

inline void GL::frontFace(FrontFaces mode)
{
	glFrontFace(static_cast<unsigned int>(mode));
}

inline void GL::getBooleanv(StateGets pname, unsigned char* values)
{
	glGetBooleanv(static_cast<unsigned int>(pname), values);
}

#if GL_DESKTOP
inline void GL::getDoublev(StateGets pname, double* values)
{
	glGetDoublev(static_cast<unsigned int>(pname), values);
}
#endif

inline void GL::getFloatv(StateGets pname, float* values)
{
	glGetFloatv(static_cast<unsigned int>(pname), values);
}

inline void GL::getIntegerv(StateGets pname, int* values)
{
	glGetIntegerv(static_cast<unsigned int>(pname), values);
}

inline void GL::getInteger64v(StateGets pname, signed long long* values)
{
	glGetInteger64v(static_cast<unsigned int>(pname), values);
}

inline void GL::getBooleani_v(StateGets target, unsigned int index, unsigned char* values)
{
	glGetBooleani_v(static_cast<unsigned int>(target), index, values);
}

inline void GL::getIntegeri_v(StateGets target, unsigned int index, int* values)
{
	glGetIntegeri_v(static_cast<unsigned int>(target), index, values);
}

inline void GL::getFloati_v(StateGets target, unsigned int index, float* values)
{
	glGetFloati_v(static_cast<unsigned int>(target), index, values);
}

#if GL_DESKTOP
inline void GL::getDoublei_v(StateGets target, unsigned int index, double* values)
{
	glGetDoublei_v(static_cast<unsigned int>(target), index, values);
}
#endif

inline void GL::getInteger64i_v(StateGets target, unsigned int index, signed long long* values)
{
	glGetInteger64i_v(static_cast<unsigned int>(target), index, values);
}

inline bool GL::getBooleanv(StateGets pname)
{
	unsigned char temp;
	getBooleanv(pname, &temp);
	return temp;
}

#if GL_DESKTOP
inline double GL::getDoublev(StateGets pname)
{
	double temp;
	getDoublev(pname, &temp);
	return temp;
}
#endif

inline float GL::getFloatv(StateGets pname)
{
	float temp;
	getFloatv(pname, &temp);
	return temp;
}

inline int GL::getIntegerv(StateGets pname)
{
	int temp;
	getIntegerv(pname, &temp);
	return temp;
}

inline signed long long GL::getInteger64v(StateGets pname)
{
	signed long long temp;
	getInteger64v(pname, &temp);
	return temp;
}

inline bool GL::getBooleani_v(StateGets target, unsigned int index)
{
	unsigned char temp;
	getBooleani_v(target, index, &temp);
	return temp;
}

inline int GL::getIntegeri_v(StateGets target, unsigned int index)
{
	int temp;
	getIntegeri_v(target, index, &temp);
	return temp;
}

inline float GL::getFloati_v(StateGets target, unsigned int index)
{
	float temp;
	getFloati_v(target, index, &temp);
	return temp;
}

#if GL_DESKTOP
inline double GL::getDoublei_v(StateGets target, unsigned int index)
{
	double temp;
	getDoublei_v(target, index, &temp);
	return temp;
}
#endif

inline signed long long GL::getInteger64i_v(StateGets target, unsigned int index)
{
	signed long long temp;
	getInteger64i_v(target, index, &temp);
	return temp;
}

inline GL::StateErrors GL::getError()
{
	return static_cast<StateErrors>(glGetError());
}

inline void GL::hint(StateHints target, StateHintModes mode)
{
	glHint(static_cast<unsigned int>(target), static_cast<unsigned int>(mode));
}

inline bool GL::isEnabled(StateEnables cap)
{
	return static_cast<bool>(glIsEnabled(static_cast<unsigned int>(cap)));
}

#if GL_DESKTOP
inline bool GL::isEnabledi(StateEnables cap, unsigned int index)
{
	return static_cast<bool>(glIsEnabledi(static_cast<unsigned int>(cap), index));
}
#endif

inline void GL::lineWidth(float width)
{
	glLineWidth(width);
}

#if GL_DESKTOP
inline void GL::logicOp(StateLogics opcode)
{
	glLogicOp(static_cast<unsigned int>(opcode));
}

inline void GL::pixelStoref(StatePixelStores pname, float param)
{
	glPixelStoref(static_cast<unsigned int>(pname), param);
}
#endif

inline void GL::pixelStorei(StatePixelStores pname, int param)
{
	glPixelStorei(static_cast<unsigned int>(pname), param);
}

#if GL_DESKTOP
inline void GL::pointParameterf(StatePointParameters pname, float param)
{
	glPointParameterf(static_cast<unsigned int>(pname), param);
}

inline void GL::pointParameteri(StatePointParameters pname, int param)
{
	glPointParameteri(static_cast<unsigned int>(pname), param);
}

inline void GL::pointParameterfv(StatePointParameters pname, const float* params)
{
	glPointParameterfv(static_cast<unsigned int>(pname), params);
}

inline void GL::pointParameteriv(StatePointParameters pname, const int* params)
{
	glPointParameteriv(static_cast<unsigned int>(pname), params);
}

inline void GL::pointSize(float size)
{
	glPointSize(size);
}

inline void GL::polygonMode(StatePolygonModes mode)
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

inline void GL::stencilFunc(StateCompareFuncs func, int ref, unsigned int mask)
{
	glStencilFunc(static_cast<unsigned int>(func), ref, mask);
}

inline void GL::stencilFuncSeparate(Faces face, StateCompareFuncs func, int ref, unsigned int mask)
{
	glStencilFuncSeparate(static_cast<unsigned int>(face), static_cast<unsigned int>(func), ref, mask);
}

inline void GL::stencilMask(unsigned int mask)
{
	glStencilMask(mask);
}

inline void GL::stencilMaskSeparate(Faces face, unsigned int mask)
{
	glStencilMaskSeparate(static_cast<unsigned int>(face), mask);
}

inline void GL::stencilOp(StateStencilOps sfail, StateStencilOps dpfail, StateStencilOps dppass)
{
	glStencilOp(static_cast<unsigned int>(sfail), static_cast<unsigned int>(dpfail), static_cast<unsigned int>(dppass));
}

inline void GL::stencilOpSeparate(Faces face, StateStencilOps sfail, StateStencilOps dpfail, StateStencilOps dppass)
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