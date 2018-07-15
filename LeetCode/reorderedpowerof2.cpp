#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>

typedef long int li;
using namespace std;

bool isPowerof2(int N){
  bool flag = true;
  while(N != 1){
    if(N & 1){ flag = false; break; }
    N >>= 1;
  }
  return flag;
}

bool reorderedPowerOf2(int N){
  if(isPowerof2(N)) return true;

  vector<int> digits;
  int temp = N; bool flag = false;

  while(temp){
    digits.push_back(temp%10);
    temp /= 10;
  }
  reverse(digits.begin(),digits.end());
  sort(digits.begin(),digits.end());
  int n = digits.size();

  int j = 0;
  while(j < n && digits[j] == 0) j++;
  if(j < n) swap(digits[0],digits[j]);

  do{
    if(digits[0] != 0){
      temp = digits[0];
      for(int i = 1;i < n;i++) temp = digits[i] + temp*10;
      if(isPowerof2(temp)){ flag = true; break; }
    }
  }while(next_permutation(digits.begin(),digits.end()));

  return flag;
}

int main(){
  int N; cin>>N;
  cout<<reorderedPowerOf2(N)<<endl;
  return 0;
}

/*
4
1 1 1
1 6 1
2 2 2
100 100 100
*/
