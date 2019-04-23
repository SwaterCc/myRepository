#include "Calulator.h"
#include <QString>

Calulator::Calulator(QWidget *parent)
	: QDialog(parent)
{
	//ui.setupUi(this);
	initGUI();
	//连接对应槽
	num_connect();
	//运算符槽
	oper_connect();
	//缓存器初始化
	M = 0;
}
void Calulator::initGUI()
{
	/**************数字显示部分******************/
	showExpr = new QLineEdit;

	showExpr->setFont(QFont("Timers", 9, QFont::Bold));
	showExpr->setFocusPolicy(Qt::NoFocus);
	showExpr->setAlignment(Qt::AlignRight);
	showExpr->setEnabled(false);

	showInput = new QLineEdit;
	showInput->setFont(QFont("Timers", 20, QFont::Bold));
	showInput->setFocusPolicy(Qt::NoFocus);
	showInput->setAlignment(Qt::AlignRight);
	showlayout = new QVBoxLayout;
	showlayout->addWidget(showExpr);
	showlayout->addWidget(showInput);
	showlayout->setSpacing(0);
	/**************按钮部分*********************/
	buttonlayout = new QGridLayout();

	//第一行
	mc = new QPushButton(tr("MC"));
	mr = new QPushButton(tr("MR"));
	ms = new QPushButton(tr("MS"));
	m_add = new QPushButton(tr("M+"));
	m_minus = new QPushButton(tr("M-"));
	//将组件放入布局中
	buttonlayout->addWidget(mc, 0, 0);
	buttonlayout->addWidget(mr, 0, 1);
	buttonlayout->addWidget(ms, 0, 2);
	buttonlayout->addWidget(m_add, 0, 3);
	buttonlayout->addWidget(m_minus, 0, 4);
	//第二行
	del = new QPushButton(tr("D E L"));
	AC = new QPushButton(tr("AC"));
	CE = new QPushButton(tr("CE"));
	sqrt = new QPushButton(tr("√"));
	//将组件放入布局中
	buttonlayout->addWidget(del, 1, 0, 1, 2);
	buttonlayout->addWidget(AC, 1, 2);
	buttonlayout->addWidget(CE, 1, 3);
	buttonlayout->addWidget(sqrt, 1, 4);
	//第三行
	num7 = new QPushButton(tr("7"));
	num8 = new QPushButton(tr("8"));
	num9 = new QPushButton(tr("9"));
	divide = new QPushButton(tr("/"));
	square = new QPushButton(tr("x^2"));
	//将组件放入布局中
	buttonlayout->addWidget(num7, 2, 0);
	buttonlayout->addWidget(num8, 2, 1);
	buttonlayout->addWidget(num9, 2, 2);
	buttonlayout->addWidget(divide, 2, 3);
	buttonlayout->addWidget(square, 2, 4);
	//第四行
	num4 = new QPushButton(tr("4"));
	num5 = new QPushButton(tr("5"));
	num6 = new QPushButton(tr("6"));
	multiply = new QPushButton(tr("*"));
	fraction = new QPushButton(tr("x^-1"));
	//将组件放入布局中
	buttonlayout->addWidget(num4, 3, 0);
	buttonlayout->addWidget(num5, 3, 1);
	buttonlayout->addWidget(num6, 3, 2);
	buttonlayout->addWidget(multiply, 3, 3);
	buttonlayout->addWidget(fraction, 3, 4);
	//第五行
	num1 = new QPushButton(tr("1"));
	num2 = new QPushButton(tr("2"));
	num3 = new QPushButton(tr("3"));
	minus = new QPushButton(tr("-"));
	result = new QPushButton(tr("="));
	//将组件放入布局中
	buttonlayout->addWidget(num1, 4, 0);
	buttonlayout->addWidget(num2, 4, 1);
	buttonlayout->addWidget(num3, 4, 2);
	buttonlayout->addWidget(minus, 4, 3);
	buttonlayout->addWidget(result, 4, 4, 2, 1);
	result->setMinimumHeight(66);
	result->setFont(QFont("Timers", 20, QFont::Bold));

	//第六行
	num0 = new QPushButton(tr("0"));
	point = new QPushButton(tr("."));
	add = new QPushButton(tr("+"));

	//将组件放入布局中
	buttonlayout->addWidget(num0, 5, 0, 1, 2);
	buttonlayout->addWidget(point, 5, 2);
	buttonlayout->addWidget(add, 5, 3);
	//设置每一列的宽度
	buttonlayout->setColumnStretch(0, 1);
	buttonlayout->setColumnStretch(1, 1);
	buttonlayout->setColumnStretch(2, 1);
	buttonlayout->setColumnStretch(3, 1);
	buttonlayout->setColumnStretch(4, 1);
	buttonlayout->setSpacing(8);
	/**************总布局***********************/
	mainlayout = new QVBoxLayout(this);
	mainlayout->addLayout(showlayout);
	mainlayout->addLayout(buttonlayout);
	mainlayout->setSpacing(15);
	mainlayout->setMargin(15);
	mainlayout->setSizeConstraint(QLayout::SetFixedSize);//设置窗口大小，且不能改变窗口大小
	setWindowTitle(tr("简易计算器"));

}

