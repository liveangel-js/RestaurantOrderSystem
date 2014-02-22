#include "adminview.h"
#include <qmessagebox>
#include "mainlogic.h"

extern vector<Desk> table_list;
extern queue<int> small_list;
extern queue<int> mid_list;
extern queue<int> big_list;
extern mainlogic logic;

AdminView::AdminView(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(reqSmlDesk()));
	QObject::connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(reqMidDesk()));
	QObject::connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(reqBigDesk()));
	QObject::connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(deskIn()));
	QObject::connect(ui.pushButton_5,SIGNAL(clicked()),this,SLOT(popDrop()));
	QObject::connect(ui.pushButton_6,SIGNAL(clicked()),this,SLOT(deskPay()));
	QObject::connect(ui.pushButton_7,SIGNAL(clicked()),this,SLOT(writeDaily()));
	QObject::connect(ui.pushButton_8,SIGNAL(clicked()),this,SLOT(browseData()));
}

AdminView::~AdminView(){

}
void AdminView::reqSmlDesk(){
	ui.textBrowser->clear();
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getType()==1&&(!table_list[i].isUsed())){
			ui.textBrowser->append("Desk NO:"+QString::number(table_list[i].getNumber()));
			
		}
	}
}
void AdminView::reqMidDesk(){
	ui.textBrowser_2->clear();
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getType()==2&&(!table_list[i].isUsed())){
			ui.textBrowser_2->append("Desk NO:"+QString::number(table_list[i].getNumber()));
		}
	}
}
void AdminView::reqBigDesk(){
	ui.textBrowser_3->clear();
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getType()==3&&(!table_list[i].isUsed())){
			ui.textBrowser_3->append("Desk NO:"+QString::number(table_list[i].getNumber()));
		}
	}
}
void AdminView::deskIn(){
	int tempNo;
	int tempDesk = ui.spinBox->text().toInt();
	bool temp;
	if(ui.radioButton->isChecked()){
		tempNo = small_list.front();
		temp=logic.smlDeskIn(tempDesk,tempNo,3);
		if(temp){
			QMessageBox::information(this,tr("warning"),tr("Success!"));
		}else{
			QMessageBox::information(this,tr("warning"),tr("FAILED!"));
		}
	}else if(ui.radioButton_2->isChecked()){
		tempNo = mid_list.front();
		temp=logic.midDeskIn(tempDesk,tempNo,3);
		if(temp){
			QMessageBox::information(this,tr("warning"),tr("Success!"));
		}else{
			QMessageBox::information(this,tr("warning"),tr("FAILED!"));
		}
	}else if(ui.radioButton_3->isChecked()){
		tempNo = big_list.front();
		temp=logic.bigDeskIn(tempDesk,tempNo,3);
		if(temp){
			QMessageBox::information(this,tr("warning"),tr("Success!"));
		}else{
			QMessageBox::information(this,tr("warning"),tr("FAILED!"));
		}
	}
}
void AdminView::popDrop(){
	if(ui.radioButton->isChecked()){
		if(small_list.size()==0){
			QMessageBox::information(this,tr("warning"),tr("No queue to POP"));
		}else{
			small_list.pop();
			QMessageBox::information(this,tr("warning"),tr("POP SUCCESS"));
		}
		
	}else if(ui.radioButton_2->isChecked()){
		if(mid_list.size()==0){
			QMessageBox::information(this,tr("warning"),tr("No queue to POP"));
		}else{
			mid_list.pop();
			QMessageBox::information(this,tr("warning"),tr("POP SUCCESS"));
		}
	}else if(ui.radioButton_3->isChecked()){
		if(big_list.size()==0){
			QMessageBox::information(this,tr("warning"),tr("No queue to POP"));
		}else{
			big_list.pop();
			QMessageBox::information(this,tr("warning"),tr("POP SUCCESS"));
		}
	}else{
		QMessageBox::information(this,tr("warning"),tr("Please choose desk TYPE!"));
	}
}

void AdminView::deskPay(){
	double cost1 = ui.lineEdit->text().toDouble();
	double cost2 = ui.lineEdit_2->text().toDouble();
	double cost= cost1+cost2;
	int tempDesk = ui.lineEdit_3->text().toInt();
	bool temp;

	if(ui.radioButton_4->isChecked()){
		temp =logic.paySmlDesk(tempDesk,cost);
		if(temp){
			QMessageBox::information(this,tr("warning"),tr("Success!"));
		}else{
			QMessageBox::information(this,tr("warning"),tr("FAILED!"));
		}



	}else if(ui.radioButton_5->isChecked()){
		temp =logic.payMidDesk(tempDesk,cost);
		if(temp){
			QMessageBox::information(this,tr("warning"),tr("Success!"));
		}else{
			QMessageBox::information(this,tr("warning"),tr("FAILED!"));
		}
	}else if(ui.radioButton_6->isChecked()){
		temp =logic.payBigDesk(tempDesk,cost);
		if(temp){
			QMessageBox::information(this,tr("warning"),tr("Success!"));
		}else{
			QMessageBox::information(this,tr("warning"),tr("FAILED!"));
		}
	}else{

		QMessageBox::information(this,tr("warning"),tr("Please choose desk TYPE!"));
	}
}

void AdminView::writeDaily(){
	logic.writeTotal();
}

void AdminView::browseData(){
	QString a = ui.dateEdit->text();
	string tmp = a.toStdString();
	const char * ss = tmp.c_str();
	
	int k =0;
	char * temp = new char[10];
	while(ss[k]!='/') k++;
	int year = atoi(ss);

	k++;
	//strncpy(temp,ss+k,3);
	int month = atoi(ss+k);
	
	while(ss[k]!='/') k++;
	k++;
//	strncpy(temp,ss[k],3);
	int day = atoi(ss+k);
	int name = year*10000+month*100+day;

	//strncpy(temp,ss,k);
	
	string tmp1 =QString::number(name).toStdString();
	const char * sss = tmp1.c_str();

	char* aa = new char[20];
	strcpy(aa,sss);



	if(ui.radioButton_7->isChecked()){
		strncat(aa,"A.txt",5);
	}else if(ui.radioButton_8->isChecked()){
		strncat(aa,"B.txt",5);
	}
	ifstream fin;
	fin.open(aa);
	if(!fin){
		QMessageBox::information(this,tr("warning"),tr("No LOG EXISTS"));
	}else{
		ui.textBrowser_4->clear();
		for(char *str=new char[200]; fin.getline(str, 200);){
			QString temp(str);
			ui.textBrowser_4->append(temp);
		}
	}
	
}