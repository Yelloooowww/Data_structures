#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<functional>
using namespace std;

//分數類別
class Fraction{
private:
  int num;//分子
  int den;//分母

  //最大公因數
  int gcd(int num,int den) const {
    if( abs(num)>= abs(den)){
      return (abs(num)%abs(den)==0 ? abs(den) : gcd(abs(den),abs(num)%abs(den)));
    }
    else{
      return (abs(den)%abs(num)==0 ? abs(num) : gcd(abs(num),abs(den)%abs(num)));
    }
  }
  //約分化簡
  void simplify(){
    int tmp1=num/gcd(num,den);
    int tmp2=den/gcd(num,den);
    num = tmp1;
    den = tmp2;
  }

public:
  Fraction(){}
  Fraction(int n,int d=1):num(n),den(d){
    assert( d!=0);
    simplify();
    if(d<0){num *= -1;den *= -1;}
  }
  ~Fraction(){}

  int get_num() const{return num;}
  int get_den() const{return den;}

  bool operator< (const Fraction&a)const{
    if( num*a.get_den() < den*a.get_num()) return true;
    else return false;
  }

  friend ostream& operator<< (ostream& out, const Fraction& foo){
    return out<<foo.get_num()<<"/"<<foo.get_den();
  }
};

template<typename T >
class Priority_Queue{
private:
  vector<T> data;
  int leftson(int i) const{return 2*i+1;}
  int rightson(int i) const {return 2*i+2 ;}
  int parent(int i) const{return (i-1)/2 ;}
  bool tree_node(int i)const{
    return (i<data.size()? true:false) ;
  }

  void reheap_downward(int i=0){
    int p,q,j;
    T s;
    while(1){
      p=leftson(i);
      q=rightson(i);
      if(tree_node(q)){
	      s=((data[p] < data[q])?data[q]:data[p]);
	      if((data[i]<s)){
	        j=(  (data[p] < data[q]) ? q:p);
	        swap(data[i],data[j]);
	        i=j;
	      }else break;
      }else if(tree_node(p)){
        if(data[i] < data[p]) {
	          swap(data[i],data[p]);
	          i=p;
	        }else break;
	    }else break;
    }
  }

  void reheap_upward(int i=0){
    int p=parent(i);
    while((data[p] <data[i])){
      swap(data[p],data[i]);
      i=p;
      if(i==0) return;
      p=parent(i);
    }
  }
public:
  Priority_Queue(){}
  Priority_Queue(const T* a,const T* b){
    for(;a!=b;++a) push(*a);
  }
  int size() const{return data.size();}
  void push(const T& a){
    data.push_back(a);
    reheap_upward(size()-1);
  }
  void pop(){
    data.front()=data.back();
    data.pop_back();
    reheap_downward(0);
  }

  void Priority_Queue_Output() {
    int tmp=size();
    for(int i=0;i<tmp;++i){
      cout<<data[0]<<" ";
      pop();
    }
  }

  friend ostream& operator<< (ostream& out,const Priority_Queue&foo){
     for(int i=0;i<foo.data.size();++i){
      out<<foo.data[i]<<" ";
      }
    return out ;
  }

};

int main(){
  Priority_Queue<Fraction> foo;
  //隨機產生10個分數
  cout<<"Initial: "<<endl;
  for(int i=0;i<10;++i){
    int n=rand()%9+1;
    int d=rand()%9+1;
    cout<<Fraction(n,d)<<" ";
    foo.push( Fraction(n,d));
  }

  cout<<endl;
  cout<<"Priority_Queue:"<<endl;
  foo.Priority_Queue_Output();

  return 0;
}
