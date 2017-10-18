/********************************************************************
	Created:	2015/01/15  15:22
	Filename: 	wkeThirdpart.cpp
	Author:		rrrfff
	Url:	    http://blog.csdn.net/rrrfff
*********************************************************************/
#include "wke.h"

namespace WebCore{
	const char* MozillaUserAgent = "Mozilla/5.0 (Windows; NT; RLib) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.93";
}
namespace wkeEx{
	WKE_SHARED_DATA wchar_t LocalStorageDatabasePath[260] = { 0 };
	WKE_SHARED_DATA wchar_t UserAgent[256] = { L"Mozilla/5.0 (Linux; Android 4.4.4; HUAWEI P7-L00 Build/HuaweiP7-L00) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.93 Mobile Safari/537.36" };
}