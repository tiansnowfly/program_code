#include "pch.h"
#include <windows.h>
#include <iostream>
using namespace std;
DWORD sum;

DWORD WINAPI Summation(LPVOID Param) {
	for (DWORD i = 0; i < 20; ++i) sum += i;
	return sum;
}

int main(int argc, char *argv[]) {
	DWORD ThreadId;
	HANDLE ThreadHandle;//句柄，四字节长的唯一的数字，用以标识许多不同对象类型，可以运行一个或多个程序的副本
	ThreadHandle = CreateThread(NULL,0,Summation,NULL,0,&ThreadId);
	if (ThreadHandle != NULL) WaitForSingleObject(ThreadHandle,INFINITE);
	CloseHandle(ThreadHandle);
	cout <<"sum=" <<sum << endl;
	return 0;
}