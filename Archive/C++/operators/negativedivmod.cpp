#include<iostream>
#include<vector>

using namespace std;

int main(){
  // division always truncates towards zero
  // modulus always takes sign of left operand

  int a = -5;
  int b = 2;
  // numerator negative
  cout<<a/b<<" : "<<a%b<<endl;

  // denominator negative
  a = -a; b = -b;
  cout<<a/b<<" : "<<a%b<<endl;

  // both negative
  a = -a;
  cout<<a/b<<" : "<<a%b<<endl;

  // both positive
  a = -a; b = -b;
  cout<<a/b<<" : "<<a%b<<endl;

  return 0;
}
