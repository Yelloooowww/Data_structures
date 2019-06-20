#include <iostream>
#include <map>
#include<set>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<vector>
using namespace std;


int main(){
  setlocale(LC_ALL,"zh_TW.UTF-8") ;


  wifstream infile("strokes.txt");
  infile.imbue(locale("zh_TW.UTF-8"));
  wistringstream istr;
  wstring line,see,idioms;
  int num;
  wchar_t  wch ;int c;

  multimap<wchar_t,int> word_strokes;
  while ( getline(infile,line)) {
    istr.str(line);
    istr >> see >>num;
    istr.clear();

    wstring b = see.substr(2) ;
    istr.str(b);
    istr >> hex >> c ;
    istr.clear();
    word_strokes.insert( make_pair(static_cast<wchar_t>(c) ,num) );
  }
  infile.close();


  multimap<int, wstring > ans;
  int total;

  pair<multimap<wchar_t,int>::iterator, multimap<wchar_t,int>::iterator > piter;
  multimap<wchar_t,int>::iterator ii;

  wifstream infile1("idioms.txt");
  infile1.imbue(locale("zh_TW.UTF-8"));
  while ( getline(infile1,line)) {
    istr.str(line);
    istr>>idioms;
    total=0;
    istr.clear();
    for(int j=0;j<4;j++){
      piter= word_strokes.equal_range( idioms[j] );
      for(ii=piter.first; ii!=piter.second; ++ii){
        total+= ii->second;
      }
    }

    ans.insert(make_pair(total,idioms));
  }

  multimap<int, wstring >::iterator aiter;
  int temp;
  for(aiter=ans.begin();aiter!=ans.end();++aiter){
    if( aiter->first != temp){
      temp=aiter->first;
      wcout<<endl<<aiter->first<<L"畫: ";
    }
    wcout<<aiter->second<<" ";
  }



  return 0;
}
