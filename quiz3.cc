#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<vector>
using namespace std;

struct Large_RGB{
	bool operator() (vector<int> a,vector<int> b) {
		if(a[0]!=b[0]) return a[0]>b[0];
		else if(a[1]!=b[1]) return a[1]>b[1];
		else return a[2]>b[2];
	}
};

int main(){
	ifstream infile("rgb.txt");
	istringstream istr;
	string line,name;
	int r,g,b;
	vector<int> rgb;
	typedef multimap<vector<int>,string,Large_RGB > rgbdefine;
    rgbdefine colars;

	while(getline(infile,line)){
		istr.str(line);			

		while(istr>>name>>r>>g>>b){
			rgb.push_back(r);
			rgb.push_back(g);
			rgb.push_back(b);
			colars.insert(make_pair(rgb,name));
			rgb.clear();
		}
		istr.clear();
						
	}
	rgbdefine::iterator iter;

	for(iter=colars.begin();iter!=colars.end();++iter){

		cout << iter->second <<":"  ;
		for(int j=0;j<3;j++) cout<< iter->first[j]  <<" ";
		cout<< endl;
	}
	
	
	
	system("pause");
	return 0;
}
