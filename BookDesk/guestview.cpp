#include "guestview.h"
#include <qmessagebox>

extern vector<Desk> table_list;
extern queue<int> small_list;
extern queue<int> mid_list;
extern queue<int> big_list;
extern mainlogic logic;

GuestView::GuestView(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QObject::connect(ui.bt_reqQueue,SIGNAL(clicked()),this,SLOT(showSmlQueue()));
	QObject::connect(ui.bt_reqQueue,SIGNAL(clicked()),this,SLOT(showMidQueue()));
	QObject::connect(ui.bt_reqQueue,SIGNAL(clicked()),this,SLOT(showBigQueue()));

	QObject::connect(ui.bt_book,SIGNAL(clicked()),this,SLOT(getNum()));
	QObject::connect(ui.bt_reqDesk,SIGNAL(clicked()),this,SLOT(getDesk()));
}
/*GuestView::GuestView(mainlogic l){
	ui.setupUi(this);

	logic = l;
}*/

GuestView::~GuestView(){

}
void GuestView::showSmlQueue(){
	int length;
	if(small_list.size()==0){
		length=0;
	//	length = table_list.size();
	}else{
		length=small_list.front();
	}
	ui.lcdNumber->display(length);

}
void GuestView::showMidQueue(){
	int length;
	if(mid_list.size()==0){
		length=0;
	}else{
		length=mid_list.front();
	}
	ui.lcdNumber_2->display(length);
}

void GuestView::showBigQueue(){
	int length;
	if(big_list.size()==0){
		length=0;
	}else{
		length=big_list.front();
	}
	ui.lcdNumber_3->display(length);
}
void GuestView::getNum(){
	if(ui.radioButton->isChecked()){
		int before = small_list.size();
		ui.lcdNumber_5->display(before);
		if(small_list.size()==0){
			int temp =1001;
			small_list.push(temp);
		}else{
			int temp = small_list.back();
			temp++;
			small_list.push(temp);
		}
		ui.lcdNumber_4->display(small_list.back());
	}else if(ui.radioButton_2->isChecked()){
		int before = mid_list.size();
		ui.lcdNumber_5->display(before);
		if(mid_list.size()==0){
			int temp =2001;
			mid_list.push(temp);
		}else{
			int temp = mid_list.back();
			temp++;
			mid_list.push(temp);
		}
		ui.lcdNumber_4->display(mid_list.back());
	}else if(ui.radioButton_3->isChecked()){
		int before = big_list.size();
		ui.lcdNumber_5->display(before);
		if(big_list.size()==0){
			int temp =3001;
			big_list.push(temp);
		}else{
			int temp = big_list.back();
			temp++;
			big_list.push(temp);
		}
		ui.lcdNumber_4->display(big_list.back());

	}


}
void GuestView::getDesk(){
	int tempNo = ui.lineEdit->text().toInt();
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getQueueNo()==tempNo){
			if(tempNo/1000==1){
				ui.label_12->setText("Your DeskType: SMALL");
			}else if(tempNo/1000==2){
				ui.label_12->setText("Your DeskType: MEDUIM");
			}else if(tempNo/1000==3){
				ui.label_12->setText("Your DeskType: BIG");
			}
			ui.label_14->setText(QString::number(table_list[i].getNumber()));
			return;
		}
	}
	QMessageBox::information(this,tr("warning"),tr("No Desk for your NO."));

}