#include <windows.h>
#include <iostream.h>
//########################################
//完成输入ERROR CODE，输出错误信息
//########################################


//HANDLE类型无效时有两种，一种为NULL,一种为INVALID_HANDLE_VALUE，它被定义为-1
//PVOID类型无效为NULL

int main()
{

	int dwError;
	HLOCAL hlocal = NULL;

	//Creates a language identifier from a primary language identifier and a sublanguage identifier.
	DWORD systemLocale = MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL);

	while(TRUE)
	{
		cout << "请输入ERROR CODE:" << endl;
		cin >> dwError;
		if(dwError == 0)break;
		//这个函数是用来格式化消息字符串，就是处理消息资源的。
		//消息资源是由mc.exe编译的，详细请在msdn中搜索mc.exe。
		BOOL fOk = FormatMessage(
			FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER,
			NULL,
			dwError,
			systemLocale,
			(PTSTR) & hlocal,
			0,
			NULL
		);

		if(!fOk)
		{
			HMODULE hDll = LoadLibraryEx(TEXT("netmsg.dll"), NULL, DONT_RESOLVE_DLL_REFERENCES);
			if (hDll != NULL)
			{
				fOk = FormatMessage(
					FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER,
					hDll,
					dwError,
					systemLocale,
					(PTSTR) & hlocal,
					0,
					NULL
				);
				FreeLibrary(hDll);
			}
		}

		if(fOk && (hlocal != NULL))
		{
			cout << (LPCTSTR)LocalLock(hlocal) << endl;
			LocalFree(hlocal);
		}
		else
		{
			cout << "NOT FOUND" << endl;
		}
	}
	
	

	

	return 1;
}

void extra_info()
{
//	SetLastError(0x2010fb10);
//	HANDLE h = CreateFile(TEXT("c:\\taw"),0,0,NULL,OPEN_EXISTING,0,NULL);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息 
	GetConsoleScreenBufferInfo(hOut, &bInfo ); 
	// 获取窗口缓冲区信息 
	char strTitle[255]; 
	GetConsoleTitle(strTitle, 255); // 获取窗口标题 
	cout << "当前窗口标题是:" << strTitle << endl; 

}