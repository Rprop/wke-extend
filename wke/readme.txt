vs2015
 std::tr1::has_trivial_destructor -> std::is_trivially_default_constructible



old fix 
	add 
		DerivedNames.cpp
		DerivedResources.cpp
		DerivedCSSResources.cpp
		DerivedSVGResources.cpp
		DerivedMathMLResources.cpp

1>WebCore.lib(JSBindingsAllInOne.obj) : error LNK2001: 无法解析的外部符号 "class WebCore::JSDOMWrapper * __cdecl WebCore::createJSSVGWrapper(class JSC::ExecState *,class WebCore::JSDOMGlobalObject *,class WTF::PassRefPtr<class WebCore::SVGElement>)" (?createJSSVGWrapper@WebCore@@YAPAVJSDOMWrapper@1@PAVExecState@JSC@@PAVJSDOMGlobalObject@1@V?$PassRefPtr@VSVGElement@WebCore@@@WTF@@@Z)

	add to DerivedSources.cpp 
	\wke_release\obj\WebCore\DerivedSources\JSSVGElementWrapperFactory.cpp(598): JSDOMWrapper* createJSSVGWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
	or diable Scalable Vector Graphics (SVG) 
		add #define ENABLE_SVG 0
		change \WebKitLibraries\win\tools\props\FeatureDefinesCairo.props(50):     <ENABLE_SVG />

project wtf:
	ignore WTF_USE_ICU_UNICODE
		open \Source\JavaScriptCore\wtf\unicode\icu\CollatorICU.cpp
		add
		#undef UCONFIG_NO_COLLATION
		#define UCONFIG_NO_COLLATION 1

project WebCore:
	ignore WTF_USE_ICU_UNICODE
		open \Source\WebCore\editing\TextIterator.cpp
		add
		#undef UCONFIG_NO_COLLATION
		#define UCONFIG_NO_COLLATION 1

all project:
	PTW32_STATIC_LIB
	CURL_STATICLIB
	LIBXML_STATIC
	JS_NO_EXPORT
	U_STATIC_IMPLEMENTATION

	release:
		_NDEBUG
		NDEBUG
		ignore DEBUG_ALL

WebCore:
	WTF_USE_EXPORT_MACROS

1>WebCore.lib(ResourceHandleCurl.obj) : warning LNK4217: 本地定义的符号 _curl_slist_free_all 在函数 "public: __thiscall WebCore::ResourceHandleInternal::~ResourceHandleInternal(void)" (??1ResourceHandleInternal@WebCore@@QAE@XZ) 中导入
1>WebCore.lib(ResourceHandleCurl.obj) : warning LNK4217: 本地定义的符号 _curl_easy_pause 在函数 "private: void __thiscall WebCore::ResourceHandle::platformSetDefersLoading(bool)" (?platformSetDefersLoading@ResourceHandle@WebCore@@AAEX_N@Z) 中导入

【未处理】2>  CachedResource.cpp
2>E:\Microsoft Visual Studio 12.0\VC\include\utility(157): warning C4244: “初始化”: 从“int”转换到“float”，可能丢失数据 (..\Source\WebCore\loader\cache\CachedImage.cpp)
2>          ..\Source\WebCore\loader\cache\CachedImage.cpp(121): 参见对正在编译的函数 模板 实例化“std::pair<WebCore::Image *,float>::pair<WebCore::Image*,int,void>(std::pair<WebCore::Image *,int> &&)”的引用
2>          ..\Source\WebCore\loader\cache\CachedImage.cpp(121): 参见对正在编译的函数 模板 实例化“std::pair<WebCore::Image *,float>::pair<WebCore::Image*,int,void>(std::pair<WebCore::Image *,int> &&)”的引用
2>  CachedResourceHandle.cpp


1>..\Source\JavaScriptCore\wtf\Assertions.cpp(31): warning C4068: 未知的杂注

6>d:\release_cairo_cflite\include\webcore\CSSWrapShapes.h : warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失

5>d:\release_cairo_cflite\obj\webcore\derivedsources\jshtmlparamelement.cpp(91): fatal error C1128: 节数超过对象文件格式限制: 请使用 /bigobj 进行编译

5>..\Source\WebCore\rendering\RenderRegion.cpp : warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失

5>d:\wke\wke-master-ui\source\webcore\rendering\RenderThemeWin.h(29): fatal error C1017: 无效的整数常量表达式

5>..\Source\WebCore\rendering\RenderFlowThread.cpp : warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失

5>..\Source\WebCore\platform\win\PopupMenuWin.cpp(741): error C2065: “CS_DROPSHADOW”: 未声明的标识符

5>..\Source\WebCore\css\CSSRegionStyleRule.cpp : warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失

