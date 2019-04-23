#include "tools.h"
#include "conio.h"
void WritetoPos(SHORT x, SHORT y, string str)			//在指定位置输出字符
{
	COORD pos = { x*2 ,y };										//获取坐标
	///注意：光标移动的距离是一个字符的宽度，而■的宽度是两个字符，所以要在循环中光标一次移动两个宽度
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	//获取标准输出流的句柄
	SetConsoleCursorPosition(hOut,pos);				//将坐标移动至指定位置
	cout.width(2);									//设置字符宽度为2
	cout << str;
}

int WaitKey()										//非阻塞式等待用户输入
{
	
	if (_kbhit())
		return _getch();
	return 0;
}

void DisShowCursor()								//隐藏光标
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	//获得标准输出的句柄
	CONSOLE_CURSOR_INFO cci;						//创建控制台光标信息结构
	cci.bVisible = 0;								//0为不显示，0以外任何正整数都为显示
	cci.dwSize = 1;									//设置光标宽度，必须为大于0的整数，否则bvisible设置为无效
	SetConsoleCursorInfo(hOut, &cci);				//设置光标
}
