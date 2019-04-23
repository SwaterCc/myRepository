#include "control.h"
#include "tools.h"
#include"game.h"
#include"food.h"
#include"map.h"
#include"snake.h"

inline string Control::selected(string str)
{
	string newstr = str;
	newstr = "→ 【 " + newstr + " 】 ←";
	return newstr;
}
void Control::MenuInput(int ch)
{
	
	
	//通过上下键选择难度
	switch (ch)
	{
	case'w':
	case 72:
		if (modenum == 0)
			break;
		modenum--;
		break;
	case's':
	case 80:
		if (modenum == 3)
			break;
		modenum++;
		break;
	default:
		break;
	}
	
}
void Control::begin()const
{
	DisShowCursor();
	system("mode con cols=143 lines=35");
	int count=1;
	WritetoPos(15, 10, "         ||||||||||||||||||||||||||||||||||||||||||      !!!!!!!!!!!!!!!!!!!!!!!");
	WritetoPos(15, 11, "        |||||||||||||||||||||||||||||||||||||||||||||    |||||||||||||||||||||||");
	WritetoPos(15, 12, "       ||||||              |||||||             |||||||   |||||||||||||||||||||||"); 
	WritetoPos(15, 13, "      |||||||||!!!!!!!!!   ||||||||||||||||||||||||||   |||||||                 ");
	WritetoPos(15, 14, "     |||||||||||||||||||!  |||||||||||||||||!!!!!!!!    |||||||     !!!!!!!!!!  ");
	WritetoPos(15, 15, "                 ||||||||! ||||||!   ||||||!           |||||||      |||||||||!  ");
	WritetoPos(15, 16, "                |||||||!   ||||||!     |||||||!!       |||||||          |||||!  ");
	WritetoPos(15, 17, "   ||||||||||||||||||||    ||||||!         ||||||!!   ||||||||||||||||||||||!   ");
	WritetoPos(15, 18, "  ||||||||||||||||||||     ||||||!            ||||||||||||||||||||||||||||||!   ");
	WritetoPos(15, 19, " =============================================================================== ");
	WritetoPos(15, 20, " =============================================================================== ");
	WritetoPos(15, 21, "                                   ============================================");
	WritetoPos(15, 22, "                                   ============================================");
	
	while (true)
	{
		if (count % 2 != 0)
			WritetoPos(33, 25, " 开  始  游  戏 ");
		else
			WritetoPos(33, 25, "                ");
		count++;
		Sleep(400);
		if (WaitKey())
			break;
	}

}

void Control::menu()
{
	//选择难度
	string Mode[4];
	Mode[0] = "简  单  模  式";
	Mode[1] = "普  通  模  式";
	Mode[2] = "困  难  模  式";
	Mode[3] = "难  度  说  明";

	
//设置选择界面
	system("mode con cols=143 lines=35");
	DisShowCursor();
	//设置选中和未选中的状态
	
	string temp;
	int ch = 0;
	while (ch != 13)
	{	//回车键确认难度
		switch (modenum)
		{
		case 0:
			temp = selected(Mode[0]);
			WritetoPos(29, 6, temp);
			WritetoPos(32, 9, Mode[1]);
			WritetoPos(32, 12, Mode[2]);
			WritetoPos(32, 28, Mode[3]);
			break;
		case 1:
			temp = selected(Mode[1]);
			WritetoPos(32, 6, Mode[0]);
			WritetoPos(29, 9, temp);
			WritetoPos(32, 12, Mode[2]);
			WritetoPos(32, 28, Mode[3]);
			break;
		case 2:
			temp = selected(Mode[2]);
			WritetoPos(32, 6, Mode[0]);
			WritetoPos(32, 9, Mode[1]);
			WritetoPos(29, 12, temp);
			WritetoPos(32, 28, Mode[3]);
			break;
		case 3:
			temp = selected(Mode[3]);
			WritetoPos(32, 6, Mode[0]);
			WritetoPos(32, 9, Mode[1]);
			WritetoPos(32, 12, Mode[2]);
			WritetoPos(29, 28, temp);
			break;
		}

		ch = _getch();
		if (ch == 224)
			ch = _getch();
		MenuInput(ch);
		
		system("CLS");
	}
	
	if (modenum == 3)
	{
		GameExplain();
	}
	SetSpeed(modenum);
}

void Control::GameStart()
{
	system("mode con cols=150 lines=31");
	DisShowCursor();

	Map map;
	map.InitMap(GameMap);
	map.DrawMap(GameMap);
	Food food;

	Snake snake;
	bool flag = true;
	show();
	char inte[20]="";
	while (flag)
	{
		sprintf_s(inte, "%d", integral);
		WritetoPos(62, 6, inte);
		food.CreateFood(GameMap);
		food.CreateToxicFood(GameMap);

		snake.Clear(GameMap);
		flag = snake.Move(GameMap, food, integral);
		snake.DrawSnake();

		snake.GetPlayerInput();


		Sleep(speed);


	}

}

bool Control::EndGame()
{
	DisShowCursor();
	system("mode con cols=150 lines=31");
	int ch = 0;
	string str[2] = {"退出","再来一局"};
	int n = 0;
	bool flag=false;
	while (ch != 13)
	{
		switch (ch)
		{
		case 75:
			if (n == 1)
				n--;
			break;
		case 77:
			if (n == 0)
				n++;
			break;
		default:
			break;
		}
		switch (n)
		{
		case 0:
			WritetoPos(32, 6, "游  戏  结  束");
			WritetoPos(21, 10, selected(str[0]));
			WritetoPos(41, 10, str[1]);
			flag = false;
			break;

		case 1:

			WritetoPos(32, 6, "游  戏  结  束");
			WritetoPos(24, 10, str[0]);
			WritetoPos(38, 10, selected(str[1]));
			flag = true;
			break;

		default:
			break;
		}
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		system("CLS");
	}

	return flag;
}

void Control::show()
{
	WritetoPos(54, 6, "当前游戏积分：");
	WritetoPos(54, 10, "控制移动：");
	WritetoPos(54, 12, "    w,a,s,d 或者");
	WritetoPos(54, 14, "    ↑，↓，←，→");
	WritetoPos(54, 18, "关于食物：");
	WritetoPos(54, 20, "   ★是正常食物，吃下后会增长长度");
	WritetoPos(54, 22, "   ☆是有毒食物，吃下后当场去世");
}

void Control::GameExplain()
{
	DisShowCursor();
	system("mode con cols=150 lines=31");
	WritetoPos(32,6,"制作者 ： 石睿");
	WritetoPos(32, 20, "贪吃蛇还要人教你玩吗？？？？？？");
	WritetoPos(32, 22, "按任意键返回");
	_getch();
	_getch();
		menu();
}

void Control::GamePlay()
{
	begin();
	bool flag = true;
	while (flag)
	{
		menu();
		GameStart();
		flag=EndGame();
	}
}


void Control::SetSpeed(int flag)
{//数值越高速度越慢
	if (flag == 0)
	{
		speed = 80;			//设置初始速度
	}
	if (flag == 1)
	{
		speed = 60;			//设置初始速度
	}
	if (flag == 2)
	{
		speed = 40;			    //设置初始速度
	}
}
