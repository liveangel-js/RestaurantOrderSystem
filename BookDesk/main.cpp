
#include <QtGui/QApplication>
#include "bookdesk.h"
#include <QTextCodec>




int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BookDesk w;
	QTextCodec *codec = QTextCodec::codecForName("GB2312");       QTextCodec::setCodecForLocale(codec);       QTextCodec::setCodecForCStrings(codec);       QTextCodec::setCodecForTr(codec); 

	w.show();
	

	

	return a.exec();
}
