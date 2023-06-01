#pragma once

#include "API.h"
#include "Enums.h"

#include <vector>

namespace GL
{
	//glBlendColor — set the blend color
	GLCW_API void blendColor(float r, float g, float b, float a);
	//glBlendColor — set the blend color
	GLCW_API void blendColor(const fvec4& rgba);

	//glBlendEquation — specify the equation used for both the RGB blend equation and the Alpha blend equation
	GLCW_API void blendEquation(GL_ENUM eq);

#if VC(4, 0)
	//glBlendEquation — specify the equation used for both the RGB blend equation and the Alpha blend equation
	GLCW_API void blendEquationi(unsigned int drawBuffer, GL_ENUM eq);
#endif

	//glBlendEquationSeparate — set the RGB blend equation and the alpha blend equation separately
	GLCW_API void blendEquationSeperate(GL_ENUM rgbMode, GL_ENUM aMode);

#if VC(4, 0)
	//glBlendEquationSeparate — set the RGB blend equation and the alpha blend equation separately
	GLCW_API void blendEquationSeperatei(unsigned int drawBuffer, GL_ENUM rgbMode, GL_ENUM aMode);
#endif

	//glBlendFunc — specify pixel arithmetic
	GLCW_API void blendFunc(GL_ENUM sfactor, GL_ENUM dfactor);

#if VC(4, 0)
	//glBlendFunc — specify pixel arithmetic
	GLCW_API void blendFunci(unsigned int drawBuffer, GL_ENUM sfactor, GL_ENUM dfactor);
#endif

	//glBlendFuncSeparate — specify pixel arithmetic for RGB and alpha components separately
	GLCW_API void blendFuncSeparate(GL_ENUM srcRGB, GL_ENUM dstRGB, GL_ENUM srcAlpha, GL_ENUM dstAlpha);

#if VC(4, 0)
	//glBlendFuncSeparate — specify pixel arithmetic for RGB and alpha components separately
	GLCW_API void blendFuncSeparatei(unsigned int drawBuffer, GL_ENUM srcRGB, GL_ENUM dstRGB, GL_ENUM srcAlpha, GL_ENUM dstAlpha);
#endif

#if GL_DESKTOP
	//glClampColor — specify whether data read via glReadPixels should be clamped
	GLCW_API void clampColor(bool clamp);
#endif

#if VC(4, 5)
	//glClipControl — control clip coordinate to window coordinate behavior
	GLCW_API void clipControl(GL_ENUM origin, GL_ENUM depth);
#endif

	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMask(bool red, bool green, bool blue, bool alpha);
	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMask(const bvec4& rgba);

#if GL_DESKTOP
	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMaski(unsigned int drawBuffer, bool red, bool green, bool blue, bool alpha);
	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMaski(unsigned int drawBuffer, const bvec4& rgba);
#endif

	//glCullFace — specify whether front- or back-facing facets can be culled
	GLCW_API void cullFace(GL_ENUM cullMode);

	//glDepthFunc — specify the value used for depth buffer comparisons
	GLCW_API void depthFunc(GL_ENUM func);

	//glDepthMask — enable or disable writing into the depth buffer
	GLCW_API void depthMask(bool writeDepthToBuffer);

#if GL_DESKTOP
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRange(double near, double far);
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRange(const dvec2& nearAndFar);
#endif

#if VC(4, 1) || (!GL_DESKTOP)
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRangef(float near, float far);
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRangef(const fvec2& nearAndFar);
#endif

#if VC(4, 1)
	//glDepthRangeArray — specify mapping of depth values from normalized device coordinates to window coordinates for a specified set of viewports
	GLCW_API void depthRangeArrayv(unsigned int first, int count, const std::vector<double>& values);

	//glDepthRangeIndexed — specify mapping of depth values from normalized device coordinates to window coordinates for a specified viewport
	GLCW_API void depthRangeIndexed(unsigned int index, double nearVal, double farVal);
	//glDepthRangeIndexed — specify mapping of depth values from normalized device coordinates to window coordinates for a specified viewport
	GLCW_API void depthRangeIndexed(unsigned int index, const dvec2& nearAndFar);
#endif

	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void enable(GL_ENUM cap);
	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void disable(GL_ENUM cap);

#if GL_DESKTOP
	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void enablei(GL_ENUM cap, unsigned int index);
	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void disablei(GL_ENUM cap, unsigned int index);
#endif

	//glFrontFace — define front- and back-facing polygons
	GLCW_API void frontFace(GL_ENUM mode);

