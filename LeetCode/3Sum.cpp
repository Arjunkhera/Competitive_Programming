#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// brute force
vector<vector<int>> threeSum(vector<int>& nums){
  vector<vector<int>> arr;
  int length = nums.size();
  int tempsum=0,cur=0;

  sort(nums.begin(),nums.end());
  for(int i=0;i<length;i++)
    if(nums[i]==0)
      tempsum++;
  if(tempsum>2)
    arr.push_back({0,0,0});

  for(int i=0;i<length-2;i++){
    for(int j=i+1;j<length-1;j++){
      if(nums[i] == nums[i-1] && i>0)
        continue;
      tempsum = 0-(nums[i]+nums[j]);
      if(tempsum == 0)
        continue;
      for(int k=j+1;k<length;k++){
        if(nums[k]>tempsum)
          break;
        if(tempsum == nums[k])
          arr.push_back({nums[i],nums[j],nums[k]});
      }
    }
  }
  return arr;
}

int main(){
  vector<int> arr;
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    arr.push_back(temp);
  }

  //solve
  vector<vector<int>> answer = threeSum(arr);
  for(int i=0;i<answer.size();i++){
    for(auto j : answer[i])
      cout<<j<<" ";
    cout<<"\n";
  }
  return 0;
}
