#ifndef BOOKDESK_H
#define BOOKDESK_H

#include <QtGui/QMainWindow>
#include "ui_bookdesk.h"




class BookDesk : public QMainWindow
{
	Q_OBJECT

public:
	BookDesk(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BookDesk();
	

private:
	Ui::BookDeskClass ui;
	//void initialize();
private slots:
	
	void adminLogin();
	void guestLogin();
};

#endif // BOOKDESK_H
