#ifndef __DEBUG_H__
#define __DEBUG_H__
#ifdef _DEBUG
#include <string>

#define ODS(szOut)\
{\
	OutputDebugString(szOut);\
}

#define ODSA(szOut)\
{\
	std::string str ="ODS:";\
	str+=szOut;\
	OutputDebugStringA(str.c_str());\
}

#define ODS1(szOut, var)\
{						\
	TCHAR sz[1024];		\
	_stprintf_s(sz, szOut, var);\
	OutputDebugString(sz);\
}
#else
#define ODS(szOut)
#define ODS1(szOut, var)
#endif
#endif
