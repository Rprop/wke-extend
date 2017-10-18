
#include <WebCore/config.h>

#include <JavaScriptCore/InitializeThreading.h>
#include <JavaScriptCore/MainThread.h>
#include <WebCore/Page.h>
#include <WebCore/PageGroup.h>
#include <WebCore/IconDatabase.h>
#include <WebCore/WebCoreInstanceHandle.h>
#include <WebCore/RenderThemeWin.h>
#include <WebCore/ResourceHandleManager.h>
#include <WebCore/Console.h>

#include "wkePlatformStrategies.inl"

#include "wke.h"
#include "icuwin.h"
#include "stringTable.h"

void wkeInitMainThread()
{
	icuwin_init(); //static charset data

	JSC::initializeThreading(); //call WTF::initializeThreading();
	WTF::initializeMainThread();
	wke::PlatformStrategies::initialize();
}

void wkeSetCookieJarFileName(const char *cookieJarFileName)
{
	WebCore::ResourceHandleManager::sharedInstance()->setCookieJarFileName(cookieJarFileName);
}

void wkeSetProxyInfo(const char *host, unsigned long port,
					 wkeEx::ProxyType type,
					 const char *username, const char *password)
{
	WebCore::ResourceHandleManager::sharedInstance()->setProxyInfo(host, port,
																   static_cast<WebCore::ResourceHandleManager::ProxyType>(type),
																   username, password);
}

void wkeInit()
{
    //double-precision float
    _controlfp(_PC_53, _MCW_PC);

    CoInitialize(NULL);
   
    initStringTable();

    JSC::initializeThreading();

//    WebCore::Console::setShouldPrintExceptions(true);
}

void wkeShutdown()
{
    wkeUpdate();

    WebCore::iconDatabase().close();
    WebCore::PageGroup::closeLocalStorage();

    destroyStringTable();

    CoUninitialize();
}