void Calulator::num_connect()
{
	connect(num0, SIGNAL(clicked()), this, SLOT(on_clicked_0()));
	connect(num1, SIGNAL(clicked()), this, SLOT(on_clicked_1()));
	connect(num2, SIGNAL(clicked()), this, SLOT(on_clicked_2()));
	connect(num3, SIGNAL(clicked()), this, SLOT(on_clicked_3()));
	connect(num4, SIGNAL(clicked()), this, SLOT(on_clicked_4()));
	connect(num5, SIGNAL(clicked()), this, SLOT(on_clicked_5()));
	connect(num6, SIGNAL(clicked()), this, SLOT(on_clicked_6()));
	connect(num7, SIGNAL(clicked()), this, SLOT(on_clicked_7()));
	connect(num8, SIGNAL(clicked()), this, SLOT(on_clicked_8()));
	connect(num9, SIGNAL(clicked()), this, SLOT(on_clicked_9()));
}

void Calulator::oper_connect()
{
	/***************基本运算************************/
	connect(add, SIGNAL(clicked()), this, SLOT(on_clicked_add()));
	connect(minus, SIGNAL(clicked()), this, SLOT(on_clicked_minus()));
	connect(multiply, SIGNAL(clicked()), this, SLOT(on_clicked_mult()));
	connect(divide, SIGNAL(clicked()), this, SLOT(on_clicked_divi()));
	connect(result, SIGNAL(clicked()), this, SLOT(on_clicked_result()));
	//小数点
	connect(point, SIGNAL(clicked()), this, SLOT(on_clicked_point()));
	/*****************特殊运算***********************/
	connect(del, SIGNAL(clicked()), this, SLOT(on_clicked_del()));
	connect(AC, SIGNAL(clicked()), this, SLOT(on_clicked_AC()));
	connect(CE, SIGNAL(clicked()), this, SLOT(on_clicked_CE()));
	connect(square, SIGNAL(clicked()), this, SLOT(on_clicked_square()));
	connect(fraction, SIGNAL(clicked()), this, SLOT(on_clicked_frac()));
	connect(sqrt, SIGNAL(clicked()), this, SLOT(on_clicked_sqrt()));
	/***************缓存器运算 ***************************/
	connect(ms, SIGNAL(clicked()), this, SLOT(on_clicked_ms()));
	connect(mr, SIGNAL(clicked()), this, SLOT(on_clicked_mr()));
	connect(mc, SIGNAL(clicked()), this, SLOT(on_clicked_mc()));
	connect(m_add, SIGNAL(clicked()), this, SLOT(on_clicked_madd()));
	connect(m_minus, SIGNAL(clicked()), this, SLOT(on_clicked_mminus()));
}

void Calulator::getResult()
{
	double temp = showInput->text().toDouble();
	double end = st.top().toDouble();
	switch (qe.front().flag)
	{
	case ADD:
		end += temp;
		break;
	case MINUS:
		end -= temp;
		break;
	case MULT:
		end *= temp;
		break;
	case DIVIDE:
		end /= temp;
		break;
	}
	st.pop();
	qe.pop();

	showExpr->clear();
	showInput->setText(QString("%1").arg(end));
}

//数字按键定义
void Calulator::on_clicked_0()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text()+'0';
	showInput->setText(temp);
}

void Calulator::on_clicked_1()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '1';
	showInput->setText(temp);
}

void Calulator::on_clicked_2()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '2';
	showInput->setText(temp);
}

void Calulator::on_clicked_3()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '3';
	showInput->setText(temp);
}

void Calulator::on_clicked_4()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '4';
	showInput->setText(temp);
}

void Calulator::on_clicked_5()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '5';
	showInput->setText(temp);
}

void Calulator::on_clicked_6()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '6';
	showInput->setText(temp);
}

void Calulator::on_clicked_7()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '7';
	showInput->setText(temp);
}

void Calulator::on_clicked_8()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '8';
	showInput->setText(temp);
}

