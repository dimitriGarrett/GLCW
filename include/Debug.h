#pragma once

#include "API.h"
#include "Config.h"

#if VC(4, 3) || EC(3, 1)
	namespace GL
	{
		enum class DebugInterfaces : unsigned int
		{
			UNIFORM = 0x92E1,
			UNIFORM_BLOCK = 0x92E2,
			ATOMIC_COUNTER_BUFFER = 0x92C0,
			PROGRAM_INPUT = 0x92E3,
			PROGRAM_OUTPUT = 0x92E4,

#if VC(4, 3)
			VERTEX_SUBROUTINE = 0x92E8,
			TESS_CONTROL_SUBROUTINE = 0x92E9,
			TESS_EVALUATION_SUBROUTINE = 0x92EA,
			GEOMETRY_SUBROUTINE = 0x92EB,
			FRAGMENT_SUBROUTINE = 0x92EC,
			COMPUTE_SUBROUTINE = 0x92ED,
			VERTEX_SUBROUTINE_UNIFORM = 0x92EE,
			TESS_CONTROL_SUBROUTINE_UNIFORM = 0x92EF,
			TESS_EVALUATION_SUBROUTINE_UNIFORM = 0x92F0,
			GEOMETRY_SUBROUTINE_UNIFORM = 0x92F1,
			FRAGMENT_SUBROUTINE_UNIFORM = 0x92F2,
			COMPUTE_SUBROUTINE_UNIFORM = 0x92F3,
#endif
			
			TRANSFORM_FEEDBACK_VARYING = 0x92F4,
			BUFFER_VARIABLE = 0x92E5,
			SHADER_STORAGE_BLOCK = 0x92E6,
			TRANSFORM_FEEDBACK_BUFFER = 0x8C8E
		};

		enum class DebugPnames : unsigned int
		{
			ACTIVE_RESOURCES = 0x92F5,
			MAX_NAME_LENGTH = 0x92F6,
			MAX_NUM_ACTIVE_VARIABLES = 0x92F7,

#if VC(4, 3)
			MAX_NUM_COMPATIBLE_SUBROUTINES = 0x92F8
#endif
		};

		//glGetProgramInterface — query a property of an interface in a program
		GLCW_API void getProgramInterfaceiv(unsigned int program, DebugInterfaces programInterface, DebugPnames pname, int* params);
		//glGetProgramInterface — query a property of an interface in a program
		GLCW_API int getProgramInterfaceiv(unsigned int program, DebugInterfaces programInterface, DebugPnames pname);
	}
#endif

