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
	//--编写socket简单服务器--//
	
	//1.创建socket套接字
	SOCKET listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//unsigned int listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//创建套接口
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4527);//host(主机) to net(网络) s(short)

	_sin.sin_addr.S_un.S_addr = INADDR_ANY;//INADDR_ANY:
	//_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	//2.bind绑定用于接受客户端连接的网络端口
	
	auto BINDCODE = bind(listenfd, (sockaddr* )&_sin, sizeof(_sin));
	if (SOCKET_ERROR == BINDCODE)
	{
		std::cerr << "ERROR,绑定端口失败！";
	}
	else
	{
		std::cerr << "绑定端口成功..."<<std::endl;
	}
	//3. listen 监听网络端口
	if(SOCKET_ERROR==listen(listenfd, 5))
	{
		std::cerr << "ERROR,监听端口失败！";
	}
	else
	{
		std::cerr << "监听端口成功..." << std::endl;
	}

	//4.accept 等待客户端连接，连接后会返回客户端的套接字
	//创建套接口
	sockaddr_in _clisin = {};
	int SOCKADDRLEN = sizeof(sockaddr_in);
	SOCKET connfd = INVALID_SOCKET;
	
	char msgBuff[] = "Hello I'm Server";
	
	while (true)
	{
		connfd = accept(listenfd, (sockaddr*)&_clisin, &SOCKADDRLEN);
		if (INVALID_SOCKET == connfd)
		{
			std::cerr << "ERROR,接收到无效客户端socket！";
		}
		std::cout << "有新的连接，客户端套接字为：" << connfd << " 地址IP：" << inet_ntoa(_clisin.sin_addr) << std::endl;
		//连接到的客户端的套接字与客户端本身的套接字不相同！！！！
		//5. send 向客户端发送数据
		
		send(connfd, msgBuff, strlen(msgBuff) + 1, 0);

	}
	
	//6. 关闭套接字
	closesocket(listenfd);

	/*******************************/
	WSACleanup();//用于关闭WINDOWS平台下SOCKET的API
	/*******************************/
	std::cin.get();
	return 0;
}