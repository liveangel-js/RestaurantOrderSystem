#include "desk.h"

Desk::Desk(int i,int _number){
	type = i;
	count=0;
	number= _number;
	used =false;
	peopleNumber =0;
	totalInCome =0.0;
	income = 0.0;
	queue_No=-1;
}

Desk::~Desk(){

}

int Desk::getType(){
	return type;
	
}
int Desk::getNumber(){
	return number;
}
int Desk::getCount(){
	return count;
}
void Desk::setNumber(int i){
	number = i;
}
bool Desk::isUsed(){
	return used;
}
void Desk::setUse(bool a){
	used=a;
}
void Desk::addCount(){
	count++;
}
void Desk::addInCome(double a){
	income+=a;
	totalInCome+=a;
}
void Desk::resetInCome(){
	income = 0.0;
}
double Desk::getInCome(){
	return totalInCome;
}
void Desk::setPeopleNum(int i){
	peopleNumber=i;
}
void Desk::setQueueNo(int i){
	queue_No = i ;
}
int Desk::getQueueNo(){
	return queue_No;
}
double Desk::getTotalInCome(){
	return totalInCome;
}
ostream& operator<<(ostream& out,const Desk & D){
	time_t t = time(0);
	char tmp[64];
	strftime(tmp,sizeof(tmp),"%Y/%m/%d%X%A%z",localtime(&t));
	out<<tmp<<endl;
	out<<"餐桌号："<<D.number<<" 类型"<<D.type<<" 本次收益："<<D.income<<" 就餐人数:"<<D.peopleNumber<<" 队列号"<<D.queue_No<<endl;
	return out;
}


//string Desk::writeRecord(){
//	return 
//}
