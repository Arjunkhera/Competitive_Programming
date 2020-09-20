#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

#define modulo 1000000007
typedef long int li;
using namespace std;

li findpower(int base,int expo){
  if(base == 0 || base == 1 || expo == 1) return base;
  if(expo == 0) return 1;

  li answer = 1;
  while(expo){
    if(expo & 1) answer = answer*base;
    base *= base;
    expo >>= 1;
  }
  return answer;
}

int solve(vector<int> &arr,int length,int maxnum){
  if(arr.empty()) return 0;

  li answer = 0,digits = arr.size(),temp = 0;
  vector<int> cdigits; temp = maxnum;
  while(temp){
    cdigits.push_back(temp%10);
    temp /= 10;
  }
  reverse(cdigits.begin(),cdigits.end());

  if(length > cdigits.size()) return 0;

  if(length < cdigits.size()){
    if(arr[0] == 0 && length > 1) answer += (digits-1)*findpower(digits,length-1);
    else answer += findpower(digits,length);
    return answer;
  }

  temp = length-1;
  for(int i = 0;i < cdigits.size();i++){
    int k = 0;
    // cout<<"first:"<<i<<":"<<k<<":"<<answer<<endl;
    for(;k < digits && arr[k] < cdigits[i];k++);
    // cout<<"sec:"<<i<<":"<<k<<":"<<answer<<endl;
    if(arr[0] == 0 && temp == length-1 && length > 1) answer += (k-1)*findpower(digits,temp);
    else answer += k*findpower(digits,temp);
    // cout<<"third:"<<i<<":"<<k<<":"<<answer<<endl;
    temp--;
    if(k == digits || arr[k] > cdigits[i]) break;
  }
  return answer;
}

int main(){
  vector<int> arr;
  int temp; cin>>temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  int length,maxnum;
  cin>>length>>maxnum;

  cout<<solve(arr,length,maxnum)<<endl;
  return 0;
}

/*
0 1 2 5 -1
2
21
---------------
0 2 3 4 5 7 8 9 -1
5
86587
*/
