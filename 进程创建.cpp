#include "pch.h"
#include <windows.h>
#include <stdio.h>

int main(int agrc,char *argv[]) {
	char szCommandLine[] = "cmd";//若果使用Unicode字符集会导致12行szCommandLine处char[4]与LPSTR不兼容
	STARTUPINFO si = {sizeof(si)};
	PROCESS_INFORMATION pi;
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;

	BOOL bRet = ::CreateProcess(NULL,szCommandLine,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
	if (bRet != NULL) {
		::CloseHandle(pi.hThread);
		::CloseHandle(pi.hProcess);
		printf("新的进程的ID号：%d\n",pi.dwProcessId);
		printf("新的进程的主线程ID号：%d\n",pi.dwThreadId);
	}
	return 0;
}
