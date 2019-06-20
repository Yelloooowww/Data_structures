#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <iomanip>
#include<sstream>
#include<fstream>
using namespace std;

int main(){
	
    ifstream  infile("adventure.txt") ;
    
    string         line , word ;
    istringstream  instr ;

    int temp;
    
    
    while ( 1 ) {
        
        getline( infile , line ) ;
        if ( ! infile ) {cout<<"end~" ; break;} //結束 
        
        instr.str(line) ;
        if ( line.size() == 0 ) {
            cout << "^^^^^^^^^^^^\n" ; //分段空一行 
            continue ;
        }
        
        while ( 1 ) {
            
            while( instr.peek() == ' ' ) {
                instr.ignore(1) ;//把緩衝區清空 
                cout << " " ;//字分開 
            }
        
            instr >> word ;
            if ( ! instr ) {temp++;cout<<"!!!"; break ;}//段落結束 

            
            cout << word ;
            
        }

//        cout << endl ;
        
        instr.clear() ;
    }
    cout<<temp;
    
	system("pause");
	return 0;
}
