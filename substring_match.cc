#include<iostream>
using namespace std;
int main(){
	
	char str[]="ACGTGTCATGTGTGATCGTGTACGTACACACGTGCATGCATGTAGTCGTGT";
    char substr[100];
	
	cout<<">input string";
	cin>> substr;
	
	bool found ;
	int count=0;
	int i,j;
	int len,len1,len2;
	
	len1=0;
	while(str[len1]!=0) len1++;
	len2=0;
	while(substr[len2]!=0) len2++;
	
	cout<<str<<endl;
	
	len=len1-len2+1;
	
	for(i=0;i<len;++i){
		found=true;
		for(j=0;j<len2;j++){
			if (str[i+j]!=substr[j]){
				found=false;
				break;
			}
		}
		if(found) ++count;
		cout<< (found ? "^":" ");
	}
	cout<<"\n>find times:"<<count<<endl;
	return 0;
}