void Calulator::on_clicked_9()
{
	if (cal_OK)
	{
		showInput->clear();
		cal_OK = false;
	}
	QString temp = showInput->text() + '9';
	showInput->setText(temp);
}
/*******************运算符************************/
void Calulator::on_clicked_add()
{
	if (!st.empty())
	{
		getResult();
	}
	//按运算符时先将输入框数入栈
	st.push(showInput->text());
	//将运算符入队
	qe.push(Flag(ADD));
	//将算式显示在showExpr中
	QString temp = showExpr->text()+ showInput->text()+" + ";
	showExpr->setText(temp);
	//清空showinput
	showInput->clear();
}

void Calulator::on_clicked_minus()
{
	if (!st.empty())
	{
		getResult();
	}
	//按运算符时先将输入框数入栈
	st.push(showInput->text());
	//将运算符入队
	qe.push(Flag(MINUS));
	//将算式显示在showExpr中
	QString temp = showExpr->text() + showInput->text() + " - ";
	showExpr->setText(temp);
	//清空showinput
	showInput->clear();

}

void Calulator::on_clicked_mult()
{
	if (!st.empty())
	{
		getResult();
	}
	//按运算符时先将输入框数入栈
	st.push(showInput->text());
	//将运算符入队
	qe.push(Flag(MULT));
	//将算式显示在showExpr中
	QString temp = showExpr->text() + showInput->text() + " * ";
	showExpr->setText(temp);
	//清空showinput
	showInput->clear();
}

void Calulator::on_clicked_divi()
{
	if (!st.empty())
	{
		getResult();
	}
	//按运算符时先将输入框数入栈
	st.push(showInput->text());
	//将运算符入队
	qe.push(Flag(DIVIDE));
	//将算式显示在showExpr中
	QString temp = showExpr->text() + showInput->text() + " / ";
	showExpr->setText(temp);
	//清空showinput
	showInput->clear();
}

void Calulator::on_clicked_point()
{
	if (QString(showInput->text()).isEmpty())
	{
		showInput->setText("0.");
	}
	else
	{
		QString temp = showInput->text() + '.';
		showInput->setText(temp);
	}
}
//DEL键实现
void Calulator::on_clicked_del()
{
	QString temp = showInput->text();
	QString newstr=temp.mid(0,temp.size()-1);
	showInput->setText(newstr);
}

void Calulator::on_clicked_AC()
{
	showInput->clear();
	showExpr->clear();

	while (!st.empty())
	{
		st.pop();
	}
	while (!qe.empty())
	{
		qe.pop();
	}

}

void Calulator::on_clicked_CE()
{
	showInput->clear();
}

void Calulator::on_clicked_result()
{
	if (!qe.empty() && !st.empty())
	{
		double temp = showInput->text().toDouble();
		double end = st.top().toDouble();
		Flag f1 = qe.front();
		switch (f1.flag)
		{
		case ADD:
			end += temp;
			break;
		case MINUS:
			end -= temp;
			break;
		case MULT:
			end *= temp;
			break;
		case DIVIDE:
			end /= temp;
			break;
		}

		cal_OK = true;


		//将计算结果显示在showInput中
		while (!st.empty())
		{
			st.pop();
		}
		while (!qe.empty())
		{
			qe.pop();
		}

		showInput->setText(QString("%1").arg(end));

		showExpr->clear();
	}
}

void Calulator::on_clicked_square()
{
	if (!showInput->text().isEmpty())
	{
		double num = showInput->text().toDouble();
		double num_e = num * num;
		showInput->setText(QString::number(num_e));
	}
}

void Calulator::on_clicked_sqrt()
{
	if (!showInput->text().isEmpty())
	{
		double num = showInput->text().toDouble();
		if (num > 0)
		{
			num = std::sqrt(num);
			showInput->setText(QString::number(num));
		}
		else
		{
			cal_OK = true;
			showInput->setText("error！！");
		}
	}
}

void Calulator::on_clicked_frac()
{
	if (!showInput->text().isEmpty())
	{
		double num = showInput->text().toDouble();
		if (num != 0)
		{
			double num_e = 1 / num;
			showInput->setText(QString::number(num_e));
		}
		else
		{
			cal_OK = true;
			showInput->setText("error！！");
		}
	}
}
void Calulator::on_clicked_mr()
{
	showInput->setText(QString::number(M));
}
void Calulator::on_clicked_mc()
{
	M = 0;
}
//缓存器运算
void Calulator::on_clicked_ms()
{
	if(!showInput->text().isEmpty())
	M = showInput->text().toDouble();
}

void Calulator::on_clicked_madd()
{
	double nownum = showInput->text().toDouble();
	M += nownum;
}

void Calulator::on_clicked_mminus()
{
	double nownum = showInput->text().toDouble();
	M -= nownum;
}

