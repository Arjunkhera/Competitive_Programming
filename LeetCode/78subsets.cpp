#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void solve(vector<int> &nums,vector<vector<int>> &answer){

  vector<vector<vector<int>>> arr(1,vector<vector<int>>(1,vector<int>(1,nums[0])));

  for(int i = 1;i < nums.size();i++){
    for(int j = 0;j < i;j++){
      int size = arr[j].size()-1;
      for(int k = size;k >= 0;k--){
        vector<int> temp = arr[j][k];
        temp.push_back(nums[i]);
        arr[j].push_back(temp);
      }
    }
    vector<vector<int>> temp(1,vector<int>(1,nums[i]));
    arr.push_back(temp);
  }

  // push the subsets
  for(int i = 0;i < arr.size();i++)
      for(int j = 0;j < arr[i].size();j++)
        answer.push_back(arr[i][j]);
}

// solution function
vector<vector<int>> subsets(vector<int>& nums){
  vector<vector<int>> answer;
  if(nums.size() == 0) return answer;

  vector<int> temp; answer.push_back(temp);
  sort(nums.begin(),nums.end());
  solve(nums,answer);
  return answer;
}


int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  vector<vector<int>> answer = subsets(arr);
  for(auto i:answer) { for(auto j:i) cout<<j<<" "; cout<<endl; }

  return 0;
}
