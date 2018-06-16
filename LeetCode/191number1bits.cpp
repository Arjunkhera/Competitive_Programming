#include<iostream>

using namespace std;

// unsetting right most set bit
int hammingWeight(uint32_t n){
  int answer = 0;
  while(n){ n = n&(n-1);answer++;}
  return answer;
}

// brute force
int hammingWeight2(uint32_t n){
  int answer = 0;
  while(n){ answer += n&1; n>>=1; }
  return answer;
}

int main(){

  uint32_t n;
  cin>>n;
  cout<<hammingWeight2(n)<<endl;
  return 0;
}
