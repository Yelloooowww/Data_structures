#include<iostream>
#include<cassert>
using namespace std;

template<typename T>
struct Node{
  T data;
  Node<T>* fptr;
  Node<T>* bptr;
  Node(){}
  Node( const T& no):data(no) {}
};

template<typename T>
Node<T>* make_node(const T& no=0){
  Node<T>* ptr=new Node<T>(no);
  ptr -> fptr  =  ptr -> bptr  = NULL;
  return ptr;
}

template<typename T>
class List{
private:
  Node<T>* head;
  Node<T>* tail;
  int osize;
  Node<T>* nptr;
public:
  List(): head(NULL),tail(NULL),osize(0),nptr(NULL) {}
  List( const T* from,const T* to): head(NULL),tail(NULL),osize(0),nptr(NULL){
    for( const T* a=from;a!=to;++a)   push_back(*a);
  }

  const Node<T>* begin() const{ return head;}
  Node<T>* begin() { return head;}
  const Node<T>* end() const{ return nptr;}
  Node<T>* end() { return nptr;}
  const List<T>& operator->() const{return *this;}
  List<T>& operator->() {return *this;}

  List<T>& operator=(const List<T>& foo){
    if(this== &foo) return *this;
    if(head!=NULL) clear();
    Node<T>* ptr=foo.head;
    while(ptr!=NULL){
      push_back(ptr->data);
      ptr = ptr->fptr;
    }
    osize=foo.osize;
    return *this;
  }

  List<T>& operator+(const List<T>& a ){
    for( const Node<T>* p=a.begin();p!=a.end(); p=p->fptr){
      push_back(p->data);
    }
    return *this;
  }

  void clear() {while(head!= NULL) pop_back();}
  void push_back(const T& foo){
    Node<T>* ptr=make_node(foo);
    if(head==NULL){
      head=tail=ptr;
    }else{
      tail->fptr = ptr;
      ptr->bptr = tail;
      tail=ptr;
    }
    ++osize;
  }
  void pop_back(){
    if(osize!=0){
      if(osize==1){
        delete head;
        head=tail=NULL;
      }else{
        Node<T>* p = tail -> fptr;
        p -> bptr =NULL;
        delete head;
        head = p;
      }
      --osize;
    }
  }


  friend ostream& operator<< (ostream& out,const List<T>& foo){
    const Node<T>* p;
    for( p= foo.begin() ; p!= foo.end(); p= p->fptr){
      out<< p->data <<" ";
    }
    return out;
  }

  ~List() { clear();}

};

class Point{
private:
  int x,y;
public:
  Point(){}
  Point(int xx=0,int yy=0): x(xx),y(yy) {}
  ~Point() {}

  friend ostream& operator<<(ostream& out,const Point& foo){
    return out<<"("<<foo.x<<","<<foo.y<<")";
  }
};
int main(){

  Point pts[] = { Point(2,3) , Point(6,5) , Point(1,2) , Point(9,2) };

  List<Point>  foo(pts,pts+4) ;
  cout << foo << endl ;
  List<Point>  bar ;
  bar.push_back(Point(3,3));
  // cout<< bar<<endl;
  List<Point>  ss ;
  ss = foo + bar ;     // 將兩個 list 加起來
  cout << ss << endl ;

  return 0;
}
