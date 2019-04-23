#define WIN32_LEAN_AND_MEAN	
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//这个宏用来避免宏定义重复
#include<iostream>

#include<windows.h>
#include<WinSock2.h>


#pragma comment(lib,"ws2_32.lib")
//导入静态链接库来使用WSAStartup函数

int main()
{
	/*******************************/
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	/******************************/
	//用于启动WINDOWS平台下SOCKET的API

	//编写自己的代码
	//--用socket API 建立一个客户端
	//1.创建一个socket套接字
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockfd)
	{
		std::cerr << "ERROR,创建套接字失败" << std::endl;
	}
	std::cout << "客户端套接字：" << sockfd << std::endl;
	// 创建一个套接口结构
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4527);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	//2.连接服务器
	int ret = connect(sockfd, (sockaddr *)&_sin, sizeof(_sin));
	if (SOCKET_ERROR == ret)
		std::cerr << "连接失败..." << std::endl;
	
	//3.接收服务器信息
	char recvBuff[256] = {};
	if (recv(sockfd, recvBuff, sizeof(recvBuff) / sizeof(char), 0) >= 0)
		std::cout << recvBuff << std::endl;
	else
		std::cerr << "接收失败..." << std::endl;
	//4.关闭连接closesocket
	closesocket(sockfd);
	/*******************************/
	WSACleanup();//用于关闭WINDOWS平台下SOCKET的API
	/*******************************/
	std::cin.get();
	return 0;
}