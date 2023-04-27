#pragma once

#include "API.h"
#include "Enums.h"

#if VC(4, 3) || EC(3, 1)
	namespace GL
	{
		//glGetProgramInterface — query a property of an interface in a program
		GLCW_API void getProgramInterfaceiv(unsigned int program, GL_ENUM programInterface, GL_ENUM pname, int* params);
		//glGetProgramInterface — query a property of an interface in a program
		GLCW_API int getProgramInterfaceiv(unsigned int program, GL_ENUM programInterface, GL_ENUM pname);
	}
#endif

#if VC(4, 3)
	#include <string_view>
	#include <vector>

	namespace GL
	{
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
		GLCW_API void debugMessageControl(GL_ENUM control, GL_ENUM type, GL_ENUM severity, int count, const unsigned int* ids, bool enabled);

		//glDebugMessageInsert — inject an application-supplied message into the debug message queue
		GLCW_API void debugMessageInsert(GL_ENUM source, GL_ENUM type, unsigned int id, GL_ENUM severity, int length, const char* message);
		//glDebugMessageInsert — inject an application-supplied message into the debug message queue
		GLCW_API void debugMessageInsert(GL_ENUM source, GL_ENUM type, unsigned int id, GL_ENUM severity, std::string_view message);

		//glGetDebugMessageLog — retrieve messages from the debug message log
		GLCW_API unsigned int getDebugMessageLog(unsigned int count, int bufSize, const std::vector<GL_ENUM >& sources, const std::vector<GL_ENUM >& types, unsigned int* ids, const std::vector<GL_ENUM >& severities, int* lengths, char* messageLog);

		//glGetObjectLabel — retrieve the label of a named object identified within a namespace
		GLCW_API void getObjectLabel(GL_ENUM identifier, unsigned int name, int bufSize, int* length, char* label);
		//glGetObjectLabel — retrieve the label of a named object identified within a namespace
		GLCW_API std::string getObjectLabel(GL_ENUM identifier, unsigned int name);

		//glGetObjectPtrLabel — retrieve the label of a sync object identified by a pointer
		GLCW_API void getObjectPtrLabel(void* ptr, int bufSize, int* length, char* label);
		//glGetObjectPtrLabel — retrieve the label of a sync object identified by a pointer
		GLCW_API std::string getObjectPtrLabel(void* ptr);

		//glGetPointerv — return the address of the specified pointer
		GLCW_API void getPointerv(GL_ENUM pname, void** params);
		//glGetPointerv — return the address of the specified pointer
		GLCW_API void* getPointerv(GL_ENUM pname);

		//glObjectLabel — label a named object identified within a namespace
		GLCW_API void objectLabel(GL_ENUM identifier, unsigned int name, int length, const char* label);
		//glObjectLabel — label a named object identified within a namespace
		GLCW_API void objectLabel(GL_ENUM identifier, unsigned int name, std::string_view label);

		//glObjectPtrLabel — label a a sync object identified by a pointer
		GLCW_API void objectPtrLabel(void* ptr, int length, const char* label);
		//glObjectPtrLabel — label a a sync object identified by a pointer
		GLCW_API void objectPtrLabel(void* ptr, std::string_view label);

		//glPopDebugGroup — pop the active debug group
		GLCW_API void popDebugGroup();

		//glPushDebugGroup — push a named debug group into the command stream
		GLCW_API void pushDebugGroup(GL_ENUM source, unsigned int id, int length, const char* message);
		//glPushDebugGroup — push a named debug group into the command stream
		GLCW_API void pushDebugGroup(GL_ENUM source, unsigned int id, std::string_view message);
	}
#endif