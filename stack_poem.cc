#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main(){
	
	char p[]="a b c d e F G H I ";
	int size=sizeof(p)/sizeof(char);
	
	stack< string,vector<string> > poem;
	
	//兩個字母當成一個字串送入堆疊
	for(int i=0;i<size-1;i+=2){
		poem.push(string(p+i,p+i+2));
	} 
	
	while(!poem.empty()){
		cout<<poem.top();
		poem.pop();
	}
	
	cout<<endl;
	
	
	system("pause");
	return 0;
}
