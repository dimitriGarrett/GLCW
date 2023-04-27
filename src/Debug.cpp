#include "Debug.h"
#include "GL.h"

#if VC(4, 3) || EC(3, 1)
	inline void GL::getProgramInterfaceiv(unsigned int program, GL_ENUM programInterface, GL_ENUM pname, int* params)
	{
		glGetProgramInterfaceiv(program, static_cast<unsigned int>(programInterface), static_cast<unsigned int>(pname), params);
	}

	inline int GL::getProgramInterfaceiv(unsigned int program, GL_ENUM programInterface, GL_ENUM pname)
	{
		int temp;
		getProgramInterfaceiv(program, programInterface, pname, &temp);
		return temp;
	}
#endif

#if VC(4, 3)
	#include "State.h"

	#include <iostream>

	inline void GL::setDefaultDebugMessageCallback()
	{
		debugMessageCallback([](unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, const void* userParam)
			{
				if (type != GL_DEBUG_TYPE_ERROR)
				return;
		std::cout << "GL callback Error" << " Type: " << type << " Severity: " << severity << " Message: " << message << std::endl;
			}, nullptr);
	}

	inline void GL::debugMessageCallback(debugMessageCallbackSignature callback, void* userParam)
	{
		glDebugMessageCallback(callback, userParam);
	}

	inline void GL::debugMessageControl(GL_ENUM control, GL_ENUM type, GL_ENUM severity, int count, const unsigned int* ids, bool enabled)
	{
		glDebugMessageControl(static_cast<unsigned int>(control), static_cast<unsigned int>(type), static_cast<unsigned int>(severity), count, ids, static_cast<unsigned char>(enabled));
	}

	inline void GL::debugMessageInsert(GL_ENUM source, GL_ENUM type, unsigned int id, GL_ENUM severity, int length, const char* message)
	{
		glDebugMessageInsert(static_cast<unsigned int>(source), static_cast<unsigned int>(type), id, static_cast<unsigned int>(severity), length, message);
	}

	inline void GL::debugMessageInsert(GL_ENUM source, GL_ENUM type, unsigned int id, GL_ENUM severity, std::string_view message)
	{
		debugMessageInsert(source, type, id, severity, static_cast<int>(message.size()), message.data());
	}

	inline unsigned int GL::getDebugMessageLog(unsigned int count, int bufSize, const std::vector<GL_ENUM >& sources, const std::vector<GL_ENUM >& types, unsigned int* ids, const std::vector<GL_ENUM >& severities, int* lengths, char* messageLog)
	{
		return glGetDebugMessageLog(count, bufSize, (unsigned int*)(&sources.front()), (unsigned int*)(&types.front()), ids, (unsigned int*)(&severities.front()), lengths, messageLog);
	}

	inline void GL::getObjectLabel(GL_ENUM identifier, unsigned int name, int bufSize, int* length, char* label)
	{
		glGetObjectLabel(static_cast<unsigned int>(identifier), name, bufSize, length, label);
	}

	inline std::string GL::getObjectLabel(GL_ENUM identifier, unsigned int name)
	{
		/*int length = 0;
		int bufSize = 512;

		std::string view(bufSize, 'x');

		do
		{
			bufSize <<= 1;
			view.resize(bufSize, 0);
			getObjectLabel(identifier, name, bufSize, &length, &view.front());
		} while (length > bufSize);

		return view.substr(0, length);*/

		int length = 0;
		std::string view(getIntegerv(MAX_DEBUG_MESSAGE_LENGTH), 'x');
		getObjectLabel(identifier, name, static_cast<int>(view.size()), &length, &view.front());
		return view.substr(0, length);
	}

	inline void GL::getObjectPtrLabel(void* ptr, int bufSize, int* length, char* label)
	{
		glGetObjectPtrLabel(ptr, bufSize, length, label);
	}

	inline std::string GL::getObjectPtrLabel(void* ptr)
	{
		int length = 0;
		std::string view(getIntegerv(MAX_DEBUG_MESSAGE_LENGTH), 'x');
		getObjectPtrLabel(ptr, view.size(), &length, view.data());
		return view.substr(0, length);
	}

	inline void GL::getPointerv(GL_ENUM pname, void** params)
	{
		glGetPointerv(static_cast<unsigned int>(pname), params);
	}

	inline void* GL::getPointerv(GL_ENUM pname)
	{
		void* temp;
		getPointerv(pname, &temp);
		return temp;
	}

	inline void GL::objectLabel(GL_ENUM identifier, unsigned int name, int length, const char* label)
	{
		glObjectLabel(static_cast<unsigned int>(identifier), name, length, label);
	}

	inline void GL::objectLabel(GL_ENUM identifier, unsigned int name, std::string_view label)
	{
		glObjectLabel(static_cast<unsigned int>(identifier), name, static_cast<int>(label.size()), label.data());
	}

	inline void GL::objectPtrLabel(void* ptr, int length, const char* label)
	{
		glObjectPtrLabel(ptr, length, label);
	}

	inline void GL::objectPtrLabel(void* ptr, std::string_view label)
	{
		glObjectPtrLabel(ptr, static_cast<int>(label.size()), &label.front());
	}

	inline void GL::popDebugGroup()
	{
		glPopDebugGroup();
	}

	inline void GL::pushDebugGroup(GL_ENUM source, unsigned int id, int length, const char* message)
	{
		glPushDebugGroup(static_cast<unsigned int>(source), id, length, message);
	}

	inline void GL::pushDebugGroup(GL_ENUM source, unsigned int id, std::string_view message)
	{
		glPushDebugGroup(static_cast<unsigned int>(source), id, static_cast<int>(message.size()), &message.front());
	}
#endif