#include<iostream>
#include<cmath>

using namespace std;

// be careful of integer overflow : for a faster method check leetcode pow question
int mypower(int base,int exponent){
  int answer = 1;
  while(exponent){
    if(exponent & 1) answer = answer*base;
    exponent >>= 1;
    base *= base;
  }
  return answer;
}

int main(){

  int base,exponent;
  cin>>base>>exponent;

  // built in function : works only for floats, can result in precision loss
  cout<<pow(base,exponent)<<endl;

  // using exponentiation by squaring
  cout<<mypower(base,exponent)<<endl;

  return 0;
}
