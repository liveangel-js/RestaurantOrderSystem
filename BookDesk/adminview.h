#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QtGui/QMainWindow>
#include "ui_adminview.h"
//#include "mainlogic.h"
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "desk.h"

class AdminView : public QMainWindow
{
	Q_OBJECT

public:
	AdminView(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AdminView();

private:
	Ui::AdminViewClass ui;
private slots:
	void reqSmlDesk();
	void reqMidDesk();
	void reqBigDesk();
	void deskIn();
	void popDrop();
	void deskPay();
	void writeDaily();
	void browseData();
};

#endif // GUESTVIEW_H
