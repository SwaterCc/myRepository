#pragma once
#include "qstring.h"
#include "iostream"

#define ADD 10			//运算对应的标记
#define MINUS 11
#define MULT  101
#define DIVIDE 111
#define NEGA   -1		//负数标记
#define END    99		//等号
#define POINT  1111     //小数点
class Flag {
public:
	int flag;
public:
	Flag() {

		flag = 0;
	}
	Flag(int f)
	{
		flag = f;
	}
};