void wkeUpdate()
{
    static HWND hTimer = NULL;
    if (!hTimer)
        hTimer = FindWindow(L"TimerWindowClass", NULL);

	//fixed by rrrfff
	//  [1/17/2015 ASUS]
	if (hTimer == NULL || !IsWindow(hTimer)){
		hTimer = NULL;
	}
	else{
        MSG msg;
        while(PeekMessage(&msg, hTimer, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}


#define MAJOR_VERSION   (1)
#define MINOR_VERSION   (2)
#define WEBKIT_BUILD    (98096)

unsigned int wkeVersion()
{
    return (MAJOR_VERSION << 8) + MINOR_VERSION;
}

const utf8* wkeVersionString()
{
    static utf8 s_versionString[128];
    sprintf(s_versionString, "wke version %d.%02d\n"
                             "webkit build %d\n"
                             "build time %s\n"
							 "extend v1.1",
                             MAJOR_VERSION,
							 MINOR_VERSION,
                             WEBKIT_BUILD,
                             __TIMESTAMP__);
    return s_versionString;
}


extern "C" void libcurl_set_file_system(WKE_FILE_OPEN pfn_open, WKE_FILE_CLOSE pfn_close, WKE_FILE_SIZE pfn_size, WKE_FILE_READ pfn_read, WKE_FILE_SEEK  pfn_seek);
void wkeSetFileSystem(WKE_FILE_OPEN pfn_open, WKE_FILE_CLOSE pfn_close, WKE_FILE_SIZE pfn_size, WKE_FILE_READ pfn_read, WKE_FILE_SEEK pfn_seek)
{
    libcurl_set_file_system(pfn_open, pfn_close, pfn_size, pfn_read, pfn_seek);
}

const char* wkeWebViewName(wkeWebView webView)
{
    return webView->name();
}

void wkeSetWebViewName(wkeWebView webView, const char* name)
{
    webView->setName(name);
}

bool wkeIsTransparent(wkeWebView webView)
{
    return webView->transparent();
}

void wkeSetTransparent(wkeWebView webView, bool transparent)
{
    webView->setTransparent(transparent);
}

void wkeLoadURL(wkeWebView webView, const utf8* url)
{
    webView->loadURL(url);
}

void wkeLoadURLW(wkeWebView webView, const wchar_t* url)
{
    webView->loadURL(url);
}

void wkeLoadHTML(wkeWebView webView, const utf8* html)
{
    webView->loadHTML(html);
}

void wkeLoadHTMLW(wkeWebView webView, const wchar_t* html)
{
    webView->loadHTML(html);
}

void wkeLoadFile(wkeWebView webView, const utf8* filename)
{
    return webView->loadFile(filename);
}

void wkeLoadFileW(wkeWebView webView, const wchar_t* filename)
{
    return webView->loadFile(filename);
}

bool wkeIsLoaded(wkeWebView webView)
{
    return webView->isLoaded();
}

bool wkeIsLoadFailed(wkeWebView webView)
{
    return webView->isLoadFailed();
}

bool wkeIsLoadComplete(wkeWebView webView)
{
    return webView->isLoadComplete();
}

bool wkeIsDocumentReady(wkeWebView webView)
{
    return webView->isDocumentReady();
}

void wkeStopLoading(wkeWebView webView)
{
    webView->stopLoading();
}

void wkeReload(wkeWebView webView)
{
    webView->reload();
}

const utf8* wkeTitle(wkeWebView webView)
{
    return webView->title();
}

const wchar_t* wkeTitleW(wkeWebView webView)
{
    return webView->titleW();
}

void wkeResize(wkeWebView webView, int w, int h)
{
    webView->resize(w, h);
}

int wkeWidth(wkeWebView webView)
{
    return webView->width();
}

int wkeHeight(wkeWebView webView)
{
    return webView->height();
}

int wkeContentsWidth(wkeWebView webView)
{
    return webView->contentsWidth();
}

int wkeContentsHeight(wkeWebView webView)
{
    return webView->contentsHeight();
}

void wkeSetDirty(wkeWebView webView, bool dirty)
{
    webView->setDirty(dirty);
}

bool wkeIsDirty(wkeWebView webView)
{
    return webView->isDirty();
}

void wkeAddDirtyArea(wkeWebView webView, int x, int y, int w, int h)
{
    webView->addDirtyArea(x, y, w, h);
}

void wkeLayoutIfNeeded(wkeWebView webView)
{
    webView->layoutIfNeeded();
}

void wkePaint(wkeWebView webView,void* bits, int bufWid, int bufHei, int xDst, int yDst, int w, int h, int xSrc, int ySrc, bool bCopyAlpha)
{
    webView->paint(bits, bufWid,  bufHei,  xDst,  yDst,  w,  h,  xSrc,  ySrc, bCopyAlpha);
}

void wkePaint2(wkeWebView webView, void* bits,int pitch)
{
    webView->paint(bits, pitch);
}

bool wkeCanGoBack(wkeWebView webView)
{
    return webView->canGoBack();
}

bool wkeGoBack(wkeWebView webView)
{
    return webView->goBack();
}

bool wkeCanGoForward(wkeWebView webView)
{
    return webView->canGoForward();
}

bool wkeGoForward(wkeWebView webView)
{
    return webView->goForward();
}

void wkeSelectAll(wkeWebView webView)
{
    webView->selectAll();
}

void wkeCopy(wkeWebView webView)
{
    webView->copy();
}

void wkeCut(wkeWebView webView)
{
    webView->cut();
}

void wkePaste(wkeWebView webView)
{
    webView->paste();
}

void wkeDelete(wkeWebView webView)
{
    webView->delete_();
}

void wkeSetCookieEnabled(wkeWebView webView, bool enable)
{
    webView->setCookieEnabled(enable);
}

bool wkeCookieEnabled(wkeWebView webView)
{
    return webView->cookieEnabled();
}

void wkeSetMediaVolume(wkeWebView webView, float volume)
{
    webView->setMediaVolume(volume);
}

float wkeMediaVolume(wkeWebView webView)
{
    return webView->mediaVolume();
}

bool wkeMouseEvent(wkeWebView webView, unsigned int message, int x, int y, unsigned int flags)
{
    return webView->mouseEvent(message, x, y, flags);
}

bool wkeContextMenuEvent(wkeWebView webView, int x, int y, unsigned int flags)
{
    return webView->contextMenuEvent(x, y, flags);
}

bool wkeMouseWheel(wkeWebView webView, int x, int y, int delta, unsigned int flags)
{
    return webView->mouseWheel(x, y, delta, flags);
}

bool wkeKeyUp(wkeWebView webView, unsigned int virtualKeyCode, unsigned int flags, bool systemKey)
{
    return webView->keyUp(virtualKeyCode, flags, systemKey);
}

bool wkeKeyDown(wkeWebView webView, unsigned int virtualKeyCode, unsigned int flags, bool systemKey)
{
    return webView->keyDown(virtualKeyCode, flags, systemKey);
}

bool wkeKeyPress(wkeWebView webView, unsigned int charCode, unsigned int flags, bool systemKey)
{
    return webView->keyPress(charCode, flags, systemKey);
}

void wkeFocus(wkeWebView webView)
{
    webView->focus();
}

void wkeUnfocus(wkeWebView webView)
{
    webView->unfocus();
}

wkeRect wkeGetCaret(wkeWebView webView)
{
    return webView->getCaret();
}

jsValue wkeRunJS(wkeWebView webView, const utf8* script)
{
    return webView->runJS(script);
}

jsValue wkeRunJSW(wkeWebView webView, const wchar_t* script)
{
    return webView->runJS(script);
}

jsExecState wkeGlobalExec(wkeWebView webView)
{
    return webView->globalExec();
}

void wkeSleep(wkeWebView webView)
{
    webView->sleep();
}

void wkeAwaken(wkeWebView webView)
{
    webView->awaken();
}

bool wkeIsAwake(wkeWebView webView)
{
    return webView->isAwake();
}

void wkeSetZoomFactor(wkeWebView webView, float factor)
{
    webView->setZoomFactor(factor);
}

float wkeZoomFactor(wkeWebView webView)
{
    return webView->zoomFactor();
}

void wkeSetEditable(wkeWebView webView, bool editable)
{
    webView->setEditable(editable);
}

WKE_API void wkeSetClientHandler(wkeWebView webView, const wkeClientHandler* handler)
{
    webView->setClientHandler(handler);
}

WKE_API const wkeClientHandler* wkeGetClientHandler(wkeWebView webView)
{
    return webView->getClientHandler();
}

WKE_API const utf8* wkeToString(const wkeString string)
{
    const String* str = (const String*)string;
    return StringTable::addString(str->characters(), str->length());
}

WKE_API const wchar_t* wkeToStringW(const wkeString string)
{
    const String* str = (const String*)string;
    return StringTableW::addString(str->characters(), str->length());
}


//FIXME: We should consider moving this to a new file for cross-project functionality
PassRefPtr<WebCore::SharedBuffer> loadResourceIntoBuffer(const char* name)
{
    return 0;
}

extern "C" BOOL WINAPI CoreFoundationDllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID pReserved);
extern void __CFInitialize(void);
namespace WebCore{
	extern CFStringRef LegacyWebArchiveMainResourceKey = nullptr;
	extern CFStringRef LegacyWebArchiveSubresourcesKey = nullptr;
	extern CFStringRef LegacyWebArchiveSubframeArchivesKey = nullptr;
	extern CFStringRef LegacyWebArchiveResourceDataKey = nullptr;
	extern CFStringRef LegacyWebArchiveResourceFrameNameKey = nullptr;
	extern CFStringRef LegacyWebArchiveResourceMIMETypeKey = nullptr;
	extern CFStringRef LegacyWebArchiveResourceURLKey = nullptr;
	extern CFStringRef LegacyWebArchiveResourceTextEncodingNameKey = nullptr;
	extern CFStringRef LegacyWebArchiveResourceResponseKey = nullptr;
	extern CFStringRef LegacyWebArchiveResourceResponseVersionKey = nullptr;

	/*
	 *	auto initialize
	 *  added by rrrfff
	 *    [1/17/2015 ASUS]
	 */
	typedef struct _LibInitializer
	{
	public:
		float unused;
	public:
		_LibInitializer() :unused(1.0)
		{
			_putenv("WEBKIT_IGNORE_SSL_ERRORS=1");
			pthread_win32_process_attach_np();

			//fixed init order
			__CFInitialize();
			*const_cast<CFStringRef *>(&LegacyWebArchiveMainResourceKey) = CFSTR("WebMainResource");
			*const_cast<CFStringRef *>(&LegacyWebArchiveSubresourcesKey) = CFSTR("WebSubresources");
			*const_cast<CFStringRef *>(&LegacyWebArchiveSubframeArchivesKey) = CFSTR("WebSubframeArchives");
			*const_cast<CFStringRef *>(&LegacyWebArchiveResourceDataKey) = CFSTR("WebResourceData");
			*const_cast<CFStringRef *>(&LegacyWebArchiveResourceFrameNameKey) = CFSTR("WebResourceFrameName");
			*const_cast<CFStringRef *>(&LegacyWebArchiveResourceMIMETypeKey) = CFSTR("WebResourceMIMEType");
			*const_cast<CFStringRef *>(&LegacyWebArchiveResourceURLKey) = CFSTR("WebResourceURL");
			*const_cast<CFStringRef *>(&LegacyWebArchiveResourceTextEncodingNameKey) = CFSTR("WebResourceTextEncodingName");
			*const_cast<CFStringRef *>(&LegacyWebArchiveResourceResponseKey) = CFSTR("WebResourceResponse");
			*const_cast<CFStringRef *>(&LegacyWebArchiveResourceResponseVersionKey) = CFSTR("WebResourceResponseVersion");
		}
	}LibInitializer;
}

STDAPI_(BOOL) DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID /*lpReserved*/)
{
	static WebCore::LibInitializer initializer;

    BOOL ret = FALSE;
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
			initializer.unused += 1.0;
            WebCore::setInstanceHandle(hModule);
            ret = TRUE;
            break;

        case DLL_PROCESS_DETACH:
			initializer.unused -= 1.0;
            WebCore::RenderThemeWin::setWebKitIsBeingUnloaded();
            pthread_win32_thread_detach_np ();
            break;

        case DLL_THREAD_ATTACH:
            pthread_win32_thread_attach_np ();
            break;

        case DLL_THREAD_DETACH:
            pthread_win32_thread_detach_np ();
            break;
    }

    CoreFoundationDllMain(hModule, ul_reason_for_call, 0);
    return ret;
}