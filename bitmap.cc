#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int main()
{
  int n;
  printf("how area?\n");
  scanf("%d",&n);
  vector<int> no(n);
  vector<int> bitmap(n);

  printf("input data\n");
  for(int i=0;i<n;i++)
  {
  	printf("next:\n");
  	scanf("%d",&no[i]);
  }

  for(int i=0;i<n;i++)
  {
  	int temp;
  	temp=no[i];
  	for(int j=7;j>=0;j--)
  	{
  		bitmap[j]=temp%2;
  		temp=(temp/2);
	}

	for(int i=0;i<=n;i++)
	{
		if(bitmap[i]==1) printf("*");
		else printf(" ");
	}
	printf("\n");
  }

  printf("\nEnd\n" );
  system("pause");
  return 0;
}
