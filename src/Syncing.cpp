#include "Syncing.h"

#if GL_DESKTOP || EC(3, 0)
	#include "GL.h"

	inline GL::GL_ENUM GL::clientWaitSync(GLsync sync, unsigned int flags, size_t timeout)
	{
		return static_cast<GL_ENUM>(glClientWaitSync(sync, flags, timeout));
	}

	inline void GL::deleteSync(GLsync sync)
	{
		glDeleteSync(sync);
	}

	inline GLsync GL::fenceSync(unsigned int flags)
	{
		return glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, flags);
	}

	inline void GL::getSynciv(GLsync sync, GL_ENUM pname, int bufSize, int* length, int* values)
	{
		glGetSynciv(sync, static_cast<unsigned int>(pname), bufSize, length, values);
	}

	inline int GL::getSynciv(GLsync sync, GL_ENUM pname)
	{
		int temp;
		getSynciv(sync, pname, sizeof(int), nullptr, &temp);
		return temp;
	}

	inline bool GL::isSync(GLsync sync)
	{
		return static_cast<bool>(glIsSync(sync));
	}

	inline void GL::waitSync(GLsync sync, unsigned int flags)
	{
		glWaitSync(sync, flags, GL_TIMEOUT_IGNORED);
	}
#endif

#if VC(4, 5)
	inline void GL::textureBarrier()
	{
		glTextureBarrier();
	}
#endif