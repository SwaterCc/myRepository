#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <qdialog.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <stack>
#include <queue>
#include <cmath>
#include "Flag.h"
//#include "ui_Calulator.h"

class Calulator : public QDialog
{
	Q_OBJECT

public:
	Calulator(QWidget *parent = Q_NULLPTR);
	void initGUI();		//初始化界面
	void num_connect();
	void oper_connect();
	void getResult();
	typedef Flag flags;
private:
	//Ui::CalulatorClass ui;
	QVBoxLayout *mainlayout;
	
	QVBoxLayout *showlayout;
	QLineEdit *showExpr;			//数字显示界面
	QLineEdit *showInput;			//用户输入
	/**************按钮部分***************/
	//按钮采用网格布局
	QGridLayout *buttonlayout;
	//数字部分
	QPushButton *num0;
	QPushButton *num1;
	QPushButton *num2;
	QPushButton *num3;
	QPushButton *num4;
	QPushButton *num5;
	QPushButton *num6;
	QPushButton *num7;
	QPushButton *num8;
	QPushButton *num9;
	//计算符号部分
	QPushButton *add;           // +
	QPushButton *minus;			// -
	QPushButton *multiply;		// *
	QPushButton *divide;		// /
	//特殊计算部分
	QPushButton *square;		// 平方
	QPushButton *result;		// =
	QPushButton *sqrt;			// 开方
	QPushButton *fraction;		// 分数
	//缓存计算部分
	QPushButton *mr;
	QPushButton *ms;
	QPushButton *mc;
	QPushButton *m_add;
	QPushButton *m_minus;
	//功能键
	QPushButton *del;
	QPushButton *AC;
	QPushButton *CE;
	QPushButton *point;
	//定义运算数栈
	std::stack<QString> st;
	//运算符队列
	std::queue<flags> qe;
	//运算完成的标记位
	bool cal_OK = false;
	//缓存器初始值
	double M;

public slots://注册信号
	/**************数字信号****************/
	void on_clicked_0();
	void on_clicked_1();
	void on_clicked_2();
	void on_clicked_3();
	void on_clicked_4();
	void on_clicked_5();
	void on_clicked_6();
	void on_clicked_7();
	void on_clicked_8();
	void on_clicked_9();
	/**************功能键*****************/
	//基本计算
	void on_clicked_add();
	void on_clicked_minus();
	void on_clicked_mult();
	void on_clicked_divi();
	//小数点
	void on_clicked_point();
	//屏幕控制
	void on_clicked_del();
	void on_clicked_AC();
	void on_clicked_CE();
	//特殊运算
	void on_clicked_result();
	void on_clicked_square();
	void on_clicked_sqrt();
	void on_clicked_frac();
	//缓存器运算
	void on_clicked_mr();
	void on_clicked_mc();
	void on_clicked_ms();
	void on_clicked_madd();
	void on_clicked_mminus();

};
