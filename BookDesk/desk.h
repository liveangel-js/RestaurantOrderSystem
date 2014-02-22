#ifndef _DESK_H
#define _DESK_H
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;
class Desk{
private:
	int type;//种类
	int count;//今天使用次数
	int number;//餐桌号
	bool used;//
	int peopleNumber;//当前用餐人数
	double totalInCome;//餐桌当天总收益
	double income;//一次消费收益
	int queue_No;//队号

public:
	Desk(int i,int _type);
	~Desk();
	int getType();
	int getNumber();
	int getCount();
	double getTotalInCome();
	void setNumber(int i);
	bool isUsed();
	void setUse(bool a);
	void addCount();
	void addInCome(double a);
	void resetInCome();
	double getInCome();
	void setPeopleNum(int i);
	void setQueueNo(int i);
	int getQueueNo();
	friend ostream& operator<<(ostream& ,const Desk &); 
//	string writeRecord();




};

#endif