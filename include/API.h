#pragma once

#ifdef _WIN32
	#ifdef GLCW_EXPORT
		#define GLCW_API __declspec(dllexport)
	#else
		#define GLCW_API __declspec(dllimport)
	#endif
#else
	#define GLCW_API extern
#endif