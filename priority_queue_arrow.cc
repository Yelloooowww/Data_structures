#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Record{
	string name;
	int  score;
	Record(const string& n,int s):name(n),score(s){}
};

bool operator< (const Record&a ,const Record& b){
	return a.score<b.score;
}
ostream& operator<< ( ostream& out ,const Record& foo){
	return out<<foo.name<<":"<<foo.score;
}

int main(){
	
	priority_queue<Record> contestant;
	contestant.push(Record("A",7));
	contestant.push(Record("B",0));
	contestant.push(Record("C",2));
	contestant.push(Record("D",8));
	contestant.push(Record("E",5));
	
	
	while(!contestant.empty()){
		cout<<contestant.top()<<"     ";
		contestant.pop();
	}
	cout<<endl;
	
	
	system("pause");
	return 0;
}




