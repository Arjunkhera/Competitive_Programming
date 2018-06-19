#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// solution function
vector<vector<int>> fourSum(vector<int>& nums, int target){
  vector<int> answer;
  if(nums.empty()) return answer;
}

int main(){
  int n,temp;
  cin>>n;
  vector<int> arr(n,0);
  for(int i = 0;i < n;i++) cin>>arr[i];
  cin>>n;

  vector<vector<int>> answer = fourSum(arr,n);
  for(int j = 0;j < answer.size();j++){
    for(auto i:answer[j]) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
