#include<iostream>
#include<string>
#include<cassert>
#include<stdlib.h>
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

  Fraction operator+(const Fraction&a){
    int den=a.get_den() * get_den();
    int num=a.get_num()*get_den()+a.get_den()*get_num();
    return Fraction(num,den);
  }
  Fraction operator-(const Fraction&a){
    int den=a.get_den() * get_den();
    int num=a.get_den()*get_num()-a.get_num()*get_den();
    return Fraction(num,den);
  }
  Fraction operator*(const Fraction&a){
    int den=a.get_den() * get_den();
    int num=a.get_num() * get_num();
    return Fraction(num,den);
  }
  Fraction operator/(const Fraction&a){
    int den=a.get_num()*get_den();
    int num=a.get_den()*get_num();
    return Fraction(num,den);
  }
  friend ostream& operator<< (ostream& out, const Fraction& foo){
    return out<<foo.get_num()<<"/"<<foo.get_den();
  }
};

//堆疊類別
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

//平衡括號組
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
    // cout<<"balance~~~";
    return true;
  }else{
    cout<<"not balance~";
    return false;
  }
}

//用Stack算出答案
Fraction calculate(string& q){
  assert( balance(q) );

  Stack<int> integer;
  Stack<Fraction> frac;
  Stack<char> operand;
  for(int i=0;i<q.size();++i){
    if( q[i]>='0' && q[i]<='9'){
      integer.push( static_cast<int>( q[i] )-48  );
    }
    if( integer.size() >=2){
      if( q[i]=='+' || q[i]=='-' || q[i]=='*'||q[i]==')'){
        int a=integer.Top();
        integer.pop();
        int b=integer.Top();
        integer.pop();
        frac.push( Fraction(b,a));
      }
    }
    if( integer.size() ==0){
      if( q[i]=='+' || q[i]=='-' || q[i]=='*' || q[i]=='/'){
        operand.push(q[i]);
      }
      if( q[i]== ')' ){
        Fraction a,b,c;
        a=frac.Top();
        frac.pop();
        b=frac.Top();
        frac.pop();
        if( operand.Top()=='+'){
          c= a+b;
        }else if( operand.Top()=='-'){
          c= b-a;
        }else if( operand.Top()=='*'){
          c= a*b;
        }else if( operand.Top()=='/'){
          c= b/a;
        }
        frac.push(c);
        operand.pop();
      }
    }
  }
  return frac.Top();
}


int main(){

  string q1= "( ( 3/2 + 4/6 ) * 2/3 )";
  cout<<"Question1= "<<q1<<endl;
  cout<< "Ans1= "<<calculate(q1)<<endl;
  string q2= "( ( ( ( 3/2 + 4/6 ) * 2/3 ) / ( 3/4 - 1/8 ) ) + 1/3 )";
  cout<<"Question2= "<<q2<<endl;
  cout<<"Ans2= "<<calculate(q2)<<endl;



  return 0;
}
