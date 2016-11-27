// wchar_t.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string.h>


#define KAKA(arg) L##arg

//########################################################################
//typedef CHAR			*PCHAR;
//typedef CHAR			*PSTR;
//typedef CONST CHAR	*PCSTR
//-------------------------------------------
//typedef WCHAR			*PWCHAR;
//typedef WCHAR			*PWSTR;
//typedef CONST WCHAR	*PCWSTR;
//########################################################################

int main(int argc, char* argv[])
{
	wchar_t a[] = L"kaka";		//typedef unsigned short		wchar_t
	CHAR b[] = "kaka";			//typedef char					CHAR
	WCHAR c[] = L"kaka";		//typedef wchar_t				WCHAR

	//不管是双字节还是单字节
	TCHAR d[] = TEXT("KAKA");
	PCSTR e   = TEXT("wkdke");

#ifdef UNICODE
	cout << "unicode defined" << endl;
#endif


	return 0;

}

