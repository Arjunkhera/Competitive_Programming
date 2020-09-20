#include<iostream>

using namespace std;

// brute force : works well here
uint32_t reverseBits(uint32_t n){
  uint32_t answer = 0,count = sizeof(answer)*8;
  while(n){ answer <<=1; if(n&1) answer ^= 1; n >>=1; count--;}
  while(count--) answer <<=1;
  return answer;
}

int main(){

  uint32_t n;
  cin>>n;
  cout<<reverseBits(n)<<endl;
  return 0;
}
