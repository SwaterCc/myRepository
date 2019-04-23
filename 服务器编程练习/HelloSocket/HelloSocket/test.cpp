#define WIN32_LEAN_AND_MEAN	
//这个宏用来避免宏定义重复
#include<iostream>

#include<windows.h>
#include<WinSock2.h>


#pragma comment(lib,"ws2_32.lib")
//导入静态链接库来使用WSAStartup函数

int main()
{
	/*******************************/
	WORD ver = MAKEWORD(2,2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	/******************************/
	//用于启动WINDOWS平台下SOCKET的API

	//编写自己的代码




	/*******************************/
	WSACleanup();//用于关闭WINDOWS平台下SOCKET的API
	/*******************************/
	std::cin.get();
	return 0;
}