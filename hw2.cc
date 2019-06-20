#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<vector>
#include<queue>
using namespace std;

class  RGB {
  private :
    wstring      color ;
    vector<int>  rgb ;

  public :

    RGB( const wstring& cname , vector<int>& crgb ) :
       color(cname) , rgb(crgb) {}

    int  operator[]( int i ) const { return  rgb[i] ; }

    friend  wostream&  operator<< ( wostream& wout , const RGB& foo ) {
        wout<< foo.color <<" "<<foo.rgb[0]<<" "<<foo.rgb[1]<<" "<<foo.rgb[2]<<endl;
        return  wout ;
    }

    friend  bool operator<( const RGB& a , const RGB& b ) {
       if(a.rgb[0] != b.rgb[0]) return a.rgb[0] < b.rgb[0];
       else if(a.rgb[1] != b.rgb[1]) return a.rgb[1] < b.rgb[1];
       else return a.rgb[2] < b.rgb[2];
     }
};

int main(){
vector<RGB>  rgb ;
priority_queue<RGB,deque<RGB>,less<RGB> >  prgb ;

wifstream  infile("rgb.txt") ;
wstring   line ,name;
wistringstream  istr ;
vector<int> rgb_num;
int r,g,b;

while ( getline(infile,line) ) {
    istr.str(line) ;
    istr >> name >> r>>g>>b;
    // wcout <<name<<":"<< r<<" "<<g<<" "<<b<<endl;
    rgb_num.push_back(r);
    rgb_num.push_back(g);
    rgb_num.push_back(b);
    istr.clear();
    prgb.push( RGB(name,rgb_num));
    rgb_num.clear();
}
infile.close();

while ( prgb.size() ) {
    wcout << prgb.top() << endl ;
    prgb.pop() ;
}
wcout << endl ;

return 0 ;
}
