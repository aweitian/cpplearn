// rd.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include <windows.h>
#include <stdio.h>
#include <Ras.h>

#pragma comment(lib,"rasapi32.lib") 

int main(int argc,char *argv[])
{
	printf("UserName:"); 
	char user[100]={"t6330633287702"};
	//scanf("%s",user);
	printf("PassWord:");
	char pass[100]={"777788"};
	//scanf("%s",pass); 
	
	//如果想自动请将上面的代码直接替换成你的用户名和密码 
	
	RASDIALPARAMSA rdParams;
	rdParams.dwSize=sizeof(RASDIALPARAMSA);
	strcpy(rdParams.szEntryName,"宽带连接over vpn"); //连接名称是你的拨号名称
	rdParams.szPhoneNumber[0]='\0';
	rdParams.szCallbackNumber[0]='\0';
	strcpy(rdParams.szUserName,user);
	strcpy(rdParams.szPassword,pass);
	rdParams.szDomain[0]='\0';
	HRASCONN hRscon=NULL;
	DWORD retn= RasDialA(NULL,NULL,&rdParams,0L,NULL,&hRscon); 
	
	if (retn==0)
	{
		printf("已经连接上...\n");
		//断开函数
		/*
		DWORD off= RasHangUp(&hRscon);
		if (off==0)
		{
			printf("连接已断开...\n");
		}
		else
			printf("断开连接出错...\n");
		*/
		//具体的细节慢慢扩充吧...仅仅演示一下...
		return 0;
	}
	printf("连接出错...\n");
	return 0;
}