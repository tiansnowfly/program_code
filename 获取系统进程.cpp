#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>

int main(int argc,char *argv[]) {
	PROCESSENTRY32 pe32;
	pe32.dwSize=sizeof(pe32);
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if (hProcessSnap == INVALID_HANDLE_VALUE) {
		printf("Create Toolhelp32napshot调用失败！\n");
	}
	BOOL bMore = ::Process32First(hProcessSnap,&pe32);
	while (bMore) {
		printf("进程名称：%\n",pe32.szExeFile);
		printf("进程ID：%\n",pe32.th32ProcessID);
		bMore = ::Process32Next(hProcessSnap,&pe32);
	}
	::CloseHandle(hProcessSnap);
	return 0;
}
