#ifndef _MAINLOGIC_H
#define _MAINOGIC_H
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "desk.h"

using namespace std;

//const int TOKEN_MAXSIZE=10; 
class mainlogic{
public:
	mainlogic();
	~mainlogic();
	bool smlDeskIn(int index,int,int);
	bool midDeskIn(int index,int,int);
	bool bigDeskIn(int index,int,int);
	bool paySmlDesk(int index, double cost);
	bool payMidDesk(int index, double cost);
	bool payBigDesk(int index, double cost);
	void writeRecord(Desk * a,const char *outputFile_Name);
	void writeTotal();


private:
	void initializeDesk();


};


#endif _MAINLOGIC_H