#include<iostream>
#include<vector>
#include<stack>

#define modulo 1000000007
typedef long long int li;
using namespace std;

int solve(vector<li> &arr){
  if(arr.empty()) return 0;

  li temp,n = arr.size(),answer = 0;
  vector<int> left(n,-1),right(n,-1);
  stack<li> stk;

  stk.push(0);
  for(int i = 1;i < n;i++){
    while(!stk.empty() && arr[i] > arr[stk.top()]){
      temp = stk.top(); stk.pop();
      right[temp] = i;
    }
    stk.push(i);
  }
  while(!stk.empty()) stk.pop();

  stk.push(n-1);
  for(int i = n-2;i >= 0;i--){
    while(!stk.empty() && arr[i] > arr[stk.top()]){
      temp = stk.top(); stk.pop();
      left[temp] = i;
    }
    stk.push(i);
  }
  while(!stk.empty()) stk.pop();

  for(int i = 0;i < n;i++){
    if(left[i] == -1 || right[i] == -1) continue;
    temp = left[i]*right[i];
    if(answer < temp) answer = temp;
  }
  answer = answer%modulo;
  return (int)answer;
}

int main(){
  vector<li> arr;
  li temp; cin>>temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  cout<<solve(arr)<<endl;
  return 0;
}

/*
6 5 4 9 9 6 5 4 5 9 9 -1
*/