#if VC(4, 3)
	#include <string_view>
	#include <vector>

	namespace GL
	{
		enum class DebugMessageControl : unsigned int
		{
			DEBUG_SOURCE_API = 0x8246,
			DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247,
			DEBUG_SOURCE_SHADER_COMPILER = 0x8248,
			DEBUG_SOURCE_THIRD_PARTY = 0x8249,
			DEBUG_SOURCE_APPLICATION = 0x824A,
			DEBUG_SOURCE_OTHER = 0x824B,
			DONT_CARE = 0x1100
		};

		enum class DebugMessageType : unsigned int
		{
			DEBUG_TYPE_ERROR = 0x824C,
			DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D,
			DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E,
			DEBUG_TYPE_PORTABILITY = 0x824F,
			DEBUG_TYPE_PERFORMANCE = 0x8250,
			DEBUG_TYPE_OTHER = 0x8251,
			DEBUG_TYPE_MARKER = 0x8268,
			DEBUG_TYPE_PUSH_GROUP = 0x8269,
			DEBUG_TYPE_POP_GROUP = 0x826A,
			DONT_CARE = 0x1100
		};

		enum class DebugMessageSeverity : unsigned int
		{
			DEBUG_SEVERITY_HIGH = 0x9146,
			DEBUG_SEVERITY_MEDIUM = 0x9147,
			DEBUG_SEVERITY_LOW = 0x9148,
			DONT_CARE = 0x1100
		};

		enum class DebugMessageSource : unsigned int
		{
			DEBUG_SOURCE_THIRD_PARTY = 0x8249,
			DEBUG_SOURCE_APPLICATION = 0x824A
		};

		enum class DebugObjectLabels : unsigned int
		{
			BUFFER = 0x82E0,
			SHADER = 0x82E1,
			PROGRAM = 0x82E2,
			QUERY = 0x82E3,
			PROGRAM_PIPELINE = 0x82E4,
			TRANSFORM_FEEDBACK = 0x8E22,
			SAMPLER = 0x82E6,
			TEXTURE = 0x1702,
			RENDERBUFFER = 0x8D41,
			FRAMEBUFFER = 0x8D40
		};

		enum class DebugPtrs : unsigned int
		{
			DEBUG_CALLBACK_FUNCTION = 0x8244,
			DEBUG_CALLBACK_USER_PARAM = 0x8245
		};

		using debugMessageCallbackSignature = void(__stdcall*)(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, const void* userParam);

		//glDebugMessageCallback — specify a callback to receive debugging messages from the GL
		GLCW_API void setDefaultDebugMessageCallback();
		//glDebugMessageCallback — specify a callback to receive debugging messages from the GL
		GLCW_API void debugMessageCallback(debugMessageCallbackSignature callback, void* userParam);
		//glDebugMessageCallback — specify a callback to receive debugging messages from the GL
		template <typename T>
		static void debugMessageCallback(debugMessageCallbackSignature callback, const T& userParam)
		{
			debugMessageCallback(callback, static_cast<void*>(userParam));
		}

		//glDebugMessageControl — control the reporting of debug messages in a debug context
		GLCW_API void debugMessageControl(DebugMessageControl control, DebugMessageType type, DebugMessageSeverity severity, int count, const unsigned int* ids, bool enabled);

		//glDebugMessageInsert — inject an application-supplied message into the debug message queue
		GLCW_API void debugMessageInsert(DebugMessageSource source, DebugMessageType type, unsigned int id, DebugMessageSeverity severity, int length, const char* message);
		//glDebugMessageInsert — inject an application-supplied message into the debug message queue
		GLCW_API void debugMessageInsert(DebugMessageSource source, DebugMessageType type, unsigned int id, DebugMessageSeverity severity, std::string_view message);

		//glGetDebugMessageLog — retrieve messages from the debug message log
		GLCW_API unsigned int getDebugMessageLog(unsigned int count, int bufSize, const std::vector<DebugMessageSource>& sources, const std::vector<DebugMessageType>& types, unsigned int* ids, const std::vector<DebugMessageSeverity>& severities, int* lengths, char* messageLog);

		//glGetObjectLabel — retrieve the label of a named object identified within a namespace
		GLCW_API void getObjectLabel(DebugObjectLabels identifier, unsigned int name, int bufSize, int* length, char* label);
		//glGetObjectLabel — retrieve the label of a named object identified within a namespace
		GLCW_API std::string getObjectLabel(DebugObjectLabels identifier, unsigned int name);

		//glGetObjectPtrLabel — retrieve the label of a sync object identified by a pointer
		GLCW_API void getObjectPtrLabel(void* ptr, int bufSize, int* length, char* label);
		//glGetObjectPtrLabel — retrieve the label of a sync object identified by a pointer
		GLCW_API std::string getObjectPtrLabel(void* ptr);

		//glGetPointerv — return the address of the specified pointer
		GLCW_API void getPointerv(DebugPtrs pname, void** params);
		//glGetPointerv — return the address of the specified pointer
		GLCW_API void* getPointerv(DebugPtrs pname);

		//glObjectLabel — label a named object identified within a namespace
		GLCW_API void objectLabel(DebugObjectLabels identifier, unsigned int name, int length, const char* label);
		//glObjectLabel — label a named object identified within a namespace
		GLCW_API void objectLabel(DebugObjectLabels identifier, unsigned int name, std::string_view label);

		//glObjectPtrLabel — label a a sync object identified by a pointer
		GLCW_API void objectPtrLabel(void* ptr, int length, const char* label);
		//glObjectPtrLabel — label a a sync object identified by a pointer
		GLCW_API void objectPtrLabel(void* ptr, std::string_view label);

		//glPopDebugGroup — pop the active debug group
		GLCW_API void popDebugGroup();

		//glPushDebugGroup — push a named debug group into the command stream
		GLCW_API void pushDebugGroup(DebugMessageSource source, unsigned int id, int length, const char* message);
		//glPushDebugGroup — push a named debug group into the command stream
		GLCW_API void pushDebugGroup(DebugMessageSource source, unsigned int id, std::string_view message);
	}
#endif