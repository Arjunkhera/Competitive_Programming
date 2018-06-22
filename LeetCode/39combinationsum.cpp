#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

void solve(vector<int> &candidates,int target,vector<vector<int>> &answer,int cur,vector<int> &arr){
  if(target == 0) { answer.push_back(arr); return; }
  if(cur == candidates.size() || target < 0) return;

  for(int i = cur;i < candidates.size() && target >= candidates[i];i++){
    arr.push_back(candidates[i]);
    solve(candidates,target-candidates[i],answer,i,arr);
    arr.pop_back();
  }
}

void solveinterviewbit(vector<int> &candidates,int target,vector<vector<int>> &answer,int cur,vector<int> &arr,set<vector<int>> &dict){
  if(target == 0) { if(dict.find(arr) == dict.end()) {answer.push_back(arr); dict.insert(arr); } return; }
  if(cur == candidates.size() || target < 0) return;

  for(int i = cur;i < candidates.size() && target >= candidates[i];i++){
    arr.push_back(candidates[i]);
    solveinterviewbit(candidates,target-candidates[i],answer,i,arr,dict);
    arr.pop_back();
  }
}

// solution function
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
  vector<vector<int>> answer;
  if(candidates.empty()) return answer;

  vector<int> temp; set<vector<int>> dict;
  sort(candidates.begin(),candidates.end());
  // solve(candidates,target,answer,0,temp);
  solveinterviewbit(candidates,target,answer,0,temp,dict);
  return answer;
}

int main(){
  int n,temp;
  cin>>n;
  vector<int> arr(n,0);
  for(int i = 0;i < n;i++) cin>>arr[i];
  cin>>temp;

  vector<vector<int>> answer = combinationSum(arr,temp);
  for(int j = 0;j < answer.size();j++){
    for(auto i:answer[j]) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
