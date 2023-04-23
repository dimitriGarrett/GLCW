#pragma once

#include "API.h"
#include "Config.h"

#if GL_DESKTOP || EC(3, 0)
namespace GL
{
#if GL_DESKTOP
	enum class QueryMode : unsigned int
	{
		QUERY_WAIT = 0x8E13,
		QUERY_NO_WAIT = 0x8E14,
		QUERY_BY_REGION_WAIT = 0x8E15,
		QUERY_BY_REGION_NO_WAIT = 0x8E16
	};
#endif

	enum class QueryTarget : unsigned int
	{
#if VC(4, 3) || EC(3, 0)
		ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A,
#endif

		ANY_SAMPLES_PASSED = 0x8C2F,
		TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,

#if GL_DESKTOP
		SAMPLES_PASSED = 0x8914,
		PRIMITIVES_GENERATED = 0x8C87,
		TIME_ELAPSED = 0x88BF
#endif
	};

#if VC(4, 0)
	enum class QueryTargetIndexed : unsigned int
	{
		SAMPLES_PASSED = 0x8914,
		ANY_SAMPLES_PASSED = 0x8C2F,
		PRIMITIVES_GENERATED = 0x8C87,
		TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,
		TIME_ELAPSED = 0x88BF
	};

	enum class QueryPname : unsigned int
	{
		CURRENT_QUERY = 0x8865,
		QUERY_COUNTER_BITS = 0x8864
	};
#endif

	enum class QueryTargetIndexedGet : unsigned int
	{
		SAMPLES_PASSED = 0x8914,
		ANY_SAMPLES_PASSED = 0x8C2F,
		ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A,
		PRIMITIVES_GENERATED = 0x8C87,
		TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,
		TIME_ELAPSED = 0x88BF,
		TIMESTAMP = 0x8E28
	};

	enum class QueryResult : unsigned int
	{
		QUERY_RESULT = 0x8866,
		QUERY_RESULT_NO_WAIT = 0x9194,
		QUERY_RESULT_AVAILABLE = 0x8867
	};

#if GL_DESKTOP
	//glBeginConditionalRender — start conditional rendering
	GLCW_API void beginConditionalRender(unsigned int id, QueryMode mode);
	//glBeginConditionalRender — start conditional rendering
	GLCW_API void endConditionalRender();
#endif

	//glBeginQuery — delimit the boundaries of a query object
	GLCW_API void beginQuery(QueryTarget target, unsigned int id);
	//glBeginQuery — delimit the boundaries of a query object
	GLCW_API void endQuery(QueryTarget target);

#if VC(4, 0)
	//glBeginQueryIndexed, glEndQueryIndexed — delimit the boundaries of a query object on an indexed target
	GLCW_API void beginQueryIndexed(QueryTargetIndexed target, unsigned int index, unsigned int id);
	//glBeginQueryIndexed, glEndQueryIndexed — delimit the boundaries of a query object on an indexed target
	GLCW_API void endQueryIndexed(QueryTargetIndexed target, unsigned int index);
#endif

#if VC(4, 5)
	//glCreateQueries — create query objects
	GLCW_API void createQueries(QueryTarget target, int n, unsigned int* ids);
#endif

	//glDeleteQueries — delete named query objects
	GLCW_API void deleteQueries(int n, const unsigned int* ids);

	//glGenQueries — generate query object names
	GLCW_API void genQueries(int n, unsigned int* ids);

#if VC(4, 0)
	//glGetQueryIndexediv — return parameters of an indexed query object target
	GLCW_API void getQueryIndexediv(QueryTargetIndexedGet target, unsigned int index, QueryPname pname, int* params);
	//glGetQueryIndexediv — return parameters of an indexed query object target
	GLCW_API int getQueryIndexediv(QueryTargetIndexedGet target, unsigned int index, QueryPname pname);
#endif

	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjectuiv(unsigned int id, QueryResult pname, unsigned int* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API unsigned int getQueryObjectuiv(unsigned int id, QueryResult pname);

#if GL_DESKTOP
	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjectiv(unsigned int id, QueryResult pname, int* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API int getQueryObjectiv(unsigned int id, QueryResult pname);
	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjecti64v(unsigned int id, QueryResult pname, signed long long* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API signed long long getQueryObjecti64v(unsigned int id, QueryResult pname);
	//glGetQueryObject — return parameters of a query object
	GLCW_API void getQueryObjectui64v(unsigned int id, QueryResult pname, unsigned long long* params);
	//glGetQueryObject — return parameters of a query object
	GLCW_API unsigned long long getQueryObjectui64v(unsigned int id, QueryResult pname);

	//glGetQueryiv — return parameters of a query object target
	GLCW_API void getQueryiv(QueryTargetIndexedGet target, QueryResult pname, int* params);
	//glGetQueryiv — return parameters of a query object target
	GLCW_API int getQueryiv(QueryTargetIndexedGet target, QueryResult pname);

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