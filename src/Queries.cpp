#include "Queries.h"
#include "GL.h"

#if GL_DESKTOP
inline void GL::beginConditionalRender(unsigned int id, GL_ENUM mode)
{
	glBeginConditionalRender(id, static_cast<unsigned int>(mode));
}

inline void GL::endConditionalRender()
{
	glEndConditionalRender();
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::beginQuery(GL_ENUM target, unsigned int id)
{
	glBeginQuery(static_cast<unsigned int>(target), id);
}

inline void GL::endQuery(GL_ENUM target)
{
	glEndQuery(static_cast<unsigned int>(target));
}
#endif

#if VC(4, 0)
inline void GL::beginQueryIndexed(GL_ENUM target, unsigned int index, unsigned int id)
{
	glBeginQueryIndexed(static_cast<unsigned int>(target), index, id);
}

inline void GL::endQueryIndexed(GL_ENUM target, unsigned int index)
{
	glEndQueryIndexed(static_cast<unsigned int>(target), index);
}
#endif

#if VC(4, 5)
inline void GL::createQueries(GL_ENUM target, int n, unsigned int* ids)
{
	glCreateQueries(static_cast<unsigned int>(target), n, ids);
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline void GL::deleteQueries(int n, const unsigned int* ids)
{
	glDeleteQueries(n, ids);
}

inline void GL::genQueries(int n, unsigned int* ids)
{
	glGenQueries(n, ids);
}
#endif

#if VC(4, 0)
inline void GL::getQueryIndexediv(GL_ENUM target, unsigned int index, GL_ENUM pname, int* params)
{
	glGetQueryIndexediv(static_cast<unsigned int>(target), index, static_cast<unsigned int>(pname), params);
}

inline int GL::getQueryIndexediv(GL_ENUM target, unsigned int index, GL_ENUM pname)
{
	int temp;
	getQueryIndexediv(target, index, pname, &temp);
	return temp;
}
#endif

#if GL_DESKTOP
inline void GL::getQueryObjectiv(unsigned int id, GL_ENUM pname, int* params)
{
	glGetQueryObjectiv(id, static_cast<unsigned int>(pname), params);
}

inline int GL::getQueryObjectiv(unsigned int id, GL_ENUM pname)
{
	int temp;
	getQueryObjectiv(id, pname, &temp);
	return temp;
}

inline void GL::getQueryObjectuiv(unsigned int id, GL_ENUM pname, unsigned int* params)
{
	glGetQueryObjectuiv(id, static_cast<unsigned int>(pname), params);
}

inline unsigned int GL::getQueryObjectuiv(unsigned int id, GL_ENUM pname)
{
	unsigned int temp;
	getQueryObjectuiv(id, pname, &temp);
	return temp;
}

inline void GL::getQueryObjecti64v(unsigned int id, GL_ENUM pname, signed long long* params)
{
	glGetQueryObjecti64v(id, static_cast<unsigned int>(pname), params);
}

inline signed long long GL::getQueryObjecti64v(unsigned int id, GL_ENUM pname)
{
	signed long long temp;
	getQueryObjecti64v(id, pname, &temp);
	return temp;
}

inline void GL::getQueryObjectui64v(unsigned int id, GL_ENUM pname, unsigned long long* params)
{
	glGetQueryObjectui64v(id, static_cast<unsigned int>(pname), params);
}

inline unsigned long long GL::getQueryObjectui64v(unsigned int id, GL_ENUM pname)
{
	unsigned long long temp;
	getQueryObjectui64v(id, pname, &temp);
	return temp;
}

inline void GL::getQueryiv(GL_ENUM target, GL_ENUM pname, int* params)
{
	glGetQueryiv(static_cast<unsigned int>(target), static_cast<unsigned int>(pname), params);
}

inline int GL::getQueryiv(GL_ENUM target, GL_ENUM pname)
{
	int temp;
	getQueryiv(target, pname, &temp);
	return temp;
}
#elif EC(3, 0)
inline void GL::getQueryiv(QueryTargetIndexedGet target, int* params)
{
	glGetQueryiv(static_cast<unsigned int>(target), GL_CURRENT_QUERY, params);
}

inline int GL::getQueryiv(QueryTargetIndexedGet target)
{
	int temp;
	getQueryiv(target, &temp);
	return temp;
}
#endif

#if GL_DESKTOP || EC(3, 0)
inline bool GL::isQuery(unsigned int id)
{
	return static_cast<bool>(glIsQuery(id));
}
#endif

#if GL_DESKTOP
inline void GL::queryCounter(unsigned int id)
{
	glQueryCounter(id, GL_TIMESTAMP);
}
#endif