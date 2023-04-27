#pragma once

#include "API.h"
#include "GLM.h"
#include "Enums.h"

#include <string_view>
#include <vector>
#include <tuple>

#include "BitfieldWrapper.h"

namespace GL
{
	static constexpr BITFIELD_WRAP(1) VERTEX_SHADER_BIT;
	static constexpr BITFIELD_WRAP(2) FRAGMENT_SHADER_BIT;
	static constexpr BITFIELD_WRAP(4) GEOMETRY_SHADER_BIT;
	static constexpr BITFIELD_WRAP(8) TESS_CONTROL_SHADER_BIT;
	static constexpr BITFIELD_WRAP(16) TESS_EVALUATION_SHADER_BIT;
	static constexpr BITFIELD_WRAP(32) COMPUTE_SHADER_BIT;
	static constexpr BITFIELD_WRAP(0xFFFFFFFF) ALL_SHADER_BITS;

	namespace detail
	{
#if VC(4, 1) || EC(3, 1)
		GLCW_API void useProgramStages(unsigned int pipeline, unsigned int stages, unsigned int program);
#endif
	}

	//glAttachShader — Attaches a shader object to a program object
	GLCW_API void attachShader(unsigned int program, unsigned int shader);

	//glBindAttribLocation — Associates a generic vertex attribute index with a named attribute variable
	GLCW_API void bindAttribLocation(unsigned int program, unsigned index, std::string_view name);

#if GL_DESKTOP
	//glBindFragDataLocation — bind a user-defined varying out variable to a fragment shader color number
	GLCW_API void bindFragDataLocation(unsigned int program, unsigned int colorNumber, std::string_view name);

	//glBindFragDataLocationIndexed — bind a user-defined varying out variable to a fragment shader color number and index
	GLCW_API void bindFragDataLocationIndexed(unsigned int program, unsigned int colorNumber, unsigned int index, std::string_view name);
#endif

	//glCompileShader — Compiles a shader object
	GLCW_API void compileShader(unsigned int shader);

	//glCreateProgram — Creates a program object
	GLCW_API unsigned int createProgram();

	//glCreateShader — Creates a shader object
	GLCW_API unsigned int createShader(GL_ENUM shaderType);

#if VC(4, 1) || EC(3, 1)
	//glCreateShaderProgramv — create a stand-alone program from an array of null-terminated source code strings
	GLCW_API unsigned int createShaderProgramv(GL_ENUM type, int count, const char** strings);
	//glCreateShaderProgramv — create a stand-alone program from an array of null-terminated source code strings
	GLCW_API unsigned int createShaderProgramv(GL_ENUM type, const std::vector<std::string>& strings);
#endif

	//glDeleteProgram — Deletes a program object
	GLCW_API void deleteProgram(unsigned int program);

	//glDeleteShader — Deletes a shader object
	GLCW_API void deleteShader(unsigned int shader);

	//glDetachShader — Detaches a shader object from a program object to which it is attached
	GLCW_API void detachShader(unsigned int program, unsigned int shader);

#if VC(4, 2)
	//glGetActiveAtomicCounterBufferiv — retrieve information about the set of active atomic counter buffers for a program
	GLCW_API void getActiveAtomicCounterBufferiv(unsigned int program, unsigned int bufferIndex, GL_ENUM pname, int* params);
	//glGetActiveAtomicCounterBufferiv — retrieve information about the set of active atomic counter buffers for a program
	GLCW_API int getActiveAtomicCounterBufferiv(unsigned int program, unsigned int bufferIndex, GL_ENUM pname);
#endif

