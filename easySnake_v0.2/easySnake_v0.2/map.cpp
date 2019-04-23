#include "map.h"
#include"windows.h"
#include"tools.h"

void Map::InitMap(int GameMap[MAX_LINES][MAX_COLS])
{
	for (int i = 0; i < MAX_LINES; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (i == 0 || j == 0 || i == MAX_LINES - 1 || j == MAX_COLS - 1)
				GameMap[i][j] = 障碍物;
			else
				GameMap[i][j] = 空地;			//创造地图边界

		}
	}
}

void Map::DrawMap(int GameMap[MAX_LINES][MAX_COLS])
{
	
	//画出地图
	for (int i = 0; i < MAX_LINES; i++)
	{
		for (int j = 0; j < MAX_COLS;j++)
		{
			if (GameMap[i][j] == 空地)
				WritetoPos(j, i, " ");
			else
				WritetoPos(j, i, "■");
		}
	}
}