3>D:\wke\wke-master-ui\vs2008\props\WebCoreGeneratedCairo.props(4,5): warning MSB4011: 无法再次导入“D:\wke\wke-master-ui\vs2008\props\common.props”。可能已在“D:\wke\wke-master-ui\vs2008\props\WebCoreGeneratedCommon.props (4,5)”处导入过它。这很可能是生成创作错误。将忽略此后续导入。[D:\wke\wke-master-ui\vs2008\WebCoreGenerated.vcxproj]


3>D:\wke\wke-master-ui\Source\JavaScriptCore\wtf/MathExtras.h(144): error C2084: 函数“bool signbit(double)”已有主体
3>          E:\Microsoft Visual Studio 12.0\VC\include\math.h(324) : 参见“signbit”的前一个定义
3>D:\wke\wke-master-ui\Source\JavaScriptCore\wtf/MathExtras.h(282): error C2264: “signbit”: 函数定义或声明中有错误；未
调用函数

3>..\Source\JavaScriptCore\API\JSBase.cpp(91): warning C4273: “JSGarbageCollect”: dll 链接不一致
3>          d:\wke\wke-master-ui\source\javascriptcore\api\JSBase.h(132) : 参见“JSGarbageCollect”的前一个定义

include\private\javascriptcore\StringImpl.h(195): warning C4291: “void *WTF::StringImpl::operator new(size_t,void *)”: 未找到匹配的删除运算符；如果初始化引发异常，则不会释放内存

5>D:\wke_release\include\private\JavaScriptCore/BumpPointerAllocator.h(124): warning C4291: “void *WTF::BumpPointerPool::operator new(size_t,const WTF::PageAllocation &)”: 未找到匹配的删除运算符；如果初始化引发异常，则不会释放内存





http://blog.csdn.net/saga1979/article/details/41959197
https://qt.gitorious.org/qt/qt/commit/1bed55097b22f2071af71ebefc9897816977fd14
http://stackoverflow.com/questions/12113400/compiling-qt-4-8-x-for-visual-studio-2012/13085842#13085842

5>d:\release_cairo_cflite\include\private\javascriptcore\HashSet.h(180): error C2664: “std::pair<WTF::HashTableConstIteratorAdapter<WTF::HashTable<int,int,WTF::IdentityExtractor<int>,WTF::IntHash<unsigned int>,WTF::HashTraits<Second>,WTF::HashTraits<Second>>,int>,bool>::pair(const std::pair<WTF::HashTableConstIteratorAdapter<WTF::HashTable<int,int,WTF::IdentityExtractor<int>,WTF::IntHash<unsigned int>,WTF::HashTraits<Second>,WTF::HashTraits<Second>>,int>,bool> &)”: 无法将参数 1 从“std::pair<WTF::HashTableIterator<Key,Value,Extractor,HashFunctions,Traits,KeyTraits>,bool>”
转换为“const std::pair<WTF::HashTableConstIteratorAdapter<WTF::HashTable<int,int,WTF::IdentityExtractor<int>,WTF::IntHash<unsigned int>,WTF::HashTraits<Second>,WTF::HashTraits<Second>>,int>,bool> &”
5>          with
5>          [
5>              Second=int
5>          ]
5>          and
5>          [
5>              Key=int
5>  ,            Value=int
5>  ,            Extractor=WTF::IdentityExtractor<int>
5>  ,            HashFunctions=WTF::IntHash<unsigned int>
5>  ,            Traits=WTF::HashTraits<int>
5>  ,            KeyTraits=WTF::HashTraits<int>
5>          ]
5>          and
5>          [
5>              Second=int
5>          ]
5>          原因如下:  无法从“std::pair<WTF::HashTableIterator<Key,Value,Extractor,HashFunctions,Traits,KeyTraits>,bool>”转换为“const std::pair<WTF::HashTableConstIteratorAdapter<WTF::HashTable<int,int,WTF::IdentityExtractor<int>,WTF::IntHash<unsigned int>,WTF::HashTraits<Second>,WTF::HashTraits<Second>>,int>,bool>”
5>          with
5>          [
5>              Key=int
5>  ,            Value=int
5>  ,            Extractor=WTF::IdentityExtractor<int>
5>  ,            HashFunctions=WTF::IntHash<unsigned int>
5>  ,            Traits=WTF::HashTraits<int>
5>  ,            KeyTraits=WTF::HashTraits<int>
5>          ]
5>          and
5>          [
5>              Second=int
5>          ]
5>          没有可用于执行该转换的用户定义的转换运算符，或者无法调用该运算符
5>          d:\release_cairo_cflite\include\private\javascriptcore\HashSet.h(179): 编译类 模板 成员函数“std::pair<WTF::HashTableConstIteratorAdapter<WTF::HashTable<int,int,WTF::IdentityExtractor<int>,WTF::IntHash<unsigned int>,WTF::HashTraits<Second>,WTF::HashTraits<Second>>,int>,bool> WTF::HashSet<int,WTF::DefaultHash<int>::Hash,WTF::HashTraits<Second>>::add(const int &)”时
5>          with
5>          [
5>              Second=int
5>          ]
5>          ..\Source\WebCore\css\CSSMutableStyleDeclaration.cpp(832): 参见对正在编译的函数 模板 实例化“std::pair<WTF::HashTableConstIteratorAdapter<WTF::HashTable<int,int,WTF::IdentityExtractor<int>,WTF::IntHash<unsigned int>,WTF::HashTraits<Second>,WTF::HashTraits<Second>>,int>,bool> WTF::HashSet<int,WTF::DefaultHash<int>::Hash,WTF::HashTraits<Second>>::add(const int &)”的引用
5>          with
5>          [
5>              Second=int
5>          ]
5>          ..\Source\WebCore\css\CSSMutableStyleDeclaration.cpp(830): 参见对正在编译的类 模板 实例化“WTF::HashSet<int,WTF::DefaultHash<int>::Hash,WTF::HashTraits<Second>>”的引用
5>          with
5>          [
5>              Second=int
5>          ]







