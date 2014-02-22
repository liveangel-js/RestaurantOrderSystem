#include "bookdesk.h"
#include "guestview.h"
#include "adminview.h"
#include <qmessagebox>
#include "desk.h"


BookDesk::BookDesk(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QObject::connect(ui.btn_adminLogin,SIGNAL(clicked()),this,SLOT(adminLogin()));
	QObject::connect(ui.btn_guest,SIGNAL(clicked()),this,SLOT(guestLogin()));
	//initialize();
}

BookDesk::~BookDesk()
{

}


void BookDesk::guestLogin(){
	GuestView *guestview = new GuestView();
	guestview->show();

}
void BookDesk::adminLogin(){
	QString username = ui.text_username->text();
	QString password = ui.text_password->text();
	ifstream fin("admin.txt");
	
	
	for(char *str=new char[200]; fin.getline(str, 200);){
		int k=0;
		while(str[k]!=','){
			k++;
		}

		char * temp_username = new char[10];
		char * temp_password = new char[10];
		strncpy(temp_username,str,k);
		temp_username[k]='\0';
		int head = k;


		while(str[k]!='\0')
			k++;
		strncpy(temp_password, str+head+1, k-head);
		QString a = QString(temp_username);
		QString b = QString(temp_password);
		if(username==a){
			if(password==b){
				AdminView *adview = new AdminView();
				adview->show();
			}else{
				QMessageBox::information(this,tr("warning"),tr("密码错误"));
			}
			}else{
				QMessageBox::information(this,tr("warining"),tr("用户不存在"));
		}

	}

	

}
