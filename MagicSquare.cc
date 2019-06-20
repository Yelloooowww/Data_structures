//魔術方針~~~各行 各列 對角線之合皆相等
#include<iostream>
#include<stdio.h>
int main()
{
	int i,j;
    int p,q;
    int key;
    int N;
	printf("input N\n");
	scanf("%d",&N);
	int square[N][N];

	for(int a=0;a<N;a++)//初始化陣列
	{
		for(int b=0;b<N;b++)
		{
			square[a][b]=0;
		}
	}

//	先填入1
	key=1;
	i=0;
	j=(N-1)/2;
	square[i][j]=key;
	key++;

	while(key<=N*N)
	{
		for(int m=0;m<N;m++)
    	{
	    	for(int n=0;n<N;n++)
		    {
			    printf("  %2d",square[m][n]);
    		}
	    	printf("\n");
	    }

		p=i-1;
		q=j-1;
		if(p>=0&&q>=0)//沒有超出方陣
		{
			printf("1\n");
			if(square[p][q]!=0)//已經有數字了
			{
				p=i+1;
				q=j;
				square[p][q]=key;
				i=p;
				j=q;
			}
			else
			{
				printf("2\n");
				p=i-1;
		        q=j-1;
		        square[p][q]=key;
				i=p;
				j=q;
			}
		}

		if(p<0&&q>=0)
		{
			printf("3\n");
			p=N-1;
			q=j-1;
			square[p][q]=key;
			i=p;
			j=q;
		}
		if(q<0&&p>=0)
		{
			printf("4\n");
			q=N-1;
			p=i-1;
			square[p][q]=key;
			i=p;
			j=q;
		}
		if(q<0&&p<0)
		{
			printf("6\n");
			p=i+1;
			q=j;
			square[p][q]=key;
			i=p;
			j=q;
		}
		else
		{
		    printf("5\n");
			square[p][q]=key;
			i=p;
			j=q;
		}
		key++;
	}

	for(int m=0;m<N;m++)
    	{
	    	for(int n=0;n<N;n++)
		    {
			    printf("  %2d",square[m][n]);
    		}
	    	printf("\n");
	    }

      system("pause");
      return 0;

}
