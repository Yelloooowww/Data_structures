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
        if ( ! infile ) {cout<<"end~" ; break;} //���� 
        
        instr.str(line) ;
        if ( line.size() == 0 ) {
            cout << "^^^^^^^^^^^^\n" ; //���q�Ť@�� 
            continue ;
        }
        
        while ( 1 ) {
            
            while( instr.peek() == ' ' ) {
                instr.ignore(1) ;//��w�İϲM�� 
                cout << " " ;//�r���} 
            }
        
            instr >> word ;
            if ( ! instr ) {temp++;cout<<"!!!"; break ;}//�q������ 

            
            cout << word ;
            
        }

//        cout << endl ;
        
        instr.clear() ;
    }
    cout<<temp;
    
	system("pause");
	return 0;
}
