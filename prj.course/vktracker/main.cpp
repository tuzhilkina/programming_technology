#include "vktracker.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	vktracker w;
	w.show();
	return a.exec();
}
