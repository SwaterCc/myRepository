#pragma once
#include"game.h"


const SHORT MAX_COLS = 50;		//控制台最宽为40个字符
const SHORT MAX_LINES = 30;		//控制台最高为40行
class Control
{
private:
	int speed;				//速度
	int modenum;			//难度标记
	int integral;			//积分
	inline string selected(string);
	void MenuInput(int);
public:
	Control() {
		speed = 0;
		modenum = 0;
		integral = 0;
	}
	int GameMap[MAX_LINES][MAX_COLS];
	
public:
	void begin()const;			//开始界面
	void menu();			//难度选择菜单
	void GameStart();		//游戏主循环
	bool EndGame();				//结束界面
	void show();			//游戏界面的一些补充
	void GameExplain();		//游戏说明
	void GamePlay();		//游戏整体循环
	//Set 和 Get
	void SetSpeed(int flag);
};