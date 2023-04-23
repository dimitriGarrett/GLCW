#include "TransformFeedback.h"
#include "GL.h"

#if GL_DESKTOP || EC(3, 0)
	inline void GL::beginTransformFeedback(TransformPrimitives primitiveMode)
	{
		glBeginTransformFeedback(static_cast<unsigned int>(primitiveMode));
	}

	inline void GL::endTransformFeedback()
	{
		glEndTransformFeedback();
	}
#endif

#if VC(4, 0) || EC(3, 0)
	inline void GL::bindTransformFeedback(unsigned int id)
	{
		glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, id);
	}
#endif

#if VC(4, 5)
	inline void GL::createTransformFeedbacks(int n, unsigned int* ids)
	{
		glCreateTransformFeedbacks(n, ids);
	}
#endif

#if VC(4, 0) || EC(3, 0)
	inline void GL::deleteTransformFeedbacks(int n, unsigned int* ids)
	{
		glDeleteTransformFeedbacks(n, ids);
	}
#endif

#if VC(4, 0)
	inline void GL::drawTransformFeedback(TransformRenderPrimitives mode, unsigned int id)
	{
		glDrawTransformFeedback(static_cast<unsigned int>(mode), id);
	}
#endif
#if VC(4, 2)
	inline void GL::drawTransformFeedbackInstanced(TransformRenderPrimitives mode, unsigned int id, int primcount)
	{
		glDrawTransformFeedbackInstanced(static_cast<unsigned int>(mode), id, primcount);
	}
#endif
#if VC(4, 0)
	inline void GL::drawTransformFeedbackStream(TransformRenderPrimitives mode, unsigned int id, unsigned int stream)
	{
		glDrawTransformFeedbackStream(static_cast<unsigned int>(mode), id, stream);
	}
#endif
#if VC(4, 2)
	inline void GL::drawTransformFeedbackStreamInstanced(TransformRenderPrimitives mode, unsigned int id, unsigned int stream, int primcount)
	{
		glDrawTransformFeedbackStreamInstanced(static_cast<unsigned int>(mode), id, stream, primcount);
	}
#endif

#if VC(4, 0) || EC(3, 0)
	inline void GL::genTransformFeedbacks(int n, unsigned int* ids)
	{
		glGenTransformFeedbacks(n, ids);
	}
#endif

#if VC(4, 5)
	inline void GL::getTransformFeedbackiv(unsigned int xfb, TransformQueries query, int* param)
	{
		glGetTransformFeedbackiv(xfb, static_cast<unsigned int>(query), param);
	}

	inline void GL::getTransformFeedbacki_v(unsigned xfb, TransformQueries query, unsigned int index, int* param)
	{
		glGetTransformFeedbacki_v(xfb, static_cast<unsigned int>(query), index, param);
	}

	inline void GL::getTransformFeedbacki64_v(unsigned xfb, TransformQueries query, unsigned int index, signed long long* param)
	{
		glGetTransformFeedbacki64_v(xfb, static_cast<unsigned int>(query), index, param);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
	inline void GL::getTransformFeedbackVarying(unsigned int program, unsigned int index, int bufSize, int* length, int* size, unsigned int* type, char* name)
	{
		glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
	}

	inline std::tuple<std::string, int, int> GL::getTransformFeedbackVarying(unsigned int program, unsigned int index)
	{
		int length;
		int len = 0;
		glGetProgramiv(program, GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH, &len);

		std::tuple<std::string, int, unsigned int> temp = { std::string(len, ' '), 0, 0};
		getTransformFeedbackVarying(program, index, len, &length, &std::get<1>(temp), &std::get<2>(temp), &std::get<0>(temp).front());

		return temp;
	}
#endif

#if VC(4, 0) || EC(3, 0)
	inline bool GL::isTransformFeedback(unsigned int id)
	{
		return static_cast<bool>(glIsTransformFeedback(id));
	}
#endif

#if VC(4, 0) || EC(3, 0)
	inline void GL::pauseTransformFeedback()
	{
		glPauseTransformFeedback();
	}

	inline void GL::resumeTransformFeedback()
	{
		glResumeTransformFeedback();
	}
#endif

#if VC(4, 5)
	inline void GL::transformFeedbackBufferBase(unsigned int xfb, unsigned int index, unsigned int buffer)
	{
		glTransformFeedbackBufferBase(xfb, index, buffer);
	}

	inline void GL::transformFeedbackBufferRange(unsigned int xfb, unsigned int index, unsigned int buffer, ptrdiff_t offset, int size)
	{
		glTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
	}
#endif

#if GL_DESKTOP || EC(3, 0)
	inline void GL::transformFeedbackVaryings(unsigned int program, int count, const char** varyings, TransformAttribs bufferMode)
	{
		glTransformFeedbackVaryings(program, count, varyings, static_cast<unsigned int>(bufferMode));
	}

	inline void GL::transformFeedbackVaryings(unsigned int program, const std::vector<const char*>& varyings, TransformAttribs bufferMode)
	{
		transformFeedbackVaryings(program, static_cast<int>(varyings.size()), const_cast<const char**>(&varyings.front()), bufferMode);
	}
#endif