#pragma once

#include "API.h"
#include "Enums.h"
//#include "GL.h"

struct __GLsync;
using GLsync = __GLsync*;

namespace GL
{
	static constexpr unsigned int SYNC_FLUSH_COMMANDS_BIT = 1;

#if GL_DESKTOP || EC(3, 0)
	//glClientWaitSync — block and wait for a sync object to become signaled
	GLCW_API GL_ENUM clientWaitSync(GLsync sync, unsigned int flags, size_t timeout);

	//glDeleteSync — delete a sync object
	GLCW_API void deleteSync(GLsync sync);

	//glFenceSync — create a new sync object and insert it into the GL command stream
	GLCW_API GLsync fenceSync(unsigned int flags);

	//glGetSynciv — query the properties of a sync object
	GLCW_API void getSynciv(GLsync sync, GL_ENUM pname, int bufSize, int* length, int* values);
	//glGetSynciv — query the properties of a sync object
	GLCW_API int getSynciv(GLsync sync, GL_ENUM pname);

	//glIsSync — determine if a name corresponds to a sync object
	GLCW_API bool isSync(GLsync sync);

	//glWaitSync — instruct the GL server to block until the specified sync object becomes signaled
	GLCW_API void waitSync(GLsync sync, unsigned int flags);
#endif

#if VC(4, 5)
	//glTextureBarrier — controls the ordering of reads and writes to rendered fragments across drawing commands
	GLCW_API void textureBarrier();
#endif
}