#pragma once
/*食物性质：
	1.随机刷新在地图上
	2.在被吃掉前不刷新
	3.
*/
#include"game.h"
#include"control.h"

class Food
{
private:
	int foodnum;
	int toxicfoodnum;
	COORD foodpos;
	COORD toxicpos;
	void CreateFoodCoord(COORD &);	//创建一个食物的坐标

public:
	Food();		//构造函数
	
	void CreateFood(int map[MAX_LINES][MAX_COLS]);//创建一个食物
	void CreateToxicFood(int map[MAX_LINES][MAX_COLS]);	//创建一个毒食物
	//GET和SET

	int Foodnum() { return foodnum; }
	int ToxicFoodnum() { return toxicfoodnum; }

	void SetFoodnum(int f) { foodnum = f; }
	void SetToxicFoodnum(int tf) { toxicfoodnum = tf; }
};