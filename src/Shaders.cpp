#include "Shaders.h"
#include "GL.h"

inline void GL::attachShader(unsigned int program, unsigned int shader)
{
	glAttachShader(program, shader);
}

inline void GL::bindAttribLocation(unsigned int program, unsigned index, std::string_view name)
{
	glBindAttribLocation(program, index, name.data());
}

#if GL_DESKTOP
inline void GL::bindFragDataLocation(unsigned int program, unsigned int colorNumber, std::string_view name)
{
	glBindFragDataLocation(program, colorNumber, name.data());
}

inline void GL::bindFragDataLocationIndexed(unsigned int program, unsigned int colorNumber, unsigned int index, std::string_view name)
{
	glBindFragDataLocationIndexed(program, colorNumber, index, name.data());
}
#endif

inline void GL::compileShader(unsigned int shader)
{
	glCompileShader(shader);
}

inline unsigned int GL::createProgram()
{
	return glCreateProgram();
}

inline unsigned int GL::createShader(GL_ENUM shaderType)
{
	return glCreateShader(static_cast<unsigned int>(shaderType));
}

#if VC(4, 1) || EC(3, 1)
inline unsigned int GL::createShaderProgramv(GL_ENUM type, int count, const char** strings)
{
	return glCreateShaderProgramv(static_cast<unsigned int>(type), count, strings);
}

inline unsigned int GL::createShaderProgramv(GL_ENUM type, const std::vector<std::string>& strings)
{
	std::vector<const char*> temp = std::vector<const char*>(strings.size(), "");

	for (const auto& s : strings)
	{
		temp[std::distance(&strings.front(), &s)] = s.c_str();
	}

	return createShaderProgramv(type, static_cast<int>(strings.size()), &temp.front());
}
#endif

inline void GL::deleteProgram(unsigned int program)
{
	glDeleteProgram(program);
}

inline void GL::deleteShader(unsigned int shader)
{
	glDeleteShader(shader);
}

inline void GL::detachShader(unsigned int program, unsigned int shader)
{
	glDetachShader(program, shader);
}

#if VC(4, 2)
inline void GL::getActiveAtomicCounterBufferiv(unsigned int program, unsigned int bufferIndex, GL_ENUM pname, int* params)
{
	glGetActiveAtomicCounterBufferiv(program, bufferIndex, static_cast<unsigned int>(pname), params);
}

inline int GL::getActiveAtomicCounterBufferiv(unsigned int program, unsigned int bufferIndex, GL_ENUM pname)
{
	int temp;
	getActiveAtomicCounterBufferiv(program, bufferIndex, pname, &temp);
	return temp;
}
#endif

inline void GL::getActiveAttrib(unsigned int program, unsigned int index, int bufSize, int* length, int* size, GL_ENUM* type, char* name)
{
	glGetActiveAttrib(program, index, bufSize, length, size, reinterpret_cast<unsigned int*>(type), name);
}

inline std::tuple<int, GL::GL_ENUM, std::string> GL::getActiveAttrib(unsigned int program, unsigned int index)
{
	std::tuple<int, GL_ENUM, std::string> temp = std::make_tuple(0, FLOAT, std::string(getProgramiv(program, ACTIVE_ATTRIBUTE_MAX_LENGTH), ' '));
	int length;
	getActiveAttrib(program, index, static_cast<int>(std::get<2>(temp).size()), &length, &std::get<0>(temp), &std::get<1>(temp), &std::get<2>(temp).front());
	std::get<2>(temp) = std::get<2>(temp).substr(0, length);
	return temp;
}

#if VC(4, 0)
inline void GL::getActiveSubroutineName(unsigned int program, GL_ENUM shadertype, unsigned int index, int bufsize, int* length, char* name)
{
	glGetActiveSubroutineName(program, static_cast<unsigned int>(shadertype), index, bufsize, length, name);
}

inline std::string GL::getActiveSubroutineName(unsigned int program, GL_ENUM shadertype, unsigned int index)
{
	std::string temp = std::string(1024, ' ');
	int length;
	getActiveSubroutineName(program, shadertype, index, 1024, &length, &temp.front());
	return temp.substr(0, length);
}

inline void GL::getActiveSubroutineUniformiv(unsigned int program, GL_ENUM shadertype, unsigned int index, GL_ENUM pname, int* values)
{
	glGetActiveSubroutineUniformiv(program, static_cast <unsigned int>(shadertype), index, static_cast<unsigned int>(pname), values);
}

inline int GL::getActiveSubroutineUniformiv(unsigned int program, GL_ENUM shadertype, unsigned int index, GL_ENUM pname)
{
	int temp;
	getActiveSubroutineUniformiv(program, shadertype, index, pname, &temp);
	return temp;
}

inline void GL::getActiveSubroutineUniformName(unsigned int program, GL_ENUM shadertype, unsigned int index, int bufsize, int* length, char* name)
{
	glGetActiveSubroutineUniformName(program, static_cast<unsigned int>(shadertype), index, bufsize, length, name);
}

