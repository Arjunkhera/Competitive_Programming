#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

void solve(int n,vector<vector<int>> &answer,int cur,vector<int> &arr,int k){
  if(k == 0) { answer.push_back(arr); return; }
  if(cur > n || k < 0) return;

  for(int i = cur;i <= n ;i++){
      arr.push_back(i);
      solve(n,answer,i+1,arr,k-1);
      arr.pop_back();
  }
}

// solution function
vector<vector<int>> combine(int n, int k){
  vector<vector<int>> answer;
  if(n == 0) return answer;

  vector<int> temp;
  solve(n,answer,1,temp,k);
  return answer;
}

int main(){
  int n,temp;
  cin>>n>>temp;

  vector<vector<int>> answer = combine(n,temp);
  for(int j = 0;j < answer.size();j++){
    for(auto i:answer[j]) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
