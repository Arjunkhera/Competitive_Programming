// leetcode question 172

#include<iostream>
#include<cmath>

using namespace std;

int trailingZeroes(int n){
  int answer = 0;
  while(n){
    answer += n/5;
    n /= 5;
  }
  return answer;
}

int main(){
  int n; cin>>n;
  cout<<trailingZeroes(n)<<"\n";

  return 0;
}
