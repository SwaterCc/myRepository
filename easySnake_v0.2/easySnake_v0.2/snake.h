#pragma once
#include"game.h"
#include"map.h"
#include"food.h"
typedef struct SNAKECOORD
{
	COORD pos;
	int terrain;
}SNAKECOORD;

const int MAXLEN = 100;			//蛇的最大长度


class Snake
{
private:
	SNAKECOORD Csnake[MAXLEN];	//蛇
	int slen;
	int ndir;
	void InitSnake(SNAKECOORD &sc,SHORT x,SHORT y, int ter);

public:
	//属性
	enum {
		上=1,
		下=2,
		左=3,
		右=4
	};
	Snake();		//初始化蛇头

	//接口
	void DrawSnake();
	void Clear(int map[MAX_LINES][MAX_COLS]);
	bool Move(int map[MAX_LINES][MAX_COLS],Food &food,int &);
	void GetPlayerInput();
};