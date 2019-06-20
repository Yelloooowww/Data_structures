#include<iostream>
using namespace std;

template<typename T>
struct Node{
  T data;
  Node<T> *next;
  Node<T>(const T&foo):data(foo){next=NULL;}
};
template<typename T>
ostream& operator<< (ostream& out, const Node<T>&foo){
  return out<<foo->data;
}
template<typename T>
Node<T>* made_node(const T&a){
  Node<T> *ptr=new Node<T>(a);
  return ptr;
}

template<typename T>
class Queue{
private:
  Node<T> *head,*tail;
  int nsize;
public:
  Queue():nsize(0){head=tail=NULL;}

  void push(const T& a){
    if(empty()){
      head = new Node<T>(a);
      tail=head;
      nsize++;
    }else{
      Node<T> *newnode=new Node<T>(a);
      tail->next =newnode;
      tail=newnode;
      nsize++;
    }
  }
  T front() const {
    return (empty()? -1:head->data);
  }
  void pop() {
    if(empty()){
      cout<<"Is empty!!!"<<endl;
    }else{
      Node<T> *popnode=head;
      head= head->next;
      nsize--;
    }
  }
  int  size() const {
    return nsize;
  }
  bool  empty() const {
    return( nsize==0 );
  }
};


int main() {
    Queue<int>  foo ;
    int i ;
    for ( i = 1 ; i <= 5 ; ++i ) {
        foo.push(i) ;
    }
    while ( ! foo.empty() ) {
        cout << foo.front() << endl ;
        foo.pop() ;
    }
    for ( i = 10 ; i >= 1 ; --i ) {
        foo.push(i) ;
    }
    while ( ! foo.empty() ) {
        cout << foo.front() << endl ;
        foo.pop() ;
    }
    return 0 ;
}
