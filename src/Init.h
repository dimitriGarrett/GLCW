#pragma once

#include "API.h"

namespace GL
{
	//Initialize GLEW with the experimental flag t/f
	GLCW_API void initGlew(bool experimental = true);
}