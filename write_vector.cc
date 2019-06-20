#include<iostream>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<cassert>
#include<iomanip>
using namespace std;

template <typename T>
class Vector{
private:
  T* data;
  int rsize;
  int osize;
public:
  Vector() :data(NULL),rsize(0),osize(0){}
  Vector( const T* from, const T* to):rsize(0),osize(0),data(NULL){
    for(const T* a=from;a!=to;++a) push_back(*a);
  }
  Vector( const Vector<T>& foo){
    rsize=foo.rsize;
    osize=foo.osize;
    data=( rsize>0 ? new T[rsize]:NULL);
    for( int i=0;i<osize;++i) data[i]=foo.data[i];
  }

  const T* begin() const {return data;}
  const T* end() const {return data+osize;}

  const T& front() const { assert(osize>0);return data[0];}
  T& front() {assert(osize>0);return data[0];}
  const T& back() const { assert(osize>0);return data[osize-1];}
  T& back() {assert(osize>0);return data[osize-1];}

  Vector& operator=( const Vector<T>& foo){
    if( this == &foo ) return *this;
    if(foo.osize==0){
      osize=0;
      return *this;
    }

    int i;
    if( foo.rsize== rsize || foo.osize<=rsize){
      osize=foo.osize;
      for( i=0;i<osize;++i) data[i]=foo.data[i];
    }
    else{
      delete [] data;
      rsize=foo.rsize;
      osize=foo.osize;
      data=new T[rsize];
      for(i=0;i<osize;++i) data[i]=foo.data[i];
    }
    return *this;
  }

  ~Vector() { if(rsize>0) delete [] data;}

  T& operator[] (int i) {return data[i];}
  const T& operator[] (int i) const{return data[i];}

  int size() const {return osize;};

  int capacity() const {return rsize;}

  void clear() {osize=0;}

  void push_back( const T& foo){
    if(osize>=rsize){
      rsize=( rsize ? 2*rsize :1);
      T* ptr = new T[rsize];
      for( int i=0;i<osize;++i) ptr[i]=data[i];
      ptr[osize]=foo;
      delete [] data;
      data=ptr;
    }
    else{
      data[osize]=foo;
    }
    ++osize;
  }
  void pop_back() { if(osize>0) --osize;}

  void resize(int nsize,const T& val){
    if( nsize< osize){
      osize=nsize;
    }
    else if(nsize<=rsize){
      for(int i=osize;i<nsize;++i) data[i]=val;
      osize=nsize;
    }
    else{
      int i;
      rsize=2*nsize;
      T* ptr=new T[rsize];
      for(i=0;i<osize;++i) ptr[i]=data[i];
      for(i=osize;i<nsize;++i) ptr[i]=val;
      delete [] data;
      data=ptr;
      osize=nsize;
    }
  }
};



int main(){
  const int N=10;
  int i,j;
  int no[N]={1,2,3,4,5,6,7,8,9,10};
  Vector<int> foo;

  

  for(i=0;i<foo.size();++i){
    cout<<"front: "<<foo.front()<<endl;
    cout<<"back: "<<foo.back()<<endl;
    cout<<"begin: "<<foo.begin()<<endl;
    cout<<"end: "<<foo.end()<<endl;

    cout<< foo.size() <<"->" <<foo.capacity()<<endl;
  }






  return 0;
}
