#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include<cassert>
using namespace std ;

template <typename T>
struct Node {
    T data ;
    Node<T> *left , *right ;
    Node( const T& d ) : data(d) , left(NULL) , right(NULL) {}
    bool  is_leaf_node() const {
        return  ( left == NULL && right == NULL ) ? true : false ;
    }

    template <typename S>
    friend ostream& operator<<( ostream& out , const Node<S>& foo){
        return out << foo.data ;
    }
} ;

template <typename T>
class BST{
private:
  Node<T> *root;
  void  print_subtree( ostream& out , const Node<T>* ptr , int depth=1 ) const{
      if ( ptr == NULL ) {
          out << setw((depth-1)*10) << "|------> "<< left << "." << right << "\n" ;
      } else {
          if ( depth > 1 ) out << setw((depth-1)*10) << "|------> " ;
          out  << left << ptr->data << right << endl ;
          if ( ! ptr->is_leaf_node() ) {
              print_subtree( out , ptr->right , depth+1 ) ;
              print_subtree( out , ptr->left , depth+1 ) ;
              if ( ptr->left == NULL || ( ptr->left != NULL && ptr->left->is_leaf_node() ) ) out << endl ;
          }
      }
  }

public:
  BST():root(NULL){}
  ~BST(){}


  void sub_tree_sum(Node<T> *ptr,T& sum){
    if(ptr != NULL){
      sum= sum + ptr->data;
      sub_tree_sum(ptr->left,sum);
      sub_tree_sum(ptr->right,sum);
    }
  }
  T sum(){
    T sum(1,1);
    sub_tree_sum(root,sum);
    return sum-(1,1);
  }
  void leaf(Node<T> *ptr,T& sum){
    if(ptr != NULL){
      if(ptr->is_leaf_node()) {
        sum= sum + ptr->data;
      }
      leaf(ptr->left,sum);
      leaf(ptr->right,sum);
    }
  }
  T leaf_sum(){
    T sum(1,1);
    leaf(root,sum);
    return sum-(1,1);
  }



  void  insert ( const T& d ){
      Node<T> *tmp = new Node<T>(d) ;
      Node<T> *p = root , *q ;
      if ( root == NULL )
          root = tmp ;
      else {
          while( p != NULL ) {
              q = p ;
              p =  ( p->data < tmp->data ? p->right : p->left ) ;
          }
          if ( q->data < tmp->data )
              q->right = tmp ;
          else
              q->left = tmp ;
      }
  }

  template <typename S>
  friend ostream& operator<<( ostream& out , const BST<S>& foo ){
      foo.print_subtree( out , foo.root ) ;
      return out ;
  }
};

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

  friend bool operator< (const Fraction& foo,const Fraction& bar){
    return ( foo.get_num()*bar.get_den() < bar.get_num()*foo.get_den() );
  }
  friend ostream& operator<< (ostream& out, const Fraction& foo){
    return out<<"("<<foo.get_num()<<"/"<<foo.get_den()<<")";
  }
};

int main(){

  BST<Fraction>  foo ;
  Fraction  frac ;
  int  n , d ;
  for ( int i = 0 ; i < 10 ; ++i ) {
      while ( 1 ) {
          n = rand()%9+1 ;
          d = rand()%8+2 ;
          if ( n%d ) break ;
      }
      // cout <<Fraction(n,d)<<" ";
      foo.insert(Fraction(n,d)) ;
  }
  cout << foo << endl ;

  // 計算所有的分數和
  cout <<"foo.sum()=  "<< foo.sum() << endl ;

  // 計算末端節點的數字和
  cout << "foo.leaf_sum()=  "<<foo.leaf_sum() << endl ;



  return 0;
}
