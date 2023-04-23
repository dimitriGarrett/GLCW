#pragma once

#include "Config.h"

#if VC(4, 1) || EC(3, 1)
	#include "API.h"
	#include <string>

	namespace GL
	{
		enum class ProgramPipelineGets : unsigned int
		{
			ACTIVE_PROGRAM = 0x8259,
			VERTEX_SHADER = 0x8B31,
			FRAGMENT_SHADER = 0x8B30,
			INFO_LOG_LENGTH = 0x8B84,
			
#if GL_DESKTOP
			TESS_CONTROL_SHADER = 0x8E88,
			TESS_EVALUATION_SHADER = 0x8E87,
			GEOMETRY_SHADER = 0x8DD9,
#else
			COMPUTE_SHADER = 0x91B9,
			VALIDATE_STATUS = 0x8B83
#endif
		};
		
		//glActiveShaderProgram — set the active program object for a program pipeline object
		GLCW_API void activeShaderProgram(unsigned int pipeline, unsigned int program);

		//glBindProgramPipeline — bind a program pipeline to the current context
		GLCW_API void bindProgramPipeline(unsigned int pipeline);

#if VC(4, 5)
		//glCreateProgramPipelines — create program pipeline objects
		GLCW_API void createProgramPipelines(int n, unsigned int* pipelines);
#endif

		//glDeleteProgramPipelines — delete program pipeline objects
		GLCW_API void deleteProgramPipelines(int n, const unsigned int* pipelines);

		//glGenProgramPipelines — reserve program pipeline object names
		GLCW_API void genProgramPipelines(int n, unsigned int* pipelines);

		//glGetProgramPipeline — retrieve properties of a program pipeline object
		GLCW_API void getProgramPipelineiv(unsigned int pipeline, ProgramPipelineGets pname, int* params);
		//glGetProgramPipeline — retrieve properties of a program pipeline object
		GLCW_API int getProgramPipelineiv(unsigned int pipeline, ProgramPipelineGets pname);

		//glGetProgramPipelineInfoLog — retrieve the info log string from a program pipeline object
		GLCW_API void getProgramPipelineInfoLog(unsigned int pipeline, int bufSize, int* length, char* infoLog);
		//glGetProgramPipelineInfoLog — retrieve the info log string from a program pipeline object
		GLCW_API std::string getProgramPipelineInfoLog(unsigned int pipeline);

		//glIsProgramPipeline — determine if a name corresponds to a program pipeline object
		GLCW_API bool isProgramPipeline(unsigned int pipeline);

		//glValidateProgramPipeline — validate a program pipeline object against current GL state
		GLCW_API void validateProgramPipeline(unsigned int pipeline);
	}
#endif