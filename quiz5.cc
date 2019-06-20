#include<iostream>
#include<sstream>
#include<cassert>
#include<iterator>
#include<iomanip>
using namespace std;

template<typename T>
class Vector{
private:
  T* data;
  int osize;
  int rsize;
public:
  Vector(): osize(0),rsize(0),data(NULL) {}
  Vector(  T* from, T* to):osize(0),rsize(0),data(NULL){
    for(T* a=from; a!=to;++a) push_back(*a);
  }
  Vector(int s, const T& v=0):osize(s),rsize(2*s){
    if(rsize==0) data=NULL;
    else{
      data=new T[rsize];
      for(int i=0;i<osize;++i) data[i]=v;
    }
  }
  Vector( const Vector<T>& foo){
    osize=foo.osize;
    rsize=foo.rsize;
    if(rsize>0){
      data=new T[rsize];
      for(int i=0;i<osize;++i) data[i]=foo.data[i];
    }
    else data=NULL;
  }
  ~Vector() { if(rsize>0) delete [] data;}

  int size() {return osize;}
  int capacity() {return rsize;}

  const T& front() const{assert(osize>0);return data[0]; }
  T& front() {assert(osize>0);return data[0]; }
  const T& back() const{assert(osize>0);return data[osize-1]; }
  T& back() {assert(osize>0);return data[osize-1]; }

  const T& operator[] (int i)const{return data[i];}
  T& operator[] (int i){return data[i];}


  Vector<T>& operator = (Vector<T>& foo){
    if(this== &foo) return *this;
    else if(foo.osize==0){osize=0;return *this;}
    else{
      if(foo.osize>rsize){
	rsize=foo.rsize;
	osize=foo.osize;
	delete [] data;
	data=new T[rsize];
	for(int i=0;i<osize;++i) data[i]=foo.data[i];
      }
      else{
	rsize=foo.rsize;
	osize=foo.osize;
	for(int i=0;i<osize;++i) data[i]=foo.data[i];
      }
      return *this;
    }
  }

  void push_back(T& a){
   if(osize>=rsize){
      rsize=(rsize? 2*rsize:1);
      T* ptr=new T[rsize] ;
      for(int i=0;i<osize;++i) ptr[i]=data[i];
      ptr[osize]=a;
      delete [] data;
      data=ptr;
   }else{
     data[osize]=a;
   }
    osize+=1;
  }

  void pop_back() {
    if(osize>0){
      --osize;
    }
  }


  void resize(int s, const T& val) {
    if(s>rsize){
      rsize=2*s;
      T* ptr=new T[rsize];
      for(int i=0;i<osize;++i) ptr[i]=data[i];
      for(int i=osize;i<s;++i) ptr[i]=val;
      osize=s;
      delete [] data;
      data=ptr;
    }
    else{
      for(int i=osize;i<s;++i) data[i]=val;
      osize=s;
    }

  }



  void clear() { if(rsize>0) data=NULL;}
};

int main(){

  int n=10;
  int num[10]={1,2,3,4,5,6,7,8,9,10};
  Vector<int> foo;

    for(int i=0;i<n;++i){
     foo.push_back(num[i]);
     }

  Vector<int> bar(num,num+n);

  foo.pop_back();

  cout<<foo.front()<<" "<<foo.back()<<endl;

  bar=foo;

  cout<<foo.size()<<" "<<foo.capacity()<<endl;

  foo.resize(15,0);

  cout<<foo.size()<<" "<<foo.capacity()<<endl;

  Vector<int> A(10.0);
  Vector<int> B(bar);

  foo.clear();
  bar.clear();
  A.clear();
  B.clear();


  return 0;
}
