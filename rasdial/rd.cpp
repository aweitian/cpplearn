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
	
	//������Զ��뽫����Ĵ���ֱ���滻������û��������� 
	
	RASDIALPARAMSA rdParams;
	rdParams.dwSize=sizeof(RASDIALPARAMSA);
	strcpy(rdParams.szEntryName,"�������over vpn"); //������������Ĳ�������
	rdParams.szPhoneNumber[0]='\0';
	rdParams.szCallbackNumber[0]='\0';
	strcpy(rdParams.szUserName,user);
	strcpy(rdParams.szPassword,pass);
	rdParams.szDomain[0]='\0';
	HRASCONN hRscon=NULL;
	DWORD retn= RasDialA(NULL,NULL,&rdParams,0L,NULL,&hRscon); 
	
	if (retn==0)
	{
		printf("�Ѿ�������...\n");
		//�Ͽ�����
		/*
		DWORD off= RasHangUp(&hRscon);
		if (off==0)
		{
			printf("�����ѶϿ�...\n");
		}
		else
			printf("�Ͽ����ӳ���...\n");
		*/
		//�����ϸ�����������...������ʾһ��...
		return 0;
	}
	printf("���ӳ���...\n");
	return 0;
}