
#include "mainlogic.h"

vector<Desk> table_list;
queue<int> small_list;
queue<int> mid_list;
queue<int> big_list;
mainlogic logic;
mainlogic::mainlogic(){

	initializeDesk();
}

mainlogic::~mainlogic(){

}
void mainlogic::initializeDesk(){
	cout<<"mainlogic"<<endl;
	if(table_list.empty()){
		ifstream fin("Desks.txt");
		char token[10];
		while(fin >> token){
			int k =0;
			while(token[k]!=','){
				k++;
			}
			char * temp_type = new char[2];
			char * temp_number = new char[4];
			strncpy(temp_type,token,k);
			int head = k;
			while(token[k]!='\0')
				k++;
			strncpy(temp_number, token+head+1, k-head);
			int type = atoi(temp_type);
			int number= atoi(temp_number);
			Desk *temp = new Desk(type,number);
			table_list.push_back(*temp);

		}
		fin.close();  
	}
}

bool mainlogic::smlDeskIn(int number,int queueno,int people){
	for(vector<Desk>::size_type i=0;i!=table_list.size()-1;++i){
		if(table_list[i].getNumber()==number&&table_list[i].getType()==1&&(!table_list[i].isUsed())){
			table_list[i].setPeopleNum(people);
			table_list[i].setQueueNo(queueno);
			table_list[i].setUse(true);
			table_list[i].addCount();
			small_list.pop();
			return true;
		}
	}
	return false;
}
bool mainlogic::midDeskIn(int number,int queueno,int people){
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getNumber()==number&&table_list[i].getType()==2&&(!table_list[i].isUsed())){
			table_list[i].setPeopleNum(people);
			table_list[i].setQueueNo(queueno);
			table_list[i].setUse(true);
			table_list[i].addCount();
			mid_list.pop();
			
			return true;
		}
	}
	return false;
}
bool mainlogic::bigDeskIn(int number,int queueno,int people){
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getNumber()==number&&table_list[i].getType()==3&&(!table_list[i].isUsed())){
			table_list[i].setPeopleNum(people);
			table_list[i].setQueueNo(queueno);
			table_list[i].setUse(true);
			table_list[i].addCount();
			big_list.pop();
			
			return true;
		}
	}
	return false;
}
bool mainlogic::paySmlDesk(int number, double cost){
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getNumber()==number&&table_list[i].getType()==1&&table_list[i].isUsed()){
			table_list[i].addInCome(cost);
			writeRecord(&table_list[i],"ss");
			table_list[i].setUse(false);
			return true;
		}
	}
	return false;
}
bool mainlogic::payMidDesk(int number, double cost){
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getNumber()==number&&table_list[i].getType()==2&&table_list[i].isUsed()){
			table_list[i].addInCome(cost);
			writeRecord(&table_list[i],"ss");
			table_list[i].setUse(false);
			return true;
		}
	}
	return false;
}
bool mainlogic::payBigDesk(int number, double cost){
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getNumber()==number&&table_list[i].getType()==3&&table_list[i].isUsed()){
			table_list[i].addInCome(cost);
			writeRecord(&table_list[i],"ss");
			table_list[i].setUse(false);
			return true;
		}
	}
	return false;
}

void mainlogic::writeRecord(Desk * a,const char *outputFile_Name){
	time_t t = time(0);
	char tmp[64];
	strftime(tmp,sizeof(tmp),"%Y%m%d",localtime(&t));
	strncat(tmp,"A.txt",5);
	//ofstream fout(outputFile_Name);
	ofstream fout;
		
	fout.open(tmp,ios::app);
	fout<<*a;
	fout.close();

}
void mainlogic::writeTotal(){
	time_t t = time(0);
	char tmp[64];
	strftime(tmp,sizeof(tmp),"%Y%m%d",localtime(&t));
	strncat(tmp,"B.txt",5);
	ofstream fout(tmp);
	fout<<tmp<<endl;
	for(vector<Desk>::size_type i=0;i!=table_list.size();++i){
		if(table_list[i].getType()==1){
			fout<<"餐桌号: "<< table_list[i].getNumber()<<" 餐桌类型:"<<"小餐桌"<<" 今天使用次数："<<table_list[i].getCount()<<
				" 当日收益："<<table_list[i].getTotalInCome()<<endl;
		}else if(table_list[i].getType()==2){
			fout<<"餐桌号: "<< table_list[i].getNumber()<<" 餐桌类型:"<<"中餐桌"<<" 今天使用次数："<<table_list[i].getCount()<<
				" 当日收益："<<table_list[i].getTotalInCome()<<endl;
		}else{
			fout<<"餐桌号: "<< table_list[i].getNumber()<<" 餐桌类型:"<<"大餐桌"<<" 今天使用次数："<<table_list[i].getCount()<<
				" 当日收益："<<table_list[i].getTotalInCome()<<endl;
		}
	}
	fout.close();
}
