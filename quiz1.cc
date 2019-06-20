#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
using namespace std;

class Cfrac
{
private:
  vector<int> data;
public:
  void cfrac(int i);
  void frac(int i);
};

void Cfrac::cfrac(int i)
{
	vector<int> Youknow(i);
	for(int k=0;k<i;k++)
	{
		Youknow[k]=k+1; 
		printf("%d ",Youknow[k]);
	}
}

void Cfrac::frac(int j)
{
	int num=1;
    int den=j;
    int add;
  for(int i=j;i>0;i--)
  {
  	add=i-1;
//  	solve();
    num=add*den+num;
//  	reciprocal();
    int temp=den;
	den=num;
	num=temp;
  }
	
	cout<<num<<" / "<<den;
}

int main()
{
  const int M=9;
//  int no[M]={1,2,3,4,5,6,7,8,9};

  Cfrac foo;
   
  for ( int i = 1 ; i <= M ; ++i )
  {
  	foo.cfrac(i);
  	cout<<"= ";
  	foo.frac(i);
  	cout<<endl;
  }

  system("pause");
  return 0;
}