	//glGet — return the value or values of a selected parameter
	GLCW_API void getBooleanv(GL_ENUM pname, unsigned char* values);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API void getDoublev(GL_ENUM pname, double* values);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API void getFloatv(GL_ENUM pname, float* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getIntegerv(GL_ENUM pname, int* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getInteger64v(GL_ENUM pname, signed long long* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getBooleani_v(GL_ENUM target, unsigned int index, unsigned char* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getIntegeri_v(GL_ENUM target, unsigned int index, int* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getFloati_v(GL_ENUM target, unsigned int index, float* values);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API void getDoublei_v(GL_ENUM target, unsigned int index, double* values);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API void getInteger64i_v(GL_ENUM target, unsigned int index, signed long long* values);

	//glGet — return the value or values of a selected parameter
	GLCW_API bool getBooleanv(GL_ENUM pname);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API double getDoublev(GL_ENUM pname);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API float getFloatv(GL_ENUM pname);
	//glGet — return the value or values of a selected parameter
	GLCW_API int getIntegerv(GL_ENUM pname);
	//glGet — return the value or values of a selected parameter
	GLCW_API signed long long getInteger64v(GL_ENUM pname);
	//glGet — return the value or values of a selected parameter
	GLCW_API bool getBooleani_v(GL_ENUM target, unsigned int index);
	//glGet — return the value or values of a selected parameter
	GLCW_API int getIntegeri_v(GL_ENUM target, unsigned int index);
	//glGet — return the value or values of a selected parameter
	GLCW_API float getFloati_v(GL_ENUM target, unsigned int index);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API double getDoublei_v(GL_ENUM target, unsigned int index);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API signed long long getInteger64i_v(GL_ENUM target, unsigned int index);

	//glGetError — return error information
	GLCW_API GL_ENUM getError();

	//glHint — specify implementation-specific hints
	GLCW_API void hint(GL_ENUM target, GL_ENUM mode);

	//glIsEnabled, glIsEnabledi — test whether a capability is enabled
	GLCW_API bool isEnabled(GL_ENUM cap);
#if GL_DESKTOP
	//glIsEnabled, glIsEnabledi — test whether a capability is enabled
	GLCW_API bool isEnabledi(GL_ENUM cap, unsigned int index);
#endif
	//glLineWidth — specify the width of rasterized lines
	GLCW_API void lineWidth(float width);

#if GL_DESKTOP
	//glLogicOp — specify a logical pixel operation for rendering
	GLCW_API void logicOp(GL_ENUM opcode);

	//glPixelStore — set pixel storage modes
	GLCW_API void pixelStoref(GL_ENUM pname, float param);
#endif
	//glPixelStore — set pixel storage modes
	GLCW_API void pixelStorei(GL_ENUM pname, int param);

#if GL_DESKTOP
	//glPointParameter — specify point parameters
	GLCW_API void pointParameterf(GL_ENUM pname, float param);
	//glPointParameter — specify point parameters
	GLCW_API void pointParameteri(GL_ENUM pname, int param);
	//glPointParameter — specify point parameters
	GLCW_API void pointParameterfv(GL_ENUM pname, const float* params);
	//glPointParameter — specify point parameters
	GLCW_API void pointParameteriv(GL_ENUM pname, const int* params);

	//glPointSize — specify the diameter of rasterized points
	GLCW_API void pointSize(float size);

	//glPolygonMode — select a polygon rasterization mode
	GLCW_API void polygonMode(GL_ENUM mode);
#endif

	//glPolygonOffset — set the scale and units used to calculate depth values
	GLCW_API void polygonOffset(float factor, float units);

	//glSampleCoverage — specify multisample coverage parameters
	GLCW_API void sampleCoverage(float value, bool invert);

	//glScissor — define the scissor box
	GLCW_API void scissor(int x, int y, int width, int height);
	//glScissor — define the scissor box
	GLCW_API void scissor(const ivec4& xYWidthHeight);

#if GL_DESKTOP
	//glScissorArray — define the scissor box for multiple viewports
	GLCW_API void scissorArrayv(unsigned int first, int count, const std::vector<int>& values);

	//glScissorIndexed — define the scissor box for a specific viewport
	GLCW_API void scissorIndexed(unsigned int index, int left, int bottom, int width, int height);
	//glScissorIndexed — define the scissor box for a specific viewport
	GLCW_API void scissorIndexed(unsigned int index, const ivec4& leftBottomWidthHeight);
	//glScissorIndexed — define the scissor box for a specific viewport
	GLCW_API void scissorIndexedv(unsigned int index, const std::vector<int>& values);
#endif

	//glStencilFunc — set front and back function and reference value for stencil testing
	GLCW_API void stencilFunc(GL_ENUM func, int ref, unsigned int mask);

	//glStencilFuncSeparate — set front and/or back function and reference value for stencil testing
	GLCW_API void stencilFuncSeparate(GL_ENUM face, GL_ENUM func, int ref, unsigned int mask);

	//glStencilMask — control the front and back writing of individual bits in the stencil planes
	GLCW_API void stencilMask(unsigned int mask);

	//glStencilMaskSeparate — control the front and/or back writing of individual bits in the stencil planes
	GLCW_API void stencilMaskSeparate(GL_ENUM face, unsigned int mask);

	//glStencilOp — set front and back stencil test actions
	GLCW_API void stencilOp(GL_ENUM sfail, GL_ENUM dpfail, GL_ENUM dppass);

	//glStencilOpSeparate — set front and/or back stencil test actions
	GLCW_API void stencilOpSeparate(GL_ENUM face, GL_ENUM sfail, GL_ENUM dpfail, GL_ENUM dppass);

	//glViewport — set the viewport
	GLCW_API void viewport(int x, int y, int width, int height);
	//glViewport — set the viewport
	GLCW_API void viewport(const ivec4& xYWidthHeight);

#if VC(4, 1)
	//glViewportArray — set multiple viewports
	GLCW_API void viewportArrayv(unsigned int first, int count, const std::vector<float>& values);

	//glViewportIndexed — set a specified viewport
	GLCW_API void viewportIndexedf(unsigned int index, float x, float y, float width, float height);
	//glViewportIndexed — set a specified viewport
	GLCW_API void viewportIndexedf(unsigned int index, const fvec4& xYWidthHeight);
	//glViewportIndexed — set a specified viewport
	GLCW_API void viewportIndexedfv(unsigned int index, const std::vector<float>& values);
#endif
}