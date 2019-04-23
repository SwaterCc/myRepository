#include "Calulator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Calulator w;
	w.show();
	return a.exec();
}
