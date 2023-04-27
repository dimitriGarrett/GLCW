#pragma once

#include "API.h"
#include "Enums.h"

#if GL_DESKTOP || EC(3, 0)
namespace GL
{
#if GL_DESKTOP
	//glBeginConditionalRender — start conditional rendering
	GLCW_API void beginConditionalRender(unsigned int id, GL_ENUM mode);
	//glBeginConditionalRender — start conditional rendering
	GLCW_API void endConditionalRender();
#endif

	//glBeginQuery — delimit the boundaries of a query object
	GLCW_API void beginQuery(GL_ENUM target, unsigned int id);
	//glBeginQuery — delimit the boundaries of a query object
	GLCW_API void endQuery(GL_ENUM target);

#if VC(4, 0)
	//glBeginQueryIndexed, glEndQueryIndexed — delimit the boundaries of a query object on an indexed target
	GLCW_API void beginQueryIndexed(GL_ENUM target, unsigned int index, unsigned int id);
	//glBeginQueryIndexed, glEndQueryIndexed — delimit the boundaries of a query object on an indexed target
	GLCW_API void endQueryIndexed(GL_ENUM target, unsigned int index);
#endif

#if VC(4, 5)
	//glCreateQueries — create query objects
	GLCW_API void createQueries(GL_ENUM target, int n, unsigned int* ids);
#endif

	//glDeleteQueries — delete named query objects
	GLCW_API void deleteQueries(int n, const unsigned int* ids);

	//glGenQueries — generate query object names
	GLCW_API void genQueries(int n, unsigned int* ids);

#if VC(4, 0)
	//glGetQueryIndexediv — return parameters of an indexed query object target
	GLCW_API void getQueryIndexediv(GL_ENUM target, unsigned int index, GL_ENUM pname, int* params);
	//glGetQueryIndexediv — return parameters of an indexed query object target
	GLCW_API int getQueryIndexediv(GL_ENUM target, unsigned int index, GL_ENUM pname);
#endif

	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjectuiv(unsigned int id, GL_ENUM pname, unsigned int* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API unsigned int getQueryObjectuiv(unsigned int id, GL_ENUM pname);

#if GL_DESKTOP
	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjectiv(unsigned int id, GL_ENUM pname, int* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API int getQueryObjectiv(unsigned int id, GL_ENUM pname);
	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjecti64v(unsigned int id, GL_ENUM pname, signed long long* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API signed long long getQueryObjecti64v(unsigned int id, GL_ENUM pname);
	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjectui64v(unsigned int id, GL_ENUM pname, unsigned long long* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API unsigned long long getQueryObjectui64v(unsigned int id, GL_ENUM pname);

	//glGetQueryiv — return parameters of a query object target
	GLCW_API void getQueryiv(GL_ENUM target, GL_ENUM pname, int* params);
	//glGetQueryiv — return parameters of a query object target
	GLCW_API int getQueryiv(GL_ENUM target, GL_ENUM pname);

#else
	//glGetQueryiv — return parameters of a query object target
	GLCW_API void getQueryiv(QueryTargetIndexedGet target, int* params);
	//glGetQueryiv — return parameters of a query object target
	GLCW_API int getQueryiv(QueryTargetIndexedGet target);
#endif

	//glIsQuery — determine if a name corresponds to a query object
	GLCW_API bool isQuery(unsigned int id);

#if GL_DESKTOP
	//glQueryCounter — record the GL time into a query object after all previous commands have reached the GL server but have not yet necessarily executed.
	GLCW_API void queryCounter(unsigned int id);
#endif
}
#endif