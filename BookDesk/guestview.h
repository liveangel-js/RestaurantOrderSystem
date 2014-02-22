#ifndef GUESTVIEW_H
#define GUESTVIEW_H

#include <QtGui/QMainWindow>
#include "ui_guestview.h"
#include "mainlogic.h"

class GuestView : public QMainWindow
{
	Q_OBJECT

public:
	GuestView(QWidget *parent = 0, Qt::WFlags flags = 0);
	//GuestView(mainlogic l);
	~GuestView();

private:
	Ui::GuestViewClass ui;
	//mainlogic logic;

private slots:
	void showSmlQueue();
	void showMidQueue();
	void showBigQueue();
	void getNum();
//	void getMidNum();
	//void getBigNum();
	void getDesk();
};

#endif // GUESTVIEW_H
