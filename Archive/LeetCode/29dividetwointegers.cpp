#include<iostream>
#include<climits>

using namespace std;

int divideanotherapproach(int dividend,int divisor){
  if(!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

  long long int temp,quot,divden = labs(dividend),divis = labs(divisor);
  int result = 0;
  int sign = ((dividend < 0)^(divisor < 0))?-1:1;

  while(divden >= divis){
    temp = divis;
    quot = 1;
    while(divden >= (temp << 1)){
      temp <<= 1;
      quot <<= 1;
    }

    divden -= temp;
    result += quot;
  }
  return (sign == 1)?result:-result;
}

int divide(int dividend, int divisor){
  if(!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

  long long int tempdiv,temp = 0,divden = labs(dividend),divis = labs(divisor);
  int result = 0;
  int sign = ((dividend < 0)^(divisor < 0))?-1:1;

  for(int i = 31;i >= 0; i--){
    tempdiv = temp + divis<<i;
    if( tempdiv <= divden){
      temp += divis<<i;
      result |= 1ll << i;
    }
  }
  return (sign == 1)?result:-result;
}

int main(){
  int dividend,divisor;
  cin>>dividend>>divisor;

  cout<<divide(dividend,divisor)<<endl;
  return 0;
}
