#pragma once

#include "API.h"
#include "Enums.h"

#if GL_DESKTOP || EC(3, 0)
	#include <string>
	#include <vector>
#endif

namespace GL
{
#if GL_DESKTOP || EC(3, 0)
	//glBeginTransformFeedback — start transform feedback operation
	GLCW_API void beginTransformFeedback(GL_ENUM primitiveMode);
	//glBeginTransformFeedback — start transform feedback operation
	GLCW_API void endTransformFeedback();
#endif

#if VC(4, 0) || EC(3, 0)
	//glBindTransformFeedback — bind a transform feedback object
	GLCW_API void bindTransformFeedback(/*GL_TRANSFORM_FEEDBACK, */unsigned int id);
#endif

#if VC(4, 5)
	//glCreateTransformFeedbacks — create transform feedback objects
	GLCW_API void createTransformFeedbacks(int n, unsigned int* ids);
#endif

#if VC(4, 0) || EC(3, 0)
	//glDeleteTransformFeedbacks — delete transform feedback objects
	GLCW_API void deleteTransformFeedbacks(int n, unsigned int* ids);
#endif

#if VC(4, 0)
	//glDrawTransformFeedback — render primitives using a count derived from a transform feedback object
	GLCW_API void drawTransformFeedback(GL_ENUM mode, unsigned int id);
#endif
#if VC(4, 2)
	//glDrawTransformFeedbackInstanced — render multiple instances of primitives using a count derived from a transform feedback object
	GLCW_API void drawTransformFeedbackInstanced(GL_ENUM mode, unsigned int id, int primcount);
#endif
#if VC(4, 0)
	//glDrawTransformFeedbackStream — render primitives using a count derived from a specifed stream of a transform feedback object
	GLCW_API void drawTransformFeedbackStream(GL_ENUM mode, unsigned int id, unsigned int stream);
#endif
#if VC(4, 2)
	//glDrawTransformFeedbackStreamInstanced — render multiple instances of primitives using a count derived from a specifed stream of a transform feedback object
	GLCW_API void drawTransformFeedbackStreamInstanced(GL_ENUM mode, unsigned int id, unsigned int stream, int primcount);
#endif

#if VC(4, 0) || EC(3, 0)
	//glGenTransformFeedbacks — reserve transform feedback object names
	GLCW_API void genTransformFeedbacks(int n, unsigned int* ids);
#endif

#if VC(4, 5)
	//glGetTransformFeedbackiv — query the state of a transform feedback object.
	GLCW_API void getTransformFeedbackiv(unsigned int xfb, GL_ENUM query, int* param);
	//glGetTransformFeedbackiv — query the state of a transform feedback object.
	GLCW_API void getTransformFeedbacki_v(unsigned xfb, GL_ENUM query, unsigned int index, int* param);
	//glGetTransformFeedbackiv — query the state of a transform feedback object.
	GLCW_API void getTransformFeedbacki64_v(unsigned xfb, GL_ENUM query, unsigned int index, signed long long* param);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glGetTransformFeedbackVarying — retrieve information about varying variables selected for transform feedback
	GLCW_API void getTransformFeedbackVarying(unsigned int program, unsigned int index, int bufSize, int* length, int* size, unsigned int* type, char* name);
	//glGetTransformFeedbackVarying — retrieve information about varying variables selected for transform feedback
	GLCW_API std::tuple<std::string, int, int> getTransformFeedbackVarying(unsigned int program, unsigned int index);
#endif

#if VC(4, 0) || EC(3, 0)
	//glIsTransformFeedback — determine if a name corresponds to a transform feedback object
	GLCW_API bool isTransformFeedback(unsigned int id);
#endif

#if VC(4, 0) || EC(3, 0)
	//glPauseTransformFeedback — pause transform feedback operations
	GLCW_API void pauseTransformFeedback();

	//glResumeTransformFeedback — resume transform feedback operations
	GLCW_API void resumeTransformFeedback();
#endif

#if VC(4, 5)
	//glTransformFeedbackBufferBase — bind a buffer object to a transform feedback buffer object
	GLCW_API void transformFeedbackBufferBase(unsigned int xfb, unsigned int index, unsigned int buffer);

	//glTransformFeedbackBufferRange — bind a range within a buffer object to a transform feedback buffer object
	GLCW_API void transformFeedbackBufferRange(unsigned int xfb, unsigned int index, unsigned int buffer, ptrdiff_t offset, int size);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glTransformFeedbackVaryings — specify values to record in transform feedback buffers
	GLCW_API void transformFeedbackVaryings(unsigned int program, int count, const char** varyings, GL_ENUM bufferMode);
	//glTransformFeedbackVaryings — specify values to record in transform feedback buffers
	GLCW_API void transformFeedbackVaryings(unsigned int program, const std::vector<const char*>& varyings, GL_ENUM bufferMode);
#endif
}