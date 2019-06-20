#include<iostream>
#include<ostream>
#include<string> 
using namespace std;
class F{
	private:
		ostream *ptr;
	public:
		friend F operator<<(ostream&, F);
		friend ostream& operator<<(const F&,int);
};
F fa;
F operator<<(ostream&out,F foo){
	foo.ptr=&out;
	return foo;
}
ostream& operator<<(const F&foo,int deg){
	*(foo.ptr)<<(9*deg/5+32);
	return *(foo.ptr);
}



int main(){
	
	for(int deg=0;deg<=100;deg+=10){
		cout<<deg<<"C<==>"<<fa<<deg<<"F \n";
	}
	
	
	
	system("pause");
	return 0;
}
