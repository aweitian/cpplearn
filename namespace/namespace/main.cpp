#include <iostream>
#include <windows.h>
#include <ShlwApi.h>
using namespace std;

int main() 
{
	TCHAR buf[9];
	PCTSTR p = TEXT("TIANANWEI");
//	MessageBox(0,p,TEXT("title"),0);
	
	char atest[] = "����1234";
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
ǰ�ԣ���Windows NT/2000��ʼ��Windowsϵͳ�Ѿ���һ����׼��UNICODEϵͳ��ϵͳ�ڲ������ַ����洢��������ʹ��UNICODE���롣���Win32 API����UNICODE�汾�ģ���Ϊ�˸��õı��ػ�֧�֣�Ҳ�ṩ��MBCS(ANSI)���Win32 API��UNICODE��Win32 API��ʽΪxxxW��W��Wide)������ַ�;MBCS(ANSI)��Win32 API��ʽΪxxxA��A��ANSI��xxxA��ʽ��Win32 API�ڱ�����ʱ�����ȸ��ݡ�����ҳת����ִ����ANSI����UNICODE��ת����Ȼ���ٵ���xxxW��ʽ��Win32 APIȥִ��ʵ�ʲ�������xxxA��ʽ��Win32 API�ڱ�����ʱֻ����ִ��ANSI����UNICODEת�����ܣ�Ȼ���ٵ���xxxA��ʽ��Win32 API��

 ����ͬ����Windows����̨Ҳ�Ǳ�׼��UNICODEϵͳ���ܣ�Ҳ��xxxA��xxxW���ֶ��������Win32 API��������WriteConsoleΪ������Ҳ����WriteConsoleA��WriteConsoleW���ϰ汾����������MSDN���Ҳ���������ԭ�ͣ�������C:\Program Files\Microsoft Visual Studio\VC98\Include\WINCON.H���Է������Ķ��壬�����Է��ֶ����ǽ��п��Ƶ�Ԥ������䡣

#ifdef UNICODE

#define WriteConsole WriteConsoleW

#else

#define WriteConsole WriteConsoleA

#endif

һ��Windows����̨���

���ǿ���ͨ�����������в��ԣ�

wchar_t test[] = L"����1234";
DWORD ws;
WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),test,wcslen(test),&ws,NULL);

//��ȷ���������1234��

char test[] = "����1234";
DWORD ws;
WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),test,wcslen(test),&ws,NULL);

//��ȷ���������1234��

�����ǵ���C�⺯�������ܻ����������⣺

char test[] = "����1234";

printf(test);

cout<<test;

//��ȷ���������1234��

wchar_t test[] = L"����1234";

wprintf(test);

wcout<<test;

//ʲôҲû���

����������Ϊwprintf��wcout���������������ϵ�֧��UNICODE������printf��wcoutһ���ڲ����ö���xxxA���Win32 API����WriteConsoleA����ֻ����������������ָ���ġ�����ҳת��������UNICODE�ַ���ת��ΪANSI�ַ�������ȥ����xxxA���Win32 API��

setlocale(LC_ALL,"chs");

wchar_t test[] = L"����1234";

wprintf(test);

wcout<<test;

//��ȷ���������1234��

�������̿�������������

GBK������������UNICODE ������������GBK������������UNICODE������������

L""                        wcout����                     xxxA API     ������xxxW API

 ����Windows����̨����

�������ӱ��뷽ʽ�Ͻ�����Windows����̨�����ַ����룬���ڼ��±���WORD�н����ַ�������һ���ģ��ַ��洢�ı��������뷨�ı��뷽ʽ�������ڼ�������XP�ϣ�����ʹ�á�����ABC�����ı������롰ab�й��������Զ����Ʒ�ʽ��ʱ�����Է�������Ķ���������(GBK����)Ϊ��

61��62��D6 D0 B9 FA

a      b     �С�    ��

ֻ�����ǿ�����ȡ�õ��ַ����ڴ濽���󣬿�������غ�������ת���Ͳ�����

�����ļ��Ķ�д

 ������������ϵ��ϵͳ��ʾ����ƺ�����ͬ���ļ��Ķ�д�����������ϵͳ���ַ����뷽ʽ��ֻ�ǵ�ִ�С��ڴ桪����桱���ֽڿ��������ַ�����ʹ���޹أ���ֻ�ṩ��һ���汾��������˼�����ļ��Ĵ�����ɾ���������汾����Ϊ���漰����ϵͳ�ڲ����롣

CreateFileA CreateFileW

DeleteFileA DeleteFileW 

ReadFile��

WriteFile

��������Ӧע�⡰�ַ��Ĵ洢���롰�ַ�����ʾ���ڱ��뷽ʽ���Ƕ����ġ�����ʹ��UNICODE�����Windowsϵͳ�����ַ�����ʾ����Ȼ��UNICODE���룬�����ַ��Ĵ洢�������û�������������ANSI(GB2312, GBK, JIS��������Ҳ������UTF-16��UTF-32��UTF-8�ȡ������÷�UNICODE���벢����xxxA��ʽ��win32 APIʱ��Windows����ʾʱ���ȸ��ݡ�����ҳת����ִ����ANSI����UNICODE��ת����


  */