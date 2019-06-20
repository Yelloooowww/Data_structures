#include<iostream>
#include<stdlib.h>
#include <string>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>

using namespace std ;

int main()
{
  vector<int> foo(10);
  vector<int>::iterator iter;
  for(iter=foo.begin();iter!=foo.end();iter++)
  {
    *iter=rand() %1000;
  }
  // deque<int> foo;
  // for(int i=0; i<10 ;i++)
  // {
  //   foo.push_front(i);
  // }
  // foo.back()=100;
  // foo.front()=1000;
  for(int i=0;i<foo.size();i++)
  {
    cout<<foo[i]<<endl;
  }


  system("pause");
  return 0;
}
