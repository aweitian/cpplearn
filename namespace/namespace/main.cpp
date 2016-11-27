#include <iostream>
#include <windows.h>
#include <ShlwApi.h>
using namespace std;

int main() 
{
	TCHAR buf[9];
	PCTSTR p = TEXT("TIANANWEI");
//	MessageBox(0,p,TEXT("title"),0);
	
	char atest[] = "测试1234";
	DWORD ws;
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),atest,strlen(atest),&ws,NULL);
	
	//_tcscpy_s(buf,_countof(p),p);

	WCHAR test[] = L"TIANANWEI";
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),test,wcslen(test),&ws,0);

	/*
	printf("%d\n",CompareStringOrdinal(
		TEXT("TIANANWEI"),
		_countof(TEXT("TIANANWEI")),
		p,
		_countof(p),
		TRUE
		)
	);
	*/
	system("pause");
	return 0;
}


/*
前言：从Windows NT/2000开始，Windows系统已经是一个标准的UNICODE系统，系统内部所有字符串存储及操作均使用UNICODE编码。因此Win32 API都是UNICODE版本的，但为了更好的本地化支持，也提供了MBCS(ANSI)版的Win32 API。UNICODE版Win32 API形式为xxxW，W（Wide)代表宽字符;MBCS(ANSI)版Win32 API形式为xxxA，A即ANSI。xxxA形式的Win32 API在被调用时，会先根据“代码页转换表”执行由ANSI——UNICODE的转换，然后再调用xxxW形式的Win32 API去执行实际操作。即xxxA形式的Win32 API在被调用时只是先执行ANSI——UNICODE转换功能，然后再调用xxxA形式的Win32 API。

 　　同样，Windows控制台也是标准的UNICODE系统功能，也有xxxA，xxxW两种对其操作的Win32 API，下面以WriteConsole为例。它也存在WriteConsoleA和WriteConsoleW两上版本，但我们在MSDN中找不到这两个原型，可以在C:\Program Files\Microsoft Visual Studio\VC98\Include\WINCON.H可以发现它的定义，并可以发现对它们进行控制的预定义语句。

#ifdef UNICODE

#define WriteConsole WriteConsoleW

#else

#define WriteConsole WriteConsoleA

#endif

一、Windows控制台输出

我们可以通过下面代码进行测试：

wchar_t test[] = L"测试1234";
DWORD ws;
WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),test,wcslen(test),&ws,NULL);

//正确输出“测试1234”

char test[] = "测试1234";
DWORD ws;
WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),test,wcslen(test),&ws,NULL);

//正确输出“测试1234”

若我们调用C库函数，可能会遇到点问题：

char test[] = "测试1234";

printf(test);

cout<<test;

//正确输出“测试1234”

wchar_t test[] = L"测试1234";

wprintf(test);

wcout<<test;

//什么也没输出

　　这是因为wprintf、wcout并不是真是意义上的支持UNICODE，它和printf、wcout一样内部调用都是xxxA版的Win32 API（如WriteConsoleA），只不过它们是先依据指定的“代码页转换表”，把UNICODE字符串转化为ANSI字符串，再去调用xxxA版的Win32 API。

setlocale(LC_ALL,"chs");

wchar_t test[] = L"测试1234";

wprintf(test);

wcout<<test;

//正确输出“测试1234”

整个过程可以这样描述：

GBK——————UNICODE ——————GBK——————UNICODE——————

L""                        wcout　　                     xxxA API     　　　xxxW API

 二、Windows控制台输入

　　仅从编码方式上讲，在Windows控制台进行字符输入，和在记事本、WORD中进行字符输入是一样的，字符存储的编码由输入法的编码方式决定。在简体中文XP上，我们使用“智能ABC”在文本中输入“ab中国”，当以二进制方式打开时，可以发现里面的二进制内容(GBK编码)为：

61　62　D6 D0 B9 FA

a      b     中　    国

只是我们可以在取得到字符的内存拷贝后，可以用相关函数进行转换和操作。

三、文件的读写

 　　与其它关系到系统显示或控制函数不同，文件的读写函数不会关心系统的字符编码方式，只是的执行“内存——外存”的字节拷贝，与字符集的使用无关，故只提供了一个版本。但有意思的是文件的创建和删除都有两版本，因为它涉及到了系统内部编码。

CreateFileA CreateFileW

DeleteFileA DeleteFileW 

ReadFile　

WriteFile

　　我们应注意“字符的存储”与“字符的显示”在编码方式上是独立的。例如使用UNICODE编码的Windows系统，“字符的显示”当然是UNICODE编码，但“字符的存储”则由用户决定，可以是ANSI(GB2312, GBK, JIS……）、也可以是UTF-16、UTF-32、UTF-8等。当采用非UNICODE编码并调用xxxA形式的win32 API时，Windows在显示时会先根据“代码页转换表”执行由ANSI——UNICODE的转换。


  */