#include<iostream>
using namespace std;

enum Status {empty,occupid};
const int Size=10;

class Set{
	private:
		int element[Size];
		Status status[Size];
		int element_no;
	public:
		Set(){
			for(int i=0;i<Size;i++){
				status[i]=empty;
			}
			element_no=0;
		}
		bool insert_element(int data);
		int delete_element(int data);
		void print_element();
}; 
int main(){
	
	Set myset;
//	myset.initial();
	
	myset.insert_element(5);
	myset.insert_element(3);
	myset.insert_element(1);
	myset.insert_element(5);
	myset.insert_element(8);
	myset.insert_element(3);
	myset.insert_element(8);
	myset.insert_element(2);
	myset.print_element();
	
	myset.delete_element(5);
	myset.print_element();
	
	system("pause");
	return 0;
}

bool Set::insert_element(int data){
	if(element_no==Size){
		return false;
	}
	for(int i=0;i<Size;i++){
		if(status[i]==empty){
			element[i]=data;
			status[i]=occupid;
			element_no++;
			return true;
		}
	}
}
int Set::delete_element(int data){
	int no_element_del=0;
	for(int i=0;i<Size;i++){
		if(element[i]==data&&status[i]==occupid){
			status[i]=empty;
			element_no--;
			no_element_del++;
		}
	}
	return no_element_del;
}
void Set::print_element(){
	cout<<"Here are"<<element_no<<" elements~"<<endl;
	for(int i=0;i<Size;i++){
		if(status[i]==occupid){
			cout<<element[i]<<" ";
		}
	cout<<endl;
		
	}
}
