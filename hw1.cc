#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std ;
struct Location {
    wstring  loc ;
    double   rain ;
    double   weight ;
    Location() {}
    Location( wstring n ) : loc(n) , rain(0) {}
};

wostream&  operator<< ( wostream& out , const Location& foo ) {
    return out << foo.loc << " : " << foo.rain << " mm" ;
}

struct By_Rain {
    bool  operator() ( const Location& a , const Location& b ) {
        return a.rain > b.rain ;
    }
};


int main() {

    // 寬字串與語系請參考第 15 章末尾
    setlocale(LC_ALL,"zh_TW.UTF-8") ;
    vector<Location>  foo ;


    wifstream  infile("rain.dat") ;
    infile.imbue(locale("zh_TW.UTF-8")) ;

    wstring line,temp;
    wistringstream wistr;

    getline(infile,line);
    wistr.str(line);
    while (wistr >> temp) {
      foo.push_back(temp);
    }
    wistr.clear();

    getline(infile,line);
    wistr.str(line);
    while ( wistr >> temp) {
      // I don't need this line;
    }
    wistr.clear();

    double tmp;
    while (getline(infile,line)) {
      wistr.str(line);
      wistr >> temp;
      for(int k=0;k<10;k++){
        wistr >>tmp;
        foo[k].rain =foo[k].rain+tmp;
      }
      wistr.clear();
    }
    infile.close();



    sort( foo.begin() , foo.end() , By_Rain() ) ;
    for ( int i = 0 ; i < foo.size() ; ++i ) {
        wcout << foo[i] << endl ;
    }

    return 0 ;

}
