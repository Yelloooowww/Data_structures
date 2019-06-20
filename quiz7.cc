#include<iostream>
#include<string>
#include<sstream>
using namespace std;

template<typename T>
class Stack{
private:
  int top;
  int capacity;
  T *stack;
  void DoubleCapacity(){
    capacity *=2;
    T *newstack= new T[capacity];
    for(int i=0;i< capacity/2 ;++i){
      newstack[i]=stack[i];
    }
    delete [] stack;
    stack =newstack;
  }
public:
  Stack():top(-1),capacity(1){
    stack= new T[capacity];
  }
  ~Stack(){}


  void push(T foo){
    if(top== capacity-1) DoubleCapacity();
    ++top;
    stack[top] =foo;
  }
  void pop(){
    if( IsEmpty()) cout<<"The stack if empty!!!"<<endl;
    else --top;
  }
  int size(){
    return top+1;
  }
  T Top(){
    if( IsEmpty()){
      return -1;
    }else{
      return stack[top];
    }
  }
  bool IsEmpty(){
    if(top== -1){
      return true;
    }
    else return false;
  }
};

bool balance(string& in){
  Stack<char> b;
  for(int i=0;i<in.size();++i){
    if(in[i]=='{' ||in[i]=='[' ||in[i]=='('){
      b.push( in[i] );
    }else if(in[i]=='}' ||in[i]==']' ||in[i]==')'){
      if(in[i]=='}'){
        if(b.Top() == '{') b.pop();
        else{
          cout<<"not balance~";
          return false;
        }
      }else if(in[i]==']'){
        if(b.Top() == '[') b.pop();
        else{
          cout<<"not balance~";
          return false;
        }
      }else if(in[i]==')'){
        if(b.Top() == '(') b.pop();
        else{
          cout<<"not balance~";
          return false;
        }
      }
    }
  }
  if(b.size()==0){
    cout<<"balance~~~";
    return true;
  }else{
    cout<<"not balance~";
    return false;
  }
}

int main(){
  while (1) {
    cout<<"input:"<<endl;
    string in;
    cin >>in;
    cout<< in<<endl;
    balance(in);
  }


  return 0;
}
