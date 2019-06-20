#include <iostream>
#include <string>
#include <iterator>
#include<sstream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
using namespace std;

void word_adjust();
string word;

int main(){
	ifstream infile("adventure.txt");
	istringstream istr;
	string line;
    set<string> part;
    map< int,set<string> > total;
    vector<set<string> > all;

	char flag_next;

	while(1){
		getline(infile,line);
		if(!infile) break;

		istr.str(line);
		if(line.size()==0) continue;

		while(1){
			while(istr.peek()==' '){
				istr.ignore(1);
			}
			istr >> word;

			word_adjust();//�j�g���p�g �h�Y�����I

			part.insert(word);
			word.clear();

			if (! istr)	{
			flag_next=1;//�U�@�q����
			break;}
		}
		istr.clear();

		if(flag_next=1){
			all.push_back(part);//�N�q�����Ʀs�Jall
            part.clear();
            flag_next=0;
		}
	}
	infile.close() ;

	int c1,c2;
	set<string> ans;
	set<string>::iterator c1iter,c2iter,iitteerr,ansiter;
	pair<set<string>::iterator,set<string>::iterator> eqiter;
	while(1){
		cout<<"input(1~7):"<<endl;
		cin>>c1;
    	cout<<"input(1~7):"<<endl;
		cin>>c2;
	    cout<<c1<<"&&"<<c2 <<endl;
	    for(c1iter=all[c1-1].begin();c1iter!=all[c1-1].end();++c1iter){
		    eqiter=all[c2-1].equal_range( *c1iter);
	        for(iitteerr=eqiter.first;iitteerr!=eqiter.second;++iitteerr){
		        ans.insert( *iitteerr);
	        }
	    }
	    cout<< ans.size()-1<<":";
        for(ansiter=ans.begin();ansiter!=ans.end();++ansiter) cout<< *ansiter<<" ";
        cout<<endl;
        ans.clear();
	}

//	system("pause");
	return 0;
}

void word_adjust(){
	//���p�g
	for(int l=0;l<word.size() ;l++){
		if(word[l]<='Z' && word[l]>='A' ) {
			word[l]=word[l]-'A'+'a';
		}
	}
	//�h�Y���I
	if(word[0]>'z' || word[0]<'A'){
		for(int p=0;p<word.size();++p) word[p]=word[p+1];
		word[word.size()-1]='\0';
		word.erase( word.size() );
	}
	//�h�����I
	if(word[word.size()-1]>'z' || word[word.size()-1]<'A'){
		word[word.size()-1]='\0';
		word.erase(word.size());
	}
}
