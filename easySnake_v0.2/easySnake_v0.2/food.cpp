#include "food.h"
#include "game.h"
#include "tools.h"
#include  "map.h"
void Food::CreateFoodCoord(COORD &pos)
{
	srand((unsigned int)time(0));
	pos.X = rand() % MAX_COLS;
	pos.Y = rand() % MAX_LINES;
}
Food::Food()
{
	foodnum = 0;
	toxicfoodnum = 0;
	foodpos = { 0,0 };
	toxicpos = { 0,0 };
}
void Food::CreateFood(int map[MAX_LINES][MAX_COLS])
{
	//食物产生的位置必须位于地图空地上
	if (foodnum == 0)
	{
		CreateFoodCoord(foodpos);
		if (map[foodpos.Y][foodpos.X] == Map::空地)
		{
			map[foodpos.Y][foodpos.X] = Map::食物;
			WritetoPos(foodpos.X, foodpos.Y, "★");
			foodnum = 1;
		}
	}
}

void Food::CreateToxicFood(int map[MAX_LINES][MAX_COLS])
{
	while (toxicfoodnum < 1)
	{
		CreateFoodCoord(toxicpos);
		if (map[toxicpos.Y][toxicpos.X] == Map::空地)
		{
			map[toxicpos.Y][toxicpos.X] = Map::毒食物;
			WritetoPos(toxicpos.X, toxicpos.Y, "☆");
			toxicfoodnum++;
		}
	}
}
