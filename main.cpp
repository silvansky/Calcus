#include <QtGui/QApplication>
#include <QIcon>
#include "calcusdlg.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CalcusDlg w;
	w.setWindowIcon(QIcon(":/Calcus.png"));
	w.show();
	return a.exec();
}
