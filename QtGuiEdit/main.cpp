#include "QtGuiEdit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiEdit w;
	w.setMaximumSize(800, 600);
	w.setMinimumSize(650, 350);
	w.setWindowTitle(QString::fromLocal8Bit("ÓÎÏ·ÐÞ¸ÄÆ÷"));
	w.show();
	return a.exec();
}