inline std::string GL::getActiveSubroutineUniformName(unsigned int program, GL_ENUM shadertype, unsigned int index)
{
	std::string temp = std::string(1024, ' ');
	
	int length;
	getActiveSubroutineUniformName(program, shadertype, index, 1024, &length, &temp.front());
	return temp.substr(0, length);
}
#endif

inline void GL::getActiveUniform(unsigned int program, unsigned int index, int bufSize, int* length, int* size, GL_ENUM * type, char* name)
{
	glGetActiveUniform(program, index, bufSize, length, size, reinterpret_cast<unsigned int*>(type), name);
}

inline std::tuple<int, GL::GL_ENUM, std::string> GL::getActiveUniform(unsigned int program, unsigned int index)
{
	std::tuple<int, GL_ENUM, std::string> temp = std::make_tuple(0, FLOAT, std::string(getProgramiv(program, ACTIVE_UNIFORM_MAX_LENGTH), ' '));
	int length;
	getActiveUniform(program, index, static_cast<int>(std::get<2>(temp).size()), &length, &std::get<0>(temp), &std::get<1>(temp), &std::get<2>(temp).front());
	std::get<2>(temp) = std::get<2>(temp).substr(0, length);
	return temp;
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::getActiveUniformBlockiv(unsigned int program, unsigned int uniformBlockIndex, GL_ENUM pname, int* params)
{
	glGetActiveUniformBlockiv(program, uniformBlockIndex, static_cast<unsigned int>(pname), params);
}

inline int GL::getActiveUniformBlockiv(unsigned int program, unsigned int uniformBlockIndex, GL_ENUM pname)
{
	int temp;
	getActiveUniformBlockiv(program, uniformBlockIndex, pname, &temp);
	return temp;
}

inline void GL::getActiveUniformBlockName(unsigned int program, unsigned int uniformBlockIndex, int bufSize, int* length, char* uniformBlockName)
{
	glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

inline std::string GL::getActiveUniformBlockName(unsigned int program, unsigned int uniformBlockIndex)
{
	std::string temp = std::string(1024, ' ');
	int length;
	
	getActiveUniformBlockName(program, uniformBlockIndex, 1024, &length, &temp.front());

	return temp.substr(0, length);
}
#endif

#if GL_DESKTOP
inline void GL::getActiveUniformName(unsigned int program, unsigned int uniformIndex, int bufSize, int* length, char* uniformName)
{
	glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
}

inline std::string GL::getActiveUniformName(unsigned int program, unsigned int uniformIndex)
{
	std::string temp = std::string(getProgramiv(program, ACTIVE_UNIFORM_MAX_LENGTH), ' ');
	int length;

	glGetActiveUniformName(program, uniformIndex, static_cast<int>(temp.size()), &length, &temp.front());

	return temp.substr(0, length);
}
#endif

inline void GL::getActiveUniformsiv(unsigned int program, int uniformCount, const unsigned int* uniformIndices, GL_ENUM pname, int* params)
{
	glGetActiveUniformsiv(program, uniformCount, uniformIndices, static_cast<unsigned int>(pname), params);
}

inline void GL::getAttachedShaders(unsigned int program, int maxCount, int* count, unsigned int* shaders)
{
	glGetAttachedShaders(program, maxCount, count, shaders);
}

inline std::vector<unsigned int> GL::getAttachedShaders(unsigned int program)
{
	std::vector<unsigned int> temp = std::vector<unsigned int>(getProgramiv(program, ATTACHED_SHADERS), 0);

	getAttachedShaders(program, static_cast<int>(temp.size()), nullptr, &temp.front());

	return temp;
}

inline int GL::getAttribLocation(unsigned int program, std::string_view name)
{
	return glGetAttribLocation(program, name.data());
}

#if GL_DESKTOP
inline int GL::getFragDataIndex(unsigned int program, std::string_view name)
{
	return glGetFragDataIndex(program, name.data());
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline int GL::getFragDataLocation(unsigned int program, std::string_view name)
{
	return glGetFragDataLocation(program, name.data());
}
#endif

inline void GL::getProgramiv(unsigned int program, GL_ENUM pname, int* params)
{
	glGetProgramiv(program, static_cast<unsigned int>(pname), params);
}

inline int GL::getProgramiv(unsigned int program, GL_ENUM pname)
{
	int temp;
	getProgramiv(program, pname, &temp);
	return temp;
}

#if VC(4, 1) || EC(3, 0)
inline void GL::getProgramBinary(unsigned int program, int bufsize, int* length, unsigned int* binaryFormat, void* binary)
{
	glGetProgramBinary(program, bufsize, length, binaryFormat, binary);
}
#endif

inline void GL::getProgramInfoLog(unsigned int program, int maxLength, int* length, char* infoLog)
{
	glGetProgramInfoLog(program, maxLength, length, infoLog);
}

inline std::string GL::getProgramInfoLog(unsigned int program)
{
	std::string temp = std::string(getProgramiv(program, GL_ENUM ::INFO_LOG_LENGTH), ' ');
	int length;

	getProgramInfoLog(program, static_cast<int>(temp.size()), &length, &temp.front());

	return temp.substr(0, length);
}

#if VC(4, 3) || EC(3, 1)
inline void GL::getProgramResourceiv(unsigned int program, GL_ENUM programInterface, unsigned int index, int propCount, GL_ENUM * props, int bufSize, int* length, int* params)
{
	glGetProgramResourceiv(program, static_cast<unsigned int>(programInterface), index, propCount, reinterpret_cast<unsigned int*>(props), bufSize, length, params);
}

inline std::vector<int> GL::getProgramResourceiv(unsigned int program, GL_ENUM programInterface, unsigned int index, const std::vector<GL_ENUM >& props)
{
	std::vector<int> temp(props.size(), 0);

	getProgramResourceiv(program, programInterface, index, static_cast<int>(props.size()), const_cast<GL_ENUM*>(&props.front()), static_cast<int>(props.size()), nullptr, &temp.front());

	return temp;
}
#endif

#if VC(4, 3) || EC(3, 1)
inline unsigned int GL::getProgramResourceIndex(unsigned int program, GL_ENUM programInterface, std::string_view name)
{
	return glGetProgramResourceIndex(program, static_cast<unsigned int>(programInterface), name.data());
}

inline int GL::getProgramResourceLocation(unsigned int program, GL_ENUM programInterface, std::string_view name)
{
	return glGetProgramResourceLocation(program, static_cast<unsigned int>(programInterface), name.data());
}
#endif

#if VC(4, 3)
inline int GL::getProgramResourceLocationIndex(unsigned int program, std::string_view name)
{
	return glGetProgramResourceLocationIndex(program, GL_PROGRAM_OUTPUT, name.data());
}
#endif

#if VC(4, 3) || EC(3, 1)
inline void GL::getProgramResourceName(unsigned int program, GL_ENUM programInterface, unsigned int index, int bufSize, int* length, char* name)
{
	return glGetProgramResourceName(program, static_cast<unsigned int>(programInterface), index, bufSize, length, name);
}

inline std::string GL::getProgramResourceName(unsigned int program, GL_ENUM programInterface, unsigned int index)
{
	std::string temp = std::string(1024, ' ');
	int length;

	getProgramResourceName(program, programInterface, index, 1024, &length, &temp.front());

	return temp.substr(0, length);
}
#endif

#if VC(4, 0)
inline void GL::getProgramStageiv(unsigned int program, GL_ENUM shadertype, GL_ENUM pname, int* values)
{
	glGetProgramStageiv(program, static_cast<unsigned int>(shadertype), static_cast<unsigned int>(pname), values);
}

inline int GL::getProgramStageiv(unsigned int program, GL_ENUM shadertype, GL_ENUM pname)
{
	int temp;
	getProgramStageiv(program, shadertype, pname, &temp);
	return temp;
}
#endif

inline void GL::getShaderiv(unsigned int shader, GL_ENUM pname, int* params)
{
	glGetShaderiv(shader, static_cast<unsigned int>(pname), params);
}

inline int GL::getShaderiv(unsigned int shader, GL_ENUM pname)
{
	int temp;
	getShaderiv(shader, pname, &temp);
	return temp;
}

inline void GL::getShaderInfoLog(unsigned int shader, int maxLength, int* length, char* infoLog)
{
	return glGetShaderInfoLog(shader, maxLength, length, infoLog);
}

inline std::string GL::getShaderInfoLog(unsigned int shader)
{
	std::string temp = std::string(getShaderiv(shader, GL_ENUM ::INFO_LOG_LENGTH), ' ');
	int length;

	getShaderInfoLog(shader, static_cast<int>(temp.size()), &length, &temp.front());

	return temp.substr(0, length);
}

inline void GL::getShaderPrecisionFormat(GL_ENUM shaderType, GL_ENUM precisionType, int* range, int* precision)
{
	glGetShaderPrecisionFormat(static_cast<unsigned int>(shaderType), static_cast<unsigned int>(precisionType), range, precision);
}

inline std::pair<ivec2, int> GL::getShaderPrecisionFormat(GL_ENUM shaderType, GL_ENUM precisionType)
{
	std::pair<ivec2, int> temp;
	getShaderPrecisionFormat(shaderType, precisionType, &temp.first.x, &temp.second);
	return temp;
}

inline void GL::getShaderSource(unsigned int shader, int bufSize, int* length, char* source)
{
	glGetShaderSource(shader, bufSize, length, source);
}

inline std::string GL::getShaderSource(unsigned int shader)
{
	std::string temp = std::string(getShaderiv(shader, SHADER_SOURCE_LENGTH), ' ');
	int length;

	getShaderSource(shader, static_cast<int>(temp.size()), &length, &temp.front());

	return temp.substr(0, length);
}

#if VC(4, 0)
inline int GL::getSubroutineIndex(unsigned int program, GL_ENUM shadertype, std::string_view name)
{
	return glGetSubroutineIndex(program, static_cast<unsigned int>(shadertype), &name.front());
}

inline int GL::getSubroutineUniformLocation(unsigned int program, GL_ENUM shadertype, std::string_view name)
{
	return glGetSubroutineUniformLocation(program, static_cast<unsigned int>(shadertype), &name.front());
}
#endif

inline void GL::getUniformfv(unsigned int program, int location, float* params)
{
	glGetUniformfv(program, location, params);
}

inline float GL::getSingleUniformfv(unsigned int program, int location)
{
	float temp;
	getUniformfv(program, location, &temp);
	return temp;
}

inline fvec2 GL::getDoubleUniformfv(unsigned int program, int location)
{
	fvec2 temp;
	getUniformfv(program, location, &temp.x);
	return temp;
}

inline fvec3 GL::getTripleUniformfv(unsigned int program, int location)
{
	fvec3 temp;
	getUniformfv(program, location, &temp.x);
	return temp;
}

inline fvec4 GL::getQuadUniformfv(unsigned int program, int location)
{
	fvec4 temp;
	getUniformfv(program, location, &temp.x);
	return temp;
}

inline void GL::getUniformiv(unsigned int program, int location, int* params)
{
	glGetUniformiv(program, location, params);
}

inline int GL::getSingleUniformiv(unsigned int program, int location)
{
	int temp;
	getUniformiv(program, location, &temp);
	return temp;
}

inline ivec2 GL::getDoubleUniformiv(unsigned int program, int location)
{
	ivec2 temp;
	getUniformiv(program, location, &temp.x);
	return temp;
}

inline ivec3 GL::getTripleUniformiv(unsigned int program, int location)
{
	ivec3 temp;
	getUniformiv(program, location, &temp.x);
	return temp;
}

inline ivec4 GL::getQuadUniformiv(unsigned int program, int location)
{
	ivec4 temp;
	getUniformiv(program, location, &temp.x);
	return temp;
}

inline void GL::getUniformuiv(unsigned int program, int location, unsigned int* params)
{
	glGetUniformuiv(program, location, params);
}

inline unsigned int GL::getSingleUniformuiv(unsigned int program, int location)
{
	unsigned int temp;
	getUniformuiv(program, location, &temp);
	return temp;
}

inline uvec2 GL::getDoubleUniformuiv(unsigned int program, int location)
{
	uvec2 temp;
	getUniformuiv(program, location, &temp.x);
	return temp;
}

inline uvec3 GL::getTripleUniformuiv(unsigned int program, int location)
{
	uvec3 temp;
	getUniformuiv(program, location, &temp.x);
	return temp;
}

inline uvec4 GL::getQuadUniformuiv(unsigned int program, int location)
{
	uvec4 temp;
	getUniformuiv(program, location, &temp.x);
	return temp;
}

#if VC(4, 0)
inline void GL::getUniformdv(unsigned int program, int location, double* params)
{
	glGetUniformdv(program, location, params);
}

inline double GL::getSingleUniformdv(unsigned int program, int location)
{
	double temp;
	getUniformdv(program, location, &temp);
	return temp;
}

inline dvec2 GL::getDoubleUniformdv(unsigned int program, int location)
{
	dvec2 temp;
	getUniformdv(program, location, &temp.x);
	return temp;
}

inline dvec3 GL::getTripleUniformdv(unsigned int program, int location)
{
	dvec3 temp;
	getUniformdv(program, location, &temp.x);
	return temp;
}

inline dvec4 GL::getQuadUniformdv(unsigned int program, int location)
{
	dvec4 temp;
	getUniformdv(program, location, &temp.x);
	return temp;
}
#endif

#if VC(4, 5)
inline void GL::getnUniformfv(unsigned int program, int location, int bufSize, float* params)
{
	glGetnUniformfv(program, location, bufSize, params);
}

inline void GL::getnUniformiv(unsigned int program, int location, int bufSize, int* params)
{
	glGetnUniformiv(program, location, bufSize, params);
}

inline void GL::getnUniformuiv(unsigned int program, int location, int bufSize, unsigned int* params)
{
	glGetnUniformuiv(program, location, bufSize, params);
}

inline void GL::getnUniformdv(unsigned int program, int location, int bufSize, double* params)
{
	glGetnUniformdv(program, location, bufSize, params);
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline unsigned int GL::getUniformBlockIndex(unsigned int program, std::string_view uniformBlockName)
{
	return glGetUniformBlockIndex(program, &uniformBlockName.front());
}

inline void GL::getUniformIndices(unsigned int program, const std::vector<std::string>& uniformNames, unsigned int* uniformIndices)
{
	std::vector<const char*> temp = std::vector<const char*>(uniformNames.size(), "");

	for (const auto& s : uniformNames)
	{
		temp[std::distance(&uniformNames.front(), &s)] = s.c_str();
	}

	glGetUniformIndices(program, static_cast<int>(uniformNames.size()), temp.data(), uniformIndices);
}

inline std::vector<unsigned int> GL::getUniformIndices(unsigned int program, const std::vector<std::string>& uniformNames)
{
	std::vector<unsigned int> temp = std::vector<unsigned int>(uniformNames.size(), 0);

	getUniformIndices(program, uniformNames, &temp.front());

	return temp;
}
#endif

inline int GL::getUniformLocation(unsigned int program, std::string_view name)
{
	return glGetUniformLocation(program, name.data());
}

#if VC(4, 0)
inline void GL::getUniformSubroutineuiv(GL_ENUM shadertype, int location, unsigned int* values)
{
	glGetUniformSubroutineuiv(static_cast<unsigned int>(shadertype), location, values);
}
#endif

inline bool GL::isProgram(unsigned int program)
{
	return glIsProgram(program);
}

inline bool GL::isShader(unsigned int shader)
{
	return glIsShader(shader);
}

inline void GL::linkProgram(unsigned int program)
{
	glLinkProgram(program);
}

#if VC(4, 0)
inline void GL::minSampleShading(float value)
{
	glMinSampleShading(value);
}
#endif

#if VC(4, 1) || EC(3, 0)
inline void GL::programBinary(unsigned int program, unsigned int binaryFormat, const void* binary, int length)
{
	glProgramBinary(program, binaryFormat, binary, length);
}
#endif

#if VC(4, 1) || EC(3, 0)
inline void GL::programParameteri(unsigned int program, GL_ENUM pname, int value)
{
	glProgramParameteri(program, static_cast<unsigned int>(pname), value);
}
#endif

#if VC(4, 1) || EC(3, 1)
inline void GL::programUniform1f(unsigned int program, int location, float v0)
{
	glProgramUniform1f(program, location, v0);
}

inline void GL::programUniform2f(unsigned int program, int location, float v0, float v1)
{
	glProgramUniform2f(program, location, v0, v1);
}

inline void GL::programUniform2f(unsigned int program, int location, const fvec2& v)
{
	glProgramUniform2f(program, location, v.x, v.y);
}

inline void GL::programUniform3f(unsigned int program, int location, float v0, float v1, float v2)
{
	glProgramUniform3f(program, location, v0, v1, v2);
}

inline void GL::programUniform3f(unsigned int program, int location, const fvec3& v)
{
	glProgramUniform3f(program, location, v.x, v.y, v.z);
}

inline void GL::programUniform4f(unsigned int program, int location, float v0, float v1, float v2, float v3)
{
	glProgramUniform4f(program, location, v0, v1, v2, v3);
}

inline void GL::programUniform4f(unsigned int program, int location, const fvec4& v)
{
	glProgramUniform4f(program, location, v.x, v.y, v.z, v.w);
}

inline void GL::programUniform1i(unsigned int program, int location, int v0)
{
	glProgramUniform1i(program, location, v0);
}

inline void GL::programUniform2i(unsigned int program, int location, int v0, int v1)
{
	glProgramUniform2i(program, location, v0, v1);
}

inline void GL::programUniform2i(unsigned int program, int location, const ivec2& v)
{
	glProgramUniform2i(program, location, v.x, v.y);
}

inline void GL::programUniform3i(unsigned int program, int location, int v0, int v1, int v2)
{
	glProgramUniform3i(program, location, v0, v1, v2);
}

inline void GL::programUniform3i(unsigned int program, int location, const ivec3& v)
{
	glProgramUniform3i(program, location, v.x, v.y, v.z);
}

inline void GL::programUniform4i(unsigned int program, int location, int v0, int v1, int v2, int v3)
{
	glProgramUniform4i(program, location, v0, v1, v2, v3);
}

inline void GL::programUniform4i(unsigned int program, int location, const ivec4& v)
{
	glProgramUniform4i(program, location, v.x, v.y, v.z, v.w);
}

inline void GL::programUniform1ui(unsigned int program, int location, unsigned int v0)
{
	glProgramUniform1ui(program, location, v0);
}

inline void GL::programUniform2ui(unsigned int program, int location, unsigned int v0, unsigned int v1)
{
	glProgramUniform2ui(program, location, v0, v1);
}

inline void GL::programUniform2ui(unsigned int program, int location, const uvec2& v)
{
	glProgramUniform2ui(program, location, v.x, v.y);
}

inline void GL::programUniform3ui(unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2)
{
	glProgramUniform3ui(program, location, v0, v1, v2);
}

inline void GL::programUniform3ui(unsigned int program, int location, const uvec3& v)
{
	glProgramUniform3ui(program, location, v.x, v.y, v.z);
}

inline void GL::programUniform4ui(unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
{
	glProgramUniform4ui(program, location, v0, v1, v2, v3);
}

inline void GL::programUniform4ui(unsigned int program, int location, const uvec4& v)
{
	glProgramUniform4ui(program, location, v.x, v.y, v.z, v.w);
}

inline void GL::programUniform1fv(unsigned int program, int location, int count, const float* value)
{
	glProgramUniform1fv(program, location, count, value);
}

inline void GL::programUniform2fv(unsigned int program, int location, int count, const float* value)
{
	glProgramUniform2fv(program, location, count, value);
}

inline void GL::programUniform2fv(unsigned int program, int location, int count, const fvec2& v)
{
	glProgramUniform2fv(program, location, count, &v.x);
}

inline void GL::programUniform3fv(unsigned int program, int location, int count, const float* value)
{
	glProgramUniform3fv(program, location, count, value);
}

inline void GL::programUniform3fv(unsigned int program, int location, int count, const fvec3& v)
{
	glProgramUniform3fv(program, location, count, &v.x);
}

inline void GL::programUniform4fv(unsigned int program, int location, int count, const float* value)
{
	glProgramUniform4fv(program, location, count, value);
}

inline void GL::programUniform4fv(unsigned int program, int location, int count, const fvec4& v)
{
	glProgramUniform4fv(program, location, count, &v.x);
}

inline void GL::programUniform1iv(unsigned int program, int location, int count, const int* value)
{
	glProgramUniform1iv(program, location, count, value);
}

inline void GL::programUniform2iv(unsigned int program, int location, int count, const int* value)
{
	glProgramUniform2iv(program, location, count, value);
}

inline void GL::programUniform2iv(unsigned int program, int location, int count, const ivec2& v)
{
	glProgramUniform2iv(program, location, count, &v.x);
}

inline void GL::programUniform3iv(unsigned int program, int location, int count, const int* value)
{
	glProgramUniform3iv(program, location, count, value);
}

inline void GL::programUniform3iv(unsigned int program, int location, int count, const ivec3& v)
{
	glProgramUniform3iv(program, location, count, &v.x);
}

inline void GL::programUniform4iv(unsigned int program, int location, int count, const int* value)
{
	glProgramUniform4iv(program, location, count, value);
}

inline void GL::programUniform4iv(unsigned int program, int location, int count, const ivec4& v)
{
	glProgramUniform4iv(program, location, count, &v.x);
}

inline void GL::programUniform1uiv(unsigned int program, int location, int count, const unsigned int* value)
{
	glProgramUniform1uiv(program, location, count, value);
}

inline void GL::programUniform2uiv(unsigned int program, int location, int count, const unsigned int* value)
{
	glProgramUniform2uiv(program, location, count, value);
}

inline void GL::programUniform2uiv(unsigned int program, int location, int count, const uvec2& v)
{
	glProgramUniform2uiv(program, location, count, &v.x);
}

inline void GL::programUniform3uiv(unsigned int program, int location, int count, const unsigned int* value)
{
	glProgramUniform3uiv(program, location, count, value);
}

inline void GL::programUniform3uiv(unsigned int program, int location, int count, const uvec3& v)
{
	glProgramUniform3uiv(program, location, count, &v.x);
}

inline void GL::programUniform4uiv(unsigned int program, int location, int count, const unsigned int* value)
{
	glProgramUniform4uiv(program, location, count, value);
}

inline void GL::programUniform4uiv(unsigned int program, int location, int count, const uvec4& v)
{
	glProgramUniform4uiv(program, location, count, &v.x);
}

inline void GL::programUniformMatrix2fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix2fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix2fv(unsigned int program, int location, int count, bool transpose, const mat2& value)
{
	glProgramUniformMatrix2fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix3fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix3fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix3fv(unsigned int program, int location, int count, bool transpose, const mat3& value)
{
	glProgramUniformMatrix3fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix4fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix4fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix4fv(unsigned int program, int location, int count, bool transpose, const mat4& value)
{
	glProgramUniformMatrix4fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix2x3fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix2x3fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix2x3fv(unsigned int program, int location, int count, bool transpose, const mat2x3& value)
{
	glProgramUniformMatrix2x3fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix3x2fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix3x2fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix3x2fv(unsigned int program, int location, int count, bool transpose, const mat3x2& value)
{
	glProgramUniformMatrix3x2fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix2x4fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix2x4fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix2x4fv(unsigned int program, int location, int count, bool transpose, const mat2x4& value)
{
	glProgramUniformMatrix2x4fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix4x2fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix4x2fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix4x2fv(unsigned int program, int location, int count, bool transpose, const mat4x2& value)
{
	glProgramUniformMatrix4x2fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix3x4fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix3x4fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix3x4fv(unsigned int program, int location, int count, bool transpose, const mat3x4& value)
{
	glProgramUniformMatrix3x4fv(program, location, count, transpose, &value[0][0]);
}

inline void GL::programUniformMatrix4x3fv(unsigned int program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix4x3fv(program, location, count, transpose, value);
}

inline void GL::programUniformMatrix4x3fv(unsigned int program, int location, int count, bool transpose, const mat4x3& value)
{
	glProgramUniformMatrix4x3fv(program, location, count, transpose, &value[0][0]);
}
#endif

#if (!GL_DESKTOP) || VC(4, 1)
inline void GL::releaseShaderCompiler()
{
	glReleaseShaderCompiler();
}

inline void GL::shaderBinary(int count, const unsigned int* shaders, unsigned int binaryFormat, const void* binary, int length)
{
	glShaderBinary(count, shaders, binaryFormat, binary, length);
}

inline void GL::shaderBinary(const std::vector<unsigned int>& shaders, unsigned int binaryFormat, const void* binary, int length)
{
	glShaderBinary(static_cast<int>(shaders.size()), shaders.data(), binaryFormat, binary, length);
}
#endif

inline void GL::shaderSource(unsigned int shader, int count, const char** string, const int* length)
{
	glShaderSource(shader, count, string, length);
}

inline void GL::shaderSource(unsigned int shader, const std::vector<std::string>& strings)
{
	std::vector<const char*> temp = std::vector<const char*>(strings.size(), "");

	for (const auto& s : strings)
	{
		temp[std::distance(&strings.front(), &s)] = s.c_str();
	}

	shaderSource(shader, static_cast<int>(strings.size()), &temp.front(), nullptr);
}

#if VC(4, 3)
inline void GL::shaderStorageBlockBinding(unsigned int program, unsigned int storageBlockIndex, unsigned int storageBlockBinding)
{
	glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
}
#endif

inline void GL::uniform1f(int location, float v0)
{
	glUniform1f(location, v0);
}

inline void GL::uniform2f(int location, float v0, float v1)
{
	glUniform2f(location, v0, v1);
}

inline void GL::uniform2f(int location, const fvec2& v)
{
	glUniform2f(location, v.x, v.y);
}

inline void GL::uniform3f(int location, float v0, float v1, float v2)
{
	glUniform3f(location, v0, v1, v2);
}

inline void GL::uniform3f(int location, const fvec3& v)
{
	glUniform3f(location, v.x, v.y, v.z);
}

inline void GL::uniform4f(int location, float v0, float v1, float v2, float v3)
{
	glUniform4f(location, v0, v1, v2, v3);
}

inline void GL::uniform4f(int location, const fvec4& v)
{
	glUniform4f(location, v.x, v.y, v.z, v.w);
}

inline void GL::uniform1i(int location, int v0)
{
	glUniform1i(location, v0);
}

inline void GL::uniform2i(int location, int v0, int v1)
{
	glUniform2i(location, v0, v1);
}

inline void GL::uniform2i(int location, const ivec2& v)
{
	glUniform2i(location, v.x, v.y);
}

inline void GL::uniform3i(int location, int v0, int v1, int v2)
{
	glUniform3i(location, v0, v1, v2);
}

inline void GL::uniform3i(int location, const ivec3& v)
{
	glUniform3i(location, v.x, v.y, v.z);
}

inline void GL::uniform4i(int location, int v0, int v1, int v2, int v3)
{
	glUniform4i(location, v0, v1, v2, v3);
}

inline void GL::uniform4i(int location, const ivec4& v)
{
	glUniform4i(location, v.x, v.y, v.z, v.w);
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::uniform1ui(int location, unsigned int v0)
{
	glUniform1ui(location, v0);
}

inline void GL::uniform2ui(int location, unsigned int v0, unsigned int v1)
{
	glUniform2ui(location, v0, v1);
}

inline void GL::uniform2ui(int location, const uvec2& v)
{
	glUniform2ui(location, v.x, v.y);
}

inline void GL::uniform3ui(int location, unsigned int v0, unsigned int v1, unsigned int v2)
{
	glUniform3ui(location, v0, v1, v2);
}

inline void GL::uniform3ui(int location, const uvec3& v)
{
	glUniform3ui(location, v.x, v.y, v.z);
}

inline void GL::uniform4ui(int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
{
	glUniform4ui(location, v0, v1, v2, v3);
}

inline void GL::uniform4ui(int location, const uvec4& v)
{
	glUniform4ui(location, v.x, v.y, v.z, v.w);
}
#endif

inline void GL::uniform1fv(int location, int count, const float* value)
{
	glUniform1fv(location, count, value);
}

inline void GL::uniform2fv(int location, int count, const float* value)
{
	glUniform2fv(location, count, value);
}

inline void GL::uniform2fv(int location, int count, const fvec2& v)
{
	glUniform2fv(location, count, &v.x);
}

inline void GL::uniform3fv(int location, int count, const float* value)
{
	glUniform3fv(location, count, value);
}

inline void GL::uniform3fv(int location, int count, const fvec3& v)
{
	glUniform3fv(location, count, &v.x);
}

inline void GL::uniform4fv(int location, int count, const float* value)
{
	glUniform4fv(location, count, value);
}

inline void GL::uniform4fv(int location, int count, const fvec4& v)
{
	glUniform4fv(location, count, &v.x);
}

inline void GL::uniform1iv(int location, int count, const int* value)
{
	glUniform1iv(location, count, value);
}

inline void GL::uniform2iv(int location, int count, const int* value)
{
	glUniform2iv(location, count, value);
}

inline void GL::uniform2iv(int location, int count, const ivec2& v)
{
	glUniform2iv(location, count, &v.x);
}

inline void GL::uniform3iv(int location, int count, const int* value)
{
	glUniform3iv(location, count, value);
}

inline void GL::uniform3iv(int location, int count, const ivec3& v)
{
	glUniform3iv(location, count, &v.x);
}

inline void GL::uniform4iv(int location, int count, const int* value)
{
	glUniform4iv(location, count, value);
}

inline void GL::uniform4iv(int location, int count, const ivec4& v)
{
	glUniform4iv(location, count, &v.x);
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::uniform1uiv(int location, int count, const unsigned int* value)
{
	glUniform1uiv(location, count, value);
}

inline void GL::uniform2uiv(int location, int count, const unsigned int* value)
{
	glUniform2uiv(location, count, value);
}

inline void GL::uniform2uiv(int location, int count, const uvec2& v)
{
	glUniform2uiv(location, count, &v.x);
}

inline void GL::uniform3uiv(int location, int count, const unsigned int* value)
{
	glUniform3uiv(location, count, value);
}

inline void GL::uniform3uiv(int location, int count, const uvec3& v)
{
	glUniform3uiv(location, count, &v.x);
}

inline void GL::uniform4uiv(int location, int count, const unsigned int* value)
{
	glUniform4uiv(location, count, value);
}

inline void GL::uniform4uiv(int location, int count, const uvec4& v)
{
	glUniform4uiv(location, count, &v.x);
}
#endif

inline void GL::uniformMatrix2fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(location, count, transpose, value);
}

inline void GL::uniformMatrix2fv(int location, int count, bool transpose, const mat2& value)
{
	glUniformMatrix2fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformMatrix3fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix3fv(location, count, transpose, value);
}

inline void GL::uniformMatrix3fv(int location, int count, bool transpose, const mat3& value)
{
	glUniformMatrix3fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformMatrix4fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix4fv(location, count, transpose, value);
}

inline void GL::uniformMatrix4fv(int location, int count, bool transpose, const mat4& value)
{
	glUniformMatrix4fv(location, count, transpose, &value[0][0]);
}

#if GL_DESKTOP || EC(3, 0)
inline void GL::uniformMatrix2x3fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix2x3fv(location, count, transpose, value);
}

inline void GL::uniformMatrix2x3fv(int location, int count, bool transpose, const mat2x3& value)
{
	glUniformMatrix2x3fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformMatrix3x2fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix3x2fv(location, count, transpose, value);
}

inline void GL::uniformMatrix3x2fv(int location, int count, bool transpose, const mat3x2& value)
{
	glUniformMatrix3x2fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformMatrix2x4fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix2x4fv(location, count, transpose, value);
}

inline void GL::uniformMatrix2x4fv(int location, int count, bool transpose, const mat2x4& value)
{
	glUniformMatrix2x4fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformMatrix4x2fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix4x2fv(location, count, transpose, value);
}

inline void GL::uniformMatrix4x2fv(int location, int count, bool transpose, const mat4x2& value)
{
	glUniformMatrix4x2fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformMatrix3x4fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix3x4fv(location, count, transpose, value);
}

inline void GL::uniformMatrix3x4fv(int location, int count, bool transpose, const mat3x4& value)
{
	glUniformMatrix3x4fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformMatrix4x3fv(int location, int count, bool transpose, const float* value)
{
	glUniformMatrix4x3fv(location, count, transpose, value);
}

inline void GL::uniformMatrix4x3fv(int location, int count, bool transpose, const mat4x3& value)
{
	glUniformMatrix4x3fv(location, count, transpose, &value[0][0]);
}

inline void GL::uniformBlockBinding(unsigned int program, unsigned int uniformBlockIndex, unsigned int uniformBlockBinding)
{
	glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
#endif

#if VC(4, 0)
inline void GL::uniformSubroutinesuiv(GL_ENUM shadertype, int count, const unsigned int* indices)
{
	glUniformSubroutinesuiv(static_cast<unsigned int>(shadertype), count, indices);
}

inline void GL::uniformSubroutinesuiv(GL_ENUM shadertype, const std::vector<unsigned int>& indices)
{
	uniformSubroutinesuiv(shadertype, static_cast<int>(indices.size()), indices.data());
}
#endif

inline void GL::useProgram(unsigned int program)
{
	glUseProgram(program);
}

#if VC(4, 1) || EC(3, 1)
inline void GL::detail::useProgramStages(unsigned int pipeline, unsigned int stages, unsigned int program)
{
	glUseProgramStages(pipeline, stages, program);
}
#endif

inline void GL::validateProgram(unsigned int program)
{
	glValidateProgram(program);
}