	//glGetActiveAttrib — Returns information about an active attribute variable for the specified program object
	GLCW_API void getActiveAttrib(unsigned int program, unsigned int index, int bufSize, int* length, int* size, GL_ENUM* type, char* name);
	//glGetActiveAttrib — Returns information about an active attribute variable for the specified program object
	GLCW_API std::tuple<int, GL_ENUM , std::string> getActiveAttrib(unsigned int program, unsigned int index);

#if VC(4, 0)
	//glGetActiveSubroutineName — query the name of an active shader subroutine
	GLCW_API void getActiveSubroutineName(unsigned int program, GL_ENUM shadertype, unsigned int index, int bufsize, int* length, char* name);
	//glGetActiveSubroutineName — query the name of an active shader subroutine
	GLCW_API std::string getActiveSubroutineName(unsigned int program, GL_ENUM shadertype, unsigned int index);

	//glGetActiveSubroutineUniform — query a property of an active shader subroutine uniform
	GLCW_API void getActiveSubroutineUniformiv(unsigned int program, GL_ENUM shadertype, unsigned int index, GL_ENUM pname, int* values);
	//glGetActiveSubroutineUniform — query a property of an active shader subroutine uniform
	GLCW_API int getActiveSubroutineUniformiv(unsigned int program, GL_ENUM shadertype, unsigned int index, GL_ENUM pname);

	//glGetActiveSubroutineUniformName — query the name of an active shader subroutine uniform
	GLCW_API void getActiveSubroutineUniformName(unsigned int program, GL_ENUM shadertype, unsigned int index, int bufsize, int* length, char* name);
	//glGetActiveSubroutineUniformName — query the name of an active shader subroutine uniform
	GLCW_API std::string getActiveSubroutineUniformName(unsigned int program, GL_ENUM shadertype, unsigned int index);
#endif

	//glGetActiveUniform — Returns information about an active uniform variable for the specified program object
	GLCW_API void getActiveUniform(unsigned int program, unsigned int index, int bufSize, int* length, int* size, GL_ENUM* type, char* name);
	//glGetActiveUniform — Returns information about an active uniform variable for the specified program object
	GLCW_API std::tuple<int, GL_ENUM, std::string> getActiveUniform(unsigned int program, unsigned int index);

#if GL_DESKTOP || EC(3, 0)
	//glGetActiveUniformBlock — query information about an active uniform block
	GLCW_API void getActiveUniformBlockiv(unsigned int program, unsigned int uniformBlockIndex, GL_ENUM pname, int* params);
	//glGetActiveUniformBlock — query information about an active uniform block
	GLCW_API int getActiveUniformBlockiv(unsigned int program, unsigned int uniformBlockIndex, GL_ENUM pname);

	//glGetActiveUniformBlockName — retrieve the name of an active uniform block
	GLCW_API void getActiveUniformBlockName(unsigned int program, unsigned int uniformBlockIndex, int bufSize, int* length, char* uniformBlockName);
	//glGetActiveUniformBlockName — retrieve the name of an active uniform block
	GLCW_API std::string getActiveUniformBlockName(unsigned int program, unsigned int uniformBlockIndex);
#endif

#if GL_DESKTOP
	//glGetActiveUniformName — query the name of an active uniform
	GLCW_API void getActiveUniformName(unsigned int program, unsigned int uniformIndex, int bufSize, int* length, char* uniformName);
	//glGetActiveUniformName — query the name of an active uniform
	GLCW_API std::string getActiveUniformName(unsigned int program, unsigned int uniformIndex);
#endif

	//glGetActiveUniformsiv — Returns information about several active uniform variables for the specified program object
	GLCW_API void getActiveUniformsiv(unsigned int program, int uniformCount, const unsigned int* uniformIndices, GL_ENUM pname, int* params);

	//glGetAttachedShaders — Returns the handles of the shader objects attached to a program object
	GLCW_API void getAttachedShaders(unsigned int program, int maxCount, int* count, unsigned int* shaders);
	//glGetAttachedShaders — Returns the handles of the shader objects attached to a program object
	GLCW_API std::vector<unsigned int> getAttachedShaders(unsigned int program);