5>  DatabaseTracker.cpp
5>E:\Microsoft Visual Studio 12.0\VC\include\utility(183): warning C4503: “WTF::HashTable<WTF::RefPtr<WebCore::SecurityOrigin>,std::pair<WTF::RefPtr<WebCore::SecurityOrigin>,WTF::HashMap<WTF::String,WebCore::DatabaseTracker::DatabaseSet *,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<MappedArg>> >,WTF::PairFirstExtractor<std::pair<WTF::RefPtr<WebCore::SecurityOrigin>,WTF::HashMap<WTF::String,MappedArg,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<MappedArg>> >>,WebCore::SecurityOriginHash,WTF::PairHashTraits<WTF::HashTraits<KeyArg>,WTF::HashTraits<WTF::HashMap<WTF::String,MappedArg,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<MappedArg>>>>,WTF::HashTraits<KeyArg>>::add”: 超出修饰名的长度，名称被截断
5>          with
5>          [
5>              MappedArg=WebCore::DatabaseTracker::DatabaseSet *
5>  ,            KeyArg=WTF::RefPtr<WebCore::SecurityOrigin>
5>          ]
5>E:\Microsoft Visual Studio 12.0\VC\include\utility(183): warning C4503: “std::pair<WTF::HashTableIteratorAdapter<WTF::HashTable<WTF::RefPtr<WebCore::SecurityOrigin>,std::pair<WTF::RefPtr<WebCore::SecurityOrigin>,WTF::HashMap<WTF::String,WebCore::DatabaseTracker::DatabaseSet *,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<MappedArg>> >,WTF::PairFirstExtractor<std::pair<WTF::RefPtr<WebCore::SecurityOrigin>,WTF::HashMap<WTF::String,MappedArg,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<MappedArg>> >>,WebCore::SecurityOriginHash,WTF::PairHashTraits<WTF::HashTraits<KeyArg>,WTF::HashTraits<WTF::HashMap<WTF::String,MappedArg,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<MappedArg>>>>,WTF::HashTraits<KeyArg>>,std::pair<WTF::RefPtr<WebCore::SecurityOrigin>,WTF::HashMap<WTF::String,MappedArg,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<MappedArg>> >>,bool>::pair”: 超出修饰名的长度，名称被截断
5>          with
5>          [
5>              MappedArg=WebCore::DatabaseTracker::DatabaseSet *
5>  ,            KeyArg=WTF::RefPtr<WebCore::SecurityOrigin>
6>d:\release_cairo_cflite\include\webcore\CSSWrapShapes.h : warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
6>D:\wke_release\Include\WebCore/RenderThemeWin.h(29): fatal error C1017: 无效的整数常量表达式

6>d:\release_cairo_cflite\include\webcore\CSSWrapShapes.h : warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失

5>          ]
5>E:\Microsoft Visual Studio 12.0\VC\include\utility(183): warning C4503: “WTF::addIterator”: 超出修饰名的长度，名称被截断
5>E:\Microsoft Visual Studio 12.0\VC\include\utility(183): warning C4503: “std::make_pair”: 超出修饰名的长度，名称被截断
5>E:\Microsoft Visual Studio 12.0\VC\include\utility(183): warning C4503: “std::pair<WTF::HashTableIterator<Key,Value,Extractor,HashFunctions,Traits,KeyTraits>,bool>::pair”: 超出修饰名的长度，名称被截断
5>          with
5>          [
5>              Key=WTF::RefPtr<WebCore::SecurityOrigin>
5>  ,            Value=std::pair<WTF::RefPtr<WebCore::SecurityOrigin>,WTF::HashMap<WTF::String,WebCore::DatabaseTracker::DatabaseSet *,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<WTF::HashSet<WebCore::AbstractDatabase *,WTF::PtrHash<WebCore::AbstractDatabase *>,WTF::HashTraits<WebCore::AbstractDatabase *>> *>> *>
5>  ,            Extractor=WTF::PairFirstExtractor<std::pair<WTF::RefPtr<WebCore::SecurityOrigin>,WTF::HashMap<WTF::String,WebCore::DatabaseTracker::DatabaseSet *,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<WTF::HashSet<WebCore::AbstractDatabase *,WTF::PtrHash<WebCore::AbstractDatabase *>,WTF::HashTraits<WebCore::AbstractDatabase *>> *>> *>>
5>  ,            HashFunctions=WebCore::SecurityOriginHash
5>  ,            Traits=WTF::PairHashTraits<WTF::HashTraits<WTF::RefPtr<WebCore::SecurityOrigin>>,WTF::HashTraits<WTF::HashMap<WTF::String,WebCore::DatabaseTracker::DatabaseSet *,WTF::DefaultHash<WTF::String>::Hash,WTF::HashTraits<WTF::String>,WTF::HashTraits<WTF::HashSet<WebCore::AbstractDatabase *,WTF::PtrHash<WebCore::AbstractDatabase *>,WTF::HashTraits<WebCore::AbstractDatabase *>> *>> *>>
5>  ,            KeyTraits=WTF::HashTraits<WTF::RefPtr<WebCore::SecurityOrigin>>
5>          ]
5>  IDBAny.cpp











