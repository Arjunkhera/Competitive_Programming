#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

// with set
void solvewith(vector<int> &candidates,int target,vector<vector<int>> &answer,int cur,vector<int> &arr,set<vector<int>> &dict,int k){
  if(target == 0 && k == 0) { if(dict.find(arr) == dict.end()) {answer.push_back(arr); dict.insert(arr); } return; }
  if(cur == candidates.size() || target < 0 || k < 0) return;

  for(int i = cur;i < candidates.size() && target >= candidates[i];i++){
    arr.push_back(candidates[i]);
    solvewith(candidates,target-candidates[i],answer,i+1,arr,dict,k-1);
    arr.pop_back();
  }
}

// without set
void solve(vector<int> &candidates,int target,vector<vector<int>> &answer,int cur,vector<int> &arr,int k){
  if(target == 0 && k == 0) { answer.push_back(arr); return; }
  if(cur == candidates.size() || target < 0 || k < 0) return;

  for(int i = cur;i < candidates.size() && target >= candidates[i];i++){
      arr.push_back(candidates[i]);
      solve(candidates,target-candidates[i],answer,i+1,arr,k-1);
      arr.pop_back();
  }
}

// solution function
vector<vector<int>> combinationSum3(int k, int n){
  vector<vector<int>> answer;
  if(k == 0 || n == 0) return answer;

  vector<int> candidates = {1,2,3,4,5,6,7,8,9};
  vector<int> temp; set<vector<int>> dict;
  // solvewith(candidates,target,answer,0,temp,dict);
  solve(candidates,n,answer,0,temp,k);
  return answer;
}

int main(){
  int n,k;
  cin>>k>>n;

  vector<vector<int>> answer = combinationSum3(k,n);
  for(int j = 0;j < answer.size();j++){
    for(auto i:answer[j]) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
