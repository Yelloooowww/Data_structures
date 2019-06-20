#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <iomanip>
using namespace std;

struct To_Upper;
class Color{
    private:
	    string name;
	    int red,green,blue; 
    public:
    	Color(){}
    	Color( string n,int r,int g,int b ) : name(n),red(r),green(g),blue(b){}
    	
    	friend ostream& operator<< ( ostream& out , const Color& color ) {
    	    out << setfill('0')<<color.name<<","<< color.red<<","<< color.green <<","<<color.blue  ;
			return out ;
        }
        friend To_Upper;
};

struct To_Upper{
	Color operator() ( Color a ) const{
		for(int i=0;i<sizeof(a.name);i++){
			if(a.name[i]>='a' && a.name[i]<='z'){
				a.name[i]=a.name[i] -'a'+'A';
			} 
		}
		return a;
	}
};


int main(){
	
	Color foo[] = { Color("black",0,0,0),Color("white",255,255,255) };
	
	//將foo 陣列裡的每個顏色名稱都轉為大寫
    transform(foo,foo+2,ostream_iterator<Color>(cout,"\n"),To_Upper());


	system("pause");
	return 0;
}

