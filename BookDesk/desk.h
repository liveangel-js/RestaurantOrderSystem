#ifndef _DESK_H
#define _DESK_H
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;
class Desk{
private:
	int type;//����
	int count;//����ʹ�ô���
	int number;//������
	bool used;//
	int peopleNumber;//��ǰ�ò�����
	double totalInCome;//��������������
	double income;//һ����������
	int queue_No;//�Ӻ�

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