	//glGetAttribLocation — Returns the location of an attribute variable
	GLCW_API int getAttribLocation(unsigned int program, std::string_view name);

#if GL_DESKTOP
	//glGetFragDataIndex — query the bindings of color indices to user-defined varying out variables
	GLCW_API int getFragDataIndex(unsigned int program, std::string_view name);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glGetFragDataLocation — query the bindings of color numbers to user-defined varying out variables
	GLCW_API int getFragDataLocation(unsigned int program, std::string_view name);
#endif

	//glGetProgramiv — Returns a parameter from a program object
	GLCW_API void getProgramiv(unsigned int program, GL_ENUM pname, int* params);
	//glGetProgramiv — Returns a parameter from a program object
	GLCW_API int getProgramiv(unsigned int program, GL_ENUM pname);

#if VC(4, 1) || EC(3, 0)
	//glGetProgramBinary — return a binary representation of a program object's compiled and linked executable source
	GLCW_API void getProgramBinary(unsigned int program, int bufsize, int* length, unsigned int* binaryFormat, void* binary);
#endif

	//glGetProgramInfoLog — Returns the information log for a program object
	GLCW_API void getProgramInfoLog(unsigned int program, int maxLength, int* length, char* infoLog);
	//glGetProgramInfoLog — Returns the information log for a program object
	GLCW_API std::string getProgramInfoLog(unsigned int program);

#if VC(4, 3) || EC(3, 1)
	//glGetProgramResource — retrieve values for multiple properties of a single active resource within a program object
	GLCW_API void getProgramResourceiv(unsigned int program, GL_ENUM programInterface, unsigned int index, int propCount, GL_ENUM* props, int bufSize, int* length, int* params);
	//glGetProgramResource — retrieve values for multiple properties of a single active resource within a program object
	GLCW_API std::vector<int> getProgramResourceiv(unsigned int program, GL_ENUM programInterface, unsigned int index, const std::vector<GL_ENUM>& props);
#endif

#if VC(4, 3) || EC(3, 1)
	//glGetProgramResourceIndex — query the index of a named resource within a program
	GLCW_API unsigned int getProgramResourceIndex(unsigned int program, GL_ENUM programInterface, std::string_view name);

	//glGetProgramResourceLocation — query the location of a named resource within a program
	GLCW_API int getProgramResourceLocation(unsigned int program, GL_ENUM programInterface, std::string_view name);
#endif

#if VC(4, 3)
	//glGetProgramResourceLocationIndex — query the fragment color index of a named variable within a program
	GLCW_API int getProgramResourceLocationIndex(unsigned int program, /*GL_PROGRAM_OUTPUT, */std::string_view name);
#endif

#if VC(4, 3) || EC(3, 1)
	//glGetProgramResourceName — query the name of an indexed resource within a program
	GLCW_API void getProgramResourceName(unsigned int program, GL_ENUM programInterface, unsigned int index, int bufSize, int* length, char* name);
	//glGetProgramResourceName — query the name of an indexed resource within a program
	GLCW_API std::string getProgramResourceName(unsigned int program, GL_ENUM programInterface, unsigned int index);
#endif

#if VC(4, 0)
	//glGetProgramStage — retrieve properties of a program object corresponding to a specified shader stage
	GLCW_API void getProgramStageiv(unsigned int program, GL_ENUM shadertype, GL_ENUM pname, int* values);
	//glGetProgramStage — retrieve properties of a program object corresponding to a specified shader stage
	GLCW_API int getProgramStageiv(unsigned int program, GL_ENUM shadertype, GL_ENUM pname);
#endif

	//glGetShaderiv — Returns a parameter from a shader object
	GLCW_API void getShaderiv(unsigned int shader, GL_ENUM pname, int* params);
	//glGetShaderiv — Returns a parameter from a shader object
	GLCW_API int getShaderiv(unsigned int shader, GL_ENUM pname);

	//glGetShaderInfoLog — Returns the information log for a shader object
	GLCW_API void getShaderInfoLog(unsigned int shader, int maxLength, int* length, char* infoLog);
	//glGetShaderInfoLog — Returns the information log for a shader object
	GLCW_API std::string getShaderInfoLog(unsigned int shader);