compile wke:
1>WebCore.lib(Frame.obj) : error LNK2001: 无法解析的外部符号 "void __cdecl WebCore::WebKitFontFamilyNames::init(void)" (?init@WebKitFontFamilyNames@WebCore@@YAXXZ)
1>WebCore.lib(Frame.obj) : error LNK2001: 无法解析的外部符号 "void __cdecl WebCore::HTMLNames::init(void)" (?init@HTMLNames@WebCore@@YAXXZ)
1>WebCore.lib(Frame.obj) : error LNK2001: 无法解析的外部符号 "void __cdecl WebCore::XMLNSNames::init(void)" (?init@XMLNSNames@WebCore@@YAXXZ)
1>WebCore.lib(Frame.obj) : error LNK2001: 无法解析的外部符号 "void __cdecl WebCore::XMLNames::init(void)" (?init@XMLNames@WebCore@@YAXXZ)
1>WebCore.lib(Frame.obj) : error LNK2001: 无法解析的外部符号 "void __cdecl WebCore::MathMLNames::init(void)" (?init@MathMLNames@WebCore@@YAXXZ)
1>WebCore.lib(Frame.obj) : error LNK2001: 无法解析的外部符号 "void __cdecl WebCore::SVGNames::init(void)" (?init@SVGNames@WebCore@@YAXXZ)
1>WebCore.lib(Frame.obj) : error LNK2001: 无法解析的外部符号 "void __cdecl WebCore::XLinkNames::init(void)" (?init@XLinkNames@WebCore@@YAXXZ)
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _ucol_getStrength_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _ucol_setStrength_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_open_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_setOffset_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_getMatchedLength_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_setText_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_getCollator_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_setPattern_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_next_4_0
1>WebCore.lib(EditingAllInOne.obj) : error LNK2001: 无法解析的外部符号 _usearch_reset_4_0
1>WebCore.lib(ScriptValue.obj) : error LNK2001: 无法解析的外部符号 __imp__JSValueIsEqual1>WebCore.lib(CSSParser.obj) : error LNK2001: 无法解析的外部符号 "struct WebCore::Property const * __cdecl WebCore::findProperty(char const *,unsigned int)" (?findProperty@WebCore@@YAPBUProperty@1@PBDI@Z)
1>WebCore.lib(CSSParser.obj) : error LNK2001: 无法解析的外部符号 "struct WebCore::Value const * __cdecl WebCore::findValue(char const *,unsigned int)" (?findValue@WebCore@@YAPBUValue@1@PBDI@Z)
1>WebCore.lib(CSSParser.obj) : error LNK2001: 无法解析的外部符号 "int __cdecl cssyyparse(void *)" (?cssyyparse@@YAHPAX@Z)
1>WebCore.lib(ResourceHandleManager.obj) : error LNK2001: 无法解析的外部符号 __imp__curl_version_info
1>WebCore.lib(XPathParser.obj) : error LNK2001: 无法解析的外部符号 "int __cdecl xpathyyparse(void *)" (?xpathyyparse@@YAHPAX@Z)