#pragma once
#include"game.h"
#include"windows.h"
void WritetoPos(SHORT x, SHORT y,string str);	//在指定位置输出字符
int WaitKey();									//非阻塞式等待用户键盘输入
void DisShowCursor();							//隐藏光标