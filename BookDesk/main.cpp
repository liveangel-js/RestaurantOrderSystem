
#include <QtGui/QApplication>
#include "bookdesk.h"
#include <QTextCodec>




int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BookDesk w;
	QTextCodec *codec = QTextCodec::codecForName("GB2312");   

	w.show();
	

	

	return a.exec();
}