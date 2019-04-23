#include "snake.h"
#include"tools.h"
#include"map.h"
#include"control.h"
void Snake::InitSnake(SNAKECOORD &sc,SHORT x,SHORT y,int ter)
{
	sc.pos = {x,y};
	sc.terrain = ter;
}

Snake::Snake()
{//初始化蛇
	//初始化蛇的长度
	slen = 3;
	//初始化蛇的坐标
	for (int i = 0; i < slen; i++)
	{
		InitSnake(Csnake[i],30-i,20,Map::蛇);
	}
	//初始化蛇的方向
	ndir = 右;
}

void Snake::DrawSnake()
{
	WritetoPos(Csnake[0].pos.X, Csnake[0].pos.Y, "●");
	for (int i = 1; i < slen; i++)
	{
		WritetoPos(Csnake[i].pos.X, Csnake[i].pos.Y, "○");
	}
}

void Snake::Clear(int map[MAX_LINES][MAX_COLS])
{
	WritetoPos(Csnake[slen - 1].pos.X, Csnake[slen - 1].pos.Y, " ");
	map[Csnake[slen - 1].pos.Y][Csnake[slen - 1].pos.X] = Map::空地;
}

bool Snake::Move(int map[MAX_LINES][MAX_COLS],Food &food,int &integral)
{
	SNAKECOORD temp;
	temp = Csnake[0];
	switch (ndir)
	{
	case 上:
		temp.pos.Y--;
		break;
	case 下:
		temp.pos.Y++;
		break;
	case 左:
		temp.pos.X--;
		break;
	case 右:
		temp.pos.X++;
		break;
	default:
		break;
	}
	
	if (map[temp.pos.Y][temp.pos.X] == Map::空地)
	{
		map[temp.pos.Y][temp.pos.X] = Map::蛇;
	}
	else if 
		(
		map[temp.pos.Y][temp.pos.X] == Map::障碍物|| 
		map[temp.pos.Y][temp.pos.X] == Map::蛇|| 
		map[temp.pos.Y][temp.pos.X] == Map::毒食物
		)
	{
		return false;
	}
	else if (map[temp.pos.Y][temp.pos.X] == Map::食物)
	{
		slen++;
		integral += 20;
		food.SetFoodnum(0);
		map[temp.pos.Y][temp.pos.X] = Map::蛇;
	}
	
	for (int i = slen - 1; i > 0; i--)
	{
		Csnake[i] = Csnake[i-1];
	}

	Csnake[0] = temp;
	return true;
}

void Snake::GetPlayerInput()
{
	
	char ch = 0;
	ch = WaitKey();
	switch (ch)
	{
	case'w':
	case 72:
		if (ndir != 下)
			ndir = 上;
		break;
	case's':
	case 80:
		if (ndir != 上)
			ndir = 下;
		break;
	case'a':
	case 75:
		if (ndir != 右)
			ndir = 左;
		break;
	case'd':
	case 77:
		if (ndir != 左)
			ndir = 右;
		break;
	}
}
