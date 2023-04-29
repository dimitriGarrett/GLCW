#include "Init.h"
#include "glew/glew.h"

#include <corecrt_terminate.h>

namespace GL
{
	void GL::initGlew(bool experimental)
	{
		glewExperimental = experimental;
		if (glewInit() != GLEW_OK)
		{
			//glew init failed

			terminate();
		}
	}
}