	//glGetShaderPrecisionFormat — retrieve the range and precision for numeric formats supported by the shader compiler
	GLCW_API void getShaderPrecisionFormat(GL_ENUM shaderType, GL_ENUM precisionType, int* range, int* precision);
	//glGetShaderPrecisionFormat — retrieve the range and precision for numeric formats supported by the shader compiler
	GLCW_API std::pair<glm::ivec2, int> getShaderPrecisionFormat(GL_ENUM shaderType, GL_ENUM precisionType);

	//glGetShaderSource — Returns the source code string from a shader object
	GLCW_API void getShaderSource(unsigned int shader, int bufSize, int* length, char* source);
	//glGetShaderSource — Returns the source code string from a shader object
	GLCW_API std::string getShaderSource(unsigned int shader);

#if VC(4, 0)
	//glGetSubroutineIndex — retrieve the index of a subroutine uniform of a given shader stage within a program
	GLCW_API int getSubroutineIndex(unsigned int program, GL_ENUM shadertype, std::string_view name);

	//glGetSubroutineUniformLocation — retrieve the location of a subroutine uniform of a given shader stage within a program
	GLCW_API int getSubroutineUniformLocation(unsigned int program, GL_ENUM shadertype, std::string_view name);
#endif

	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getUniformfv(unsigned int program, int location, float* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API float getSingleUniformfv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::vec2 getDoubleUniformfv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::vec3 getTripleUniformfv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::vec4 getQuadUniformfv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getUniformiv(unsigned int program, int location, int* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API int getSingleUniformiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::ivec2 getDoubleUniformiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::ivec3 getTripleUniformiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::ivec4 getQuadUniformiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getUniformuiv(unsigned int program, int location, unsigned int* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API unsigned int getSingleUniformuiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::uvec2 getDoubleUniformuiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::uvec3 getTripleUniformuiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::uvec4 getQuadUniformuiv(unsigned int program, int location);
#if VC(4, 0)
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getUniformdv(unsigned int program, int location, double* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API double getSingleUniformdv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::dvec2 getDoubleUniformdv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::dvec3 getTripleUniformdv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API glm::dvec4 getQuadUniformdv(unsigned int program, int location);
#endif

#if VC(4, 5)
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getnUniformfv(unsigned int program, int location, int bufSize, float* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getnUniformiv(unsigned int program, int location, int bufSize, int* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getnUniformuiv(unsigned int program, int location, int bufSize, unsigned int* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getnUniformdv(unsigned int program, int location, int bufSize, double* params);
#endif

#if GL_DESKTOP || EC(3, 0)
	//glGetUniformBlockIndex — retrieve the index of a named uniform block
	GLCW_API unsigned int getUniformBlockIndex(unsigned int program, std::string_view uniformBlockName);

	//glGetUniformIndices — retrieve the index of a named uniform block
	GLCW_API void getUniformIndices(unsigned int program, const std::vector<std::string>& uniformNames, unsigned int* uniformIndices);
	//glGetUniformIndices — retrieve the index of a named uniform block
	GLCW_API std::vector<unsigned int> getUniformIndices(unsigned int program, const std::vector<std::string>& uniformNames);
#endif

	//glGetUniformLocation — Returns the location of a uniform variable
	GLCW_API int getUniformLocation(unsigned int program, std::string_view name);

#if VC(4, 0)
	//glGetUniformSubroutine — retrieve the value of a subroutine uniform of a given shader stage of the current program
	GLCW_API void getUniformSubroutineuiv(GL_ENUM shadertype, int location, unsigned int* values);
#endif

	//glIsProgram — Determines if a name corresponds to a program object
	GLCW_API bool isProgram(unsigned int program);

	//glIsShader — Determines if a name corresponds to a shader object
	GLCW_API bool isShader(unsigned int shader);

	//glLinkProgram — Links a program object
	GLCW_API void linkProgram(unsigned int program);

#if VC(4, 0)
	//glMinSampleShading — specifies minimum rate at which sample shading takes place
	GLCW_API void minSampleShading(float value);
#endif

#if VC(4, 1) || EC(3, 0)
	//glProgramBinary — load a program object with a program binary
	GLCW_API void programBinary(unsigned int program, unsigned int binaryFormat, const void* binary, int length);
#endif

#if VC(4, 1) || EC(3, 0)
	//glProgramParameter — specify a parameter for a program object
	GLCW_API void programParameteri(unsigned int program, GL_ENUM pname, int value);
#endif

#if VC(4, 1) || EC(3, 1)
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	template <typename T>
	void programUniform(int location, const T& v, int count = 1, bool transpose = false)
	{
		if constexpr (std::is_same_v<T, float>)
			programUniform1fv(location, count, v);
		if constexpr (std::is_same_v<T, glm::vec2>)
			programUniform2fv(location, count, v);
		if constexpr (std::is_same_v<T, glm::vec3>)
			programUniform3fv(location, count, v);
		if constexpr (std::is_same_v<T, glm::vec4>)
			programUniform4fv(location, count, v);

		if constexpr (std::is_same_v<T, int>)
			programUniform1iv(location, count, v);
		if constexpr (std::is_same_v<T, glm::ivec2>)
			programUniform2iv(location, count, v);
		if constexpr (std::is_same_v<T, glm::ivec3>)
			programUniform3iv(location, count, v);
		if constexpr (std::is_same_v<T, glm::ivec4>)
			programUniform4iv(location, count, v);

		if constexpr (std::is_same_v<T, unsigned int>)
			programUniform1uiv(location, count, v);
		if constexpr (std::is_same_v<T, glm::uvec2>)
			programUniform2uiv(location, count, v);
		if constexpr (std::is_same_v<T, glm::uvec3>)
			programUniform3uiv(location, count, v);
		if constexpr (std::is_same_v<T, glm::uvec4>)
			programUniform4uiv(location, count, v);

		if constexpr (std::is_same_v<T, glm::mat2>)
			programUniformMatrix2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat3>)
			programUniformMatrix3fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat4>)
			programUniformMatrix4fv(location, count, transpose, v);

		if constexpr (std::is_same_v<T, glm::mat2x3>)
			programUniformMatrix2x3fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat3x2>)
			programUniformMatrix3x2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat2x4>)
			programUniformMatrix2x4fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat4x2>)
			programUniformMatrix4x2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat3x4>)
			programUniformMatrix3x4fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat4x3>)
			programUniformMatrix4x3fv(location, count, transpose, v);
	}

	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1f(unsigned int program, int location, float v0);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2f(unsigned int program, int location, float v0, float v1);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2f(unsigned int program, int location, const glm::vec2& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3f(unsigned int program, int location, float v0, float v1, float v2);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3f(unsigned int program, int location, const glm::vec3& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4f(unsigned int program, int location, float v0, float v1, float v2, float v3);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4f(unsigned int program, int location, const glm::vec4& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1i(unsigned int program, int location, int v0);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2i(unsigned int program, int location, int v0, int v1);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2i(unsigned int program, int location, const glm::ivec2& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3i(unsigned int program, int location, int v0, int v1, int v2);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3i(unsigned int program, int location, const glm::ivec3& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4i(unsigned int program, int location, int v0, int v1, int v2, int v3);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4i(unsigned int program, int location, const glm::ivec4& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1ui(unsigned int program, int location, unsigned int v0);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2ui(unsigned int program, int location, unsigned int v0, unsigned int v1);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2ui(unsigned int program, int location, const glm::uvec2& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3ui(unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3ui(unsigned int program, int location, const glm::uvec3& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4ui(unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4ui(unsigned int program, int location, const glm::uvec4& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2fv(unsigned int program, int location, int count, const glm::vec2& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3fv(unsigned int program, int location, int count, const glm::vec3& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4fv(unsigned int program, int location, int count, const glm::vec4& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2iv(unsigned int program, int location, int count, const glm::ivec2& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3iv(unsigned int program, int location, int count, const glm::ivec3& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4iv(unsigned int program, int location, int count, const glm::ivec4& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2uiv(unsigned int program, int location, int count, const glm::uvec2& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3uiv(unsigned int program, int location, int count, const glm::uvec3& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4uiv(unsigned int program, int location, int count, const glm::uvec4& v);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2fv(unsigned int program, int location, int count, bool transpose, const glm::mat2& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3fv(unsigned int program, int location, int count, bool transpose, const glm::mat3& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4fv(unsigned int program, int location, int count, bool transpose, const glm::mat4& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2x3fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2x3fv(unsigned int program, int location, int count, bool transpose, const glm::mat2x3& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3x2fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3x2fv(unsigned int program, int location, int count, bool transpose, const glm::mat3x2& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2x4fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2x4fv(unsigned int program, int location, int count, bool transpose, const glm::mat2x4& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4x2fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4x2fv(unsigned int program, int location, int count, bool transpose, const glm::mat4x2& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3x4fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3x4fv(unsigned int program, int location, int count, bool transpose, const glm::mat3x4& value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4x3fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4x3fv(unsigned int program, int location, int count, bool transpose, const glm::mat4x3& value);
#endif

#if (!GL_DESKTOP) || VC(4, 1)
	//glReleaseShaderCompiler — release resources consumed by the implementation's shader compiler
	GLCW_API void releaseShaderCompiler();

	//glShaderBinary — load pre-compiled shader binaries
	GLCW_API void shaderBinary(int count, const unsigned int* shaders, unsigned int binaryFormat, const void* binary, int length);
	//glShaderBinary — load pre-compiled shader binaries
	GLCW_API void shaderBinary(const std::vector<unsigned int>& shaders, unsigned int binaryFormat, const void* binary, int length);
#endif

	//glShaderSource — Replaces the source code in a shader object
	GLCW_API void shaderSource(unsigned int shader, int count, const char** string, const int* length);
	//glShaderSource — Replaces the source code in a shader object
	GLCW_API void shaderSource(unsigned int shader, const std::vector<std::string>& strings);

#if VC(4, 3)
	//glShaderStorageBlockBinding — change an active shader storage block binding
	GLCW_API void shaderStorageBlockBinding(unsigned int program, unsigned int storageBlockIndex, unsigned int storageBlockBinding);
#endif

	//glUniform — Specify the value of a uniform variable for the current program object
	template <typename T>
	void uniform(int location, const T& v, int count = 0, bool transpose = false)
	{
		if constexpr (std::is_same_v<T, float>)
			uniform1fv(location, count, v);
		if constexpr (std::is_same_v<T, glm::vec2>)
			uniform2fv(location, count, v);
		if constexpr (std::is_same_v<T, glm::vec3>)
			uniform3fv(location, count, v);
		if constexpr (std::is_same_v<T, glm::vec4>)
			uniform4fv(location, count, v);

		if constexpr (std::is_same_v<T, int>)
			uniform1iv(location, count, v);
		if constexpr (std::is_same_v<T, glm::ivec2>)
			uniform2iv(location, count, v);
		if constexpr (std::is_same_v<T, glm::ivec3>)
			uniform3iv(location, count, v);
		if constexpr (std::is_same_v<T, glm::ivec4>)
			uniform4iv(location, count, v);

#if GL_DESKTOP || EC(3, 0)
		if constexpr (std::is_same_v<T, unsigned int>)
			uniform1uiv(location, count, v);
		if constexpr (std::is_same_v<T, glm::uvec2>)
			uniform2uiv(location, count, v);
		if constexpr (std::is_same_v<T, glm::uvec3>)
			uniform3uiv(location, count, v);
		if constexpr (std::is_same_v<T, glm::uvec4>)
			uniform4uiv(location, count, v);
#endif

		if constexpr (std::is_same_v<T, glm::mat2>)
			uniformMatrix2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat3>)
			uniformMatrix3fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat4>)
			uniformMatrix4fv(location, count, transpose, v);

#if GL_DESKTOP || EC(3, 0)
		if constexpr (std::is_same_v<T, glm::mat2x3>)
			uniformMatrix2x3fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat3x2>)
			uniformMatrix3x2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat2x4>)
			uniformMatrix2x4fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat4x2>)
			uniformMatrix4x2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat3x4>)
			uniformMatrix3x4fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, glm::mat4x3>)
			uniformMatrix4x3fv(location, count, transpose, v);
#endif
	}

	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1f(int location, float v0);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2f(int location, float v0, float v1);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2f(int location, const glm::vec2& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3f(int location, float v0, float v1, float v2);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3f(int location, const glm::vec3& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4f(int location, float v0, float v1, float v2, float v3);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4f(int location, const glm::vec4& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1i(int location, int v0);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2i(int location, int v0, int v1);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2i(int location, const glm::ivec2& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3i(int location, int v0, int v1, int v2);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3i(int location, const glm::ivec3& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4i(int location, int v0, int v1, int v2, int v3);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4i(int location, const glm::ivec4& v);

#if GL_DESKTOP || EC(3, 0)
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1ui(int location, unsigned int v0);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2ui(int location, unsigned int v0, unsigned int v1);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2ui(int location, const glm::uvec2& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3ui(int location, unsigned int v0, unsigned int v1, unsigned int v2);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3ui(int location, const glm::uvec3& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4ui(int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4ui(int location, const glm::uvec4& v);
#endif
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2fv(int location, int count, const glm::vec2& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3fv(int location, int count, const glm::vec3& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4fv(int location, int count, const glm::vec4& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2iv(int location, int count, const glm::ivec2& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3iv(int location, int count, const glm::ivec3& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4iv(int location, int count, const glm::ivec4& v);
#if GL_DESKTOP || EC(3, 0)
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2uiv(int location, int count, const glm::uvec2& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3uiv(int location, int count, const glm::uvec3& v);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4uiv(int location, int count, const glm::uvec4& v);
#endif
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2fv(int location, int count, bool transpose, const glm::mat2& value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3fv(int location, int count, bool transpose, const glm::mat3& value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4fv(int location, int count, bool transpose, const glm::mat4& value);
#if GL_DESKTOP || EC(3, 0)
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2x3fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2x3fv(int location, int count, bool transpose, const glm::mat2x3& value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3x2fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3x2fv(int location, int count, bool transpose, const glm::mat3x2& value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2x4fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2x4fv(int location, int count, bool transpose, const glm::mat2x4& value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4x2fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4x2fv(int location, int count, bool transpose, const glm::mat4x2& value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3x4fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3x4fv(int location, int count, bool transpose, const glm::mat3x4& value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4x3fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4x3fv(int location, int count, bool transpose, const glm::mat4x3& value);

	//glUniformBlockBinding — assign a binding point to an active uniform block
	GLCW_API void uniformBlockBinding(unsigned int program, unsigned int uniformBlockIndex, unsigned int uniformBlockBinding);
#endif

#if VC(4, 0)
	//glUniformSubroutines — load active subroutine uniforms
	GLCW_API void uniformSubroutinesuiv(GL_ENUM shadertype, int count, const unsigned int* indices);
	//glUniformSubroutines — load active subroutine uniforms
	GLCW_API void uniformSubroutinesuiv(GL_ENUM shadertype, const std::vector<unsigned int>& indices);
#endif

	//glUseProgram — Installs a program object as part of current rendering state
	GLCW_API void useProgram(unsigned int program);

#if VC(4, 1) || EC(3, 1)
	//glUseProgramStages — bind stages of a program object to a program pipeline
	template <unsigned int final_bits>
	void useProgramStages(unsigned int pipeline, BitfieldWrapper<cti::type_info(__FILE__).hash(), final_bits> stages, unsigned int program)
	{
		detail::useProgramStages(pipeline, stages.value, program);
	}
#endif

	//glValidateProgram — Validates a program object
	GLCW_API void validateProgram(unsigned int program);
}