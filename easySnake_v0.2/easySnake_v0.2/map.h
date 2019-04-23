#pragma once
#include"game.h"
#include"control.h"





class Map
{
private:
	
public:
	//属性
	enum {
		空地 = 1,
		食物 = 2,
		蛇 = 3,
		障碍物 = 4,
		毒食物 = 5
	};
	
public:
	void InitMap(int GameMap[MAX_LINES][MAX_COLS]);		//初始化地图
	void DrawMap(int GameMap[MAX_LINES][MAX_COLS]);		//画出地图
};