#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
using namespace std;

class man{
private:
  string name;
  int age;
  int month;
  int date;
public:
  man(){}
  man(string n,int a,int m,int d):name(n),age(a),month(m),date(d){}

  bool operator< (const man& a)const{
    if (name.size()<a.name.size()){
      return true;
    }else if(name.size()==a.name.size()){
      if(name[0]>a.name[0]){
	return true;
      }else if(name[0] == a.name[0]){
	if(name[1]>a.name[1]){
	  return true;
	}else{
	  return false;
	}
      }
    }
  }

  friend ostream& operator<< (ostream& out,const man& who){
    out<<who.name<<" "<<who.age<<" "<<who.month<<"/"<<who.date<<endl;;
    return out;
  }
};


template<typename T,typename LESS=less<T> >
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
	s=(LESS()(data[p],data[q])?data[q]:data[p]);
	if(LESS()(data[i],s)){
	  j=(  LESS()(data[p],data[q]) ? q:p);
	  swap(data[i],data[j]);
	  i=j;
	}else break;
      }else if(tree_node(p)){
	if( LESS()(data[i],data[p]) ){
	  if(LESS()(data[i],data[p]) ){
	    swap(data[i],data[p]);
	    i=p;
	  }else break;
	}
      }else break;
    }
  }

  void reheap_upward(int i=0){
    int p=parent(i);
    while(LESS()(data[p],data[i])){
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
  T top() const{return data[0];}
  void pop(){
    data.front()=data.back();
    data.pop_back();
    reheap_downward(0);
  }

  friend ostream& operator<< (ostream& out,const Priority_Queue&foo){
     for(int i=0;i<1;++i){
      out<<foo.data[i]<<" ";
      }
    return out ;
  }

};

int main(){



  Priority_Queue <man>  foo;
  foo.push(man("Sue", 26, 3,21));
  foo.push(man("Kit", 41, 9,6));
  foo.push(man("Abe" ,32 ,2,5));
  foo.push(man("Lucy", 30, 7,31));
  foo.push(man("Nell",26, 8,16));
  foo.push(man("Olga",25, 3,7));
  foo.push(man("John", 32, 1,11));
  foo.push(man("Ivan", 41,3,25));
  foo.push(man("Kimi",37,5,30));
  foo.push(man("Liz",52,4,27));
  foo.push(man("Toni",47,7,22));
  foo.push(man("Una",18,11,1));

  for(int i=0;i<12;i++){
    cout<<foo<<endl;
    foo.pop();
  }



  return 0;









}
