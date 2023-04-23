#include "ProgramPipeline.h"

#if VC(4, 1) || EC(3, 1)
	#include "GL.h"
	#include "State.h"

	inline void GL::activeShaderProgram(unsigned int pipeline, unsigned int program)
	{
		glActiveShaderProgram(pipeline, program);
	}

	inline void GL::bindProgramPipeline(unsigned int pipeline)
	{
		glBindProgramPipeline(pipeline);
	}

#if VC(4, 5)
	inline void GL::createProgramPipelines(int n, unsigned int* pipelines)
	{
		glCreateProgramPipelines(n, pipelines);
	}
#endif

	inline void GL::deleteProgramPipelines(int n, const unsigned int* pipelines)
	{
		glDeleteProgramPipelines(n, pipelines);
	}

	inline void GL::genProgramPipelines(int n, unsigned int* pipelines)
	{
		glGenProgramPipelines(n, pipelines);
	}

	inline void GL::getProgramPipelineiv(unsigned int pipeline, ProgramPipelineGets pname, int* params)
	{
		glGetProgramPipelineiv(pipeline, static_cast<unsigned int>(pname), params);
	}

	inline int GL::getProgramPipelineiv(unsigned int pipeline, ProgramPipelineGets pname)
	{
		int temp;
		getProgramPipelineiv(pipeline, pname, &temp);
		return temp;
	}

	inline void GL::getProgramPipelineInfoLog(unsigned int pipeline, int bufSize, int* length, char* infoLog)
	{
		glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
	}

	inline std::string GL::getProgramPipelineInfoLog(unsigned int pipeline)
	{
		//TODO: use glGetProgram to get the max info log length instead of hardcoding 1024
		int length;
		std::string temp(getProgramPipelineiv(pipeline, ProgramPipelineGets::INFO_LOG_LENGTH), ' ');
	
		getProgramPipelineInfoLog(pipeline, static_cast<int>(temp.size()), &length, &temp.front());

		return temp.substr(0, length);
	}

	inline bool GL::isProgramPipeline(unsigned int pipeline)
	{
		return static_cast<bool>(glIsProgramPipeline(pipeline));
	}

	inline void GL::validateProgramPipeline(unsigned int pipeline)
	{
		glValidateProgramPipeline(pipeline);
	}

#endif
