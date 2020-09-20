#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(vector<int>& nums,vector<vector<int>> &answer,int start){
  if(start == nums.size()-1) { answer.push_back(nums); return; }

  for(int i = start;i < nums.size();i++){
    swap(nums[start],nums[i]);
    solve(nums,answer,start+1);
    swap(nums[start],nums[i]);
  }
}

// solution function
vector<vector<int>> permute(vector<int>& nums){
  vector<vector<int>> answer;
  if(nums.empty()) return answer;

  solve(nums,answer,0);
  return answer;
}

int main(){
  int n,temp;
  cin>>n;
  vector<int> arr(n,0);
  for(int i = 0;i < n;i++) cin>>arr[i];

  vector<vector<int>> answer = permute(arr);
  for(int j = 0;j < answer.size();j++){
    for(auto i:answer[j]) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
