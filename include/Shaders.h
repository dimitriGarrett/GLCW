#pragma once

#include "API.h"
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
	inline std::pair<ivec2, int> getShaderPrecisionFormat(GL_ENUM shaderType, GL_ENUM precisionType)
	{
		std::pair<ivec2, int> temp;
		getShaderPrecisionFormat(shaderType, precisionType, &temp.first.x, &temp.second);
		return temp;
	}

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
	inline fvec2 getDoubleUniformfv(unsigned int program, int location)
	{
		fvec2 temp;
		getUniformfv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline fvec3 getTripleUniformfv(unsigned int program, int location)
	{
		fvec3 temp;
		getUniformfv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline fvec4 getQuadUniformfv(unsigned int program, int location)
	{
		fvec4 temp;
		getUniformfv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getUniformiv(unsigned int program, int location, int* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API int getSingleUniformiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	inline ivec2 getDoubleUniformiv(unsigned int program, int location)
	{
		ivec2 temp;
		getUniformiv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline ivec3 getTripleUniformiv(unsigned int program, int location)
	{
		ivec3 temp;
		getUniformiv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline ivec4 getQuadUniformiv(unsigned int program, int location)
	{
		ivec4 temp;
		getUniformiv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getUniformuiv(unsigned int program, int location, unsigned int* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API unsigned int getSingleUniformuiv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	inline uvec2 getDoubleUniformuiv(unsigned int program, int location)
	{
		uvec2 temp;
		getUniformuiv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline uvec3 getTripleUniformuiv(unsigned int program, int location)
	{
		uvec3 temp;
		getUniformuiv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline uvec4 getQuadUniformuiv(unsigned int program, int location)
	{
		uvec4 temp;
		getUniformuiv(program, location, &temp.x);
		return temp;
	}
#if VC(4, 0)
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API void getUniformdv(unsigned int program, int location, double* params);
	//glGetUniform — Returns the value of a uniform variable
	GLCW_API double getSingleUniformdv(unsigned int program, int location);
	//glGetUniform — Returns the value of a uniform variable
	inline dvec2 getDoubleUniformdv(unsigned int program, int location)
	{
		dvec2 temp;
		getUniformdv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline dvec3 getTripleUniformdv(unsigned int program, int location)
	{
		dvec3 temp;
		getUniformdv(program, location, &temp.x);
		return temp;
	}
	//glGetUniform — Returns the value of a uniform variable
	inline dvec4 getQuadUniformdv(unsigned int program, int location)
	{
		dvec4 temp;
		getUniformdv(program, location, &temp.x);
		return temp;
	}
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
	GLCW_API void programUniform1f(unsigned int program, int location, float v0);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2f(unsigned int program, int location, float v0, float v1);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform2f(unsigned int program, int location, const fvec2& v)
	{
		programUniform2f(program, location, v.x, v.y);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3f(unsigned int program, int location, float v0, float v1, float v2);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform3f(unsigned int program, int location, const fvec3& v)
	{
		programUniform3f(program, location, v.x, v.y, v.z);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4f(unsigned int program, int location, float v0, float v1, float v2, float v3);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform4f(unsigned int program, int location, const fvec4& v)
	{
		programUniform4f(program, location, v.x, v.y, v.z, v.w);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1i(unsigned int program, int location, int v0);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2i(unsigned int program, int location, int v0, int v1);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform2i(unsigned int program, int location, const ivec2& v)
	{
		programUniform2i(program, location, v.x, v.y);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3i(unsigned int program, int location, int v0, int v1, int v2);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform3i(unsigned int program, int location, const ivec3& v)
	{
		programUniform3i(program, location, v.x, v.y, v.z);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4i(unsigned int program, int location, int v0, int v1, int v2, int v3);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform4i(unsigned int program, int location, const ivec4& v)
	{
		programUniform4i(program, location, v.x, v.y, v.z, v.w);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1ui(unsigned int program, int location, unsigned int v0);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2ui(unsigned int program, int location, unsigned int v0, unsigned int v1);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform2ui(unsigned int program, int location, const uvec2& v)
	{
		programUniform2ui(program, location, v.x, v.y);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3ui(unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform3ui(unsigned int program, int location, const uvec3& v)
	{
		programUniform3ui(program, location, v.x, v.y, v.z);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4ui(unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform4ui(unsigned int program, int location, const uvec4& v)
	{
		programUniform4ui(program, location, v.x, v.y, v.z, v.w);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform2fv(unsigned int program, int location, int count, const fvec2& v)
	{
		programUniform2fv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform3fv(unsigned int program, int location, int count, const fvec3& v)
	{
		programUniform3fv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4fv(unsigned int program, int location, int count, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform4fv(unsigned int program, int location, int count, const fvec4& v)
	{
		programUniform4fv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform2iv(unsigned int program, int location, int count, const ivec2& v)
	{
		programUniform2iv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform3iv(unsigned int program, int location, int count, const ivec3& v)
	{
		programUniform3iv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4iv(unsigned int program, int location, int count, const int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform4iv(unsigned int program, int location, int count, const ivec4& v)
	{
		programUniform4iv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform1uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform2uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform2uiv(unsigned int program, int location, int count, const uvec2& v)
	{
		programUniform2uiv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform3uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform3uiv(unsigned int program, int location, int count, const uvec3& v)
	{
		programUniform3uiv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniform4uiv(unsigned int program, int location, int count, const unsigned int* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniform4uiv(unsigned int program, int location, int count, const uvec4& v)
	{
		programUniform4uiv(program, location, count, &v.x);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix2fv(unsigned int program, int location, int count, bool transpose, const mat2& value)
	{
		programUniformMatrix2fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix3fv(unsigned int program, int location, int count, bool transpose, const mat3& value)
	{
		programUniformMatrix3fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix4fv(unsigned int program, int location, int count, bool transpose, const mat4& value)
	{
		programUniformMatrix4fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2x3fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix2x3fv(unsigned int program, int location, int count, bool transpose, const mat2x3& value)
	{
		programUniformMatrix2x3fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3x2fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix3x2fv(unsigned int program, int location, int count, bool transpose, const mat3x2& value)
	{
		programUniformMatrix3x2fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix2x4fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix2x4fv(unsigned int program, int location, int count, bool transpose, const mat2x4& value)
	{
		programUniformMatrix2x4fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4x2fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix4x2fv(unsigned int program, int location, int count, bool transpose, const mat4x2& value)
	{
		programUniformMatrix4x2fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix3x4fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix3x4fv(unsigned int program, int location, int count, bool transpose, const mat3x4& value)
	{
		programUniformMatrix3x4fv(program, location, count, transpose, &value[0][0]);
	}
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	GLCW_API void programUniformMatrix4x3fv(unsigned int program, int location, int count, bool transpose, const float* value);
	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	inline void programUniformMatrix4x3fv(unsigned int program, int location, int count, bool transpose, const mat4x3& value)
	{
		programUniformMatrix4x3fv(program, location, count, transpose, &value[0][0]);
	}

	//glProgramUniform — Specify the value of a uniform variable for a specified program object
	template <typename T>
	void programUniform(unsigned int program, int location, const T& v, int count = 1, bool transpose = false)
	{
		if constexpr (std::is_same_v<T, float>)
			programUniform1f(program, location, v);
		if constexpr (std::is_same_v<T, fvec2>)
			programUniform2f(program, location, v);
		if constexpr (std::is_same_v<T, fvec3>)
			programUniform3f(program, location, v);
		if constexpr (std::is_same_v<T, fvec4>)
			programUniform4f(program, location, v);

		if constexpr (std::is_same_v<T, int>)
			programUniform1i(program, location, v);
		if constexpr (std::is_same_v<T, ivec2>)
			programUniform2i(program, location, v);
		if constexpr (std::is_same_v<T, ivec3>)
			programUniform3i(program, location, v);
		if constexpr (std::is_same_v<T, ivec4>)
			programUniform4i(program, location, v);

		if constexpr (std::is_same_v<T, unsigned int>)
			programUniform1ui(program, location, v);
		if constexpr (std::is_same_v<T, uvec2>)
			programUniform2ui(program, location, v);
		if constexpr (std::is_same_v<T, uvec3>)
			programUniform3ui(program, location, v);
		if constexpr (std::is_same_v<T, uvec4>)
			programUniform4ui(program, location, v);

		if constexpr (std::is_same_v<T, mat2>)
			programUniformMatrix2fv(program, location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat3>)
			programUniformMatrix3fv(program, location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat4>)
			programUniformMatrix4fv(program, location, count, transpose, v);

		if constexpr (std::is_same_v<T, mat2x3>)
			programUniformMatrix2x3fv(program, location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat3x2>)
			programUniformMatrix3x2fv(program, location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat2x4>)
			programUniformMatrix2x4fv(program, location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat4x2>)
			programUniformMatrix4x2fv(program, location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat3x4>)
			programUniformMatrix3x4fv(program, location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat4x3>)
			programUniformMatrix4x3fv(program, location, count, transpose, v);
	}
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
	GLCW_API void uniform1f(int location, float v0);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2f(int location, float v0, float v1);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform2f(int location, const fvec2& v)
	{
		uniform2f(location, v.x, v.y);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3f(int location, float v0, float v1, float v2);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform3f(int location, const fvec3& v)
	{
		uniform3f(location, v.x, v.y, v.z);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4f(int location, float v0, float v1, float v2, float v3);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform4f(int location, const fvec4& v)
	{
		uniform4f(location, v.x, v.y, v.z, v.w);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1i(int location, int v0);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2i(int location, int v0, int v1);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform2i(int location, const ivec2& v)
	{
		uniform2i(location, v.x, v.y);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3i(int location, int v0, int v1, int v2);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform3i(int location, const ivec3& v)
	{
		uniform3i(location, v.x, v.y, v.z);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4i(int location, int v0, int v1, int v2, int v3);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform4i(int location, const ivec4& v)
	{
		uniform4i(location, v.x, v.y, v.z, v.w);
	}

#if GL_DESKTOP || EC(3, 0)
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1ui(int location, unsigned int v0);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2ui(int location, unsigned int v0, unsigned int v1);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform2ui(int location, const uvec2& v)
	{
		uniform2ui(location, v.x, v.y);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3ui(int location, unsigned int v0, unsigned int v1, unsigned int v2);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform3ui(int location, const uvec3& v)
	{
		uniform3ui(location, v.x, v.y, v.z);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4ui(int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform4ui(int location, const uvec4& v)
	{
		uniform4ui(location, v.x, v.y, v.z, v.w);
	}
#endif
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform2fv(int location, int count, const fvec2& v)
	{
		uniform2fv(location, count, &v.x);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform3fv(int location, int count, const fvec3& v)
	{
		uniform3fv(location, count, &v.x);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4fv(int location, int count, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform4fv(int location, int count, const fvec4& v)
	{
		uniform4fv(location, count, &v.x);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform2iv(int location, int count, const ivec2& v)
	{
		uniform2iv(location, count, &v.x);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform3iv(int location, int count, const ivec3& v)
	{
		uniform3iv(location, count, &v.x);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4iv(int location, int count, const int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform4iv(int location, int count, const ivec4& v)
	{
		uniform4iv(location, count, &v.x);
	}
#if GL_DESKTOP || EC(3, 0)
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform1uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform2uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform2uiv(int location, int count, const uvec2& v)
	{
		uniform2uiv(location, count, &v.x);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform3uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform3uiv(int location, int count, const uvec3& v)
	{
		uniform3uiv(location, count, &v.x);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniform4uiv(int location, int count, const unsigned int* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniform4uiv(int location, int count, const uvec4& v)
	{
		uniform4uiv(location, count, &v.x);
	}
#endif
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix2fv(int location, int count, bool transpose, const mat2& value)
	{
		uniformMatrix2fv(location, count, transpose, &value[0][0]);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix3fv(int location, int count, bool transpose, const mat3& value)
	{
		uniformMatrix3fv(location, count, transpose, &value[0][0]);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix4fv(int location, int count, bool transpose, const mat4& value)
	{
		uniformMatrix4fv(location, count, transpose, &value[0][0]);
	}
#if GL_DESKTOP || EC(3, 0)
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2x3fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix2x3fv(int location, int count, bool transpose, const mat2x3& value)
	{
		uniformMatrix2x3fv(location, count, transpose, &value[0][0]);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3x2fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix3x2fv(int location, int count, bool transpose, const mat3x2& value)
	{
		uniformMatrix3x2fv(location, count, transpose, &value[0][0]);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix2x4fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix2x4fv(int location, int count, bool transpose, const mat2x4& value)
	{
		uniformMatrix2x4fv(location, count, transpose, &value[0][0]);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4x2fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix4x2fv(int location, int count, bool transpose, const mat4x2& value)
	{
		uniformMatrix4x2fv(location, count, transpose, &value[0][0]);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix3x4fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix3x4fv(int location, int count, bool transpose, const mat3x4& value)
	{
		uniformMatrix3x4fv(location, count, transpose, &value[0][0]);
	}
	//glUniform — Specify the value of a uniform variable for the current program object
	GLCW_API void uniformMatrix4x3fv(int location, int count, bool transpose, const float* value);
	//glUniform — Specify the value of a uniform variable for the current program object
	inline void uniformMatrix4x3fv(int location, int count, bool transpose, const mat4x3& value)
	{
		uniformMatrix4x3fv(location, count, transpose, &value[0][0]);
	}

	//glUniform — Specify the value of a uniform variable for the current program object
	template <typename T>
	void uniform(int location, const T& v, int count = 1, bool transpose = false)
	{
		if constexpr (std::is_same_v<T, float>)
			uniform1f(location, v);
		if constexpr (std::is_same_v<T, uvec2>)
			uniform2f(location, v);
		if constexpr (std::is_same_v<T, uvec3>)
			uniform3f(location, v);
		if constexpr (std::is_same_v<T, uvec4>)
			uniform4f(location, v);

		if constexpr (std::is_same_v<T, int>)
			uniform1i(location, v);
		if constexpr (std::is_same_v<T, ivec2>)
			uniform2i(location, v);
		if constexpr (std::is_same_v<T, ivec3>)
			uniform3i(location, v);
		if constexpr (std::is_same_v<T, ivec4>)
			uniform4i(location, v);

#if GL_DESKTOP || EC(3, 0)
		if constexpr (std::is_same_v<T, unsigned int>)
			uniform1ui(location, v);
		if constexpr (std::is_same_v<T, uvec2>)
			uniform2ui(location, v);
		if constexpr (std::is_same_v<T, uvec3>)
			uniform3ui(location, v);
		if constexpr (std::is_same_v<T, uvec4>)
			uniform4ui(location, v);
#endif

		if constexpr (std::is_same_v<T, mat2>)
			uniformMatrix2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat3>)
			uniformMatrix3fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat4>)
			uniformMatrix4fv(location, count, transpose, v);

#if GL_DESKTOP || EC(3, 0)
		if constexpr (std::is_same_v<T, mat2x3>)
			uniformMatrix2x3fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat3x2>)
			uniformMatrix3x2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat2x4>)
			uniformMatrix2x4fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat4x2>)
			uniformMatrix4x2fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat3x4>)
			uniformMatrix3x4fv(location, count, transpose, v);
		if constexpr (std::is_same_v<T, mat4x3>)
			uniformMatrix4x3fv(location, count, transpose, v);
#endif
	}

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